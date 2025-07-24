//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int randomNumber, guess, attempts = 0;
    
    srand(time(NULL));
    randomNumber = rand()%100 + 1;

    printf("Welcome to the Guessing Game!\n");
    printf("**************************************\n");
    printf("You have to guess a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess < randomNumber) {
            printf("Your guess is too low. Try again.\n");
        }
        else if(guess > randomNumber) {
            printf("Your guess is too high. Try again.\n");
        }

        attempts++;
    } while(guess != randomNumber);

    printf("Congratulations! You guessed the number in %d attempts.\n", attempts);

    return 0;
}