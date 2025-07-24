//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initialize rand function with current time
    int guess, num, max_range = 10, attempts = 0; 

    printf("\nWelcome to the Guessing Game!\n");
    printf("You have 5 attempts to guess the number between 1 and %d.\n", max_range);

    num = rand() % max_range + 1; // Generate random number

    while(attempts < 5){
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if(guess == num){
            printf("\nCongratulations! You guessed the number in %d attempts.\n", attempts);
            return 0;
        }
        else{
            if(attempts == 5){
                printf("\nGame over! The number was %d.\n", num);
                return 0;
            }
            else if(guess < num){
                printf("\nSorry, your guess is too low. Please try again.\n");
            }
            else{
                printf("\nSorry, your guess is too high. Please try again.\n");
            }
        }
    }

    return 0;
}