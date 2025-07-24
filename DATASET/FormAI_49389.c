//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Huffman tree node structure
struct HuffmanNode {
    char character;
    int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
};

// Create a new Huffman tree node
struct HuffmanNode *newHuffmanNode(char character, int frequency) {
    struct HuffmanNode *node = (struct HuffmanNode *) malloc(sizeof(struct HuffmanNode));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Compare frequency of Huffman tree nodes
int compareHuffmanNodes(const void *a, const void *b) {
    struct HuffmanNode **nodeA = (struct HuffmanNode **) a;
    struct HuffmanNode **nodeB = (struct HuffmanNode **) b;
    return (*nodeA)->frequency - (*nodeB)->frequency;
}

// Build Huffman tree from frequency table
struct HuffmanNode *buildHuffmanTree(char characters[], int frequencies[], int n) {
    struct HuffmanNode *nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = newHuffmanNode(characters[i], frequencies[i]);
    }
    while (n > 1) {
        qsort(nodes, n, sizeof(struct HuffmanNode *), compareHuffmanNodes);
        struct HuffmanNode *left = nodes[0];
        struct HuffmanNode *right = nodes[1];
        struct HuffmanNode *parent = newHuffmanNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        nodes[0] = parent;
        n--;
        for (int i = 1; i < n; i++) {
            nodes[i] = nodes[i+1];
        }
    }
    return nodes[0];
}

// Traverse Huffman tree and assign codes
void assignHuffmanCodes(struct HuffmanNode *node, char *code, int len, char codes[][256], int *count) {
    if (node->left == NULL && node->right == NULL) {
        // Leaf node, assign code
        code[len] = '\0';
        char *newCode = (char *) malloc(len + 1);
        strcpy(newCode, code);
        codes[*count][0] = node->character;
        strcpy(codes[*count]+1, newCode);
        (*count)++;
        free(newCode);
        return;
    }
    code[len] = '0';
    assignHuffmanCodes(node->left, code, len+1, codes, count);
    code[len] = '1';
    assignHuffmanCodes(node->right, code, len+1, codes, count);
}

// Huffman coding function
char *huffmanEncode(char message[]) {
    int frequencies[256] = {0};
    char characters[256];
    int n = 0;
    for (int i = 0; message[i]; i++) {
        if (frequencies[message[i]] == 0) {
            // New character, add to frequency table
            characters[n] = message[i];
            n++;
        }
        frequencies[message[i]]++;
    }
    struct HuffmanNode *tree = buildHuffmanTree(characters, frequencies, n);
    char codes[n][256];
    int count = 0;
    char code[256];
    assignHuffmanCodes(tree, code, 0, codes, &count);
    char *encoded = (char *) malloc(8*strlen(message));
    int index = 0;
    for (int i = 0; message[i]; i++) {
        for (int j = 0; j < count; j++) {
            if (codes[j][0] == message[i]) {
                strcat(encoded, codes[j]+1);
                index += strlen(codes[j]+1);
                break;
            }
        }
    }
    encoded[index] = '\0';
    return encoded;
}

// Huffman decoding function
char *huffmanDecode(char encoded[], struct HuffmanNode *tree) {
    char *decoded = (char *) malloc(strlen(encoded));
    struct HuffmanNode *current = tree;
    for (int i = 0; encoded[i]; i++) {
        if (encoded[i] == '0') {
            current = current->left;
        }
        else if (encoded[i] == '1') {
            current = current->right;
        }
        if (current->left == NULL && current->right == NULL) {
            // Leaf node reached, add character to decoded message
            int len = strlen(decoded);
            decoded[len] = current->character;
            decoded[len+1] = '\0';
            current = tree;
        }
    }
    return decoded;
}

int main() {
    char message[] = "Huffman coding is fun!";
    char *encoded = huffmanEncode(message);
    printf("Encoded message: %s\n", encoded);
    struct HuffmanNode *tree = buildHuffmanTree(NULL, NULL, 0);
    char *decoded = huffmanDecode(encoded, tree);
    printf("Decoded message: %s\n", decoded);
    free(encoded);
    free(decoded);
    return 0;
}