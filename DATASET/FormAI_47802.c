//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of characters in the input string
#define MAX_INPUT_LEN 100

// define the structure of a Huffman tree node
typedef struct node {
    char c;
    int freq;
    struct node *left, *right;
} node;

// allocate a new node with a given character and frequency
node* new_node(char c, int freq) {
    node* n = malloc(sizeof(node));
    n->c = c;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

// compare two nodes based on their frequency
int compare_nodes(const void* a, const void* b) {
    node** na = (node**) a;
    node** nb = (node**) b;
    return (*na)->freq - (*nb)->freq;
}

// build a Huffman tree from a given input string
node* build_huffman_tree(char* input) {
    // count the frequency of each character in the input string
    int freq[256] = {0};
    for (int i = 0; i < strlen(input); i++) {
        freq[(int) input[i]]++;
    }
    // create a node for each character with a non-zero frequency
    node* nodes[256];
    int num_nodes = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            nodes[num_nodes++] = new_node((char) i, freq[i]);
        }
    }
    // build the Huffman tree by repeatedly merging the two nodes with the lowest frequency
    while (num_nodes > 1) {
        qsort(nodes, num_nodes, sizeof(node*), compare_nodes);
        node* left = nodes[0];
        node* right = nodes[1];
        node* parent = new_node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        nodes[0] = parent;
        for (int i = 1; i < num_nodes - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        num_nodes--;
    }
    return nodes[0];
}

// print the code for each character in the Huffman tree
void print_codes(node* root, int code[], int length) {
    if (!root->left && !root->right) {
        printf("%c: ", root->c);
        for (int i = 0; i < length; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
        return;
    }
    code[length] = 0;
    print_codes(root->left, code, length + 1);
    code[length] = 1;
    print_codes(root->right, code, length + 1);
}

// main function
int main() {
    printf("Enter a string to encode using Huffman coding (max %d characters):\n", MAX_INPUT_LEN);
    char input[MAX_INPUT_LEN];
    fgets(input, MAX_INPUT_LEN, stdin);
    input[strcspn(input, "\n")] = '\0';
    node* root = build_huffman_tree(input);
    printf("\nThe Huffman codes for each character in the input string are:\n");
    int code[256];
    print_codes(root, code, 0);
    return 0;
}