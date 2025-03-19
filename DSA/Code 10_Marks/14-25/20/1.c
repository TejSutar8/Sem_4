#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *create(int val) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}

Node *insert(int val, Node *root) {
    if (root == NULL) 
        return create(val);

    Node *parent = NULL, *temp = root;
    
    while (temp != NULL) {
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

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

int main() {
    Node *root = NULL;
    int choice, val;

    while (1) {
        printf("\n\n----- Binary Search Tree Menu -----");
        printf("\n1. Insert");
        printf("\n2. Inorder Traversal");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(val, root);
                break;

            case 2:
                printf("\nInorder Traversal:\n");
                inorder(root);
                break;

            case 3:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
