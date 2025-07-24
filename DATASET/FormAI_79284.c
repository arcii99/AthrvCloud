//FormAI DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

char board[BOARD_SIZE][BOARD_SIZE];
int playerX, playerY, treasureX, treasureY;
int numMoves = 0;

void initBoard();
void printBoard();
void getPlayerMove();
void updateBoard();
int isGameOver();

int main() {
    initBoard();

    while (!isGameOver()) {
        printBoard();
        getPlayerMove();
        updateBoard();
        numMoves++;
    }

    printf("Congratulations, you found the treasure in %d moves!\n", numMoves);

    return 0;
}

void initBoard() {
    srand(time(NULL)); // Seed the random number generator

    // Place the player randomly on the board
    playerX = rand() % BOARD_SIZE;
    playerY = rand() % BOARD_SIZE;
    board[playerX][playerY] = 'P';

    // Place the treasure randomly on the board (make sure it's not on top of the player)
    do {
        treasureX = rand() % BOARD_SIZE;
        treasureY = rand() % BOARD_SIZE;
    } while (treasureX == playerX && treasureY == playerY);
    board[treasureX][treasureY] = 'T';

    // Fill the rest of the board with empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != 'P' && board[i][j] != 'T') {
                board[i][j] = ' ';
            }
        }
    }
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void getPlayerMove() {
    char move;

    printf("Enter your move (w for up, s for down, a for left, d for right): ");
    scanf(" %c", &move);

    switch (move) {
        case 'w':
            if (playerX > 0) {
                playerX--;
            }
            break;
        case 's':
            if (playerX < BOARD_SIZE - 1) {
                playerX++;
            }
            break;
        case 'a':
            if (playerY > 0) {
                playerY--;
            }
            break;
        case 'd':
            if (playerY < BOARD_SIZE - 1) {
                playerY++;
            }
            break;
        default:
            printf("Invalid move!\n");
            getPlayerMove();
    }
}

void updateBoard() {
    // Clear the old player position
    board[playerX][playerY] = ' ';

    // Move the player to the new position
    board[playerX][playerY] = 'P';

    // Check if the player has found the treasure
    if (playerX == treasureX && playerY == treasureY) {
        printf("You found the treasure!\n");
    }
}

int isGameOver() {
    return playerX == treasureX && playerY == treasureY;
}