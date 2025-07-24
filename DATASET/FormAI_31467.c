//FormAI DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000 // Maximum length of input string
#define MAX_ALPHA 256 // Maximum ASCII value of a character
#define MAX_BIT 8 // Maximum bit value for a single character

void compress(char *input)
{
    int freq[MAX_ALPHA] = { 0 }; // Create an array to store frequency of characters in the input
    int len = strlen(input); // Find the length of the input string
    for (int i = 0; i < len; i++) {
        freq[input[i]]++; // Increment frequency of character at the given position
    }

    // Create a priority queue for all the characters with non-zero frequency
    struct node {
        char c;
        int freq;
        struct node *left, *right;
    };
    struct pq {
        int size;
        struct node **data;
    };
    struct pq *queue = calloc(1, sizeof(struct pq));
    queue->data = calloc(MAX_ALPHA, sizeof(struct node *));
    for (int i = 0; i < MAX_ALPHA; i++) {
        if (freq[i] > 0) {
            struct node *new_node = calloc(1, sizeof(struct node));
            new_node->c = (char)i;
            new_node->freq = (int)freq[i];
            queue->data[queue->size++] = new_node;
        }
    }

    // Build the Huffman tree by repeatedly combining the lowest frequency nodes
    while (queue->size > 1) {
        struct node *left = queue->data[0];
        struct node *right = queue->data[1];

        struct node *parent = calloc(1, sizeof(struct node));
        parent->freq = left->freq + right->freq;
        parent->left = left;
        parent->right = right;

        int index = 0;
        while (index < queue->size-1 && parent->freq > queue->data[index+1]->freq) {
            queue->data[index] = queue->data[index+1];
            index++;
        }
        queue->data[index] = parent;
        queue->size--;
    }
    struct node *root = queue->data[0];

    // Generate codes for each character
    char codes[MAX_ALPHA][MAX_LEN];
    void generate_codes(struct node *n, char *buffer, int depth) {
        if (n->left) {
            buffer[depth] = '0';
            generate_codes(n->left, buffer, depth + 1);
        }
        if (n->right) {
            buffer[depth] = '1';
            generate_codes(n->right, buffer, depth + 1);
        }
        if (!n->left && !n->right) {
            strcpy(codes[n->c], buffer);
        }
    }
    char buffer[MAX_LEN];
    generate_codes(root, buffer, 0);

    // Encode the input string using the generated codes
    char output[MAX_LEN*MAX_BIT+1] = { 0 };
    int output_len = 0;
    for (int i = 0; i < len; i++) {
        strcat(output, codes[input[i]]);
        output_len += strlen(codes[input[i]]);
    }

    // Convert the encoded bits into bytes and write them to stdout
    if (output_len % MAX_BIT != 0) {
        // Append trailing zeros to make sure the output has a multiple of 8 bits
        int padding = MAX_BIT - (output_len % MAX_BIT);
        for (int i = 0; i < padding; i++) {
            strcat(output, "0");
        }
        output_len += padding;
    }
    unsigned char byte = 0;
    for (int i = 0; i < output_len; i++) {
        byte = byte << 1;
        if (output[i] == '1') {
            byte |= 1;
        }
        if ((i+1) % MAX_BIT == 0) {
            putchar(byte);
            byte = 0;
        }
    }
    free(queue->data);
    free(queue);
}

int main()
{
    char input[MAX_LEN];
    printf("Enter string to compress: ");
    fgets(input, MAX_LEN, stdin);
    compress(input);
    return 0;
}