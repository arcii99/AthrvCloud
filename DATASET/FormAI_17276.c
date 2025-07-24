//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float probability;
    char name[30];

    printf("Hello! Welcome to the Alien Invasion Probability Calculator.\n");
    printf("What is your name?\n");
    scanf("%s", name);

    printf("\nWelcome, %s! Let's get started.\n\n", name);

    srand(time(0));

    int alienTech = rand() % 101; // Alien Technology Level (0-100)
    int earthTech = rand() % 101; // Earth Technology Level (0-100)
    int distance = rand() % 200000001; // Distance between Earth and Alien planet (in km)

    printf("Calculating...\n");
    printf("Alien Technology Level: %d\n", alienTech);
    printf("Earth Technology Level: %d\n", earthTech);
    printf("Distance between Earth and Alien planet: %d km\n", distance);

    // Calculation of Probability of Alien Invasion
    probability = (alienTech - earthTech) / (float)distance;

    printf("\nBased on our calculations, the probability of an alien invasion is %f%%\n", probability*100);

    printf("\nThank you for using the Alien Invasion Probability Calculator. Stay vigilant, %s!\n", name);

    return 0;
}