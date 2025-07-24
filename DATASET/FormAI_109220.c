//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int invadeProbability = rand() % 101;

    if (invadeProbability > 50) {
        printf("ALERT: Alien invasion detected!\n");
        printf("Probability of invasion: %d%%\n", invadeProbability);
        printf("Initiating emergency protocols!\n");
    } else {
        printf("No signs of alien invasion detected.\n");
        printf("Probability of invasion: %d%%\n", invadeProbability);
        printf("Carry on with normal operations.\n");
    }

    return 0;
}