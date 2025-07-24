//FormAI DATASET v1.0 Category: Binary search trees ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left, *right;
};

// function to create a new node
struct node *newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// function to insert a node in BST
struct node* insert(struct node* node, int key){
    // if tree is empty, return a new node
    if(node == NULL) return newNode(key);

    // if tree is not empty, recur down the tree
    if(key < node->key) node->left = insert(node->left, key);
    else if(key > node->key) node->right = insert(node->right, key);

    return node;
}

// function to search a node in BST
struct node* search(struct node* root, int key){
    // base cases: root is null or key is present at root
    if(root == NULL || root->key == key) return root;

    // if key is greater than root's key
    if(root->key < key) return search(root->right, key);

    // if key is smaller than root's key
    return search(root->left, key);
}

// function to find inorder successor to replace node to delete
struct node *minValueNode(struct node* node){
    struct node* current = node;

    // loop down to leftmost leaf
    while(current && current->left != NULL)
        current = current->left;

    return current;
}

// function to delete a node in BST
struct node* deleteNode(struct node* root, int key){
    // base case
    if(root == NULL) return root;

    // if the key to be deleted is smaller than root's key, search in left subtree
    if(key < root->key) root->left = deleteNode(root->left, key);

    // if the key to be deleted is greater than root's key, search in right subtree
    else if(key > root->key) root->right = deleteNode(root->right, key);

    // if key is same as root's key, then this is the node to be deleted
    else{
        // node with only one child or no child
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: get inorder successor
        struct node* temp = minValueNode(root->right);

        // copy the inorder successor's key to this node
        root->key = temp->key;

        // delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// function to traverse the tree in inorder fashion
void inorderTraversal(struct node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// main function to test the program
int main(){
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);

    printf("\n\nAfter deletion of key 20: \n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified BST: ");
    inorderTraversal(root);

    printf("\n\nAfter deletion of key 30: \n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified BST: ");
    inorderTraversal(root);

    printf("\n\nAfter deletion of key 50: \n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified BST: ");
    inorderTraversal(root);

    return 0;
}