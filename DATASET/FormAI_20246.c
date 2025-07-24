//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: dynamic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    //Initializing seed for random number generation
    srand(time(NULL));
    
    //Initializing variables to keep track of probabilities
    int totalCalculations = 0;
    int alienInvasionProbs = 0;
    int noAlienInvasionProbs = 0;
    
    //Taking input from user
    printf("Enter the number of times you want to calculate probability: ");
    int numCalculations;
    scanf("%d", &numCalculations);
    
    //Generating probability for each calculation
    for(int i = 0; i < numCalculations; i++) {
        
        int randomNumber = (rand() % 10) + 1; //Generating a random number between 1 and 10
        
        if(randomNumber >= 7) { //If the random number is 7 or greater, the probability of alien invasion is higher
            alienInvasionProbs++;
        }
        else { //If the random number is less than 7, the probability of alien invasion is lower
            noAlienInvasionProbs++;
        }
        
        //Incrementing total calculations
        totalCalculations++;
    }
    
    //Calculating and displaying results
    float alienInvasionProbability = (float)alienInvasionProbs / (float)totalCalculations;
    float noAlienInvasionProbability = (float)noAlienInvasionProbs / (float)totalCalculations;
    
    printf("\nAfter conducting %d calculations, the probabilities of the following events have been determined:\n", numCalculations);
    printf("Probability of an alien invasion: %.2f\n", alienInvasionProbability);
    printf("Probability of no alien invasion: %.2f", noAlienInvasionProbability);
    
    return 0;
}