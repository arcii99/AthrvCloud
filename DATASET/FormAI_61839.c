//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int invasionYear, invasionChance, defenseBudget;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    
    srand(time(NULL));  // initialize random seed

    // get user input
    printf("Enter the current year: ");
    scanf("%d", &invasionYear);
    printf("Enter your planet's current defense budget (in billions of USD): ");
    scanf("%d", &defenseBudget);

    // calculate invasion probability based on current year and defense budget
    invasionChance = rand() % 101;  // generate a random number between 0 and 100
    if (invasionYear < 2050) {
        invasionChance += defenseBudget * 0.1;  // increase chance by 10% of defense budget if invasion is before 2050
    } else {
        invasionChance -= defenseBudget * 0.05;  // decrease chance by 5% of defense budget if invasion is after 2050
    }

    // print results
    printf("\nBased on your current defense budget and the current year, the probability of an alien invasion is %d%%.\n", invasionChance);

    return 0;
}