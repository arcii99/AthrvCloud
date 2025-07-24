//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BAGS 20
#define NUM_CONVEYORS 4

struct bag {
    int id;
    int weight;
    int destination;
};

typedef struct bag Bag;

typedef struct {
    int bags_on_conveyor;
    Bag *conveyor_bags[NUM_BAGS];
} Conveyor;

Conveyor conveyors[NUM_CONVEYORS];

void add_bag_to_conveyor(Bag *bag_to_add, int conveyor_index) {
    if (conveyors[conveyor_index].bags_on_conveyor == NUM_BAGS) {
        printf("Conveyor %d is full.\n", conveyor_index);
        return;
    }
    conveyors[conveyor_index].conveyor_bags[conveyors[conveyor_index].bags_on_conveyor++] = bag_to_add;
}

int main(void) {
    // Generate random bags
    srand(time(NULL));
    Bag bags[NUM_BAGS];
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].id = i;
        bags[i].weight = rand() % 50 + 1;
        bags[i].destination = rand() % 4;
        add_bag_to_conveyor(&bags[i], bags[i].destination);
    }

    // Print conveyors
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        printf("Conveyor %d:\n", i);
        for (int j = 0; j < conveyors[i].bags_on_conveyor; j++) {
            printf("Bag %d: Weight = %d, Destination = %d\n", conveyors[i].conveyor_bags[j]->id,
                   conveyors[i].conveyor_bags[j]->weight, conveyors[i].conveyor_bags[j]->destination);
        }
    }

    return 0;
}