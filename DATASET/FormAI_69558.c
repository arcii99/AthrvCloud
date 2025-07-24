//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char player = 'X';
char computer = 'O';

int minimax(int depth, int isMaximizing) {
    int score = eval();

    if (score == 10 || score == -10) return score;

    if (boardFull()) return 0;

    int bestScore;
    if (isMaximizing) {
        bestScore = -1000;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = computer;

                    bestScore = max(bestScore, minimax(depth + 1, !isMaximizing));

                    board[i][j] = ' ';
                }
            }
        }

        return bestScore;
    } else {
        bestScore = 1000;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = player;

                    bestScore = min(bestScore, minimax(depth + 1, !isMaximizing));

                    board[i][j] = ' ';
                }
            }
        }

        return bestScore;
    }
}

void computerMove() {
    int bestScore = -1000, row = 0, col = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = computer;

                int score = minimax(0, 0);

                board[i][j] = ' ';

                if (score > bestScore) {
                    bestScore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }

    board[row][col] = computer;
}

void printBoard() {
    printf("\n");

    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }

    printf("\n");
}

int eval() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == computer) return 10;
            else if (board[i][0] == player) return -10;
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == computer) return 10;
            else if (board[0][i] == player) return -10;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == computer) return 10;
        else if (board[0][0] == player) return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == computer) return 10;
        else if (board[0][2] == player) return -10;
    }

    return 0;
}

int boardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }

    return 1;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    int row, col;
    int gameOver = 0;

    printf("Tic Tac Toe AI\n\n");

    do {
        if (player == 'X') {
            printf("Enter row (1 - 3) and column (1 - 3) separated by space: ");
            scanf("%d %d", &row, &col);
            printf("\n");

            if (row >= 1 && row <= 3 && col >= 1 && col <= 3) {
                row--;
                col--;

                if (board[row][col] == ' ') {
                    board[row][col] = player;
                    player = 'O';
                    computer = 'X';

                    gameOver = eval();
                } else {
                    printf("That cell is already occupied. Try again.\n\n");
                }
            } else {
                printf("Invalid input. Rows and columns are numbered 1 - 3. Try again.\n\n");
            }
        } else {
            printf("Computer is thinking...\n");
            computerMove();

            player = 'X';
            computer = 'O';

            gameOver = eval();
        }

        printBoard();
    } while (!gameOver && !boardFull());

    if (gameOver == 10) {
        printf("Computer wins!\n");
    } else if (gameOver == -10) {
        printf("You win!\n");
    } else {
        printf("Draw.\n");
    }

    return 0;
}