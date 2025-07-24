//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));
    int num_of_aliens = (rand() % 1001) + 500; //generates aliens between 500 and 1500
    int num_of_humans = (rand() % 1000001) + 100000; //generates humans between 100000 and 1100000
    int num_of_fighters = (rand() % 1001) + 100; //generates fighters between 100 and 1100
    int num_of_ships = (rand() % 51) + 50; //generates ships between 50 and 100
    printf("Alien Invasion Probability Calculator:\n");
    printf("---------------------------------------\n");
    printf("Number of aliens: %d\n", num_of_aliens);
    printf("Number of humans: %d\n", num_of_humans);
    printf("Number of fighters: %d\n", num_of_fighters);
    printf("Number of ships: %d\n", num_of_ships);
    int alien_advantage = (num_of_aliens * num_of_ships) / (num_of_humans * num_of_fighters);
    if (alien_advantage > 1)
    {
        printf("The aliens have a %d%% chance of winning the invasion.\n", alien_advantage * 10);
    }
    else
    {
        printf("The humans have a %d%% chance of winning the invasion.\n", (10 - alien_advantage) * 10);
    }
    return 0;
}