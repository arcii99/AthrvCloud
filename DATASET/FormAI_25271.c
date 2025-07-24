//FormAI DATASET v1.0 Category: Binary search trees ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* left;
   struct Node* right;
};

struct Node* createNode(int data) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

struct Node* insert(struct Node* root,int data) {
   if (root == NULL)
      return createNode(data);
   if (data < root->data)
      root->left = insert(root->left, data);
   else if (data > root->data)
      root->right = insert(root->right, data);
   return root;
}

void inorder(struct Node* root) {
   if (root != NULL) {
      inorder(root->left);
      printf("%d -> ", root->data);
      inorder(root->right);
   }
}

int main() {
   struct Node* root = NULL;
   root = insert(root, 5);
   insert(root, 1);
   insert(root, 10);
   insert(root, 3);
   insert(root, 7);
   insert(root, 9);
   printf("Inorder traversal of the binary search tree is: ");
   inorder(root);
   return 0;
}