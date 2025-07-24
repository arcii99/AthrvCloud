//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numAliens;
    double invasionProb;
    srand(time(0)); // initialize random seed

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of aliens you think will invade Earth: ");
    scanf("%d", &numAliens);

    if (numAliens < 0) {
        printf("Invalid input. The number of aliens cannot be negative.\n");
        return 1;
    } else if (numAliens == 0) {
        printf("The probability of an alien invasion is 0.\n");
        return 0;
    }

    int minAliens = rand() % 100 + 1; // generate random number between 1 and 100
    int maxAliens = minAliens + (rand() % 1000 + 1); // generate random number between 1 and 1000 and add to minAliens

    if (numAliens > maxAliens) {
        invasionProb = 1;
    } else if (numAliens < minAliens) {
        invasionProb = 0;
    } else {
        invasionProb = ((double)numAliens - minAliens) / (maxAliens - minAliens);
    }

    printf("The probability of an invasion with %d aliens is %.2f.\n", numAliens, invasionProb);

    return 0;
}