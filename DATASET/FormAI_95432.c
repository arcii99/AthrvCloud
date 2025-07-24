//FormAI DATASET v1.0 Category: Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int guess, number, attempts = 0;
    srand(time(0));
    number = rand() % 100 + 1;
    printf("\t\t***Welcome to the Number Guessing Game***\n");
    printf("Guess a number between 1 and 100: ");
    do{
        scanf("%d", &guess);
        attempts++;
        if(guess > number){
            printf("You guessed too high! Try Again\n");
        }else if(guess < number){
            printf("You guessed too low! Try Again\n");
        }else{
            printf("\n\nCongratulations! You guessed the number in %d attempt(s).\n", attempts);
            break;
        }
    }while(guess != number);
    return 0;
}