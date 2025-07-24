//FormAI DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int data) {
  Node *node = (Node *) malloc(sizeof(Node));
  
  if(node != NULL) {
    node->data = data;
    node->left = NULL;
    node->right = NULL;
  }
  
  return node;
}

void insert(Node **root, int data) {
  if(*root == NULL) {
    *root = createNode(data);
    printf("%d has been added to the tree! Woo hoo!\n", data);
  } else if(data < (*root)->data) {
    insert(&(*root)->left, data);
  } else {
    insert(&(*root)->right, data);
  }
}

Node *search(Node *root, int data) {
  if(root == NULL) {
    printf("Sorry, %d not found in the tree. Better luck next time!\n", data);
    return NULL;
  }
  
  if(root->data == data) {
    printf("%d found! You're amazing!\n", data);
    return root;
  } else if(data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

void printInOrder(Node *root) {
  if(root != NULL) {
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
  }
}

int main() {
  Node *root = NULL;
  
  insert(&root, 10);
  insert(&root, 5);
  insert(&root, 2);
  insert(&root, 7);
  insert(&root, 50);
  insert(&root, 25);
  insert(&root, 15);
  insert(&root, 30);
  
  printInOrder(root);
  
  Node *found = search(root, 25);
  
  if(found != NULL) {
    printf("Ahh yeah! I found %d!\n", found->data);
  }
  
  found = search(root, 500);
  
  if(found == NULL) {
    printf("Aw man! Couldn't find 500. Better luck next time!\n");
  }

  return 0;
}