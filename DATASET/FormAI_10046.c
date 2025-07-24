//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool alienInvasion(float probability) {
    float random = ((float)rand()/(float)(RAND_MAX));
    if (random <= probability) {
        return true;
    }
    return false;
}

int main() {
    // Seed for random numbers
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the probability of an alien invasion (0.0 to 1.0): ");
    float probability;
    scanf("%f", &probability);

    if (probability < 0.0 || probability > 1.0) {
        printf("\nInvalid probability entered. Exiting program.\n");
        return 1;
    }

    printf("\nCalculating probability...\n\n");

    // Displaying progress
    for (int i = 0; i < 50; i++) {
        printf("#");
        fflush(stdout);
        // Wait for 100 milliseconds
        usleep(100000);
    }

    bool invasion = alienInvasion(probability);

    printf("\n\n");
    if (invasion) {
        printf("ALERT: An alien invasion is very likely to happen!\n");
    } else {
        printf("GOOD NEWS: An alien invasion is very unlikely to happen!\n");
    }

    return 0;
}