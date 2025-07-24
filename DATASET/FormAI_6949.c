//FormAI DATASET v1.0 Category: Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int target, guess, attempts = 0; 
    srand(time(NULL)); // seeds the random number generator with the current time
    
    printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n");
    target = rand() % 100 + 1; // generates a random number between 1 and 100
    
    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess == target) {
            printf("Congratulations! You guessed the number %d in %d attempts.\n", target, attempts);
            break; // exit the loop if the guess is correct
        } else if (guess < target) {
            printf("Your guess is too low. Try again.\n");
        } else {
            printf("Your guess is too high. Try again.\n");
        }
    }
    
    return 0; // end the program
}