//FormAI DATASET v1.0 Category: Binary search trees ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct node {  //structure of node
   int data;
   struct node *left;
   struct node *right;
};

struct node* new_node(int data) { //createnewnode function
   struct node* node = (struct node*)malloc(sizeof(struct node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return(node);
}

void display(struct node *root)  //inordertraversal function to display elements in BST
{
    if(root!=NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

struct node* insert(struct node* node, int data) { //insert function for the nodes into BST
   if (node == NULL) return new_node(data);
 
   if (data < node->data)
      node->left  = insert(node->left, data);
   else if (data > node->data)
      node->right = insert(node->right, data);   
 
   return node;
}

int main() {
   struct node *root = NULL;
   root = insert(root, 50);  //insertion of nodes in BST
   insert(root, 30);
   insert(root, 20);
   insert(root, 40);
   insert(root, 70);
   insert(root, 60);
   insert(root, 80);
   
   printf("Elements in the BST : ");
   display(root);  //calling the function for inorder traversal to display contents of BST
 
   return 0;
}