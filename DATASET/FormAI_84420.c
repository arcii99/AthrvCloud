//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seeding rand() with current time

    int planetSize = rand() % 100 + 1; // generating a random planet size between 1 and 100

    int alienCount = rand() % 1000 + 1; // generating a random alien count between 1 and 1000

    float invasionProbability = ((float)alienCount / planetSize) * 100; // calculating invasion probability 

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Based on our sophisticated calculations\n");
    printf("of the planet size and alien count, there is a\n");
    printf("%.2f percent chance of an alien invasion.\n\n", invasionProbability);

    printf("Do you want to see the details of our calculations?\n");
    printf("Enter 'yes' or 'no': ");

    char input[10];
    scanf("%s", input);

    if (strcmp(input, "yes") == 0)
    {
        printf("\nPlanet size: %d\n", planetSize);
        printf("Alien count: %d\n", alienCount);
        printf("Invasion probability: %.2f percent\n", invasionProbability);
    }

    return 0;
}