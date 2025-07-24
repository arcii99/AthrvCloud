//FormAI DATASET v1.0 Category: Game ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num, guess, attempts = 0;
    srand(time(0)); // to get a different number each time the game is played
    num = rand() % 100 + 1; // generates a random number between 1 and 100
    printf("Welcome to the Number Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100, try to guess it.\n\n");

    do {
        // prompting the user to enter a guess
        printf("Enter your guess:\n");
        scanf("%d", &guess);
        attempts++; // incrementing the number of attempts
        // checking if user's guess is correct, too high or too low
        if(guess > num) {
            printf("Too High. Try guessing a smaller number.\n\n");
        }
        else if(guess < num) {
            printf("Too Low. Try guessing a larger number.\n\n");
        }
        else {
            printf("Congratulations! You guessed the right number in %d attempts!\n", attempts);
        }
    } while(guess != num); // loop until user guesses the right number

    return 0; // program execution successful
}