//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define HUMAN_PLAYER 'X'
#define AI_PLAYER 'O'
#define BLANK_SPACE ' '

void printBoard(char board[][SIZE]) {
    printf("\n-------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n-------------\n");
    }
}

int checkWin(char board[][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        else if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    else if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int checkTie(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == BLANK_SPACE) {
                return 0;
            }
        }
    }
    return 1;
}

int miniMax(char board[][SIZE], int depth, int isMax, char player) {
    int score = 0;
    int bestScore = isMax ? -100 : 100;

    if (checkWin(board, AI_PLAYER)) {
        return 10 - depth;
    }
    else if (checkWin(board, HUMAN_PLAYER)) {
        return depth - 10;
    }
    else if (checkTie(board)) {
        return 0;
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == BLANK_SPACE) {
                board[i][j] = player;
                if (player == AI_PLAYER) {
                    score = miniMax(board, depth+1, !isMax, HUMAN_PLAYER);
                }
                else {
                    score = miniMax(board, depth+1, !isMax, AI_PLAYER);
                }
                board[i][j] = BLANK_SPACE;

                if (isMax && score > bestScore) {
                    bestScore = score;
                }
                else if (!isMax && score < bestScore) {
                    bestScore = score;
                }
            }
        }
    }

    return bestScore;
}

void aiMove(char board[][SIZE]) {
    int bestScore = -100;
    int row = -1, col = -1;
    int score = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == BLANK_SPACE) {
                board[i][j] = AI_PLAYER;
                score = miniMax(board, 0, 0, HUMAN_PLAYER);
                board[i][j] = BLANK_SPACE;

                if (score > bestScore) {
                    bestScore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    board[row][col] = AI_PLAYER;
}

int main() {
    char board[SIZE][SIZE];
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = BLANK_SPACE;
        }
    }

    printf("\nWelcome to Tic Tac Toe!\nYou are playing as '%c', AI is playing as '%c'\n", HUMAN_PLAYER, AI_PLAYER);

    while (1) {
        printBoard(board);

        printf("\nIt's your turn! Choose a position (1-9): ");
        int humanPos;
        scanf("%d", &humanPos);
        humanPos--;

        int row = humanPos / SIZE;
        int col = humanPos % SIZE;

        if (board[row][col] == BLANK_SPACE) {
            board[row][col] = HUMAN_PLAYER;
        }
        else {
            printf("\nThat position is already taken. Choose another position.\n");
            continue;
        }

        if (checkWin(board, HUMAN_PLAYER)) {
            printBoard(board);
            printf("\nCongratulations! You won!\n");
            break;
        }

        if (checkTie(board)) {
            printBoard(board);
            printf("\nIt's a tie!\n");
            break;
        }

        aiMove(board);
        if (checkWin(board, AI_PLAYER)) {
            printBoard(board);
            printf("\nThe AI has won! Better luck next time.\n");
            break;
        }

        if (checkTie(board)) {
            printBoard(board);
            printf("\nIt's a tie!\n");
            break;
        }
    }

    return 0;
}