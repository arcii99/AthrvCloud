//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This is a simple implementation of a compression algorithm using Huffman coding technique*/

#define ASCII_CODE_LENGTH 256

typedef struct Node{
    char character;
    int frequency;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(char character, int frequency){
    Node *node = (Node*) malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void swap(Node **a, Node **b){
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(Node **nodes_array, int i, int total_nodes){
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child < total_nodes && nodes_array[left_child]->frequency > nodes_array[largest]->frequency)
        largest = left_child;

    if (right_child < total_nodes && nodes_array[right_child]->frequency > nodes_array[largest]->frequency)
        largest = right_child;

    if (largest != i){
        swap(&nodes_array[i], &nodes_array[largest]);
        heapify(nodes_array, largest, total_nodes);
    }
}

Node *extract_max(Node **nodes_array, int *total_nodes){
    Node *max_node = nodes_array[0];
    nodes_array[0] = nodes_array[(*total_nodes)-1];
    (*total_nodes)--;
    heapify(nodes_array, 0, (*total_nodes));
    return max_node;
}

void insert_node(Node **nodes_array, int *total_nodes, Node *node){
    (*total_nodes)++;
    int i = (*total_nodes) - 1;

    while(i != 0 && node->frequency > nodes_array[(i-1)/2]->frequency){
        nodes_array[i] = nodes_array[(i-1)/2];
        i = (i-1)/2;
    }

    nodes_array[i] = node;
}

int is_leaf(Node *node){
    return !(node->left) && !(node->right);
}

void print_codes(Node *node, int *arr, int top){
    if (node->left){
        arr[top] = 0;
        print_codes(node->left, arr, top+1);
    }

    if (node->right){
        arr[top] = 1;
        print_codes(node->right, arr, top+1);
    }

    if (is_leaf(node)){
        printf("%c: ", node->character);
        for(int i=0; i<top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void build_tree(char *data, int *frequencies, int length){
    Node *left, *right, *top = NULL;
    Node **nodes_array = (Node **) malloc(length * sizeof(Node *));
    int total_nodes = 0;

    for(int i=0; i<length; i++)
        nodes_array[i] = create_node(data[i], frequencies[i]);
    total_nodes = length;

    while(total_nodes != 1){
        left = extract_max(nodes_array, &total_nodes);
        right = extract_max(nodes_array, &total_nodes);
        top = create_node('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
    
        insert_node(nodes_array, &total_nodes, top);
    }

    int arr[100], top_value = 0;
    print_codes(top, arr, top_value);
}

int main(){
    char data[] = "peaceful";
    int frequencies[ASCII_CODE_LENGTH] = {0};
    int length = strlen(data);

    for(int i=0; i<length; i++)
        frequencies[(int)data[i]]++;

    build_tree(data, frequencies, length);

    return 0;
}