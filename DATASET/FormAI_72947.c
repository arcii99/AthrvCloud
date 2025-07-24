//FormAI DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_SIZE 256
#define MAX_CODE_LENGTH 32
#define MAX_COMPRESSED_SIZE (1 << 20)
#define MAX_HUFFMAN_NODES 512

typedef struct huffman_node {
    unsigned char symbol;
    int frequency;
    struct huffman_node *left, *right;
} huffman_node_t;

typedef struct bitstring {
    unsigned char bits[MAX_CODE_LENGTH];
    size_t length;
} bitstring_t;

typedef struct huffman_table {
    bitstring_t codes[ASCII_SIZE];
    size_t sizes[ASCII_SIZE];
} huffman_table_t;

huffman_node_t *new_huffman_node(unsigned char symbol, int frequency) {
    huffman_node_t *node = (huffman_node_t *)malloc(sizeof(huffman_node_t));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void destroy_huffman_tree(huffman_node_t *tree) {
    if (tree) {
        destroy_huffman_tree(tree->left);
        destroy_huffman_tree(tree->right);
        free(tree);
    }
}

int compare_huffman_nodes(const void *a, const void *b) {
    const huffman_node_t **na = (const huffman_node_t **)a;
    const huffman_node_t **nb = (const huffman_node_t **)b;
    return (*na)->frequency - (*nb)->frequency;
}

void create_huffman_codes(huffman_node_t *tree, bitstring_t *bits, size_t depth, huffman_table_t *table) {
    if (tree->left || tree->right) {
        bitstring_t left_bits = *bits;
        bitstring_t right_bits = *bits;
        left_bits.bits[depth] = 0;
        left_bits.length = depth + 1;
        right_bits.bits[depth] = 1;
        right_bits.length = depth + 1;
        create_huffman_codes(tree->left, &left_bits, depth + 1, table);
        create_huffman_codes(tree->right, &right_bits, depth + 1, table);
    } else {
        table->codes[tree->symbol] = *bits;
        table->sizes[tree->symbol] = depth;
    }
}

huffman_node_t *create_huffman_tree(const unsigned char *data, size_t size) {
    huffman_node_t *nodes[MAX_HUFFMAN_NODES];
    memset(nodes, 0, sizeof(nodes));
    int counts[ASCII_SIZE];
    memset(counts, 0, sizeof(counts));
    for (size_t i = 0; i < size; ++i) {
        ++counts[data[i]];
    }
    int n = 0;
    for (unsigned short i = 0; i < ASCII_SIZE; ++i) {
        if (counts[i]) {
            nodes[n++] = new_huffman_node(i, counts[i]);
        }
    }
    int j = n;
    while (j-- > 1) {
        qsort((void *)nodes, n, sizeof(huffman_node_t *), compare_huffman_nodes);
        huffman_node_t *node = new_huffman_node(0, nodes[0]->frequency + nodes[1]->frequency);
        node->left = nodes[0];
        node->right = nodes[1];
        nodes[0] = node;
        nodes[1] = nodes[--n];
    }
    return nodes[0];
}

int compress(const void *src, size_t src_size, void *dst, size_t dst_size) {
    if (src_size >= dst_size) {
        return -1;
    }
    huffman_table_t table;
    memset(&table, 0, sizeof(table));
    huffman_node_t *tree = create_huffman_tree(src, src_size);
    bitstring_t bits;
    memset(&bits, 0, sizeof(bits));
    create_huffman_codes(tree, &bits, 0, &table);
    destroy_huffman_tree(tree);
    unsigned char *dst_buffer = (unsigned char *)dst;
    size_t position = 0;
    size_t bits_written = 0;
    for (size_t i = 0; i < src_size; ++i) {
        bitstring_t *code = &table.codes[((unsigned char *)src)[i]];
        size_t code_size = table.sizes[((unsigned char *)src)[i]];
        if (bits_written + code_size > 8) {
            dst_buffer[position++] |= code->bits[0] >> (bits_written - (8 - code_size));
            size_t bits_remaining = code_size - (8 - bits_written);
            while (bits_remaining >= 8) {
                dst_buffer[position++] = code->bits[(code_size - bits_remaining) / 8];
                bits_remaining -= 8;
            }
            bits_written = bits_remaining;
            if (bits_written) {
                dst_buffer[position] = code->bits[code_size / 8] << (8 - bits_written);
            }
        } else {
            dst_buffer[position] |= code->bits[0] << (8 - bits_written - code_size);
            bits_written += code_size;
        }
    }
    return position + (bits_written ? 1 : 0);
}

int decompress(const void *src, size_t src_size, void *dst, size_t dst_size) {
    unsigned char *src_buffer = (unsigned char *)src;
    unsigned char *dst_buffer = (unsigned char *)dst;
    huffman_node_t *tree = new_huffman_node(0, 0);
    for (size_t i = 0; i < ASCII_SIZE; ++i) {
        huffman_node_t *node = tree;
        for (size_t j = 0; j < MAX_CODE_LENGTH && i < ASCII_SIZE; ++j) {
            unsigned char bit = i % 2;
            if (bit) {
                if (!node->right) {
                    node->right = new_huffman_node(0, 0);
                }
                node = node->right;
            } else {
                if (!node->left) {
                    node->left = new_huffman_node(0, 0);
                }
                node = node->left;
            }
            i >>= 1;
        }
        node->symbol = i;
    }
    huffman_node_t *node = tree;
    size_t bits_read = 0;
    for (size_t i = 0; i < src_size; ++i) {
        unsigned char byte = src_buffer[i];
        for (size_t j = 0; j < 8; ++j) {
            unsigned char bit = byte >> (7 - j) & 1;
            if (bit) {
                node = node->right;
            } else {
                node = node->left;
            }
            if (node->left == NULL && node->right == NULL) {
                if (bits_read / 8 >= dst_size) {
                    return -1;
                }
                dst_buffer[bits_read / 8] = node->symbol;
                node = tree;
            }
            ++bits_read;
        }
    }
    destroy_huffman_tree(tree);
    return bits_read / 8;
}

int main() {
    char *input_string = "This is a compression algorithm using Huffman coding.";
    char compressed[MAX_COMPRESSED_SIZE];
    char decompressed[strlen(input_string)];
    size_t compressed_size = sizeof(compressed);
    size_t decompressed_size = sizeof(decompressed);
    if (compress(input_string, strlen(input_string) + 1, compressed, compressed_size) == -1) {
        fprintf(stderr, "Compression failed");
        return 1;
    }
    if (decompress(compressed, compressed_size, decompressed, decompressed_size) == -1) {
        fprintf(stderr, "Decompression failed");
        return 1;
    }
    printf("Input string: %s\n", input_string);
    printf("Compressed size: %zu bytes\n", compressed_size);
    printf("Decompressed size: %zu bytes\n", decompressed_size);
    printf("Decompressed string: %s\n", decompressed);
    return 0;
}