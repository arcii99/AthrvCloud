//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_COUNT 256
#define MAX_BIT_COUNT 10

typedef struct node {
    char ch;
    int freq;
    struct node *left;
    struct node *right;
} node_t;

typedef struct priority_queue {
    int size;
    node_t *data[MAX_NODE_COUNT];
} priority_queue_t;

void priority_queue_init(priority_queue_t *pq) {
    pq->size = 0;
}

void priority_queue_insert(priority_queue_t *pq, node_t *node) {
    if (pq->size == MAX_NODE_COUNT) {
        printf("Priority Queue Full\n");
        return;
    }

    int i = ++pq->size;
    while (i != 1 && node->freq < pq->data[i / 2]->freq) {
        pq->data[i] = pq->data[i / 2];
        i /= 2;
    }
    pq->data[i] = node;
}

node_t* priority_queue_pop(priority_queue_t *pq) {
    if (pq->size == 0) {
        return NULL;
    }

    node_t *node = pq->data[1];
    node_t *temp = pq->data[pq->size--];

    int parent = 1, child = 2;
    while (child <= pq->size) {
        if (child < pq->size && pq->data[child]->freq > pq->data[child + 1]->freq) {
            child++;
        }
        if (temp->freq <= pq->data[child]->freq) {
            break;
        }

        pq->data[parent] = pq->data[child];
        parent = child;
        child *= 2;
    }
    pq->data[parent] = temp;

    return node;
}

void huffman_tree_traverse(node_t *node, int level, char *code, char code_table[MAX_NODE_COUNT][MAX_BIT_COUNT]) {
    if (!node->left && !node->right) {
        code[level] = '\0';
        strcpy(code_table[(int)node->ch], code);
        return;
    }

    code[level] = '0';
    huffman_tree_traverse(node->left, level + 1, code, code_table);

    code[level] = '1';
    huffman_tree_traverse(node->right, level + 1, code, code_table);
}

void huffman_tree_build(char *input_string, node_t **root) {
    int freq_table[MAX_NODE_COUNT] = {0};

    int length = strlen(input_string);
    for (int i = 0; i < length; i++) {
        freq_table[(int)input_string[i]]++;
    }

    priority_queue_t pq;
    priority_queue_init(&pq);

    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        if (freq_table[i] > 0) {
            node_t *node = (node_t*)malloc(sizeof(node_t));
            node->ch = (char)i;
            node->freq = freq_table[i];
            node->left = NULL;
            node->right = NULL;
            priority_queue_insert(&pq, node);
        }
    }

    while (pq.size > 1) {
        node_t *node_a = priority_queue_pop(&pq);
        node_t *node_b = priority_queue_pop(&pq);

        node_t *sum_node = (node_t*)malloc(sizeof(node_t));
        sum_node->ch = '\0';
        sum_node->freq = node_a->freq + node_b->freq;
        sum_node->left = node_a;
        sum_node->right = node_b;

        priority_queue_insert(&pq, sum_node);
    }

    *root = priority_queue_pop(&pq);
}

int main() {
    char input_string[MAX_NODE_COUNT] = "hello world";
    node_t *root = NULL;
    huffman_tree_build(input_string, &root);

    char code_table[MAX_NODE_COUNT][MAX_BIT_COUNT] = {0};
    char code[MAX_BIT_COUNT] = {0};
    huffman_tree_traverse(root, 0, code, code_table);

    printf("Huffman Codes:\n");
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        if (strlen(code_table[i]) > 0) {
            printf("%c: %s\n", (char)i, code_table[i]);
        }
    }

    return 0;
}