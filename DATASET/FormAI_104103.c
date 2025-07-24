//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct node {
    char data;
    int freq;
    struct node *left, *right;
} Node;

typedef struct min_heap {
    uint size;
    uint capacity;
    Node **array;
} MinHeap;

typedef struct huffman_tree {
    Node *root;
} HuffmanTree;

MinHeap *createMinHeap(uint capacity) {
    MinHeap *minHeap = (MinHeap *) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node **) malloc(minHeap->capacity * sizeof(Node *));
    return minHeap;
}

void swapNode(Node **a, Node **b) {
    Node *t = *a;
    *a = *b;
    *b = t;
}

Node *getMinNode(MinHeap *minHeap) {
    Node *minNode = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    return minNode;
}

void minHeapify(MinHeap *minHeap, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    if (leftChild < minHeap->size && minHeap->array[leftChild]->freq < minHeap->array[smallest]->freq) {
        smallest = leftChild;
    }
    if (rightChild < minHeap->size && minHeap->array[rightChild]->freq < minHeap->array[smallest]->freq) {
        smallest = rightChild;
    }
    if (smallest != index) {
        swapNode(&minHeap->array[index], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

void insertMinHeap(MinHeap *minHeap, Node *node) {
    ++minHeap->size;
    int index = minHeap->size - 1;
    while (index && node->freq < minHeap->array[(index - 1) / 2]->freq) {
        minHeap->array[index] = minHeap->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    minHeap->array[index] = node;
}

MinHeap *createAndBuildMinHeap(char *data[], int freq[], uint size) {
    MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = (Node *) malloc(sizeof(Node));
        minHeap->array[i]->data = *data[i];
        minHeap->array[i]->freq = freq[i];
        minHeap->array[i]->left = minHeap->array[i]->right = NULL;
    }
    minHeap->size = size;

    for (int i = minHeap->size / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }

    return minHeap;
}

Node *buildHuffmanTree(char *data[], int freq[], uint size) {
    Node *left, *right, *top;
    MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);

    while (minHeap->size != 1) {
        left = getMinNode(minHeap);
        right = getMinNode(minHeap);
        top = (Node *) malloc(sizeof(Node));
        top->data = '$';
        top->freq = left->freq + right->freq;
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return getMinNode(minHeap);
}

void printEncode(Node *root, int arr[], int top, char *data) {
    if (root->left) {
        arr[top] = 0;
        printEncode(root->left, arr, top + 1, data);
    }
    if (root->right) {
        arr[top] = 1;
        printEncode(root->right, arr, top + 1, data);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void HuffmanCodes(char *data[], int freq[], uint size) {
    Node *root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printEncode(root, arr, top, *data);
}

int main() {
    char *data[] = {"a", "b", "c", "d", "e", "f"};
    int freq[] = {5, 9, 12, 13, 16, 45};
    uint size = sizeof(data) / sizeof(data[0]);
    HuffmanCodes(data, freq, size);

    return 0;
}