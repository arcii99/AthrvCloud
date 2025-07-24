//FormAI DATASET v1.0 Category: Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int secret_number, guess, tries = 1;
    srand(time(NULL));
    secret_number = rand() % 100 + 1;

    printf("*** Welcome to Guess the Number game! ***\n");
    printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");

    do{
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess < secret_number){
            printf("Too low, try again!\n");
            tries++;
        }
        else if(guess > secret_number){
            printf("Too high, try again!\n");
            tries++;
        }
        else{
            printf("\nCongratulations! You guessed it in %d tries!\n\n", tries);
        }

    }while(guess != secret_number);

    return 0;
}