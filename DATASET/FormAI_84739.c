//FormAI DATASET v1.0 Category: Educational ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    //declaring variables
    int num, count=0, guess;
    srand(time(0)); //generating random seed for number generation
    num = rand()%100 + 1; //generating random number between 1 to 100
    printf("Welcome to Guess the Number Game!\n");
    printf("You have total 5 chances to guess the number!\n");
    //loop for taking 5 guesses
    while(count<5){
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        if(guess<1 || guess>100){ //checking guess range
            printf("Invalid guess! Enter a number between 1 to 100.");
            continue;
        }
        if(guess<num){ //if guess is lesser than number
            printf("Your guess is too low!\n");
            count++;
        }
        else if(guess>num){ //if guess is greater than number
            printf("Your guess is too high!\n");
            count++;
        }
        else{ //if guess is equal to number
            printf("Congratulations! You guessed the number.\n");
            printf("You won the game in %d attempts!", count+1);
            exit(0); //exiting program
        }
    }
    printf("Sorry! You lost the game. The number was %d.", num);
    return 0;
}