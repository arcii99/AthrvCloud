//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    srand(time(NULL)); //initialize random seed

    int earthDefense = rand() % 101; //generate Earth's defense rating
    int alienTech = rand() % 101; //generate alien technology rating

    printf("Earth's defense rating is %d\n", earthDefense);
    printf("Alien technology rating is %d\n", alienTech);

    float invasionProbability = (float)alienTech / (float)earthDefense; //calculate probability of invasion
    printf("Probability of invasion is %.2f%%\n", invasionProbability);

    if(invasionProbability >= 0.75){
        printf("Attention! Probability of invasion is high. Prepare for battle!\n");
    }
    else if(invasionProbability >= 0.5){
        printf("Attention! Probability of invasion is moderate. Be vigilant!\n");
    }
    else if(invasionProbability >= 0.25){
        printf("Attention! Probability of invasion is low. But don't let your guard down!\n");
    }
    else{
        printf("Attention! Probability of invasion is minimal. But stay alert just in case!\n");
    }

    return 0;
}