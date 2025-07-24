//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator\n\n");

    //Initialize seed for random number generator
    srand(time(0));

    int num_of_aliens = (rand() % 100) + 1; //1-100 aliens
    int num_of_humans = (rand() % 10000) + 1; //1-10000 humans
    float alien_attack_prob = (float)num_of_aliens / num_of_humans;

    printf("There is a %f%% chance that aliens will attack Earth\n", alien_attack_prob);

    return 0;
}