//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 1000
#define MAX_SORTERS 10

// Baggage Struct
typedef struct {
    int id;
    int weight;
} Baggage;

// Sorter Struct
typedef struct {
    int id;
    int capacity;
    int loaded_weight;
} Sorter;

// Function Prototypes
void generate_baggage(Baggage*, int);
void initialize_sorters(Sorter*, int);
void print_baggage(Baggage*, int);
void print_sorters(Sorter*, int);
void sort_baggage(Baggage*, int, Sorter*, int);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create and generate the baggage
    Baggage all_baggage[MAX_BAGGAGE];
    int total_baggage = rand() % MAX_BAGGAGE + 1;
    generate_baggage(all_baggage, total_baggage);

    // Create and initialize the sorters
    int total_sorters = rand() % MAX_SORTERS + 1;
    Sorter all_sorters[MAX_SORTERS];
    initialize_sorters(all_sorters, total_sorters);

    // Print the initial state of the program
    printf("== Initial State ==\n");
    printf("Total baggage: %d\n", total_baggage);
    print_baggage(all_baggage, total_baggage);
    printf("\n");
    printf("Total sorters: %d\n", total_sorters);
    print_sorters(all_sorters, total_sorters);
    printf("\n");

    // Sort the baggage based on weight
    sort_baggage(all_baggage, total_baggage, all_sorters, total_sorters);

    // Print the final state of the program
    printf("== Final State ==\n");
    printf("Total baggage: %d\n", total_baggage);
    print_baggage(all_baggage, total_baggage);
    printf("\n");
    printf("Total sorters: %d\n", total_sorters);
    print_sorters(all_sorters, total_sorters);
    printf("\n");

    return 0;
}

// Generates random baggage with random weights
void generate_baggage(Baggage* baggage, int total_baggage) {
    for (int i = 0; i < total_baggage; i++) {
        baggage[i].id = i + 1;
        baggage[i].weight = rand() % 100 + 1;
    }
}

// Initializes the sorter capacities
void initialize_sorters(Sorter* sorters, int total_sorters) {
    for (int i = 0; i < total_sorters; i++) {
        sorters[i].id = i + 1;
        sorters[i].capacity = rand() % 100 + 1;
        sorters[i].loaded_weight = 0;
    }
}

// Prints out the baggage and their weights
void print_baggage(Baggage* baggage, int total_baggage) {
    printf("Baggage:\n");
    for (int i = 0; i < total_baggage; i++) {
        printf("ID: %d | Weight: %d\n", baggage[i].id, baggage[i].weight);
    }
}

// Prints out the sorter ids and their weights
void print_sorters(Sorter* sorters, int total_sorters) {
    printf("Sorters:\n");
    for (int i = 0; i < total_sorters; i++) {
        printf("ID: %d | Loaded Weight: %d / %d\n", sorters[i].id, sorters[i].loaded_weight, sorters[i].capacity);
    }
}

// Sorts baggage based on weight and assigns them to sorters
void sort_baggage(Baggage* baggage, int total_baggage, Sorter* sorters, int total_sorters) {
    for (int i = 0; i < total_baggage; i++) {
        int max_weight = 0;
        int max_index = 0;
        for (int j = 0; j < total_sorters; j++) {
            if (sorters[j].loaded_weight + baggage[i].weight <= sorters[j].capacity) {
                if (sorters[j].loaded_weight + baggage[i].weight >= max_weight) {
                    max_weight = sorters[j].loaded_weight + baggage[i].weight;
                    max_index = j;
                }
            }
        }
        sorters[max_index].loaded_weight += baggage[i].weight;
    }
}