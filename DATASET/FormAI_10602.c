//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 256

typedef struct Node {
    int value;
    char character;
    struct Node *left, *right;
} Node;

typedef struct Heap {
    int size;
    int capacity;
    Node **array;
} Heap;

Node *create_new_node(int value, char character) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->value = value;
    new_node->character = character;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Heap *create_heap(int capacity) {
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (Node **) malloc(heap->capacity * sizeof(Node *));
    return heap;
}

void swap_nodes(Node **x, Node **y) {
    Node *temp = *x;
    *x = *y;
    *y = temp;
}

void min_heapify(Heap *heap, int index) {
    int smallest = index;
    int left_child = (2 * index) + 1;
    int right_child = (2 * index) + 2;

    if (left_child < heap->size && heap->array[left_child]->value < heap->array[smallest]->value)
        smallest = left_child;

    if (right_child < heap->size && heap->array[right_child]->value < heap->array[smallest]->value)
        smallest = right_child;

    if (smallest != index) {
        swap_nodes(&heap->array[smallest], &heap->array[index]);
        min_heapify(heap, smallest);
    }
}

Heap *build_heap(char *data, int *frequencies) {
    Heap *heap = create_heap(MAX_TREE_HT);
    for (int i = 0; i < strlen(data); i++) {
        Node *new_node = create_new_node(frequencies[data[i]], data[i]);
        heap->array[heap->size++] = new_node;
    }

    for (int i = heap->size / 2 - 1; i >= 0; --i)
        min_heapify(heap, i);

    return heap;
}

Node *build_huffman_tree(char *data, int *frequencies) {
    Heap *heap = build_heap(data, frequencies);
    Node *root = NULL;

    while (heap->size > 1) {
        Node *node1 = heap->array[0];
        heap->array[0] = heap->array[heap->size - 1];
        --heap->size;
        min_heapify(heap, 0);

        Node *node2 = heap->array[0];
        heap->array[0] = heap->array[heap->size - 1];
        --heap->size;
        min_heapify(heap, 0);

        Node *new_node = create_new_node(node1->value + node2->value, '*');
        new_node->left = node1;
        new_node->right = node2;

        root = new_node;
        heap->array[heap->size++] = new_node;
        min_heapify(heap, heap->size - 1);
    }

    return root;
}

void print_codes(Node *root, int array[], int top) {
    if (root->left) {
        array[top] = 0;
        print_codes(root->left, array, top + 1);
    }

    if (root->right) {
        array[top] = 1;
        print_codes(root->right, array, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", array[i]);
        }
        printf("\n");
    }
}

void huffman_compress(char *data, int length) {
    int frequencies[256] = {0};
    for (int i = 0; i < length; ++i) {
        frequencies[data[i]]++;
    }

    Node *root = build_huffman_tree(data, frequencies);
    int array[MAX_TREE_HT] = {0};
    print_codes(root, array, 0);
}

int main() {
    char data[] = "hello world";
    int length = strlen(data);

    huffman_compress(data, length);

    return 0;
}