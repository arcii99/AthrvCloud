//FormAI DATASET v1.0 Category: Math exercise ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_guess, correct_answer;
    int num_guesses = 0;
    srand(time(0));
    correct_answer = rand() % 100;
    printf("Welcome to the Guessing Game!\n");
    printf("You will have to guess the correct answer between 0 and 100.\n");

    while(1) {
        printf("Enter your guess: ");
        scanf("%d", &player_guess);
        num_guesses++;
        
        if(player_guess == correct_answer) {
            printf("Congratulations! You guessed the correct answer in %d tries.\n", num_guesses);
            break;
        }
        else if(player_guess < correct_answer) {
            printf("Too low! Try guessing higher.\n");
        }
        else {
            printf("Too high! Try guessing lower.\n");
        }
        printf("You have %d guesses left.\n", 6 - num_guesses);
        if(num_guesses == 6) {
            printf("Sorry, you have used up all your guesses. The correct answer was %d.\n", correct_answer);
            break;
        }
    }

    return 0;
}