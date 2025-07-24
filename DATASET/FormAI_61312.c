//FormAI DATASET v1.0 Category: Binary search trees ; Style: genious
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode(int item)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct node *insertNode(struct node *node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);

    return node;
}

struct node *searchNode(struct node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;

    if (root->data < data)
        return searchNode(root->right, data);

    return searchNode(root->left, data);
}

int main()
{
    struct node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Inorder traversal of the Binary Search Tree is: ");
    inorderTraversal(root);

    int item;
    printf("\nEnter item to search in the Binary Search Tree: ");
    scanf("%d", &item);

    struct node *search_result = searchNode(root, item);

    if (search_result == NULL)
        printf("%d is not found in the Binary Search Tree.", item);
    else
        printf("%d is found in the Binary Search Tree!", search_result->data);

    return 0;
}