//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: energetic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char AI = 'O', human = 'X';

void welcomeMessage() {
    printf("\tLet's Play Tic Tac Toe!\n");
    printf("You are playing against the AI. The AI is 'O' and you are 'X'.\n\n");
    printf("To make your move, enter row number and column number such as 1 2.\n");
    printf("Let's get started!\n\n");
}

void printBoard() {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

bool boardFull() {
    int i, j;
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool win(char player) {
    // checking rows
    for (int i=0; i<3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    // checking columns
    for (int j=0; j<3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }

    // checking diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool gameOver() {
    return win(human) || win(AI) || boardFull();
}

void humanMove() {
    int row, col;
    printf("Your turn. Enter row number and column number: ");
    scanf("%d %d", &row, &col);

    // check boundaries of row and col
    while (row>3 || row<1 || col>3 || col<1 || board[row-1][col-1]!=' ') {
        printf("Invalid! The cell is either occupied or out of range. Enter again: ");
        scanf("%d %d", &row, &col);
    }

    board[row-1][col-1] = human;
    printBoard();
}

int evaluate() {
    if (win(AI))
        return 10;
    else if (win(human))
        return -10;
    else
        return 0;
}

int minimax(int depth, bool maximizingPlayer) {
    int score = evaluate();

    if (score != 0)
        return score;

    if (boardFull())
        return 0;

    if (maximizingPlayer) {
        int bestScore = -1000;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = AI;
                    int score = minimax(depth+1, false);
                    board[i][j] = ' ';

                    if (score > bestScore)
                        bestScore = score;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = human;
                    int score = minimax(depth+1, true);
                    board[i][j] = ' ';

                    if (score < bestScore)
                        bestScore = score;
                }
            }
        }
        return bestScore;
    }
}

void AIMove() {
    int bestScore = -1000;
    int row, col;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = AI;
                int score = minimax(0, false);
                board[i][j] = ' ';

                if (score > bestScore) {
                    bestScore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }

    board[row][col] = AI;
    printf("My turn! I put 'O' in row %d column %d.\n", row+1, col+1);
    printBoard();
}

void playGame() {
    welcomeMessage();
    printBoard();

    while (!gameOver()) {
        humanMove();
        if (gameOver())
            break;
        printf("\n");
        AIMove();
        printf("\n");
    }

    if (win(human))
        printf("Congratulations! You won.\n");
    else if (win(AI))
        printf("Sorry! I won.\n");
    else
        printf("It was a tie.\n");
}

int main() {
    playGame();
    return 0;
}