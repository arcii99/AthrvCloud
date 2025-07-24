//FormAI DATASET v1.0 Category: Binary search trees ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
struct node {
  int key;
  struct node* left;
  struct node* right;
};

// Function to create a new node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node *));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Function to insert a new node into the tree
struct node* insert(struct node* node, int key) {
  // If no node exists, create a new one
  if (node == NULL) return newNode(key);
  
  // Traverse through the tree and insert the new node in the appropriate position
  if (key < node->key)
    node->left  = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);
  
  // Return the node with the new addition
  return node;
}

// Function to search for a node in the tree
struct node* search(struct node* root, int key) {
  // If the tree is empty or the desired node is found
  if (root == NULL || root->key == key)
    return root;
  
  // Search for the node in the left or right subtree, as appropriate
  if (root->key < key)
    return search(root->right, key);
  
  return search(root->left, key);
}

// Function to display the tree in-order (ascending order)
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d \n", root->key);
    inorder(root->right);
  }
}

// Main function
int main() {
  struct node *root = NULL;
  
  // Insert nodes
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);
  
  // Display the in-order tree traversal
  printf("In-order traversal of the given binary search tree:\n");
  inorder(root);
  
  // Search for a node and display the result
  int searchKey = 70;
  struct node* result = search(root, searchKey);
  if(result != NULL) {
    printf("Node with key %d found.\n", searchKey);
  } else {
    printf("Node with key %d not found.\n", searchKey);
  }

  return 0;
}