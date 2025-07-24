//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Define structure for each node in the Huffman tree
struct node {
    char data;
    unsigned freq;
    struct node *left, *right;
};
 
// Define structure for the Huffman heap
struct heap {
    unsigned count;
    unsigned capacity;
    struct node **array;
};
 
// Create a new node with a specified character and frequency
struct node* newNode(char data, unsigned freq) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
 
// Create a new heap with a specified capacity
struct heap* newHeap(unsigned capacity) {
    struct heap* temp = (struct heap*)malloc(sizeof(struct heap));
    temp->count = 0;
    temp->capacity = capacity;
    temp->array = (struct node**)malloc(temp->capacity * sizeof(struct node*));
    return temp;
}
 
// Swap two nodes in the heap
void swapNodes(struct node** a, struct node** b) {
    struct node* t = *a;
    *a = *b;
    *b = t;
}
 
// Heapify a tree with a specified index
void heapify(struct heap* h, int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
 
    if(left < h->count && h->array[left]->freq < h->array[smallest]->freq)
        smallest = left;
 
    if(right < h->count && h->array[right]->freq < h->array[smallest]->freq)
        smallest = right;
 
    if(smallest != index) {
        swapNodes(&h->array[smallest], &h->array[index]);
        heapify(h, smallest);
    }
}
 
// Check if the heap has only one node left
int isSizeOne(struct heap* h) {
    return (h->count == 1);
}
 
// Get the minimum node in the heap
struct node* getMinNode(struct heap* h) {
    struct node* minNode = h->array[0];
    h->array[0] = h->array[h->count-1];
    --h->count;
    heapify(h, 0);
    return minNode;
}
 
// Insert a new node into the heap
void insertNode(struct heap* h, struct node* node) {
    ++h->count;
    int i = h->count-1;
 
    while(i && node->freq < h->array[(i-1)/2]->freq) {
        h->array[i] = h->array[(i-1)/2];
        i = (i-1)/2;
    }
    h->array[i] = node;
}
 
// Build a Huffman tree and return the root node
struct node* buildHuffmanTree(char data[], int freq[], int n) {
    struct node *left, *right, *top;
    struct heap* h = newHeap(n);
 
    for(int i=0; i<n; ++i)
        insertNode(h, newNode(data[i], freq[i]));
 
    while(!isSizeOne(h)) {
        left = getMinNode(h);
        right = getMinNode(h);
 
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
 
        insertNode(h, top);
    }
 
    return getMinNode(h);
}
 
// Print Huffman codes from the root node
void printCodes(struct node* root, int arr[], int top) {
    if(root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
 
    if(root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }
 
    if(!root->left && !root->right) {
        printf("%c: ", root->data);
        for(int i=0; i<top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}
 
// Huffman Code driver function
void huffmanCode(char data[], int freq[], int n) {
    struct node* root = buildHuffmanTree(data, freq, n);
    int arr[n], top = 0;
    printCodes(root, arr, top);
}
 
// Test our code function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(data)/sizeof(data[0]);
    huffmanCode(data, freq, n);
    return 0;
}