//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define variables
int MAX_CAPACITY = 100;
int MAX_TIME = 10;
int bags_processed = 0;
int bags_total = 0;

// Define function to simulate baggage handling
void baggage_handling(int time) {
    int capacity = rand() % MAX_CAPACITY + 1;
    printf("Processing %d bags...\n", capacity);
    for (int i = 0; i < capacity; i++) {
        printf("Handling bag %d\n", i+1);
        // Simulate handling time
        int handle_time = rand() % time + 1;
        sleep(handle_time);
        printf("Bag %d processed in %d seconds\n", i+1, handle_time);
        bags_processed++;
    }
    printf("All bags processed\n");
}

int main() {
    // Seed random number generator
    srand(time(0));

    // Get number of bags to handle
    printf("How many bags are there to handle? ");
    scanf("%d", &bags_total);

    // Loop through handling until all bags are processed
    while (bags_processed < bags_total) {
        int time = rand() % MAX_TIME + 1;
        printf("Next handler available in %d seconds\n", time);
        sleep(time);
        baggage_handling(time);
    }

    // Print final report
    printf("Total bags processed: %d\n", bags_processed);

    return 0;
}