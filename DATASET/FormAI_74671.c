//FormAI DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
   int data;
   struct TreeNode* left;
   struct TreeNode* right;
};
struct TreeNode* createNode(int val) {
  struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
  node->data = val;
  node->left = NULL;
  node->right = NULL;
  return node;
}
struct TreeNode* insert(struct TreeNode* root, int val) {
   if (root == NULL) {
      return createNode(val);
   }
   if (val < root->data) {
      root->left = insert(root->left, val);
   } else if (val > root->data) {
      root->right = insert(root->right, val);
   }
   return root;
}
struct TreeNode* search(struct TreeNode* root, int val) {
   if (root == NULL || root->data == val) {
      return root;
   }
   if (val < root->data) {
      return search(root->left, val);
   }
   return search(root->right, val);
}
void printInorder(struct TreeNode* root) {
   if (root != NULL) {
      printInorder(root->left);
      printf("%d ", root->data);
      printInorder(root->right);
   }
}

int main() {
   struct TreeNode* root = NULL;
   root = insert(root, 50);
   insert(root, 30);
   insert(root, 20);
   insert(root, 40);
   insert(root, 70);
   insert(root, 60);
   insert(root, 80);
   printf("Inorder traversal of binary search tree is: ");
   printInorder(root);
   printf("\n");

   int searchVal = 60;
   struct TreeNode* result = search(root, searchVal);
   if (result) {
      printf("%d is found in the binary search tree.\n", searchVal);
   } else {
      printf("%d is not found in the binary search tree.\n", searchVal);
   }
   return 0;
}