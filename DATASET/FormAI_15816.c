//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));

    int earth_population;
    float alien_prob, random_prob;

    printf("Enter the earth population: ");
    scanf("%d", &earth_population);

    alien_prob = earth_population * 0.00001;

    random_prob = ((float)rand() / (RAND_MAX));

    printf("\nALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("=====================================\n");
    printf("Earth population: %d\n", earth_population);
    printf("Alien invasion probability: %f\n", alien_prob);

    if (random_prob <= alien_prob)
    {
        printf("ALERT! Alien invasion is highly probable!\n");
    }
    else
    {
        printf("It is unlikely that aliens will invade Earth.\n");
    }

    return 0;
}