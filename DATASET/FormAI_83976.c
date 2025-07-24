//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Seed the random number generator

    int alienTechLevel = rand() % 11; // Generate random number between 0 and 10
    int humanTechLevel = rand() % 11; // Generate random number between 0 and 10

    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");
    printf("Alien Tech Level: %d\n", alienTechLevel);
    printf("Human Tech Level: %d\n\n", humanTechLevel);

    float invasionProbability = (float)(10 - humanTechLevel + alienTechLevel) / 20 * 100;

    printf("INVASION PROBABILITY: %.2f%%\n\n", invasionProbability);

    if (invasionProbability > 50) {
        printf("RUN FOR YOUR LIFE! An alien invasion is highly likely!\n");
    } else if (invasionProbability > 20) {
        printf("STAY ALERT! There is a moderate chance of an alien invasion!\n");
    } else {
        printf("RELAX! There is a low probability of an alien invasion!\n");
    }

    return 0;
}