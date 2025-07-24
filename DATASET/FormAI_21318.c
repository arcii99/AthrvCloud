//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: standalone
#include <stdio.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

void initBoard() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void printBoard() {
    int i, j;
    printf("   ");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", i);
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkWin(char player) {
    int i, j;
    int countRow, countCol, countDiag = 0, countRDiag = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        countRow = 0;
        countCol = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            // Check each row and column
            if (board[i][j] == player) {
                countRow++;
            }
            if (board[j][i] == player) {
                countCol++;
            }
            // Check diagonal
            if (i == j && board[i][j] == player) {
                countDiag++;
            }
            // Check reverse diagonal
            if (i+j == BOARD_SIZE-1 && board[i][j] == player) {
                countRDiag++;
            }
        }
        if (countRow == BOARD_SIZE || countCol == BOARD_SIZE || countDiag == BOARD_SIZE || countRDiag == BOARD_SIZE) {
            return 1;
        }
    }
    return 0;
}

int makeMove(char player, int row, int col) {
    if(row >= BOARD_SIZE || col >= BOARD_SIZE || row < 0 || col < 0 || board[row][col] != '-') {
        return -1;
    }
    board[row][col] = player;
    return 1;
}

int minimax(char player) {
    int i, j, score;
    int bestScore = -2;
    int moveScore = -2;
    int bestRow = -1;
    int bestCol = -1;
 
    if(checkWin('X')) {
        return 1;
    } else if(checkWin('O')) {
        return -1;
    } else if(!checkMovesLeft()) {
        return 0;
    }
 
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == '-') {
                board[i][j] = player;
                if(player == 'X') {
                    score = minimax('O');
                } else {
                    score = minimax('X');
                }
                board[i][j] = '-';
                if(player == 'X' && score > moveScore) {
                    moveScore = score;
                } else if(player == 'O' && score < moveScore) {
                    moveScore = score;
                }
                if(score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
 
    if(moveScore != -2) {
        return moveScore;
    }
    return bestScore;
}

void computerMove() {
    int i, j;
    int bestScore = -2;
    int moveScore = -2;
    int bestRow = -1;
    int bestCol = -1;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == '-') {
                board[i][j] = 'O';
                int score = minimax('X');
                board[i][j] = '-';
                if(score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
    makeMove('O', bestRow, bestCol);
}

int checkMovesLeft() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == '-') {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int row, col;
    printf("Let's play Tic Tac Toe vs the computer!\n");
    initBoard();
    printBoard();
    while(checkMovesLeft() && !checkWin('X') && !checkWin('O')) {
        printf("Your turn.\nEnter a row (0-2): ");
        scanf("%d", &row);
        printf("Enter a col (0-2): ");
        scanf("%d", &col);
        if(makeMove('X', row, col) == -1) {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        printBoard();
        if(!checkMovesLeft() || checkWin('X') || checkWin('O')) {
            break;
        }
        printf("Computer's turn...\n");
        computerMove();
        printBoard();
    }
    if(checkWin('X')) {
        printf("You win!\n");
    } else if(checkWin('O')) {
        printf("Computer wins!\n");
    } else {
        printf("It's a tie.\n");
    }
    return 0;
}