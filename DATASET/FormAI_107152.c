//FormAI DATASET v1.0 Category: Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secret_num, guess, num_guesses = 0;
    srand(time(0));
    secret_num = rand() % 100 + 1;
    
    printf("Let's play a game! I am thinking of a number between 1 and 100. You have to guess what that number is.\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        num_guesses++;
        
        if (guess > secret_num) {
            printf("Too high! Guess again.\n");
        } else if (guess < secret_num) {
            printf("Too low! Guess again.\n");
        } else {
            printf("Congratulations! You guessed the secret number in %d tries.\n", num_guesses);
        }
    } while (guess != secret_num);
    
    return 0;
}