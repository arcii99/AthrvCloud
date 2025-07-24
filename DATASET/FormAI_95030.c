//FormAI DATASET v1.0 Category: Binary search trees ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* left;
  struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a node
struct Node* insertNode(struct Node* node, int value) {
  if (node == NULL) return createNode(value);
  if (value < node->value)
    node->left  = insertNode(node->left, value);
  else if (value > node->value)
    node->right = insertNode(node->right, value);   
  return node;
}

// Function to search a node
struct Node* searchNode(struct Node* node, int value) {
  if (node == NULL || node->value == value)
     return node;
  if (node->value < value)
     return searchNode(node->right, value);
  return searchNode(node->left, value);
}

// Function to print a node in order
void printInOrder(struct Node* node) {
  if (node != NULL) {
    printInOrder(node->left);
    printf("%d ", node->value);
    printInOrder(node->right);
  }
}

// Main function
int main() {
  struct Node* root = createNode(50);
  insertNode(root, 30);
  insertNode(root, 20);
  insertNode(root, 40);
  insertNode(root, 70);
  insertNode(root, 60);
  insertNode(root, 80);

  printf("In Order Traversal: ");
  printInOrder(root);

  struct Node* result = searchNode(root, 60);
  if (result == NULL) printf("\nKey not found");
  else printf("\nKey found: %d", result->value);

  return 0;
}