//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
} Node;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    Node** array;
} MinHeap;

Node* newNode(char data, unsigned freq) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;

    return node;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));

    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (Node**)malloc(minHeap->capacity * sizeof(Node*));

    return minHeap;
}

void swapNodes(Node** leaf1, Node** leaf2) {
    Node* temp = *leaf1;
    *leaf1 = *leaf2;
    *leaf2 = temp;
}

void heapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
        
    if (smallest != idx) {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        heapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

Node* extractMin(MinHeap* minHeap) {
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    heapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = node;
}

void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for(i = (n - 1) / 2; i >= 0; --i)
        heapify(minHeap, i);
}

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);

    printf("\n");
}

int isLeaf(Node* root) {
    return !(root->left) && !(root->right);
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    
    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

Node* buildHuffmanTree(char data[], int freq[], int size) {
    Node *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(Node* root, int arr[], int top) {
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
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size) {
    Node* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    int len;
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    len = strlen(str);

    char data[len];
    int freq[len];

    int i, j, count;

    for (i = 0; i < len; i++) {
        count = 1;
        if (str[i] == -128) {
            continue;
        }
        for (j = i + 1; j < len; j++) {
            if (str[j] == str[i]) {
                count++;
                str[j] = -128;
            }
        }
        data[i] = str[i];
        freq[i] = count;
    }

    HuffmanCodes(data, freq, len - 1);

    return 0; 
}