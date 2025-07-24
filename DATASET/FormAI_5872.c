//FormAI DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess, guess_count = 0;
    time_t t;
    srand((unsigned) time(&t));
    secret_number = rand() % 50 + 1;
    
    printf("Welcome to the Guessing Game!\n");
    printf("Can you guess the secret number between 1 and 50?\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guess_count++;
        
        if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the secret number in %d tries.\n", guess_count);
        }
    } while (guess != secret_number);

    return 0;
}