//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int guess, guess_count = 0, num, option;
    srand(time(0));  //initialize random seed
    
    printf("Welcome to the Guessing Game!\n");
    printf("Enter 1 to play or 2 to exit.\n");
    scanf("%d", &option);
    
    if(option == 1) {
        printf("Guess a number between 1 and 100.\n");
        num = rand() % 100 + 1;     //random number between 1 and 100
        do {
            scanf("%d", &guess);
            guess_count++;
            if(guess > num) {
                printf("Too high! Guess again.\n");
            }
            else if(guess < num) {
                printf("Too low! Guess again.\n");
            }
            else {
                printf("Congratulations! You guessed the number in %d tries.\n", guess_count);
                break;
            }
        } while(guess != num);
    }
    else if(option == 2) {
        printf("Thank you for playing! Goodbye.\n");
    }
    else {
        printf("Invalid option. Please try again.\n");
    }
    
    return 0;
}