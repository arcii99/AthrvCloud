//FormAI DATASET v1.0 Category: Error handling ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Set the seed for the random number generator
    int random_number = rand() % 10 + 1; // Generate a random number between 1 and 10

    printf("Guess a number between 1 and 10: ");

    int user_guess;
    scanf("%d", &user_guess);

    if(user_guess == random_number)
    {
        printf("Congratulations! You guessed the correct number.\n");
    }
    else if(user_guess < 1 || user_guess > 10) // Error handling for input out of range
    {
        printf("Error: Your guess was out of range (1 - 10).\n");
    }
    else // Error handling for incorrect guess
    {
        printf("Sorry, your guess was incorrect. The correct number was %d.\n", random_number);
    }
    
    return 0;
}