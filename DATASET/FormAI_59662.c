//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// function prototypes
void initializeBoard(char board[ROWS][COLS], int randRow, int randCol);
void printBoard(char board[ROWS][COLS]);
void movePlayer(char board[ROWS][COLS], int* playerRow, int* playerCol, char move);
bool isGameOver(char board[ROWS][COLS], int playerRow, int playerCol);

int main() {
    char board[ROWS][COLS];
    int playerRow, playerCol, randRow, randCol;
    char move;

    // generate random starting position for player
    srand(time(0));
    playerRow = rand() % ROWS;
    playerCol = rand() % COLS;

    // generate random position for ghost
    randRow = rand() % ROWS;
    randCol = rand() % COLS;

    // initialize board and place player and ghost
    initializeBoard(board, randRow, randCol);
    board[playerRow][playerCol] = 'P';
    board[randRow][randCol] = 'G';

    // game loop
    while(!isGameOver(board, playerRow, playerCol)) {
        // print board and ask for player input
        printBoard(board);
        printf("Move (W/A/S/D): ");
        scanf(" %c", &move);

        // move player and update board
        movePlayer(board, &playerRow, &playerCol, move);
        board[playerRow][playerCol] = 'P';
        board[randRow][randCol] = 'G';

        // move ghost randomly
        switch(rand() % 4) {
            case 0:
                if(randRow > 0)
                    randRow--;
                break;
            case 1:
                if(randRow < ROWS-1)
                    randRow++;
                break;
            case 2:
                if(randCol > 0)
                    randCol--;
                break;
            case 3:
                if(randCol < COLS-1)
                    randCol++;
                break;
        }

        // update board
        board[playerRow][playerCol] = 'P';
        board[randRow][randCol] = 'G';
    }

    // print final board and game over message
    printBoard(board);
    printf("GAME OVER!\n");

    return 0;
}

void initializeBoard(char board[ROWS][COLS], int randRow, int randCol) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(i == randRow && j == randCol)
                board[i][j] = 'G';  // ghost
            else
                board[i][j] = '.';  // empty space
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char board[ROWS][COLS], int* playerRow, int* playerCol, char move) {
    switch(move) {
        case 'W':
            if(*playerRow > 0)
                (*playerRow)--;
            break;
        case 'A':
            if(*playerCol > 0)
                (*playerCol)--;
            break;
        case 'S':
            if(*playerRow < ROWS-1)
                (*playerRow)++;
            break;
        case 'D':
            if(*playerCol < COLS-1)
                (*playerCol)++;
            break;
    }
}

bool isGameOver(char board[ROWS][COLS], int playerRow, int playerCol) {
    if(board[playerRow][playerCol] == 'G')
        return true;
    else
        return false;
}