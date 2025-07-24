//FormAI DATASET v1.0 Category: Compression algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Struct to hold the sequence of characters and their frequency
typedef struct SeqNode {
    char sequence[CHAR_BIT + 1];
    int freq;
    struct SeqNode *next;
} SeqNode;

// Struct to hold the encoding of a character
typedef struct Encoding {
    char sequence[CHAR_BIT + 1];
    struct Encoding *next;
} Encoding;

// This function takes in a sequence of characters and returns a new SeqNode
SeqNode *new_seq_node(char *sequence) {
    SeqNode *node = malloc(sizeof(SeqNode));
    strncpy(node->sequence, sequence, sizeof(node->sequence) - 1);
    node->freq = 1;
    node->next = NULL;
    return node;
}

// This function takes in a sequence of characters and a linked list of SeqNodes. It finds the SeqNode with the specified sequence or creates a new one if it doesn't exist
SeqNode *find_node(SeqNode **list, char *sequence) {
    SeqNode *ptr = *list;
    SeqNode *prev = NULL;
    while (ptr != NULL && strcmp(ptr->sequence, sequence) != 0) {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        ptr = new_seq_node(sequence);
        if (prev == NULL) {
            *list = ptr;
        } else {
            prev->next = ptr;
        }
    } else {
        ptr->freq++;
    }
    return ptr;
}

// This function frees all the memory associated with a linked list of SeqNodes
void free_seq_list(SeqNode **list) {
    SeqNode *ptr, *next;
    ptr = *list;
    while (ptr != NULL) {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    *list = NULL;
}

// This function takes in a linked list of SeqNodes and sorts it by frequency in decreasing order using bubble sort
void sort_seq_list(SeqNode **list) {
    SeqNode *ptr1, *ptr2, *end;
    int swapped;
    if (*list == NULL) {
        return;
    }
    end = NULL;
    do {
        swapped = 0;
        ptr1 = *list;
        while (ptr1->next != end) {
            ptr2 = ptr1->next;
            if (ptr1->freq < ptr2->freq) {
                SeqNode *temp = ptr1;
                ptr1 = ptr2;
                ptr2 = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        end = ptr1;
    } while (swapped);
}

// This function takes in a SeqNode, decrements its frequency, and returns a new SeqNode with the same sequence and frequency of 1. This is used to split a node into two
SeqNode *split_node(SeqNode *node) {
    SeqNode *new_node = new_seq_node(node->sequence);
    new_node->freq = 1;
    node->freq--;
    new_node->next = node->next;
    node->next = new_node;
    return new_node;
}

// This function takes in a linked list of SeqNodes and returns the tree root
SeqNode *build_tree(SeqNode **list) {
    sort_seq_list(list);
    while ((*list)->next != NULL) {
        SeqNode *left = *list;
        SeqNode *right = (*list)->next;
        SeqNode *parent = new_seq_node("");
        parent->freq = left->freq + right->freq;
        parent->next = right->next;
        right->next = left->next;
        left->next = parent;
        *list = parent;
        sort_seq_list(list);
    }
    return *list;
}

// This function takes in a tree root and generates the encodings for each character in the tree
Encoding *generate_encodings(SeqNode *root) {
    Encoding *table[CHAR_MAX];
    memset(table, 0, sizeof(table));
    Encoding *encodings = malloc(sizeof(Encoding));
    encodings->next = NULL;
    if (root->next == NULL) { // Only one node in the tree
        strncpy(encodings->sequence, "0", sizeof(encodings->sequence) - 1);
        table[(int)root->sequence[0]] = encodings;
        return encodings;
    }
    char zero[] = "0";
    char one[] = "1";
    void traverse_tree(SeqNode *node, Encoding *encoding) {
        if (node == NULL) {
            return;
        }
        Encoding *new_encoding = malloc(sizeof(Encoding));
        memcpy(new_encoding, encoding, sizeof(Encoding));
        if (node->next == NULL) { // Leaf node
            table[(int)node->sequence[0]] = new_encoding;
        } else { // Interior node
            traverse_tree(node->next, new_encoding);
            new_encoding = malloc(sizeof(Encoding));
            memcpy(new_encoding, encoding, sizeof(Encoding));
            strcat(new_encoding->sequence, one);
            traverse_tree(node->next->next, new_encoding);
        }
        free(new_encoding);
    }
    traverse_tree(root, encodings);
    return table;
}

// This function takes in a string, compresses it using Huffman coding, and returns the compressed data as a string
char *compress(char *data) {
    int data_len = strlen(data);
    SeqNode *list = NULL;
    for (int i = 0; i < data_len; i++) {
        find_node(&list, &data[i]);
    }
    SeqNode *root = build_tree(&list);
    Encoding *table[CHAR_MAX];
    memset(table, 0, sizeof(table));
    Encoding *encodings = generate_encodings(root);
    Encoding *encodings_ptr = encodings->next;
    while (encodings_ptr != NULL) {
        table[(int)encodings_ptr->sequence[0]] = encodings_ptr;
        encodings_ptr = encodings_ptr->next;
    }
    free(encodings);
    char *compressed_data = malloc(data_len * sizeof(char) + 1);
    int compressed_data_len = 0;
    char *ptr = compressed_data;
    int bits = 0;
    char buffer = 0;
    for (int i = 0; i < data_len; i++) {
        Encoding *encoding = table[(int)data[i]];
        int encoding_len = strlen(encoding->sequence);
        for (int j = 0; j < encoding_len; j++) {
            if (bits == CHAR_BIT) { // If buffer is full, write it to ptr
                *ptr++ = buffer;
                compressed_data_len++;
                buffer = 0;
                bits = 0;
            }
            if (encoding->sequence[j] == '1') {
                buffer |= (1 << (CHAR_BIT - 1 - bits)); // Set the bit at the current position in the buffer to 1
            }
            bits++;
        }
    }
    if (bits != CHAR_BIT) { // If there are bits left in the buffer, write it to ptr
        *ptr++ = buffer;
        compressed_data_len++;
    }
    *ptr = '\0';
    compressed_data = realloc(compressed_data, compressed_data_len + 1);
    return compressed_data;
}

// This function takes in a string of compressed data and returns the decompressed data as a string
char *decompress(char *compressed_data) {
    SeqNode *root = new_seq_node("");
    SeqNode *node = root;
    for (int i = 0; compressed_data[i] != '\0'; i++) {
        for (int j = CHAR_BIT - 1; j >= 0; j--) {
            int bit = (compressed_data[i] >> j) & 1;
            if (bit == 0) {
                if (node->next == NULL) {
                    SeqNode *new_node = new_seq_node("");
                    node->next = new_node;
                    node = new_node;
                } else {
                    node = node->next;
                }
            } else {
                if (node->next == NULL) {
                    char sequence[2] = { node->sequence[0], '\0' };
                    SeqNode *new_node = new_seq_node(sequence);
                    node->next = new_node;
                    node = new_node;
                } else {
                    node = node->next;
                }
            }
        }
    }
    char *data = malloc(CHAR_BIT + 1);
    char *ptr = data;
    void traverse_tree(SeqNode *node) {
        if (node->next == NULL) { // Leaf node
            *ptr = node->sequence[0];
            ptr++;
        } else { // Interior node
            traverse_tree(node->next);
            traverse_tree(node->next->next);
        }
    }
    traverse_tree(root);
    *ptr = '\0';
    data = realloc(data, strlen(data) + 1);
    free_seq_list(&root);
    return data;
}

int main() {
    char *data = "Hello, world!";
    printf("Original data: %s\n", data);
    char *compressed_data = compress(data);
    printf("Compressed data: ");
    for (int i = 0; compressed_data[i] != '\0'; i++) {
        printf("%02X ", (unsigned char)compressed_data[i]);
    }
    printf("\n");
    char *decompressed_data = decompress(compressed_data);
    printf("Decompressed data: %s\n", decompressed_data);
    free(compressed_data);
    free(decompressed_data);
    return 0;
}