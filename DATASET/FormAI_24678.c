//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *word;
    int count;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(char* w, int c) {
    Node* n = (Node*) malloc(sizeof(Node));
    n->word = (char*) malloc(strlen(w) + 1);
    strcpy(n->word, w);
    n->count = c;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void add_word(Node** root, char* w) {
    if (*root == NULL) {
        *root = create_node(w, 1);
    } else {
        int cmp = strcmp((*root)->word, w);
        if (cmp == 0) {
            (*root)->count++;
        } else if (cmp > 0) {
            add_word(&((*root)->left), w);
        } else {
            add_word(&((*root)->right), w);
        }
    }
}

void traverse_tree(Node* root) {
    if (root == NULL) {
        return;
    }
    traverse_tree(root->left);
    printf("%s: %d\n", root->word, root->count);
    traverse_tree(root->right);
}

int main() {
    char input[256];
    Node* root = NULL;

    printf("Enter a paragraph of text:\n");
    fgets(input, 256, stdin);

    // convert to lowercase
    int i;
    for (i = 0; i < strlen(input); i++) {
        input[i] = tolower(input[i]);
    }

    // replace non-alphanumeric characters with spaces
    for (i = 0; i < strlen(input); i++) {
        if (!isalnum(input[i])) {
            input[i] = ' ';
        }
    }

    // tokenize string
    char* token = strtok(input, " ");
    while (token != NULL) {
        add_word(&root, token);
        token = strtok(NULL, " ");
    }

    traverse_tree(root);

    return 0;
}