//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define constants */
#define MAX_BAGGAGE_WEIGHT 50
#define MAX_FLIGHTS 10
#define MAX_BAGGAGE_PER_FLIGHT 100
#define BELT_SPEED 5

/* Define struct for baggage */
typedef struct {
    int weight;
    int flight;
} Baggage;

/* Define helper function for random number generation */
int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    /* Seed random number generator */
    srand(time(NULL));
    
    /* Initialize baggage array */
    Baggage baggage[MAX_FLIGHTS * MAX_BAGGAGE_PER_FLIGHT];
    int total_baggage = 0;

    /* Generate random baggage */
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        int baggage_count = random_int(1, MAX_BAGGAGE_PER_FLIGHT);
        for (int j = 0; j < baggage_count; j++) {
            baggage[total_baggage].weight = random_int(1, MAX_BAGGAGE_WEIGHT);
            baggage[total_baggage].flight = i + 1;
            total_baggage++;
        }
    }

    /* Sort the baggage by flight number (using bubble sort) */
    for (int i = 0; i < total_baggage - 1; i++) {
        for (int j = 0; j < total_baggage - 1 - i; j++) {
            if (baggage[j].flight > baggage[j + 1].flight) {
                /* Swap the two baggage items */
                Baggage temp = baggage[j];
                baggage[j] = baggage[j + 1];
                baggage[j + 1] = temp;
            }
        }
    }

    /* Simulate the baggage handling process */
    int current_flight = 1;
    int current_baggage_index = 0;
    int baggage_on_belt = 0;
    int baggage_handled = 0;
    int total_time = 0;

    while (baggage_handled < total_baggage) {
        /* Check if we need to load more baggage on the belt */
        if (baggage_on_belt == 0 && current_baggage_index < total_baggage && baggage[current_baggage_index].flight == current_flight) {
            baggage_on_belt++;
            current_baggage_index++;
        }

        /* Run the belt for a minute */
        baggage_on_belt -= BELT_SPEED;
        if (baggage_on_belt < 0) {
            baggage_on_belt = 0;
        }

        /* Check if any baggage has reached the end of the belt */
        if (baggage_on_belt == 0) {
            printf("Baggage for flight %d has reached the end of the belt.\n", current_flight);
            current_flight++;
            baggage_handled += BELT_SPEED;
            total_time += BELT_SPEED;
        } else {
            baggage_handled += BELT_SPEED - baggage_on_belt;
            total_time += BELT_SPEED - baggage_on_belt;
        }
    }

    /* Print the total time it took to handle all baggage */
    printf("It took %d minutes to handle all baggage.\n", total_time);

    return 0;
}