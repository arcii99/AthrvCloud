//FormAI DATASET v1.0 Category: Compression algorithms ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 256

int getCharFrequency(char* str, int freq[])
{
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }
    return len;
}

void huffmanCode(char* str)
{
    int len = strlen(str);
    int freq[MAX_LENGTH] = { 0 };
    int size = getCharFrequency(str, freq);

    struct Node {
        char ch;
        int freq;
        struct Node* left, * right;
    };

    struct Node* heap[MAX_LENGTH] = { NULL };
    int heapSize = 0;

    for (int i = 0; i < MAX_LENGTH; i++) {
        if (freq[i]) {
            struct Node* node = (struct Node*)malloc(sizeof(struct Node));
            node->ch = i;
            node->freq = freq[i];
            node->left = node->right = NULL;
            heap[heapSize++] = node;
        }
    }

    while (heapSize > 1) {
        struct Node* left = heap[--heapSize];
        struct Node* right = heap[--heapSize];
        struct Node* root = (struct Node*)malloc(sizeof(struct Node));
        root->freq = left->freq + right->freq;
        root->left = left;
        root->right = right;
        heap[heapSize++] = root;
    }

    struct Node* root = heap[0];

    int codes[MAX_LENGTH] = { 0 };
    int top = 0;

    void printCodes(struct Node* node)
    {
        if (node->left) {
            codes[top++] = 0;
            printCodes(node->left);
            --top;
        }
        if (node->right) {
            codes[top++] = 1;
            printCodes(node->right);
            --top;
        }
        if (!node->left && !node->right) {
            printf("%c: ", node->ch);

            for (int i = 0; i < top; i++) {
                printf("%d", codes[i]);
            }
            printf("\n");
        }
    }

    printCodes(root);
}

int main()
{
    char str[] = "hello world!";
    huffmanCode(str);
    return 0;
}