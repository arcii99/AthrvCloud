//FormAI DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node = (struct Node*)
                         malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

struct Node* insert(struct Node* root, int data){
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

void inorderTraversal(struct Node* root){
    if (root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct Node* search(struct Node* root, int data){
    if (root == NULL || root->data == data)
       return root;
    if (root->data < data)
       return search(root->right, data);
    return search(root->left, data);
}

struct Node* minValueNode(struct Node* node){
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int data){
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else {
        if (root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the binary search tree: \n");
    inorderTraversal(root);

    printf("\n\nDeleting value 20 from the binary search tree: \n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified binary search tree: \n");
    inorderTraversal(root);

    printf("\n\nDeleting value 30 from the binary search tree: \n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified binary search tree: \n");
    inorderTraversal(root);

    printf("\n\nDeleting value 50 from the binary search tree: \n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified binary search tree: \n");
    inorderTraversal(root);

    return 0;
}