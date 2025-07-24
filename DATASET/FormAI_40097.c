//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printBoard(int board[ROWS][COLS]);
int checkBingo(int board[ROWS][COLS]);
int generateRandom(int min, int max);

int main() {
    int board[ROWS][COLS] = { 0 };
    int turn = 1;
    int winner = 0;
    
    srand(time(NULL));
    
    while (winner == 0) {
        int row = generateRandom(0, ROWS - 1);
        int col = generateRandom(0, COLS - 1);
        if (board[row][col] == 0) {
            board[row][col] = turn;
            turn++;
        }
        winner = checkBingo(board);
        printBoard(board);
    }
    
    printf("Bingo! Winner is player %d\n", winner);    
    
    return 0;
}

void printBoard(int board[ROWS][COLS]) {
    printf("---------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                printf("   |");
            } else {
                printf(" %2d|", board[i][j]);
            }
        }
        printf("\n---------------\n");
    }
}

int checkBingo(int board[ROWS][COLS]) {
    int winner = 0;
    for (int i = 0; i < ROWS; i++) {
        int sumRow = 0;
        int sumCol = 0;
        for (int j = 0; j < COLS; j++) {
            sumRow += board[i][j];
            sumCol += board[j][i];
        }
        if (sumRow == 15) {
            winner = board[i][0];
            break;
        } else if (sumCol == 15) {
            winner = board[0][i];
            break;
        }
    }
    if (board[0][0] + board[1][1] + board[2][2] + board[3][3] + board[4][4] == 15) {
        winner = board[0][0];
    }
    if (board[0][4] + board[1][3] + board[2][2] + board[3][1] + board[4][0] == 15) {
        winner = board[0][4];
    }
    return winner;
}

int generateRandom(int min, int max) {
    int r = rand() % (max - min + 1) + min;
    return r;
}