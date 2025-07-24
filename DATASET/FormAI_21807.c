//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int lives = 3;
    int score = 0;
    char playAgain = 'y';
    while (playAgain == 'y') {
        int answer = rand() % 101;
        int guess;
        printf("*** Guess the number game ***\n");
        printf("You have %d lives left!\n", lives);
        printf("Enter a number between 0 and 100: ");
        scanf("%d", &guess);
        while (guess != answer && lives > 1) {
            if (guess < answer) {
                printf("Too low! Try again.\n");
                printf("Enter a number between 0 and 100: ");
                scanf("%d", &guess);
            }
            else if (guess > answer) {
                printf("Too high! Try again.\n");
                printf("Enter a number between 0 and 100: ");
                scanf("%d", &guess);
            }
            lives--;
            printf("You have %d lives left!\n", lives);
        }
        if (lives == 1) {
            printf("You lose! The correct answer was %d.\n", answer);
        }
        else {
            printf("You win! The correct answer was %d.\n", answer);
            score++;
        }
        printf("Your current score is %d.\n", score);
        printf("Do you want to play again? (y/n) ");
        scanf(" %c", &playAgain);
        while (playAgain != 'y' && playAgain != 'n') {
            printf("Invalid input. Please enter 'y' or 'n': ");
            scanf(" %c", &playAgain);
        }
        lives = 3;
    }
    printf("Thanks for playing! Your final score is %d.\n", score);
    return 0;
}