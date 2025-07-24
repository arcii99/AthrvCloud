//FormAI DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Number Guessing Game!\n");
    
    srand(time(NULL)); // sets a seed for random number generator
    
    int number_to_guess = rand() % 100; // generates a number between 0-99
    int user_guess;
    int count_guess = 0;
    
    do {
        printf("Guess the number between 0-99: ");
        scanf("%d", &user_guess);
        count_guess++;
        
        if (user_guess < number_to_guess) {
            printf("Too low!\n");
        } else if (user_guess > number_to_guess) {
            printf("Too high!\n");
        } else {
            printf("Congratulations, you guessed the number in %d tries!\n", count_guess);
            break;
        }
        
    } while (1);
    
    return 0;
}