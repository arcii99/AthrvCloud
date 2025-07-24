//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int alienProbability;
    int paranoiaLevel;
    srand(time(0));  // Seed for random number generator

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter your level of paranoia (0-100): ");
    scanf("%d", &paranoiaLevel);

    if (paranoiaLevel < 0 || paranoiaLevel > 100) {
        printf("Invalid paranoia level. Please enter a number between 0 and 100.\n");
        return 0;
    }

    alienProbability = rand() % 101;

    if (alienProbability <= paranoiaLevel) {
        printf("ALERT: Alien invasion probability is %d%%. Take evasive action immediately!\n", alienProbability);
    } else {
        printf("Alien invasion probability is %d%%. No immediate action required.\n", alienProbability);
    }

    return 0;
}