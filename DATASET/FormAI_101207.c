//FormAI DATASET v1.0 Category: Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100
#define MAX_GUESSES 10

int main(void) {
    srand(time(0));
    int secret_number = rand() % MAX_NUM + 1;
    int guess_count = 0;
    int guess;
    
    printf("Welcome to the guessing game!\n");
    printf("I'm thinking of a number between 1 and %d.\n", MAX_NUM);
    printf("You have %d guesses.\n", MAX_GUESSES);
    
    while (guess_count < MAX_GUESSES) {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        guess_count++;
        
        if (guess == secret_number) {
            printf("Congratulations! You guessed the number in %d tries.\n", guess_count);
            return 0;
        } else if (guess < secret_number) {
            printf("Too low. ");
        } else {
            printf("Too high. ");
        }
        
        printf("You have %d guesses left.\n", MAX_GUESSES - guess_count);
    }
    
    printf("Sorry, you ran out of guesses. The number was %d.\n", secret_number);
    return 0;
}