//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int alienCount = rand() % 1001;
    int probability = alienCount/10;

    if (probability > 0)
        printf("There is a %d%% chance of an alien invasion!\n", probability);
    else
        printf("There is no chance of an alien invasion today.\n");

    return 0;
}