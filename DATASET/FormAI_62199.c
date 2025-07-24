//FormAI DATASET v1.0 Category: Table Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLUMNS 6

void initializeGameBoard(int gameBoard[][COLUMNS]);
void printGameBoard(int gameBoard[][COLUMNS]);
void placePlayerMarker(int player, int gameBoard[][COLUMNS]);
int checkWinCondition(int gameBoard[][COLUMNS], int player);

int main() {
    int gameBoard[ROWS][COLUMNS];
    int currentPlayer = 1;
    int winner = 0;

    initializeGameBoard(gameBoard);

    do {
        system("clear");
        printf("Player %d's Turn\n", currentPlayer);
        printGameBoard(gameBoard);
        placePlayerMarker(currentPlayer, gameBoard);
        winner = checkWinCondition(gameBoard, currentPlayer);
        if(winner != 0) {
            printf("Player %d wins!\n", currentPlayer);
            break;
        }
        if(currentPlayer == 1) {
            currentPlayer = 2;
        }
        else {
            currentPlayer = 1;
        }
    }while(winner == 0);

    return 0;
}

void initializeGameBoard(int gameBoard[][COLUMNS]) {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            gameBoard[i][j] = rand() % 2;
        }
    }
}

void printGameBoard(int gameBoard[][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(gameBoard[i][j] == 0) {
                printf("O ");
            }
            else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

void placePlayerMarker(int player, int gameBoard[][COLUMNS]) {
    int row, col;
    printf("Enter row and column to place your marker (1-6): ");
    scanf("%d %d", &row, &col);
    if(gameBoard[row-1][col-1] == 0) {
        gameBoard[row-1][col-1] = player;
    }
    else {
        printf("That spot is already taken! Try again.\n");
        placePlayerMarker(player, gameBoard);
    }
}

int checkWinCondition(int gameBoard[][COLUMNS], int player) {
    int win = 0;
    for(int i=0; i<ROWS; i++) {
        int rowMatch = 1, colMatch = 1, diagMatch1 = 1, diagMatch2 = 1;
        for(int j=0; j<COLUMNS; j++) {
            if(gameBoard[i][j] != player) {
                rowMatch = 0;
            }
            if(gameBoard[j][i] != player) {
                colMatch = 0;
            }
            if(gameBoard[j][j] != player) {
                diagMatch1 = 0;
            }
            if(gameBoard[j][COLUMNS-1-j] != player) {
                diagMatch2 = 0;
            }
        }
        if(rowMatch == 1 || colMatch == 1 || diagMatch1 == 1 || diagMatch2 == 1) {
            win = player;
        }
    }
    return win;
}