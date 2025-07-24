//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define TOTAL_BAGS 500
#define TOTAL_CONVEYORS 5
#define BAG_WEIGHT_LIMIT 30.0

typedef struct {
    int id;
    float weight;
    bool loaded;
} Bag;

typedef struct {
    int id;
    bool occupied;
} Conveyor;

int main() {
    Bag bags[TOTAL_BAGS];
    Conveyor conveyors[TOTAL_CONVEYORS];
    int total_bags_loaded = 0;
    int i;

    // Initialize bags
    for(i = 0; i < TOTAL_BAGS; i++) {
        bags[i].id = i + 1;
        bags[i].weight = (float)(random() % 50) / 2.0;
        bags[i].loaded = false;
    }

    // Initialize conveyors
    for(i = 0; i < TOTAL_CONVEYORS; i++) {
        conveyors[i].id = i + 1;
        conveyors[i].occupied = false;
    }

    // Start baggage handling simulation
    printf("Starting baggage handling simulation...\n");
    while(total_bags_loaded < TOTAL_BAGS) {
        // Load bags onto conveyors
        for(i = 0; i < TOTAL_BAGS; i++) {
            if(!bags[i].loaded && bags[i].weight <= BAG_WEIGHT_LIMIT) {
                int conveyor_index = random() % TOTAL_CONVEYORS;
                if(!conveyors[conveyor_index].occupied) {
                    bags[i].loaded = true;
                    conveyors[conveyor_index].occupied = true;
                    total_bags_loaded++;
                    printf("Bag %d loaded onto Conveyor %d\n", bags[i].id, conveyors[conveyor_index].id);
                }
            }
        }

        // Move bags on occupied conveyors
        for(i = 0; i < TOTAL_CONVEYORS; i++) {
            if(conveyors[i].occupied) {
                // Move bag for 1 second
                sleep(1);
                conveyors[i].occupied = false;
                printf("Bag moved on Conveyor %d\n", conveyors[i].id);
            }
        }
    }

    printf("All bags have been loaded.\n");
    return 0;
}