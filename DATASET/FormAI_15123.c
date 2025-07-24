//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 5

int main() {
    int number, guess, tries = 0;
    
    srand(time(NULL));
    number = rand() % 100 + 1;
    
    printf("\nWelcome to Guess the Number Game!");
    printf("\n--------------------------------\n");
    printf("\nYou have %d tries to guess the number between 1 to 100.\n", MAX_GUESSES);
    
    while(tries < MAX_GUESSES) {
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        tries++;
        
        if(guess == number) {
            printf("\nCongratulations! You guessed the number in %d tries.\n", tries);
            return 0;
        } else if(guess < number) {
            printf("\nSorry, your guess is too low.");
        } else {
            printf("\nSorry, your guess is too high.");
        }
        
        printf(" You have %d try/tries left.", MAX_GUESSES-tries);
    }
    
    printf("\n\nSorry, you have used all your tries. The number was %d.\n", number);
    return 0;
}