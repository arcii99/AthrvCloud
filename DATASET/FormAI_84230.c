//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasion_probability, max_probability, min_probability;
    int alien_species;
    srand(time(NULL)); //seed random number generator with current time

    printf("Welcome to the Alien Invasion Probability Calculator\n");

    //Get user input for alien species
    printf("Please select the type of alien species: \n");
    printf("1 - Grey Aliens\n2 - Reptilian Aliens\n3 - Insectoid Aliens\n");
    scanf("%d", &alien_species);

    //Set max and min invasion probability based on alien species
    switch (alien_species) {
        case 1:
            max_probability = 50;
            min_probability = 1;
            printf("Calculating invasion probability for Grey Aliens...\n");
            break;
        case 2:
            max_probability = 80;
            min_probability = 20;
            printf("Calculating invasion probability for Reptilian Aliens...\n");
            break;
        case 3:
            max_probability = 30;
            min_probability = 5;
            printf("Calculating invasion probability for Insectoid Aliens...\n");
            break;
        default:
            printf("Invalid alien species selected. Program closing...\n");
            return 0;
    }

    //Generate random invasion probability within the set range
    invasion_probability = (rand() % (max_probability - min_probability + 1)) + min_probability;

    //Print calculated invasion probability
    printf("Invasion probability for selected alien species is %d%%\n", invasion_probability);

    return 0;
}