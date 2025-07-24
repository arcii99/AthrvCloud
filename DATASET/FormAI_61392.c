//FormAI DATASET v1.0 Category: Random ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {

    printf("Greetings, adventurer! Welcome to my dungeon of randomness!\n\n");

    // Seed the random number generator with system time
    srand(time(NULL));

    // Display a menu of choices for the user
    printf("Please choose an option:\n");
    printf("1. Guess the random number\n");
    printf("2. Roll the dice\n");
    printf("3. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Generate a random number between 1 and 100
            int answer = rand() % 100 + 1;
            int guess;

            printf("\nI'm thinking of a number between 1 and 100. Can you guess what it is?\n");

            do {
                scanf("%d", &guess);

                if(guess < answer)
                    printf("Too low! Try again.\n");
                else if(guess > answer)
                    printf("Too high! Try again.\n");
                else
                    printf("Congratulations! You guessed correctly!\n");

            } while(guess != answer);

            break;

        case 2:
            // Generate two random numbers between 1 and 6
            int roll1 = rand() % 6 + 1;
            int roll2 = rand() % 6 + 1;

            printf("\nYou rolled a %d and a %d for a total of %d\n", roll1, roll2, roll1+roll2);

            break;

        case 3:
            printf("\nThank you for playing! Goodbye!\n");
            exit(0);

        default:
            printf("\nInvalid choice. Please choose a valid option.\n");
            break;
    }

    return 0;
}