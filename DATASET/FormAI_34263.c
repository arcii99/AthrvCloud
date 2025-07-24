//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

typedef struct TreeNode {
    char data;
    unsigned frequency;
    struct TreeNode *left, *right;
} TreeNode;

typedef struct MinHeap {
    unsigned heap_size;
    unsigned capacity;
    TreeNode** array;
} MinHeap;

TreeNode* create_node(char data, unsigned frequency) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

MinHeap* create_min_heap(unsigned capacity) {
    MinHeap* min_heap = (MinHeap*) malloc(sizeof(MinHeap));
    min_heap->heap_size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (TreeNode**)malloc(min_heap->capacity * sizeof(TreeNode*));
    return min_heap;
}

void swap_nodes(TreeNode** a, TreeNode** b) {
    TreeNode* t = *a;
    *a = *b;
    *b = t;
}

void min_heapify(MinHeap* min_heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < min_heap->heap_size && min_heap->array[left]->frequency < min_heap->array[smallest]->frequency)
        smallest = left;

    if (right < min_heap->heap_size && min_heap->array[right]->frequency < min_heap->array[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swap_nodes(&min_heap->array[smallest], &min_heap->array[index]);
        min_heapify(min_heap, smallest);
    }
}

int is_size_one(MinHeap* min_heap) {
    return (min_heap->heap_size == 1);
}

TreeNode* extract_min_node(MinHeap* min_heap) {
    TreeNode* temp = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->heap_size - 1];
    --min_heap->heap_size;
    min_heapify(min_heap, 0);
    return temp;
}

void insert_node(MinHeap* min_heap, TreeNode* tree_node) {
    ++min_heap->heap_size;
    int i = min_heap->heap_size - 1;

    while (i && tree_node->frequency < min_heap->array[(i - 1) / 2]->frequency) {
        min_heap->array[i] = min_heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    min_heap->array[i] = tree_node;
}

void build_min_heap(MinHeap* min_heap) {
    int n = min_heap->heap_size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        min_heapify(min_heap, i);
}

int is_leaf(TreeNode* node) {
    return !(node->left) && !(node->right);
}

MinHeap* create_and_build_min_heap(char data[], int frequency[], int size) {
    MinHeap* min_heap = create_min_heap(size);

    for (int i = 0; i < size; ++i)
        min_heap->array[i] = create_node(data[i], frequency[i]);

    min_heap->heap_size = size;
    build_min_heap(min_heap);

    return min_heap;
}

TreeNode* build_huffman_tree(char data[], int frequency[], int size) {
    TreeNode *left, *right, *top;
    MinHeap* min_heap = create_and_build_min_heap(data, frequency, size);

    while (!is_size_one(min_heap)) {
        left = extract_min_node(min_heap);
        right = extract_min_node(min_heap);
        top = create_node('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insert_node(min_heap, top);
    }

    return extract_min_node(min_heap);
}

void print_codes(TreeNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }

    if (is_leaf(root)) {
        printf("%c -> ", root->data);

        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);

        printf("\n");
    }
}

void huffman_encoding(char data[], int frequency[], int size) {
    TreeNode* root = build_huffman_tree(data, frequency, size);
    int arr[MAX_TREE_HT], top = 0;
    print_codes(root, arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e'};
    int frequency[] = {5, 1, 2, 6, 3};
    int size = sizeof(data) / sizeof(data[0]);

    huffman_encoding(data, frequency, size);

    return 0;
}