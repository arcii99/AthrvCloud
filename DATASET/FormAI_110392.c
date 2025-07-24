//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int weight;
    char destination[50];
} Baggage;

typedef struct {
    int id;
    int capacity;
    int current_weight;
} Bin;

typedef struct {
    int id;
    int max_bins;
    Bin *bins;
} Conveyor;

int main() {
    srand(time(NULL));

    int num_bags = 100;
    Baggage bags[num_bags];
    for (int i = 0; i < num_bags; i++) {
        bags[i].id = i+1;
        bags[i].weight = rand() % 50 + 10;
        sprintf(bags[i].destination, "Destination %d", rand() % 5 + 1);
    }

    int num_bins = 10, max_capacity = 100;
    Bin bins[num_bins];
    for (int i = 0; i < num_bins; i++) {
        bins[i].id = i+1;
        bins[i].capacity = max_capacity;
        bins[i].current_weight = 0;
    }

    int num_conveyors = 3, max_bins_per_conveyor = 5;
    Conveyor conveyors[num_conveyors];
    for (int i = 0; i < num_conveyors; i++) {
        conveyors[i].id = i+1;
        conveyors[i].max_bins = max_bins_per_conveyor;
        conveyors[i].bins = (Bin *) malloc(sizeof(Bin) * max_bins_per_conveyor);
        for (int j = 0; j < max_bins_per_conveyor; j++) {
            conveyors[i].bins[j] = bins[rand() % num_bins];
        }
    }

    for (int i = 0; i < num_bags; i++) {
        Baggage bag = bags[i];
        Bin *bin = NULL;
        for (int j = 0; j < num_conveyors; j++) {
            Conveyor conveyor = conveyors[j];
            for (int k = 0; k < conveyor.max_bins; k++) {
                Bin current_bin = conveyor.bins[k];
                if (current_bin.current_weight + bag.weight <= current_bin.capacity) {
                    bin = &current_bin;
                    break;
                }
            }
            if (bin != NULL) {
                printf("Baggage %d loaded onto Conveyor %d, Bin %d\n", bag.id, conveyor.id, bin->id);
                bin->current_weight += bag.weight;
                break;
            }
        }
        if (bin == NULL) {
            printf("Baggage %d was not loaded onto any Conveyor due to lack of space in all bins\n", bag.id);
        }
    }

    for (int i = 0; i < num_conveyors; i++) {
        free(conveyors[i].bins);
    }

    return 0;
}