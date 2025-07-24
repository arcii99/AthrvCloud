//FormAI DATASET v1.0 Category: Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num, guess, tries=0;

    srand(time(0)); //Generate new random number each time program is run
    num = rand() % 100 + 1; //Generate random number between 1-100

    printf("\n\n\t*****Welcome to the Number Guessing Game*****\n\n");
    printf("Instructions: Guess a number between 1-100.\n");
    printf("You have 10 tries to guess the number.\n");

    do{
        printf("\nEnter Guess (Try %d): ", tries+1);
        scanf("%d", &guess);

        if(guess>num){
            printf("Sorry, %d is too high. Try again.\n\n", guess);
        }
        else if(guess<num){
            printf("Sorry, %d is too low. Try again.\n\n", guess);
        }
        tries++;
    }while(guess!=num && tries<10);

    if(guess==num){
        printf("\n\n\t*****Congratulations! You guessed the number in %d tries.*****\n\n", tries);
    }
    else{
        printf("\n\n\t*****Sorry, you have exceeded the maximum number of tries. The number was %d.*****\n\n", num);
    }

    return 0;
}