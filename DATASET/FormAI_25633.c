//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Define variables
    int distance, fleet_size, tech_level, invasion_prob;

    // Get user input
    printf("Please enter the distance between Earth and the alien planet (in light years):\n");
    scanf("%d", &distance);

    printf("Please enter the size of the alien fleet:\n");
    scanf("%d", &fleet_size);

    printf("Please enter the state of technology on the alien planet (1 to 10):\n");
    scanf("%d", &tech_level);

    // Calculate invasion probability
    invasion_prob = (rand() % 101) + (distance * 2) - (fleet_size * tech_level);

    // Display results
    printf("\n\n-----------------------------\n");
    printf("   Alien Invasion Calculator  \n");
    printf("-----------------------------\n");
    printf("Distance:        %d light years\n", distance);
    printf("Fleet Size:      %d ships\n", fleet_size);
    printf("Tech Level:      %d\n", tech_level);
    printf("Invasion Prob:   %d%%\n", invasion_prob);

    // Check if invasion is likely
    if (invasion_prob >= 50) {
        printf("ALERT: Invasion is likely!\n");
    } else {
        printf("No immediate threat detected.\n");
    }

    return 0;
}