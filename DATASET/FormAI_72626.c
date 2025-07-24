//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int alienProbability, humanProbability, randomProb;
    
    printf("Fair Juliet, my love for thee is as strong as the probability of an alien invasion occurring in our fair city. Let us determine our fate by creating a probability calculator.\n\n");
    printf("What is the likelihood, in percentage, of an alien invasion occurring in our city?\n");
    scanf("%d", &alienProbability);
    
    printf("And what is the likelihood, in percentage, of us being able to defeat the aliens?\n");
    scanf("%d", &humanProbability);
    
    printf("\n\n");
    
    srand((unsigned)time(NULL));
    randomProb = rand() % 100 + 1;
    
    printf("My dearest Juliet, the stars have aligned and fate has spoken:\n\n");
    
    if(randomProb <= alienProbability){
        printf("Alas! The probability of an alien invasion has come to pass. We must prepare for battle!\n");
    }
    else{
        printf("Hark! Our city remains safe from the invaders from beyond.\n");
    }
    
    randomProb = rand() % 100 + 1;
    
    printf("\n\n");
    
    if(randomProb <= humanProbability){
        printf("Oh joyous occasion! Our forces have prevailed against the alien threat. We shall drink to our triumph tonight.\n");
    }
    else{
        printf("Tragedy has befallen our city. Our defenses were not enough to withstand the might of the alien invaders.\n");
    }
    
    return 0;
}