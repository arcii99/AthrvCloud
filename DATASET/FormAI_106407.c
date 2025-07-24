//FormAI DATASET v1.0 Category: Binary search trees ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary search tree
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node *newNode(int item) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a node
struct node* insert(struct node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return newNode(data);
    }
    
    // Otherwise, recur down the tree
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    
    // Return the (unchanged) node pointer
    return node;
}

// Function to search for a node
struct node* search(struct node* root, int data) {
    // Base case - empty tree or data is present at root
    if (root == NULL || root->data == data) {
        return root;
    }
    
    // Data is greater than root's data
    if (root->data < data) {
        return search(root->right, data);
    }
    
    // Data is smaller than root's data
    return search(root->left, data);
}

// Function to find minimum value node in a given subtree
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    
    // Loop down to find the leftmost leaf
    while (current && current->left != NULL) {
        current = current->left;
    }
    
    return current;
}

// Function to delete a node
struct node* deleteNode(struct node* root, int data) {
    // Base case - empty tree
    if (root == NULL) {
        return root;
    }
    
    // If the data to be deleted is smaller than the root's data, 
    // then it lies in left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If the data to be deleted is greater than the root's data, 
    // then it lies in the right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // If the data is same as root's data, then this is the node 
    // to be deleted
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children - get the inorder successor (smallest 
        // in the right subtree)
        struct node* temp = minValueNode(root->right);
        
        // Copy the inorder successor's content to this node
        root->data = temp->data;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

// Function to traverse the tree in-order
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    struct node* root = NULL;
    
    // Insert various elements into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    
    // Traverse the tree in-order
    printf("Inorder traversal of the binary search tree:\n");
    inorder(root);
    
    // Search for an element in the tree
    int element = 60;
    struct node* temp = search(root, element);
    if (temp != NULL) {
        printf("\n%d found in the binary search tree\n", element);
    } else {
        printf("\n%d not found in the binary search tree\n", element);
    }
    
    // Delete an element from the tree
    element = 40;
    root = deleteNode(root, element);
    printf("\nInorder traversal after deleting %d from the tree:\n", element);
    inorder(root);
    
    return 0;
}