//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printBoard(char board[ROWS][COLS], int playerX, int playerY) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == playerX && j == playerY) {
                printf("👻 ");
            } else {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    char board[ROWS][COLS] = {' '};
    int playerX = rand() % ROWS, playerY = rand() % COLS;
    board[playerX][playerY] = 'X';

    // Place random ghosts on the board
    for (int i = 0; i < 5; i++) {
        int ghostX = rand() % ROWS, ghostY = rand() % COLS;
        while (board[ghostX][ghostY] != ' ') {
            ghostX = rand() % ROWS;
            ghostY = rand() % COLS;
        }
        board[ghostX][ghostY] = '👻';
    }

    do {
        // Print the board and prompt for input
        printBoard(board, playerX, playerY);
        printf("Which direction do you want to move? (w, a, s, d): ");
        char direction;
        scanf(" %c", &direction);

        // Update the player's position
        switch (direction) {
            case 'w':
                if (playerX > 0) playerX--;
                break;
            case 'a':
                if (playerY > 0) playerY--;
                break;
            case 's':
                if (playerX < ROWS - 1) playerX++;
                break;
            case 'd':
                if (playerY < COLS - 1) playerY++;
                break;
            default:
                printf("Invalid input\n");
                break;
        }

        // Check for ghosts
        if (board[playerX][playerY] == '👻') {
            printf("You were caught by a ghost! Game over.\n");
            return 0;
        }

        // Check for win state
        int foundX = -1, foundY = -1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == '👻') {
                    if (foundX == -1 && foundY == -1) {
                        foundX = i;
                        foundY = j;
                    } else {
                        // More than one ghost left on the board, continue playing
                        foundX = -2;
                        foundY = -2;
                        break;
                    }
                }
            }
            if (foundX == -2 && foundY == -2) {
                break;
            }
        }
        if (foundX == playerX && foundY == playerY) {
            printf("You have caught all the ghosts! You win!\n");
            return 0;
        }

    } while (1);
    return 0;
}