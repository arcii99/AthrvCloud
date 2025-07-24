//FormAI DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

void print_tree(struct Node *root, int space) {
  if (root == NULL) {
    return;
  }
  space += 10;
  print_tree(root->right, space);
  printf("\n");
  for (int i = 10; i < space; i++) {
    printf(" ");
  }
  printf("%d\n", root->data);
  print_tree(root->left, space);
}

struct Node* new_node(int data) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

int main() {
  struct Node *root = new_node(1);
  root->left = new_node(2);
  root->right = new_node(3);
  root->left->left = new_node(4);
  root->left->right = new_node(5);
  root->right->left = new_node(6);
  root->right->right = new_node(7);
  root->left->left->left = new_node(8);
  root->left->left->right = new_node(9);

  print_tree(root, 0);
  return 0;
}