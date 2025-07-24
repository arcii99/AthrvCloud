//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Ada Lovelace
// Ada Tic Tac Toe AI Example Program

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define BOARD_SIZE 3

// Functions
void printBoard(char board[][BOARD_SIZE]) {
    printf("\n");
    for(int i=0;i<BOARD_SIZE;i++) {
        for(int j=0;j<BOARD_SIZE;j++) {
            printf(" %c ", board[i][j]);
            if(j != BOARD_SIZE-1) {
                printf("|");
            }
        }
        printf("\n");
        if(i != BOARD_SIZE-1) {
            printf("___|___|___\n");
            printf("   |   |   \n");
        }
    }
    printf("\n");
}

int checkWinner(char board[][BOARD_SIZE], char player) {
    int i, j;

    // Check rows
    for(i=0;i<BOARD_SIZE;i++) {
        int count = 0;
        for(j=0;j<BOARD_SIZE;j++) {
            if(board[i][j] == player) {
                count++;
            }
        }
        if(count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for(j=0;j<BOARD_SIZE;j++) {
        int count = 0;
        for(i=0;i<BOARD_SIZE;i++) {
            if(board[i][j] == player) {
                count++;
            }
        }
        if(count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check diagonal
    int count = 0;
    for(i=0;i<BOARD_SIZE;i++) {
        if(board[i][i] == player) {
            count++;
        }
    }
    if(count == BOARD_SIZE) {
        return 1;
    }

    // Check reverse diagonal
    count = 0;
    for(i=0;i<BOARD_SIZE;i++) {
        if(board[i][BOARD_SIZE-i-1] == player) {
            count++;
        }
    }
    if(count == BOARD_SIZE) {
        return 1;
    }

    return 0;
}

int minimax(char board[][BOARD_SIZE], int depth, int isMaximizingPlayer, char player) {
    int i, j;

    // Base case
    int isGameOver = 1;
    for(i=0;i<BOARD_SIZE;i++) {
        for(j=0;j<BOARD_SIZE;j++) {
            if(board[i][j] == '-') {
                isGameOver = 0;
                break;
            }
        }
        if(!isGameOver) {
            break;
        }
    }
    if(isGameOver) {
        int winner = checkWinner(board, player);
        if(winner == 1) {
            return 10-depth;
        } else {
            return 0;
        }
    }

    if(isMaximizingPlayer) {
        int bestScore = -1000;
        for(i=0;i<BOARD_SIZE;i++) {
            for(j=0;j<BOARD_SIZE;j++) {
                if(board[i][j] == '-') {
                    board[i][j] = player;
                    int score = minimax(board, depth+1, 0, player);
                    board[i][j] = '-';
                    if(score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for(i=0;i<BOARD_SIZE;i++) {
            for(j=0;j<BOARD_SIZE;j++) {
                if(board[i][j] == '-') {
                    board[i][j] = (player == 'X' ? 'O' : 'X');
                    int score = minimax(board, depth+1, 1, player);
                    board[i][j] = '-';
                    if(score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

void aiMakeMove(char board[][BOARD_SIZE], char player) {
    int i, j;
    int bestScore = -1000;
    int bestRow, bestColumn;
    for(i=0;i<BOARD_SIZE;i++) {
        for(j=0;j<BOARD_SIZE;j++) {
            if(board[i][j] == '-') {
                board[i][j] = player;
                int score = minimax(board, 0, 0, player);
                board[i][j] = '-';
                if(score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestColumn = j;
                }
            }
        }
    }
    board[bestRow][bestColumn] = player;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int i, j;
    for(i=0;i<BOARD_SIZE;i++) {
        for(j=0;j<BOARD_SIZE;j++) {
            board[i][j] = '-';
        }
    }

    srand(time(NULL));
    int humanFirst = rand() % 2;

    char humanPlayer = '-';
    char aiPlayer = '-';
    if(humanFirst == 0) {
        printf("You are X and the computer is O!\n");
        humanPlayer = 'X';
        aiPlayer = 'O';
    } else {
        printf("You are O and the computer is X!\n");
        humanPlayer = 'O';
        aiPlayer = 'X';
        aiMakeMove(board, aiPlayer);
    }

    int winner = 0;
    while(!winner) {
        if(humanFirst) {
            int row, column;
            printf("Enter row and column (1-3): ");
            scanf("%d %d", &row, &column);

            if(board[row-1][column-1] == '-') {
                board[row-1][column-1] = humanPlayer;
                printBoard(board);
                winner = checkWinner(board, humanPlayer);
                if(!winner) {
                    aiMakeMove(board, aiPlayer);
                    printBoard(board);
                    winner = checkWinner(board, aiPlayer);
                }
            } else {
                printf("Position already occupied. Try again.\n");
            }
        } else {
            aiMakeMove(board, aiPlayer);
            printBoard(board);
            winner = checkWinner(board, aiPlayer);
            if(!winner) {
                int row, column;
                printf("Enter row and column (1-3): ");
                scanf("%d %d", &row, &column);

                if(board[row-1][column-1] == '-') {
                    board[row-1][column-1] = humanPlayer;
                    printBoard(board);
                    winner = checkWinner(board, humanPlayer);
                } else {
                    printf("Position already occupied. Try again.\n");
                }
            }
        }
    }

    if(winner == 1) {
        printf("Congratulations, you win!\n");
    } else {
        printf("Game over, the computer wins!\n");
    }

    return 0;
}