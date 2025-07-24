//FormAI DATASET v1.0 Category: Checkers Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int board[8][8] = {{0,-1,0,-1,0,-1,0,-1},
                   {-1,0,-1,0,-1,0,-1,0},
                   {0,-1,0,-1,0,-1,0,-1},
                   {0,0,0,0,0,0,0,0},
                   {0,0,0,0,0,0,0,0},
                   {1,0,1,0,1,0,1,0},
                   {0,1,0,1,0,1,0,1},
                   {1,0,1,0,1,0,1,0}};
int player = 1;

int isValidMove(int i, int j, int moveI, int moveJ) {
    if (moveI < 0 || moveJ < 0 || moveI > 7 || moveJ > 7) {
        return 0;
    }
    if (board[moveI][moveJ] != 0) {
        return 0;
    }
    if (player == 1) {
        if (board[i][j] == 1 && (moveI - i == 1) && (abs(moveJ - j) == 1)) {
            return 1;
        }
        if (board[i][j] == 2) {
            if ((moveI - i == 1) && (abs(moveJ - j) == 1)) {
                return 1;
            }
            if ((moveI - i == 2) && (abs(moveJ - j) == 2)) {
                if (board[i+((moveI-i)/2)][j+((moveJ-j)/2)] == -1) {
                    return 1;
                }
            }
        }
    } else if (player == -1) {
        if (board[i][j] == -1 && (moveI - i == -1) && (abs(moveJ - j) == 1)) {
            return 1;
        }
        if (board[i][j] == -2) {
            if ((moveI - i == -1) && (abs(moveJ - j) == 1)) {
                return 1;
            }
            if ((moveI - i == -2) && (abs(moveJ - j) == 2)) {
                if (board[i+((moveI-i)/2)][j+((moveJ-j)/2)] == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int canJump(int i, int j) {
    if (board[i][j] == 1 || board[i][j] == -1) {
        if (isValidMove(i, j, i+2, j+2)
            || isValidMove(i, j, i+2, j-2)
            || isValidMove(i, j, i-2, j+2)
            || isValidMove(i, j, i-2, j-2)) {
            return 1;
        }
    } else if (board[i][j] == 2 || board[i][j] == -2) {
        if (isValidMove(i, j, i+2, j+2)
            || isValidMove(i, j, i+2, j-2)
            || isValidMove(i, j, i-2, j+2)
            || isValidMove(i, j, i-2, j-2)) {
            return 1;
        }        
    }
    return 0;
}

void makeMove(int i, int j, int moveI, int moveJ) {
    board[moveI][moveJ] = board[i][j];
    board[i][j] = 0;
    if ((moveI == 0 && player == -1) || (moveI == 7 && player == 1)) {
        if (board[moveI][moveJ] == 1 || board[moveI][moveJ] == -1) {
            board[moveI][moveJ] *= 2;
        }
    }
    if (abs(moveI-i) == 2) {
        board[i+((moveI-i)/2)][j+((moveJ-j)/2)] = 0;
    }
}

void printBoard() {
    printf("   0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 0) {
                printf(". ");
            } else if (board[i][j] == 1) {
                printf("o ");
            } else if (board[i][j] == 2) {
                printf("O ");
            } else if (board[i][j] == -1) {
                printf("x ");
            } else if (board[i][j] == -2) {
                printf("X ");
            }
        }
        printf("\n");
    }
}

int main() {
    int turn = 1;
    int gameOver = 0;
    printf("Welcome to Checkers!\n\n");
    while (!gameOver) {
        printf("Turn %d:\n", turn);
        printBoard();
        int i, j, moveI, moveJ;
        printf("Player %d's turn.\n", player);
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &i, &j);
        printf("Enter the row and column you want to move to: ");
        scanf("%d %d", &moveI, &moveJ);
        if (isValidMove(i, j, moveI, moveJ)) {
            makeMove(i, j, moveI, moveJ);
            if (canJump(moveI, moveJ)) {
                i = moveI;
                j = moveJ;
                printf("You made a jump! You can jump again!\n");
            } else {
                turn++;
                player *= -1;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
        // Check if the game is over
        int player1 = 0, player2 = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 1 || board[i][j] == 2) {
                    player1++;
                } else if (board[i][j] == -1 || board[i][j] == -2) {
                    player2++;
                }
            }
        }
        if (player1 == 0 || player2 == 0) {
            printf("Game over!\n");
            if (player1 == 0) {
                printf("Player 2 wins!\n");
            } else {
                printf("Player 1 wins!\n");
            }
            gameOver = 1;
        }
    }
    return 0;
}