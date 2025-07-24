//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define ROWS 25
#define COLS 25

typedef struct {
    int x;
    int y;
} Point;

char gameBoard[ROWS][COLS];
Point playerPosition;
Point foodPosition;
Point badGuyPositions[4];

// Initialize the game board with walls, player, food, and bad guys
void initializeGameBoard() {
    // Fill the game board with dots
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            gameBoard[i][j] = '.';
        }
    }

    // Place the walls
    for (int i = 0; i < ROWS; i++) {
        gameBoard[i][0] = '|';
        gameBoard[i][COLS - 1] = '|';
    }

    for (int i = 0; i < COLS; i++) {
        gameBoard[0][i] = '_';
        gameBoard[ROWS - 1][i] = '_';
    }

    // Place the player
    playerPosition.x = ROWS / 2;
    playerPosition.y = COLS / 2;
    gameBoard[playerPosition.x][playerPosition.y] = 'P';

    // Place the food
    srand(time(NULL));
    foodPosition.x = rand() % ROWS;
    foodPosition.y = rand() % COLS;

    while ((foodPosition.x == playerPosition.x && foodPosition.y == playerPosition.y)) {
        foodPosition.x = rand() % ROWS;
        foodPosition.y = rand() % COLS;
    }

    gameBoard[foodPosition.x][foodPosition.y] = '*';

    // Place the bad guys
    for (int i = 0; i < 4; i++) {
        badGuyPositions[i].x = rand() % ROWS;
        badGuyPositions[i].y = rand() % COLS;

        while ((badGuyPositions[i].x == playerPosition.x && badGuyPositions[i].y == playerPosition.y) ||
               (badGuyPositions[i].x == foodPosition.x && badGuyPositions[i].y == foodPosition.y)) {
            badGuyPositions[i].x = rand() % ROWS;
            badGuyPositions[i].y = rand() % COLS;
        }

        gameBoard[badGuyPositions[i].x][badGuyPositions[i].y] = 'B';
    }
}

// Display the game board
void displayGameBoard() {
    printf("┌");
    for (int i = 0; i < COLS - 2; i++) {
        printf("─");
    }
    printf("┐\n");

    for (int i = 0; i < ROWS; i++) {
        printf("│");
        for (int j = 0; j < COLS; j++) {
            printf("%c", gameBoard[i][j]);
        }
        printf("│\n");
    }

    printf("└");
    for (int i = 0; i < COLS - 2; i++) {
        printf("─");
    }
    printf("┘\n");
}

// Move the player in a certain direction
bool movePlayer(char direction) {
    int newX = playerPosition.x;
    int newY = playerPosition.y;

    switch (direction) {
        case 'w':
            newX--;
            break;
        case 'a':
            newY--;
            break;
        case 's':
            newX++;
            break;
        case 'd':
            newY++;
            break;
    }

    if (gameBoard[newX][newY] == 'B') {
        printf("Oh no! You got caught by a bad guy!\n");
        return false;
    }

    if (gameBoard[newX][newY] == '|') {
        return false;
    }

    if (gameBoard[newX][newY] == '_') {
        return false;
    }

    if (gameBoard[newX][newY] == '*') {
        printf("Yay! You found the food!\n");
        playerPosition.x = newX;
        playerPosition.y = newY;
        return true;
    }

    gameBoard[playerPosition.x][playerPosition.y] = '.';
    playerPosition.x = newX;
    playerPosition.y = newY;
    gameBoard[playerPosition.x][playerPosition.y] = 'P';

    return false;
}

// Move the bad guys randomly
void moveBadGuys() {
    for (int i = 0; i < 4; i++) {
        int newX = badGuyPositions[i].x;
        int newY = badGuyPositions[i].y;

        int randomDirection = rand() % 4;

        switch (randomDirection) {
            case 0:
                newX--;
                break;
            case 1:
                newY--;
                break;
            case 2:
                newX++;
                break;
            case 3:
                newY++;
                break;
        }

        if (gameBoard[newX][newY] != '|' && gameBoard[newX][newY] != '_') {
            gameBoard[badGuyPositions[i].x][badGuyPositions[i].y] = '.';
            badGuyPositions[i].x = newX;
            badGuyPositions[i].y = newY;
            gameBoard[badGuyPositions[i].x][badGuyPositions[i].y] = 'B';
        }
    }
}

int main() {
    initializeGameBoard();
    displayGameBoard();

    while (true) {
        char direction;

        printf("Enter a direction (w,a,s,d): ");
        scanf(" %c", &direction);

        bool foodFound = movePlayer(direction);

        if (foodFound) {
            break;
        }

        moveBadGuys();
        displayGameBoard();
    }

    return 0;
}