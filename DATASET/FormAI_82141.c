//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3

// Function to check if any row is winning
int checkRows(int board[ROWS][COLS]) {
    int i, j, sum;
    for(i = 0; i < ROWS; i++) {
        sum = 0;
        for(j = 0; j < COLS; j++) {
            sum += board[i][j];
        }
        if(sum == 3 || sum == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if any column is winning
int checkCols(int board[ROWS][COLS]) {
    int i, j, sum;
    for(i = 0; i < COLS; i++) {
        sum = 0;
        for(j = 0; j < ROWS; j++) {
            sum += board[j][i];
        }
        if(sum == 3 || sum == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if any diagonal is winning
int checkDiagonals(int board[ROWS][COLS]) {
    int sum = 0, i;
    for(i = 0; i < ROWS; i++) {
        sum += board[i][i];
    }
    if(sum == 3 || sum == 0) {
        return 1;
    }
    sum = 0;
    for(i = ROWS-1; i >= 0; i--) {
        sum += board[ROWS-i-1][i];
    }
    if(sum == 3 || sum == 0) {
        return 1;
    }
    return 0;
}

// Function to print the current status of the board
void printBoard(int board[ROWS][COLS]) {
    int i, j;
    printf("Current Board Status: \n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j] == 1) {
                printf("X\t");
            }
            else if(board[i][j] == 0) {
                printf("O\t");
            }
            else {
                printf("-\t");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS] = {-1};
    int i, j, turn = 1, row, col, computerChoice;
    srand(time(0));

    // Loop until either someone wins or the board fills up
    while(!checkRows(board) && !checkCols(board) && !checkDiagonals(board)) {
        // Print the current status of the board
        printBoard(board);
        // Player's Turn
        if(turn) {
            printf("\nPlayer's Turn (O)\n");
            printf("Enter Row Number (1-%d): ", ROWS);
            scanf("%d", &row);
            printf("Enter Column Number (1-%d): ", COLS);
            scanf("%d", &col);
            if(board[row-1][col-1] != -1) {
                printf("Invalid Move! Try Again!\n");
                continue;
            }
            board[row-1][col-1] = 0;
            turn = 0;
        }
        // Computer's Turn
        else {
            printf("\nComputer's Turn (X)\n");
            do {
                computerChoice = rand() % (ROWS*COLS);
                row = computerChoice / ROWS + 1;
                col = computerChoice % COLS + 1;
            } while(board[row-1][col-1] != -1);
            board[row-1][col-1] = 1;
            turn = 1;
        }
    }

    // Print the final status of the board
    printBoard(board);

    // Print the winner
    if(checkRows(board) || checkCols(board) || checkDiagonals(board)) {
        if(turn == 1) {
            printf("\nPlayer Wins!!!!\n");
        }
        else {
            printf("\nComputer Wins!!!!\n");
        }
    }
    else {
        printf("\nThe Game is a Tie!\n");
    }

    return 0;
}