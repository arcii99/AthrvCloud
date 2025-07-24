//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare variables
    int alien_ships, magic_wizards, dragon_fire;
    float invasion_probability;

    // Get user input
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of alien spaceships: ");
    scanf("%d", &alien_ships);

    printf("Please enter the number of magic wizards defending the realm: ");
    scanf("%d", &magic_wizards);

    printf("Please enter the strength of the dragon fire: ");
    scanf("%d", &dragon_fire);

    // Calculate invasion probability
    invasion_probability = ((float)alien_ships / magic_wizards) * dragon_fire;

    // Display the results to the user
    printf("\nThe probability of an alien invasion is: %.2f%%\n", invasion_probability);

    // Display a message based on the invasion probability
    if (invasion_probability > 75) {
        printf("We are doomed! Prepare for the worst!\n");
    } else if (invasion_probability > 50) {
        printf("We must prepare for battle! Rally the troops!\n");
    } else if (invasion_probability > 25) {
        printf("We have a chance at victory! Huzzah!\n");
    } else {
        printf("We shall prevail! The aliens stand no chance!\n");
    }

    return 0;
}