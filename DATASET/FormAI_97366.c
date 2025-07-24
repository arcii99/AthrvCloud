//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int prob;
    srand(time(NULL)); //initialize random seed

    printf("Welcome to the Alien Invasion Probability Calculator\n");

    printf("Enter the percentage chance of alien invasion: ");
    scanf("%d", &prob);

    int rand_num = rand() % 100 + 1; //generate random number between 1 and 100

    if (rand_num <= prob) {
        printf("Alien invasion is likely with a %d%% chance.\n", prob);
    } else {
        printf("Alien invasion is unlikely with only a %d%% chance.\n", prob);
    }

    return 0;
}