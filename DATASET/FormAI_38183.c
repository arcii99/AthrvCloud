//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char data;
    int freq;
    struct node *left, *right;
} node;

typedef struct min_heap {
    int size;
    int capacity;
    node **array;
} min_heap;

node *new_node(char data, int freq) {
    node *temp = (node *) malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

min_heap *create_heap(int capacity) {
    min_heap *heap = (min_heap *) malloc(sizeof(min_heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (node **) malloc(capacity * sizeof(node *));
    return heap;
}

void swap(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(min_heap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swap(&heap->array[smallest], &heap->array[idx]);
        min_heapify(heap, smallest);
    }
}

int is_size_one(min_heap* heap) {
    return (heap->size == 1);
}

node *extract_min(min_heap* heap) {
    node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    min_heapify(heap, 0);
    return temp;
}

void insert(min_heap* heap, node* temp) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && temp->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = temp;
}

void build_heap(min_heap* heap) {
    int n = heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        min_heapify(heap, i);
}

int is_leaf(node* root) {
    return !(root->left) && !(root->right);
}

min_heap *build_heap_frequency(int *freq, char *data, int size) {
    int i;
    min_heap *heap = create_heap(size);
    for (i = 0; i < size; ++i)
        heap->array[i] = new_node(data[i], freq[i]);
    heap->size = size;
    build_heap(heap);
    return heap;
}

node* build_huffman_tree(int *freq, char *data, int size) {
    node *left, *right, *top;
    min_heap *heap = build_heap_frequency(freq, data, size);


    while (!is_size_one(heap)) {
        left = extract_min(heap);
        right = extract_min(heap);
        top = new_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insert(heap, top);
    }
    return extract_min(heap);
}

void print_codes(node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }
    if (is_leaf(root)) {
        printf(" %c | ", root->data);
        int i;
        for (i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void huffman_codes(int freq[], char data[], int size) {
    node *root = build_huffman_tree(freq, data, size);
    int arr[size], top = 0;
    printf("Character\tHuffman Codes\n");
    print_codes(root, arr, top);
}

int main() {
    int size, i;
    char data[100], ch;
    int freq[100];
    printf("Enter the number of characters: ");
    scanf("%d", &size);
    printf("Enter the characters with their frequencies:\n");
    for (i = 0; i < size; ++i) {
        scanf(" %c%d", &data[i], &freq[i]);
    }
    huffman_codes(freq, data, size);
    return 0;
}