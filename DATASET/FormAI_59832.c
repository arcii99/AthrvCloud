//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // initialize random seed with time
    int alien_prob = rand() % 101; // generate random number between 0 and 100 as alien invasion probability
    printf("Alien invasion probability: %d%%\n", alien_prob);
    
    if(alien_prob < 50){
        printf("There is a low probability of an alien invasion. You can relax for now.\n");
    }
    else if(alien_prob >= 50 && alien_prob < 80){
        printf("There is a moderate probability of an alien invasion. You may want to prepare for the possibility.\n");
    }
    else{
        printf("There is a high probability of an alien invasion. Take necessary precautions and seek help from experts.\n");
    }
    
    return 0;
}