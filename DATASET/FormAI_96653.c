//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_TREE_HT 100
#define MASTER_THREAD_ID 0

// Structure for a Huffman tree node
struct MinHeapNode {
    char data; // character to store
    unsigned freq; // frequency of character
    struct MinHeapNode *left, *right; // left and right child pointers
};

// Structure for a Min Heap
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array; // array of min heap node pointers
};

// Creates a new Huffman tree node
struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Create a min heap of a given capacity
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**) malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Swap two nodes of min heap.
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify function to maintain min heap property of the heap.
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

// Check if size of heap is 1.
bool isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract minimum value node from heap.
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node to min heap.
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Creates a min heap of given size from an array of frequencies.
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    for (int i = (size - 1) / 2; i >= 0; --i) minHeapify(minHeap, i);
    return minHeap;
}

// Build Huffman tree and print codes by traversing the built tree.
void HuffmanCodesUtil(struct MinHeapNode* root, int arr[], int top, char** huffmanCodes) {
    if (root->left) {
        arr[top] = 0;
        HuffmanCodesUtil(root->left, arr, top + 1, huffmanCodes);
    }
    if (root->right) {
        arr[top] = 1;
        HuffmanCodesUtil(root->right, arr, top + 1, huffmanCodes);
    }
    if (root->left == NULL && root->right == NULL) {
        char* code = (char*) malloc(top + 1);
        for (int i = 0; i < top; ++i) code[i] = (arr[i] == 1) ? '1' : '0';
        code[top] = '\0';
        huffmanCodes[root->data] = code;
    }
}

// Prints Huffman codes for the characters in a given array of frequencies.
char** HuffmanCodes(char data[], int freq[], int size) {
    struct MinHeapNode* left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    char** huffmanCodes = (char**) malloc(sizeof(char*) * size);
    int* arr = (int*) malloc(sizeof(int) * size);
    HuffmanCodesUtil(extractMin(minHeap), arr, 0, huffmanCodes);
    return huffmanCodes;
}

// Function to print the Huffman code for each character in a string.
void printHuffmanCode(char** huffmanCodes, char str[]) {
    printf("\nHuffman Codes For The Given String:\n\n");
    for (int i = 0; i < strlen(str); ++i) printf("%c: %s\n", str[i], huffmanCodes[str[i]]);
}

// Master thread function to run the huffman coding algorithm.
void* master(void* args) {
    // Get the input string and its frequency of each character from user.
    char str[1000], ch;
    printf("Enter an input string: ");
    scanf("%[^\n]s", str);
    int freq[256] = { 0 };
    for (int i = 0; str[i] != '\0'; ++i) ++freq[str[i]];

    // Get the number of threads to be used in the algorithm.
    int num_threads;
    printf("Enter the number of threads to be used for the huffman coding algorithm: ");
    scanf("%d", &num_threads);

    // Initialize some variables before creating threads.
    char** huffmanCodes = (char**) malloc(sizeof(char*) * 256);
    pthread_t tid[num_threads];
    int index = 0;

    // Create threads and let the threads do the work asynchronously.
    for (int i = 1; i <= num_threads; ++i) {
        int* thread_id = (int*) malloc(sizeof(int));
        *thread_id = i;
        pthread_create(&tid[i], NULL, HuffmanCodes, (void*) thread_id);
        usleep(10000);
    }

    // Wait for all threads to finish their execution.
    for (int i = 1; i <= num_threads; ++i) pthread_join(tid[i], NULL);

    // Get the final huffman codes from all threads and combine it to get the result.
    for (int i = 1; i <= num_threads; ++i) {
        char** tempCodes;
        pthread_join(tid[i], &tempCodes);
        for (int j = 0; j < 256; ++j) {
            if (tempCodes[j] != NULL) huffmanCodes[j] = tempCodes[j];
        }
    }

    // Print the final Huffman codes of each character in the input string.
    printHuffmanCode(huffmanCodes, str);
    return NULL;
}

// Main function to initiate the master thread.
int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, master, NULL);
    pthread_join(tid, NULL);
    return 0;
}