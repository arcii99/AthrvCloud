//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARS 256

// A node of Huffman tree 
struct Node {
    int freq;
    char data;
    struct Node *left;
    struct Node *right;
};

// Priority queue node 
struct PQNode {
    struct Node *data;
    struct PQNode *next;
};

// The priority queue 
struct PriorityQueue {
    struct PQNode *head;
};

// Initialize the priority queue 
struct PriorityQueue* initializePriorityQueue() {
    struct PriorityQueue* pq = (struct PriorityQueue*) malloc(sizeof(struct PriorityQueue));
    pq->head = NULL;
    return pq;
}

// Insert a node into the priority queue 
void insert(struct PriorityQueue* pq, struct Node *node) {
    struct PQNode *newPQNode = (struct PQNode*) malloc(sizeof(struct PQNode));
    newPQNode->next = NULL;
    newPQNode->data = node;
    if (pq->head == NULL) {
        pq->head = newPQNode;
    }
    else if(newPQNode->data->freq <= pq->head->data->freq){
        newPQNode->next = pq->head;
        pq->head = newPQNode;
    }
    else{
        struct PQNode *curr = pq->head;
        while(curr->next!=NULL && curr->next->data->freq <= newPQNode->data->freq) {
            curr = curr->next;
        }
        newPQNode->next = curr->next;
        curr->next = newPQNode;
    }
}

// Get the minimum node from the priority queue 
struct Node* getMin(struct PriorityQueue* pq) {
    struct Node* temp = pq->head->data;
    pq->head = pq->head->next;
    return temp;
}

// Check if the node is a leaf node 
int isLeaf(struct Node* node) {
    return node->left == NULL && node->right == NULL;
}

// Traverse the tree and build the huffman code 
void encode(struct Node* node, char *arr, int top, char **codes) {
    if (node->left) {
        arr[top] = '0';
        encode(node->left, arr, top + 1, codes);
    }
    if (node->right) {
        arr[top] = '1';
        encode(node->right, arr, top + 1, codes);
    }
    if (isLeaf(node)) {
        arr[top] = '\0';
        char *temp = (char*) malloc(sizeof(char) * CHARS);
        strcpy(temp,arr);
        codes[(int)node->data] = temp;
    }
}

// Build the Huffman tree 
struct Node* buildHuffmanTree(int freqs[]) {
    struct PriorityQueue* pq = initializePriorityQueue();
    for (int i = 0; i < CHARS; ++i) {
        if (freqs[i] != 0) {
            struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
            newNode->left = newNode->right = NULL;
            newNode->data = (char) i;
            newNode->freq = freqs[i];
            insert(pq, newNode);
        }
    }
    while (pq->head->next) {
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->left = getMin(pq);
        newNode->right = getMin(pq);
        newNode->data = '\0';
        newNode->freq = newNode->left->freq + newNode->right->freq;
        insert(pq, newNode);
    }
    return getMin(pq);
}

// Huffman code generation 
char ** generateCodes(int freqs[]) {
    char arr[CHARS];
    char **codes = (char**) malloc(sizeof(char*) * CHARS);
    for (int i = 0; i < CHARS; i++) {
        codes[i] = NULL;
    }
    struct Node* root = buildHuffmanTree(freqs);
    encode(root, arr, 0, codes);
    return codes;
}

// Encode a string using the Huffman codes 
void encodeString(char **codes, char *input, char *output) {
    int i = 0;
    while(input[i]!='\0'){
        strcat(output,codes[(int)input[i++]]);
    }
}

// Decode a string using the Huffman codes 
void decodeString(struct Node* root, char *input, char *output) {
    struct Node* curr = root;
    for (int i = 0; input[i]!='\0'; i++) {
        if (input[i] == '0') {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
        if (isLeaf(curr)) {
            strncat(output,&curr->data,1);
            curr = root;
        }
    }
}

// Main function 
int main() {
    char input[CHARS], output[CHARS];
    int freqs[CHARS];
    for(int i=0;i<CHARS;i++){
        freqs[i]=0;
    }
    printf("Enter the input string: ");
    scanf("%[^\n]s", input);
    for(int i=0;i<strlen(input);i++){
        freqs[(int)input[i]]++;
    }
    char **codes = generateCodes(freqs);
    encodeString(codes,input,output);
    printf("\nHuffman Encoded Output: %s\n", output);
    decodeString(buildHuffmanTree(freqs),output,output);
    printf("\nDecoded Output: %s\n", output);
    return 0;
}