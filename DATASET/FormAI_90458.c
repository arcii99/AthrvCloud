//FormAI DATASET v1.0 Category: Checkers Game ; Style: detailed
#include <stdio.h>

#define SIZE 8

char board[SIZE][SIZE];
char playerOne = 'X';
char playerTwo = 'O';

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) {
                    board[i][j] = playerOne;
                } else if (i > 4) {
                    board[i][j] = playerTwo;
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

void drawBoard() {
    printf("   0  1  2  3  4  5  6  7\n");
    printf("   ----------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d |", i);
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("   ----------------------\n");
}

int isMoveValid(int x1, int y1, int x2, int y2, char player) {
    if (x1 < 0 || x1 > SIZE-1 || y1 < 0 || y1 > SIZE-1 || x2 < 0 || x2 > SIZE-1 || y2 < 0 || y2 > SIZE-1) {
        return 0;
    }

    if (board[x2][y2] != ' ') {
        return 0;
    }

    if (player == playerOne && board[x1][y1] != playerOne && board[x1][y1] != 'X') {
        return 0;
    }
    
    if (player == playerTwo && board[x1][y1] != playerTwo && board[x1][y1] != 'O') {
        return 0;
    }

    if ((x2 - x1) != 1 && (x2 - x1) != -1) {
        return 0;
    }

    if ((y2 - y1) != 1 && (y2 - y1) != -1) {
        return 0;
    }

    if (((x2 - x1) == 1 && player == playerOne) || ((x1 - x2) == 1 && player == playerTwo)) {
        return 0;
    }

    if (abs(y1 - y2) == 1) {
        return 1;
    } else {
        int midX = (x1 + x2) / 2;
        int midY = (y1 + y2) / 2;
        if (board[midX][midY] == ' ') {
            return 0;
        } else if (player == playerOne && board[midX][midY] != playerTwo && board[midX][midY] != 'O') {
            return 0;
        } else if (player == playerTwo && board[midX][midY] != playerOne && board[midX][midY] != 'X') {
            return 0;
        } else {
            return 1;
        }
    }
}

void move(int x1, int y1, int x2, int y2, char player) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = ' ';

    if (abs(y1 - y2) == 2) {
        int midX = (x1 + x2) / 2;
        int midY = (y1 + y2) / 2;
        board[midX][midY] = ' ';
    }

    if (player == playerOne && x2 == SIZE-1) {
        board[x2][y2] = 'K';
    }

    if (player == playerTwo && x2 == 0) {
        board[x2][y2] = 'K';
    }
}

int checkWin(char player) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (player == playerOne && (board[i][j] == playerTwo || board[i][j] == 'O')) {
                return 0;
            } else if (player == playerTwo && (board[i][j] == playerOne || board[i][j] == 'X')) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    initBoard();
    drawBoard();

    char currentPlayer = playerOne;

    while (1) {
        int startX, startY, endX, endY;
        printf("%c's turn\n", currentPlayer);
        printf("Enter starting row: ");
        scanf("%d", &startX);
        printf("Enter starting column: ");
        scanf("%d", &startY);
        printf("Enter ending row: ");
        scanf("%d", &endX);
        printf("Enter ending column: ");
        scanf("%d", &endY);

        if (isMoveValid(startX, startY, endX, endY, currentPlayer)) {
            move(startX, startY, endX, endY, currentPlayer);
            drawBoard();
            
            if (checkWin(currentPlayer)) {
                printf("%c wins!\n", currentPlayer);
                break;
            }

            if (currentPlayer == playerOne) {
                currentPlayer = playerTwo;
            } else {
                currentPlayer = playerOne;
            }
        } else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}