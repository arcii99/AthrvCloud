//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function declarations
int calculateProbability(int distance, int technologyLevel);

int main() {
    int distance, technologyLevel, probability;

    //Seed the random number generator
    srand(time(NULL));

    //Get input from user
    printf("Enter distance from Earth in light years: ");
    scanf("%d", &distance);

    printf("Enter the technology level of aliens (1 to 10): ");
    scanf("%d", &technologyLevel);

    //Calculate probability of alien invasion
    probability = calculateProbability(distance, technologyLevel);

    //Print out the probability
    printf("The probability of alien invasion is %d percent\n", probability);

    return 0;
}

//Function to calculate probability of alien invasion
int calculateProbability(int distance, int technologyLevel) {
    int probability = 0;

    //Calculate probability based on distance and technology level
    if(distance <= 100 && technologyLevel >= 8) {
        probability = rand() % 91 + 10; //10% - 100%
    } else if(distance > 100 && distance <= 1000 && technologyLevel >= 6) {
        probability = rand() % 51 + 10; //10% - 60%
    } else if(distance > 1000 && distance <= 10000 && technologyLevel >= 4) {
        probability = rand() % 21 + 5;  //5% - 25%
    }

    return probability;
}