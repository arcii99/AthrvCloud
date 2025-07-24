//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_BAGS 50
#define NUM_CONVEYORS 5

// Conveyor struct
typedef struct {
    int id;
    int capacity;
    int num_bags_on_conveyor;
} conveyor_t;

// Bag struct
typedef struct {
    int id;
    bool is_checked_in;
    int conveyor_id;
} bag_t;

// Function prototypes
void initialize_conveyors(conveyor_t* conveyors);
void add_bag_to_conveyor(conveyor_t* conveyors, bag_t* bags);
bool check_in_bag(bag_t* bags);
void print_conveyors(conveyor_t* conveyors);

int main() {
    srand(time(NULL)); // Seed random number generator
    
    conveyor_t conveyors[NUM_CONVEYORS];
    initialize_conveyors(conveyors);
    
    bag_t bags[NUM_BAGS];
    for (int i = 0; i < NUM_BAGS; i++) {
        bags[i].id = i;
        bags[i].is_checked_in = false;
        bags[i].conveyor_id = -1;
    }
    
    int bags_checked_in = 0;
    
    while (bags_checked_in < NUM_BAGS) {
        // Check in a bag
        bool bag_checked_in = check_in_bag(bags);
        if (bag_checked_in) {
            bags_checked_in++;
        }
        
        // Add bags to conveyors
        for (int i = 0; i < NUM_BAGS; i++) {
            if (bags[i].is_checked_in && bags[i].conveyor_id == -1) {
                add_bag_to_conveyor(conveyors, &bags[i]);
            }
        }
        
        // Print conveyor status
        print_conveyors(conveyors);
    }
    
    printf("All bags have been checked in!\n");
    
    return 0;
}

void initialize_conveyors(conveyor_t* conveyors) {
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        conveyors[i].id = i;
        conveyors[i].capacity = rand() % 6 + 5; // Random capacity between 5 and 10
        conveyors[i].num_bags_on_conveyor = 0;
    }
}

void add_bag_to_conveyor(conveyor_t* conveyors, bag_t* bag) {
    int conveyor_id = rand() % NUM_CONVEYORS;
    if (conveyors[conveyor_id].num_bags_on_conveyor < conveyors[conveyor_id].capacity) {
        bag->conveyor_id = conveyor_id;
        conveyors[conveyor_id].num_bags_on_conveyor++;
    }
}

bool check_in_bag(bag_t* bags) {
    int bag_id = rand() % NUM_BAGS;
    if (!bags[bag_id].is_checked_in) {
        bags[bag_id].is_checked_in = true;
        return true;
    }
    return false;
}

void print_conveyors(conveyor_t* conveyors) {
    printf("Conveyor Status:\n");
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        printf("Conveyor %d: Capacity %d, Bags on Conveyor %d\n", conveyors[i].id, conveyors[i].capacity, conveyors[i].num_bags_on_conveyor);
    }
    printf("\n");
}