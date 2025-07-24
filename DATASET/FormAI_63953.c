//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between 1 and max
int generateRandomNumber(int max) {
    srand(time(NULL));
    return (rand() % max) + 1;
}

int main() {
    int lives = 3;
    int score = 0;
    int currentLevel = 1;
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are a lone astronaut on a mission to explore the galaxy.\n");
    printf("Your goal is to survive as long as possible and earn as many points as you can!\n\n");
    
    while (lives > 0) {
        printf("Level %d\n", currentLevel);
        printf("You encounter a random alien spaceship.\n");
        
        // generate random number between 1 and 5 to determine outcome of encounter
        int encounter = generateRandomNumber(5);
        
        if (encounter == 1 || encounter == 2) {
            printf("You successfully negotiate a peace treaty with the aliens.\n");
            score += currentLevel * 10;
        } else if (encounter == 3 || encounter == 4) {
            printf("The aliens attack you! You lose a life.\n");
            lives--;
        } else {
            printf("You discover an uncharted planet! You gain points.\n");
            score += currentLevel * 5;
        }
        
        printf("Lives: %d\n", lives);
        printf("Score: %d\n\n", score);
        
        if (score >= 100 && currentLevel == 1) {
            currentLevel = 2;
            printf("You have reached a new level!\n");
        } else if (score >= 200 && currentLevel == 2) {
            currentLevel = 3;
            printf("You have reached a new level!\n");
        }
    }
    
    printf("\nGame over! Your final score is %d points.\n", score);
    
    return 0;
}