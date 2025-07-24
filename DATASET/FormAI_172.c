//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed

    int alien_ships;
    int probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of alien ships in space: ");
    scanf("%d", &alien_ships);

    printf("\nCalculating probability of an alien invasion...\n");

    probability = rand() % 101; // Random number between 0 and 100

    if (alien_ships <= 10) {
        printf("There are only %d alien ships in space. The probability of an invasion is low.\n", alien_ships);
        printf("Probability: %d%%\n", probability);
    } else if (alien_ships <= 50) {
        printf("There are %d alien ships in space. The probability of an invasion is moderate.\n", alien_ships);
        printf("Probability: %d%%\n", probability);
    } else {
        printf("There are %d alien ships in space. The probability of an invasion is high.\n", alien_ships);
        printf("Probability: %d%%\n", probability);
    }

    printf("\nGood luck!\n");

    return 0;
}