//FormAI DATASET v1.0 Category: Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int secret_number = rand() % 100 + 1;
    int guess, attempts = 0;

    printf("Welcome to the guessing game!\n\n");
    printf("I am thinking of a number between 1 and 100. Can you guess it?\n");
    
    while(1) {
        printf("Enter your guess (between 1 and 100): ");
        scanf("%d", &guess);
        attempts++;
        
        if (guess < 1 || guess > 100) {
            printf("Your guess is out of range! Please try again.\n");
            continue;
        }
        
        if (guess == secret_number) {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }

    return 0;
}