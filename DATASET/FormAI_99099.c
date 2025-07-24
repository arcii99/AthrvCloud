//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    float invasionProbability = (rand() % 100 + 1) / 100.0; // Generates a random probability between 0 and 1
    printf("Alien invasion probability: %.2f\n", invasionProbability);
    if (invasionProbability >= 0.5) {
        printf("The chance of alien invasion is high! Take precautions.\n");
    } else if (invasionProbability >= 0.25) {
        printf("The chance of alien invasion is moderate. Keep an eye out.\n");
    } else {
        printf("The chance of alien invasion is low. No need to worry.\n");
    }
    return 0;
}