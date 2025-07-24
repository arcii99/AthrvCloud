//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LENGTH 100

// Define the maximum number of characters in the alphabet
#define ALPHA_SIZE 26

// Define the maximum number of nodes in the trie
#define MAX_NODES 100000

// Define the trie node structure
struct TrieNode {
    int children[ALPHA_SIZE];   // An array of children nodes
    int is_end_of_word;         // A flag indicating if this node marks the end of a word
};

// Define the trie structure
struct Trie {
    struct TrieNode nodes[MAX_NODES];   // An array of nodes
    int root;                          // The root node of the trie
    int next_node;                     // The next available node in the trie
};

// Initialize a trie node
void init_node(struct TrieNode* node) {
    int i;
    for (i = 0; i < ALPHA_SIZE; i++) {
        node->children[i] = -1;
    }
    node->is_end_of_word = 0;
}

// Initialize a trie
void init_trie(struct Trie* trie) {
    init_node(&trie->nodes[0]);
    trie->root = 0;
    trie->next_node = 1;
}

// Insert a word into the trie
void trie_insert(struct Trie* trie, char* word) {
    int i;
    int node_index = trie->root;
    int len = strlen(word);

    for (i = 0; i < len; i++) {
        int child_index = word[i] - 'a';

        if (trie->nodes[node_index].children[child_index] == -1) {
            // Create a new node
            if (trie->next_node >= MAX_NODES) {
                printf("Error: trie is full\n");
                exit(1);
            }

            init_node(&trie->nodes[trie->next_node]);
            trie->nodes[node_index].children[child_index] = trie->next_node;
            trie->next_node++;
        }

        node_index = trie->nodes[node_index].children[child_index];
    }

    // Mark the last node as the end of a word
    trie->nodes[node_index].is_end_of_word = 1;
}

// Search for a word in the trie
int trie_search(struct Trie* trie, char* word) {
    int i;
    int node_index = trie->root;
    int len = strlen(word);

    for (i = 0; i < len; i++) {
        int child_index = word[i] - 'a';

        if (trie->nodes[node_index].children[child_index] == -1) {
            // Word not found
            return 0;
        }

        node_index = trie->nodes[node_index].children[child_index];
    }

    // Check if the last node marks the end of a word
    return trie->nodes[node_index].is_end_of_word;
}

int main() {
    // Initialize the trie
    struct Trie trie;
    init_trie(&trie);

    // Read input from the user
    printf("Enter words to insert into the trie, one per line:\n");

    char input[MAX_LENGTH];
    while (fgets(input, MAX_LENGTH, stdin)) {
        // Trim the newline character
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) > 0) {
            trie_insert(&trie, input);
        } else {
            break;
        }
    }

    // Search for words in the trie
    printf("Enter words to search for in the trie, one per line:\n");

    while (fgets(input, MAX_LENGTH, stdin)) {
        // Trim the newline character
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) > 0) {
            int found = trie_search(&trie, input);
            if (found) {
                printf("%s found in the trie\n", input);
            } else {
                printf("%s not found in the trie\n", input);
            }
        } else {
            break;
        }
    }

    return 0;
}