//FormAI DATASET v1.0 Category: Computer Biology ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_POPULATION 1
#define MAX_POPULATION 1000000

int main() {
    int population = INITIAL_POPULATION;
    int time = 0;

    printf("Welcome to the Bacterial Colony Simulator! We have %d initial bacteria.\n", population);

    while (population < MAX_POPULATION) {
        int newBacteria = rand() % (population + 1); // simulate random division
        population += newBacteria;

        printf("Wow! Our colony has grown to %d bacteria after %d hours! ", population, time);

        if (newBacteria > 0) {
            printf("That's %d new bacteria born!", newBacteria);
        } else {
            printf("No new bacteria born this time, but we still grew!");
        }

        if (population > 1000 && population <= 10000) {
            printf("We are growing at a steady rate!\n");
        } else if (population > 10000 && population <= 100000) {
            printf("The colony is getting crowded!\n");
        } else if (population > 100000) {
            printf("We're gonna need a bigger petri dish...\n");
        } else {
            printf("\n");
        }

        time += 1;
    }

    printf("Our colony has reached the maximum population of %d!", MAX_POPULATION);

    return 0;
}