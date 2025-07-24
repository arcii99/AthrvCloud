//FormAI DATASET v1.0 Category: Educational ; Style: funny
// This program generates a random number and asks the user to guess it.
// But there's a catch! The program will only accept input if the user
// types it backwards. Hilarity ensues.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int secret_number = rand() % 100 + 1;

    // Print some instructions
    printf("Welcome to the backwards guessing game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have to guess it, but there's a twist.\n");
    printf("I'll only accept your guess if you type it backwards.\n");
    printf("Good luck!\n\n");

    // Loop until the user guesses the correct number
    while (1) {
        // Prompt the user for a guess
        printf("Enter your guess: ");

        // Read the user's input
        char input[100];
        fgets(input, sizeof(input), stdin);

        // Remove the newline character from the end of the input
        input[strcspn(input, "\n")] = '\0';

        // Check if the input is the correct length
        if (strlen(input) != 2) {
            printf("That's not exactly backwards, try again!\n");
            continue;
        }

        // Check if the input is actually backwards
        if (input[0] != '0' + secret_number % 10 ||
            input[1] != '0' + secret_number / 10) {
            printf("That's not quite backwards, try again!\n");
            continue;
        }

        // The user guessed the correct number!
        printf("Congratulations, you guessed the number!\n");
        printf("You're a true backwards genius :)\n");
        return 0;
    }
}