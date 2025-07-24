//FormAI DATASET v1.0 Category: Compression algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_SYMBOLS 256
#define BUF_SIZE    4096

typedef struct codeword {
    unsigned int length;
    unsigned int value;
} codeword;

typedef struct huffman_tree_node {
    unsigned int count;
    bool         used;
    codeword     code;
    struct huffman_tree_node* left;
    struct huffman_tree_node* right;
} huffman_tree_node;

static int freq[NUM_SYMBOLS];
static codeword codewords[NUM_SYMBOLS];

// Comparison function for sorting codewords by their length and value
static int codeword_compare(const void* a, const void* b)
{
    const codeword* cw1 = (const codeword*)a;
    const codeword* cw2 = (const codeword*)b;
    int diff;

    diff = (int)cw1->length - (int)cw2->length;
    if (diff == 0)
        diff = (int)cw1->value - (int)cw2->value;

    return diff;
}

// Recursive function for building the Huffman tree
static huffman_tree_node* build_huffman_tree(int* freq, int num_symbols)
{
    huffman_tree_node* nodes;
    huffman_tree_node* node;
    huffman_tree_node* min1;
    huffman_tree_node* min2;
    int i, j;

    nodes = (huffman_tree_node*)malloc(num_symbols*sizeof(huffman_tree_node));

    // Create leaf nodes
    for (i = 0; i < num_symbols; i++) {
        nodes[i].count = freq[i];
        nodes[i].used  = false;
        nodes[i].left  = NULL;
        nodes[i].right = NULL;
    }

    // Build tree by iteratively merging lowest count nodes
    for (j = num_symbols; j > 1; j--) {
        // Find two unused nodes with lowest counts
        min1 = min2 = NULL;
        for (i = 0; i < num_symbols; i++) {
            node = &nodes[i];
            if (!node->used) {
                if (min1 == NULL || node->count < min1->count) {
                    min2 = min1;
                    min1 = node;
                } else if (min2 == NULL || node->count < min2->count) {
                    min2 = node;
                }
            }
        }
        // Mark nodes as used and create new parent node
        min1->used  = true;
        min2->used  = true;
        node = &nodes[j-2];
        node->count = min1->count + min2->count;
        node->used  = false;
        node->left  = min1;
        node->right = min2;
    }

    return &nodes[num_symbols-2];
}

// Recursive function for assigning codewords to leaf nodes
static void assign_codewords(huffman_tree_node* node, int length, unsigned int value)
{
    if (node->left == NULL && node->right == NULL) {
        node->code.length = length;
        node->code.value  = value;
        if (value < NUM_SYMBOLS)
            codewords[value] = node->code;
    } else {
        assign_codewords(node->left, length+1, (value<<1));
        assign_codewords(node->right, length+1, (value<<1)|1);
    }
}

// Read input, calculate frequency table and build Huffman tree
static huffman_tree_node* build_tree_from_input()
{
    int i, c;
    huffman_tree_node* root;

    for (i = 0; i < NUM_SYMBOLS; i++) {
        freq[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        freq[c]++;
    }

    root = build_huffman_tree(freq, NUM_SYMBOLS);
    assign_codewords(root, 0, 0);

    return root;
}

// Write out codewords in table form
static void write_codeword_table()
{
    int i;
    printf("Codeword table:\n");
    for (i = 0; i < NUM_SYMBOLS; i++) {
        if (codewords[i].length > 0) {
            printf("%02X: %0*X\n", i, (codewords[i].length+3)/4, codewords[i].value);
        }
    }
}

// Write out compressed data using assigned codewords
static void compress_input(huffman_tree_node* root)
{
    unsigned int buffer = 0;
    int bits = 0;
    int c;

    while ((c = getchar()) != EOF) {
        codeword cw = codewords[c];
        if (cw.length > 0) {
            while (cw.length > 0) {
                buffer |= (cw.value >> (--cw.length)) & 1;
                if (++bits == 32) {
                    putc(buffer>>24, stdout);
                    putc(buffer>>16, stdout);
                    putc(buffer>>8, stdout);
                    putc(buffer, stdout);
                    bits = 0;
                    buffer = 0;
                } else {
                    buffer <<= 1;
                }
            }
        }
    }

    if (bits > 0) {
        buffer <<= (32-bits);
        putc(buffer>>24, stdout);
        if (bits >= 16) putc(buffer>>16, stdout);
        if (bits >=  8) putc(buffer>> 8, stdout);
    }
}

int main(int argc, char** argv)
{
    huffman_tree_node* root;

    root = build_tree_from_input();
    write_codeword_table();
    compress_input(root);

    return 0;
}