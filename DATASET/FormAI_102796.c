//FormAI DATASET v1.0 Category: Compression algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_CHARS 256

/* Node structure for Huffman tree */
struct node {
    unsigned char data;
    unsigned freq;
    struct node *left, *right;
};

struct node *new_node(unsigned char data, unsigned freq)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

/* Priority queue structure for Huffman tree */
struct priority_queue {
    int size;
    int capacity;
    struct node **arr;
};

struct priority_queue *create_priority_queue(int capacity)
{
    struct priority_queue *pq = (struct priority_queue *)malloc(sizeof(struct priority_queue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->arr = (struct node **)malloc(sizeof(struct node *) * capacity);
    return pq;
}

void swap_nodes(struct node **a, struct node **b)
{
    struct node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct priority_queue *pq, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < pq->size && pq->arr[left]->freq < pq->arr[smallest]->freq)
        smallest = left;
    if (right < pq->size && pq->arr[right]->freq < pq->arr[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swap_nodes(&(pq->arr[idx]), &(pq->arr[smallest]));
        heapify(pq, smallest);
    }
}

int is_empty(struct priority_queue *pq)
{
    return pq->size == 0;
}

struct node *front(struct priority_queue *pq)
{
    return pq->arr[0];
}

void pop(struct priority_queue *pq)
{
    if (is_empty(pq))
        return;
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    heapify(pq, 0);
}

void push(struct priority_queue *pq, struct node *node)
{
    pq->size++;
    int i = pq->size - 1;
    while (i && node->freq < pq->arr[(i - 1) / 2]->freq) {
        pq->arr[i] = pq->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->arr[i] = node;
}

void build_priority_queue(struct priority_queue *pq, unsigned freq[])
{
    for (int i = 0; i < MAX_CHARS; i++) {
        if (freq[i] != 0) {
            struct node *temp = new_node(i, freq[i]);
            push(pq, temp);
        }
    }
}

struct node *build_huffman_tree(unsigned freq[])
{
    struct priority_queue *pq = create_priority_queue(MAX_CHARS);
    build_priority_queue(pq, freq);
    while (pq->size > 1) {
        struct node *left = front(pq);
        pop(pq);
        struct node *right = front(pq);
        pop(pq);
        struct node *top = new_node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        push(pq, top);
    }
    return front(pq);
}

void print_codes(struct node *root, char *str, int idx)
{
    if (root == NULL)
        return;
    if (root->data != '$') {
        printf("%c: %s\n", root->data, str);
        return;
    }
    str[idx] = '0';
    print_codes(root->left, str, idx + 1);
    str[idx] = '1';
    print_codes(root->right, str, idx + 1);
}

void huffman_compress(unsigned char *data)
{
    unsigned freq[MAX_CHARS] = {0};
    int len = strlen(data);
    for (int i = 0; i < len; i++)
        freq[data[i]]++;
    struct node *root = build_huffman_tree(freq);
    char code[MAX_CHARS] = {0};
    print_codes(root, code, 0);
}

int main()
{
    unsigned char data[] = "this is a string for huffman coding";
    huffman_compress(data);
    return 0;
}