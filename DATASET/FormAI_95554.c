//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int MAX_GUESS = 100;
    int NUMBER_OF_GUESSES = 10;
    
    srand(time(NULL)); // seed for random number generator
    int number_to_guess = rand() % MAX_GUESS + 1; // random number between 1 and 100
    int guess;
    int num_guesses = 0; // number of guesses so far
    
    printf("Guess a number between 1 and %d\n", MAX_GUESS);
    
    while(num_guesses < NUMBER_OF_GUESSES){
        printf("Guess #%d: ", num_guesses+1);
        scanf("%d", &guess);
        
        if(guess == number_to_guess){
            printf("Congratulations! You guessed the number in %d guesses.\n", num_guesses+1);
            return 0;
        } else if(guess < number_to_guess) {
            printf("Too low! ");
        } else {
            printf("Too high! ");
        }
        
        if(num_guesses == NUMBER_OF_GUESSES-1){
            printf("You ran out of guesses. The number was %d.\n", number_to_guess);
        }
        
        num_guesses++;
    }
    
    return 0;
}