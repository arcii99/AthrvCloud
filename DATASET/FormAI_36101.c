//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Shannon-Fano tree node */
struct node {
    char *symbol;
    int frequency;
    int code;
    struct node *left;
    struct node *right;
};

/* Function prototypes */
void shannon_fano_code(struct node *tree, int code, int size);
void sort_frequency_array(int *freq, char **symbols, int size);
struct node *build_tree(int *freq, char **symbols, int left, int right);


/* main function */
int main(void) {

    /* Example symbol frequency array */
    char *symbols[] = {"a", "b", "c", "d", "e", "f"};
    int freq[] = {4, 2, 3, 6, 1, 4};
    int size = sizeof(freq)/sizeof(freq[0]);

    /* Sort the symbol frequency arrays in non-increasing order */
    sort_frequency_array(freq, symbols, size);

    /* Build the Shannon-Fano tree */
    struct node *root = build_tree(freq, symbols, 0, size-1);

    /* Assign codes to each symbol */
    shannon_fano_code(root, 0, size);

    /* Print out the codes for each symbol */
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", symbols[i], root[i].code);
    }

    /* Free the memory used by the Shannon-Fano tree */
    free(root);

    return 0;
}

/* Sorts the symbol frequency arrays in non-increasing order */
void sort_frequency_array(int *freq, char **symbols, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (freq[i] < freq[j]) {
                int temp_freq = freq[i];
                char *temp_symbol = symbols[i];
                freq[i] = freq[j];
                symbols[i] = symbols[j];
                freq[j] = temp_freq;
                symbols[j] = temp_symbol;
            }
        }
    }
}

/* Builds the Shannon-Fano tree */
struct node *build_tree(int *freq, char **symbols, int left, int right) {

    /* Allocate memory for a new node */
    struct node *node = (struct node *) malloc(sizeof(struct node));

    /* Base case: if there is only one symbol left */
    if (left == right) {
        node->symbol = symbols[left];
        node->frequency = freq[left];
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    /* Calculate the total frequency for the range */
    int total_freq = 0;
    for (int i = left; i <= right; i++) {
        total_freq += freq[i];
    }

    /* Calculate the midpoint of the range */
    int midpoint_freq = 0;
    int midpoint = left;
    for (int i = left; i < right; i++) {
        midpoint_freq += freq[i];
        if (midpoint_freq <= total_freq/2) {
            midpoint = i;
        } else {
            break;
        }
    }

    /* Recursive case: split the range into two subranges */
    node->symbol = NULL;
    node->frequency = total_freq;
    node->left = build_tree(freq, symbols, left, midpoint);
    node->right = build_tree(freq, symbols, midpoint+1, right);

    return node;
}

/* Assigns the Shannon-Fano codes to each symbol */
void shannon_fano_code(struct node *tree, int code, int size) {
    if (tree == NULL) {
        return;
    }
    if (tree->symbol != NULL) {
        tree->code = code;
        code++;
    }
    shannon_fano_code(tree->left, code*2, size);
    shannon_fano_code(tree->right, code*2+1, size);
}