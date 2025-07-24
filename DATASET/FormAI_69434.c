//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int score = 0;
    int guess;
    srand(time(0));
    int number = rand() % 100;
    printf("Welcome to the Number Guessing Game!\n");
    printf("You will get 5 tries to guess a number between 0 and 99.\n");
    printf("Guess the number: ");
    for(int i=1;i<=5;i++){
        scanf("%d",&guess);
        if (guess==number){
            printf("\nCongratulations! You guessed the number.\n");
            printf("Your total score is %d out of 500.\n", score+(i*100));
            return 0;
        }
        else{
            printf("\nIncorrect guess. Try again.\n");
            printf("You have %d guesses left.\n", 5-i);
            if(guess<number){
                printf("The number is higher.\n");
            }
            else{
                printf("The number is lower.\n");
            }
        }
    }
    printf("\nGame Over. You ran out of tries.\n");
    printf("The correct number was %d.\nYour total score is %d out of 500.\n", number, score);
    return 0;
}