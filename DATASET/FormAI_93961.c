//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    srand(time(NULL)); // set seed for random number generation
    
    int alienTechLevel = rand() % 11; // generate random alien tech level
    int humanTechLevel = rand() % 11; // generate random human tech level
    int alienNumbers = rand() % 1000; // generate random number of alien invaders
    int humanPopulation = rand() % 2000000001; // generate random human population
    
    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");
    printf("Alien Tech Level: %d\n", alienTechLevel);
    printf("Human Tech Level: %d\n", humanTechLevel);
    printf("Alien Invaders: %d\n", alienNumbers);
    printf("Human Population: %d\n\n", humanPopulation);
    
    // calculate invasion probability based on tech level and invasion force size
    double invasionProbability = ((1.0 + alienTechLevel) / (1.0 + humanTechLevel)) * ((double)alienNumbers / (double)humanPopulation);
    
    printf("Invasion Probability: %.2f%%\n", invasionProbability * 100);
    
    if(invasionProbability <= 0.1) {
        printf("There is a low probability of invasion. We can relax for now.\n");
    } else if(invasionProbability > 0.1 && invasionProbability <= 0.5) {
        printf("The probability of invasion is moderate. We should prepare a defense strategy.\n");
    } else if(invasionProbability > 0.5 && invasionProbability <= 0.9) {
        printf("The probability of invasion is high. We need to take immediate action to defend.\n");
    } else {
        printf("The probability of invasion is very high. We are in great peril! We need to act fast to save our planet!\n");
    }
    
    return 0;
}