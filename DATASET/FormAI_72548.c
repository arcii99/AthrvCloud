//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed random number generator

    int numPlanets = rand() % 1000 + 1; // generate a random number between 1 and 1000 for number of planets in the galaxy

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Based on the number of planets in the galaxy, we will calculate the probability of an alien invasion.\n");

    printf("Number of planets in the galaxy: %d\n", numPlanets);

    float invasionProbability = ((float)numPlanets / 1000) * 100; // calculate invasion probability as a percentage

    printf("Current invasion probability: %.2f%%\n", invasionProbability);

    printf("But wait, there's more... \n");
    printf("There are rumors of a highly advanced alien species that has been moving through the galaxy, conquering planet after planet...\n");
    printf("This alien species has been known to completely wipe out any other civilization that they encounter.\n");
    printf("What is the probability that this species will invade our planet? Let's factor that in...\n");

    int alienProbability = rand() % 101; // generate a random probability for alien invasion

    if (alienProbability < 25) { // 25% chance of alien invasion
        invasionProbability += 50;
    }
    else if (alienProbability >= 25 && alienProbability < 50) { // 25% chance of alien invasion
        invasionProbability += 25;
    }
    else if (alienProbability >= 50 && alienProbability < 75) { // 25% chance of alien invasion
        invasionProbability += 10;
    }
    else { // 25% chance of alien invasion
        invasionProbability += 5;
    }

    printf("After factoring in the advanced alien species, the new invasion probability is: %.2f%%\n", invasionProbability);

    printf("But we're not done yet... \n");
    printf("What if the aliens have already invaded a nearby planet and are using it as a base to launch their attack?\n");
    printf("Let's factor that in as well...\n");

    int baseProbability = rand() % 101; // generate a random probability for alien base

    if (baseProbability < 25) { // 25% chance of alien base
        invasionProbability += 25;
    }
    else if (baseProbability >= 25 && baseProbability < 50) { // 25% chance of alien base
        invasionProbability += 15;
    }
    else if (baseProbability >= 50 && baseProbability < 75) { // 25% chance of alien base
        invasionProbability += 10;
    }
    else { // 25% chance of alien base
        invasionProbability += 5;
    }

    printf("After factoring in the nearby alien base, the final invasion probability is: %.2f%%\n", invasionProbability);

    printf("You may want to start preparing for the worst...\n");

    return 0;
}