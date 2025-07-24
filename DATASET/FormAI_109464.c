//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int humans = 0, aliens = 0, human_survivors = 0;
    double invasion_probability = 0, human_survivor_probability = 0;
    srand(time(NULL));

    //Generate random number of humans and aliens
    humans = rand() % 100000000 + 1;
    aliens = rand() % 1000000 + 1;

    //Calculate invasion_probability
    invasion_probability = (double)aliens / humans;

    printf("ALIEN INVASION PROBABILITY CALCULATOR\n\n");
    printf("Number of humans on Earth: %d\n", humans);
    printf("Number of aliens attacking Earth: %d\n", aliens);
    printf("Invasion Probability: %lf\n\n", invasion_probability);

    //Calculate probability of human survival
    if (invasion_probability >= 1)
    {
        human_survivor_probability = 0;
        printf("Unfortunately, it is impossible for humans to survive the invasion.\n");
    }
    else if (invasion_probability >= 0.5)
    {
        human_survivors = rand() % humans / 2;
        human_survivor_probability = (double)human_survivors / humans;
        printf("Humans have a %lf%% chance of survival.\n", human_survivor_probability * 100);
    }
    else if (invasion_probability >= 0.1)
    {
        human_survivors = rand() % humans / 4;
        human_survivor_probability = (double)human_survivors / humans;
        printf("Humans have a %lf%% chance of survival.\n", human_survivor_probability * 100);
    }
    else
    {
        human_survivors = rand() % humans / 10;
        human_survivor_probability = (double)human_survivors / humans;
        printf("Humans have a %lf%% chance of survival.\n", human_survivor_probability * 100);
    }

    printf("\nPRESS ENTER TO CONTINUE...");
    getchar();

    return 0;
}