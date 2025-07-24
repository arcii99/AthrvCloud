//FormAI DATASET v1.0 Category: Game ; Style: surprised
// Oh wow, I can't believe I just came up with this amazing game!
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess, attempts = 1;
    printf("Welcome to my unique number guessing game!\n");
    printf("I have randomly generated a number between 1 and 100.\n");
    printf("Can you guess what it is?\n\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if(guess < number) {
            printf("Too low, try again!\n\n");
            attempts++;
        } else if(guess > number) {
            printf("Too high, try again!\n\n");
            attempts++;
        } else {
            printf("\nCongratulations! You guessed the number in %d attempts!\n", attempts);
        }
        
    } while(guess != number);

    printf("\nThank you for playing my game, you are amazing!\n");
    return 0;
}