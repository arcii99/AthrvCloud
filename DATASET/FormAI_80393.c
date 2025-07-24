//FormAI DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // seed the random number generator
    
    int secret_number = rand() % 100; // generate a random number from 0 to 99
    
    int guess_number;
    int attempts = 0;
    
    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between 0 and 99.\n");
    
    while (attempts < 5) { // give the player 5 attempts to guess the number
        printf("Guess the number: ");
        scanf("%d", &guess_number);
        
        if (guess_number < 0 || guess_number > 99) { // check if the guess is out of bounds
            printf("Your guess is out of bounds! Please guess a number between 0 and 99.\n");
            continue; // skip the rest of the loop and start again
        }
        
        if (guess_number == secret_number) { // check if the guess is correct
            printf("Congratulations, you guessed the number in %d attempts!\n", attempts+1);
            break; // exit the loop
        }
        
        attempts++; // increment the number of attempts
        
        if (guess_number < secret_number) {
            printf("Sorry, your guess is too low.\n");
        } else {
            printf("Sorry, your guess is too high.\n");
        }
        
        printf("You have %d attempts left.\n", 5 - attempts);
    }
    
    if (attempts == 5) { // if the player used all 5 attempts without guessing the number
        printf("Game over! The secret number was %d.\n", secret_number);
    }
    
    return 0;
}