//FormAI DATASET v1.0 Category: Compression algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    int freq;
    struct node* left;
    struct node* right;
} node;

// function to initialize a new node
node* init_node(char data, int freq) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// priority queue implementation
typedef struct prio_queue {
    int size;
    node** arr;
} prio_queue;

// function to initialize a new priority queue
prio_queue* init_prio_queue(int max_size) {
    prio_queue* new_queue = (prio_queue*)malloc(sizeof(prio_queue));
    new_queue->size = 0;
    new_queue->arr = (node**)malloc(sizeof(node*) * max_size);
    return new_queue;
}

// function to swap two nodes in the priority queue
void swap(prio_queue* queue, int i, int j) {
    node* temp = queue->arr[i];
    queue->arr[i] = queue->arr[j];
    queue->arr[j] = temp;
}

// function to insert a node into the priority queue
void insert(prio_queue* queue, node* new_node) {
    queue->size++;
    int i = queue->size - 1;
    queue->arr[i] = new_node;

    while(i != 0 && queue->arr[(i-1)/2]->freq > queue->arr[i]->freq) {
        swap(queue, i, (i-1)/2);
        i = (i-1)/2;
    }
}

// function to extract the minimum node from the priority queue
node* extract_min(prio_queue* queue) {
    node* min = queue->arr[0];
    queue->arr[0] = queue->arr[queue->size-1];
    queue->size--;
    int i = 0;

    while(2*i+1 < queue->size) {
        int left = 2*i+1;
        int right = 2*i+2;
        int min_child = (right < queue->size && queue->arr[right]->freq < queue->arr[left]->freq) ? right : left;

        if(queue->arr[i]->freq > queue->arr[min_child]->freq) {
            swap(queue, i, min_child);
            i = min_child;
        } else {
            break;
        }
    }

    return min;
}

// function to build the huffman tree
node* build_huffman_tree(int* freq_table, char* char_table, int char_count) {
    prio_queue* queue = init_prio_queue(char_count);

    for(int i = 0; i < char_count; i++) {
        node* new_node = init_node(char_table[i], freq_table[i]);
        insert(queue, new_node);
    }

    while(queue->size > 1) {
        node* left = extract_min(queue);
        node* right = extract_min(queue);

        int freq = left->freq + right->freq;
        node* new_node = init_node('\0', freq);
        new_node->left = left;
        new_node->right = right;

        insert(queue, new_node);
    }

    node* huffman_tree = extract_min(queue);
    return huffman_tree;
}

// function to generate the huffman code table
void generate_huffman_codes(node* root, char* prefix, char** codes_table) {
    if(root->left == NULL && root->right == NULL) {
        codes_table[root->data] = prefix;
    } else {
        char* left_prefix = (char*)malloc(sizeof(char) * (strlen(prefix) + 1));
        strcpy(left_prefix, prefix);
        strcat(left_prefix, "0");

        char* right_prefix = (char*)malloc(sizeof(char) * (strlen(prefix) + 1));
        strcpy(right_prefix, prefix);
        strcat(right_prefix, "1");

        generate_huffman_codes(root->left, left_prefix, codes_table);
        generate_huffman_codes(root->right, right_prefix, codes_table);
    }
}

// function to compress a string using the huffman encoding
char* compress(char* input, int* freq_table, char* char_table, node* huffman_tree, char** codes_table) {
    int input_size = strlen(input);

    // calculate the size of the compressed string
    int compressed_size = 0;
    for(int i = 0; i < input_size; i++) {
        compressed_size += strlen(codes_table[input[i]]);
    }

    // allocate memory for the compressed string
    char* compressed = (char*)malloc(sizeof(char) * (compressed_size+1));
    int j = 0;

    // encode each character and append it to the compressed string
    for(int i = 0; i < input_size; i++) {
        strcat(compressed, codes_table[input[i]]);
        j += strlen(codes_table[input[i]]);
    }

    compressed[j] = '\0';
    return compressed;
}

// example usage
int main() {
    // the string to be compressed
    char* input = "hello world";

    // create a frequency table for the characters in the string
    int freq_table[256] = {0};
    char char_table[256];
    int char_count = 0;
    int input_size = strlen(input);
    for(int i = 0; i < input_size; i++) {
        if(freq_table[input[i]] == 0) {
            char_table[char_count] = input[i];
            char_count++;
        }
        freq_table[input[i]]++;
    }

    // build the huffman tree and generate the huffman code table
    node* huffman_tree = build_huffman_tree(freq_table, char_table, char_count);
    char** codes_table = (char**)malloc(sizeof(char*) * 256);
    for(int i = 0; i < char_count; i++) {
        codes_table[char_table[i]] = (char*)malloc(sizeof(char) * 20);
    }
    generate_huffman_codes(huffman_tree, "", codes_table);

    // compress the input string using the huffman encoding
    char* compressed = compress(input, freq_table, char_table, huffman_tree, codes_table);
    printf("%s\n", compressed);

    return 0;
}