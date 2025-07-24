//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7

void print_board(int board[ROWS][COLS]) {
    printf(" 1 2 3 4 5 6 7\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            switch(board[i][j]) {
                case 0:
                    printf("| |");
                    break;
                case 1:
                    printf("|X|");
                    break;
                case -1:
                    printf("|O|");
                    break;
            }
        }
        printf("\n");
    }
}

void player_move(int board[ROWS][COLS], int player) {
    int col;
    printf("Player %d, enter column (1-7): ", player);
    scanf("%d", &col);
    col--;
    for(int i = ROWS-1; i >= 0; i--) {
        if(board[i][col] == 0) {
            board[i][col] = player == 1 ? 1 : -1;
            return;
        }
    }
}

int check_win(int board[ROWS][COLS]) {
    int count;
    // Check rows
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS-3; j++) {
            count = 0;
            for(int k = 0; k < 4; k++) {
                count += board[i][j+k];
            }
            if(count == 4 || count == -4) {
                return count / 4;
            }
        }
    }
    // Check columns
    for(int i = 0; i < ROWS-3; i++) {
        for(int j = 0; j < COLS; j++) {
            count = 0;
            for(int k = 0; k < 4; k++) {
                count += board[i+k][j];
            }
            if(count == 4 || count == -4) {
                return count / 4;
            }
        }
    }
    // Check diagonals
    for(int i = 0; i < ROWS-3; i++) {
        for(int j = 0; j < COLS-3; j++) {
            count = 0;
            for(int k = 0; k < 4; k++) {
                count += board[i+k][j+k];
            }
            if(count == 4 || count == -4) {
                return count / 4;
            }
        }
    }
    for(int i = 3; i < ROWS; i++) {
        for(int j = 0; j < COLS-3; j++) {
            count = 0;
            for(int k = 0; k < 4; k++) {
                count += board[i-k][j+k];
            }
            if(count == 4 || count == -4) {
                return count / 4;
            }
        }
    }
    return 0;
}

int main() {
    int board[ROWS][COLS] = {0};
    int player = 1;
    int winner = 0;
    srand(time(NULL));
    printf("Welcome to the C Table Game!\n");
    printf("The objective of this game is to connect four pieces of your own color in a row, column, or diagonal.\n");
    printf("The player with the most possible connections possible without creating 4 in a row wins.\n");
    printf("The first player will be chosen randomly.\n");
    player = rand() % 2 + 1;
    while(1) {
        printf("\nCurrent board:\n");
        print_board(board);
        player_move(board, player);
        winner = check_win(board);
        if(winner != 0) {
            printf("\nPlayer %d wins!\n", winner);
            break;
        }
        // Check if board is full
        int count = 0;
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(board[i][j] != 0) {
                    count++;
                }
            }
        }
        if(count == ROWS*COLS) {
            printf("\nBoard is full. It's a tie!\n");
            break;
        }
        player = player == 1 ? 2 : 1;
    }
    return 0;
}