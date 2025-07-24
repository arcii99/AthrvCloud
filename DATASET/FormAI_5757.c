//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Node struct for Huffman Tree
struct TreeNode {
    unsigned char data;
    int freq;
    struct TreeNode *left, *right;
};

// Priority Queue Node struct 
struct PriorityQueue {
    struct TreeNode *data;
    struct PriorityQueue *next;
};

// Function to create new Node
struct TreeNode* newNode(unsigned char data, int freq) {
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to create new PriorityQueue node
struct PriorityQueue* newPQNode(struct TreeNode* node) {
    struct PriorityQueue* newNode = (struct PriorityQueue*) malloc(sizeof(struct PriorityQueue));
    newNode->data = node;
    newNode->next = NULL;
    return newNode;
}

// Function to compare PQ nodes
int compare(struct PriorityQueue* a, struct PriorityQueue* b) {
    return (a->data->freq > b->data->freq);
}

// Function to push PQ nodes
void push(struct PriorityQueue **headRef, struct TreeNode* node) {
    struct PriorityQueue* newNode = newPQNode(node);
    if (*headRef == NULL || compare(*headRef, newNode)) {
         newNode->next = *headRef;
        *headRef = newNode;
    } else {
        struct PriorityQueue* current = *headRef;
        while (current->next && compare(newNode, current->next)) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to pop PQ nodes
struct TreeNode* pop(struct PriorityQueue** headRef) {
    struct PriorityQueue* temp = *headRef;
    *headRef = (*headRef)->next;
    return temp->data;
}

// Function to build Huffman Tree
struct TreeNode* buildHuffmanTree(char *data, int *freq, int size) {
    struct PriorityQueue *head = NULL;
    for (int i = 0; i < size; ++i) {
        push(&head, newNode(data[i], freq[i]));
    }
    while (head && head->next) {
        struct TreeNode* left = pop(&head);
        struct TreeNode* right = pop(&head);
        struct TreeNode* parent = newNode(0, left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        push(&head, parent);
    }
    return pop(&head);
}

// Function to traverse Huffman Tree and store codes in array
void traverseHuffmanTree(struct TreeNode* root, int top, char *codes[], char code[]) {
    if (root->left) {
        code[top] = '0';
        traverseHuffmanTree(root->left, top + 1, codes, code);
    }
    if (root->right) {
        code[top] = '1';
        traverseHuffmanTree(root->right, top + 1, codes, code);
    }
    if (!root->left && !root->right) {
        char *newCode = (char*) malloc(sizeof(char) * (top + 1));
        strncpy(newCode, code, top);
        codes[root->data] = newCode;
    }
}

// Function to Huffman encode a string and print output
void huffmanEncode(char* str, int *freq, int size) {
    struct TreeNode* root = buildHuffmanTree(str, freq, size);
    char code[CHAR_BIT];
    char *codes[UCHAR_MAX + 1] = {NULL};
    traverseHuffmanTree(root, 0, codes, code);
    printf("\n Huffman Codes for Characters in String:\n");
    for (int i = 0; i < UCHAR_MAX + 1; ++i) {
        if (codes[i]) {
            printf("%c: %s\n", i, codes[i]);
        }
    }
    printf("\n Huffman Encoded String:\n");
    for (int i = 0; i < strlen(str); ++i) {
        printf("%s", codes[str[i]]);
    }
}

// Driver Code
int main() {
    char* str = "huffman";
    int freq[] = {1, 1, 1, 1, 2, 2};
    int size = strlen(str);
    huffmanEncode(str, freq, size);
    return 0;
}