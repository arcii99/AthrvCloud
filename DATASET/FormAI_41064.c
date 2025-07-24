//FormAI DATASET v1.0 Category: Binary search trees ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

/* Binary search tree node */
struct node {
    int data;
    struct node *left, *right;
};

/* Function to create a new node with given data */
struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/* Function to insert a new node with given data in BST */
struct node *insert(struct node *node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(data);

    /* Otherwise, recur down the tree */
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    /* return the (unchanged) node pointer */
    return node;
}

/* Function to find the node with minimum value in BST */
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Function to delete the node with given data from BST */
struct node *deleteNode(struct node *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/* Function to inorder traversal of BST */
void inorderTraversal(struct node *root)
{
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

/* Main function */
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    /* Print inorder traversal of the BST */
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);

    /* Delete node with key 20 */
    root = deleteNode(root, 20);

    /* Print inorder traversal of the modified tree */
    printf("\nInorder traversal of the modified BST: ");
    inorderTraversal(root);

    return 0;
}