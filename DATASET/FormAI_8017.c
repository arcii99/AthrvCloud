//FormAI DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// create new node
struct node *new_node(int data) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// insert node
struct node *insert_node(struct node *node, int data) {
    if (node == NULL) 
        return new_node(data);
    
    if (data < node->data)
        node->left = insert_node(node->left, data);
    
    else if (data > node->data)
        node->right = insert_node(node->right, data);
    
    return node;
}

// search node
struct node *search_node(struct node *node, int data) {
    if (node == NULL || node->data == data)
        return node;
    
    if (data < node->data)
        return search_node(node->left, data);
    
    return search_node(node->right, data);
}

// inorder traversal
void inorder_traversal(struct node *node) {
    if (node != NULL) {
        inorder_traversal(node->left);
        printf("%d ", node->data);
        inorder_traversal(node->right);
    }
}

// main function
int main() {
    struct node *root = new_node(50);
    
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    
    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");
    
    int search_data = 60;
    struct node *result = search_node(root, search_data);
    if (result == NULL)
        printf("%d not found in tree\n", search_data);
    else
        printf("%d found in tree\n", search_data);
    
    return 0;
}