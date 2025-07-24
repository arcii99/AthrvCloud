//FormAI DATASET v1.0 Category: Random ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
    int i, random_num;
    char play_again = 'y';

    printf("Welcome to the Random Number Game!\n\n");

    while(play_again == 'y'){
        printf("I am thinking of a number between 1 and 100. Can you guess it?\n\n");

        random_num = rand() % 100 + 1;

        for(i=1; i<=10; i++){
            int guess;
            printf("Guess #%d: ", i);
            scanf("%d", &guess);

            if(guess < random_num){
                printf("Too low! Guess again.\n");
            }
            else if(guess > random_num){
                printf("Too high! Guess again.\n");
            }
            else{
                printf("Congratulations! You guessed the number in %d guesses.\n", i);
                break;
            }
        }

        if(i > 10){
            printf("Game over! The number was %d.\n", random_num);
        }

        printf("\nDo you want to play again? (y/n)\n\n");
        scanf(" %c", &play_again);

    }

    return 0;
}