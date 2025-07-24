//FormAI DATASET v1.0 Category: Math exercise ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secret[5];
    srand(time(NULL));
    int i, j, k, guess[5], correct_color, correct_position;
    for (i = 0; i < 5; i++)
    {
        secret[i] = rand() % 10;
    }
    printf("Welcome to the paranoid math exercise program!\n");
    printf("I have generated a secret code consisting of 5 numbers between 0 and 9.\n");
    printf("Your job is to guess the code by entering 5 numbers between 0 and 9.\n");
    printf("You have 10 chances to guess the correct code.\n");
    for (i = 0; i < 10; i++)
    {
        printf("Enter your guess: ");
        scanf("%1d%1d%1d%1d%1d", &guess[0], &guess[1], &guess[2], &guess[3], &guess[4]);
        correct_color = 0;
        correct_position = 0;
        for (j = 0; j < 5; j++)
        {
            for (k = 0; k < 5; k++)
            {
                if (guess[j] == secret[k])
                {
                    correct_color++;
                    if (j == k)
                    {
                        correct_position++;
                    }
                }
            }
        }
        printf("You got %d colors correct and %d in the correct position.\n", correct_color, correct_position);
        if (correct_position == 5)
        {
            printf("Congratulations! You have guessed the correct code!\n");
            return 0;
        }
    }
    printf("You have failed to guess the code within 10 attempts.\n");
    printf("The correct code was %d%d%d%d%d.\n", secret[0], secret[1], secret[2], secret[3], secret[4]);
    return 0;
}