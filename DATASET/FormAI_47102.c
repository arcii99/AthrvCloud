//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to return a random integer between min and max
int getRandomInt(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize game variables
    int score = 0;
    int lives = 3;
    int level = 1;
    int gameover = 0;

    // Print welcome message and instructions
    printf("Welcome to the cheerful game!\n\n");
    printf("Instructions:\n");
    printf("Use the arrow keys to move the player and collect the coins.\n");
    printf("Each coin is worth one point, and you start with three lives.\n");
    printf("Avoid the enemies, hitting one will cost you a life.\n");
    printf("Reach a score of 10 to advance to the next level and increase the enemy speed.\n");
    printf("If you lose all your lives, the game is over.\n");
    printf("Good luck and have fun!\n\n");

    // Loop until gameover is set to 1
    while (!gameover) {
        // Initialize level variables
        int playerX = 0;
        int playerY = 0;
        int coinX = getRandomInt(0, 9);
        int coinY = getRandomInt(0, 9);
        int enemyX = getRandomInt(0, 9);
        int enemyY = getRandomInt(0, 9);
        double enemySpeed = 0.1 * level;

        // Loop until the player collects a coin or hits an enemy
        int coinCollected = 0;
        int hitEnemy = 0;
        while (!coinCollected && !hitEnemy) {
            // Print game board
            printf("Score: %d    Lives: %d    Level: %d\n", score, lives, level);
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if ((i == playerY) && (j == playerX)) {
                        printf("P ");
                    } else if ((i == coinY) && (j == coinX)) {
                        printf("C ");
                    } else if ((i == enemyY) && (j == enemyX)) {
                        printf("E ");
                    } else {
                        printf(". ");
                    }
                }
                printf("\n");
            }

            // Get user input
            char move;
            printf("Move (up/down/left/right): ");
            scanf(" %c", &move);

            // Update player position based on input
            switch (move) {
                case 'up':
                    if (playerY > 0) {
                        playerY--;
                    }
                    break;
                case 'down':
                    if (playerY < 9) {
                        playerY++;
                    }
                    break;
                case 'left':
                    if (playerX > 0) {
                        playerX--;
                    }
                    break;
                case 'right':
                    if (playerX < 9) {
                        playerX++;
                    }
                    break;
                default:
                    printf("Invalid move, try again.\n");
            }

            // Check if player collects a coin or hits an enemy
            if ((playerX == coinX) && (playerY == coinY)) {
                score++;
                coinCollected = 1;
                printf("You collected a coin!\n");
            } else if ((playerX == enemyX) && (playerY == enemyY)) {
                lives--;
                hitEnemy = 1;
                printf("You hit an enemy and lost a life!\n");
            }

            // Check if gameover conditions are met
            if (lives == 0) {
                printf("Game over, you lost all your lives!\n");
                gameover = 1;
            } else if (score == 10) {
                level++;
                printf("Congratulations, you advanced to level %d!\n", level);
                coinCollected = 1;
            } else {
                // Update enemy position based on speed and random direction
                if (enemyX < playerX) {
                    enemyX += 1;
                } else if (enemyX > playerX) {
                    enemyX -= 1;
                }
                if (enemyY < playerY) {
                    enemyY += 1;
                } else if (enemyY > playerY) {
                    enemyY -= 1;
                }
                if (getRandomInt(0, 99) < (int) (enemySpeed * 100)) {
                    if (getRandomInt(0, 1)) {
                        enemyX += getRandomInt(-1, 1);
                    } else {
                        enemyY += getRandomInt(-1, 1);
                    }
                }
            }
        }
    }

    // End of game message
    printf("Thanks for playing the cheerful game!\n");
    return 0;
}