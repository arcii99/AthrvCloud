//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); //seeds random number generator with current time
    printf("Welcome to the Alien Invasion Probability Calculator\n");

    int popSize, armySize, techLevel;
    float prob;

    printf("Please enter the population size of the area you want to calculate probability for: ");
    scanf("%d", &popSize);
    printf("Please enter the military size of the area you want to calculate probability for: ");
    scanf("%d", &armySize);
    printf("Please enter the technology level (0-10) of the military in the area: ");
    scanf("%d", &techLevel);

    int alienArmySize = popSize / 10; //assumes aliens will bring 1 army for every 10 humans
    int alienTechLevel = rand() % 11; //randomly generates alien tech level between 0-10
    printf("\nBased on our calculations, the alien army size is: %d", alienArmySize);
    printf("\nThe alien technology level is: %d\n", alienTechLevel);

    //calculates probability of alien invasion success
    prob = 0.1 * (alienArmySize - armySize + 10*(alienTechLevel - techLevel) + rand()%21); 
    printf("The probability of a successful alien invasion is: %f%%\n", prob);

    return 0; //end program
}