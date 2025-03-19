#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

Node *copyTree(Node *root)
{
    if (root == NULL)
        return NULL;
    Node *newRoot = createNode(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    return newRoot;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    int n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter node values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Original Inorder Traversal: ");
    inorder(root);
    printf("\n");

    Node *copiedRoot = copyTree(root);
    printf("Copied Tree Inorder Traversal: ");
    inorder(copiedRoot);
    printf("\n");
    return 0;
}
