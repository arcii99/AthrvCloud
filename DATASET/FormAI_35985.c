//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define ASCII_SIZE 256
#define BUFFER_SIZE 1000

typedef struct Leaf {
    int freq;
    unsigned char symbol;
} Leaf;

typedef struct Tree {
    int freq;
    struct Tree *left;
    struct Tree *right;
} Tree;

typedef struct Code {
    unsigned int code;
    unsigned int length;
} Code;

typedef struct HuffmanCode {
    Code *codes;
    Leaf *leaves;
    int size;
} HuffmanCode;

int compare(const void *a, const void *b) {
    Leaf *x = (Leaf *)a;
    Leaf *y = (Leaf *)b;

    if (x->freq == y->freq) {
        return x->symbol - y->symbol;
    } else {
        return x->freq - y->freq;
    }
}

void generate_codes(HuffmanCode *code, Tree *node, unsigned int path, unsigned int length) {
    if (node->left == NULL && node->right == NULL) {
        int i = node->freq - 1;
        code->leaves[i].symbol = (unsigned char) node->freq;
        code->leaves[i].freq = node->freq;
        code->codes[i].code = path;
        code->codes[i].length = length;
        code->size++;
        return;
    }

    generate_codes(code, node->left, (path << 1) | 0, length + 1);
    generate_codes(code, node->right, (path << 1) | 1, length + 1);
}

void write_buffer(unsigned char *buffer, size_t *index, unsigned char bit, int bits) {
    if (bits == 8) {
        buffer[*index] = bit;
        (*index)++;
    } else {
        buffer[*index] |= bit << (8 - bits);
        (*index)++;

        if (*index == BUFFER_SIZE) {
            fwrite(buffer, sizeof(unsigned char), *index, stdout);
            *index = 0;
        }
    }
}

void compress(unsigned char *input, size_t input_size) {
    int freqs[ASCII_SIZE] = {0};

    for (size_t i = 0; i < input_size; i++) {
        freqs[input[i]]++;
    }

    Leaf leaves[ASCII_SIZE];
    int count = 0;

    for (int i = 0; i < ASCII_SIZE; i++) {
        if (freqs[i] > 0) {
            Leaf leaf = {
                .freq = freqs[i],
                .symbol = (unsigned char) i
            };
            leaves[count++] = leaf;
        }
    }

    qsort(leaves, count, sizeof(Leaf), compare);

    Tree *nodes[ASCII_SIZE];

    for (int i = 0; i < count; i++) {
        Tree *node = (Tree *) malloc(sizeof(Tree));

        node->left = NULL;
        node->right = NULL;
        node->freq = leaves[i].freq;

        nodes[i] = node;
    }

    int size = 0;

    while (size != count - 1) {
        Tree *node = (Tree *) malloc(sizeof(Tree));
        node->left = nodes[size];
        node->right = nodes[size + 1];
        node->freq = node->left->freq + node->right->freq;
        nodes[size + 1] = node;

        int i, j;
        for (i = size + 2; i < count && nodes[i]->freq < node->freq; i++);

        for (j = size + 1; j < i - 1; j++) {
            nodes[j] = nodes[j + 1];
        }

        nodes[j] = node;
        size++;
    }

    HuffmanCode code = {
        .codes = (Code *) malloc(count * sizeof(Code)),
        .leaves = (Leaf *) malloc(count * sizeof(Leaf)),
        .size = 0
    };

    generate_codes(&code, nodes[count - 1], 0, 0);

    fwrite(&count, sizeof(int), 1, stdout);

    for (int i = 0; i < count; i++) {
        fwrite(&code.leaves[i].symbol, sizeof(unsigned char), 1, stdout);
        fwrite(&code.codes[i].code, sizeof(unsigned int), 1, stdout);
        fwrite(&code.codes[i].length, sizeof(unsigned int), 1, stdout);
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t index = 0;
    unsigned int path = 0;
    unsigned int length = 0;

    for (size_t i = 0; i < input_size; i++) {
        for (int j = 0; j < code.size; j++) {
            if (input[i] == code.leaves[j].symbol) {
                path = code.codes[j].code;
                length = code.codes[j].length;

                for (unsigned int k = 0; k < length; k++) {
                    unsigned char bit = path & (1 << (length - k - 1)) ? 1 : 0;
                    write_buffer(buffer, &index, bit, k + 1);
                }

                break;
            }
        }
    }

    if (index > 0) {
        fwrite(buffer, sizeof(unsigned char), index, stdout);
    }
}

int main() {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, stdin))) {
        compress(buffer, bytes_read);
    }

    return 0;
}