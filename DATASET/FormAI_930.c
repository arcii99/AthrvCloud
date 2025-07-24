//FormAI DATASET v1.0 Category: Binary search trees ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// To create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// To insert data in the tree
struct Node* insert(struct Node* node, int data) {
    if(node == NULL)
        return createNode(data);
    if(data < node->data)
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);
    return node;
}

// To search for an element in the tree
struct Node* search(struct Node* node, int data) {
    if(node == NULL || node->data == data)
        return node;
    if(data < node->data)
        return search(node->left, data);
    return search(node->right, data);
}

// To find the minimum value in a tree
struct Node* minNode(struct Node* node) {
    struct Node* current = node;
    while(current->left != NULL)
        current = current->left;
    return current;
}

// To delete a node from the tree
struct Node* deleteNode(struct Node* node, int data) {
    if(node == NULL)
        return node;
    if(data < node->data)
        node->left = deleteNode(node->left, data);
    else if(data > node->data)
        node->right = deleteNode(node->right, data);
    else {
        if(node->left == NULL){
            struct Node* temp = node->right;
            free(node);
            return temp;
        }
        else if(node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }
        struct Node* temp = minNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

// To display the tree in inorder
void inorderPrint(struct Node* node) {
    if(node != NULL) {
        inorderPrint(node->left);
        printf("%d -> ", node->data);
        inorderPrint(node->right);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    root = insert(root, 23);
    insert(root, 10);
    insert(root, 30);
    insert(root, 40);
    insert(root, 25);
    insert(root, 8);
    insert(root, 12);
    printf("Inorder traversal of the tree\n");
    inorderPrint(root);
    printf("\n");
    printf("Searching for 30 in the tree\n");
    if(search(root, 30) != NULL)
        printf("30 found in the tree\n");
    else
        printf("30 not found in the tree\n");
    printf("Deleting 25 from the tree\n");
    root = deleteNode(root, 25);
    printf("Inorder traversal of the updated tree\n");
    inorderPrint(root);
    return 0;
}