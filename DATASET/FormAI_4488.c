//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHARS 256

typedef struct {
    int freq;
    int index;
    char *code;
} huff_node;

int cmpfunc(const void* a, const void* b) {
    const huff_node *d1 = a;
    const huff_node *d2 = b;
    return (d2->freq - d1->freq);
}

void build_code_map(huff_node *nodes, int index, char *parent_code, int parent_len) {
    int i;
    char *node_code = malloc(parent_len + 2);
    strcpy(node_code, parent_code);
    if (parent_len > 0) {
        node_code[parent_len] = '0' + (index % 2);
        node_code[parent_len + 1] = '\0';
    }
    else {
        node_code[0] = '\0';
    }
    nodes[index].code = node_code;
    if (nodes[index].index >= 0) {
        printf("%c: %s\n", (char) nodes[index].index, node_code);
    }
    else {
        build_code_map(nodes, nodes[index].freq, node_code, parent_len + 1);
        build_code_map(nodes, nodes[index].freq + 1, node_code, parent_len + 1);
    }
}

void encode_string(char *str, huff_node *nodes) {
    printf("Encoded message: ");
    for (int i = 0; i < strlen(str); i++) {
        printf("%s", nodes[(int) str[i]].code);
    }
    printf("\n");
}

int main() {
    char test_string[] = "hello world";
    huff_node nodes[NUM_CHARS * 2 - 1];
    int freqs[NUM_CHARS] = { 0 };
    int i = 0;
    for (i = 0; i < strlen(test_string); i++) {
        freqs[(int) test_string[i]]++;
    }
    int num_nodes = NUM_CHARS;
    for (i = 0; i < NUM_CHARS; i++) {
        if (freqs[i] > 0) {
            nodes[i].freq = freqs[i];
            nodes[i].index = i;
            nodes[i].code = NULL;
        }
        else {
            nodes[i].freq = 0;
            nodes[i].index = -1;
            nodes[i].code = NULL;
            num_nodes--;
        }
    }
    qsort(nodes, NUM_CHARS, sizeof(huff_node), cmpfunc);
    for (i = NUM_CHARS; i < num_nodes; i++) {
        nodes[i].index = -1;
        nodes[i].code = NULL;
        nodes[i].freq = nodes[i*2 - NUM_CHARS].freq + nodes[i*2+1 - NUM_CHARS].freq;
    }
    build_code_map(nodes, num_nodes - 1, "", 0);
    encode_string(test_string, nodes);
    return 0;
}