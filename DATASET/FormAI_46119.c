//FormAI DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

struct min_heap_node {
    char data;
    unsigned freq;
    struct min_heap_node *left, *right;
};

struct min_heap {
    unsigned size;
    unsigned capacity;
    struct min_heap_node **array;
};

struct min_heap_node* new_node(char data, unsigned freq) {
    struct min_heap_node *node = (struct min_heap_node*) malloc(sizeof(struct min_heap_node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

struct min_heap* create_min_heap(unsigned capacity) {
    struct min_heap* heap = (struct min_heap*) malloc(sizeof(struct min_heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct min_heap_node**) malloc(heap->capacity * sizeof(struct min_heap_node*));
    return heap;
}

void swap_min_heap_node(struct min_heap_node** a, struct min_heap_node** b) {
    struct min_heap_node* t = *a;
    *a = *b;
    *b = t;
}

void min_heapify(struct min_heap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swap_min_heap_node(&heap->array[smallest], &heap->array[idx]);
        min_heapify(heap, smallest);
    }
}

int is_size_one(struct min_heap* heap) {
    return (heap->size == 1);
}

struct min_heap_node* extract_min(struct min_heap* heap) {
    struct min_heap_node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    min_heapify(heap, 0);
    return temp;
}

void insert_min_heap(struct min_heap* heap, struct min_heap_node* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void build_min_heap(struct min_heap* heap) {
    int n = heap->size - 1;
    int i;
    for(i = (n - 1) / 2; i >= 0; --i)
        min_heapify(heap, i);
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int is_leaf(struct min_heap_node* root) {
    return !(root->left) && !(root->right);
}

struct min_heap* create_and_build_min_heap(char data[], int freq[], int size) {
    struct min_heap* heap = create_min_heap(size);
    int i;
    for (i = 0; i < size; ++i) {
        heap->array[i] = new_node(data[i], freq[i]);
    }
    heap->size = size;
    build_min_heap(heap);
    return heap;
}

struct min_heap_node* build_huffman_tree(char data[], int freq[], int size) {
    struct min_heap_node *left, *right, *top;
    struct min_heap* heap = create_and_build_min_heap(data, freq, size);
    while (!is_size_one(heap)) {
        left = extract_min(heap);
        right = extract_min(heap);
        top = new_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert_min_heap(heap, top);
    }
    return extract_min(heap);
}

void print_codes(struct min_heap_node* root, int array[], int top) {
    if (root->left) {
        array[top] = 0;
        print_codes(root->left, array, top + 1);
    }
    if (root->right) {
        array[top] = 1;
        print_codes(root->right, array, top + 1);
    }
    if (is_leaf(root)) {
        printf("%c: ", root->data);
        print_array(array, top);
    }
}

void Huffman_codes(char data[], int freq[], int size) {
    struct min_heap_node* root = build_huffman_tree(data, freq, size);
    int array[MAX_TREE_HT], top = 0;
    print_codes(root, array, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    Huffman_codes(data, freq, size);
    return 0;
}