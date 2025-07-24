//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    // setting the seed for rand() to current time for random values

    float probability = 0.0;
    int aliens_detected = 0;
    int total_time = 0;
    int i;

    printf("Welcome to the Alien Invasion Probability Calculator\n\n");

    printf("Enter the probability (in %%) of an alien invasion: ");
    scanf("%f", &probability);

    printf("Enter the number of times you want to run the simulation: ");
    scanf("%d", &total_time);

    int invasion_count = 0;

    for (i = 0; i < total_time; i++) {
        int rand_num = rand() % 100;

        // checking if rand_num is less than probability
        // if yes, then alien invasion detected
        if (rand_num < probability) {
            invasion_count++;
        }
    }

    printf("\n\nResults:\n");
    printf("Total number of times simulation run: %d\n", total_time);
    printf("Number of times alien invasion detected: %d\n", invasion_count);
    printf("Probability of an alien invasion: %.2f%%\n", probability);

    return 0;
}