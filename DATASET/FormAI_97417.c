//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int invasionProbability, randomNumber;
    srand(time(NULL));
    randomNumber = rand() % 100 + 1;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Enter the number of knights in your army: ");
    int numberOfKnights;
    scanf("%d", &numberOfKnights);
    invasionProbability = (randomNumber * numberOfKnights) / 2;
    printf("Calculating the probability of an alien invasion...\n");
    printf("Hmmm... it looks like there is a %d%% chance of an alien invasion.\n", invasionProbability);
    if(invasionProbability > 50){
        printf("The odds do not look good. You should prepare your army for battle!\n");
    }
    else{
        printf("The odds are in your favor. Your kingdom is safe from alien invasion for now!\n");
    }
    return 0;
}