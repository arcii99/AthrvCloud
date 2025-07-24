//FormAI DATASET v1.0 Category: Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed random number generator
    
    printf("Welcome to the Wacky Number Game!\n\n");
    printf("In this game, you will be guessing a random number between 1 and 100.\n");
    printf("But it's not that simple! You will have to do it while wearing a silly hat.\n\n");
    
    int guess;
    int attempts = 0;
    int secret_number = rand() % 100 + 1; // generate secret number
    
    printf("Put on your silly hat and let's get started!\n\n");
    
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        if (guess < 1 || guess > 100) {
            printf("That's not a valid guess, silly. Try again.\n\n");
            continue;
        }
        
        attempts++;
        
        if (guess == secret_number) {
            printf("Congratulations! You guessed the secret number in %d attempts while wearing a silly hat!\n", attempts);
            break;
        } else if (guess < secret_number) {
            printf("Higher, higher! Try again.\n\n");
        } else {
            printf("Lower, lower! Try again.\n\n");
        }
    }
    
    printf("Thanks for playing the Wacky Number Game! Don't forget to take off your silly hat.\n");
    
    return 0;
}