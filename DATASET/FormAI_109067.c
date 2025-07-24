//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char character;
    int freq;
    struct node *left;
    struct node *right;
} node;

typedef struct dictionary {
    char character;
    char *code;
} dict;

int cmp(const void *a, const void *b) {
    node **nodeA = (node **)a;
    node **nodeB = (node **)b;

    if((*nodeA)->freq > (*nodeB)->freq) return 1;
    else if((*nodeA)->freq < (*nodeB)->freq) return -1;
    else return 0;
}

void frequency(char *input, int len, node **nodes, int *size) {
    for(int i = 0; i < len; i++) {
        char c = input[i];
        int found = 0;
        for(int j = 0; j < *size; j++) {
            if(nodes[j]->character == c) {
                found = 1;
                nodes[j]->freq++;
            }
        }
        if(!found) {
            node *n = (node *)malloc(sizeof(node));
            n->character = c;
            n->freq = 1;
            n->left = NULL;
            n->right = NULL;
            nodes[*size] = n;
            (*size)++;
        }
    }
}

node* buildHuffmanTree(node **nodes, int size) {
    qsort(nodes, size, sizeof(node *), cmp);

    while(size > 1) {
        node *n1 = nodes[0];
        node *n2 = nodes[1];

        node *parent = (node *)malloc(sizeof(node));
        parent->character = '\0';
        parent->freq = n1->freq + n2->freq;
        parent->left = n1;
        parent->right = n2;

        nodes[0] = parent;
        for(int i = 1; i < size - 1; i++) {
            nodes[i] = nodes[i+1];
        }
        size--;

        qsort(nodes, size, sizeof(node *), cmp);
    }

    return nodes[0];
}

void code(node *n, char *prefix, int level, dict *map) {
    if(n->left == NULL && n->right == NULL) {
        dict d;
        d.character = n->character;
        d.code = (char *)malloc((level+1) * sizeof(char));
        strcat(d.code, prefix);
        map[(int)n->character] = d;
    } else {
        prefix[level] = '0';
        prefix[level+1] = '\0';
        code(n->left, prefix, level+1, map);
        prefix[level] = '1';
        prefix[level+1] = '\0';
        code(n->right, prefix, level+1, map);
    }
}

void printDictionary(dict *map) {
    for(int i = 0; i < 256; i++) {
        dict d = map[i];
        if(d.character != '\0') {
            printf("%c\t%s\n", d.character, d.code);
        }
    }
}

char* encode(char *input, int len, dict *map) {
    char *output = (char *)malloc(len * 8 * sizeof(char));
    output[0] = '\0';
    for(int i = 0; i < len; i++) {
        strcat(output, map[(int)input[i]].code);
    }

    return output;
}

char* decode(char *input, int len, node *tree) {
    char *output = (char *)malloc(len * sizeof(char));
    output[0] = '\0';
    int pos = 0;
    node *n = tree;
    for(int i = 0; i < len; i++) {
        if(input[i] == '0') {
            n = n->left;
        } else {
            n = n->right;
        }
        if(n->left == NULL && n->right == NULL) {
            output[pos++] = n->character;
            n = tree;
        }
    }

    output[pos] = '\0';
    return output;
}

int main() {
    char input[] = "this is an example of huffman encoding";
    int len = strlen(input);

    node **nodes = (node **)malloc(256 * sizeof(node *));
    int size = 0;

    frequency(input, len, nodes, &size);

    node *tree = buildHuffmanTree(nodes, size);

    dict *map = (dict *)malloc(256 * sizeof(dict));
    for(int i = 0; i < 256; i++) {
        dict d;
        d.character = '\0';
        d.code = "";
        map[i] = d;
    }

    char prefix[256];
    prefix[0] = '\0';
    code(tree, prefix, 0, map);

    printDictionary(map);

    char *encoded = encode(input, len, map);
    printf("%s\n", encoded);

    char *decoded = decode(encoded, strlen(encoded), tree);
    printf("%s\n", decoded);

    free(nodes);
    free(map);
    free(encoded);
    free(decoded);

    return 0;
}