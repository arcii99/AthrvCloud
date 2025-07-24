//FormAI DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(0)); //seed for random number

    int num = rand() % 10; // generate a random number between 0-9
    int guess;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I am thinking of a number between 0 and 9. Can you guess what it is?\n");

    for(int i = 0; i < 3; i++) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess == num) {
            printf("Congratulations! You guessed the correct answer!\n");
            return 0;
        }
        else if(guess < num) {
            printf("Oops! Your guess is too low. Please try again.\n");

            if(i == 2) {
                printf("Sorry, you have exhausted your attempts.\n");
                return 1; // example of error handling
            }
        }
        else if(guess > num) {
            printf("Oops! Your guess is too high. Please try again.\n");

            if(i == 2) {
                printf("Sorry, you have exhausted your attempts.\n");
                return 1; // example of error handling
            }
        }

    }

    return 0;
}