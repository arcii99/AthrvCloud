//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
};

struct PriorityQueue {
    int size;
    struct Node **nodes;
};

struct Node *createNode(char character, int frequency) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct PriorityQueue *createPriorityQueue() {
    struct PriorityQueue *queue = (struct PriorityQueue *) malloc(sizeof(struct PriorityQueue));
    queue->size = 0;
    queue->nodes = (struct Node **) malloc(sizeof(struct Node *));
    queue->nodes[0] = NULL;
    return queue;
}

void enqueue(struct PriorityQueue *queue, struct Node *node) {
    queue->size++;
    queue->nodes = (struct Node **) realloc(queue->nodes, (queue->size + 1) * sizeof(struct Node *));
    int i = queue->size;
    while (queue->nodes[i/2] != NULL && node->frequency < queue->nodes[i/2]->frequency) {
        queue->nodes[i] = queue->nodes[i/2];
        i /= 2;
    }
    queue->nodes[i] = node;
}

struct Node *dequeue(struct PriorityQueue *queue) {
    struct Node *node = queue->nodes[1];
    queue->nodes[1] = queue->nodes[queue->size];
    queue->nodes[queue->size] = NULL;
    queue->size--;
    int i = 1;
    int child;
    struct Node *temp = queue->nodes[1];
    while (i * 2 <= queue->size) {
        child = i * 2;
        if (child != queue->size && queue->nodes[child+1]->frequency < queue->nodes[child]->frequency) {
            child++;
        }
        if (temp->frequency > queue->nodes[child]->frequency) {
            queue->nodes[i] = queue->nodes[child];
        } else {
            break;
        }
        i = child;
    }
    queue->nodes[i] = temp;
    return node;
}

void printCode(struct Node *node, char *code) {
    if (node == NULL) {
        return;
    }
    if (node->character != '\0') {
        printf("%c: %s\n", node->character, code);
    }
    char *leftCode = (char *) malloc(strlen(code) + 2);
    strcpy(leftCode, code);
    leftCode[strlen(code)] = '0';
    leftCode[strlen(code)+1] = '\0';
    printCode(node->left, leftCode);
    char *rightCode = (char *) malloc(strlen(code) + 2);
    strcpy(rightCode, code);
    rightCode[strlen(code)] = '1';
    rightCode[strlen(code)+1] = '\0';
    printCode(node->right, rightCode);
}

int main() {
    char *str = "this is an example of a string to be encoded using huffman coding";
    int len = strlen(str);
    int frequencies[256];
    memset(frequencies, 0, sizeof(frequencies));
    for (int i = 0; i < len; i++) {
        frequencies[str[i]]++;
    }
    struct PriorityQueue *queue = createPriorityQueue();
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] != 0) {
            struct Node *node = createNode(i, frequencies[i]);
            enqueue(queue, node);
        }
    }
    while (queue->size > 1) {
        struct Node *node1 = dequeue(queue);
        struct Node *node2 = dequeue(queue);
        struct Node *parent = createNode('\0', node1->frequency + node2->frequency);
        parent->left = node1;
        parent->right = node2;
        enqueue(queue, parent);
    }
    struct Node *root = dequeue(queue);
    char *code = (char *) malloc(1);
    code[0] = '\0';
    printCode(root, code);
    return 0;
}