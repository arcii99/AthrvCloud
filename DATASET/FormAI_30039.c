//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current system time
    srand(time(NULL));
    
    // Declare and initialize variables
    int numPlanetsVisited = 0;
    int numPlanetsWithIntelligentLife = 0;
    
    // Welcome message
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will calculate the probability of an alien invasion after visiting a set number of planets.\n\n");
    
    // Prompt user for number of planets to visit
    int numPlanetsToVisit;
    printf("How many planets do you plan to visit? ");
    scanf("%d", &numPlanetsToVisit);
    printf("\n");
    
    // Visit each planet and determine if it has intelligent life
    for (int i = 1; i <= numPlanetsToVisit; i++) {
        // Generate a random number between 1 and 10 to determine if the planet has intelligent life
        int randomNum = rand() % 10 + 1;
        
        // If the random number is greater than or equal to 5, the planet has intelligent life
        if (randomNum >= 5) {
            numPlanetsWithIntelligentLife++;
            printf("Planet #%d has intelligent life!\n", i);
        } else {
            printf("Planet #%d does not have intelligent life.\n", i);
        }
        
        // Increment the number of planets visited
        numPlanetsVisited++;
    }
    
    // Calculate the probability of an alien invasion
    float invasionProbability = (float) numPlanetsWithIntelligentLife / numPlanetsVisited;
    
    // Output the results to the user
    printf("\n");
    printf("Out of the %d planets visited, %d had intelligent life.\n", numPlanetsVisited, numPlanetsWithIntelligentLife);
    printf("The probability of an alien invasion is %.2f.\n", invasionProbability);
    
    return 0;
}