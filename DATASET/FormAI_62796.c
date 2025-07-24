//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_LUGGAGE_COUNT 50
#define MAX_BAGGAGE_BELT_SIZE 10

// struct to store luggage information
typedef struct {
    int id;
    int weight;
} luggage;

// initializes the luggage with random weight
void init_luggage(luggage* l, int i) {
    l->id = i;
    l->weight = rand() % 50 + 1; // random weight between 1 and 50 kgs
}

// simulates the process of loading and unloading the baggage
void simulate_baggage_handling() {
    // initialize random seed
    srand(time(NULL)); 

    // initialize variables
    luggage baggage[MAX_LUGGAGE_COUNT];
    int luggage_count = 0;
    bool is_baggage_belt_full = false;
    bool is_baggage_belt_empty = true;
    int current_luggage_index = 0;
    int total_weight_on_belt = 0;

    printf("Simulating airport baggage handling...\n\n");

    // continue until all luggage has been loaded and unloaded
    while ((luggage_count < MAX_LUGGAGE_COUNT) || (!is_baggage_belt_empty)) {

        // check if new luggage can be loaded
        if (!is_baggage_belt_full && luggage_count < MAX_LUGGAGE_COUNT) {
            luggage new_luggage;
            init_luggage(&new_luggage, luggage_count);
            printf("Loaded luggage with id %d and weight %d kgs on the belt.\n", new_luggage.id, new_luggage.weight);
            baggage[luggage_count] = new_luggage;
            luggage_count++;

            // check if baggage belt has reached maximum capacity
            if (luggage_count == MAX_BAGGAGE_BELT_SIZE) {
                is_baggage_belt_full = true;
                printf("Baggage belt is full.\n");
            }
        }

        // check if luggage can be unloaded
        if (!is_baggage_belt_empty && total_weight_on_belt == 0) {
            printf("Unloaded luggage with id %d from the belt.\n", baggage[current_luggage_index].id);
            current_luggage_index++;
            if (current_luggage_index == MAX_BAGGAGE_BELT_SIZE) {
                is_baggage_belt_empty = true;
                is_baggage_belt_full = false;
                current_luggage_index = 0;
                printf("Baggage belt is empty.\n");
            }
        }

        // add weight of newly loaded luggage to the belt
        if (!is_baggage_belt_empty && total_weight_on_belt < 1000 && current_luggage_index < MAX_BAGGAGE_BELT_SIZE) {
            total_weight_on_belt += baggage[current_luggage_index].weight;
            printf("Luggage with id %d and weight %d kgs is on the belt.\n", baggage[current_luggage_index].id, baggage[current_luggage_index].weight);
            current_luggage_index++;
            if (current_luggage_index == MAX_BAGGAGE_BELT_SIZE) {
                is_baggage_belt_full = true;
                is_baggage_belt_empty = false;
                current_luggage_index = 0;
                printf("Baggage belt is full.\n");
            }
        }

        // unload the luggage if weight on the belt exceeds the limit
        if (!is_baggage_belt_empty && total_weight_on_belt > 1000) {
            printf("Unloading luggage from the belt as weight limit exceeded.\n");
            while (current_luggage_index < MAX_BAGGAGE_BELT_SIZE) {
                printf("Unloaded luggage with id %d from the belt.\n", baggage[current_luggage_index].id);
                current_luggage_index++;
            }
            total_weight_on_belt = 0;
            is_baggage_belt_empty = true;
            is_baggage_belt_full = false;
            current_luggage_index = 0;
            printf("Baggage belt is empty.\n");
        }

        // random delay to simulate real-time process
        int delay = rand() % 5 + 1; // random delay between 1 and 5 seconds
        printf("\n");
        sleep(delay);
    }
    printf("\n\nBaggage handling simulation completed.\n");
}

int main() {
    simulate_baggage_handling();
    return 0;
}