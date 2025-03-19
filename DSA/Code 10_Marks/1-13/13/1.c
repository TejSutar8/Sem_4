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

int compare(Node *T1, Node *T2)
{
    if (T1 == NULL && T2 == NULL)
        return 1;
    if (T1 == NULL || T2 == NULL)
        return 0;
    return (T1->data == T2->data) && compare(T1->left, T2->left) && compare(T1->right, T2->right);
}

int main()
{
    Node *T1 = NULL, *T2 = NULL;
    int n1, n2, value;

    printf("Enter number of nodes in first BST: ");
    scanf("%d", &n1);
    printf("Enter values for first BST: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &value);
        T1 = insert(T1, value);
    }

    printf("Enter number of nodes in second BST: ");
    scanf("%d", &n2);
    printf("Enter values for second BST: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &value);
        T2 = insert(T2, value);
    }

    if (compare(T1, T2))
        printf("The BSTs are equal.\n");
    else
        printf("The BSTs are not equal.\n");

    return 0;
}