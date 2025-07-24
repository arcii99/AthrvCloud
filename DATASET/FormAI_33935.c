//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// Recursive function
void play_game(int guess, int answer, int num_guesses) {
    // Base case
    if (guess == answer) {
        printf("Congratulations! You guessed the number in %d tries\n", num_guesses);
        return;
    }
    
    // Recursive case
    if (guess < answer) {
        printf("Too low, try again: ");
    } else {
        printf("Too high, try again: ");
    }
    
    scanf("%d", &guess);
    play_game(guess, answer, num_guesses+1);
}

int main() {
    // Generate random number
    srand(time(0));
    int answer = rand() % 100 + 1;
    
    // Prompt user to enter guess
    int guess;
    printf("Guess the number (between 1 to 100): ");
    scanf("%d", &guess);
    
    // Call recursive function
    play_game(guess, answer, 1);
    
    return 0;
}