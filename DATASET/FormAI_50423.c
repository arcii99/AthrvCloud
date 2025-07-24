//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0));
    int num, guess, tries=0;
    char choice;
    printf("Welcome to Shape-Shifter Game!\n");
    printf("In this game, the number you have to guess will keep shifting its shape!\n");
    printf("Do you want to play? (y/n): ");
    scanf("%c", &choice);
    while(choice=='y'){
        num = rand()%100 + 1;
        while(guess!=num){
            printf("Guess the number (1-100): ");
            scanf("%d", &guess);
            if(guess<num){
                printf("The number has shifted and become larger!\n");
                tries++;
            }
            else if(guess>num){
                printf("The number has shifted and become smaller!\n");
                tries++;
            }
            else{
                printf("Congratulations! You guessed it right in %d tries!\n", tries);
                printf("Do you want to play again? (y/n): ");
                scanf("%*c%c", &choice); //To clear the input buffer before getting choice
                tries = 0;
            }
        }
    }
    printf("Thanks for playing Shape-Shifter Game!\n");
    return 0;
}