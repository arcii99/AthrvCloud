//FormAI DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    int roll, guess;
    
    printf("Welcome to the Roll and Guess game!\n\n");
    
    srand(time(0));
    
    while(score < 10) {
        printf("Your current score is %d. Enter your guess between 1 and 6: ", score);
        scanf("%d", &guess);
        
        if(guess < 1 || guess > 6) {
            printf("Invalid input. Please enter a number between 1 and 6.\n\n");
            continue;
        }
        
        roll = rand() % 6 + 1;
        
        printf("The dice rolled a %d!\n", roll);
        
        if(guess == roll) {
            printf("Congratulations! You guessed correctly and earned a point.\n");
            score++;
        } else {
            printf("Sorry, you guessed incorrectly. No point earned.\n");
        }
        
        printf("\n");
    }
    
    printf("Congratulations, you have won the game with a score of %d!\n", score);
    
    return 0;
}