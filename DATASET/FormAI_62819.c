//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SYMBOL_NUM 256

struct huffman_node {
    unsigned char symbol;
    unsigned int count;
    struct huffman_node *left_child;
    struct huffman_node *right_child;
};

typedef struct huffman_node huffman_node;

huffman_node* create_huffman_node(unsigned char symbol, unsigned int count) {
    huffman_node* node = (huffman_node*)malloc(sizeof(huffman_node));
    node->symbol = symbol;
    node->count = count;
    node->left_child = NULL;
    node->right_child = NULL;
    return node;
}

void free_huffman_tree(huffman_node* root) {
    if (root == NULL) return;
    free_huffman_tree(root->left_child);
    free_huffman_tree(root->right_child);
    free(root);
}

void swap_huffman_node(huffman_node** x, huffman_node** y) {
    huffman_node* tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort_huffman_nodes(huffman_node** nodes, unsigned int nodes_num) {
    for (unsigned int i = 0; i < nodes_num; i++) {
        for (unsigned int j = i; j < nodes_num; j++) {
            if (nodes[i]->count > nodes[j]->count) {
                swap_huffman_node(&nodes[i], &nodes[j]);
            }
        }
    }
}

unsigned int count_symbol_frequencies(unsigned char* text, unsigned int text_len,
                                       unsigned int* frequencies) {
    for (unsigned int i = 0; i < SYMBOL_NUM; i++) {
        frequencies[i] = 0;
    }

    for (unsigned int i = 0; i < text_len; i++) {
        frequencies[text[i]]++;
    }

    unsigned int unique_symbols_num = 0;
    for (unsigned int i = 0; i < SYMBOL_NUM; i++) {
        if (frequencies[i] > 0) {
            unique_symbols_num++;
        }
    }

    return unique_symbols_num;
}

void build_huffman_tree(huffman_node** root, unsigned int* frequencies) {
    huffman_node* nodes[SYMBOL_NUM];
    unsigned int nodes_num = 0;

    for (unsigned int i = 0; i < SYMBOL_NUM; i++) {
        if (frequencies[i] > 0) {
            nodes[nodes_num] = create_huffman_node((unsigned char)i, frequencies[i]);
            nodes_num++;
        }
    }

    sort_huffman_nodes(nodes, nodes_num);

    while (nodes_num > 1) {
        huffman_node* new_node = create_huffman_node(0, 0);
        huffman_node* left_child = nodes[0];
        huffman_node* right_child = nodes[1];

        new_node->count = left_child->count + right_child->count;
        new_node->left_child = left_child;
        new_node->right_child = right_child;

        nodes[0] = new_node;
        nodes[1] = NULL;

        for (unsigned int i = 2; i < nodes_num; i++) {
            nodes[i - 1] = nodes[i];
        }

        nodes_num--;

        sort_huffman_nodes(nodes, nodes_num);
    }

    *root = nodes[0];
}

void print_encoding(huffman_node* root, unsigned char* encoding, unsigned int encoding_len) {
    if (root == NULL) return;

    if (root->symbol > 0) {
        printf("%c: ", root->symbol);
        for (unsigned int i = 0; i < encoding_len; i++) {
            printf("%d", encoding[i]);
        }
        printf("\n");
    } else {
        encoding[encoding_len] = 0;
        print_encoding(root->left_child, encoding, encoding_len + 1);

        encoding[encoding_len] = 1;
        print_encoding(root->right_child, encoding, encoding_len + 1);
    }
}

void encode_text(huffman_node* root, unsigned char* text, unsigned int text_len,
                  unsigned char* encoded_text, unsigned int* encoded_text_len) {
    if (root == NULL) return;

    unsigned char encoding[SYMBOL_NUM] = {};
    unsigned int encoding_len = 0;

    for (unsigned int i = 0; i < text_len; i++) {
        huffman_node* node = root;
        while (node->left_child != NULL || node->right_child != NULL) {
            if (node->left_child != NULL && node->left_child->symbol == text[i]) {
                encoding[encoding_len] = 0;
                node = node->left_child;
            } else if (node->right_child != NULL && node->right_child->symbol == text[i]) {
                encoding[encoding_len] = 1;
                node = node->right_child;
            } else {
                printf("Error: symbol not found in Huffman tree!\n");
                return;
            }
            encoding_len++;
        }
    }

    *encoded_text_len = encoding_len / 8 + (encoding_len % 8 > 0 ? 1 : 0);

    for (unsigned int i = 0; i < *encoded_text_len; i++) {
        encoded_text[i] = 0;
    }

    for (unsigned int i = 0; i < encoding_len; i++) {
        if (i % 8 == 0 && i > 0) {
            encoded_text[i / 8] <<= 1;
        }
        encoded_text[i / 8] |= encoding[i];
    }
}

void decode_text(huffman_node* root, unsigned char* encoded_text, unsigned int encoded_text_len,
                  unsigned char* decoded_text, unsigned int* decoded_text_len) {
    if (root == NULL) return;

    unsigned int decoded_len = 0;
    for (unsigned int i = 0; i < encoded_text_len; i++) {
        for (unsigned int j = 0; j < 8; j++) {
            if (decoded_len >= *decoded_text_len) {
                printf("Error: decoded text buffer overflow!\n");
                return;
            }
            bool symbol_bit = ((encoded_text[i] >> (7 - j)) & 1) == 1;
            huffman_node* node = root;
            while (node->left_child != NULL || node->right_child != NULL) {
                node = symbol_bit ? node->right_child : node->left_child;
                symbol_bit = ((encoded_text[i] >> (7 - j)) & 1) == 1;
                if (node == NULL) {
                    printf("Error: symbol not found in Huffman tree!\n");
                    return;
                }
            }
            decoded_text[decoded_len] = node->symbol;
            decoded_len++;
        }
    }
    *decoded_text_len = decoded_len;
}

int main() {
    unsigned char* text = (unsigned char*)"The quick brown fox jumps over the lazy dog.";
    unsigned int text_len = 43;
    unsigned int frequencies[SYMBOL_NUM] = {};

    count_symbol_frequencies(text, text_len, frequencies);

    huffman_node* huffman_tree = NULL;
    build_huffman_tree(&huffman_tree, frequencies);

    unsigned char encoding[SYMBOL_NUM] = {};
    unsigned int encoding_len = 0;
    print_encoding(huffman_tree, encoding, encoding_len);

    unsigned char encoded_text[SYMBOL_NUM] = {};
    unsigned int encoded_text_len = 0;
    encode_text(huffman_tree, text, text_len, encoded_text, &encoded_text_len);

    printf("Encoded text: ");
    for (unsigned int i = 0; i < encoded_text_len; i++) {
        printf("%02x ", encoded_text[i]);
    }
    printf("\n");

    unsigned char decoded_text[SYMBOL_NUM] = {};
    unsigned int decoded_text_len = SYMBOL_NUM;
    decode_text(huffman_tree, encoded_text, encoded_text_len, decoded_text, &decoded_text_len);

    printf("Decoded text: %s\n", decoded_text);

    free_huffman_tree(huffman_tree);

    return 0;
}