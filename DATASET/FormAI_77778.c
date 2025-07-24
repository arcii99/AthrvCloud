//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Node structure for Huffman coding tree
struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
};

// Priority queue node structure
struct PQNode {
    struct HuffmanNode *data;
    struct PQNode *next;
};

// Function to create new Huffman tree node
struct HuffmanNode* newHuffmanNode(char data, unsigned freq) {
    struct HuffmanNode* node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to create new priority queue node
struct PQNode* newPQNode(struct HuffmanNode *data) {
    struct PQNode* node = (struct PQNode*) malloc(sizeof(struct PQNode));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node in the priority queue
void insertPQNode(struct PQNode **head, struct PQNode *new_node) {
    struct PQNode *curr;
    if (*head == NULL || (*head)->data->freq >= new_node->data->freq) {
        new_node->next = *head;
        *head = new_node;
    } else {
        curr = *head;
        while (curr->next != NULL && curr->next->data->freq < new_node->data->freq) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

// Function to delete the node with the minimum frequency from priority queue
struct HuffmanNode* deleteMinNode(struct PQNode **head) {
    struct PQNode *temp = *head;
    *head = (*head)->next;
    struct HuffmanNode *data = temp->data;
    free(temp);
    return data;
}

// Function to build Huffman coding tree and return the root node
struct HuffmanNode* buildHuffmanTree(char *str, int *freq) {
    struct PQNode *head = NULL;
    struct HuffmanNode *left, *right, *top;
    for(int i = 0; i < strlen(str); i++) {
        insertPQNode(&head, newPQNode(newHuffmanNode(str[i], freq[i])));
    }
    while(head->next != NULL) {
        left = deleteMinNode(&head);
        right = deleteMinNode(&head);
        top = newHuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertPQNode(&head, newPQNode(top));
    }
    return deleteMinNode(&head);
}

// Function to print Huffman codes from the root of Huffman tree
void printHuffmanCodes(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    char str[] = "Hello World";
    int freq[] = {7, 1, 4, 4, 1, 1, 1, 2, 1, 1, 3};
    struct HuffmanNode* root = buildHuffmanTree(str, freq);
    int arr[MAX_TREE_HT], top = 0;
    printHuffmanCodes(root, arr, top);
    return 0;
}