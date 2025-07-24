//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the node structure
typedef struct node {
    int frequency;
    char letter;
    struct node *left, *right;
} Node;

// Define the frequency table structure
typedef struct frequency_table {
    int size;
    Node **nodes;
} FTable;

// Define the huffman tree structure
typedef struct huffman_tree {
    Node *root;
} HTree;

// Create a new node
Node* create_node(char letter, int frequency) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->letter = letter;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Create a new frequency table
FTable* create_frequency_table() {
    FTable* table = (FTable*) malloc(sizeof(FTable));
    table->size = 0;
    table->nodes = (Node**) malloc(sizeof(Node*));
    return table;
}

// Add a new node to the frequency table
void add_node_to_table(FTable* table, Node* node) {
    table->size++;
    table->nodes = (Node**) realloc(table->nodes, table->size * sizeof(Node*));
    table->nodes[table->size-1] = node;
}

// Compare function for sorting nodes by frequency
int compare_nodes(const void* a, const void* b) {
    const Node* na = *(const Node**)a;
    const Node* nb = *(const Node**)b;
    if (na->frequency < nb->frequency) return -1;
    if (na->frequency > nb->frequency) return 1;
    return 0;
}

// Sort the frequency table by frequency using quicksort
void sort_frequency_table(FTable* table) {
    qsort(table->nodes, table->size, sizeof(Node*), compare_nodes);
}

// Build the huffman tree
HTree* build_huffman_tree(FTable* table) {
    sort_frequency_table(table);
    while (table->size > 1) {
        Node* left = table->nodes[0];
        Node* right = table->nodes[1];
        Node* parent = create_node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        table->nodes[0] = parent;
        for (int i = 1; i < table->size-1; i++) {
            table->nodes[i] = table->nodes[i+1];
        }
        table->size--;
        sort_frequency_table(table);
    }
    HTree* tree = (HTree*) malloc(sizeof(HTree));
    tree->root = table->nodes[0];
    return tree;
}

// Recursive function to encode each letter in the huffman tree
void encode_letter(Node* node, int code, int length, int* codes, int* length_arr) {
    if (node->left == NULL && node->right == NULL) {
        codes[(int)node->letter] = code;
        length_arr[(int)node->letter] = length;
    } else {
        encode_letter(node->left, code << 1, length + 1, codes, length_arr);
        encode_letter(node->right, (code << 1) + 1, length + 1, codes, length_arr);
    }
}

// Encode the huffman tree
void encode_huffman_tree(Node* node, int* codes, int* length_arr) {
    encode_letter(node, 0, 0, codes, length_arr);
}

// Encode the string using the huffman codes
void encode_string(char* string, int size, int* codes, int* length_arr, int* encoded_string_size, int* encoded_string) {
    int encoded_bits = 0;
    for (int i = 0; i < size; i++) {
        int code = codes[(int)string[i]];
        int length = length_arr[(int)string[i]];
        encoded_bits += length;
        int j = 0;
        while (length > 0) {
            if (encoded_bits % 32 == 0) {
                encoded_string = (int*) realloc(encoded_string, (*encoded_string_size+1) * sizeof(int));
                (*encoded_string_size)++;
                encoded_string[(*encoded_string_size)-1] = 0;
            }
            encoded_string[(*encoded_string_size)-1] += ((code >> j) & 1) * pow(2, (encoded_bits % 32));
            length--;
            j++;
        }
    }
}

// Print the encoded string in binary format
void print_binary_string(int* encoded_string, int size) {
    for (int i = 0; i < size; i++) {
        int j = 31;
        while (j >= 0) {
            printf("%d", (encoded_string[i] >> j) & 1);
            j--;
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    char* input_string = "Huffman Coding Example";
    int input_size = strlen(input_string);

    FTable* frequency_table = create_frequency_table();

    // Get the frequency of each letter in the string and add it to the frequency table
    int* letter_counts = (int*) calloc(256, sizeof(int));
    for (int i = 0; i < input_size; i++) {
        letter_counts[(int)input_string[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (letter_counts[i] > 0) {
            add_node_to_table(frequency_table, create_node((char)i, letter_counts[i]));
        }
    }

    HTree* huffman_tree = build_huffman_tree(frequency_table);

    int* huffman_codes = (int*) calloc(256, sizeof(int));
    int* huffman_code_lengths = (int*) calloc(256, sizeof(int));
    encode_huffman_tree(huffman_tree->root, huffman_codes, huffman_code_lengths);

    int encoded_string_size = 0;
    int* encoded_string = (int*) malloc(sizeof(int));

    encode_string(input_string, input_size, huffman_codes, huffman_code_lengths, &encoded_string_size, encoded_string);

    printf("Original string: %s\n", input_string);
    printf("Encoded string: ");
    print_binary_string(encoded_string, encoded_string_size);

    return 0;
}