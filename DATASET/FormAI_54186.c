//FormAI DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SYMBOLS 256 // Maximum number of symbols in the input data
#define MAX_CODE_LEN 16 // Maximum length of a Huffman code

typedef struct code_node {
    uint16_t code; // The Huffman code representing this symbol
    uint8_t length; // The length of the Huffman code in bits
} code_node;

typedef struct huffman_node {
    uint32_t frequency; // The frequency of this symbol in the input data
    uint16_t symbol; // The symbol represented by this node
    bool is_leaf; // Flag to indicate if the node is a leaf or not
    struct huffman_node *left_child; // Pointer to the left child node
    struct huffman_node *right_child; // Pointer to the right child node
} huffman_node;

typedef struct bit_code {
    uint8_t *data; // The bit-packed Huffman codes
    uint32_t length; // The length of the bit-packed codes in bits
} bit_code;

void generate_codes(huffman_node *root, code_node *codes, uint16_t code, uint8_t length) {
    if (root->is_leaf) {
        uint16_t symbol = root->symbol;
        codes[symbol].code = code;
        codes[symbol].length = length;
    }
    else {
        generate_codes(root->left_child, codes, (code << 1), (length + 1));
        generate_codes(root->right_child, codes, (code << 1) | 1, (length + 1));
    }
}

int huffman_compress(uint8_t *data, uint32_t length, bit_code *compressed_data) {
    if (length == 0) {
        return -1;
    }
    // Calculate the frequency of each symbol in the input data
    uint32_t frequencies[MAX_SYMBOLS] = {0};
    for (uint32_t i = 0; i < length; i++) {
        frequencies[data[i]]++;
    }
    // Create a list of huffman nodes with the frequencies and symbols
    huffman_node node_list[MAX_SYMBOLS] = {0};
    uint16_t num_nodes = 0;
    for (uint16_t i = 0; i < MAX_SYMBOLS; i++) {
        if (frequencies[i] > 0) {
            node_list[num_nodes].frequency = frequencies[i];
            node_list[num_nodes].symbol = i;
            node_list[num_nodes].is_leaf = true;
            node_list[num_nodes].left_child = NULL;
            node_list[num_nodes].right_child = NULL;
            num_nodes++;
        }
    }
    // Build the Huffman tree by repeatedly combining the two nodes with lowest frequencies
    while (num_nodes > 1) {
        uint16_t min1 = 0;
        uint16_t min2 = 1;
        if (node_list[min2].frequency < node_list[min1].frequency) {
            uint16_t temp = min1;
            min1 = min2;
            min2 = temp;
        }
        for (uint16_t i = 2; i < num_nodes; i++) {
            if (node_list[i].frequency < node_list[min1].frequency) {
                uint16_t temp = min1;
                min1 = i;
                min2 = temp;
            }
            else if (node_list[i].frequency < node_list[min2].frequency) {
                min2 = i;
            }
        }
        huffman_node new_node = {0};
        new_node.frequency = node_list[min1].frequency + node_list[min2].frequency;
        new_node.left_child = &node_list[min1];
        new_node.right_child = &node_list[min2];
        node_list[min1] = new_node;
        node_list[min2] = node_list[num_nodes - 1];
        num_nodes--;
    }
    // Generate the Huffman codes from the tree
    code_node codes[MAX_SYMBOLS] = {0};
    generate_codes(&node_list[0], codes, 0, 0);
    // Pack the codes into a bit stream
    uint8_t *bit_data = (uint8_t*) malloc(sizeof(uint8_t) * length * MAX_CODE_LEN);
    uint32_t bit_length = 0;
    for (uint32_t i = 0; i < length; i++) {
        uint16_t symbol = data[i];
        uint16_t code = codes[symbol].code;
        uint8_t code_length = codes[symbol].length;
        for (uint8_t j = 0; j < code_length; j++) {
            uint8_t bit = ((code >> (code_length - j - 1)) & 0x01);
            bit_data[bit_length / 8] |= (bit << (bit_length % 8));
            bit_length++;
        }
    }
    // Pack the bit stream into 8-bit bytes
    uint32_t byte_length = ((bit_length + 7) >> 3);
    uint8_t *byte_data = (uint8_t*) malloc(sizeof(uint8_t) * byte_length);
    for (uint32_t i = 0; i < byte_length; i++) {
        uint8_t byte = 0;
        for (uint8_t j = 0; j < 8; j++) {
            if ((i * 8 + j) < bit_length) {
                byte |= ((bit_data[i * 8 + j]) << j);
            }
        }
        byte_data[i] = byte;
    }
    // Store the compressed data in the bit_code struct
    compressed_data->data = byte_data;
    compressed_data->length = byte_length * 8;
    // Free the temporary memory used during compression
    free(bit_data);
    return 0;
}

int huffman_decompress(bit_code *compressed_data, uint8_t *decompressed_data, uint32_t *decompressed_length) {
    if (compressed_data->length == 0) {
        return -1;
    }
    // Calculate the frequency of each symbol in the compressed data
    uint32_t frequencies[MAX_SYMBOLS] = {0};
    for (uint32_t i = 0; i < compressed_data->length; i++) {
        uint8_t byte = compressed_data->data[i];
        for (uint8_t j = 0; j < 8; j++) {
            if ((i * 8 + j) < compressed_data->length) {
                uint8_t bit = ((byte >> j) & 0x01);
                frequencies[bit]++;
            }
        }
    }
    // Create a list of Huffman nodes with the frequencies and symbols
    huffman_node node_list[MAX_SYMBOLS] = {0};
    uint16_t num_nodes = 0;
    for (uint16_t i = 0; i < MAX_SYMBOLS; i++) {
        if (frequencies[i] > 0) {
            node_list[num_nodes].frequency = frequencies[i];
            node_list[num_nodes].symbol = i;
            node_list[num_nodes].is_leaf = true;
            node_list[num_nodes].left_child = NULL;
            node_list[num_nodes].right_child = NULL;
            num_nodes++;
        }
    }
    // Build the Huffman tree by repeatedly combining the two nodes with lowest frequencies
    while (num_nodes > 1) {
        uint16_t min1 = 0;
        uint16_t min2 = 1;
        if (node_list[min2].frequency < node_list[min1].frequency) {
            uint16_t temp = min1;
            min1 = min2;
            min2 = temp;
        }
        for (uint16_t i = 2; i < num_nodes; i++) {
            if (node_list[i].frequency < node_list[min1].frequency) {
                uint16_t temp = min1;
                min1 = i;
                min2 = temp;
            }
            else if (node_list[i].frequency < node_list[min2].frequency) {
                min2 = i;
            }
        }
        huffman_node new_node = {0};
        new_node.frequency = node_list[min1].frequency + node_list[min2].frequency;
        new_node.left_child = &node_list[min1];
        new_node.right_child = &node_list[min2];
        node_list[min1] = new_node;
        node_list[min2] = node_list[num_nodes - 1];
        num_nodes--;
    }
    // Decompress the bit data using the Huffman tree
    huffman_node *current_node = &node_list[0];
    uint32_t bit_position = 0;
    uint32_t byte_position = 0;
    while (bit_position < compressed_data->length) {
        uint8_t byte = compressed_data->data[byte_position];
        for (uint8_t j = 0; j < 8; j++) {
            if (bit_position >= compressed_data->length) {
                break;
            }
            uint8_t bit = ((byte >> j) & 0x01);
            if (bit == 0) {
                current_node = current_node->left_child;
            }
            else {
                current_node = current_node->right_child;
            }
            if (current_node->is_leaf) {
                decompressed_data[bit_position / 8] |= (current_node->symbol << (bit_position % 8));
                bit_position += current_node->left_child->frequency;
                current_node = &node_list[0];
            }
        }
        byte_position++;
    }
    // Store the decompressed data and length in the output parameters
    *decompressed_length = (bit_position + 7) / 8;
    return 0;
}

int main() {
    // Example usage of the Huffman compression and decompression functions
    uint8_t input_data[] = "Hello, world!";
    uint32_t input_length = strlen((char*) input_data);
    bit_code compressed_data = {0};
    huffman_compress(input_data, input_length, &compressed_data);
    printf("Compressed data length: %d\n", compressed_data.length);
    uint8_t *decompressed_data = (uint8_t*) malloc(sizeof(uint8_t) * input_length);
    uint32_t decompressed_length = 0;
    huffman_decompress(&compressed_data, decompressed_data, &decompressed_length);
    printf("Decompressed data: %s\n", decompressed_data);
    free(compressed_data.data);
    free(decompressed_data);
    return 0;
}