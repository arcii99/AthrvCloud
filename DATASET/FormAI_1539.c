//FormAI DATASET v1.0 Category: Checkers Game ; Style: introspective
#include <stdio.h>

// Function to initialize the board with pieces
void initializeBoard(int board[][8]) {
    int i, j;
    // Filling the black cells with black pieces
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 8; j++) {
            if ((i+j)%2 == 0) {
                board[i][j] = -1;   // -1 indicates a black piece
            }
        }
    }
    // Filling the white cells with white pieces
    for (i = 5; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if ((i+j)%2 == 0) {
                board[i][j] = 1;    // 1 indicates a white piece
            }
        }
    }
}

// Function to print the board
void printBoard(int board[][8]) {
    int i, j;
    printf("   0  1  2  3  4  5  6  7 \n");
    for (i = 0; i < 8; i++) {
        printf("%d ", i);
        for (j = 0; j < 8; j++) {
            printf("|");
            switch (board[i][j]) {
                case -1:
                    printf(" B ");
                    break;
                case 0:
                    printf("   ");
                    break;
                case 1:
                    printf(" W ");
                    break;
            }
        }
        printf("|\n");
    }
}

// Function to move a piece
void movePiece(int board[][8], int sx, int sy, int dx, int dy) {
    int temp = board[sx][sy];
    board[sx][sy] = board[dx][dy];
    board[dx][dy] = temp;   
}

// Function to check if a move is valid
int checkValidMove(int board[][8], int sx, int sy, int dx, int dy, int player) {
    if (dx < 0 || dx > 7 || dy < 0 || dy > 7) {
        return 0;
    }
    if (board[dx][dy] != 0) {
        return 0;
    }
    if (player == 1) {
        if (board[sx][sy] == 1 && dx > sx) {
            return 0;
        }
        if (board[sx][sy] == 1 && dx == sx-1 && (dy == sy+1 || dy == sy-1)) {
            return 1;
        }
        if (dx == sx-1 && (dy == sy+1 || dy == sy-1)) {
            return 1;
        }
        if (dx == sx-2 && dy == sy+2 && board[sx-1][sy+1] == -1) {
            return 1;
        }
        if (dx == sx-2 && dy == sy-2 && board[sx-1][sy-1] == -1) {
            return 1;
        }
    }
    else {
        if (board[sx][sy] == -1 && dx < sx) {
            return 0;
        }
        if (board[sx][sy] == -1 && dx == sx+1 && (dy == sy+1 || dy == sy-1)) {
            return 1;
        }
        if (dx == sx+1 && (dy == sy+1 || dy == sy-1)) {
            return 1;
        }
        if (dx == sx+2 && dy == sy+2 && board[sx+1][sy+1] == 1) {
            return 1;
        }
        if (dx == sx+2 && dy == sy-2 && board[sx+1][sy-1] == 1) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the game has ended
int checkEndGame(int board[][8]) {
    int i, j, blackCount = 0, whiteCount = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == -1) {
                blackCount++;
            }
            else if (board[i][j] == 1) {
                whiteCount++;
            }
        }
    }
    if (blackCount == 0) {
        return 1;
    }
    else if (whiteCount == 0) {
        return -1;
    }
    else {
        return 0;
    }
}

// Main function
int main() {
    int board[8][8] = {0};      // 0 indicates an empty cell
    int player = 1, endGame = 0, sx, sy, dx, dy, isValidMove;
    initializeBoard(board);
    while (endGame == 0) {
        printBoard(board);
        if (player == 1) {
            printf("\nPlayer 1's turn (W):\n");
        }
        else {
            printf("\nPlayer 2's turn (B):\n");
        }
        printf("Enter the coordinates of the piece to be moved (row column): ");
        scanf("%d %d", &sx, &sy);
        printf("Enter the coordinates of the destination (row column): ");
        scanf("%d %d", &dx, &dy);
        isValidMove = checkValidMove(board, sx, sy, dx, dy, player);
        if (isValidMove) {
            movePiece(board, sx, sy, dx, dy);
            if ((player == 1 && dx == 0) || (player == -1 && dx == 7)) {
                board[dx][dy] = player*2;   // 2 indicates a king piece
            }
            if ((player == 1 && checkValidMove(board, dx, dy, dx-2, dy-2, player)) || (player == -1 && checkValidMove(board, dx, dy, dx+2, dy-2, player)) || (player == 1 && checkValidMove(board, dx, dy, dx-2, dy+2, player)) || (player == -1 && checkValidMove(board, dx, dy, dx+2, dy+2, player))) {
                if (player == 1) {
                    printf("Player 1 (W) can make another move.\n");
                }
                else {
                    printf("Player 2 (B) can make another move.\n");
                }
            }
            else {
                player *= -1;
            }
        }
        else {
            printf("Invalid move. Please try again.\n");
        }
        endGame = checkEndGame(board);
    }
    printBoard(board);
    if (endGame == 1) {
        printf("Player 2 (B) wins.\n");
    }
    else {
        printf("Player 1 (W) wins.\n");
    }
    return 0;
}