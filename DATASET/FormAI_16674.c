//FormAI DATASET v1.0 Category: Binary search trees ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int key;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int item)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct Node* insert(struct Node* node, int key)
{
    if (node == NULL) 
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

struct Node* search(struct Node* root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

int main()
{
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the binary search tree is: \n");
    inorder(root);

    int key = 60;
    struct Node* result = search(root, key);
    if (result == NULL)
        printf("\nElement %d is not present in the binary search tree.\n", key);
    else
        printf("\nElement %d is present in the binary search tree.\n", result->key);

    key = 100;
    struct Node* result2 = search(root, key);
    if (result2 == NULL)
        printf("Element %d is not present in the binary search tree.", key);
    else
        printf("Element %d is present in the binary search tree.", result2->key);

    return 0;
}