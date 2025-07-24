//FormAI DATASET v1.0 Category: Image Classification system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMG_SIZE 64

typedef struct Image {
    int pixels[IMG_SIZE][IMG_SIZE][3]; // RGB pixel values
    char label[10]; // label of image (e.g. "cat", "dog", "tree")
} Image;

typedef struct Node {
    Image data; // data stored in node
    struct Node* left; // pointer to left child node
    struct Node* right; // pointer to right child node
} Node;

Node* create_node(Image data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert node recursively
Node* insert_node(Node* root, Image data) {
    if (root == NULL) {
        root = create_node(data);
    } else if (strcmp(data.label, root->data.label) < 0) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// function to print tree recursively
void print_tree(Node* root) {
    if (root == NULL) {
        return;
    }
    print_tree(root->left);
    printf("Label: %s\n", root->data.label);
    print_tree(root->right);
}

int main() {
    // create some sample images
    Image img1 = {.pixels = {{{255, 0, 0}}}, .label = "red"};
    Image img2 = {.pixels = {{{0, 255, 0}}}, .label = "green"};
    Image img3 = {.pixels = {{{0, 0, 255}}}, .label = "blue"};
    Image img4 = {.pixels = {{{128, 128, 0}}}, .label = "olive"};
    Image img5 = {.pixels = {{{128, 0, 128}}}, .label = "purple"};

    // create root node and insert images recursively into binary search tree
    Node* root = create_node(img1);
    insert_node(root, img2);
    insert_node(root, img3);
    insert_node(root, img4);
    insert_node(root, img5);

    // print tree recursively
    print_tree(root);

    return 0;
}