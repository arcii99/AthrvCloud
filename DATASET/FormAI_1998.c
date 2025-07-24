//FormAI DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    int dice_faces = 6; // A standard dice has 6 faces

    // Welcome message
    printf("\nWelcome to the Dice Roller!\n");
    printf("This program can simulate any number of dice rolls with any number of faces.\n\n");

    // Input number of dice and faces
    int num_dice, num_faces;
    printf("How many dice would you like to roll? (1 or more): ");
    scanf("%d", &num_dice);
    printf("How many faces does each dice have? (1 or more): ");
    scanf("%d", &num_faces);

    // Roll the dice(s) and display the results
    printf("\nRolling %d dice with %d faces...\n", num_dice, num_faces);
    for (int i = 1; i <= num_dice; i++) {
        int result = rand() % num_faces + 1; // Calculate a random number between 1 and num_faces (inclusive)
        printf("Dice %d: %d\n", i, result);
    }

    // Ask the user if they want to roll again
    char answer;
    printf("\nWould you like to roll again? (Y/N): ");
    scanf(" %c", &answer); // Note the space before %c to consume any remaining whitespace
    if (answer == 'Y' || answer == 'y') {
        main(); // Recursively call main function to start over
    } else {
        printf("\nThank you for using the Dice Roller! Have a nice day.\n"); // End message
    }
    return 0;
}