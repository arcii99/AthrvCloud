//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define SYMBOL_COUNT 256

/* Define a binary tree node */
typedef struct TreeNode {
    unsigned char symbol;
    int frequency;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/* Define a MinHeap data structure */
typedef struct MinHeap {
    int size;
    int capacity;
    TreeNode **array;
} MinHeap;

/* Function to create a new binary tree node */
TreeNode* new_node(unsigned char symbol, int frequency) {
    TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to swap two nodes in the MinHeap */
void swap_nodes(TreeNode **a, TreeNode **b) {
    TreeNode *temp = *a;
    *a = *b;
    *b = temp;
}

/* Heapify function to maintain the MinHeap property */
void heapify(MinHeap *heap, int index) {
    int smallest = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;

    if (left_child < heap->size && heap->array[left_child]->frequency < heap->array[smallest]->frequency) {
        smallest = left_child;
    }

    if (right_child < heap->size && heap->array[right_child]->frequency < heap->array[smallest]->frequency) {
        smallest = right_child;
    }

    if (smallest != index) {
        swap_nodes(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

/* Function to create a new MinHeap */
MinHeap* new_min_heap(int capacity) {
    MinHeap *heap = (MinHeap *) malloc(sizeof(MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (TreeNode **) malloc(capacity * sizeof(TreeNode *));
    return heap;
}

/* Function to extract the minimum element from the MinHeap */
TreeNode* extract_min(MinHeap *heap) {
    TreeNode *min_node = heap->array[0];
    heap->array[0] = heap->array[heap->size-1];
    heap->size--;
    heapify(heap, 0);
    return min_node;
}

/* Function to insert a new node into the MinHeap */
void insert_node(MinHeap *heap, TreeNode *node) {
    heap->size++;
    int i = heap->size-1;

    while (i > 0 && node->frequency < heap->array[(i-1)/2]->frequency) {
        heap->array[i] = heap->array[(i-1)/2];
        i = (i-1)/2;
    }

    heap->array[i] = node;
}

/* Function to check if the given node is a leaf node */
int is_leaf(TreeNode *node) {
    return (node->left == NULL && node->right == NULL);
}

/* Function to traverse the Huffman tree and build the Huffman code for each symbol */
void build_huffman_code(TreeNode *node, int *code, int depth, int **codes) {
    if (node == NULL) {
        return;
    }

    if (is_leaf(node)) {
        codes[node->symbol] = (int *) malloc(depth * sizeof(int));
        for (int i = 0; i < depth; i++) {
            codes[node->symbol][i] = code[i];
        }
        return;
    }

    code[depth] = 0;
    build_huffman_code(node->left, code, depth+1, codes);

    code[depth] = 1;
    build_huffman_code(node->right, code, depth+1, codes);
}

/* Function to build the Huffman tree and return the codes for each symbol */
int** huffman_encode(char *input, int length, int *code_length) {
    /* Calculate the frequency of each symbol */
    int frequency[SYMBOL_COUNT] = {0};
    for (int i = 0; i < length; i++) {
        frequency[input[i]]++;
    }

    /* Create a MinHeap of binary tree nodes */
    MinHeap *heap = new_min_heap(SYMBOL_COUNT);
    for (int i = 0; i < SYMBOL_COUNT; i++) {
        if (frequency[i] > 0) {
            insert_node(heap, new_node(i, frequency[i]));
        }
    }

    /* Build the Huffman tree */
    while (heap->size != 1) {
        TreeNode *left = extract_min(heap);
        TreeNode *right = extract_min(heap);
        TreeNode *parent = new_node('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        insert_node(heap, parent);
    }

    /* Traverse the Huffman tree to build the Huffman codes */
    int *code = (int *) malloc(SYMBOL_COUNT * sizeof(int));
    int **codes = (int **) malloc(SYMBOL_COUNT * sizeof(int *));
    build_huffman_code(heap->array[0], code, 0, codes);

    /* Calculate the total length of the encoded message */
    int total_length = 0;
    for (int i = 0; i < length; i++) {
        total_length += code_length[input[i]];
    }
    *code_length = total_length;

    /* Return the Huffman codes */
    return codes;
}

/* Main function */
int main() {
    /* Read the input string */
    char input[100];
    printf("Enter the input string: ");
    fgets(input, 100, stdin);

    /* Calculate the length of the input string */
    int length = 0;
    while (input[length] != '\0') {
        length++;
    }

    /* Calculate the length of the Huffman codes for each symbol */
    int code_length[SYMBOL_COUNT] = {0};
    for (int i = 0; i < SYMBOL_COUNT; i++) {
        code_length[i] = 0;
    }
    int **codes = huffman_encode(input, length-1, code_length);

    /* Print the Huffman codes for each symbol */
    printf("Huffman Codes:\n");
    for (int i = 0; i < SYMBOL_COUNT; i++) {
        if (codes[i] != NULL) {
            printf("%c: ", i);
            for (int j = 0; j < code_length[i]; j++) {
                printf("%d", codes[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}