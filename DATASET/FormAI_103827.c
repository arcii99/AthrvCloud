//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 21
#define MAX_FOOD 15

char board[BOARD_SIZE][BOARD_SIZE];
int pacmanX, pacmanY;
int ghostX, ghostY;
int foodCount = 0;
bool gameOver = false;

void initBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == BOARD_SIZE - 1 || j == 0 || j == BOARD_SIZE - 1) {
                board[i][j] = '#'; // Wall
            } else {
                board[i][j] = ' '; // Empty space
            }
        }
    }
    // Randomly place pacman and ghost
    srand(time(NULL)); // Seed the random number generator
    pacmanX = rand() % (BOARD_SIZE - 2) + 1;
    pacmanY = rand() % (BOARD_SIZE - 2) + 1;
    board[pacmanX][pacmanY] = 'P'; // Pacman
    ghostX = rand() % (BOARD_SIZE - 2) + 1;
    ghostY = rand() % (BOARD_SIZE - 2) + 1;
    board[ghostX][ghostY] = 'G'; // Ghost
}

void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void updateBoard(char direction) {
    int nextX, nextY;
    switch (direction) {
        case 'W': // Up
            nextX = pacmanX - 1;
            nextY = pacmanY;
            break;
        case 'A': // Left
            nextX = pacmanX;
            nextY = pacmanY - 1;
            break;
        case 'S': // Down
            nextX = pacmanX + 1;
            nextY = pacmanY;
            break;
        case 'D': // Right
            nextX = pacmanX;
            nextY = pacmanY + 1;
            break;
        default:
            return; // Invalid direction
    }
    if (board[nextX][nextY] == '#') {
        return; // Hit wall
    } else if (board[nextX][nextY] == 'G') {
        gameOver = true; // Game over
        return;
    } else if (board[nextX][nextY] == '.') {
        foodCount--;
    }
    board[pacmanX][pacmanY] = ' '; // Empty current position
    pacmanX = nextX;
    pacmanY = nextY;
    board[pacmanX][pacmanY] = 'P'; // Place Pacman at new position
}

void placeFood() {
    while (foodCount < MAX_FOOD) {
        int x = rand() % (BOARD_SIZE - 2) + 1;
        int y = rand() % (BOARD_SIZE - 2) + 1;
        if (board[x][y] == ' ') {
            board[x][y] = '.';
            foodCount++;
        }
    }
}

int main() {
    initBoard();
    placeFood();
    while (!gameOver) {
        printBoard();
        printf("Score: %d\n", MAX_FOOD - foodCount);
        char direction;
        printf("Enter direction (WASD): ");
        scanf(" %c", &direction);
        updateBoard(direction);
        if (foodCount == 0) {
            printf("\nCongratulations! You won!\n");
            break;
        }
        system("clear"); // Clear screen (Linux/Mac only)
    }
    printf("\nGame over!\n");
    return 0;
}