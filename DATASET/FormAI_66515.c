//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Data structure to hold frequency of characters
struct freq {
    int frequency;
    char character;
};

// Data structure to hold Huffman tree nodes
struct huffman_node {
    char data;
    int frequency;
    struct huffman_node *left, *right;
};

// Data structure for a heap node
struct heap_node {
    char data;
    int frequency;
    struct heap_node *left, *right;
};

// Priority queue data structure
struct priority_queue {
    int size;
    int capacity;
    struct heap_node **heap_array;
};

// Create a new Huffman node
struct huffman_node* new_huffman_node(char data, int frequency) {
    struct huffman_node* node = (struct huffman_node*)malloc(sizeof(struct huffman_node));
    node->data = data;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Create a new heap node
struct heap_node* new_heap_node(char data, int frequency) {
    struct heap_node* node = (struct heap_node*)malloc(sizeof(struct heap_node));
    node->data = data;
    node->frequency = frequency;
    node->left = node->right = NULL;
    return node;
}

// Create a new priority queue
struct priority_queue* create_priority_queue(int capacity) {
    struct priority_queue* pq = (struct priority_queue*)malloc(sizeof(struct priority_queue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->heap_array = (struct heap_node**)malloc(pq->capacity * sizeof(struct heap_node*));
    return pq;
}

// Swap two heap nodes
void swap_heap_nodes(struct heap_node** a, struct heap_node** b) {
    struct heap_node* temp = *a;
    *a = *b;
    *b = temp;
}

// Min heapify function for the priority queue
void min_heapify(struct priority_queue* pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < pq->size && pq->heap_array[left]->frequency < pq->heap_array[smallest]->frequency)
        smallest = left;
    if (right < pq->size && pq->heap_array[right]->frequency < pq->heap_array[smallest]->frequency)
        smallest = right;
    if (smallest != index) {
        swap_heap_nodes(&pq->heap_array[index], &pq->heap_array[smallest]);
        min_heapify(pq, smallest);
    }
}

// Check if priority queue is empty
int is_empty(struct priority_queue* pq) {
    return pq->size == 0;
}

// Extract minimum element from priority queue
struct heap_node* extract_min(struct priority_queue* pq) {
    struct heap_node* heap_node = pq->heap_array[0];
    pq->heap_array[0] = pq->heap_array[pq->size - 1];
    pq->size--;
    min_heapify(pq, 0);
    return heap_node;
}

// Insert an element to the priority queue
void insert(struct priority_queue* pq, struct heap_node* heap_node) {
    pq->size++;
    int i = pq->size - 1;
    while (i && heap_node->frequency < pq->heap_array[(i - 1) / 2]->frequency) {
        pq->heap_array[i] = pq->heap_array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->heap_array[i] = heap_node;
}

// Build Huffman tree from the frequency table
struct huffman_node* build_huffman_tree(struct freq* frequency_table, int size) {
    struct huffman_node *left, *right, *top;
    // Create a priority queue of heap nodes from the frequency table
    struct priority_queue* pq = create_priority_queue(size);
    for (int i = 0; i < size; ++i)
        insert(pq, new_heap_node(frequency_table[i].character, frequency_table[i].frequency));
    // Build Huffman tree from the priority queue
    while (pq->size != 1) {
        left = extract_min(pq);
        right = extract_min(pq);
        top = new_huffman_node('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insert(pq, top);
    }
    return extract_min(pq);
}

// Utility function to check for leaf node
int is_leaf(struct huffman_node* node) {
    return !(node->left) && !(node->right);
}

// Utility function for printing Huffman codes from the Huffman tree
void print_huffman_codes(struct huffman_node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_huffman_codes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        print_huffman_codes(root->right, arr, top + 1);
    }
    if (is_leaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Huffman coding function
void huffman_encoding(char* input_string) {
    int n = strlen(input_string), top = 0;
    struct freq frequency_table[MAX_TREE_HT];
    int frequency_count = 0;
    // Create frequency table for all characters in the input string
    for (int i = 0; i < n; i++) {
        int j;
        for(j = 0; j < frequency_count; j++) {
            if(input_string[i] == frequency_table[j].character) {
                frequency_table[j].frequency++;
                break;
            }
        }
        if (j == frequency_count) {
            frequency_table[frequency_count].character = input_string[i];
            frequency_table[frequency_count].frequency = 1;
            frequency_count++;
        }
    }
    // Build Huffman tree and print Huffman codes
    struct huffman_node* root = build_huffman_tree(frequency_table, frequency_count);
    int arr[MAX_TREE_HT];
    print_huffman_codes(root, arr, top);
}

int main() {
    char input_string[] = "hello world";
    huffman_encoding(input_string);
    return 0;
}