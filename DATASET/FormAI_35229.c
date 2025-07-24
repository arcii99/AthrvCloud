//FormAI DATASET v1.0 Category: Game ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));
    int guess, number, tries = 0, maxTries = 10;
    number = rand() % 100 + 1;
    printf("Welcome to the Number Guessing Game!\n");
    printf("Guess the number between 1 and 100. You have %d tries.\n", maxTries);
    do{
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;
        if(guess > number){
            printf("Your guess is too high. Try again.\n");
        }else if(guess < number){
            printf("Your guess is too low. Try again.\n");
        }else{
            printf("Congratulations! You guessed the number in %d tries.\n", tries);
            return 0;
        }
    }while(tries < maxTries);
    printf("Game over. The number was %d\n", number);
    return 0;
}