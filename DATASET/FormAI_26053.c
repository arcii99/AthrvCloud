//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int score = 0;
    int guess = 0;
    int number_of_guesses = 0;
    int num = rand() % 100 + 1;
    printf("Welcome to Guess the Number!\n\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n\n");

    while (number_of_guesses < 10) {
        printf("Guess %d: ", number_of_guesses + 1);
        scanf("%d", &guess);
        if (guess == num) {
            printf("Congratulations! You guessed the number in %d tries.\n", number_of_guesses + 1);
            printf("Your score is %d.\n", score);
            return 0;
        } else if (guess > num) {
            printf("Too high. Guess lower.\n");
        } else {
            printf("Too low. Guess higher.\n");
        }
        number_of_guesses++;
        score = 10*(10-number_of_guesses);
    }
    printf("Sorry, you ran out of guesses. The number was %d.\n", num);
    printf("Your score is %d.\n", score);
    return 0;
}