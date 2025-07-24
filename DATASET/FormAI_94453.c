//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BAGS 100 // define the total number of bags
#define NUM_CONVEYORS 10 // define the total number of conveyors
#define MAX_WEIGHT 50 // define the maximum weight limit of bags

typedef struct Bag { // create a Bag struct
    int id;
    float weight;
    char destination[3];
} Bag;

typedef struct Conveyor { // create a Conveyor struct
    int id;
    int max_capacity;
    int current_capacity;
    Bag* bags[NUM_BAGS];
} Conveyor;

int main() { // main function
    int i, j;
    int total_bags = 0;
    int max_capacity[NUM_CONVEYORS] = {20, 20, 30, 30, 40, 40, 50, 50, 60, 60}; // set the max capacity for each conveyor
    Conveyor conveyors[NUM_CONVEYORS]; // create an array of conveyors

    // initialize the conveyors with their respective ids and max capacities
    for (i = 0; i < NUM_CONVEYORS; i++) {
        conveyors[i].id = i+1;
        conveyors[i].max_capacity = max_capacity[i];
        conveyors[i].current_capacity = 0;

        // initialize all the bags in this conveyor to NULL
        for (j = 0; j < NUM_BAGS; j++) {
            conveyors[i].bags[j] = NULL;
        }
    }

    // generate random bags and send them to their respective conveyors
    for (i = 0; i < NUM_BAGS; i++) {
        Bag* new_bag = (Bag*) malloc(sizeof(Bag)); // allocate memory for the new bag
        new_bag->id = i+1;
        new_bag->weight = (float) rand() / (float) (RAND_MAX/MAX_WEIGHT); // generate a random weight between 0 and MAX_WEIGHT
        int dest = rand() % NUM_CONVEYORS; // randomly assign a destination conveyor for the bag
        sprintf(new_bag->destination, "%d", dest+1);

        // add the bag to its destination conveyor if there is enough space
        if (conveyors[dest].current_capacity < conveyors[dest].max_capacity) {
            conveyors[dest].bags[conveyors[dest].current_capacity] = new_bag;
            conveyors[dest].current_capacity++;
            total_bags++;
        }
        else {
            printf("No more space in conveyor %d for bag %d\n", dest+1, new_bag->id);
            free(new_bag); // free the memory if there is no space
        }
    }

    // print the total number of bags and the bags in each conveyor
    printf("Total number of bags generated: %d\n", total_bags);
    for (i = 0; i < NUM_CONVEYORS; i++) {
        printf("Conveyor %d:\n", conveyors[i].id);
        printf("Max capacity: %d\n", conveyors[i].max_capacity);
        printf("Current capacity: %d\n", conveyors[i].current_capacity);
        printf("Bags: ");
        for (j = 0; j < conveyors[i].current_capacity; j++) {
            printf("%d ", conveyors[i].bags[j]->id);
        }
        printf("\n\n");
    }

    // free the memory allocated for the bags
    for (i = 0; i < NUM_CONVEYORS; i++) {
        for (j = 0; j < NUM_BAGS; j++) {
            if (conveyors[i].bags[j] != NULL) {
                free(conveyors[i].bags[j]);
            }
        }
    }

    return 0;
}