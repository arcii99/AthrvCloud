//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: funny
//Welcome to the Huffman Coding Program!
//Today we shall be encoding some words,
//And hopefully, we shall have loads of fun!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for each node in the tree
typedef struct node{
    char character;
    int frequency;
    struct node *left_child;
    struct node *right_child;
} Node;

//Function to create a node and initialize its values
Node* createNode(char c, int freq){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = c;
    newNode->frequency = freq;
    newNode->left_child = NULL;
    newNode->right_child = NULL;
    return newNode;
}

//Min heap structure for storing nodes
typedef struct minHeap{
    int size;
    int capacity;
    Node** nodes;
} MinHeap;

//Function to create a new empty min heap
MinHeap* createMinHeap(int capacity){
    MinHeap* newHeap = (MinHeap*)malloc(sizeof(MinHeap));
    newHeap->size = 0;
    newHeap->capacity = capacity;
    newHeap->nodes = (Node**)malloc(capacity * sizeof(Node*));
    return newHeap;
}

//Function to swap two nodes in the min heap
void swapNodes(Node** a, Node** b){
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

//Function to heapify the min heap by fixing the min-heap property
void heapify(MinHeap* heap, int index){
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    if(leftChild < heap->size && heap->nodes[leftChild]->frequency < heap->nodes[smallest]->frequency){
        smallest = leftChild;
    }
    if(rightChild < heap->size && heap->nodes[rightChild]->frequency < heap->nodes[smallest]->frequency){
        smallest = rightChild;
    }
    if(smallest != index){
        swapNodes(&heap->nodes[smallest], &heap->nodes[index]);
        heapify(heap, smallest);
    }
}

//Function to insert a node into the min heap
void insertNode(MinHeap* heap, Node* newNode){
    heap->size++;
    int index = heap->size - 1;
    while(index && newNode->frequency < heap->nodes[(index - 1) / 2]->frequency){
        heap->nodes[index] = heap->nodes[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    heap->nodes[index] = newNode;
}

//Function to extract the minimum value from the min heap
Node* extractMin(MinHeap* heap){
    Node* min = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return min;
}

//Function to check if the node is a leaf node
int isLeaf(Node* node){
    return !(node->left_child) && !(node->right_child);
}

//Function to build the Huffman tree
Node* buildHuffmanTree(char* text, int* frequency){
    MinHeap* heap = createMinHeap(strlen(text));
    for(int i = 0; i < strlen(text); i++){
        insertNode(heap, createNode(text[i], frequency[i]));
    }
    while(heap->size > 1){
        Node* left = extractMin(heap);
        Node* right = extractMin(heap);
        Node* parent = createNode('#', left->frequency + right->frequency);
        parent->left_child = left;
        parent->right_child = right;
        insertNode(heap, parent);
    }
    return extractMin(heap);
}

//Function to traverse the Huffman tree and get the Huffman codes
void generateCodes(Node* root, int code[], int top){
    if(root->left_child){
        code[top] = 0;
        generateCodes(root->left_child, code, top + 1);
    }
    if(root->right_child){
        code[top] = 1;
        generateCodes(root->right_child, code, top + 1);
    }
    if(isLeaf(root)){
        printf("%c: ", root->character);
        for(int i = 0; i < top; i++){
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

//Main function to drive the program
int main(){
    char* text = "huffmancoding";
    int frequency[14] = {2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Node* root = buildHuffmanTree(text, frequency);
    int code[50], top = 0;
    printf("Huffman Codes:\n");
    generateCodes(root, code, top);
    return 0;
}