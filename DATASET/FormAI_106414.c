//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct node_t {
    unsigned char symbol;
    unsigned int frequency;
    struct node_t *left, *right;
} node_t;

typedef struct heap_t {
    size_t size;
    size_t capacity;
    node_t **arr;
} heap_t;

typedef struct code_table_t {
    char **bits;
    size_t *len;
} code_table_t;

heap_t *create_heap(size_t capacity) {
    heap_t *heap = malloc(sizeof(heap_t));
    if (!heap) {
        return NULL;
    }
    heap->arr = malloc(capacity * sizeof(node_t *));
    if (!heap->arr) {
        free(heap);
        return NULL;
    }
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void free_heap(heap_t *heap) {
    if (!heap) {
        return;
    }
    for (size_t i = 0; i < heap->size; ++i) {
        free(heap->arr[i]);
    }
    free(heap->arr);
    free(heap);
}

void push_heap(heap_t *heap, node_t *node) {
    if (heap->size == heap->capacity) {
        return;
    }
    heap->arr[heap->size++] = node;
    size_t i = heap->size - 1;
    while (i > 0 && heap->arr[i]->frequency < heap->arr[i/2]->frequency) {
        node_t *temp = heap->arr[i];
        heap->arr[i] = heap->arr[i/2];
        heap->arr[i/2] = temp;
        i = i/2;
    }
}

node_t *pop_heap(heap_t *heap) {
    if (heap->size == 0) {
        return NULL;
    }
    node_t *node = heap->arr[0];
    heap->arr[0] = heap->arr[--heap->size];
    size_t i = 0;
    while (2*i + 1 < heap->size) {
        size_t j = 2*i + 1;
        if (j + 1 < heap->size && heap->arr[j+1]->frequency < heap->arr[j]->frequency) {
            j++;
        }
        if (heap->arr[i]->frequency <= heap->arr[j]->frequency) {
            break;
        }
        node_t *temp = heap->arr[i];
        heap->arr[i] = heap->arr[j];
        heap->arr[j] = temp;
        i = j;
    }
    return node;
}

node_t *create_node(unsigned char symbol, unsigned int frequency) {
    node_t *node = malloc(sizeof(node_t));
    if (!node) {
        return NULL;
    }
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void free_node(node_t *node) {
    if (!node) {
        return;
    }
    free_node(node->left);
    free_node(node->right);
    free(node);
}

void build_frequency_table(const char *str, size_t len, unsigned int freq[256]) {
    memset(freq, 0, 256 * sizeof(unsigned int));
    for (size_t i = 0; i < len; ++i) {
        freq[(unsigned char)str[i]]++;
    }
}

node_t *build_huffman_tree(unsigned int freq[256]) {
    heap_t *heap = create_heap(256);
    if (!heap) {
        return NULL;
    }
    for (size_t i = 0; i < 256; ++i) {
        if (freq[i] > 0) {
            node_t *node = create_node(i, freq[i]);
            if (!node) {
                free_heap(heap);
                return NULL;
            }
            push_heap(heap, node);
        }
    }
    while (heap->size > 1) {
        node_t *left = pop_heap(heap);
        node_t *right = pop_heap(heap);
        node_t *parent = create_node(0, left->frequency + right->frequency);
        if (!parent) {
            free_heap(heap);
            free_node(left);
            free_node(right);
            return NULL;
        }
        parent->left = left;
        parent->right = right;
        push_heap(heap, parent);
    }
    node_t *root = pop_heap(heap);
    free_heap(heap);
    return root;
}

code_table_t *build_code_table(node_t *root) {
    code_table_t *table = malloc(sizeof(code_table_t));
    if (!table) {
        return NULL;
    }
    table->bits = malloc(256 * sizeof(char *));
    if (!table->bits) {
        free(table);
        return NULL;
    }
    table->len = malloc(256 * sizeof(size_t));
    if (!table->len) {
        free(table->bits);
        free(table);
        return NULL;
    }
    memset(table->bits, 0, 256 * sizeof(char *));
    memset(table->len, 0, 256 * sizeof(size_t));
    char *buffer = malloc(256);
    if (!buffer) {
        free(table->bits);
        free(table->len);
        free(table);
        return NULL;
    }
    size_t pos = 0;
    size_t n = 256;
    node_t **stack = malloc(n * sizeof(node_t *));
    if (!stack) {
        free(buffer);
        free(table->bits);
        free(table->len);
        free(table);
        return NULL;
    }
    size_t top = 0;
    stack[top++] = root;
    while (top > 0) {
        node_t *node = stack[--top];
        if (node->left) {
            buffer[pos++] = '0';
            if (top == n) {
                n *= 2;
                node_t **temp = realloc(stack, n * sizeof(node_t *));
                if (!temp) {
                    free(buffer);
                    free(table->bits);
                    free(table->len);
                    free(table);
                    free(stack);
                    return NULL;
                }
                stack = temp;
            }
            stack[top++] = node->right;
            stack[top++] = node->left;
        } else {
            buffer[pos] = '\0';
            table->bits[node->symbol] = strdup(buffer);
            table->len[node->symbol] = strlen(buffer);
            pos--;
        }
    }
    free(buffer);
    free(stack);
    return table;
}

void free_code_table(code_table_t *table) {
    if (!table) {
        return;
    }
    for (size_t i = 0; i < 256; ++i) {
        if (table->bits[i]) {
            free(table->bits[i]);
        }
    }
    free(table->bits);
    free(table->len);
    free(table);
}

void encode_str(const char *str, size_t len, code_table_t *table) {
    for (size_t i = 0; i < len; ++i) {
        printf("%s", table->bits[(unsigned char)str[i]]);
    }
}

int main(int argc, char *argv[]) {
    const char *str = "abracadabra";
    size_t len = strlen(str);
    unsigned int freq[256];
    build_frequency_table(str, len, freq);
    node_t *root = build_huffman_tree(freq);
    code_table_t *table = build_code_table(root);
    encode_str(str, len, table);
    free_code_table(table);
    free_node(root);
    return 0;
}