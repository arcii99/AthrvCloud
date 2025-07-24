//FormAI DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of distinct symbols
#define MAX_SYMBOLS 256 

// Define the maximum length of the code
#define MAX_CODE_LENGTH 32 

// Define the symbol frequency table 
int frequency[MAX_SYMBOLS] = { 0 };

// Define the Huffman code structure
struct huffman_node {
    int symbol;
    int frequency;
    struct huffman_node* left;
    struct huffman_node* right;
};

// Define the Huffman tree structure
struct huffman_tree {
    struct huffman_node* root;
};

// Initialize the Huffman tree
void init_huffman_tree(struct huffman_tree* ht)
{
    ht->root = NULL;
}

// Create a new Huffman node
struct huffman_node* new_huffman_node(int symbol, int frequency)
{
    struct huffman_node* node = (struct huffman_node*)malloc(sizeof(struct huffman_node));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a new Huffman node into the Huffman tree
void insert_huffman_node(struct huffman_tree* ht, struct huffman_node* node)
{
    struct huffman_node* ptr = ht->root;

    // If the root node is null, insert new node as root
    if (ptr == NULL) {
        ht->root = node;
        return;
    }

    // Iterate over the Huffman tree to find the right position to insert new node
    while (1) {
        if (node->frequency < ptr->frequency) {
            if (ptr->left == NULL) {
                ptr->left = node;
                break;
            }
            else {
                ptr = ptr->left;
            }
        }
        else {
            if (ptr->right == NULL) {
                ptr->right = node;
                break;
            }
            else {
                ptr = ptr->right;
            }
        }
    }
}

// Build the Huffman tree from the symbol frequency table
void build_huffman_tree(struct huffman_tree* ht)
{
    int i;

    // Create a Huffman node for each symbol with non-zero frequency
    for (i = 0; i < MAX_SYMBOLS; i++) {
        if (frequency[i] > 0) {
            insert_huffman_node(ht, new_huffman_node(i, frequency[i]));
        }
    }

    // Merge the two lowest-frequency nodes until only one node remains
    while (1) {
        struct huffman_node* left = ht->root;
        struct huffman_node* right = ht->root->right;
        struct huffman_node* parent = new_huffman_node(-1, left->frequency + right->frequency);

        parent->left = left;
        parent->right = right;

        if (right->right == NULL) {
            ht->root = parent;
            break;
        }

        ht->root = right;
        insert_huffman_node(ht, parent);
    }
}

// Recursively traverse the Huffman tree to encode each symbol
void encode_huffman_node(struct huffman_node* node, int code, int length, int* codes, int* lengths)
{
    if (node == NULL) {
        return;
    }

    if (node->symbol != -1) {
        codes[node->symbol] = code;
        lengths[node->symbol] = length;
    }
    else {
        encode_huffman_node(node->left, (code << 1) | 0, length + 1, codes, lengths);
        encode_huffman_node(node->right, (code << 1) | 1, length + 1, codes, lengths);
    }
}

// Encode the data using the generated Huffman code
void encode_huffman_data(char* data, int length, int* codes, int* lengths, char* encoded_data)
{
    int i, j, k;
    int code;
    int code_length;

    for (i = 0; i < length; i++) {
        code = codes[(int)data[i]];
        code_length = lengths[(int)data[i]];

        for (j = code_length - 1, k = 0; j >= 0; j--, k++) {
            if ((code & (1 << j)) != 0) {
                encoded_data[k / 8] |= (1 << (k % 8));
            }
            else {
                encoded_data[k / 8] &= ~(1 << (k % 8));
            }
        }
    }
}

// Driver function to compress the data using the Huffman coding technique
int main()
{
    char data[] = "This is a sample C program to demonstrate Huffman coding technique!";
    int codes[MAX_SYMBOLS] = { 0 };
    int lengths[MAX_SYMBOLS] = { 0 };
    char encoded_data[1024] = { 0 };

    // Calculate the frequency of each symbol in the input data
    int i, length = strlen(data);
    for (i = 0; i < length; i++) {
        frequency[(int)data[i]]++;
    }

    // Initialize the Huffman tree
    struct huffman_tree ht;
    init_huffman_tree(&ht);

    // Build the Huffman tree
    build_huffman_tree(&ht);

    // Encode each symbol in the input data using the Huffman code
    encode_huffman_node(ht.root, 0, 0, codes, lengths);
    encode_huffman_data(data, length, codes, lengths, encoded_data);

    printf("Original data:\n%s\n", data);
    printf("Encoded data:\n");
    for (i = 0; i < (length*4)/8; i++) {
        printf("%c", encoded_data[i]);
    }
    printf("\n");

    return 0;
}