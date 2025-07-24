//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: inquisitive
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    int alienProbability, randomNumber; 
    
    srand(time(0)); // Seed for random number generator
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n"); 
    
    printf("The first step is to enter the probability of an alien invasion on a scale of 1 to 10.\n"); 
    
    printf("Please enter a number between 1 and 10: "); 
    
    scanf("%d", &alienProbability); 
    
    if(alienProbability < 1 || alienProbability > 10) { 
        printf("Invalid input. Please enter a number between 1 and 10.\n"); 
        return 0; 
    } 
    
    // Generate a random number between 1 and 10
    
    randomNumber = rand() % 10 + 1; 
    
    printf("Calculating....\n\n"); 
    
    printf("The probability of an alien invasion is %d out of 10.\n", randomNumber); 
    
    if(randomNumber <= alienProbability) { 
        printf("There is a high likelihood of an alien invasion. Please take necessary precautions!\n"); 
    } else { 
        printf("The probability of an alien invasion is low. Don't worry too much about it!\n"); 
    } 
    
    printf("\nThank you for using the Alien Invasion Probability Calculator!\n"); 
    
    return 0; 
}