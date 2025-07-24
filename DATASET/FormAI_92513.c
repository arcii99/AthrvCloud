//FormAI DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess, rand_num, num_guesses = 0;
    srand(time(NULL));  // seed for random number generator
    rand_num = rand() % 100 + 1;  // generates random number between 1 and 100
    printf("Welcome to the Guessing Game! You have 7 attempts to guess the randomly generated number between 1 and 100. Good luck!\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;
        if (guess > rand_num) {
            printf("Too high. Try again.\n\n");
        }
        else if (guess < rand_num) {
            printf("Too low. Try again.\n\n");
        }
        else {
            printf("Congratulations! You guessed the correct number in %d attempts!\n", num_guesses);
            return 0;
        }
    } while (num_guesses < 7);

    printf("Sorry, you have used up all your attempts. The number to guess was %d.", rand_num);
    return 0;
}