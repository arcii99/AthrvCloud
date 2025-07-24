//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct Node {
    char symbol;
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct MinHeap {
    int size;
    int capacity;
    Node **array;
} MinHeap;

MinHeap *create_min_heap(int capacity) {
    MinHeap *min_heap = (MinHeap*)malloc(sizeof(MinHeap));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (Node**)malloc(capacity*sizeof(Node*));
    return min_heap;
}

Node *create_node(char symbol, int freq) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->symbol = symbol;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void swap_nodes(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(MinHeap *min_heap, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < min_heap->size && min_heap->array[left]->freq < min_heap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < min_heap->size && min_heap->array[right]->freq < min_heap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != i) {
        swap_nodes(&min_heap->array[i], &min_heap->array[smallest]);
        min_heapify(min_heap, smallest);
    }
}

Node *extract_min_node(MinHeap *min_heap) {
    Node *min_node = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    min_heap->size--;
    min_heapify(min_heap, 0);
    return min_node;
}

void insert_node_to_min_heap(MinHeap *min_heap, Node *node) {
    min_heap->size++;
    int i = min_heap->size - 1;
    while (i > 0 && node->freq < min_heap->array[(i - 1)/2]->freq) {
        min_heap->array[i] = min_heap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    min_heap->array[i] = node;
}

int is_leaf_node(Node *node) {
    return node->left == NULL && node->right == NULL;
}

MinHeap *build_min_heap_from_frequency_table(char *input_string, int input_string_size) {
    int frequency_table[128] = {0};
    for (int i = 0; i < input_string_size; i++) {
        frequency_table[input_string[i]]++;
    }
    MinHeap *min_heap = create_min_heap(128);
    for (int i = 0; i < 128; i++) {
        if (frequency_table[i] != 0) {
            insert_node_to_min_heap(min_heap, create_node(i, frequency_table[i]));
        }
    }
    return min_heap;
}

Node *build_huffman_tree(MinHeap *min_heap) {
    while (min_heap->size > 1) {
        Node *left_node = extract_min_node(min_heap);
        Node *right_node = extract_min_node(min_heap);
        Node *parent_node = create_node('$', left_node->freq + right_node->freq);
        parent_node->left = left_node;
        parent_node->right = right_node;
        insert_node_to_min_heap(min_heap, parent_node);
    }
    return extract_min_node(min_heap);
}

void print_codes_from_tree(Node *root, int *codes, int top) {
    if (root->left) {
        codes[top] = 0;
        print_codes_from_tree(root->left, codes, top + 1);
    }
    if (root->right) {
        codes[top] = 1;
        print_codes_from_tree(root->right, codes, top + 1);
    }
    if (is_leaf_node(root)) {
        printf("%c: ", root->symbol);
        for (int i = 0; i < top; i++) {
            printf("%d", codes[i]);
        }
        printf("\n");
    }
}

void huffman_encoding(char *input_string, int input_string_size) {
    MinHeap *min_heap = build_min_heap_from_frequency_table(input_string, input_string_size);
    Node *root = build_huffman_tree(min_heap);
    int codes[MAX_TREE_HT], top = 0;
    print_codes_from_tree(root, codes, top);
}

int main() {
    char input_string[] = "Huffman coding is a data compression algorithm.";
    huffman_encoding(input_string, strlen(input_string));
    return 0;
}