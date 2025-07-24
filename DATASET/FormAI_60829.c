//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random number generator with current time
    int invasionProbability = rand() % 101; // generate a random number between 0 to 100 as invasion probability
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("-------------------------------------\n");
    printf("Invasion Probability: %d%%\n", invasionProbability);
    if (invasionProbability >= 0 && invasionProbability <= 20) {
        printf("The chance of an alien invasion is very low.\n");
    } else if (invasionProbability >= 21 && invasionProbability <= 50) {
        printf("There is a moderate chance of an alien invasion.\n");
    } else if (invasionProbability >= 51 && invasionProbability <= 80) {
        printf("The chance of an alien invasion is high.\n");
    } else if (invasionProbability >= 81 && invasionProbability <= 100) {
        printf("There is a very high chance of an alien invasion.\n");
    }
    return 0;
}