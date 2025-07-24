//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: thoughtful
// C program to simulate an airport baggage handling system

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 100      // Maximum number of baggage allowed in the system
#define MAX_COUNTERS 10      // Maximum number of counters in the airport
#define MAX_TIME 10          // Maximum time for baggage processing
#define MIN_TIME 5           // Minimum time for baggage processing

struct Baggage {
    int id;                   // Baggage ID
    int time;                 // Processing time for the baggage
    int status;               // Status of the baggage (0 = unprocessed, 1 = done)
};

struct Counter {
    int id;                  // Counter ID
    int status;              // Status of the counter (0 = free, 1 = busy)
};

int main() {
    struct Baggage baggage_list[MAX_BAGGAGE];         // Array to store the baggage information
    struct Counter counter_list[MAX_COUNTERS];        // Array to store the counter information
    int baggage_count = 0;        // Total number of baggage
    int counter_count = 0;        // Total number of counters
    int total_time = 0;           // Total processing time for all baggage

    srand(time(NULL));            // Seed the random number generator with the current time

    // Initialize the counters
    for (int i = 0; i < MAX_COUNTERS; i++) {
        counter_list[i].id = i+1;
        counter_list[i].status = 0;
    }

    // Generate random baggage and assign them to counters
    while (1) {
        struct Baggage new_baggage;
        new_baggage.id = ++baggage_count;
        new_baggage.time = rand() % (MAX_TIME - MIN_TIME) + MIN_TIME;
        new_baggage.status = 0;

        // Check if any counter is free
        int free_counter_index = -1;
        for (int i = 0; i < MAX_COUNTERS; i++) {
            if (counter_list[i].status == 0) {
                free_counter_index = i;
                break;
            }
        }

        // If a free counter is available, assign baggage to that counter
        if (free_counter_index != -1) {
            printf("Assigning Baggage %d to Counter %d\n", new_baggage.id, counter_list[free_counter_index].id);
            counter_list[free_counter_index].status = 1;     // Mark the counter as busy
            new_baggage.status = 1;                          // Mark the baggage as processed
            total_time += new_baggage.time;                  // Add processing time to the total time
        }

        // Add the new baggage to the baggage list
        baggage_list[baggage_count-1] = new_baggage;

        // Check if all baggage have been processed
        int all_done = 1;
        for (int i = 0; i < baggage_count; i++) {
            if (baggage_list[i].status == 0) {
                all_done = 0;
                break;
            }
        }

        if (all_done) {
            break;
        }

        // Wait for some time to simulate real-time baggage arrival
        sleep(rand() % 5);
    }

    printf("\n===== End of Simulation =====\n");
    printf("Total Processing Time: %d minutes\n", total_time);
    printf("Average Processing Time per Baggage: %.2f minutes\n", (float)total_time/(float)baggage_count);

    return 0;
}