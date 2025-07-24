//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    // Initialize the random number generator
    srand(time(NULL));

    // Set the probability of an alien invasion to 0.01
    float probability = 0.01;

    // Ask for user input
    printf("How many years from now would you like to calculate the probability of an alien invasion?\n");
    int years;
    scanf("%d", &years);

    // Calculate the probability of an alien invasion
    float alien_invasion_probability = 1 - pow(1 - probability, years);

    // Print out the results
    printf("The probability of an alien invasion in %d years is %.2f%%.\n", years, alien_invasion_probability * 100);

    return 0;
}