//FormAI DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

/* Function to create a new node */
struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* Function to insert a new node with the given key */
struct node *insert(struct node* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL) {
        return newNode(key);
    }

    /* Otherwise, recur down the tree */
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    /* Return the unchanged node pointer */
    return node;
}

/* Function to traverse the tree in-order */
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* Function to find the node with the minimum key */
struct node * minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

/* Function to delete a node with the given key */
struct node* deleteNode(struct node* root, int key) {
    /* Base Case */
    if (root == NULL) {
        return root;
    }

    /* If the key to be deleted is smaller than the root's key, 
    then it lies in left subtree */
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }

    /* If the key to be deleted is greater than the root's key, 
    then it lies in right subtree */
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }

    /* If key is same as root's key, then This is the node 
    to be deleted */
    else {
        /* Node with only one child or no child */
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        /* Node with two children: Get the inorder successor (smallest 
        in the right subtree) */
        struct node* temp = minValueNode(root->right);

        /* Copy the inorder successor's content to this node */
        root->key = temp->key;

        /* Delete the inorder successor */
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

/* Driver program to test above functions */
int main() {
    struct node *root = NULL;
    int choice = 1, n, key;

    while (choice != 0)
    {
        printf("\n\nBinary Search Tree\n\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Traverse the tree in-order\n");
        printf("0. Exit\n\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key you want to insert: ");
            scanf("%d", &n);
            root = insert(root, n);
            printf("Inserted successfully\n");
            break;

        case 2:
            printf("Enter the key you want to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            printf("Deleted successfully\n");
            break;

        case 3:
            printf("In-order traversal of the binary search tree: ");
            inorder(root);
            printf("\n");
            break;

        case 0:
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}