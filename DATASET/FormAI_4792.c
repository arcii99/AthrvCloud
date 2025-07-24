//FormAI DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    printf("Welcome to my C game program!\n\n");
    printf("Instructions:\n");
    printf("Control the spaceship using arrow keys to save earth from asteroids.\n");
    printf("Be careful, if you collide with an asteroid or go out of bounds - Game Over!\n\n");

    // Initialize spaceship position
    int spaceship_x = 10;
    int spaceship_y = 10;

    // Initialize asteroid position
    int asteroid_x = 20;
    int asteroid_y = 5;

    // Game loop
    while (1) {
        // Display game board
        printf("__________________________________________________\n");
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 50; j++) {
                if (i == spaceship_y && j == spaceship_x) {
                    printf("*");
                } else if (i == asteroid_y && j == asteroid_x) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf("|\n");
        }
        printf("¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

        // Check for collision or out of bounds
        if (spaceship_y == asteroid_y && spaceship_x == asteroid_x) {
            printf("Game Over! Asteroid collided with spaceship!\n");
            break;
        } else if (spaceship_y == 0 || spaceship_y == 19 || spaceship_x == 0 || spaceship_x == 49) {
            printf("Game Over! Spaceship went out of bounds!\n");
            break;
        }

        // Get user input
        char input = getchar();
        while (getchar() != '\n');  // Clear input buffer

        // Move spaceship based on user input
        switch (input) {
            case 'w':
                spaceship_y--;
                break;
            case 'a':
                spaceship_x--;
                break;
            case 's':
                spaceship_y++;
                break;
            case 'd':
                spaceship_x++;
                break;
            default:
                printf("Invalid input, try again.\n");
        }

        // Move asteroid randomly
        asteroid_y++;

        // Wait for 0.5 seconds before continuing
        for (int i = 0; i < 100000000; i++);
    }

    return 0;
}