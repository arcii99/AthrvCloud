//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TREE_HT 100

typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

typedef struct HuffmanNode {
    char data;
    char *code;
    struct HuffmanNode *next;
} HuffmanNode;

MinHeapNode* createMinHeapNode(char data, unsigned freq) {
    MinHeapNode* node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* minHeap, int idx) {
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

int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1)/2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->array[i] = minHeapNode;
}

int isLeaf(MinHeapNode* root) {
    return !(root->left) && !(root->right) ;
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = createMinHeapNode(data[i], freq[i]);
    minHeap->size = size;
    for (int i = size/2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}

MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {      
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(MinHeapNode* root, int arr[], int top) {
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
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void storeCodes(HuffmanNode** headRef, char data, char* code) {
    HuffmanNode* node = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    node->data = data;
    node->code = (char*) malloc(strlen(code) + 1);
    strcpy(node->code, code);
    node->next = NULL;
    if (!(*headRef)) {
        (*headRef) = node;
    }
    else {
        HuffmanNode* temp = (*headRef);
        while (temp->next) temp = temp->next;
        temp->next = node;
    }
}

void encodeHKString(char str[], HuffmanNode** head) {
    int i, size = strlen(str);
    int freq[256] = {0};
    char data[256] = {0};
    for (i = 0; i < size; ++i)
        freq[str[i]]++;
    int count = 0;
    for (i = 0; i < 256; ++i)
        if (freq[i] != 0) {
            data[count] = (char)i;
            count++;
        }
    MinHeapNode* root = buildHuffmanTree(data, freq, count);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
    char* code = (char*) malloc(sizeof(char) * MAX_TREE_HT);
    HuffmanNode* headTemp = NULL;
    for (i = 0; i < size; ++i) {
        headTemp = (*head);
        while (headTemp != NULL && headTemp->data != str[i])
            headTemp = headTemp->next;
        if (!headTemp) {
            top = 0;
            printCodes(root, arr, top);
            HuffmanNode* tempNode = (*head);
            while (tempNode && tempNode->next)
                tempNode = tempNode->next;
            code[0] = '\0';
            HuffmanNode* newNode = (HuffmanNode*) malloc(sizeof(HuffmanNode));
            newNode->data = str[i];
            getHuffmanCode(root, str[i], code, str[i], &newNode->code);
            newNode->next = NULL;
            if (!(*head))
                *head = newNode;
            else
                tempNode->next = newNode;
        }
        else {
            char* encodedCode = headTemp->code;
            printf("%s", encodedCode);
        }
    }
}

void getHuffmanCode(MinHeapNode* root, char key, char* code,
                    char keyName, char** keyFoundCode) {
    if (root) {
        if (root->data == key) {
            *keyFoundCode = (char*) malloc(strlen(code) + 1);
            strcpy(*keyFoundCode, code);
        }
        else {
            char* leftCode = (char*) malloc(strlen(code) + 2);
            char* rightCode = (char*) malloc(strlen(code) + 2);
            strcpy(leftCode, code);
            strcpy(rightCode, code);
            leftCode[strlen(code)] = '0';
            leftCode[strlen(code) + 1] = '\0';
            rightCode[strlen(code)] = '1';
            rightCode[strlen(code) + 1] = '\0';
            getHuffmanCode(root->left, key, leftCode, keyName, keyFoundCode);
            getHuffmanCode(root->right, key, rightCode, keyName, keyFoundCode);
        }
    }
}

void main() {
    char inputStr[1000];
    printf("Enter input string\n");
    scanf("%[^\n]%*c", inputStr);
    printf("\nEncoded string: ");
    HuffmanNode* head = NULL;
    encodeHKString(inputStr, &head);
    printf("\n\n");
}