//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int population, military, resources, alien_tech;
    float invasion_prob;

    srand(time(0)); // seeding random number generator

    printf("Welcome to the Alien Invasion Probability Calculator.\n\n");

    // Getting inputs from user
    printf("Enter the current population of your country (in millions): ");
    scanf("%d", &population);

    printf("Enter the number of personnel in your military: ");
    scanf("%d", &military);

    printf("Enter the amount of resources your country has (in billions): ");
    scanf("%d", &resources);

    printf("Enter your country's level of alien technology (1-10): ");
    scanf("%d", &alien_tech);

    // Calculating invasion probability
    invasion_prob = (float) ((rand() % (35 - 15 + 1)) + 15) / 100; // random number between 0.15 and 0.35
    invasion_prob = invasion_prob + (float) ((100 - population) / 1000); // increasing probability for low population
    invasion_prob = invasion_prob + (float) ((military / 100000) * 0.2); // increasing probability for strong military
    invasion_prob = invasion_prob + (float) ((resources / 100) * 0.1); // increasing probability for abundant resources
    invasion_prob = invasion_prob - (float) ((10 - alien_tech) * 0.03); // decreasing probability for advanced alien technology

    // Printing the result
    printf("\nBased on the inputs provided, the probability of a successful alien invasion is %f.\n", invasion_prob);

    return 0;
}