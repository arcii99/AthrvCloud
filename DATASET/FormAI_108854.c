//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random number generator
    int invasion_prob = rand() % 101; // Generate a random number from 0-100
    int defense_level;
 
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("Please enter the current defense level of the planet (1-10): ");
    scanf("%d", &defense_level);

    if (invasion_prob >= defense_level * 10) {
        printf("\nALERT: Alien invasion is highly likely! Probability: %d%%\n", invasion_prob);
    } else {
        printf("\nAlien invasion is unlikely. Probability: %d%%\n", invasion_prob);
    }

    return 0;
}