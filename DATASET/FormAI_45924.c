//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function to get random number between low and high inclusive.
int get_random_num(int low, int high){
    return rand() % (high - low + 1) + low;
}

int main(){
    srand(time(NULL)); // Seed the random number generator with current time.
    int num_guesses = 0;
    int num_to_guess = get_random_num(1,100); // Generate a random number between 1 and 100.
    printf("I am thinking of a number between 1 and 100. Can you guess what it is?\n");
    bool is_game_over = false;
    while(!is_game_over){
        int guess;
        printf("Guess #%d: ", num_guesses+1);
        scanf("%d", &guess);
        if(guess < 1 || guess > 100){
            printf("Invalid input. Please enter a number between 1 and 100.\n");
            continue; // Ask for input again.
        }
        if(guess == num_to_guess){
            num_guesses++;
            printf("Congratulations! You guessed the number in %d tries!\n", num_guesses);
            is_game_over = true;
        } else {
            num_guesses++;
            if(guess < num_to_guess){
                printf("Too low. Try again.\n");
            } else {
                printf("Too high. Try again.\n");
            }
        }
    }
    return 0; // End of game.
}