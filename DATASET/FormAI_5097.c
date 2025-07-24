//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //seed the random number generator with current time
    int alienProb = rand() % 100 + 1; //generate a random number between 1 and 100
    int invasionProb = alienProb * 0.75; //determine invasion probability as 75% of alien probability
    
    printf("Alien Probability: %d%%\n", alienProb);
    printf("Invasion Probability: %d%%\n", invasionProb);
    
    if(invasionProb >= 50) { //if invasion probability is greater than or equal to 50%
        printf("Prepare for an Alien Invasion!\n");
    } else {
        printf("No need to worry, no alien invasion expected.\n");
    }
    
    return 0;
}