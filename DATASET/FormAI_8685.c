//FormAI DATASET v1.0 Category: Game ; Style: surprised
#include<stdio.h>

int main(){
    printf("Wow, I can't believe I coded this game!\n");
    printf("Welcome to my C Game\n");
    int guessCount = 0;
    int guessLimit = 3;
    int secretNum = 10;
    int guess;

    while(guess != secretNum && guessCount != guessLimit){
        printf("Guess a number between 1 and 20: ");
        scanf("%d", &guess);
        guessCount++;

        if(guess == secretNum){
            printf("Wow, you guessed it right! Congrats!\n");
        } else if(guess > secretNum){
            printf("You guessed too high\n");
        } else {
            printf("You guessed too low\n");
        }
    }

    if(guessCount == guessLimit){
        printf("Oops, you couldn't guess the number in time. Game Over!\n");
    }
    
    return 0;
}