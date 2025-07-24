//FormAI DATASET v1.0 Category: Table Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

void initializeBoard(int board[][BOARD_SIZE]);
void drawBoard(int board[][BOARD_SIZE]);
void playerMove(int board[][BOARD_SIZE]);
void computerMove(int board[][BOARD_SIZE]);
int checkWin(int board[][BOARD_SIZE]);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int turn, winner, moveCount;
    
    srand(time(NULL)); // seed random number generator
    
    initializeBoard(board);
    drawBoard(board);
    
    for (turn = 0, moveCount = 0; moveCount < BOARD_SIZE*BOARD_SIZE; turn++, moveCount++) {
        if (turn % 2 == 0) {
            printf("Your move:\n");
            playerMove(board);
        }
        else {
            printf("Computer's move:\n");
            computerMove(board);
        }
        
        drawBoard(board);
        
        winner = checkWin(board);
        
        if (winner != 0) {
            break;
        }
    }
    
    if (winner == 1) {
        printf("You win!\n");
    }
    else if (winner == -1) {
        printf("Computer wins!\n");
    }
    else {
        printf("It's a tie!\n");
    }
    
    return 0;
}

void initializeBoard(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0; // 0 means empty square
        }
    }
}

void drawBoard(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                printf("_ ");
            }
            else if (board[i][j] == 1) {
                printf("X ");
            }
            else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

void playerMove(int board[][BOARD_SIZE]) {
    int row, col;
    do {
        printf("Enter row and column (1-3) separated by a space:\n");
        scanf("%d%d", &row, &col);
    } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != 0);
    board[row-1][col-1] = 1;
}

void computerMove(int board[][BOARD_SIZE]) {
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != 0);
    board[row][col] = -1;
}

int checkWin(int board[][BOARD_SIZE]) {
    int i, j, sum;
    // check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        sum = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            sum += board[i][j];
        }
        if (sum == BOARD_SIZE) {
            return 1; // player wins
        }
        else if (sum == -BOARD_SIZE) {
            return -1; // computer wins
        }
    }
    // check columns
    for (j = 0; j < BOARD_SIZE; j++) {
        sum = 0;
        for (i = 0; i < BOARD_SIZE; i++) {
            sum += board[i][j];
        }
        if (sum == BOARD_SIZE) {
            return 1; // player wins
        }
        else if (sum == -BOARD_SIZE) {
            return -1; // computer wins
        }
    }
    // check diagonal (top-left to bottom-right)
    sum = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        sum += board[i][i];
    }
    if (sum == BOARD_SIZE) {
        return 1; // player wins
    }
    else if (sum == -BOARD_SIZE) {
        return -1; // computer wins
    }
    // check diagonal (top-right to bottom-left)
    sum = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        sum += board[i][BOARD_SIZE-1-i];
    }
    if (sum == BOARD_SIZE) {
        return 1; // player wins
    }
    else if (sum == -BOARD_SIZE) {
        return -1; // computer wins
    }
    
    return 0; // no winner
}