//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // initialize variables
    int alienProb = 0;
    int humanProb = 0;
    srand(time(NULL));

    // calculate the probabilities
    for(int i = 0; i < 100; i++){
        int randNum = rand() % 101; // generate a random number between 0-100
        if(randNum <= 50){
            alienProb++; // increment the alien probability
        }else{
            humanProb++; // increment the human probability
        }
    }

    // display the results
    printf("Alien Invasion Probability Calculator\n\n");
    printf("Based on our calculations, the probability of an alien invasion is: %d%%\n", alienProb);
    printf("The probability of us being safe from an alien invasion is: %d%%\n", humanProb);

    return 0;
}