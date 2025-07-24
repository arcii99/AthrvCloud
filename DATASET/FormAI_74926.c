//FormAI DATASET v1.0 Category: Table Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

char board[ROWS][COLS] = {'1','2','3','4','5','6','7','8','9'};
char playerMark = 'X', computerMark = 'O';

int isMovePossible(int row, int col){
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        return 1;
    if (board[row][col] == 'X' || board[row][col] == 'O')
        return 1;
    return 0;
}

void displayBoard() {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++)
            printf("%c\t", board[i][j]);
        printf("\n");
    }
}

int checkWin() {
    int i;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

int evaluate() {
    int i;
    for (i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == playerMark)
                return -1;
            else if (board[i][0] == computerMark)
                return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == playerMark)
                return -1;
            else if (board[0][i] == computerMark)
                return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == playerMark)
            return -1;
        else if (board[0][0] == computerMark)
            return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == playerMark)
            return -1;
        else if (board[0][2] == computerMark)
            return 1;
    }
    return 0;
}

int minimax(int depth, int isMaxPlayer) {
    int i, j, score, bestScore;
    bestScore = isMaxPlayer ? -100000 : 100000;
    if (depth == 0 || checkWin())
        return evaluate();
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (!isMovePossible(i, j))
                continue;
            board[i][j] = isMaxPlayer ? computerMark : playerMark;
            score = minimax(depth - 1, !isMaxPlayer);
            board[i][j] = (i * 3) + (j + 1) + '0';
            if (isMaxPlayer) {
                if (score > bestScore)
                    bestScore = score;
            } else {
                if (score < bestScore)
                    bestScore = score;
            }
        }
    }
    return bestScore;
}

void computerMove() {
    int i, j, bestScore = -100000, score;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (!isMovePossible(i, j))
                continue;
            board[i][j] = computerMark;
            score = minimax(9, 0);
            board[i][j] = (i * 3) + (j + 1) + '0';
            if (score > bestScore) {
                bestScore = score;
                playerMark = computerMark;
            }
        }
    }
    board[(rand() % ROWS)][(rand() % COLS)] = computerMark;
}

void playerMove() {
    int row, col;
    printf("\nEnter position to place 'X': ");
    scanf("%d", &row);
    if (row > 0 && row < 10) {
        row--;
        col = (row % 3);
        row /= 3;
        if (isMovePossible(row, col))
            board[row][col] = playerMark;
        else {
            printf("\nInvalid move! Try again.");
            playerMove();
        }
    } else {
        printf("\nInvalid input! Try again.");
        playerMove();
    }
}

int main()
{
    int i, j, movesLeft = 9;
    srand(time(NULL));
    printf("******************WELCOME TO TIC-TAC-TOE GAME*****************\n");
    printf("Positions on the board are:\n");
    displayBoard();
    while (movesLeft) {
        playerMove();
        movesLeft--;
        if (checkWin()) {
            displayBoard();
            printf("\nYOU WIN!\n");
            break;
        }
        if (!movesLeft)
            break;
        computerMove();
        movesLeft--;
        displayBoard();
        if (checkWin()) {
            printf("\nCOMPUTER WINS!\n");
            break;
        }
    }
    if (movesLeft == 0 && !checkWin())
        printf("\nITS A TIE\n");
    printf("\nTHANK YOU FOR PLAYING\n");
    return 0;
}