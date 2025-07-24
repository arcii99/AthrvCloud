//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    //setting up the seed for random number generation
    srand(time(0));
    
    //defining variables
    int numberOfPlanets, numberOfAlienRaces, i, j;
    float alienInvasionProbability = 0.0;
    
    //greeting message
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    
    //getting user input
    printf("Enter the number of planets in the universe: ");
    scanf("%d", &numberOfPlanets);
    
    printf("\nEnter the number of alien races in the universe: ");
    scanf("%d", &numberOfAlienRaces);
    
    //calculating the alien invasion probability
    for(i=0;i<numberOfPlanets;i++){
        for(j=0;j<numberOfAlienRaces;j++){
            //generating a random number between 0 and 1 for each planet and alien race combination
            float probability = (float)rand()/(float)RAND_MAX;
            alienInvasionProbability += probability;
        }
    }
    
    //dividing the result by the total number of planet-alien race combinations to get the average probability
    alienInvasionProbability /= (numberOfPlanets * numberOfAlienRaces);
    
    //displaying the result
    printf("\nThe probability of an alien invasion is %.2f%%\n", alienInvasionProbability*100);
    
    return 0;
}