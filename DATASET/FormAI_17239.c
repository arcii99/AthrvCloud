//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0)); // seeding the random number generator with current time

    float invasionProb = 0.0;

    int numElevators = rand() % 10 + 1; // generating a random number between 1 and 10
    int numWarriors = rand() % 1000 + 1; // generating a random number between 1 and 1000
    int numShips = rand() % 50 + 1; // generating a random number between 1 and 50

    // calculating the invasion probability based on the randomly generated numbers
    invasionProb = (numElevators * numWarriors * numShips) / (5000.0);

    printf("Based on our calculations, the probability of an alien invasion is: %.2f%%\n", invasionProb*100);

    return 0;
}