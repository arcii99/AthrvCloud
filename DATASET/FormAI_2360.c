//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024   //maximum length of input string
#define MAX_SYM 256    //maximum number of symbols that can be encoded
#define BITS 8         //number of bits in a byte

//structure to represent a symbol and its frequency
typedef struct frequency {
    int symbol;
    int freq;
} Frequency;

//structure to represent the Huffman tree node
typedef struct huffman_node {
    int symbol;
    int freq;
    struct huffman_node *left, *right;
} HuffmanNode;

//array to store the frequency of each symbol
int freq[MAX_SYM] = {0};

//array to store the Huffman codes for each symbol
char codes[MAX_SYM][MAX_LEN] = {'\0'};

//function to create a new Huffman tree node
HuffmanNode *new_huffman_node(int symbol, int freq, HuffmanNode *left, HuffmanNode *right) {
    HuffmanNode *node = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    node->symbol = symbol;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

//function to compare two Frequency objects based on their frequency (for qsort)
int compare_freq(const void *a, const void *b) {
    const Frequency *f1 = (const Frequency *)a;
    const Frequency *f2 = (const Frequency *)b;
    return f2->freq - f1->freq;
}

//function to build the Huffman tree and generate the codes for each symbol
void build_huffman_tree(Frequency *freq_array, int num_freqs) {
    //initialize a priority queue of Huffman tree nodes
    HuffmanNode **pq = (HuffmanNode **)malloc(num_freqs * sizeof(HuffmanNode *));
    int pq_size = 0;    //size of the priority queue
    for (int i = 0; i < num_freqs; i++) {
        pq[pq_size++] = new_huffman_node(freq_array[i].symbol, freq_array[i].freq, NULL, NULL);
    }

    //build the Huffman tree by repeatedly combining the two lowest frequency nodes into a new node
    while (pq_size > 1) {
        //extract the two lowest frequency nodes from the priority queue
        HuffmanNode *left = pq[--pq_size];
        HuffmanNode *right = pq[--pq_size];

        //create a new node with combined frequency and add it to the priority queue
        HuffmanNode *parent = new_huffman_node(-1, left->freq + right->freq, left, right);
        pq[pq_size++] = parent;
    }

    //the root of the Huffman tree is the only node left in the priority queue
    HuffmanNode *root = pq[0];

    //generate the Huffman codes for each symbol by traversing the Huffman tree
    char path[MAX_LEN];
    path[0] = '\0'; //start with an empty path
    int path_len = 0;
    void traverse_huffman_tree(HuffmanNode *node) {
        if (node->symbol != -1) {   //if this is a leaf node
            path[path_len] = '\0';
            strcpy(codes[node->symbol], path);  //copy the current path to the code array
        } else {   //if this is not a leaf node
            path[path_len++] = '0';
            traverse_huffman_tree(node->left);
            path[--path_len] = '1';
            traverse_huffman_tree(node->right);
            path[--path_len] = '\0';
        }
    }
    traverse_huffman_tree(root);   //start traversing the tree from the root

    free(pq);  //free the priority queue
}

//function to compress a string using Huffman coding
void compress(char *input, char *output) {
    //calculate the frequency of each symbol in the input string
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        freq[input[i]]++;
    }

    //build a sorted array of Frequency objects from the frequency array
    Frequency freq_array[MAX_SYM];
    int num_freqs = 0;
    for (int i = 0; i < MAX_SYM; i++) {
        if (freq[i] > 0) {
            freq_array[num_freqs++] = (Frequency){i, freq[i]};
        }
    }
    qsort(freq_array, num_freqs, sizeof(Frequency), compare_freq); //sort the array by frequency in descending order

    //build the Huffman tree and generate the codes for each symbol
    build_huffman_tree(freq_array, num_freqs);

    //encode the input string using the Huffman codes and write it to the output file
    int output_len = 0;
    char current_byte = 0;
    int current_bit = 0;
    for (int i = 0; i < len; i++) {
        char *code = codes[input[i]];
        int code_len = strlen(code);
        for (int j = 0; j < code_len; j++) {
            if (code[j] == '1') {
                current_byte |= (1 << current_bit);
            }
            current_bit++;
            if (current_bit == BITS) {
                output[output_len++] = current_byte;
                current_byte = 0;
                current_bit = 0;
            }
        }
    }
    if (current_bit > 0) {  //if there are remaining bits in the last byte
        output[output_len++] = current_byte;
    }
    output[output_len] = '\0';   //add the null terminator to the output string
}

int main() {
    char input[MAX_LEN], output[MAX_LEN];

    //read input string from standard input
    printf("Enter a string to compress: ");
    fgets(input, MAX_LEN, stdin);
    int len = strlen(input);
    if (input[len-1] == '\n') {
        input[len-1] = '\0';   //remove the newline character
    }

    //compress the input string and print the compressed string as binary bytes
    compress(input, output);
    printf("Compressed string as binary bytes:\n");
    for (int i = 0; i < strlen(output); i++) {
        printf("%02X ", (unsigned char)output[i]);
    }
    printf("\n");

    return 0;
}