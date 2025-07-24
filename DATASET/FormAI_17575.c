//FormAI DATASET v1.0 Category: Data structures visualization ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

// Define the data structure
typedef struct {
    int id;
    int value;
} Node;

// Function prototypes
void print_nodes(Node *nodes, int size);
void shuffle_nodes(Node *nodes, int size);
void bubble_sort(Node *nodes, int size);
void selection_sort(Node *nodes, int size);

int main() {
    // Create an array of nodes
    Node nodes[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        nodes[i].id = i;
        nodes[i].value = rand() % 100;
    }
    printf("Original array:\n");
    print_nodes(nodes, MAX_SIZE);

    // Shuffle the array
    srand(time(NULL));
    shuffle_nodes(nodes, MAX_SIZE);
    printf("\nShuffled array:\n");
    print_nodes(nodes, MAX_SIZE);

    // Sort the array using bubble sort
    bubble_sort(nodes, MAX_SIZE);
    printf("\nBubble sorted array:\n");
    print_nodes(nodes, MAX_SIZE);
    
    // Sort the array using selection sort
    shuffle_nodes(nodes, MAX_SIZE);
    selection_sort(nodes, MAX_SIZE);
    printf("\nSelection sorted array:\n");
    print_nodes(nodes, MAX_SIZE);

    return 0;
}

void print_nodes(Node *nodes, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d] %d ", nodes[i].id, nodes[i].value);
    }
    printf("\n");
}

void shuffle_nodes(Node *nodes, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Node temp = nodes[i];
        nodes[i] = nodes[j];
        nodes[j] = temp;
    }
}

void bubble_sort(Node *nodes, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (nodes[j].value > nodes[j + 1].value) {
                Node temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
        }
    }
}

void selection_sort(Node *nodes, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (nodes[j].value < nodes[min_index].value) {
                min_index = j;
            }
        }
        Node temp = nodes[i];
        nodes[i] = nodes[min_index];
        nodes[min_index] = temp;
    }
}