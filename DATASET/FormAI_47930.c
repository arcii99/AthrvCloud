//FormAI DATASET v1.0 Category: Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL)); //seed the rand function with the current time
    int number = rand() % 100; //generate a random number between 0 and 99
    int guess;
    int attempts = 0;
    printf("Welcome to the Guess the Number game!\n");
    printf("I'm thinking of a number between 0 and 99.\n");
    printf("Can you guess what it is?\n");

    do{
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        if(guess < number){
            printf("Too low! Try again.\n");
        }else if(guess > number){
            printf("Too high! Try again.\n");
        }else{
            printf("Congratulations! You guessed the number in %d attempts!\n", attempts);
        }
    }while(guess != number);

    return 0;
}