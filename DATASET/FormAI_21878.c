//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 50 // Maximum number of bags that can be processed
#define MAX_TERMINALS 5 // Maximum number of terminals

// Baggage class
typedef struct {
    int id;
    int terminal;
} Baggage;

// Terminal class
typedef struct {
    int id;
    int processing_time;
    int current_baggage_id;
    int time_left;
    int num_processed;
} Terminal;

// Main function
int main() {
    srand(time(NULL)); // Initialize seed for random number generator
    
    // Initialize baggage and terminals
    Baggage baggage[MAX_BAGGAGE];
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        baggage[i].id = i+1;
        baggage[i].terminal = rand() % MAX_TERMINALS + 1;
    }
    Terminal terminals[MAX_TERMINALS];
    for (int i = 0; i < MAX_TERMINALS; i++) {
        terminals[i].id = i+1;
        terminals[i].processing_time = rand() % 5 + 1;
        terminals[i].current_baggage_id = 0;
        terminals[i].time_left = 0;
        terminals[i].num_processed = 0;
    }
    
    // Start processing bags
    int time = 1;
    int num_processed = 0;
    while (num_processed < MAX_BAGGAGE) {
        printf("Time %d\n", time);
        
        // Process next bag at each terminal
        for (int i = 0; i < MAX_TERMINALS; i++) {
            if (terminals[i].current_baggage_id == 0) { // If terminal is available
                for (int j = 0; j < MAX_BAGGAGE; j++) {
                    if (baggage[j].terminal == terminals[i].id) { // If there is a bag for this terminal
                        terminals[i].current_baggage_id = baggage[j].id;
                        terminals[i].time_left = terminals[i].processing_time;
                        printf("Terminal %d is now processing bag %d\n", i+1, baggage[j].id);
                        break;
                    }
                }
            } else { // If terminal is busy, decrement time left and process bag if time is up
                terminals[i].time_left--;
                if (terminals[i].time_left == 0) {
                    printf("Terminal %d has finished processing bag %d\n", i+1, terminals[i].current_baggage_id);
                    terminals[i].current_baggage_id = 0;
                    terminals[i].num_processed++;
                    num_processed++;
                }
            }
        }
        
        // Wait for one second before next iteration
        printf("\n");
        sleep(1);
        time++;
    }
    
    // Print final stats
    printf("All bags have been processed:\n");
    for (int i = 0; i < MAX_TERMINALS; i++) {
        printf("Terminal %d processed %d bags\n", i+1, terminals[i].num_processed);
    }
    
    return 0;
}