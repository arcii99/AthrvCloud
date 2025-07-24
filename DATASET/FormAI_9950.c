//FormAI DATASET v1.0 Category: Scientific ; Style: lively
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the 'Mystery Number' game!\n");
    printf("In this game, you'll have to guess a number between 0 and 1000\n");
    printf("You have 10 chances to get it right!\n");

    int random_num = rand() % 1001; // generate a random number between 0 and 1000
    int guess_count = 0; //keep track of guess count
    int user_guess;

    while(guess_count <= 10){
        printf("\nEnter your guess: ");
        scanf("%d", &user_guess);

        if(user_guess == random_num){
            printf("\nCongratulations! You guessed it right!\n");
            break;
        } else if(user_guess > random_num) {
            printf("A good guess but too high!\n");
        } else if(user_guess < random_num){
            printf("A good guess but too low!\n");
        }

        guess_count++;
        printf("You have %d more guesses left.\n", 10-guess_count);

        if(guess_count == 10){
            printf("\nSorry, you've reached the maximum number of guesses. The mystery number was %d.\n", random_num);
        }
    }

    return 0;
}