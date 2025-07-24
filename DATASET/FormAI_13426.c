//FormAI DATASET v1.0 Category: Checkers Game ; Style: innovative
#include <stdio.h>

// Function to print the board
void printBoard(char board[][8]) {
    printf("   A B C D E F G H\n");
    for (int i = 0; i < 8; i++) {
        printf("%d  ", i + 1);
        for(int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to move the piece
void movePiece(char board[][8], int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = '-';
    if (endX == 0 && board[endX][endY] == 'O') {
        board[endX][endY] = 'K';
    }
    if (endX == 7 && board[endX][endY] == 'X') {
        board[endX][endY] = 'K';
    }
}

// Function to check if a move is valid
int validMove(char board[][8], int startX, int startY, int endX, int endY) {
    // Check if the move is within the board
    if (startX < 0 || startY < 0 || endX < 0 || endY < 0 || startX > 7 || startY > 7 || endX > 7 || endY > 7) {
        return 0;
    }
    // Check if the ending position is empty
    if (board[endX][endY] != '-') {
        return 0;
    }
    // Check if the piece is moving diagonally
    if ((startX - endX != startY - endY) && (startX - endX != endY - startY)) {
        return 0;
    }
    // Check if a normal piece is moving backwards
    if ((board[startX][startY] == 'O' && endX > startX) || (board[startX][startY] == 'X' && endX < startX)) {
        return 0;
    }
    // Check if a normal piece is moving more than one space
    if ((startX - endX == 2 || startX - endX == -2) && (startY - endY == 2 || startY - endY == -2)) {
        if (board[(startX + endX)/2][(startY + endY)/2] != 'X' && board[(startX + endX)/2][(startY + endY)/2] != 'K') {
            return 0;
        }
    }
    // Check if a king is moving more than one space
    if ((board[startX][startY] == 'K' || board[startX][startY] == 'P') && (startX - endX == 2 || startX - endX == -2)) {
        if ((startY - endY == 2 || startY - endY == -2)) {
            if (board[(startX + endX)/2][(startY + endY)/2] != 'X' && board[(startX + endX)/2][(startY + endY)/2] != 'K') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if a piece can jump
int canJump(char board[][8], int x, int y) {
    if (board[x][y] == 'O') {
        if (x > 1 && y > 1 && board[x-1][y-1] == 'X' && board[x-2][y-2] == '-') {
            return 1;
        }
        if (x > 1 && y < 6 && board[x-1][y+1] == 'X' && board[x-2][y+2] == '-') {
            return 1;
        }
    }
    if (board[x][y] == 'X') {
        if (x < 6 && y > 1 && board[x+1][y-1] == 'O' && board[x+2][y-2] == '-') {
            return 1;
        }
        if (x < 6 && y < 6 && board[x+1][y+1] == 'O' && board[x+2][y+2] == '-') {
            return 1;
        }
    }
    if (board[x][y] == 'K') {
        if (x > 1 && y > 1 && board[x-1][y-1] == 'O' && board[x-2][y-2] == '-') {
            return 1;
        }
        if (x > 1 && y < 6 && board[x-1][y+1] == 'O' && board[x-2][y+2] == '-') {
            return 1;
        }
        if (x < 6 && y > 1 && board[x+1][y-1] == 'X' && board[x+2][y-2] == '-') {
            return 1;
        }
        if (x < 6 && y < 6 && board[x+1][y+1] == 'X' && board[x+2][y+2] == '-') {
            return 1;
        }
    }
    return 0;
}

// Function to determine if a player has won
int hasWon(char board[][8], char player) {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == player || board[i][j] == player + 32) {
                count++;
            }
        }
    }
    return count == 0;
}

int main() {
    // Initialize the board
    char board[8][8] = {
        {'-', 'X', '-', 'X', '-', 'X', '-', 'X'},
        {'X', '-', 'X', '-', 'X', '-', 'X', '-'},
        {'-', 'X', '-', 'X', '-', 'X', '-', 'X'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'O', '-', 'O', '-', 'O', '-', 'O', '-'},
        {'-', 'O', '-', 'O', '-', 'O', '-', 'O'},
        {'O', '-', 'O', '-', 'O', '-', 'O', '-'}
    };
    printf("Welcome to Checkers!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n\n");
    printBoard(board);
    int player = 1;
    int startX, startY, endX, endY;
    while (!hasWon(board, player == 1 ? 'O' : 'X')) {
        // Determine the player's move
        printf("Player %d's turn\n", player);
        printf("Enter the start position (e.g. A3): ");
        scanf(" %c%d", &startY, &startX);
        printf("Enter the end position (e.g. B4): ");
        scanf(" %c%d", &endY, &endX);
        startX--;
        startY = startY - 'A';
        endX--;
        endY = endY - 'A';
        if (validMove(board, startX, startY, endX, endY)) {
            movePiece(board, startX, startY, endX, endY);
            if (canJump(board, endX, endY)) {
                printf("You can jump again!\n");
            } else {
                player = player == 1 ? 2 : 1;
            }
            printBoard(board);
        } else {
            printf("Invalid move! Try again.\n\n");
        }
    }
    printf("Player %d has won!\n", player == 1 ? 2 : 1);
    return 0;
}