//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Initializing random seed
    
    int invasion_prob = rand() % 100 + 1; // Generating a random probability number 
    
    printf("Welcome to the C Alien Invasion Probability Calculator!\n\n");
    
    printf("Our experts have calculated that there is a %d%% chance of an alien invasion.\n", invasion_prob);
    
    if(invasion_prob >= 80){
        printf("Our prediction system shows that an invasion is highly likely.\n");
    } else if(invasion_prob >= 50){
        printf("There is a moderate probability of an invasion occurring.\n");
    } else if(invasion_prob >= 30){
        printf("There is a low probability of an invasion taking place.\n");
    } else{
        printf("There is a very low probability of an alien invasion occurring anytime soon.\n");
    }
    
    return 0;
}