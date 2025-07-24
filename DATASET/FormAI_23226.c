//FormAI DATASET v1.0 Category: Checkers Game ; Style: happy
#include <stdio.h>

// function to print the board
void printBoard(int board[][8]) {
    printf("    0 1 2 3 4 5 6 7\n");
    printf("   -----------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%d | ", i);
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 0) printf("  ");
            else printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("   -----------------\n");
}

// function to move the piece
void movePiece(int board[][8], int from[], int to[], int turn) {
    int x1 = from[0], y1 = from[1], x2 = to[0], y2 = to[1];
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = 0;
    if (turn == 1 && x2 == 7) {
        board[x2][y2] = 'K';
    }
    if (turn == -1 && x2 == 0) {
        board[x2][y2] = 'Q';
    }
}

// function to check if the move is valid
int isValidMove(int board[][8], int from[], int to[], int turn) {
    int x1 = from[0], y1 = from[1], x2 = to[0], y2 = to[1];
    if (x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
        printf("Invalid move! Out of bounds.\n");
        return 0;
    }
    if (board[x2][y2] != 0) {
        printf("Invalid move! Square already occupied.\n");
        return 0;
    }
    if (board[x1][y1] == 'O' || board[x1][y1] == 'X') {
        printf("Invalid move! Invalid piece.\n");
        return 0;
    }
    if (board[x1][y1] == 'K' || board[x1][y1] == 'Q') {
        if (abs(x2-x1) != abs(y2-y1)) {
            printf("Invalid move! Wrong direction.\n");
            return 0;
        }
        if (abs(x2-x1) > 2) {
            printf("Invalid move! Too far.\n");
            return 0;
        }
        if (abs(x2-x1) == 2) {
            int midx = (x1+x2)/2, midy = (y1+y2)/2;
            if (board[midx][midy] != -1 * turn) {
                printf("Invalid move! No piece to jump over.\n");
                return 0;
            }
            board[midx][midy] = 0;
        }
        return 1;
    }
    if (turn == 1 && x2-x1 == 1 && abs(y2-y1) == 1) return 1;
    if (turn == -1 && x1-x2 == 1 && abs(y2-y1) == 1) return 1;
    printf("Invalid move! Wrong direction.\n");
    return 0;
}

int main() {
    // initialize the board
    int board[8][8] = {0};
    board[0][1] = board[0][3] = board[0][5] = -1;
    board[1][0] = board[1][2] = board[1][4] = board[1][6] = -1;
    board[2][1] = board[2][3] = board[2][5] = -1;
    board[5][0] = board[5][2] = board[5][4] = board[5][6] = 1;
    board[6][1] = board[6][3] = board[6][5] = 1;
    board[7][0] = board[7][2] = board[7][4] = 1;

    // game loop
    int turn = 1, gameOver = 0;
    while (!gameOver) {
        printf("It's %s turn.\n", turn == 1 ? "white" : "black");
        printBoard(board);
        int from[2], to[2];
        printf("Enter the position of the piece to move (row col): ");
        scanf("%d %d", &from[0], &from[1]);
        printf("Enter the position to move the piece to (row col): ");
        scanf("%d %d", &to[0], &to[1]);
        if (isValidMove(board, from, to, turn)) {
            movePiece(board, from, to, turn);
            turn *= -1;
        }
        // check for game over
        int whiteCount = 0, blackCount = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'K' || board[i][j] == 'Q') {
                    if (board[i][j] == 'K') whiteCount++;
                    if (board[i][j] == 'Q') blackCount++;
                }
            }
        }
        if (whiteCount == 1 && blackCount == 0) {
            printf("White wins!\n");
            gameOver = 1;
        }
        if (whiteCount == 0 && blackCount == 1) {
            printf("Black wins!\n");
            gameOver = 1;
        }
    }
    return 0;
}