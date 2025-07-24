//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int probAlienInvasion, probNuclearWar, probNaturalDisaster;
    srand(time(NULL)); // seed random number generator

    // randomly generate probabilities
    probAlienInvasion = rand() % 101; // probability of alien invasion (0-100%)
    probNuclearWar = rand() % 101; // probability of nuclear war (0-100%)
    probNaturalDisaster = rand() % 101; // probability of natural disaster (0-100%)

    // display the probabilities to the user
    printf("The probability of an alien invasion is %d percent.\n", probAlienInvasion);
    printf("The probability of a nuclear war is %d percent.\n", probNuclearWar);
    printf("The probability of a natural disaster is %d percent.\n", probNaturalDisaster);

    // determine overall probability of an apocalypse
    int probApocalypse = (probAlienInvasion + probNuclearWar + probNaturalDisaster) / 3;

    // display the overall probability to the user
    printf("The overall probability of an apocalypse is %d percent.\n", probApocalypse);

    // determine whether the user should prepare for an apocalypse
    if(probApocalypse >= 50)
    {
        printf("You should prepare for the apocalypse!\n");
    }
    else
    {
        printf("You don't need to worry about the apocalypse for now.\n");
    }

    return 0;
}