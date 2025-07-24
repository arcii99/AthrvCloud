//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    char name[20];
    int i, num, guess, attempts, playAgain;
    
    printf("Welcome to the Number Guessing Game!\n");
    printf("What's your name?\n");
    scanf("%s", name);
    printf("Hi %s! I'm thinking of a number between 1 and 100. Can you guess what it is?\n", name);
    
    srand(time(0)); //Seed random number generator
    num = rand() % 100 + 1; //Generate random number
    
    do {
        attempts = 0; //Reset attempts for each round
        do {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            attempts++; //Increment attempts
            if (guess > num) {
                printf("Too high! Try again.\n");
            } else if (guess < num) {
                printf("Too low! Try again.\n");
            }
        } while (guess != num && attempts < 10); //Keep guessing until correct or ran out of attempts
        
        if (guess == num) {
            printf("Congratulations %s, you got it in %d attempt(s)! Do you want to play again? (1 for yes, 0 for no)\n", name, attempts);
        } else {
            printf("Sorry %s, you ran out of attempts. The number was %d. Do you want to play again? (1 for yes, 0 for no)\n", name, num);
        }
        
        scanf("%d", &playAgain); //Check if user wants to play again
        if (playAgain == 1) {
            printf("Okay, let's play again!\n");
            num = rand() % 100 + 1; //Generate new random number
        }
    } while (playAgain == 1);
    
    printf("Thanks for playing %s! Goodbye.\n", name);
    
    return 0; //End program
}