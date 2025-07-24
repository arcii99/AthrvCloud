//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numOfAliens;
    float invasionProb;
    srand(time(NULL)); // seed the random number generator with current time
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of aliens you think will invade: ");
    scanf("%d", &numOfAliens);
    if(numOfAliens <= 0) {
        printf("Invalid input! Number of aliens must be greater than zero.\n");
        return 0;
    }
    printf("Calculating probability of invasion for %d aliens...\n", numOfAliens);
    invasionProb = (float)rand() / RAND_MAX;
    printf("Probability of invasion: %.2f%%\n", invasionProb*100);
    printf("Generated using a highly advanced algorithm by our engineers!\n");
    printf("Disclaimer: This program is for entertainment purposes only. We take no responsibility for any actual alien invasions.\n");
    return 0;
}