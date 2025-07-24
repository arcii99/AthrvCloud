//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int probability; //probability of alien invasion
    srand(time(0)); //initialize random seed using current time

    printf("Welcome to the Alien Invasion Probability Calculator.\n");
    
    //generate random number between 0-100
    probability = rand() % 101;

    printf("Based on our calculations, there is a %d%% chance of an alien invasion.\n", probability);
    
    //give recommendation based on probability
    if(probability >= 75) {
        printf("We recommend that all citizens prepare for an imminent invasion.\n");
    }
    else if(probability >= 50) {
        printf("We suggest that citizens remain vigilant and report any suspicious activity.\n");
    }
    else {
        printf("There is a low chance of an invasion, but it is always best to be prepared.\n");
    }

    return 0;
}