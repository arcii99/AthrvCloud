//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int attackChance; // Probability of alien attack
    int defenseChance; // Probability of defense against attack
    int invasionProb; // Probability of alien invasion
    srand(time(0)); // Initialize random seed

    printf("Welcome to the Alien Invasion Probability Calculator.\n");
    printf("This program calculates the probability of an alien invasion.\n");
    printf("Please enter the likelihood of an alien attack (0-100): ");
    scanf("%d", &attackChance);
    printf("Please enter the likelihood of successful defense against the attack (0-100): ");
    scanf("%d", &defenseChance);

    // Calculate the probability of an alien invasion
    invasionProb = attackChance * (100 - defenseChance) / 100;

    // Generate a random number between 1 to 100
    int randNum = rand() % 100 + 1;

    // If the random number is less than or equal to invasion probability, then the invasion occurs
    if(randNum <= invasionProb)
    {
        printf("\nALERT! ALIEN INVASION OCCURRED!\n");
        printf("Probability of invasion: %d%%\n\n", invasionProb);
    }
    else
    {
        printf("\nNo alien invasion occurred.\n");
        printf("Probability of invasion: %d%%\n\n", invasionProb);
    }

    return 0;
}