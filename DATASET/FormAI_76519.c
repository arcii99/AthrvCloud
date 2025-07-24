//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasionChance = 0;
    srand(time(0)); // seed for random function

    int numSpaceships = rand() % 11; // random number of spaceships
    int numPlanets = rand() % 11; // random number of planets
    int numYears = rand() % 31; // random number of years

    printf("Welcome to the Alien Invasion Probability Calculator\n");
    printf("---------------------------------------------------\n");

    printf("Based on our analysis, there are currently %d spaceships and %d planets within %d light years of Earth.\n", numSpaceships, numPlanets, numYears);
    
    // calculate invasion chance based on number of spaceships and planets
    if (numSpaceships > 5 && numPlanets > 5) {
        invasionChance = 80;
    } else if (numSpaceships > 3 || numPlanets > 3) {
        invasionChance = 50;
    } else {
        invasionChance = 20;
    }

    printf("Our calculations show that the probability of an alien invasion is %d%%.\n", invasionChance);

    return 0;
}