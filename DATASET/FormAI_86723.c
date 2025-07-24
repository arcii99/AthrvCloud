//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Shocker Game!\n");
    printf("The rules of the game are simple: we will give you a number and you have to guess it within a certain number of attempts.\n");
    printf("Get ready to be shocked!\n\n");

    int shockNumber;
    int guessCount = 0;
    int maxGuesses = 5;
    int guess;

    srand(time(NULL));
    shockNumber = rand() % 30;

    printf("We have selected a number between 0 and 30. You have %d attempts.\n", maxGuesses);

    while(guessCount < maxGuesses){
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        guessCount++;

        if(guess == shockNumber){
            printf("\nCongratulations! You have guessed the shocking number in %d attempts.\n", guessCount);
            return 0;
        }else if(guess < shockNumber){
            printf("Too low! You have %d attempts left.\n", maxGuesses - guessCount);
        }else{
            printf("Too high! You have %d attempts left.\n", maxGuesses - guessCount);
        }
    }

    printf("\nOh no! You have used up all your attempts. The shocking number was %d. Better luck next time!\n", shockNumber);

    return 0;
}