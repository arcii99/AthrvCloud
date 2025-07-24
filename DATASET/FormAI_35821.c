//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
/*
 * This is a Huffman Coding Implementation program, coded in a Linus Torvalds style
 * by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Huffman Tree Node struct */
struct node {
    char character;  // character stored in node
    int frequency;  // frequency of character
    struct node *left;  // left child node
    struct node *right;  // right child node
};

/* Function to create a new Huffman Tree Node */
struct node* createNode(char character, int frequency) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->character = character;
    new_node->frequency = frequency;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/* Function to create a Min Heap from an array of Huffman Tree Nodes */
void createMinHeap(struct node** minHeap, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(minHeap, i, size);
    }
}

/* Function to min heapify a subtree rooted at a specific index */
void minHeapify(struct node** minHeap, int root, int size) {
    int smallest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && minHeap[left]->frequency < minHeap[smallest]->frequency) {
        smallest = left;
    }
    if (right < size && minHeap[right]->frequency < minHeap[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != root) {
        // Swap nodes
        struct node* temp = minHeap[root];
        minHeap[root] = minHeap[smallest];
        minHeap[smallest] = temp;

        // Recursively min heapify subtree
        minHeapify(minHeap, smallest, size);
    }
}

/* Function to extract the minimum element from the min heap */
struct node* extractMin(struct node** minHeap, int* size) {
    struct node* min_node = minHeap[0];
    minHeap[0] = minHeap[*size - 1];
    (*size)--;
    minHeapify(minHeap, 0, *size);
    return min_node;
}

/* Function to insert a new node in the min heap */
void insertNode(struct node** minHeap, struct node* newNode, int* size) {
    (*size)++;
    int index = *size - 1;
    while (index > 0 && newNode->frequency < minHeap[(index - 1)/2]->frequency) {
        minHeap[index] = minHeap[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    minHeap[index] = newNode;
}

/* Function to check if a node is a leaf node */
int isLeaf(struct node* root) {
    return !(root->left) && !(root->right);
}

/* Function to build a Huffman Tree */
struct node* buildHuffmanTree(char* characters, int* frequencies, int size) {
    struct node *left, *right, *top;

    // Create a min heap and initialize with all nodes
    struct node** minHeap = (struct node**)malloc(size * sizeof(struct node*));
    for (int i = 0; i < size; i++) {
        minHeap[i] = createNode(characters[i], frequencies[i]);
    }
    int minHeapSize = size;
    createMinHeap(minHeap, minHeapSize);

    // Build Huffman Tree by extracting minimum nodes from the min heap until only one node remains
    while (minHeapSize > 1) {
        left = extractMin(minHeap, &minHeapSize);
        right = extractMin(minHeap, &minHeapSize);

        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertNode(minHeap, top, &minHeapSize);
    }

    return extractMin(minHeap, &minHeapSize);
}

/* Function to print the Huffman codes for each character in the Huffman Tree */
void printHuffmanCodes(struct node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("\t%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequencies[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(characters) / sizeof(characters[0]);

    struct node* root = buildHuffmanTree(characters, frequencies, size);

    printf("Huffman Codes:\n");
    int arr[100], top = 0;
    printHuffmanCodes(root, arr, top);

    return 0;
}