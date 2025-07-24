//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDays;
    float probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many days till the predicted invasion? ");
    scanf("%d", &numDays);

    // Calculate random probability between 0 and 1
    srand(time(NULL));
    probability = (float)rand()/(float)RAND_MAX;

    printf("The probability of an alien invasion in %d days is: %.2f\n", numDays, probability);

    if (probability >= 0.9) {
        printf("Alien invasion imminent! Seek shelter immediately.\n");
    } else if (probability >= 0.5) {
        printf("High risk of alien invasion. Take precautions.\n");
    } else if (probability >= 0.1) {
        printf("Low risk of alien invasion. Keep monitoring situation.\n");
    } else {
        printf("No risk of alien invasion detected.\n");
    }

    return 0;
}