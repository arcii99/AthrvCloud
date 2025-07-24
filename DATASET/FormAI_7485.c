//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: mathematical
#include <stdio.h>

// Define constant values
#define ROW 7
#define COL 8
#define ENEMY_COUNT 10
#define SPEED 3

int main() {
    // Initialize variables
    int playerPos = 3;
    int enemyPos[ENEMY_COUNT] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int enemyRow[ENEMY_COUNT] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4};
    int playerBulletRow = 0;
    int playerBulletPos = playerPos;
    int enemyBulletRow[ENEMY_COUNT];
    int enemyBulletPos[ENEMY_COUNT];
    int score = 0;
    int gameOver = 0;

    // Start game loop
    while (!gameOver) {
        // Clear screen
        printf("\033[2J");

        // Print player and enemy positions
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (i == ROW-1 && j == playerPos) {
                    printf("A");
                } else {
                    int enemyIndex = -1;
                    for (int k = 0; k < ENEMY_COUNT; k++) {
                        if (enemyRow[k] == i && enemyPos[k] == j) {
                            enemyIndex = k;
                        }
                    }
                    if (enemyIndex == -1) {
                        printf(" ");
                    } else {
                        printf("E");
                    }
                }
            }
            printf("\n");
        }

        // Update player position
        char input = getchar();
        if (input == 'a') {
            if (playerPos > 0) {
                playerPos--;
            }
        } else if (input == 'd') {
            if (playerPos < COL-1) {
                playerPos++;
            }
        } else if (input == ' ') {
            if (playerBulletRow == 0) {
                playerBulletRow = ROW-2;
                playerBulletPos = playerPos;
            }
        }

        // Update enemy positions
        for (int k = 0; k < ENEMY_COUNT; k++) {
            if (enemyPos[k] < COL-1) {
                enemyPos[k]++;
            } else {
                enemyPos[k] = 0;
                enemyRow[k]++;
                if (enemyRow[k] == ROW-1) {
                    gameOver = 1;
                }
            }
            if (enemyRow[k] == ROW-2 && enemyPos[k] == playerPos) {
                gameOver = 1;
            }
        }

        // Update player bullet position
        if (playerBulletRow > 0) {
            playerBulletRow--;
        } else {
            playerBulletPos = -1;
        }

        // Update enemy bullet positions
        for (int k = 0; k < ENEMY_COUNT; k++) {
            if (enemyBulletRow[k] > ROW-1) {
                enemyBulletPos[k] = -1;
            }
            if (enemyBulletPos[k] == -1) {
                enemyBulletRow[k] = enemyRow[k]+1;
                enemyBulletPos[k] = enemyPos[k];
            } else {
                enemyBulletRow[k]++;
            }
            if (enemyBulletRow[k] == ROW-1 && enemyBulletPos[k] == playerPos) {
                gameOver = 1;
            }
        }

        // Print player bullet
        printf("\033[%d;%dH", playerBulletRow+1, playerBulletPos+1);
        printf("*");

        // Print enemy bullets
        for (int k = 0; k < ENEMY_COUNT; k++) {
            if (enemyBulletPos[k] != -1) {
                printf("\033[%d;%dH", enemyBulletRow[k]+1, enemyBulletPos[k]+1);
                printf("|");
            }
        }

        // Print score
        printf("\033[%d;%dH", ROW+1, 1);
        printf("Score: %d", score);

        // Sleep for speed
        sleep(SPEED);
    }

    // Print game over
    printf("\033[2J");
    printf("\033[%d;%dH", ROW/2, COL/2-5);
    printf("Game Over");
    printf("\033[%d;%dH", ROW/2+1, COL/2-5);
    printf("Score: %d", score);
    printf("\033[%d;%dH", ROW+1, 1);

    return 0;
}