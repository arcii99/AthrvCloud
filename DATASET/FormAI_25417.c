//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Welcome message
    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    //Initialize variables
    int alienShips = 0;
    int defenses = 0;
    float invasionProbability = 0.0;

    //Get user input for number of alien ships and defenses
    printf("How many alien ships are detected? ");
    scanf("%d", &alienShips);
    printf("How many available defenses do we have? ");
    scanf("%d", &defenses);

    //Seed the random number generator with current time
    srand(time(NULL));

    //Calculate the invasion probability
    invasionProbability = (float) alienShips / (float) (defenses + rand() % 100);

    //Print the results
    printf("\nBased on the number of alien ships and available defenses, the probability of an invasion is: %.2f%%\n", invasionProbability * 100);

    return 0;
}