//FormAI DATASET v1.0 Category: Binary search trees ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

Node* create_node(int data) {
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* insert(Node* root, int data) {
  if (root == NULL) {
    return create_node(data);
  }

  if (data < root->data) {
    root->left = insert(root->left, data);
  } 
  else {
    root->right = insert(root->right, data);
  }
  
  return root;
}

void inorder_traversal(Node* root) {
  if (root != NULL) {
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}

int main() {
  Node* root = create_node(50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Inorder traversal: ");
  inorder_traversal(root);

  return 0;
}