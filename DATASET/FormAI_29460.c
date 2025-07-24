//FormAI DATASET v1.0 Category: Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int guess, num, tries=0;
    srand(time(0)); //seeds the random number generator
    num = rand() % 100 + 1; //generates a random number between 1 and 100
    printf("\nWelcome to the Number Guessing Game!\n");
    printf("Try to guess the number between 1 and 100 in the fewest number of tries.\n\n");

    do{
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;
        if(guess > num){
            printf("Too high! Try again.\n\n");
        }
        else if(guess < num){
            printf("Too low! Try again.\n\n");
        }
        else{
            printf("\nCongratulations! You guessed the number in %d tries!\n", tries);
        }
    }while(guess != num);

    return 0;
}