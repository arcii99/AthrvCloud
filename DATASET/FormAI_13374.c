//FormAI DATASET v1.0 Category: Table Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void print_board(int board[ROWS][COLS]) {
    int i, j;
    printf("\n");
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board[i][j] == 0) {
                printf(" ");
            }
            else if (board[i][j] == 1) {
                printf("x");
            }
            else {
                printf("o");
            }
            if(j != COLS-1) {
                printf("|");
            }
        }
        if(i != ROWS-1) {
            printf("\n- - -\n");
        }
    }
    printf("\n\n");
}

int check_win(int board[ROWS][COLS]) {
    int i, j;
    // Check rows
    for(i=0; i<ROWS; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for(j=0; j<COLS; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // Check for tie
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(board[i][j] == 0) {
                return -1;
            }
        }
    }
    // Draw
    return 0;
}

int main() {
    int board[ROWS][COLS] = {{0,0,0}, {0,0,0}, {0,0,0}};
    int player = 1, row, col, result;
    srand(time(NULL));
    printf("Welcome to Tic Tac Toe!\n");
    while(1) {
        print_board(board);
        printf("Player %d's turn.\n", player);
        if(player == 1) {
            printf("Enter row (1-3): ");
            scanf("%d", &row);
            printf("Enter column (1-3): ");
            scanf("%d", &col);
        }
        else {
            row = rand() % 3 + 1;   // computer's turn
            col = rand() % 3 + 1;
            printf("Computer chooses row %d and column %d.\n", row, col);
        }
        if(row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid row/column. Try again.\n");
            continue;
        }
        if(board[row-1][col-1] != 0) {
            printf("That spot is already taken. Try again.\n");
            continue;
        }
        board[row-1][col-1] = player;
        result = check_win(board);
        if(result != -1) {
            break;
        }
        player = (player == 1) ? 2 : 1; // switch players
    }
    print_board(board);
    if(result == 0) {
        printf("The game is a draw.\n");
    }
    else {
        printf("Player %d wins!\n", result);
    }
    return 0;
}