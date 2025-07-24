//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define PLAYER 1
#define COMPUTER 2

#define BOARD_SIZE 3

int board[BOARD_SIZE][BOARD_SIZE];

void initBoard() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void displayBoard() {
    printf("\n\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("\t\t\t");
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == PLAYER) {
                printf(" X ");
            } else if(board[i][j] == COMPUTER) {
                printf(" O ");
            } else {
                printf(" - ");
            }
            if(j < BOARD_SIZE-1) {
                printf("|");
            }
        }
        if(i < BOARD_SIZE-1) {
            printf("\n\t\t\t---------");
        }
        printf("\n");
    }
    printf("\n\n");
}

int isMoveValid(int row, int col) {
    if(row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0) {
        return 1;
    }
    return 0;
}

int checkWin(int player) {
    // Check rows
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check columns
    for(int j=0; j<BOARD_SIZE; j++) {
        if(board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return 1;
        }
    }
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

int evaluateBoard() {
    if(checkWin(PLAYER)) {
        return -10;
    } else if(checkWin(COMPUTER)) {
        return 10;
    } else {
        return 0;
    }
}

int minimax(int depth, int isMax) {
    int score = evaluateBoard();
    if(score == 10 || score == -10) {
        return score;
    }
    if(depth == 0) {
        return 0;
    }
    if(isMax) {
        int best = -1000;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == 0) {
                    board[i][j] = COMPUTER;
                    best = (best > minimax(depth-1, !isMax)) ? best : minimax(depth-1, !isMax);
                    board[i][j] = 0;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == 0) {
                    board[i][j] = PLAYER;
                    best = (best < minimax(depth-1, !isMax)) ? best : minimax(depth-1, !isMax);
                    board[i][j] = 0;
                }
            }
        }
        return best;
    }
}

void computerMove() {
    int bestScore = -1000;
    int bestRow = -1;
    int bestCol = -1;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 0) {
                board[i][j] = COMPUTER;
                int score = minimax(4, 0);
                board[i][j] = 0;
                if(score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    board[bestRow][bestCol] = COMPUTER;
}

void playerMove() {
    int row, col, validMove;
    do {
        printf("\nEnter your move (row col): ");
        scanf("%d %d", &row, &col);
        row--;
        col--;
        validMove = isMoveValid(row, col);
        if(!validMove) {
            printf("\nInvalid move, try again!");
        }
    } while(!validMove);
    board[row][col] = PLAYER;
}

int isBoardFull() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void playGame() {
    initBoard();
    int currentPlayer = PLAYER;
    int gameEnded = checkWin(PLAYER) || checkWin(COMPUTER) || isBoardFull();
    while(!gameEnded) {
        if(currentPlayer == PLAYER) {
            displayBoard();
            playerMove();
            gameEnded = checkWin(PLAYER) || checkWin(COMPUTER) || isBoardFull();
            currentPlayer = COMPUTER;
        } else {
            computerMove();
            gameEnded = checkWin(PLAYER) || checkWin(COMPUTER) || isBoardFull();
            currentPlayer = PLAYER;
        }
    }
    displayBoard();
    if(checkWin(PLAYER)) {
        printf("\nCongratulations, you win!\n");
    } else if(checkWin(COMPUTER)) {
        printf("\nBetter luck next time, computer wins!\n");
    } else {
        printf("\nIt's a draw!\n");
    }
}

int main() {
    playGame();
    return 0;
}