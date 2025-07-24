//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

typedef struct HuffmanNode {
    int data;
    unsigned freq;
    struct HuffmanNode *left, *right;
} HuffmanNode;

typedef struct PriorityQueue {
    unsigned size;
    unsigned capacity;
    HuffmanNode **array;
} PriorityQueue;

HuffmanNode *newHuffmanNode(int data, unsigned freq) {
    HuffmanNode *node = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

PriorityQueue *newPriorityQueue(unsigned capacity) {
    PriorityQueue *queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    queue->size = 0;
    queue->capacity = capacity;
    queue->array = (HuffmanNode**)malloc(queue->capacity * sizeof(HuffmanNode*));
    return queue;
}

void swap(HuffmanNode **x, HuffmanNode **y) {
    HuffmanNode *temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(PriorityQueue *queue, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < queue->size && queue->array[left]->freq < queue->array[smallest]->freq)
        smallest = left;
    if (right < queue->size && queue->array[right]->freq < queue->array[smallest]->freq)
        smallest = right;
    if (smallest != index) {
        swap(&queue->array[smallest], &queue->array[index]);
        minHeapify(queue, smallest);
    }
}

int isSizeOne(PriorityQueue *queue) {
    return (queue->size == 1);
}

int isEmpty(PriorityQueue *queue) {
    return queue->size == 0;
}

HuffmanNode *extractMin(PriorityQueue *queue) {
    HuffmanNode *node = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];
    --queue->size;
    minHeapify(queue, 0);
    return node;
}

void insert(PriorityQueue *queue, HuffmanNode *node) {
    ++queue->size;
    int i = queue->size - 1;
    while (i && node->freq < queue->array[(i - 1) / 2]->freq) {
        queue->array[i] = queue->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    queue->array[i] = node;
}

void buildMinHeap(PriorityQueue *queue) {
    int n = queue->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(queue, i);
    }
}

bool isLeaf(HuffmanNode *node) {
    return !(node->left) && !(node->right);
}

PriorityQueue *createPriorityQueue(char data[], int freq[], int size) {
    PriorityQueue *queue = newPriorityQueue(size);
    for (int i = 0; i < size; ++i)
        queue->array[i] = newHuffmanNode(data[i], freq[i]);
    queue->size = size;
    buildMinHeap(queue);
    return queue;
}

HuffmanNode *buildHuffmanTree(char data[], int freq[], int size) {
    HuffmanNode *left, *right, *top;
    PriorityQueue *queue = createPriorityQueue(data, freq, size);
    while (!isSizeOne(queue)) {
        left = extractMin(queue);
        right = extractMin(queue);
        top = newHuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert(queue, top);
    }
    return extractMin(queue);
}

void printCodes(HuffmanNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void huffmanCodes(char data[], int freq[], int size) {
    HuffmanNode *root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    huffmanCodes(data, freq, size);
    return 0;
}