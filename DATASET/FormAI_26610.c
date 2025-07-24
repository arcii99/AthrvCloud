//FormAI DATASET v1.0 Category: Table Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int input, random;
    int lives = 5;
    
    srand(time(NULL));
    random = rand() % 11;
    
    printf("Welcome to the Guessing Game!\n"
           "You have 5 lives to guess a number between 1 and 10.\n"
           "Good luck!\n");
    
    do {
        printf("Enter your guess: ");
        scanf("%d", &input);
        
        if (input < 1 || input > 10) {
            printf("Hey, I said between 1 and 10! Try again.\n");
            continue;
        }
        
        if (input == random) {
            printf("Congratulations! You've won.\n");
            break;
        } else {
            lives--;
            if (lives == 0) {
                printf("You lose! The number was %d.\n", random);
                break;
            } else {
                printf("Sorry, that's not it. You have %d lives left.\n", lives);
                continue;
            }
        }
    } while (lives > 0);
    
    return 0;
}