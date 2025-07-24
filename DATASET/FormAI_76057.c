//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define network quality levels
#define GOOD 80
#define MODERATE 60
#define POOR 40
#define BAD 20

// Define function to generate random numbers between 0-100
int random_num() {
    return rand() % 101;
}

int main() {
    srand(time(0));

    // Set up network monitoring loop
    int count = 0;
    while (count < 10) {

        // Generate random network quality score
        int quality_score = random_num();

        // Determine network quality level
        if (quality_score >= GOOD) {
            printf("Network Quality: GOOD - %d\n", quality_score);
        } else if (quality_score >= MODERATE) {
            printf("Network Quality: MODERATE - %d\n", quality_score);
        } else if (quality_score >= POOR) {
            printf("Network Quality: POOR - %d\n", quality_score);
        } else {
            printf("Network Quality: BAD - %d\n", quality_score);
        }

        // Sleep for a random amount of time between 1-5 seconds
        int sleep_time = (rand() % 5) + 1;
        printf("Sleeping for %d seconds...\n", sleep_time);
        sleep(sleep_time);

        count++;
    }

    return 0;
}