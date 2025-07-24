//FormAI DATASET v1.0 Category: Binary search trees ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert(struct node* root, int data){
    if(root == NULL){
        root = create_node(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

struct node* search(struct node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    else if(data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

// utility function to find the minimum value in a tree
struct node* minimum_value_node(struct node* node){
    struct node* current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

// function to delete a node from the binary search tree
struct node* delete_node(struct node* root, int data){
    if(root == NULL){
        return root;
    }
    else if(data < root->data){
        root->left = delete_node(root->left, data);
    }
    else if(data > root->data){
        root->right = delete_node(root->right, data);
    }
    else{
        // Case 1: node with only one child or no child
        if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 2: node with two children
        struct node* temp = minimum_value_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

void inorder_traversal(struct node* root){
    if(root!=NULL){
        inorder_traversal(root->left);
        printf("%d ",root->data);
        inorder_traversal(root->right);
    }
}

int main(){
    printf("Code by Linus Torvalds\n\n");
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of the binary search tree: ");
    inorder_traversal(root);
    printf("\n\nDeleting node with value 20\n");
    root = delete_node(root, 20);
    printf("Inorder traversal of the binary search tree after deletion: ");
    inorder_traversal(root);
    printf("\n");
    return 0;
}