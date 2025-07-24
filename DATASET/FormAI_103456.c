//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of nodes
#define NUM_NODES 4

// Define the structure for each node
typedef struct {
    int node_id;
    int* data;
    int data_size;
    int checksum;
} Node;

// Define the structure for the global checksum
typedef struct {
    int checksum;
    pthread_mutex_t mutex;
} GlobalChecksum;

// Function to calculate the checksum for a given node
void* calculate_checksum(void* arg) {
    Node* node = (Node*) arg;
    int checksum = 0;
    for (int i = 0; i < node->data_size; i++) {
        checksum += node->data[i];
    }
    node->checksum = checksum;
    printf("Node %d: Calculated checksum = %d\n", node->node_id, node->checksum);
    pthread_exit(NULL);
}

// Function to calculate the global checksum
void calculate_global_checksum(Node* nodes, GlobalChecksum* global_checksum) {
    pthread_mutex_lock(&global_checksum->mutex);
    global_checksum->checksum = 0;
    for (int i = 0; i < NUM_NODES; i++) {
        global_checksum->checksum += nodes[i].checksum;
    }
    printf("Global: Calculated checksum = %d\n", global_checksum->checksum);
    pthread_mutex_unlock(&global_checksum->mutex);
}

int main(void) {
    // Create an array of nodes
    Node nodes[NUM_NODES] = {
        {0, (int[]) {1, 2, 3}, 3, 0},
        {1, (int[]) {4, 5, 6}, 3, 0},
        {2, (int[]) {7, 8, 9}, 3, 0},
        {3, (int[]) {10, 11, 12}, 3, 0}
    };

    // Initialize the global checksum
    GlobalChecksum global_checksum;
    global_checksum.checksum = 0;
    pthread_mutex_init(&global_checksum.mutex, NULL);

    // Create threads to calculate the checksum for each node
    pthread_t threads[NUM_NODES];
    for (int i = 0; i < NUM_NODES; i++) {
        pthread_create(&threads[i], NULL, calculate_checksum, &nodes[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_NODES; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculate the global checksum
    calculate_global_checksum(nodes, &global_checksum);

    // Destroy the mutex
    pthread_mutex_destroy(&global_checksum.mutex);

    return 0;
}