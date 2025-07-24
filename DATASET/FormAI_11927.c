//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct node {
    char data;
    unsigned freq;
    struct node *left, *right;
} node;

typedef struct heap {
    unsigned size;
    unsigned capacity;
    node **array;
} heap;

node *new_node(char data, unsigned freq) {
    node *temp = (node *) malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

heap *create_heap(unsigned capacity) {
    heap *temp = (heap *) malloc(sizeof(heap));
    temp->size = 0;
    temp->capacity = capacity;
    temp->array = (node **) malloc(capacity * sizeof(node *));
    return temp;
}

void swap_node(node **a, node **b) {
    node *t = *a;
    *a = *b;
    *b = t;
}

void heapify(heap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swap_node(&heap->array[smallest], &heap->array[idx]);
        heapify(heap, smallest);
    }
}

int is_size_one(heap *heap) {
    return heap->size == 1;
}

node *extract_min(heap *heap) {
    node *temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    heapify(heap, 0);
    return temp;
}

void insert_heap(heap *heap, node *temp) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && temp->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = temp;
}

void build_heap(heap *heap) {
    int n = heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        heapify(heap, i);
    }
}

void print_arr(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int is_leaf(node *root) {
    return !(root->left) && !(root->right);
}

heap *create_and_build_heap(char data[], int freq[], int size) {
    heap *heap = create_heap(size);
    for (int i = 0; i < size; i++)
        heap->array[i] = new_node(data[i], freq[i]);
    heap->size = size;
    build_heap(heap);
    return heap;
}

node *build_huffman_tree(char data[], int freq[], int size) {
    node *left, *right, *top;
    heap *heap = create_and_build_heap(data, freq, size);
    while (!is_size_one(heap)) {
        left = extract_min(heap);
        right = extract_min(heap);
        top = new_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert_heap(heap, top);
    }
    return extract_min(heap);
}

void encode(node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        encode(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        encode(root->right, arr, top + 1);
    }
    if (is_leaf(root)) {
        printf("%c: ", root->data);
        print_arr(arr, top);
    }
}

void huffman_code(char data[], int freq[], int size) {
    node *root = build_huffman_tree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    encode(root, arr, top);
}

int main() {
    char arr_char[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int arr_freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr_char) / sizeof(arr_char[0]);
    huffman_code(arr_char, arr_freq, size);
    return 0;
}