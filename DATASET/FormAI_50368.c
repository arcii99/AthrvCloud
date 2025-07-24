//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_NODES 256
#define MAX_THREADS 16

int graph[MAX_NODES][MAX_NODES]; // adjacency matrix representing the network graph
int nodes[MAX_NODES]; // array storing the unique node IDs in the network
int num_nodes = 0; // total number of nodes in the network

// function to add a node to the network
void add_node(int node_id) {
    // check if node already exists in the network
    for(int i=0; i<num_nodes; i++) {
        if(nodes[i] == node_id) {
            return;
        }
    }
    // add node to the network
    nodes[num_nodes++] = node_id;
}

// function to add a link between two nodes in the network
void add_link(int node1, int node2) {
    // add nodes to the network if they don't already exist
    add_node(node1);
    add_node(node2);
    // add link to the adjacency matrix
    graph[node1][node2] = 1;
    graph[node2][node1] = 1;
}

// function to print the network topology
void print_topology() {
    // print the node IDs
    printf("Node IDs: ");
    for(int i=0; i<num_nodes; i++) {
        printf("%d ", nodes[i]);
    }
    printf("\n");

    // print the adjacency matrix
    printf("Adjacency Matrix:\n");
    for(int i=0; i<num_nodes; i++) {
        for(int j=0; j<num_nodes; j++) {
            printf("%d ", graph[nodes[i]][nodes[j]]);
        }
        printf("\n");
    }
}

// function executed by each thread to add links to the network
void* add_links(void* arg) {
    int* input = (int*) arg;
    int start = input[0];
    int end = input[1];

    // randomly generate links between nodes in the specified range
    for(int i=start; i<=end; i++) {
        for(int j=i+1; j<=num_nodes; j++) {
            double rand_val = (double)rand() / (double)RAND_MAX; // generate a random value between 0 and 1
            if(rand_val < 0.2) { // add a link between nodes with a 20% probability
                add_link(nodes[i], nodes[j]);
            }
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    // generate a random seed for the random number generator
    srand((unsigned int)time(NULL));

    // add some initial links to the network
    add_link(0, 1);
    add_link(0, 2);
    add_link(1, 2);
    add_link(2, 3);
    add_link(2, 4);
    add_link(3, 4);
    add_link(4, 5);

    // print the initial network topology
    printf("Initial Network Topology:\n");
    print_topology();

    // divide nodes into equal partitions for each thread
    int nodes_per_thread = num_nodes / MAX_THREADS;
    int input[MAX_THREADS][2];
    for(int i=0; i<MAX_THREADS; i++) {
        input[i][0] = i * nodes_per_thread;
        if(i == MAX_THREADS-1) {
            input[i][1] = num_nodes-1;
        } else {
            input[i][1] = (i+1) * nodes_per_thread - 1;
        }
    }

    // create threads and execute the add_links function for each thread
    pthread_t threads[MAX_THREADS];
    for(int i=0; i<MAX_THREADS; i++) {
        if(pthread_create(&threads[i], NULL, add_links, (void*)input[i])) {
            printf("Error creating thread!\n");
            return 1;
        }
    }

    // wait for all threads to finish execution
    for(int i=0; i<MAX_THREADS; i++) {
        if(pthread_join(threads[i], NULL)) {
            printf("Error joining thread!\n");
            return 1;
        }
    }

    // print the final network topology
    printf("Final Network Topology:\n");
    print_topology();

    return 0;
}