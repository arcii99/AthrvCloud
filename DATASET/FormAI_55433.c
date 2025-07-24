//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initializeGameBoard(char gameBoard[][COLS]);
void printGameBoard(char gameBoard[][COLS]);
void startGame(char gameBoard[][COLS]);
void movePlayer(char gameBoard[][COLS], int playerRow, int playerCol, char direction);
void moveEnemies(char gameBoard[][COLS], int enemyRows[], int enemyCols[], int numEnemies);
void placeEnemies(char gameBoard[][COLS], int enemyRows[], int enemyCols[], int numEnemies);
bool checkValidMove(char gameBoard[][COLS], int newRow, int newCol);
bool checkGameOver(char gameBoard[][COLS], int playerRow, int playerCol);

int main(void) {
    char gameBoard[ROWS][COLS];
    initializeGameBoard(gameBoard);
    printGameBoard(gameBoard);
    startGame(gameBoard);
    return 0;
}

void initializeGameBoard(char gameBoard[][COLS]) {
    int i, j;
    // Set all squares to be empty
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            gameBoard[i][j] = '.';
        }
    }
    // Add player
    gameBoard[ROWS-1][COLS/2] = 'P';
}

void printGameBoard(char gameBoard[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }
}

void startGame(char gameBoard[][COLS]) {
    int playerRow, playerCol;
    int enemyRows[3], enemyCols[3];
    int numEnemies = 3;
    char input;

    // Set up player and enemies
    playerRow = ROWS-1;
    playerCol = COLS/2;
    placeEnemies(gameBoard, enemyRows, enemyCols, numEnemies);

    while (true) {
        printf("Enter move (W/A/S/D): ");
        scanf(" %c", &input);
        movePlayer(gameBoard, playerRow, playerCol, input);
        moveEnemies(gameBoard, enemyRows, enemyCols, numEnemies);
        printGameBoard(gameBoard);
        if (checkGameOver(gameBoard, playerRow, playerCol)) {
            printf("Game Over!\n");
            break;
        }
    }
}

void movePlayer(char gameBoard[][COLS], int playerRow, int playerCol, char direction) {
    int newRow, newCol;
    newRow = playerRow;
    newCol = playerCol;

    if (direction == 'W') {
        newRow--;
    } else if (direction == 'A') {
        newCol--;
    } else if (direction == 'S') {
        newRow++;
    } else if (direction == 'D') {
        newCol++;
    }

    if (checkValidMove(gameBoard, newRow, newCol)) {
        gameBoard[playerRow][playerCol] = '.';
        gameBoard[newRow][newCol] = 'P';
    }
}

void moveEnemies(char gameBoard[][COLS], int enemyRows[], int enemyCols[], int numEnemies) {
    int i, newRow, newCol;
    for (i = 0; i < numEnemies; i++) {
        newRow = enemyRows[i] + (rand() % 3) - 1;
        newCol = enemyCols[i] + (rand() % 3) - 1;
        if (checkValidMove(gameBoard, newRow, newCol)) {
            gameBoard[enemyRows[i]][enemyCols[i]] = '.';
            gameBoard[newRow][newCol] = 'E';
            enemyRows[i] = newRow;
            enemyCols[i] = newCol;
        }
    }
}

void placeEnemies(char gameBoard[][COLS], int enemyRows[], int enemyCols[], int numEnemies) {
    srand(time(NULL));
    int i, row, col;
    for (i = 0; i < numEnemies; i++) {
        row = rand() % ROWS;
        col = rand() % COLS;
        while (gameBoard[row][col] != '.') {
            row = rand() % ROWS;
            col = rand() % COLS;
        }
        gameBoard[row][col] = 'E';
        enemyRows[i] = row;
        enemyCols[i] = col;
    }
}

bool checkValidMove(char gameBoard[][COLS], int newRow, int newCol) {
    if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLS) {
        return false;
    }
    if (gameBoard[newRow][newCol] == 'E') {
        return false;
    }
    return true;
}

bool checkGameOver(char gameBoard[][COLS], int playerRow, int playerCol) {
    if (gameBoard[playerRow][playerCol] == 'E') {
        return true;
    }
    int i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (playerRow+i >= 0 && playerRow+i < ROWS && playerCol+j >= 0 && playerCol+j < COLS) {
                if (gameBoard[playerRow+i][playerCol+j] == 'E') {
                    return true;
                }
            }
        }
    }
    return false;
}