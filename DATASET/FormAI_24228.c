//FormAI DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Set seed for rand()

    printf("Guess the Number!\n");
    printf("You have only 7 attempts to guess the number between 1 and 100\n");
    
    int randomNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    while(attempts < 7){
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        if(guess == randomNumber) {
            printf("Congratulations! You guessed the number in %d attempts\n", attempts+1);
            return 0;
        } else if(guess > randomNumber) {
            printf("Your guess is too high. Try again.\n");
        } else {
            printf("Your guess is too low. Try again.\n");
        }

        attempts++;
    }
    printf("Sorry! The number was %d. Better luck next time.\n", randomNumber);

    return 0;
}