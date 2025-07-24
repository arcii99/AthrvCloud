//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int secret_number = rand() % 100 + 1; // Generate a secret number between 1 to 100
    int guess, tries = 0;

    printf("\nWelcome to the Guessing Game! Please guess a number between 1 and 100: ");

    do{
        scanf("%d", &guess);
        tries++;

        if(guess > secret_number){
            printf("Too high! Guess lower.\n");
        }
        else if(guess < secret_number){
            printf("Too low! Guess higher.\n");
        }
        else{
           printf("Congratulations! You guessed the secret number in %d tries.\n", tries);
           break;
        }

        printf("Try again: ");
    } while(guess != secret_number);

    return 0;
}