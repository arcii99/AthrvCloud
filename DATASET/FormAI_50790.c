//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random number between 1 and 100
int getRandomNumber() {
    srand(time(NULL));
    int random = rand() % 100 + 1;
    return random;
}

int main() {
    int randomNumber = getRandomNumber();
    int guess, count = 0;

    // Introduction of the game
    printf("Welcome to the Guessing Game!\n");
    printf("You have to guess a random number between 1 and 100. You have 5 tries.\n\n");

    //Loop through each try
    while (count < 5) {
        printf("Guess #%d: ", count+1);
        scanf("%d", &guess);

        //If the guess is correct, exit the program
        if (guess == randomNumber) {
            printf("\nCongratulations! You have guessed the correct number!\n");
            return 0;
        }
        
        // If the guess is higher, ask user to guess a lower number
        else if (guess > randomNumber) {
            printf("Too high! Guess a lower number.\n");
        }
        
        // If the guess is lower, ask user to guess a higher number
        else {
            printf("Too low! Guess a higher number.\n");
        }

        count++;
    }

    //If guesses exceeded limit, end the game
    printf("\nGame over! You exceeded the maximum number of guesses.\n");
    printf("The correct number was %d\n", randomNumber);

    return 0;
}