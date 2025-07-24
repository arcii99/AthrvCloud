//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int random_num, guess_num, num_attempts = 0;
    srand(time(NULL));

    printf("Welcome to the Guess the Number game!\n");
    printf("I have a random number between 1 and 100. Can you guess it?\n");

    random_num = rand() % 100 + 1;

    do
    {
        printf("Enter your guess (1-100): ");
        scanf("%d", &guess_num);
        num_attempts++;

        if(guess_num > random_num)
            printf("Too high! Guess again.\n");
        else if(guess_num < random_num)
            printf("Too low! Guess again.\n");
    } while(guess_num != random_num);

    printf("Congratulations! You guessed the number in %d attempts!\n", num_attempts);

    return 0;
}