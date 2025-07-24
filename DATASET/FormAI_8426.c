//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100
#define MAX_CODE_LEN 100

typedef struct freq {
    char symbol;
    int frequency;
} Frequency;

typedef struct min_heap_node {
    char symbol;
    unsigned frequency;
    struct min_heap_node *left, *right;
} MinHeapNode;

typedef struct min_heap {
    unsigned size;
    unsigned capacity;
    MinHeapNode** heap_array;    
} MinHeap;

typedef struct huffman_node {
    char symbol;
    char* code;
    struct huffman_node *left, *right;
} HuffmanNode;

typedef struct symbol_code_map {
    char symbol;
    char *code;
} SymbolCodeMap;

MinHeapNode* create_min_heap_node(char symbol, unsigned frequency) {
    MinHeapNode* new_node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    new_node->left = new_node->right = NULL;
    new_node->frequency = frequency;
    new_node->symbol = symbol;

    return new_node;
}

MinHeap* create_min_heap(unsigned capacity) {
    MinHeap* new_heap = (MinHeap*)malloc(sizeof(MinHeap));
    new_heap->size = 0;
    new_heap->capacity = capacity;
    new_heap->heap_array = (MinHeapNode**)malloc(new_heap->capacity * sizeof(MinHeapNode*));
   
    return new_heap;
}

void swap_min_heap_nodes(MinHeapNode** x, MinHeapNode** y) {
    MinHeapNode* temp = *x;
    *x = *y;
    *y = temp;
}

void min_heapify(MinHeap* heap, int idx) {
    int smallest_index = idx;
    int left_index = 2*idx + 1;
    int right_index = 2*idx + 2;

    if(left_index < heap->size && heap->heap_array[left_index]->frequency < heap->heap_array[smallest_index]->frequency) {
        smallest_index = left_index;
    }

    if(right_index < heap->size && heap->heap_array[right_index]->frequency < heap->heap_array[smallest_index]->frequency) {
        smallest_index = right_index;
    }

    if(smallest_index != idx) {
        swap_min_heap_nodes(&heap->heap_array[smallest_index], &heap->heap_array[idx]);
        min_heapify(heap, smallest_index);
    }
}

bool is_size_one(MinHeap *heap) {
    return heap->size == 1;
}

MinHeapNode* extract_min(MinHeap* heap) {
    MinHeapNode* min_node = heap->heap_array[0];
    heap->heap_array[0] = heap->heap_array[heap->size - 1];

    heap->size--;
    min_heapify(heap, 0);

    return min_node;
}

void insert_min_heap(MinHeap* heap, MinHeapNode* node) {
    heap->size++;
    int i = heap->size - 1;

    while(i && node->frequency < heap->heap_array[(i-1)/2]->frequency) {
        heap->heap_array[i] = heap->heap_array[(i-1)/2];
        i = (i-1)/2;
    }

    heap->heap_array[i] = node;
}

void build_min_heap(MinHeap* heap) {
    int n = heap->size - 1;
    int i;
    for(i=(n-1)/2; i>=0; i--) {
        min_heapify(heap, i);
    }
}

MinHeap* create_and_build_min_heap(Frequency* freq_list, int size) {
    MinHeap* heap = create_min_heap(size);

    int i;
    for(i=0; i<size; i++) {
        heap->heap_array[i] = create_min_heap_node(freq_list[i].symbol, freq_list[i].frequency);
    }

    heap->size = size;

    build_min_heap(heap);

    return heap;
}

HuffmanNode* create_huffman_node(char symbol, char* code) {
    HuffmanNode* new_node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    new_node->left = new_node->right = NULL;
    new_node->symbol = symbol;
    new_node->code = code;

    return new_node;
}

void destroy_huffman_tree(HuffmanNode* root) {
    if(root == NULL) {
        return;
    }

    destroy_huffman_tree(root->left);
    destroy_huffman_tree(root->right);

    free(root);
}

void create_symbol_code_map(HuffmanNode* root, SymbolCodeMap *symbol_code_map, char* code, int index) {
    if(root->left != NULL) {
        char* leftCode = (char*)malloc(MAX_CODE_LEN * sizeof(char));
        strcpy(leftCode, code);
        leftCode[index] = '0';
        create_symbol_code_map(root->left, symbol_code_map, leftCode, index+1);
    }

    if(root->right != NULL) {
        char* rightCode = (char*)malloc(MAX_CODE_LEN * sizeof(char));
        strcpy(rightCode, code);
        rightCode[index] = '1';
        create_symbol_code_map(root->right, symbol_code_map, rightCode, index+1);
    }

    if(root->left == NULL && root->right == NULL) {
        SymbolCodeMap new_symbol_code_map;
        new_symbol_code_map.symbol = root->symbol;
        new_symbol_code_map.code = (char*)malloc(MAX_CODE_LEN * sizeof(char));
        strcpy(new_symbol_code_map.code, code);

        symbol_code_map[root->symbol - 'a'] = new_symbol_code_map;
    }
}

void print_symbol_codes(SymbolCodeMap *symbol_code_map) {
    printf("--- Symbol Codes ---\n");
    int i;
    for(i=0; i<26; i++) {
        if(symbol_code_map[i].symbol != '\0') {
            printf("%c : %s\n", symbol_code_map[i].symbol, symbol_code_map[i].code);
        }
    }
}

void encode(char *data, SymbolCodeMap *symbol_code_map, char *encoded_data) {
    int n = strlen(data);
    int i;
    int encoded_data_index = 0;
    for(i=0; i<n; i++) {
        int index = data[i] - 'a';
        strcat(encoded_data, symbol_code_map[index].code);
    }
}

void decode(HuffmanNode *root, char *encoded_data) {
    int n = strlen(encoded_data);
    int i;
    HuffmanNode *current_node = root;
    for(i=0; i<n; i++) {
        if(encoded_data[i] == '0') {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }

        if(current_node->left == NULL && current_node->right == NULL) {
            printf("%c", current_node->symbol);
            current_node = root;
        }
    }
}

void huffman_encoding(char *data) {
    int n = strlen(data);
    int i;
    Frequency freq_list[26];
    for(i=0; i<26; i++) {
        freq_list[i].symbol = i + 'a';
        freq_list[i].frequency = 0;
    }

    for(i=0; i<n; i++) {
        int index = data[i] - 'a';
        freq_list[index].frequency++;
    }

    MinHeap *heap = create_and_build_min_heap(freq_list, 26);

    while(!is_size_one(heap)) {
        MinHeapNode *node1 = extract_min(heap);
        MinHeapNode *node2 = extract_min(heap);

        int new_freq = node1->frequency + node2->frequency;

        MinHeapNode *new_node = create_min_heap_node('\0', new_freq);
        new_node->left = node1;
        new_node->right = node2;

        insert_min_heap(heap, new_node);
    }

    HuffmanNode *root = (HuffmanNode*)extract_min(heap);
    SymbolCodeMap symbol_code_map[26];
    char code[MAX_CODE_LEN] = {'\0'};
    create_symbol_code_map(root, symbol_code_map, code, 0);
    print_symbol_codes(symbol_code_map);

    char encoded_data[MAX_CODE_LEN] = {'\0'};
    encode(data, symbol_code_map, encoded_data);
    printf("\n--- Encoded Data ---\n%s\n", encoded_data);

    printf("\n--- Decoded Data ---\n");
    decode(root, encoded_data);
    printf("\n");

    destroy_huffman_tree(root);
    free(heap->heap_array);
    free(heap);
}

int main() {
    char data[] = "huffman coding";
    huffman_encoding(data);
    return 0;
}