//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 256 // Maximize code length to 256 characters

/* Definition of Huffman node */
typedef struct node {
    char character;
    int frequency;
    struct node* left;
    struct node* right;
} node_t;

/* Definition of linked list node */
typedef struct linked_list_node {
    node_t* node;
    struct linked_list_node* next;
} linked_list_node_t;

/* Function to create a new Huffman node */
node_t* create_node(char character, int frequency) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to create a new linked list node */
linked_list_node_t* create_linked_list_node(node_t* node) {
    linked_list_node_t* new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
    new_node->node = node;
    new_node->next = NULL;
    return new_node;
}

/* Function to append new node to linked list */
void append_node(linked_list_node_t** head_ref, node_t* node) {
    linked_list_node_t* new_node = create_linked_list_node(node);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    linked_list_node_t* current = *head_ref;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

/* Function to delete the linked list */
void delete_linked_list(linked_list_node_t* head) {
    linked_list_node_t* current = head;
    while (current != NULL) {
        linked_list_node_t* temp = current;
        current = current->next;
        free(temp->node);
        free(temp);
    }
}

/* Function to combine two nodes weighted frequencies and create a merged node */
node_t* merge_nodes(node_t* left, node_t* right) {
    int new_frequency = left->frequency + right->frequency;
    node_t* new_node = create_node('\0', new_frequency);
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

/* Function to pop the node with the lowest frequency from linked list */
node_t* pop_lowest_frequency(linked_list_node_t** head_ref) {
    linked_list_node_t* current_node = *head_ref;
    linked_list_node_t* previous_node = NULL;
    linked_list_node_t* lowest_node = *head_ref;
    node_t* lowest_node_pointer = lowest_node->node;

    while (current_node != NULL && current_node->next != NULL) {
        if (current_node->next->node->frequency < lowest_node_pointer->frequency) {
            lowest_node = current_node->next;
            lowest_node_pointer = lowest_node->node;
            previous_node = current_node;
        }
        current_node = current_node->next;
    }

    /* Handle edge cases */
    if (previous_node == NULL) {
        *head_ref = lowest_node->next;
    } else {
        previous_node->next = lowest_node->next;
    }

    node_t* popped_node = lowest_node_pointer;
    free(lowest_node);
    return popped_node;
}

/* Function to perform Huffman encoding */
void huffman_encoding(char* input_string, int input_length, char** encoded_output, int* encoded_output_length) {
    int count_characters_array[MAX_CODE_LENGTH] = {0};

    /* Store individual character frequency in array */
    for (int i = 0; i < input_length; ++i) {
        ++count_characters_array[input_string[i]];
    }

    linked_list_node_t* linked_list_head = NULL;

    /* Appending individual character as node to linked list with frequency as data for each node */
    for (int i = 0; i < MAX_CODE_LENGTH; ++i) {
        if (count_characters_array[i] > 0) {
            node_t* new_node = create_node(i, count_characters_array[i]);
            append_node(&linked_list_head, new_node);
        }
    }

    /* Combine two nodes with minimum weighted frequency and create a merged node until linked list only contains one node */
    while (linked_list_head->next != NULL) {
        node_t* left = pop_lowest_frequency(&linked_list_head);
        node_t* right = pop_lowest_frequency(&linked_list_head);
        node_t* new_node = merge_nodes(left, right);
        append_node(&linked_list_head, new_node);
    }

    node_t* huffman_tree_root = linked_list_head->node;

    /* Create a code array that stores the Huffman code for each character in input_string */
    char code[MAX_CODE_LENGTH];
    int top = 0;
    memset(code, 0, sizeof(code));

    /* Traverse the Huffman tree and store the Huffman code in the code array */
    void print_codes(node_t* node, char code[], int top) {
        if (node->left) {
            code[top] = '0';
            print_codes(node->left, code, top + 1);
        }
        if (node->right) {
            code[top] = '1';
            print_codes(node->right, code, top + 1);
        }
        if (node->left == NULL && node->right == NULL) {
            printf("%c: %s\n", node->character, code);
        }
    }

    print_codes(huffman_tree_root, code, top);
}

/* Main function */
int main() {
    char input_string[] = "this is an example of huffman encoding";
    char* encoded_string;
    int input_length = strlen(input_string);
    int encoded_output_length;

    huffman_encoding(input_string, input_length, &encoded_string, &encoded_output_length);

    return 0;
}