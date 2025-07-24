//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_EDGES 1000

int adj_list[MAX_NODES][MAX_EDGES];
int num_edges[MAX_NODES];

// Function to add an edge to the adjacency list
void addEdge(int u, int v) {
    adj_list[u][num_edges[u]++] = v;
}

// Function to simulate the circuit and print the output
void simulate(int input[], int num_inputs) {
    int output[num_inputs];

    for (int i = 0; i < num_inputs; i++) {
        int current_state[MAX_NODES] = {0};
        current_state[0] = input[i];

        for (int j = 0; j < MAX_NODES; j++) {
            for (int k = 0; k < num_edges[j]; k++) {
                int neighbor = adj_list[j][k];

                if (current_state[j] == 1) {
                    current_state[neighbor] = !current_state[neighbor];
                }
            }
        }

        // The output is the state of the final node
        output[i] = current_state[MAX_NODES - 1];
    }

    printf("Input: ");
    for (int i = 0; i < num_inputs; i++) {
        printf("%d ", input[i]);
    }

    printf("\nOutput: ");
    for (int i = 0; i < num_inputs; i++) {
        printf("%d ", output[i]);
    }

    printf("\n");
}

int main() {
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);

    int input[] = {0, 1, 0, 1};
    int num_inputs = sizeof(input) / sizeof(input[0]);

    simulate(input, num_inputs);

    return 0;
}