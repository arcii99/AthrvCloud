//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

struct node{
   int value;
   struct node *left;
   struct node *right;
};

struct node* create_node(int value){
   struct node* n=malloc(sizeof(struct node));
   n->value=value;
   n->left=NULL;
   n->right=NULL;
   return n;
}

struct node* insert_node(struct node* root, int value){
   if(root==NULL){
      return create_node(value);
   }
   if(value<root->value){
      root->left=insert_node(root->left,value);
   }
   else{
      root->right=insert_node(root->right,value);
   }
   return root;
}

void inorder_traversal(struct node* root){
   if(root!=NULL){
      inorder_traversal(root->left);
      printf("%d ",root->value);
      inorder_traversal(root->right);
   }
}

int main(){
   struct node* root=NULL;
   root=insert_node(root,50);
   insert_node(root,30);
   insert_node(root,20);
   insert_node(root,40);
   insert_node(root,70);
   insert_node(root,60);
   insert_node(root,80);
   printf("Inorder Traversal of Binary Search Tree: ");
   inorder_traversal(root);
   return 0;
}