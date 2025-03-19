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

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printLevel(Node *root, int level, int *count)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        printf("%d ", root->data);
        (*count)++;
    }
    else if (level > 1)
    {
        printLevel(root->left, level - 1, count);
        printLevel(root->right, level - 1, count);
    }
}

void levelOrder(Node *root)
{
    int h = height(root);
    printf("Total Levels: %d\n", h);
    for (int i = 1; i <= h; i++)
    {
        int count = 0;
        printf("Level %d: ", i);
        printLevel(root, i, &count);
        printf(" (Nodes: %d)\n", count);
    }
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
    printf("\nBinary Search Tree Levels:\n");
    levelOrder(root);
    return 0;
}