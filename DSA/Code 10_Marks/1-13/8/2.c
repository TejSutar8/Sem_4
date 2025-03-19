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

void mirror(Node *root)
{
    if (root == NULL)
        return;
    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirror(root->left);
    mirror(root->right);
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
    mirror(root);
    printf("Mirror Inorder Traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}