//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for random number generator
    
    printf("Welcome to the Alien Invasion Probability Calculator\n\n");
    
    float probability = (rand() % 101) / 100.0; // generate random probability from 0 to 1
    
    if (probability < 0.25) {
        printf("Alien invasion probability: %.2f%%\n", probability * 100);
        printf("Uh oh, it looks like the aliens are already here!\n");
    } else if (probability < 0.5) {
        printf("Alien invasion probability: %.2f%%\n", probability * 100);
        printf("It's not looking good, the aliens have a decent chance of invading.\n");
    } else if (probability < 0.75) {
        printf("Alien invasion probability: %.2f%%\n", probability * 100);
        printf("The aliens are out there, but it's not very likely they'll invade.\n");
    } else {
        printf("Alien invasion probability: %.2f%%\n", probability * 100);
        printf("We have nothing to fear, the aliens are not coming.\n");
    }
    
    printf("\nThanks for using the Alien Invasion Probability Calculator!\n");
    
    return 0;
}