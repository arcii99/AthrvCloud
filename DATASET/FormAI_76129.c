//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct huff_tree_node {
    char data;
    int freq;
    struct huff_tree_node *left, *right;
};

struct huff_code {
    char data;
    char code[1000];
};

int freq_arr[256];

int get_min_freq_node_index(struct huff_tree_node* nodes[], int size) {
    if (size <= 0) return -1;
    int min_index = 0;
    for (int i = 1; i < size; i++) {
        if (nodes[i]->freq < nodes[min_index]->freq) {
            min_index = i;
        }
    }
    return min_index;
}

void create_huffman_tree(struct huff_tree_node* nodes[], int size) {
    while(size > 1) {
        int min_index1 = get_min_freq_node_index(nodes, size);
        struct huff_tree_node* min_node1 = nodes[min_index1];
        nodes[min_index1] = nodes[size-1];
        size--;

        int min_index2 = get_min_freq_node_index(nodes, size);
        struct huff_tree_node* min_node2 = nodes[min_index2];
        nodes[min_index2] = nodes[size-1];
        size--;

        struct huff_tree_node* parent = (struct huff_tree_node*) malloc(sizeof(struct huff_tree_node));
        parent->data = '\0';
        parent->freq = min_node1->freq + min_node2->freq;
        parent->left = min_node1;
        parent->right = min_node2;
        nodes[size] = parent;
        size++;
    }
}

void generate_huffman_codes(struct huff_tree_node* root, struct huff_code huff_codes[], char code[], int size) {
    if (!root) return;

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < size; i++)
            huff_codes[(int) root->data].code[i] = code[i];
        huff_codes[(int) root->data].data = root->data;
    }

    code[size] = '0';
    generate_huffman_codes(root->left, huff_codes, code, size + 1);
    code[size] = '1';
    generate_huffman_codes(root->right, huff_codes, code, size + 1);
}

void print_huffman_codes(struct huff_code huff_codes[]) {
    printf("\nHuffman Codes:\n");
    for (int i = 0; i < 256; i++) {
        if (freq_arr[i] > 0) {
            printf("%c: %s\n", huff_codes[i].data, huff_codes[i].code);
        }
    }
}

void print_huff_tree(struct huff_tree_node* root, int indent) {
    if (root == NULL)
        return;

    indent += 5;

    print_huff_tree(root->right, indent);

    printf("\n");
    for (int i = 5; i < indent; i++)
        printf(" ");
    printf("%c [%d]\n", root->data, root->freq);

    print_huff_tree(root->left, indent);
}

void encode_data(char data[], int size, struct huff_code huff_codes[], char encoded_output[], int* encoded_size) {
    for (int i=0; i<size; i++) {
        strcat(encoded_output, huff_codes[(int)data[i]].code);
    }
    *encoded_size = strlen(encoded_output);
}

void decode_data(struct huff_tree_node* root, char encoded_data[], int bits_to_read, char decoded_output[], int size) {
    int current_bit_index = -1;
    struct huff_tree_node* current_node = root;
    for (int i = 0; i < size; i++) {
        if (current_bit_index == bits_to_read-1) {
            current_bit_index = -1;
            current_node = root;
        }

        current_bit_index++;
        if (encoded_data[i] == '0') {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }

        if (current_node->left == NULL && current_node->right == NULL) {
            decoded_output[i] = current_node->data;
        }
    }
}

int main() {
    char data[] = "hello world!";
    int size = strlen(data);

    for (int i=0; i<256; i++) freq_arr[i] = 0;

    for (int i=0; i<size; i++) {
        freq_arr[(int)data[i]]++;
    }

    struct huff_tree_node* nodes[256];
    int nodes_size = 0;

    for (int i=0; i<256; i++) {
        if (freq_arr[i] > 0) {
            struct huff_tree_node* node = (struct huff_tree_node*) malloc(sizeof(struct huff_tree_node));
            node->data = i;
            node->freq = freq_arr[i];
            node->left = NULL;
            node->right = NULL;
            nodes[nodes_size++] = node;
        }
    }

    create_huffman_tree(nodes, nodes_size);
    struct huff_tree_node* root = nodes[0];

    struct huff_code huff_codes[256];
    char code[1000] = "";
    generate_huffman_codes(root, huff_codes, code, 0);

    printf("Original Data: %s\n", data);
    print_huffman_codes(huff_codes);

    char encoded_output[10000] = "";
    int encoded_size = 0;
    encode_data(data, size, huff_codes, encoded_output, &encoded_size);
    printf("\nEncoded Output: %s\n", encoded_output);

    char decoded_output[1000] = "";
    decode_data(root, encoded_output, encoded_size, decoded_output, size);
    printf("\nDecoded Output: %s\n\n", decoded_output);

    return 0;
}