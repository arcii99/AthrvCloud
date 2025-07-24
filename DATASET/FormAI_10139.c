//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 20

char board[ROWS][COLUMNS];
int pacManRow, pacManColumn;
bool gameOver = false;
int score = 0;

void initializeBoard() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(i == 0 || i == ROWS-1 || j == 0 || j == COLUMNS-1) {
                board[i][j] = '#';
            }
            else {
                board[i][j] = '.';
            }
        }
    }
    pacManRow = ROWS / 2;
    pacManColumn = COLUMNS / 2;
    board[pacManRow][pacManColumn] = 'P';
}

void displayBoard() {
    system("clear");
    printf("SCORE: %d\n", score);
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void updateBoard() {
    board[pacManRow][pacManColumn] = ' ';
    char keyPressed = getchar();
    if(keyPressed == 'w') {
        pacManRow -= 1;
    }
    else if(keyPressed == 'a') {
        pacManColumn -= 1;
    }
    else if(keyPressed == 's') {
        pacManRow += 1;
    }
    else if(keyPressed == 'd') {
        pacManColumn += 1;
    }
    if(board[pacManRow][pacManColumn] == '.') {
        score += 1;
    }
    board[pacManRow][pacManColumn] = 'P';
}

void checkGameOver() {
    bool hasDotsRemaining = false;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(board[i][j] == '.') {
                hasDotsRemaining = true;
                break;
            }
        }
        if(hasDotsRemaining == true) {
            break;
        }
    }
    if(hasDotsRemaining == false) {
        gameOver = true;
        printf("Congratulations! You won the game!\n");
    }
}

int main() {
    srand(time(NULL));
    initializeBoard();
    while(!gameOver) {
        displayBoard();
        updateBoard();
        checkGameOver();
    }
    return 0;
}