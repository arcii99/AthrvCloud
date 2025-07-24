//FormAI DATASET v1.0 Category: Compression algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

// Node structure for the Huffman tree
struct Node {
    int freq;
    char data;
    struct Node *left, *right;
};

// Queue structure for building the Huffman tree
struct Queue {
    int size;
    int capacity;
    int front, rear;
    struct Node **arr;
};

// Function to initialize a new node
struct Node* newNode(char data, int freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to initialize a new queue
struct Queue* newQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (struct Node**)malloc(capacity * sizeof(struct Node*));
    return queue;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* queue) {
    return queue->size == 0;
}

// Function to check if the queue is full
int isQueueFull(struct Queue* queue) {
    return queue->size == queue->capacity;
}

// Function to enqueue a node into the queue
void enqueue(struct Queue* queue, struct Node* node) {
    if (isQueueFull(queue)) {
        printf("Queue is full!");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = node;
    queue->size++;
}

// Function to dequeue a node from the queue
struct Node* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!");
        return NULL;
    }
    struct Node* node = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return node;
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Queue* queue = newQueue(size);
    for (int i = 0; i < size; i++) {
        enqueue(queue, newNode(data[i], freq[i]));
    }
    while (queue->size > 1) {
        struct Node* left = dequeue(queue);
        struct Node* right = dequeue(queue);
        struct Node* parent = newNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        enqueue(queue, parent);
    }
    return dequeue(queue);
}

// Helper function to print a binary representation of a character
void printBits(unsigned char byte) {
    printf("0b");
    for(int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
    printf(" ");
}

// Function to traverse the Huffman tree and print the codes
void printHuffmanCodes(struct Node* root, unsigned char code, int length) {
    if (root->left != NULL) {
        code = (code << 1);
        printHuffmanCodes(root->left, code, length + 1);
    }
    if (root->right != NULL) {
        code = (code << 1) | 1;
        printHuffmanCodes(root->right, code, length + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);
        for(int i = 0; i < length; i++) {
            printBits(code >> (length - i - 1));
        }
        printf("\n");
    }
}

// Function to compress a string using Huffman coding
void compress(char str[]) {
    int len = strlen(str);
    char data[MAX_CHAR];
    int freq[MAX_CHAR] = {0};
    int count = 0;
    for(int i = 0; i < len; i++) {
        if(freq[str[i]] == 0) {
            data[count++] = str[i];
        }
        freq[str[i]]++;
    }
    struct Node* root = buildHuffmanTree(data, freq, count);
    printHuffmanCodes(root, 0, 0);
    printf("Compressed string: ");
    unsigned char byte = 0;
    int bitsWritten = 0;
    for(int i = 0; i < len; i++) {
        struct Node* curr = root;
        while(curr->left != NULL || curr->right != NULL) {
            if((str[i] >> bitsWritten) & 1) {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
            bitsWritten++;
            if(bitsWritten == 8) {
                printBits(byte);
                byte = 0;
                bitsWritten = 0;
            }
        }
        byte |= ((curr->data & 1) << (7 - bitsWritten));
        bitsWritten++;
        if(bitsWritten == 8) {
            printBits(byte);
            byte = 0;
            bitsWritten = 0;
        }
    }
    if(bitsWritten > 0 && bitsWritten < 8) {
        byte <<= (8 - bitsWritten);
        printBits(byte);
    }
}

// Driver program to test the compression function
int main() {
    char str[] = "hello world!";
    compress(str);
    return 0;
}