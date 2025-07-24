//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50

// Create structure node
struct node {
    char data;
    unsigned frequency;
    struct node *left, *right;
};

// Create a priority queue
struct priority_queue {
    unsigned size;
    unsigned capacity;
    struct node** array;
};

// Create a New Node
struct node* new_node(char data, unsigned frequency) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;

    return node;
}

// Create new priority queue, size of queue will be size
struct priority_queue* create_priority_queue(unsigned capacity) {
    struct priority_queue* priority_queue = (struct priority_queue*)malloc(sizeof(struct priority_queue));
    priority_queue->size = 0;
    priority_queue->capacity = capacity;
    priority_queue->array = (struct node**)malloc(priority_queue->capacity * sizeof(struct node*));
    return priority_queue;
}

// Swap two nodes
void swap_nodes(struct node** a, struct node** b) {
    struct node* temp = *a;
    *a = *b;
    *b = temp;
}

// Max heapify the queue
void max_heapify(struct priority_queue* queue, int index) {
    int maximum = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < queue->size && queue->array[left]->frequency > queue->array[maximum]->frequency) {
        maximum = left;
    }

    if (right < queue->size && queue->array[right]->frequency > queue->array[maximum]->frequency) {
        maximum = right;
    }

    if (maximum != index) {
        swap_nodes(&queue->array[maximum], &queue->array[index]);
        max_heapify(queue, maximum);
    }
}

// Check if queue is empty
int is_empty(struct priority_queue* queue) {
    return queue->size == 1;
}

// Extract Maximum node of queue
struct node* extract_maximum(struct priority_queue* queue) {
    struct node* node = queue->array[0];
    queue->array[0] = queue->array[queue->size - 1];

    --queue->size;
    max_heapify(queue, 0);

    return node;
}

// Insert node to priority queue
void insert_node(struct priority_queue* queue, struct node* node) {
    ++queue->size;
    int index = queue->size - 1;
    while (index && node->frequency > queue->array[(index - 1) / 2]->frequency) {
        queue->array[index] = queue->array[(index - 1) / 2];
        index = (index - 1) / 2;
    }

    queue->array[index] = node;
}

// Check if node is leaf
int is_leaf(struct node* node) {
    return !(node->left) && !(node->right);
}

// Create priority queue and insert all characters with frequency
struct priority_queue* create_queue(char data[], int frequency[], int size) {
    struct priority_queue* queue = create_priority_queue(size);

    for (int i = 0; i < size; ++i) {
        queue->array[i] = new_node(data[i], frequency[i]);
    }

    queue->size = size;

    for (int i = (queue->size - 1) / 2; i >= 0; --i) {
        max_heapify(queue, i);
    }

    return queue;
}

// Create Huffman tree
struct node* create_huffman_tree(char data[], int frequency[], int size) {
    struct node *left, *right, *top;

    struct priority_queue* queue = create_queue(data, frequency, size);

    while (!is_empty(queue)) {
        left = extract_maximum(queue);
        right = extract_maximum(queue);

        top = new_node('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insert_node(queue, top);
    }

    return extract_maximum(queue);
}

// Print codes of Huffman tree
void print_codes(struct node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }

    if (is_leaf(root)) {
        printf(" %c : ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Huffman coding main function
void huffman_coding(char data[], int frequency[], int size) {
    struct node* root = create_huffman_tree(data, frequency, size);
    int arr[MAX_TREE_HT], top = 0;

    print_codes(root, arr, top);
}

// Main Function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    huffman_coding(data, frequency, size);

    return 0;
}