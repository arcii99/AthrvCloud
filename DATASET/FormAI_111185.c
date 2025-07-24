//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TREE_HT 50

// Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// Min heap node structure
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

// Create a new Min Heap node
struct MinHeapNode* new_node(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Create a new Min Heap, capacity of size
struct MinHeap* create_min_heap(unsigned capacity)
{
    struct MinHeap* min_heap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    min_heap->size = 0;
    min_heap->capacity = capacity;
    min_heap->array = (struct MinHeapNode**) malloc(min_heap->capacity * sizeof(struct MinHeapNode*));
    return min_heap;
}

// Swap two Min Heap Nodes
void swap_min_heap_node(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify a min heap
void min_heapify(struct MinHeap* min_heap, int idx)
{
    int smallest = idx;
    int left_node = 2 * idx + 1;
    int right_node = 2 * idx + 2;
    if (left_node < min_heap->size && min_heap->array[left_node]->freq < min_heap->array[smallest]->freq)
        smallest = left_node;

    if (right_node < min_heap->size && min_heap->array[right_node]->freq < min_heap->array[smallest]->freq)
        smallest = right_node;

    if (smallest != idx) {
        swap_min_heap_node(&min_heap->array[smallest], &min_heap->array[idx]);
        min_heapify(min_heap, smallest);
    }
}

// Check if size becomes 1
bool is_size_one(struct MinHeap* min_heap)
{
    return (min_heap->size == 1);
}

// Extract the minimum element from the min heap
struct MinHeapNode* extract_min(struct MinHeap* min_heap)
{
    struct MinHeapNode* temp = min_heap->array[0];
    min_heap->array[0] = min_heap->array[min_heap->size - 1];
    --min_heap->size;
    min_heapify(min_heap, 0);
    return temp;
}

// Insert key into the min heap
void insert_min_heap(struct MinHeap* min_heap, struct MinHeapNode* min_heap_node)
{
    ++min_heap->size;
    int i = min_heap->size - 1;

    while (i && min_heap_node->freq < min_heap->array[(i - 1) / 2]->freq) {
        min_heap->array[i] = min_heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    min_heap->array[i] = min_heap_node;
}

// Check if Huffman Code can be generated or not
bool check_if_huffman_possible(int size, unsigned freq[])
{
    int freq_sum = 0;
    for (int i = 0; i < size; ++i) {
        freq_sum += freq[i];
    }

    return (freq_sum <= 1);
}

// Print Huffman codes
void print_huffman_codes(struct MinHeapNode* root, int arr[], int top)
{

    // Add '0' at the end of the code
    if (root->left) {
        arr[top] = 0;
        print_huffman_codes(root->left, arr, top + 1);
    }

    // Add '1' at the end of the code
    if (root->right) {
        arr[top] = 1;
        print_huffman_codes(root->right, arr, top + 1);
    }

    // Print leaf nodes
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Build a Huffman Tree
void build_huffman_tree(char data[], unsigned freq[], int size)
{
    struct MinHeapNode *left_child, *right_child, *top_node;
    struct MinHeap* min_heap = create_min_heap(size);

    for (int i = 0; i < size; ++i) {
        min_heap->array[i] = new_node(data[i], freq[i]);
    }

    min_heap->size = size;

    while (!is_size_one(min_heap)) {

        left_child = extract_min(min_heap);
        right_child = extract_min(min_heap);

        top_node = new_node('$', left_child->freq + right_child->freq);
        top_node->left = left_child;
        top_node->right = right_child;

        insert_min_heap(min_heap, top_node);
    }

    int arr[MAX_TREE_HT], top = 0;
    print_huffman_codes(extract_min(min_heap), arr, top);
}

// Driver program to test above functions
int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(data) / sizeof(data[0]);

    if (check_if_huffman_possible(size, freq)) {
        printf("Huffman codes can't be generated\n");
    }
    else {
        build_huffman_tree(data, freq, size);
    }

    return 0;
}