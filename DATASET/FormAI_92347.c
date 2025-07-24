//FormAI DATASET v1.0 Category: Random ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    printf("Welcome to the Random Number Game!\n");
    printf("You have 5 tries to guess the correct number between 1 and 100.\n");
    
    int correct_num = rand() % 100 + 1;
    int guess, tries = 0;
    
    while (tries < 5) {
        printf("Attempt %d: Enter your guess: ", tries+1);
        scanf("%d", &guess);
        
        if (guess < 1 || guess > 100) {
            printf("Invalid guess. Guess must be between 1 and 100.\n");
            continue;
        }
        
        if (guess == correct_num) {
            printf("Congratulations! You guessed correctly!\n");
            return 0;
        }
        
        if (guess < correct_num) {
            printf("Your guess is too low. Try again.\n");
        } else {
            printf("Your guess is too high. Try again.\n");
        }
        
        tries++;
    }
    
    printf("Sorry, you have reached the maximum number of tries.\n");
    printf("The correct number was %d. Better luck next time!\n", correct_num);
    
    return 0;
}