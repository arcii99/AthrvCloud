//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include<stdio.h>
#include<stdlib.h>

#define PLAYER 0
#define COMPUTER 1
#define EMPTY 2

#define ROW 3
#define COLUMN 3

#define COMPUTERMOVE 10
#define PLAYERMOVE -10

int evaluateBoard(int board[ROW][COLUMN]);
int checkWin(int board[ROW][COLUMN]);
void printBoard(int board[ROW][COLUMN]);
int minimax(int board[ROW][COLUMN], int depth, int isMaximizer);
int findBestMove(int board[ROW][COLUMN]);

int main()
{
    int board[ROW][COLUMN] = { {EMPTY, EMPTY, EMPTY},
                               {EMPTY, EMPTY, EMPTY},
                               {EMPTY, EMPTY, EMPTY} };
    int turn = PLAYER;
    while (checkWin(board) == 0 && evaluateBoard(board) != 0) {
        printBoard(board);
        if (turn == PLAYER) {
            int row, column;
            printf("Player's turn:\nEnter row and column indices (1-3): ");
            scanf("%d%d", &row, &column);
            if (board[row - 1][column - 1] == EMPTY) {
                board[row - 1][column - 1] = PLAYER;
                turn = COMPUTER;
            }
        }
        else {
            printf("\nComputer's turn...\n");
            int bestMove = findBestMove(board);
            int row = bestMove / 3;
            int column = bestMove % 3;
            board[row][column] = COMPUTER;
            turn = PLAYER;
        }
    }
    if (checkWin(board) == 0)
        printf("\nIt's a tie!\n");
    else if (checkWin(board) == COMPUTER)
        printf("\nComputer wins!\n");
    else
        printf("\nPlayer wins!\n");
    printBoard(board);
    return 0;
}

int evaluateBoard(int board[ROW][COLUMN])
{
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            if (board[i][j] == EMPTY)
                return 1;
        }
    }
    return 0;
}

int checkWin(int board[ROW][COLUMN])
{
    int i, j;
    // Check rows
    for (i = 0; i < ROW; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == PLAYER)
                return PLAYERMOVE;
            else if (board[i][0] == COMPUTER)
                return COMPUTERMOVE;
        }
    }
    // Check columns
    for (j = 0; j < COLUMN; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == PLAYER)
                return PLAYERMOVE;
            else if (board[0][j] == COMPUTER)
                return COMPUTERMOVE;
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == PLAYER)
            return PLAYERMOVE;
        else if (board[0][0] == COMPUTER)
            return COMPUTERMOVE;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == PLAYER)
            return PLAYERMOVE;
        else if (board[0][2] == COMPUTER)
            return COMPUTERMOVE;
    }
    return 0;
}

void printBoard(int board[ROW][COLUMN])
{
    int i, j;
    printf("\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            if(board[i][j] == PLAYER)
                printf("| X |");
            else if(board[i][j] == COMPUTER)
                printf("| O |");
            else
                printf("|   |");
        }
        printf("\n");
    }
}

int minimax(int board[ROW][COLUMN], int depth, int isMaximizer)
{
    int score = checkWin(board);
    if (score == COMPUTERMOVE || score == PLAYERMOVE)
        return score;
    if (evaluateBoard(board) == 0)
        return 0;
    if (isMaximizer) {
        int best = -1000;
        int i, j;
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COLUMN; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = COMPUTER;
                    int value = minimax(board, depth + 1, 0);
                    best = (value > best) ? value : best;
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
    else {
        int best = 1000;
        int i, j;
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COLUMN; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER;
                    int value = minimax(board, depth + 1, 1);
                    best = (value < best) ? value : best;
                    board[i][j] = EMPTY;
                }
            }
        }
        return best;
    }
}

int findBestMove(int board[ROW][COLUMN])
{
    int bestValue = -1000;
    int bestMove = -1;
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COLUMN; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = COMPUTER;
                int moveValue = minimax(board, 0, 0);
                board[i][j] = EMPTY;
                if (moveValue > bestValue) {
                    bestValue = moveValue;
                    bestMove = i * 3 + j;
                }
            }
        }
    }
    return bestMove;
}