//FormAI DATASET v1.0 Category: Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to my game, let's have some fun!\n");
    printf("----------------------------------------\n");

    srand(time(NULL));

    int secret_number = rand() % 100;
    int guess, num_guesses = 0;

    while (1)
    {
        printf("Guess the secret number (between 0 and 99): ");
        scanf("%d", &guess);
        num_guesses++;

        if (guess == secret_number)
        {
            printf("You Win! Congratulation, you have guessed the number in %d tries.\n", num_guesses);
            break;
        }
        else if (guess < secret_number)
        {
            printf("Too Low!\n");
        }
        else
        {
            printf("Too High!\n");
        }
    }
    return 0;
}