//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_TRIES 5 // Maximum number of attempts allowed
#define MAX_NUMBER 100 // Maximum number in range

int main(){
    int guess, number, try_count=0;
    srand(time(0)); // Seed for random number generator
    number = rand()%MAX_NUMBER + 1; // Generate random number
    
    printf("\nGuess the Number!\n\n");
    printf("You have %d attempts to guess the number between 1 and %d.\n", MAX_TRIES, MAX_NUMBER);
    
    do{
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        try_count++; // Increase attempt count
        if(guess > number){
            printf("Too high!\n");
        }
        else if(guess < number){
            printf("Too low!\n");
        }
        else{
            printf("Congratulations! You guessed the number in %d attempts.\n", try_count);
            return 0; // End program
        }
    }while(try_count < MAX_TRIES);
    
    printf("Sorry, you have used all your attempts. The number was %d.\n", number);
    
    return 0;
}