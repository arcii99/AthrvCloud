//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasion_probability;
    srand(time(NULL));
    invasion_probability = rand() % 101;

    // Alien invasion probability calculation
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("The probability of an alien invasion is: %d%%\n\n",invasion_probability);

    if(invasion_probability >= 50) {
        printf("Warning! The probability of an alien invasion is high. Please take necessary measures!\n");
    } else {
        printf("The probability of an alien invasion is low. You can relax but stay alert.\n");
    }

    return 0;
}