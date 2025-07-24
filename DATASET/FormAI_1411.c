//FormAI DATASET v1.0 Category: Image compression ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 256

struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode* left;
    struct MinHeapNode* right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

int front = 0, rear = -1;

int queue[MAX_TREE_HT];

struct MinHeapNode* createNode(char data, unsigned freq) {
    struct MinHeapNode* newNode = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    newNode->freq = freq;
    return newNode;
}

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode* left, * right, * top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top, int fd) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1, fd);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1, fd);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->data);
        printArr(arr, top);

        char code[100];
        int j = 0;

        for (int i = 0; i < top; i++) {
            code[j] = arr[i] + '0';
            j++;
        }

        code[j] = '\0';

        fprintf(fd, "%c%s\n", root->data, code);
    }
}

void storeEncodedPixels(unsigned char* pixels, int size, FILE* fd) {
    int freq[256] = { 0 };

    for (int i = 0; i < size; i++) {
        freq[pixels[i]]++;
    }

    char data[256];

    for (int i = 0; i < 256; i++) {
        data[i] = (char)i;
    }

    struct MinHeapNode* root = buildHuffmanTree(data, freq, 256);
    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top, fd);

    for (int i = 0; i < size; i++) {
        fseek(fd, -1, SEEK_END);
        unsigned char pixel = pixels[i];
        fprintf(fd, "%c", pixel);
    }
}

void decodeHuffmanCodes(int codes[][MAX_TREE_HT], unsigned char* pixels, int size, FILE* fd) {
    struct MinHeapNode* root = createNode('$', 0);

    for (int i = 0; i < 256; i++) {
        if (codes[i][0] != -1) {
            struct MinHeapNode* current = root;

            for (int j = 0; j < MAX_TREE_HT; j++) {
                if (codes[i][j] == -1) {
                    break;
                }

                if (codes[i][j] == 0) {
                    if (!current->left) {
                        current->left = createNode('$', 0);
                    }

                    current = current->left;
                }
                else {
                    if (!current->right) {
                        current->right = createNode('$', 0);
                    }

                    current = current->right;
                }
            }

            current->data = (char)i;
        }
    }

    struct MinHeapNode* current = root;

    for (int i = 0; i < size; i++) {
        unsigned char pixel = pixels[i];

        for (int j = 7; j >= 0; j--) {
            if (((pixel >> j) & 1) == 0) {
                current = current->left;
            }
            else {
                current = current->right;
            }

            if (isLeaf(current)) {
                fprintf(fd, "%c", current->data);
                current = root;
            }
        }
    }
}

void compressImage(char* filename, unsigned char* pixels, int width, int height) {
    int size = width * height;
    FILE* fd = fopen(filename, "wb+");
    storeEncodedPixels(pixels, size, fd);
    fclose(fd);
}

void decompressImage(char* filename, unsigned char* pixels, int width, int height) {
    int size = width * height;
    int codes[256][MAX_TREE_HT];

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < MAX_TREE_HT; j++) {
            codes[i][j] = -1;
        }
    }

    FILE* fd = fopen(filename, "rb+");

    char line[MAX_TREE_HT + 10];

    while (fgets(line, MAX_TREE_HT + 10, fd)) {
        int len = strlen(line);
        int c = line[0];
        int j = 1;

        for (int i = 2; i < len; i++) {
            int bit = line[i] - '0';
            codes[c][j - 2] = bit;
            j++;
        }
    }

    decodeHuffmanCodes(codes, pixels, size, fd);

    fclose(fd);
}

int main() {
    unsigned char pixels[30 * 30];
    int width = 30;
    int height = 30;

    for (int i = 0; i < width * height; i++) {
        pixels[i] = rand() % 256;
    }

    compressImage("compress.bin", pixels, width, height);
    memset(pixels, 0, sizeof(pixels));
    decompressImage("compress.bin", pixels, width, height);

    return 0;
}