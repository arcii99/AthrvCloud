//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int score = 0, answer, guess;
    srand(time(NULL));
    printf("Welcome to Donald Knuth's Guessing Game!\n\n");
    printf("Here's how to play:\n");
    printf("1. I will generate a random number between 1 and 100.\n");
    printf("2. You will have to guess the number.\n");
    printf("3. If you guess the number correctly, you will earn 10 points.\n");
    printf("4. If you guess wrong, you will lose 5 points.\n");
    printf("5. You have 10 guesses.\n\n");
    printf("Let's get started!\n\n");

    for (int i = 0; i < 10; i++) {
        int num = rand() % 100 + 1;
        printf("Guess #%d: ", i+1);
        scanf("%d", &guess);
        if (guess == num) {
            printf("Congratulations! You guessed the correct number and earned 10 points!\n\n");
            score += 10;
        }
        else {
            printf("Sorry, the correct number was %d. You lose 5 points.\n\n", num);
            score -= 5;
        }
    }

    printf("Your final score is: %d\n", score);

    if (score >= 50) {
        printf("Great job! You have won the game!\n");
    }
    else {
        printf("Sorry, you did not earn enough points to win the game.\n");
    }
    return 0;
}