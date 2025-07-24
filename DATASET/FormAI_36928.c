//FormAI DATASET v1.0 Category: Image compression ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_SYMBOLS 256
#define MAX_NODE_VALUES 512

// The Huffman node represents a tree of symbols with their frequency count.
typedef struct HuffmanNode {
    uint32_t symbol;
    int32_t frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
} HuffmanNode;

// The SymbolFrequency struct represents the count of occurrences of each symbol.
typedef struct SymbolFrequency {
    uint32_t symbol;
    int32_t frequency;
} SymbolFrequency;

// The Bitstream struct represents the compressed bitstream.
typedef struct Bitstream {
    uint8_t *buffer;
    uint32_t length;
    uint32_t capacity;
    uint32_t offset;
} Bitstream;

// The HuffmanTree struct represents the Huffman coding tree.
typedef struct HuffmanTree {
    HuffmanNode *root;
    uint32_t size;
    uint32_t symbols;
    SymbolFrequency frequencies[MAX_SYMBOLS];
} HuffmanTree;

// Initialize the bitstream.
Bitstream *initializeBitstream() {
    Bitstream *stream = malloc(sizeof(Bitstream));
    if (stream == NULL) {
        printf("Error allocating bitstream memory.\n");
        return NULL;
    }
    stream->length = 0;
    stream->capacity = 8;
    stream->offset = 0;
    stream->buffer = (uint8_t *) calloc(stream->capacity, sizeof(uint8_t));
    if (stream->buffer == NULL) {
        free(stream);
        printf("Error allocating bitstream buffer memory.\n");
        return NULL;
    }
    return stream;
}

// Destroy the bitstream.
void destroyBitstream(Bitstream *stream) {
    if (stream != NULL) {
        if (stream->buffer != NULL) {
            free(stream->buffer);
        }
        free(stream);
    }
}

// Add a single bit to the bitstream.
void addBit(Bitstream *stream, uint8_t bit) {
    if (stream->offset == 8) {
        stream->capacity += 8;
        uint8_t *newBuffer = (uint8_t *) realloc(stream->buffer, stream->capacity * sizeof(uint8_t));
        if (newBuffer == NULL) {
            printf("Error reallocating bitstream buffer memory.\n");
            return;
        }
        stream->buffer = newBuffer;
        memset(stream->buffer + stream->length, 0, stream->capacity - stream->length);
    }
    stream->buffer[stream->length] |= (bit << (7 - stream->offset));
    stream->offset = (stream->offset + 1) % 8;
    if (stream->offset == 0) {
        stream->length++;
    }
}

// Add a bit sequence to the bitstream.
void addBits(Bitstream *stream, uint32_t bits, uint8_t length) {
    for (uint8_t i = length; i > 0; i--) {
        addBit(stream, ((bits >> (i-1)) & 1));
    }
}

// Flush any remaining bits to the bitstream.
void flushBitstream(Bitstream *stream) {
    if (stream->offset > 0) {
        stream->length++;
    }
}

// Create a new Huffman node.
HuffmanNode *createNode(uint32_t symbol, int32_t frequency) {
    HuffmanNode *node = malloc(sizeof(HuffmanNode));
    if (node == NULL) {
        printf("Error allocating Huffman node memory.\n");
        return NULL;
    }
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Destroy a Huffman node and its children.
void destroyNode(HuffmanNode *node) {
    if (node != NULL) {
        destroyNode(node->left);
        destroyNode(node->right);
        free(node);
    }
}

// Compare two SymbolFrequency structs by comparing their frequency count.
int compareFrequencies(const void *a, const void *b) {
    int32_t diff = ((const SymbolFrequency *)b)->frequency - ((const SymbolFrequency *)a)->frequency;
    if (diff == 0) {
        diff = ((const SymbolFrequency *)b)->symbol - ((const SymbolFrequency *)a)->symbol;
    }
    return diff;
}

// Create a new Huffman coding tree.
HuffmanTree *createHuffmanTree(uint8_t *data, uint32_t length) {
    if (data == NULL || length == 0) {
        printf("Error creating Huffman tree: invalid input data.\n");
        return NULL;
    }

    // Count the number of occurrences of each symbol.
    SymbolFrequency frequencies[MAX_SYMBOLS];
    memset(frequencies, 0, sizeof(frequencies));
    for (uint32_t i = 0; i < length; i++) {
        frequencies[data[i]].symbol = data[i];
        frequencies[data[i]].frequency++;
    }

    // Sort the symbols by frequency count.
    qsort(frequencies, MAX_SYMBOLS, sizeof(SymbolFrequency), compareFrequencies);

    // Create the Huffman tree.
    HuffmanTree *tree = malloc(sizeof(HuffmanTree));
    if (tree == NULL) {
        printf("Error allocating Huffman tree memory.\n");
        return NULL;
    }
    tree->root = NULL;
    tree->size = 0;
    tree->symbols = 0;

    // Build the Huffman tree.
    HuffmanNode *nodes[MAX_NODE_VALUES];
    for (int i = 0; i < MAX_NODE_VALUES; i++) {
        nodes[i] = NULL;
    }
    int nodeCount = 0;
    for (uint32_t i = 0; i < MAX_SYMBOLS && frequencies[i].frequency > 0; i++) {
        nodes[nodeCount] = createNode(frequencies[i].symbol, frequencies[i].frequency);
        nodeCount++;
    }
    for (; nodeCount > 1; nodeCount--) {
        HuffmanNode *node = createNode(0, 0);
        node->left = nodes[nodeCount-1];
        node->right = nodes[nodeCount-2];
        node->frequency = node->left->frequency + node->right->frequency;
        nodes[nodeCount-2] = node;
        nodes[nodeCount-1] = NULL;
        for (int i = nodeCount-2; i > 0 && nodes[i-1] != NULL && nodes[i]->frequency < nodes[i-1]->frequency; i--) {
            HuffmanNode *temp = nodes[i];
            nodes[i] = nodes[i-1];
            nodes[i-1] = temp;
        }
    }
    tree->root = nodes[0];
    for (int i = 0; i < MAX_SYMBOLS && frequencies[i].frequency > 0; i++) {
        tree->symbols++;
        tree->frequencies[i].symbol = frequencies[i].symbol;
        tree->frequencies[i].frequency = frequencies[i].frequency;
    }
    tree->size = tree->symbols + (tree->symbols-1);

    return tree;
}

// Destroy a Huffman coding tree.
void destroyHuffmanTree(HuffmanTree *tree) {
    if (tree != NULL) {
        destroyNode(tree->root);
        free(tree);
    }
}

// Traverse the Huffman tree recursively and generate codes for each symbol.
void generateHuffmanCodes(HuffmanNode *node, uint32_t code, uint8_t length, uint32_t *codes, uint8_t *lengths) {
    if (node == NULL) {
        return;
    }
    if (node->symbol > 0) {
        codes[node->symbol] = code;
        lengths[node->symbol] = length;
    } else {
        generateHuffmanCodes(node->left, (code << 1), length + 1, codes, lengths);
        generateHuffmanCodes(node->right, (code << 1) | 1, length + 1, codes, lengths);
    }
}

// Write the compressed image data to a file.
void writeCompressedData(Bitstream *stream, HuffmanTree *tree, uint8_t *data, uint32_t length) {
    // Write the Huffman coding tree to the beginning of the compressed data.
    uint32_t treeData[tree->size];
    uint8_t treeLengths[tree->symbols];
    memset(treeData, 0, sizeof(treeData));
    memset(treeLengths, 0, sizeof(treeLengths));
    uint32_t treeIndex = 0;
    generateHuffmanCodes(tree->root, 0, 0, treeData, treeLengths);
    addBits(stream, tree->symbols-1, 8);
    for (uint32_t i = 0; i < MAX_SYMBOLS && tree->frequencies[i].frequency > 0; i++) {
        if (i > 0) {
            addBits(stream, tree->frequencies[i].symbol - tree->frequencies[i-1].symbol - 1, treeLengths[tree->frequencies[i].symbol]);
        } else {
            addBits(stream, tree->frequencies[i].symbol, treeLengths[tree->frequencies[i].symbol]);
        }
        treeIndex++;
    }
    uint32_t padding = stream->offset;
    flushBitstream(stream);

    // Write the compressed data.
    uint32_t code = 0;
    uint8_t codeLength = 0;
    for (uint32_t i = 0; i < length; i++) {
        uint32_t symbol = data[i];
        uint8_t symbolLength = treeLengths[symbol];
        code = (code << symbolLength) | treeData[symbol];
        codeLength += symbolLength;
        while (codeLength >= 8) {
            addBit(stream, (code >> (codeLength-8)) & 0xff);
            codeLength -= 8;
        }
    }

    // Write the final code bits and padding.
    if (codeLength > 0) {
        addBits(stream, code, codeLength);
    }
    for (uint32_t i = 0; i < padding; i++) {
        addBit(stream, 0);
    }
    flushBitstream(stream);
}

int main(int argc, char **argv) {
    // Load the input image.
    uint8_t image[WIDTH * HEIGHT];
    FILE *file = fopen("input.raw", "r");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return -1;
    }
    fread(image, sizeof(uint8_t), WIDTH * HEIGHT, file);
    fclose(file);

    // Compress the image data using Huffman coding.
    HuffmanTree *tree = createHuffmanTree(image, WIDTH * HEIGHT);
    Bitstream *stream = initializeBitstream();
    writeCompressedData(stream, tree, image, WIDTH * HEIGHT);

    // Write the compressed data to a file.
    file = fopen("output.dat", "w");
    if (file == NULL) {
        printf("Error opening output file.\n");
        return -1;
    }
    fwrite(stream->buffer, sizeof(uint8_t), stream->length, file);
    fclose(file);

    // Clean up memory.
    destroyHuffmanTree(tree);
    destroyBitstream(stream);

    return 0;
}