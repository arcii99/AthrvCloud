//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int planets, population, resources, defense;
    float invasion_prob;
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the number of planets in the galaxy: ");
    scanf("%d", &planets);

    printf("Please enter the average population of each planet: ");
    scanf("%d", &population);

    printf("Please enter the average amount of resources each planet has: ");
    scanf("%d", &resources);

    printf("Please enter the average defense level of each planet: ");
    scanf("%d", &defense);

    invasion_prob = (float)(rand() % (resources/2) + defense/4) / (float)(population/1000);

    if(invasion_prob > 0.5){
        printf("\nAlert! Alert! The probability of an alien invasion is %.2f, be prepared for battle!", invasion_prob);
    }
    else{
        printf("\nGood news - the probability of an alien invasion is only %.2f! Keep on enjoying life on your planet!", invasion_prob);
    }

    return 0;
}