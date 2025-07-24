//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// initialize variables
int score = 0;
int lives = 3;

// function to generate random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    // seed random number generator
    srand(time(NULL));
    
    // game loop
    while (lives > 0) {
        // generate random numbers for equations
        int num1 = rand_num(1, 10);
        int num2 = rand_num(1, 10);
        int answer = num1 + num2;
        
        // display equation and prompt for user input
        printf("What is %d + %d? ", num1, num2);
        int user_answer;
        scanf("%d", &user_answer);
        
        // check if user's answer is correct
        if (user_answer == answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect.\n");
            lives--;
        }
        
        // display current score and lives
        printf("Score: %d  Lives: %d\n", score, lives);
    }
    
    // game over screen
    printf("GAME OVER\n");
    printf("Final Score: %d\n", score);
    
    return 0;
}