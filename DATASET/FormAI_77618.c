//FormAI DATASET v1.0 Category: Image compression ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 512
#define MAX_HUFFMAN_SYMBOLS 256
#define MAX_CODE_SIZE 64

typedef struct huffman_node {
    unsigned char symbol;
    int frequency;
    struct huffman_node *left, *right;
} huffman_node_t;

typedef struct huffman_code {
    unsigned char bits[MAX_CODE_SIZE];
    int length;
} huffman_code_t;

typedef struct huffman_table {
    int num_symbols;
    huffman_node_t *nodes[MAX_HUFFMAN_SYMBOLS];
    huffman_code_t codes[MAX_HUFFMAN_SYMBOLS];
} huffman_table_t;

int pixel_data[MAX_PIXELS][MAX_PIXELS];
unsigned char compressed_data[2 * MAX_PIXELS * MAX_PIXELS];
int compressed_len = 0;

void encode_pixel_data(int width, int height)
{
    huffman_table_t table = {0};
    int num_pixels = width * height;
    int pixel_freq[MAX_HUFFMAN_SYMBOLS] = {0};
    int i, j;

    // count the frequency of each pixel value
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int pixel_val = pixel_data[i][j];
            pixel_freq[pixel_val]++;
        }
    }

    // build the huffman tree and create the encoding table
    for (i = 0; i < MAX_HUFFMAN_SYMBOLS; i++) {
        if (pixel_freq[i] > 0) {
            huffman_node_t *node = malloc(sizeof(huffman_node_t));
            node->symbol = i;
            node->frequency = pixel_freq[i];
            node->left = NULL;
            node->right = NULL;
            table.nodes[table.num_symbols++] = node;
        }
    }

    while (table.num_symbols > 1) {
        huffman_node_t *parent = malloc(sizeof(huffman_node_t));
        parent->symbol = 0;
        parent->frequency = 0;
        parent->left = table.nodes[0];
        parent->right = table.nodes[1];
        for (i = 2; i < table.num_symbols; i++) {
            if (table.nodes[i]->frequency < parent->left->frequency) {
                parent->right = parent->left;
                parent->left = table.nodes[i];
            } else if (table.nodes[i]->frequency < parent->right->frequency) {
                parent->right = table.nodes[i];
            }
        }
        parent->frequency = parent->left->frequency + parent->right->frequency;
        table.nodes[0] = parent;
        table.num_symbols--;
    }

    // generate huffman codes for each pixel value
    for (i = 0; i < table.num_symbols; i++) {
        huffman_node_t *node = table.nodes[i];
        huffman_code_t code = {0};
        huffman_node_t *parent = node;
        while (parent != NULL) {
            if (parent->left == node) {
                code.bits[code.length++] = 0;
            } else {
                code.bits[code.length++] = 1;
            }
            node = parent;
            parent = parent->left ? parent->left : parent->right;
        }
        memcpy(&table.codes[node->symbol], &code, sizeof(huffman_code_t));
    }

    // write the compressed data
    compressed_data[compressed_len++] = (width >> 8) & 0xff;
    compressed_data[compressed_len++] = width & 0xff;
    compressed_data[compressed_len++] = (height >> 8) & 0xff;
    compressed_data[compressed_len++] = height & 0xff;
    for (i = 0; i < table.num_symbols; i++) {
        compressed_data[compressed_len++] = table.nodes[i]->symbol;
        compressed_data[compressed_len++] = (table.nodes[i]->frequency >> 8) & 0xff;
        compressed_data[compressed_len++] = table.nodes[i]->frequency & 0xff;
    }
    int bits_needed = 0, bit_pos = 0, curr_byte = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            huffman_code_t code = table.codes[pixel_data[i][j]];
            bits_needed += code.length;
        }
    }
    compressed_data[compressed_len++] = (bits_needed >> 24) & 0xff;
    compressed_data[compressed_len++] = (bits_needed >> 16) & 0xff;
    compressed_data[compressed_len++] = (bits_needed >> 8) & 0xff;
    compressed_data[compressed_len++] = bits_needed & 0xff;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            huffman_code_t code = table.codes[pixel_data[i][j]];
            int k;
            for (k = 0; k < code.length; k++) {
                curr_byte |= (code.bits[k] << bit_pos);
                if (++bit_pos == 8) {
                    compressed_data[compressed_len++] = curr_byte;
                    curr_byte = 0;
                    bit_pos = 0;
                }
            }
        }
    }
    if (bit_pos > 0) {
        compressed_data[compressed_len++] = curr_byte;
    }

    // free memory used by huffman tree and table
    for (i = 0; i < table.num_symbols; i++) {
        free(table.nodes[i]);
    }
}

int main()
{
    int width = 256;
    int height = 256;
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel_data[i][j] = (i + j) % 256;
        }
    }
    encode_pixel_data(width, height);
    printf("Compressed %d bytes of pixel data into %d bytes\n", width * height, compressed_len);
    return 0;
}