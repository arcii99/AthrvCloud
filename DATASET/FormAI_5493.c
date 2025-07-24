//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // initializes random seed using time
    
    printf("Welcome to the Guessing Game!\n");
    printf("I am thinking of a number between 1 and 100.\n");
    
    int correct_number = rand() % 100 + 1; // generates random number
    
    int guess;
    int num_guesses = 0;
    
    do{
        printf("Guess the number: ");
        scanf("%d", &guess);
        num_guesses++;
        
        if(guess < correct_number){
            printf("Too low! Guess higher.\n");
        } else if(guess > correct_number){
            printf("Too high! Guess lower.\n");
        } else{
            printf("Congratulations! You guessed the number in %d attempts.\n", num_guesses);
        }
        
    } while(guess != correct_number);
    
    
    return 0;
}