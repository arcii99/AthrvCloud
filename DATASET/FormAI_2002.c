//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int num_trials;
    double probability;
    int aliens_killed;
    int total_aliens = 10000;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("How many trials would you like to run?\n");
    scanf("%d", &num_trials);
    srand(time(NULL));

    for (int i = 0; i < num_trials; i++)
    {
        aliens_killed = rand() % 1000 + 1;
        probability = ((double)aliens_killed / total_aliens) * 100;
        printf("For trial %d, you killed %d aliens, which gives a %.2f%% chance of survival.\n", i+1, aliens_killed, probability);
    }

    return 0;
}