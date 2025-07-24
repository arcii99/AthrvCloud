//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numPlanets, numYears, alienArrivalChance;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of planets in the solar system: ");
    scanf("%d", &numPlanets);
    printf("Enter the number of years you want to calculate: ");
    scanf("%d", &numYears);
    
    srand(time(NULL)); // initializes random seed
    
    printf("Calculating...\n");
    
    int numInvasions = 0;
    for (int year = 1; year <= numYears; year++) {
        for (int planet = 1; planet <= numPlanets; planet++) {
            alienArrivalChance = rand() % 101; // generate a random number between 0 and 100
            if (alienArrivalChance < 5) { // 5% chance of alien arrival
                numInvasions++;
                printf("Year %d: Planet %d has been invaded!\n", year, planet);
                break; // only one invasion can happen per year
            }
        }
    }

    float invasionProbability = (float) numInvasions / (numYears * numPlanets) * 100;
    printf("\nAfter %d years and %d planets, the probability of an alien invasion is %.2f%%.\n", numYears, numPlanets, invasionProbability);

    return 0;
}