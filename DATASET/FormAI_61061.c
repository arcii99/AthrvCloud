//FormAI DATASET v1.0 Category: Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Function to generate a random number between a and b
int random_int(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize variables
    int secret_number = random_int(1, 100);
    int guess;
    int guess_count = 0;
    const int max_guesses = 5;

    // Welcome the user, but don't give away any information
    printf("Hello. I'm just a simple computer program. Nothing to see here.\n");
    printf("Please enter your guess (between 1 and 100): ");

    // Game loop
    while (guess_count < max_guesses) {
        scanf("%d", &guess);
        
        // Check if the guess is correct
        if (guess == secret_number) {
            printf("You win! But don't get too excited, I'm always watching.\n");
            break;
        } else if (guess < secret_number) {
            printf("Too low. Keep trying, I'm sure you'll get there eventually.\n");
        } else {
            printf("Too high. I know you can do better than that!\n");
        }
        
        // Ask for another guess
        guess_count++;
        printf("You have %d guesses left: ", max_guesses - guess_count);
    }

    // The user loses if they run out of guesses
    if (guess_count == max_guesses) {
        printf("You lose. Better luck next time, or not. Who knows what I'm planning?\n");
    }

    return 0;
}