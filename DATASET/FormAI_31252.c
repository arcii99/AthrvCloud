//FormAI DATASET v1.0 Category: Game ; Style: synchronous
#include <stdio.h>

int main() {
    // Initialize variables
    int score = 0;
    int level = 1;
    int lives = 3;

    // Main game loop
    while (lives > 0) {
        // Print game title and level
        printf("==== Welcome to My Game (Level %d) ====\n", level);

        // Print game instructions
        printf("Instructions:\n");
        printf("- Use arrow keys to move left and right\n");
        printf("- Press spacebar to shoot projectiles\n");
        printf("- Don't let the enemy hit you or you lose a life\n");
        printf("- Kill all enemies to advance to the next level\n");
        printf("\n");

        // Sub-level loop
        int enemies_left = 3 + level;
        while (enemies_left > 0) {
            // User input
            printf("Score: %d | Lives: %d\n", score, lives);
            printf("Enemies Left: %d\n", enemies_left);
            printf("Use arrow keys to move and spacebar to shoot\n");

            // Process user input

            // Draw game screen
            printf(" _______     _________         _________              \n");
            printf("/       \\   |         \\       |         \\        \n");
            printf("|   *_*   |  |    *    | ___  |    *    | ___     \n");
            printf("|  /. .\\  |  |    |    |/   \\ |    |    |/   \\   \n");
            printf("|  \\_^_/  |  |____|____|\\___/ |____|____|\\___/ \n");
            printf("\\         /    _____     _____    _____              \n");
            printf(" \\_______/    /     \\   /     \\  /     \\         \n");
            printf("             |   *   | |   *   ||   *   |             \n");
            printf("             |___|___| |___|___||___|___|         \n");

            // Game logic
            int enemy_shoots = rand() % 2;
            if (enemy_shoots) {
                printf("Enemy shoots!\n");
                printf("You lose a life!\n");
                lives--;
            }
            else {
                printf("No shot from enemy.\n");
            }

            // Check if user won sub-level
            int user_wins = rand() % 2;
            if (user_wins) {
                printf("You defeated an enemy!\n");
                enemies_left--;
                score += 100;
            }
            else {
                printf("You missed the enemy!\n");
            }

            // Check if game is over
            if (lives <= 0) {
                printf("Game over! Final score: %d\n", score);
                break;
            }

            // Check if user won main level
            if (enemies_left == 0) {
                printf("You won level %d!\n", level);
                level++;
                lives++;
            }
        }
    }
    return 0;
}