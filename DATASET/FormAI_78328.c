//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    srand(time(0)); // Use current time as seed

    double alien_probability = (double)rand() / RAND_MAX; // Generate a random probability between 0 and 1

    printf("The probability of an alien invasion is %.2f%%. ", alien_probability * 100);

    if (alien_probability < 0.25) {
        printf("But don't worry, the chance of an invasion is very low. Enjoy your day!");
    }
    else if (alien_probability < 0.5) {
        printf("There's a moderate chance of an invasion. You may want to prepare a plan just in case.");
    }
    else {
        printf("Uh oh, it looks like there's a high chance of an invasion. Better start building your bunker!");
    }

    return 0;
}