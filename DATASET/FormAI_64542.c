//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50
 
typedef struct Node
{
    char data;
    unsigned frequency;
    struct Node *left, *right;
}Node;
 
typedef struct MinHeap
{
    unsigned size;
    unsigned capacity;
    Node **array;
}MinHeap;

Node *newNode(char data, unsigned frequency)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = frequency;

    return temp;
}
 
MinHeap *createMinHeap(unsigned capacity)
{
    MinHeap *minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;

    minHeap->array = (Node**)malloc(minHeap->capacity * sizeof(Node*));
    return minHeap;
}
 
void swapNodes(Node** a, Node** b)
{
    Node *t = *a;
    *a = *b;
    *b = t;
}
 
void minHeapify(MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if(left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if(right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if(smallest != idx)
    {
        swapNodes(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
 
Node *extractMin(MinHeap *minHeap)
{
    Node *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}
 
void insertMinHeap(MinHeap *minHeap, Node *node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while(i && node->frequency < minHeap->array[(i - 1)/2]->frequency)
    {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }

    minHeap->array[i] = node;
}
 
void buildMinHeap(MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    int i;

    for(i = (n - 1)/2; i >= 0; --i)
        minHeapify(minHeap, i);
}
 
void printArr(int arr[], int n)
{
    int i;

    for(i = 0; i < n; ++i)
        printf("%d", arr[i]);

    printf("\n");
}
 
int isLeaf(Node *root)
{
    return !(root->left) && !(root->right) ;
}
 
MinHeap *createAndBuildMinHeap(char data[], int freq[], int size)
{
    MinHeap *minHeap = createMinHeap(size);

    for(int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}
 
Node *buildHuffmanTree(char data[], int freq[], int size)
{
    Node *left, *right, *top;
    MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);

    while(minHeap->size != 1)
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}
 
void printCodes(Node *root, int arr[], int top)
{
    if(root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);}

    if(root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);}

    if(isLeaf(root)){

        printf("%c: ", root->data);
        printArr(arr, top);
    }
}
 
void HuffmanCodes(char data[], int freq[], int size)
{
   Node *root = buildHuffmanTree(data, freq, size);

   int arr[MAX_TREE_HT], top = 0;

   printCodes(root, arr, top);
}
 
int main()
{
    char arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[6] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);

    return 0;
}