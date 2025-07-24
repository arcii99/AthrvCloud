//FormAI DATASET v1.0 Category: Binary search trees ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *left, *right;
};

struct node* create_node(int item) {
   struct node* new_node = (struct node*) malloc(sizeof(struct node));
   new_node->data = item;
   new_node->left = new_node->right = NULL;
   return new_node;
}

void inorder_traversal(struct node* root) {
   if (root != NULL) {
      inorder_traversal(root->left);
      printf("%d ", root->data);
      inorder_traversal(root->right);
   }
}

struct node* insert_node(struct node* node, int data) {
   if (node == NULL) return create_node(data);
   if (data < node->data)
      node->left = insert_node(node->left, data);
   else if (data > node->data)
      node->right = insert_node(node->right, data);
   return node;
}

struct node* min_node(struct node* node) {
   struct node* curr = node;
   while (curr && curr->left != NULL)
      curr = curr->left;
   return curr;
}

struct node* delete_node(struct node* root, int key) {
   if (root == NULL) return root;
   if (key < root->data)
      root->left = delete_node(root->left, key);
   else if (key > root->data)
      root->right = delete_node(root->right, key);
   else {
      if (root->left == NULL) {
         struct node* temp = root->right;
         free(root);
         return temp;
      }
      else if (root->right == NULL) {
         struct node* temp = root->left;
         free(root);
         return temp;
      }
      struct node* temp = min_node(root->right);
      root->data = temp->data;
      root->right = delete_node(root->right, temp->data);
   }
   return root;
}

int main() {
   struct node* root = NULL;
   root = insert_node(root, 50);
   insert_node(root, 30);
   insert_node(root, 20);
   insert_node(root, 40);
   insert_node(root, 70);
   insert_node(root, 60);
   insert_node(root, 80);
   printf("Inorder traversal of tree before deletion: ");
   inorder_traversal(root);
   root = delete_node(root, 20);
   printf("\nInorder traversal of tree after deletion: ");
   inorder_traversal(root);
   return 0;
}