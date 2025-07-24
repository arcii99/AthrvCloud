//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set random seed
    srand(time(0));

    // Set up game board
    int board[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // Set initial player position
    int playerX = 2;
    int playerY = 2;

    // Set up game loop
    int gameRunning = 1;
    while (gameRunning) {
        // Print game board
        printf("\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (i == playerY && j == playerX) {
                    printf("P ");
                } else {
                    printf("%d ", board[i][j]);
                }
            }
            printf("\n");
        }

        // Get player input
        char playerInput;
        printf("\nMove player (WASD): ");
        scanf(" %c", &playerInput);

        // Move player
        switch (playerInput) {
            case 'w':
                if (playerY > 0) {
                    playerY--;
                }
                break;
            case 'a':
                if (playerX > 0) {
                    playerX--;
                }
                break;
            case 's':
                if (playerY < 4) {
                    playerY++;
                }
                break;
            case 'd':
                if (playerX < 4) {
                    playerX++;
                }
                break;
            default:
                break;
        }

        // Check if player has won
        if (board[playerY][playerX] == 25) {
            gameRunning = 0;
            printf("\nYou win!\n");
        }

        // Randomly move obstacles
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int randomNum = rand() % 4;
                switch (randomNum) {
                    case 0:
                        if (i > 0) {
                            int temp = board[i][j];
                            board[i][j] = board[i-1][j];
                            board[i-1][j] = temp;
                        }
                        break;
                    case 1:
                        if (j > 0) {
                            int temp = board[i][j];
                            board[i][j] = board[i][j-1];
                            board[i][j-1] = temp;
                        }
                        break;
                    case 2:
                        if (i < 4) {
                            int temp = board[i][j];
                            board[i][j] = board[i+1][j];
                            board[i+1][j] = temp;
                        }
                        break;
                    case 3:
                        if (j < 4) {
                            int temp = board[i][j];
                            board[i][j] = board[i][j+1];
                            board[i][j+1] = temp;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }

    return 0;
}