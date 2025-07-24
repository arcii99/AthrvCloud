//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Ask for probability of alien invasion
    printf("Enter the probability of an alien invasion (0-100): ");
    int probability;
    scanf("%d", &probability);

    // Check if given probability is valid
    if (probability < 0 || probability > 100) {
        printf("Invalid probability!\n");
        return 1;
    }

    // Check if there will be an alien invasion
    bool alienInvasion = (rand() % 100) < probability;

    if (alienInvasion) {
        printf("ALERT! ALERT! ALIEN INVASION IMMINENT!\n");
        printf("Please take necessary precautions and stay safe.\n");
    } else {
        printf("No signs of alien invasion at this time.\n");
        printf("Continue living your life with normalcy.\n");
    }

    return 0;
}