//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// struct to store the Huffman tree node
struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
};

// struct to represent the Huffman tree
struct HuffmanTree {
    unsigned size;
    struct HuffmanNode **arr;
};

// utility function to create a new Huffman tree node
struct HuffmanNode* newHuffmanNode(char data, unsigned freq)
{
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// utility function to swap two Huffman Tree Nodes
void swapHuffmanNodes(struct HuffmanNode** a, struct HuffmanNode** b)
{
    struct HuffmanNode* t = *a;
    *a = *b;
    *b = t;
}

// utility function to create Huffman Tree from the given character frequency array
struct HuffmanTree* createHuffmanTree(char* data, int* freq, int size)
{
    struct HuffmanTree* tree = (struct HuffmanTree*)malloc(sizeof(struct HuffmanTree));
    tree->size = size;
    tree->arr = (struct HuffmanNode**)malloc(size * sizeof(struct HuffmanNode*));
    for (int i = 0; i < size; ++i)
        tree->arr[i] = newHuffmanNode(data[i], freq[i]);
    for (int i = size/2 - 1; i >= 0; --i)
        siftDown(tree->arr, i, size);
    return tree;
}

// utility function to extract the minimum element from the heap
struct HuffmanNode* extractMin(struct HuffmanTree* tree)
{
    struct HuffmanNode* min = tree->arr[0];
    tree->arr[0] = tree->arr[tree->size - 1];
    --tree->size;
    siftDown(tree->arr, 0, tree->size);
    return min;
}

// utility function to insert a new Huffman tree node into the heap
void insert(struct HuffmanTree* tree, struct HuffmanNode* node)
{
    ++tree->size;
    int i = tree->size - 1;
    while (i && node->freq < tree->arr[(i - 1)/2]->freq)
    {
        tree->arr[i] = tree->arr[(i - 1)/2];
        i = (i - 1) / 2;
    }
    tree->arr[i] = node;
}

// utility function to check if a given node is a leaf node
int isLeaf(struct HuffmanNode* node)
{
    return !(node->left) && !(node->right);
}

// utility function to build the Huffman tree and store the codes in the given array
void buildHuffmanTree(char* data, int* freq, int size)
{
    struct HuffmanNode *left, *right, *top;
    struct HuffmanTree* tree = createHuffmanTree(data, freq, size);

    while (tree->size != 1)
    {
        left = extractMin(tree);
        right = extractMin(tree);
        top = newHuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert(tree, top);
    }
    int* codes = (int*) malloc (sizeof(int) * MAX_TREE_HT);
    int topIndex = 0;
    printHuffmanCodes(tree->arr[0], codes, topIndex);
}

// utility function to print the Huffman codes of each character in the tree
void printHuffmanCodes(struct HuffmanNode* root, int* codes, int topIndex)
{
    if (root->left)
    {
        codes[topIndex] = 0;
        printHuffmanCodes(root->left, codes, topIndex + 1);
    }

    if (root->right)
    {
        codes[topIndex] = 1;
        printHuffmanCodes(root->right, codes, topIndex + 1);
    }

    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        printArray(codes, topIndex);
    }
}

// utility function to heapify the heap
void siftDown(struct HuffmanNode** arr, int i, int size)
{
    int minIndex = i;
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;
    if (leftChild < size && arr[leftChild]->freq < arr[minIndex]->freq)
        minIndex = leftChild;
    if (rightChild < size && arr[rightChild]->freq < arr[minIndex]->freq)
        minIndex = rightChild;
    if (i != minIndex) {
        swapHuffmanNodes(&arr[i], &arr[minIndex]);
        siftDown(arr, minIndex, size);
    }
}

// utility function to print an array of Huffman codes
void printArray(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

// main function to test the Huffman coding implementation
int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    buildHuffmanTree(data, freq, size);
    return 0;
}