//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TREE_HEIGHT 100
#define MAX_CODE_LENGTH 100

struct HuffmanNode {
    char character;
    int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
};

struct HuffmanCode {
    char character;
    char code[MAX_CODE_LENGTH + 1];
};

void generate_codes(struct HuffmanNode *root, char *code, int depth, struct HuffmanCode *codes) {
    if (root->left == NULL && root->right == NULL) {
        codes[root->character].character = root->character;
        codes[root->character].code[depth] = '\0';
        strcpy(codes[root->character].code, code);
    } else {
        if (root->left != NULL) {
            code[depth] = '0';
            generate_codes(root->left, code, depth + 1, codes);
        }
        if (root->right != NULL) {
            code[depth] = '1';
            generate_codes(root->right, code, depth + 1, codes);
        }
    }
}

struct HuffmanNode *construct_tree(char *text) {
    int frequencies[256] = { 0 };
    for (int i = 0; text[i] != '\0'; i++) {
        frequencies[(int)text[i]]++;
    }

    struct HuffmanNode *node_heap[256] = { NULL };
    int heap_size = 0;
    for (int c = 0; c < 256; c++) {
        if (frequencies[c] > 0) {
            struct HuffmanNode *node = malloc(sizeof(struct HuffmanNode));
            node->character = c;
            node->frequency = frequencies[c];
            node->left = NULL;
            node->right = NULL;
            node_heap[heap_size++] = node;
        }
    }

    while (heap_size > 1) {
        struct HuffmanNode *left = node_heap[--heap_size];
        struct HuffmanNode *right = node_heap[--heap_size];
        struct HuffmanNode *parent = malloc(sizeof(struct HuffmanNode));
        parent->character = '\0';
        parent->frequency = left->frequency + right->frequency;
        parent->left = left;
        parent->right = right;

        // insert the new node into the heap
        int i;
        for (i = heap_size - 1; i >= 0; i--) {
            if (parent->frequency > node_heap[i]->frequency) {
                node_heap[i + 1] = node_heap[i];
            } else {
                break;
            }
        }
        node_heap[i + 1] = parent;
        heap_size++;
    }

    return node_heap[0];
}

void encode(struct HuffmanCode *codes, char *text, char *encoded_text) {
    int i, j;
    for (i = 0, j = 0; text[i] != '\0'; i++) {
        strcpy(&encoded_text[j], codes[(int)text[i]].code);
        j += strlen(codes[(int)text[i]].code);
    }
    encoded_text[j] = '\0';
}

void decode(struct HuffmanNode *root, char *encoded_text, char *decoded_text) {
    struct HuffmanNode *current_node = root;
    int i, j;
    for (i = 0, j = 0; encoded_text[i] != '\0'; i++) {
        if (encoded_text[i] == '0') {
            current_node = current_node->left;
        } else if (encoded_text[i] == '1') {
            current_node = current_node->right;
        }
        if (current_node->left == NULL && current_node->right == NULL) {
            decoded_text[j++] = current_node->character;
            current_node = root;
        }
    }
    decoded_text[j] = '\0';
}

int main() {
    char text[1000] = "The end of the world was not as we expected. Instead of a biblical apocalypse or a chaotic natural disaster, it was the result of a simple coding error. A computer virus, perhaps unleashed by accident or design, spread rapidly through the internet, causing systems to crash, networks to go down, and chaos to reign. Within hours, the world as we knew it had become a distant memory.";
    struct HuffmanNode *tree = construct_tree(text);
    struct HuffmanCode codes[256] = { { 0 } };
    char code[MAX_CODE_LENGTH + 1] = { 0 };
    generate_codes(tree, code, 0, codes);
    char encoded_text[10000] = { 0 };
    encode(codes, text, encoded_text);
    char decoded_text[1000] = { 0 };
    decode(tree, encoded_text, decoded_text);
    printf("Original text: %s\n\n", text);
    printf("Huffman codes:\n");
    for (int c = 0; c < 256; c++) {
        if (codes[c].code[0] != '\0') {
            printf("%c: %s\n", codes[c].character, codes[c].code);
        }
    }
    printf("\nEncoded text: %s\n\n", encoded_text);
    printf("Decoded text: %s\n", decoded_text);
    return 0;
}