//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10
#define MAX_NUMBER 100

int main(){
    int number, guess, num_guesses = 0;
    
    // generate random number between 1 and MAX_NUMBER
    srand(time(NULL));
    number = rand() % MAX_NUMBER + 1;
    
    printf("Welcome to Guess the Number game!\n");
    printf("Guess the number between 1 and %d\n", MAX_NUMBER);
    
    do{
        printf("Guess %d: ", num_guesses + 1);
        scanf("%d", &guess);
        num_guesses++;
        
        if(guess == number){
            printf("Congratulations! You guessed the correct number in %d guesses\n", num_guesses);
            return 0;
        }
        else if(guess > number){
            printf("Too high! ");
        }
        else{
            printf("Too low! ");
        }
        
        if(num_guesses == MAX_GUESSES){
            printf("You ran out of guesses. The number was %d\n", number);
            return 0;
        }
        else{
            printf("You have %d guesses left\n", MAX_GUESSES - num_guesses);
        }
    }while(num_guesses < MAX_GUESSES);
    
    return 0;
}