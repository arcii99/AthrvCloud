//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // set seed for random number generator
    int alien_ships = rand() % 100;  // generate random number of alien ships
    int total_ships = rand() % 1000 + 1;  // generate random total number of ships
    int invasion_probability = 0;

    // calculate probability of alien invasion based on number of alien ships and total number of ships
    if (total_ships == 0) {
        printf("There are no ships to invade. Probability of invasion is 0%%.\n");
    } else if (alien_ships == 0) {
        printf("There are no alien ships. Probability of invasion is 0%%.\n");
    } else {
        invasion_probability = (int)(((float)alien_ships / (float)total_ships) * 100);
        printf("There are %d alien ships out of %d total ships. Probability of invasion is %d%%.\n", alien_ships, total_ships, invasion_probability);
    }

    return 0;
}