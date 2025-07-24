//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50
#define MAX_WAIT 10
#define PROCESS_TIME 3

struct baggage {
    int id;
    int process_time;
    int arrival_time;
} bags[MAX_BAGS];

int main() {
    int i, j;
    int total_bags;
    int wait_time;
    int processed_bags = 0;
    srand(time(NULL));

    // Generate random baggage arrival time and processing time
    for(i=0; i<MAX_BAGS; i++) {
        bags[i].id = i+1;
        bags[i].arrival_time = rand()%MAX_WAIT + 1;
        bags[i].process_time = PROCESS_TIME;
    }

    // Simulate the baggage handling system
    for(i=1; i<=MAX_WAIT; i++) {
        printf("--- Processing time step %d ---\n", i);
        for(j=0; j<MAX_BAGS; j++) {
            if(bags[j].arrival_time == i) {
                printf("Bag %d arrives at step %d.\n", bags[j].id, i);
            }
        }
        for(j=0; j<MAX_BAGS; j++) {
            if(bags[j].process_time > 0) {
                bags[j].process_time--;
            } else if(bags[j].process_time == 0) {
                printf("Bag %d processed at step %d.\n", bags[j].id, i);
                processed_bags++;
            }
        }
        printf("--------------------------\n");
    }

    // Calculate average wait time
    wait_time = MAX_WAIT / processed_bags;

    printf("Total bags processed: %d\n", processed_bags);
    printf("Average wait time: %d\n", wait_time);

    return 0;
}