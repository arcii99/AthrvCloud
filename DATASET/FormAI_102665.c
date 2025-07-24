//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_of_planets, num_of_days, num_of_ships, invasion_probability;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    // Get user input
    printf("How many planets does the system have? ");
    scanf("%d", &num_of_planets);
    printf("How many days until the invasion? ");
    scanf("%d", &num_of_days);
    printf("How many alien ships are present in the system? ");
    scanf("%d", &num_of_ships);

    // Seed the random number generator
    srand(time(NULL));

    // Calculate the invasion probability
    invasion_probability = (num_of_ships * (rand() % 10)) / (num_of_days + num_of_planets);

    // Print the result
    printf("The probability of an alien invasion is %d%%.\n", invasion_probability);

    return 0;
}