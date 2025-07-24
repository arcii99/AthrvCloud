//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

struct node {
    char data;
    unsigned freq;
    struct node *left, *right;
};

struct heap {
    unsigned size;
    unsigned capacity;
    struct node **array;
};

struct node *create_node(char data, unsigned freq) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = data;
    new_node->freq = freq;
    return new_node;
}

struct heap *create_heap(unsigned capacity) {
    struct heap *new_heap = (struct heap *) malloc(sizeof(struct heap));
    new_heap->size = 0;
    new_heap->capacity = capacity;
    new_heap->array = (struct node **) malloc(new_heap->capacity * sizeof(struct node *));
    return new_heap;
}

void swap_node(struct node **a, struct node **b) {
    struct node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct heap *h, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < h->size && h->array[left]->freq < h->array[smallest]->freq) smallest = left;
    if (right < h->size && h->array[right]->freq < h->array[smallest]->freq) smallest = right;
    if (smallest != i) {
        swap_node(&h->array[smallest], &h->array[i]);
        heapify(h, smallest);
    }
}

int is_size_one(struct heap *h) { return h->size == 1; }

struct node *extract_min(struct heap *h) {
    struct node *temp = h->array[0];
    h->array[0] = h->array[h->size - 1];
    --h->size;
    heapify(h, 0);
    return temp;
}

void insert_min_heap(struct heap *h, struct node *new_node) {
    ++h->size;
    int i = h->size - 1;
    while (i && new_node->freq < h->array[(i - 1) / 2]->freq) {
        h->array[i] = h->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    h->array[i] = new_node;
}

void build_heap(struct heap *h) {
    int n = h->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) heapify(h, i);
}

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i) printf("%d", arr[i]);
    printf("\n");
}

int is_leaf(struct node *root) { return !(root->left) && !(root->right); }

struct heap *create_and_build_heap(char data[], int freq[], int size) {
    struct heap *h = create_heap(size);
    for (int i = 0; i < size; ++i) h->array[i] = create_node(data[i], freq[i]);
    h->size = size;
    build_heap(h);
    return h;
}

struct node *build_huffman_tree(char data[], int freq[], int size) {
    struct node *left, *right, *top;
    struct heap *h = create_and_build_heap(data, freq, size);
    while (!is_size_one(h)) {
        left = extract_min(h);
        right = extract_min(h);
        top = create_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert_min_heap(h, top);
    }
    return extract_min(h);
}

void print_codes(struct node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }
    if (is_leaf(root)) {
        printf("%c:", root->data);
        print_array(arr, top);
    }
}

void Huffman_code(char data[], int freq[], int size) {
    struct node *root = build_huffman_tree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    print_codes(root, arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    Huffman_code(data, freq, size);
    return 0;
}