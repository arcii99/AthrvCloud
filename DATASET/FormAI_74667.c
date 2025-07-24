//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHARS 256

struct node {
    int freq;
    int is_leaf;
    struct node *left;
    struct node *right;
};

struct heap {
    struct node **arr;
    int size;
};

struct huffman_code {
    char c;
    char *code;
};

struct node *create_node(int freq, int is_leaf, struct node *left, struct node *right) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->freq = freq;
    n->is_leaf = is_leaf;
    n->left = left;
    n->right = right;
    return n;
}

void swap_nodes(struct node **n1, struct node **n2) {
    struct node *temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void heapify(struct heap *h, int index) {
    int smallest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if (left < h->size && h->arr[left]->freq < h->arr[smallest]->freq)
        smallest = left;

    if (right < h->size && h->arr[right]->freq < h->arr[smallest]->freq)
        smallest = right;

    if (smallest != index) {
        swap_nodes(&h->arr[index], &h->arr[smallest]);
        heapify(h, smallest);
    }
}

void build_heap(struct heap *h, int *freq) {
    h->size = NUM_CHARS;
    h->arr = (struct node **)malloc(h->size * sizeof(struct node *));
    for (int i = 0; i < h->size; i++) {
        h->arr[i] = create_node(freq[i], 1, NULL, NULL);
    }

    for (int i = h->size / 2 - 1; i >= 0; i--) {
        heapify(h, i);
    }
}

struct node *extract_min(struct heap *h) {
    struct node *min = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapify(h, 0);
    return min;
}

void insert(struct heap *h, struct node *n) {
    h->size++;
    int i = h->size - 1;

    while (i > 0 && h->arr[(i - 1) / 2]->freq > n->freq) {
        h->arr[i] = h->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    h->arr[i] = n;
}

struct node *build_huffman_tree(int *freq) {
    struct heap *h = (struct heap *)malloc(sizeof(struct heap));
    build_heap(h, freq);

    while (h->size > 1) {
        struct node *n1 = extract_min(h);
        struct node *n2 = extract_min(h);

        struct node *new_n = create_node(n1->freq + n2->freq, 0, n1, n2);

        insert(h, new_n);
    }

    return extract_min(h);
}

void traverse_tree(struct node *n, struct huffman_code *hc, char *code, int depth) {
    if (n == NULL) {
        return;
    }

    traverse_tree(n->left, hc, code, depth + 1);

    if (n->is_leaf) {
        hc[(int)n->freq].c = (char)n->freq;
        hc[(int)n->freq].code = (char *)malloc((depth + 1) * sizeof(char));
        strcpy(hc[(int)n->freq].code, code);
    }

    traverse_tree(n->right, hc, code, depth + 1);
}

void print_huffman_codes(struct huffman_code *hc) {
    printf("Huffman Codes:\n");

    for (int i = 0; i < NUM_CHARS; i++) {
        if (strlen(hc[i].code) > 0) {
            printf("%c: %s\n", hc[i].c, hc[i].code);
        }
    }
}

void encode_text(char *text, struct huffman_code *hc) {
    printf("Encoded Text:\n");

    for (int i = 0; i < strlen(text); i++) {
        printf("%s", hc[(int)text[i]].code);
    }

    printf("\n");
}

void decode_text(char *encoded_text, struct node *huffman_tree) {
    printf("Decoded Text:\n");
    struct node *current_node = huffman_tree;

    for (int i = 0; i < strlen(encoded_text); i++) {
        if (encoded_text[i] == '0') {
            current_node = current_node->left;
        } else {
            current_node = current_node->right;
        }

        if (current_node->is_leaf) {
            printf("%c", (char)current_node->freq);
            current_node = huffman_tree;
        }
    }

    printf("\n");
}

int main() {
    char text[] = "Huffman Coding is a data compression algorithm.";

    int freq[NUM_CHARS] = {0};
    for (int i = 0; i < strlen(text); i++) {
        freq[(int)text[i]]++;
    }

    struct node *huffman_tree = build_huffman_tree(freq);

    struct huffman_code hc[NUM_CHARS] = {{'\0', "\0"}};
    char code[NUM_CHARS] = {'\0'};
    traverse_tree(huffman_tree, hc, code, 0);

    print_huffman_codes(hc);

    encode_text(text, hc);

    char encoded_text[] = "1011110110001101100011110011101000001111101000001110110111100111101110001010001001100101001";
    decode_text(encoded_text, huffman_tree);

    return 0;
}