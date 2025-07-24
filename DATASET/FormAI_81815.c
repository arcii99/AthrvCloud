//FormAI DATASET v1.0 Category: System administration ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int num = rand() % 100 + 1; //generating a random number between 1 and 100
    int guess, attempts = 0;
    printf("Welcome to the number guessing game!\n");
    printf("You have 5 attempts to guess a number between 1 and 100.\n");
    
    while(attempts < 5) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        
        if(guess < 1 || guess > 100) {
            printf("Invalid guess. Please enter a number between 1 and 100.\n");
            continue;
        }
        
        attempts++;
        
        if(guess == num) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            return 0;
        } else if(guess < num) {
            printf("Your guess is too low.\n");
        } else {
            printf("Your guess is too high.\n");
        }
    }
    
    printf("Sorry, you ran out of attempts. The number was %d. Better luck next time!\n", num);
    return 0;
}