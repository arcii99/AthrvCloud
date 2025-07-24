//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int guess, num, attempts=0;
    srand(time(0));
    num = rand()%100+1;

    printf("\n\nWelcome to the Number Guessing Game!\n\n");
    printf("You have 10 attempts to guess the number between 1 and 100.\n");
    printf("Good Luck!\n\n");

    do{
        printf("Attempt %d: ", attempts+1);
        scanf("%d", &guess);
        attempts++;

        if(guess==num){
            printf("\nCongratulations! You guessed the number in %d attempts.\n\n", attempts);
            return 0;
        }
        else if(guess<num){
            printf("The number is greater than %d. Try Again!\n\n", guess);
        }
        else{
            printf("The number is less than %d. Try Again!\n\n", guess);
        }

    }while(attempts<10);

    printf("\nGame Over! You failed to guess the number in 10 attempts.\n");
    printf("The number was %d. Better Luck Next Time!\n\n", num);

    return 0;
}