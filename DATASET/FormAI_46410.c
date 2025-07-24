//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Welcome message
    printf("\n\n=== Welcome to the Alien Invasion Probability Calculator! ===\n\n");

    // Set the seed for the random number generator
    srand(time(NULL));

    // Declare and initialize the variables
    int num_of_aliens, invasion_likelihood;
    float probability;
    char play_again;

    do {
        // Get the number of aliens
        printf("Enter the number of aliens: ");
        scanf("%d", &num_of_aliens);

        // Calculate the invasion likelihood
        invasion_likelihood = rand() % (num_of_aliens * 2);

        // Calculate the invasion probability
        probability = 1.0 * invasion_likelihood / (num_of_aliens * 2) * 100;

        // Print the results
        printf("\n\n~~~ CALCULATING ~~~\n\n");
        printf("There is a %0.2f%% chance of an alien invasion with %d aliens.\n\n", probability, num_of_aliens);

        // Ask the user if they want to play again
        printf("Do you want to calculate again? (Y/N) ");
        scanf(" %c", &play_again);

    } while (play_again == 'Y' || play_again == 'y');

    // Goodbye message
    printf("\n\n=== Thanks for calculating! ===\n\n");

    return 0;
}