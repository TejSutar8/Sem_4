#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *create(int val)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

Node *insert(int val, Node *root)
{
    if (root == NULL)
        return create(val);

    Node *parent = NULL, *temp = root;

    while (temp != NULL)
    {
        parent = temp;
        if (val <= temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }

    Node *newnode = create(val);
    if (val <= parent->data)
        parent->left = newnode;
    else
        parent->right = newnode;

    return root;
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

int search(Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return 1;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}

int sumOdd(Node *root)
{
    if (root == NULL)
        return 0;
    int sum = (root->data % 2 != 0) ? root->data : 0;
    return sum + sumOdd(root->left) + sumOdd(root->right);
}

int sumEven(Node *root)
{
    if (root == NULL)
        return 0;
    int sum = (root->data % 2 == 0) ? root->data : 0;
    return sum + sumEven(root->left) + sumEven(root->right);
}

int main()
{
    Node *root = NULL;
    int choice, val;

    while (1)
    {
        printf("\n\n----- Binary Search Tree Menu -----");
        printf("\n1. Insert");
        printf("\n2. Postorder Traversal");
        printf("\n3. Preorder Traversal");
        printf("\n4. Inorder Traversal");
        printf("\n5. Search");
        printf("\n6. Sum of Odd Numbers");
        printf("\n7. Sum of Even Numbers");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(val, root);
            break;

        case 2:
            printf("\nPostorder Traversal:\n");
            postorder(root);
            break;

        case 3:
            printf("\nPreorder Traversal:\n");
            preorder(root);
            break;

        case 4:
            printf("\nInorder Traversal:\n");
            inorder(root);
            break;

        case 5:
            printf("\nEnter a key to search: ");
            scanf("%d", &val);
            if (search(root, val))
                printf("Number %d found in tree\n", val);
            else
                printf("Number %d not found in tree\n", val);
            break;

        case 6:
            printf("\nSum of odd numbers in BST: %d\n", sumOdd(root));
            break;

        case 7:
            printf("\nSum of even numbers in BST: %d\n", sumEven(root));
            break;

        case 8:
            printf("Exiting program...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
