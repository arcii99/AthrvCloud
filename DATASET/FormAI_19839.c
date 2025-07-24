//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int board[ROWS][COLS];

void populateBoard() {
    int begin = 1;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == ROWS/2 && j == COLS/2) {
                board[i][j] = 0;
            } else {
                board[i][j] = begin;
                begin++;
            }
        }
    }
}

void shuffleBoard() {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int randomI = rand() % ROWS;
            int randomJ = rand() % COLS;
            int temp = board[i][j];
            board[i][j] = board[randomI][randomJ];
            board[randomI][randomJ] = temp;
        }
    }
}

void printBoard() {
    printf("[ B  I  N  G  O ]\n");
    for(int i = 0; i < ROWS; i++) {
        printf("-----------------\n");
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == 0) {
                printf("|%2c ", 'X');
            } else {
                printf("|%2d ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("-----------------\n");
}

int isWinner() {
    int isRowWinner = 0;
    int isColWinner = 0;
    int isDiagWinner1 = 0;
    int isDiagWinner2 = 0;
    for(int i = 0; i < ROWS; i++) {
        // row check
        if(board[i][0] == 0 && board[i][1] == 0 && board[i][2] == 0 
            && board[i][3] == 0 && board[i][4] == 0) {
            isRowWinner = 1;
        }
        // col check
        if(board[0][i] == 0 && board[1][i] == 0 && board[2][i] == 0 
            && board[3][i] == 0 && board[4][i] == 0) {
            isColWinner = 1;
        }
    }
    // diag check 1
    if(board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 
        && board[3][3] == 0 && board[4][4] == 0) {
        isDiagWinner1 = 1;
    }
    // diag check 2
    if(board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 
        && board[3][1] == 0 && board[4][0] == 0) {
        isDiagWinner2 = 1;
    }
    // overall check
    if(isRowWinner == 1 || isColWinner == 1 || isDiagWinner1 == 1 || isDiagWinner2 == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int bingoCounter = 0;
    populateBoard();
    shuffleBoard();
    printf("Welcome to the Bingo Game!\n");
    printf("Here is your Bingo Board:\n");
    printBoard();
    while(1) {
        int userPrompt;
        printf("Enter a number from 1-25: ");
        scanf("%d", &userPrompt);
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(board[i][j] == userPrompt) {
                    board[i][j] = 0;
                    printf("You marked %d\n", userPrompt);
                    bingoCounter++;
                    break;
                }
            }
        }
        printf("Here is your updated Bingo Board:\n");
        printBoard();
        if(isWinner() == 1) {
            printf("BINGO! You won the game in %d tries!\n", bingoCounter);
            break;
        }
    }
    return 0;
}