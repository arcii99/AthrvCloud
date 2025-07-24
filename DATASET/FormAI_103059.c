//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to generate random probability value
float generateProbability() {
    float prob = (float)rand() / (float)RAND_MAX;
    return prob;
}

// function to calculate the probability of alien invasion
float calculateInvasionProbability(int population, int militaryPower, int technologyLevel) {
    float baseProb = 0.1; // base probability of invasion
    float popFactor = (float)population / 1000000000; // population factor
    float milFactor = (float)militaryPower / 1000000; // military power factor
    float techFactor = (float)technologyLevel / 10; // technology level factor
    float randomFactor = generateProbability(); // random factor

    float finalProb = baseProb + (popFactor * 0.2) + (milFactor * 0.3) + (techFactor * 0.4) + (randomFactor * 0.1); // final probability calculation
    return finalProb;
}

// main function
int main() {
    int population, militaryPower, technologyLevel;
    float invasionProb;

    // initialize random seed
    srand(time(NULL));

    // get input from user
    printf("Enter current population (in billions): ");
    scanf("%d", &population);

    printf("\nEnter military power of your country (in millions): ");
    scanf("%d", &militaryPower);

    printf("\nEnter technology level of your country (on a scale of 1-10): ");
    scanf("%d", &technologyLevel);

    // calculate invasion probability
    invasionProb = calculateInvasionProbability(population, militaryPower, technologyLevel);

    // display result
    printf("\n\nThe probability of alien invasion is %.2f%%\n\n", invasionProb*100);

    return 0;
}