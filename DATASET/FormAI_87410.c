//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    // Initialize game variables
    int num1, num2, num3, guess;
    bool gameOver = false;
    srand(time(NULL));
    num1 = rand() % 10;
    num2 = rand() % 10;
    num3 = rand() % 10;

    // Print instructions
    printf("Welcome to the puzzling game!\nThe goal of the game is to guess the three-digit code.\nEach digit is between 0 and 9, and is randomly generated.\nYou have 10 attempts to guess the code.\nGood luck!\n");

    // Start game loop
    for(int i = 0; i < 10; i++) {
        printf("Attempt %d: ", i+1);
        scanf("%d", &guess);

        // Check number of correct digits
        int correct = 0;
        if(guess / 100 == num1) correct++;
        if((guess / 10) % 10 == num2) correct++;
        if(guess % 10 == num3) correct++;

        printf("You guessed %d correct digits.\n", correct);

        // Check if game is over
        if(correct == 3) {
            printf("Congratulations, you guessed the code!\n");
            gameOver = true;
            break;
        }
    }

    // Print game over message and correct code
    if(!gameOver) printf("Game over, you did not guess the code.\nThe correct code was %d%d%d.\n", num1, num2, num3);

    return 0;
}