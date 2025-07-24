//FormAI DATASET v1.0 Category: Table Game ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* This program is a dynamic table game in which the user needs to guess
a randomly generated number within a certain number of attempts */

int main(){
    int num, guess, num_guesses = 0;
    int max_guesses = 5; // Maximum number of attempts
    
    srand(time(0)); // Random seed
    
    num = rand()%100 + 1; // Random number between 1 and 100
    
    printf("Welcome to the Guessing Game!\n");
    printf("You need to guess a number between 1 and 100 within %d attempts.\n", max_guesses);
    
    while(num_guesses < max_guesses){
        printf("Guess %d: ", num_guesses+1);
        scanf("%d", &guess);
        
        if(guess == num){
            printf("Congratulations, you guessed the number in %d attempts!\n", num_guesses+1);
            return 0; // Game over
        }
        else if(guess < num){
            printf("Too low, try again.\n");
        }
        else{
            printf("Too high, try again.\n");
        }
        
        num_guesses++; // Increment the number of guesses
    }
    
    printf("Sorry, you ran out of attempts. The number was %d.\n", num);

    return 0;
}