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

void countNodesAtEachLevel(Node *root, int level, int count[])
{
    if (root == NULL)
        return;
    count[level]++;
    countNodesAtEachLevel(root->left, level + 1, count);
    countNodesAtEachLevel(root->right, level + 1, count);
}

void displayLevels(Node *root)
{
    int count[100] = {0};
    countNodesAtEachLevel(root, 0, count);
    int totalLevels = 0;
    printf("Nodes at each level:\n");
    for (int i = 0; count[i] > 0; i++)
    {
        printf("Level %d: %d nodes\n", i, count[i]);
        totalLevels++;
    }
    printf("Total levels: %d\n", totalLevels);
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
    displayLevels(root);
    return 0;
}