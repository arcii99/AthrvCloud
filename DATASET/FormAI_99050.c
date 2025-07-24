//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float alienInvasionProbabilityCalculator(float distance, float populationDensity);

int main() {
    float distance, populationDensity, invasionProbability;

    printf("Welcome to the Alien Invasion Probability Calculator\n\n");
    printf("Please enter the distance from the alien planet to earth in light years: ");
    scanf("%f", &distance);
    printf("Please enter the population density of the earth in people per square kilometer: ");
    scanf("%f", &populationDensity);

    invasionProbability = alienInvasionProbabilityCalculator(distance, populationDensity);
    printf("\n\nThe probability of an alien invasion is: %f\n\n", invasionProbability);

    return 0;
}

float alienInvasionProbabilityCalculator(float distance, float populationDensity) {
    float probability;

    srand(time(NULL)); // seed the random number generator with the current time

    if(distance >= 0 && distance <= 10) {
        // 10% chance of invasion for close distances
        probability = 0.1;
    } else if(distance > 10 && distance <= 50) {
        // 30% chance of invasion for mid-range distances
        probability = 0.3;
    } else {
        // 50% chance of invasion for far distances
        probability = 0.5;
    }

    // increase the probability of invasion based on population density
    probability += (populationDensity / 10000);
    // add a random factor between -10% and +10%
    probability *= (rand() % 21 - 10) / 100.0;

    return probability;
}