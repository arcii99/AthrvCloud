//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
 
#define ROWS 5
#define COLS 10
#define INVADER_DESCENT 2
 
int invaderRow = 0;
int invaderCol = 0;
 
int playerRow = ROWS - 1;
int playerCol = COLS / 2;
 
int shots[ROWS][COLS] = {0};
int invaders[ROWS][COLS] = {0};
 
//Function Declarations
void initInvaders();
void initPlayer();
void movePlayer(int dir);
void moveInvaders();
void drawBoard();
void playerShoot();
int checkHit(int row, int col);
int checkLoss();
 
int main() {
    srand(time(NULL));
    int dir = 0;
    int gameOver = 0;
    initInvaders();
    initPlayer();
    while (!gameOver) {
        dir = rand() % 3 - 1;
        movePlayer(dir);
        moveInvaders();
        drawBoard();
        playerShoot();
        gameOver = checkLoss();
        usleep(100000);
        system("clear");
    }
    printf("Game Over\n");
    return 0;
}
 
void initInvaders() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            invaders[i][j] = 1;
        }
    }
}
 
void initPlayer() {
    playerRow = ROWS - 1;
    playerCol = COLS / 2;
}
 
void movePlayer(int dir) {
    if (playerCol + dir >= 0 && playerCol + dir < COLS) {
        playerCol += dir;
    }
}
 
void moveInvaders() {
    int i, j;
    for (i = ROWS - 1; i >= 0; i--) {
        for (j = 0; j < COLS; j++) {
            if (invaders[i][j]) {
                invaders[i][j] = 0;
                invaderRow = i + INVADER_DESCENT;
                invaderCol = j;
                if (invaderRow >= ROWS) {
                    return;
                }
                invaders[invaderRow][invaderCol] = 1;
            }
        }
    }
}
 
void drawBoard() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLS; j++) {
            if (playerRow == i && playerCol == j) {
                printf("P");
            } else if (invaders[i][j]) {
                printf("I");
            } else if (shots[i][j]) {
                printf("X");
            } else {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }
}
 
void playerShoot() {
    if (shots[playerRow - 1][playerCol]) {
        shots[playerRow - 1][playerCol] = 0;
        return;
    }
    shots[playerRow - 1][playerCol] = 1;
}
 
int checkHit(int row, int col) {
    if (invaders[row][col]) {
        invaders[row][col] = 0;
        return 1;
    }
    return 0;
}
 
int checkLoss() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (invaders[i][j] && i == ROWS - 1) {
                return 1;
            }
        }
    }
    return 0;
}