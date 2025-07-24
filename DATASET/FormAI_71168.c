//FormAI DATASET v1.0 Category: Compression algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 256

struct node
{
    char data;
    unsigned freq;
    struct node *left, *right;
};

struct minHeap
{
    unsigned size;
    unsigned capacity;
    struct node** array;
};

struct node* createNode(char data, unsigned freq)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

struct minHeap* createMinHeap(unsigned capacity)
{
    struct minHeap* minHeap = (struct minHeap*) malloc(sizeof(struct minHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct node**)malloc(minHeap->capacity * sizeof(struct node*));
    return minHeap;
}

void swapNode(struct node** a, struct node** b)
{
    struct node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct minHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    
    if (smallest != idx)
    {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

bool isSizeOne(struct minHeap* minHeap)
{
    return (minHeap->size == 1);
}

struct node* extractMin(struct minHeap* minHeap)
{
    struct node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct minHeap* minHeap, struct node* node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    
    minHeap->array[i] = node;
}

void buildMinHeap(struct minHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArray(char arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%c", arr[i]);
    printf("\n");
}

bool isLeaf(struct node* root)
{
    return !(root->left) && !(root->right);
}

struct minHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct minHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct node* buildHuffmanTree(char data[], int freq[], int size)
{
    struct node *left, *right, *top;
    struct minHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    
    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(struct node* root, char arr[], int top)
{
    if (root->left)
    {
        arr[top] = '0';
        printCodes(root->left, arr, top + 1);
    }
    
    if (root->right)
    {
        arr[top] = '1';
        printCodes(root->right, arr, top + 1);
    }
    
    if (isLeaf(root))
    {
        printf("%c: ", root->data);
        printArray(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct node* root = buildHuffmanTree(data, freq, size);
    char arr[MAX_TREE_HT], code[size];
    int top = 0, i;
    printCodes(root, arr, top);
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}