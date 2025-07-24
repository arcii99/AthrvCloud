//FormAI DATASET v1.0 Category: Binary search trees ; Style: systematic
#include<stdio.h> 
#include<stdlib.h> 

typedef struct node { 
    int key; 
    struct node *left, *right; 
}Node;

//Creates a new node with given key
Node* newNode(int item) { 
    Node* temp = (Node*)malloc(sizeof(Node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

// Inserts a new node with the given key in the BST 
Node* insert(Node* node, int key) { 
    if(node == NULL) 
        return newNode(key);
        
    if(key < node->key) 
        node->left = insert(node->left, key); 
    else if(key > node->key) 
        node->right = insert(node->right, key); 
    
    return node;
} 

// Search for a node with the given key
Node* search(Node* root, int key) { 
    if(root == NULL || root->key == key) 
       return root; 
    
    if(root->key < key) 
       return search(root->right, key); 
       
    return search(root->left, key); 
} 

void inorder(Node* root) { 
    if(root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
} 

int main() { 
    Node* root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 

    printf("Inorder traversal of the binary search tree :\n");
    inorder(root); 
    
    int key = 40; 
    Node* result = search(root, key); 
    if(result == NULL) 
        printf("\nNode with key %d not found\n ", key); 
    else
        printf("\nNode with key %d found\n ", result->key); 
   
    return 0; 
}