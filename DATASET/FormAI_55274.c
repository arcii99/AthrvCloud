//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: excited
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    int alienTechLevel, defenseTechLevel, humanPopulation; 
    float invasionProbability; 

    printf("Welcome to the Alien Invasion Probability Calculator!\n"); 

    printf("Enter the current level of alien technology (1-10): "); 
    scanf("%d", &alienTechLevel); 

    printf("Enter the current level of defense technology (1-10): "); 
    scanf("%d", &defenseTechLevel); 

    printf("Enter the current human population: "); 
    scanf("%d", &humanPopulation); 

    srand(time(0)); 

    int randomFactor = rand() % 101; 

    invasionProbability = ((float) alienTechLevel / (float) defenseTechLevel) * (1 + ((float) humanPopulation / 5000000000)) * (1 + ((float) randomFactor / 100)); 

    printf("\n\n"); 
    printf("Based on the factors entered, the probability of an alien invasion is %f percent.\n", invasionProbability); 

    printf("\n\n"); 
    printf("Thank you for using the Alien Invasion Probability Calculator! Stay safe and keep looking up!\n"); 

    return 0; 
}