//FormAI DATASET v1.0 Category: Table Game ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int number, guess, nguesses=1;
    srand(time(0));
    number = rand()%100 + 1; //generating random number between 1 to 100

    //game starts here
    printf("\nWelcome to the C Table Game!\n");
    printf("Guess the number between 1 to 100.\n\n");

    //Loop until the number is guessed
    do{
        printf("Enter your guess: ");
        scanf("%d", &guess);
        if(guess<number){
            printf("Your guess is lower than the number. Try again!\n\n");
        }
        else if(guess>number){
            printf("Your guess is greater than the number. Try again!\n\n");
        }
        else{
            printf("\n\n********Congratulations! You guessed the number in %d attempts********\n\n", nguesses);
        }
        nguesses++;
    }
    while(guess!=number);

    return 0;
}