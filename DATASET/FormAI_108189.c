//FormAI DATASET v1.0 Category: Compression algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#define BUFFER_SIZE 1024

typedef struct Node {
    struct Node *left;
    struct Node *right;
    int freq;
    char ch;
} Node;

typedef struct MinHeap {
    int size;
    int capacity;
    Node **array;
} MinHeap;

Node *get_new_node(int freq, char ch) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->freq = freq;
    node->ch = ch;
    return node;
}

MinHeap *create_min_heap(int capacity) {
    MinHeap *min_heap = (MinHeap *) malloc(sizeof(MinHeap));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (Node **) malloc(sizeof(Node *) * capacity);
    return min_heap;
}

void swap_node(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(MinHeap *min_heap, int index) {
    int smallest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    if (left_child < min_heap->size &&
        min_heap->array[left_child]->freq < min_heap->array[smallest]->freq) {
        smallest = left_child;
    }
    if (right_child < min_heap->size &&
        min_heap->array[right_child]->freq < min_heap->array[smallest]->freq) {
        smallest = right_child;
    }
    if (smallest != index) {
        swap_node(&min_heap->array[index], &min_heap->array[smallest]);
        min_heapify(min_heap, smallest);
    }
}

bool is_size_one(MinHeap *min_heap) {
    return min_heap->size == 1;
}

Node *extract_min(MinHeap *min_heap) {
    Node *temp = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    --min_heap->size;
    min_heapify(min_heap, 0);
    return temp;
}

void insert_min_heap(MinHeap *min_heap, Node *node) {
    ++min_heap->size;
    int index = min_heap->size - 1;
    while (index && node->freq < min_heap->array[(index - 1) / 2]->freq) {
        min_heap->array[index] = min_heap->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }
    min_heap->array[index] = node;
}

void build_min_heap(MinHeap *min_heap) {
    int n = min_heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        min_heapify(min_heap, i);
    }
}

void display_codes(Node *root, int *arr, int top) {
    if (root->left) {
        arr[top] = 0;
        display_codes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        display_codes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->ch);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void huffman_encoding(int *freq, char *chars, int n) {
    MinHeap *min_heap = create_min_heap(n);
    for (int i = 0; i < n; ++i) {
        insert_min_heap(min_heap, get_new_node(freq[i], chars[i]));
    }
    build_min_heap(min_heap);
    while (!is_size_one(min_heap)) {
        Node *left = extract_min(min_heap);
        Node *right = extract_min(min_heap);
        Node *new_node = get_new_node(left->freq + right->freq, '-');
        new_node->left = left;
        new_node->right = right;
        insert_min_heap(min_heap, new_node);
    }
    Node *root = extract_min(min_heap);
    int arr[BUFFER_SIZE], top = 0;
    display_codes(root, arr, top);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    int c;
    int freq[BUFFER_SIZE] = {0};
    while ((c = fgetc(fp)) != EOF) {
        ++freq[(unsigned char) c];
    }
    char chars[BUFFER_SIZE] = {0};
    int n = 0;
    for (int i = 0; i < BUFFER_SIZE; ++i) {
        if (freq[i]) {
            chars[n++] = i;
        }
    }
    fclose(fp);
    huffman_encoding(freq, chars, n);
    return 0;
}