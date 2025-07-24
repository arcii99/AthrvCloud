//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGS 100        // the maximum number of bags to be processed
#define MAX_WEIGHT 23       // the maximum weight for a single bag
#define MAX_SORTERS 8       // the maximum number of sorting machines
#define MAX_WORKERS 16      // the maximum number of baggage handlers

typedef struct {
    int id;
    int weight;
    int sorter_id;
    int worker_id;
} Bag;

typedef struct {
    int id;
    int capacity;
    int occupancy;
} Sorter;

typedef struct {
    int id;
    int bags_processed;
    int bags_dropped;
} Worker;

int main() {
    // initialize the sorting machines
    Sorter sorters[MAX_SORTERS];
    for (int i = 0; i < MAX_SORTERS; i++) {
        sorters[i].id = i;
        sorters[i].capacity = 20;
        sorters[i].occupancy = 0;
    }

    // initialize the baggage handlers
    Worker workers[MAX_WORKERS];
    for (int i = 0; i < MAX_WORKERS; i++) {
        workers[i].id = i;
        workers[i].bags_processed = 0;
        workers[i].bags_dropped = 0;
    }

    // generate the bags randomly
    Bag bags[MAX_BAGS];
    int num_bags = rand() % MAX_BAGS + 1;
    for (int i = 0; i < num_bags; i++) {
        bags[i].id = i;
        bags[i].weight = rand() % MAX_WEIGHT + 1;
        bags[i].sorter_id = rand() % MAX_SORTERS;
        bags[i].worker_id = -1;
    }

    // process the bags
    for (int i = 0; i < num_bags; i++) {
        Bag bag = bags[i];
        Sorter *sorter = &sorters[bag.sorter_id];

        if (sorter->capacity > sorter->occupancy && bag.weight <= MAX_WEIGHT) {
            sorter->occupancy++;
            bag.worker_id = -1;
        } else {
            bag.worker_id = -2;
        }
    }

    // assign the bags to the baggage handlers
    for (int i = 0; i < num_bags; i++) {
        Bag bag = bags[i];

        if (bag.worker_id == -1) {
            int min_bags_dropped = workers[0].bags_dropped;
            int worker_idx = 0;

            for (int j = 1; j < MAX_WORKERS; j++) {
                if (workers[j].bags_dropped < min_bags_dropped) {
                    min_bags_dropped = workers[j].bags_dropped;
                    worker_idx = j;
                }
            }

            workers[worker_idx].bags_processed++;
            bag.worker_id = worker_idx;
        }
    }

    // print the results
    printf("SUMMARY\n");
    printf("-------\n");
    for (int i = 0; i < MAX_SORTERS; i++) {
        Sorter sorter = sorters[i];
        printf("Sorter #%d: Capacity=%d, Occupancy=%d\n", sorter.id, sorter.capacity, sorter.occupancy);
    }
    printf("\n");
    for (int i = 0; i < MAX_WORKERS; i++) {
        Worker worker = workers[i];
        printf("Worker #%d: Bags Processed=%d, Bags Dropped=%d\n", worker.id, worker.bags_processed, worker.bags_dropped);
    }

    return 0;
}