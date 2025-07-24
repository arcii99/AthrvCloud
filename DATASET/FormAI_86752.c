//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game() {
    int seconds = time(NULL);
    srand(seconds);
    
    int points = 0;
    int rng = rand() % 100;
    
    printf("Welcome to the Surrealist Game!\n\n");
    
    for (int i = 0; i < 10; i++) {
        int guess;
        printf("Please guess a number between 0-99: ");
        scanf("%d", &guess);
        fflush(stdin);
        
        if (guess == rng) {
            points += 10;
            printf("You guessed correctly! +10 points\n");
            rng = rand() % 100;
        } else if (guess < rng) {
            printf("Your guess is too low.\n");
        } else if (guess > rng) {
            printf("Your guess is too high.\n");
        }
        
        if (points >= 50) {
            printf("\nYou have reached the maximum points of 50. Congratulations! Return to reality now.\n\n");
            return;
        }
        
        if (i == 9) {
            printf("\nYou have run out of guesses. Try again in your dreams.\n\n");
        }
    }
}

int main() {
    int play = 1;
    while (play) {
        game();
        
        printf("Do you want to play again? Enter 1 for Yes and 0 for No: ");
        scanf("%d", &play);
        fflush(stdin);
        if (play == 0) {
            printf("\nThank you for playing the Surrealist Game. Goodbye!\n");
        }
    }
    
    return 0;
}