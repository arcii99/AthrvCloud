//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); //seeding the random number generator

    int invasionProbability = rand() % 101; //generating a random number between 0 and 100 for the invasion probability

    if(invasionProbability >= 50) //if probability is greater than or equal to 50, an invasion is likely
    {
        char response[256] = {0};

        printf("ALERT! ALIEN INVASION PROBABILITY IS %d%%!\n", invasionProbability);
        printf("What is your plan of action? Enter 'attack', 'defend', or 'surrender': ");

        fgets(response, 256, stdin); //grabbing user input

        if(strcmp(response, "attack\n") == 0)
        {
            printf("You chose to attack! Good luck, soldier!\n");
        }
        else if(strcmp(response, "defend\n") == 0)
        {
            printf("You chose to defend! Protect your territory with all your might!\n");
        }
        else if(strcmp(response, "surrender\n") == 0)
        {
            printf("You have chosen to surrender. May the aliens spare your lives.\n");
        }
        else
        {
            printf("Invalid response. Please enter 'attack', 'defend', or 'surrender'.\n");
        }
    }
    else //if probability is less than 50, no invasion is likely
    {
        printf("Alien invasion probability is only %d%%. No need to worry... yet.\n", invasionProbability);
    }

    return 0;
}