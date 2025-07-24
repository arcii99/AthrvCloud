//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    int score = 0;
    int x, y, guess_x, guess_y;
    
    srand(time(NULL));
    x = rand() % 10 + 1;
    y = rand() % 10 + 1;
    
    printf("Welcome to Guess the Coordinates Game!\n");
    printf("The x and y coordinates are between 1 and 10.\n\n");
    
    while(score < 5) {
        printf("Enter your guess for x coordinate:");
        scanf("%d", &guess_x);
        printf("Enter your guess for y coordinate:");
        scanf("%d", &guess_y);
        
        if(guess_x == x && guess_y == y) {
            score++;
            printf("Congratulations! You guessed the correct coordinates!\n");
            printf("Score: %d\n", score);
        }
        else {
            printf("Oops! Wrong coordinates, try again.\n");
        }
    }
    
    printf("You have won the game! Thanks for playing.\n");
    
    return 0;
}