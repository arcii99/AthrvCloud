//FormAI DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} node;

node* create_node(int data) {
  node* new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node* insert(node* root, int data) {
  if (root == NULL) {
    root = create_node(data);
  }
  else if (data <= root->data) {
    root->left = insert(root->left, data);
  }
  else {
    root->right = insert(root->right, data);
  }
  return root;
}

void inorder_traversal(node* root) {
  if (root != NULL) {
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}

int main() {
  node* root = NULL;

  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Inorder Traversal of Binary Search Tree:\n");
  inorder_traversal(root);

  return 0;
}