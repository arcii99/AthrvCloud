//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char ch;
    int freq;
    struct node *left, *right;
};

// Function to create a new node
struct node *newNode(char ch, int freq, struct node *left, struct node *right) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->ch = ch;
    new_node->freq = freq;
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

// Function to build the frequency array
int build_freq_array(int freq[], const char *data) {
    int i;
    for (i = 0; i < strlen(data); i++)
        freq[data[i]]++;
    return i;
}

// Function to build the Huffman tree and generate codes for each symbol
void build_tree(struct node **root, const int freq[]) {
    int i, j, n = 256;
    struct node *node_array[n], *left, *right, *top;

    // Initialize the node array with leaf nodes
    for (i = 0, j = 0; i < n; i++) {
        if (freq[i])
            node_array[j++] = newNode(i, freq[i], NULL, NULL);
    }

    // Build the Huffman tree
    while (j > 1) {
        left = node_array[--j];
        right = node_array[--j];
        top = newNode('$', left->freq + right->freq, left, right);
        node_array[j++] = top;
    }

    *root = node_array[0];
}

// Function to encode the input string
void encode_string(struct node *root, const char *data, char *output) {
    int i, n = strlen(data), index = 0;
    char code[n];
    struct node *current;

    for (i = 0; i < n; i++) {
        current = root;
        memset(code, '\0', sizeof(code));
        while (current->left || current->right) {
            if (current->left && strchr(current->left->ch, data[i])) {
                strcat(code, "0");
                current = current->left;
            } else if (current->right && strchr(current->right->ch, data[i])) {
                strcat(code, "1");
                current = current->right;
            } else {
                fprintf(stderr, "Error: character %c does not exist in the Huffman tree.\n", data[i]);
                return;
            }
        }
        strcat(output, code);
    }
}

// Function to decode the input string
void decode_string(struct node *root, const char *data, char *output) {
    int i, n = strlen(data);
    struct node *current = root;

    for (i = 0; i < n; i++) {
        if (data[i] == '0' && current->left)
            current = current->left;
        else if (data[i] == '1' && current->right)
            current = current->right;
        else {
            fprintf(stderr, "Error: invalid Huffman code detected.\n");
            return;
        }

        if (!current->left && !current->right) {
            strcat(output, current->ch);
            current = root;
        }
    }
}

int main() {
    const char *data = "Huffman coding is a lossless data compression algorithm.";
    int freq[256] = {0};
    char encoded[1000] = "", decoded[1000] = "";
    struct node *root = NULL;

    build_freq_array(freq, data);
    build_tree(&root, freq);
    encode_string(root, data, encoded);
    printf("Encoded string: %s\n", encoded);
    decode_string(root, encoded, decoded);
    printf("Decoded string: %s\n", decoded);

    return 0;
}