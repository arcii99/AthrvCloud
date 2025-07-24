//FormAI DATASET v1.0 Category: Checkers Game ; Style: realistic
// C Checkers Game Example Program

#include <stdio.h>
#include <stdlib.h>

// Initializing the checkers board
char board[8][8] = {
    {'-', 'B', '-', 'B', '-', 'B', '-', 'B'},
    {'B', '-', 'B', '-', 'B', '-', 'B', '-'},
    {'-', 'B', '-', 'B', '-', 'B', '-', 'B'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'W', '-', 'W', '-', 'W', '-', 'W', '-'},
    {'-', 'W', '-', 'W', '-', 'W', '-', 'W'},
    {'W', '-', 'W', '-', 'W', '-', 'W', '-'}
};

// Function to display the checkers board
void displayBoard() {
    printf("   1  2  3  4  5  6  7  8\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < 8; j++) {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }
}

// Function to move a checker piece
int move(int x1, int y1, int x2, int y2) {
    if (board[x2][y2] != '-') {
        printf("Invalid move. The target square is not empty.\n");
        return 0;
    }
    if (board[x1][y1] == '-') {
        printf("Invalid move. There is no checker on the starting square.\n");
        return 0;
    }
    if (x2 > x1 && board[x1][y1] == 'B') {
        printf("Invalid move. You cannot move a black checker backwards.\n");
        return 0;
    }
    if (x2 < x1 && board[x1][y1] == 'W') {
        printf("Invalid move. You cannot move a white checker backwards.\n");
        return 0;
    }
    if (abs(x2-x1) == 1 && abs(y2-y1) == 1 && board[x1][y1] != 'K') {
        printf("Invalid move. You can only move one square diagonally if you are not a king.\n");
        return 0;
    }
    if (abs(x2-x1) != 2 || abs(y2-y1) != 2) {
        printf("Invalid move. You can only move two squares diagonally to capture an opponent's checker.\n");
        return 0;
    }
    int mid_x = (x1+x2)/2;
    int mid_y = (y1+y2)/2;
    if (board[mid_x][mid_y] == '-') {
        printf("Invalid move. You can only capture an opponent's checker.\n");
        return 0;
    }
    if (board[mid_x][mid_y] == 'B' && board[x1][y1] == 'B') {
        printf("Invalid move. You cannot capture your own checker.\n");
        return 0;
    }
    if (board[mid_x][mid_y] == 'W' && board[x1][y1] == 'W') {
        printf("Invalid move. You cannot capture your own checker.\n");
        return 0;
    }
    // Move the checker
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = '-';
    if (abs(x2-x1) == 2 && abs(y2-y1) == 2) {
        // Capture the opponent's checker
        board[mid_x][mid_y] = '-';
    }
    if (x2 == 0 && board[x2][y2] == 'W') {
        // Promote to king
        board[x2][y2] = 'K';
    }
    if (x2 == 7 && board[x2][y2] == 'B') {
        // Promote to king
        board[x2][y2] = 'K';
    }
    return 1;
}

// Main function
int main() {
    int player = 1;
    int x1, y1, x2, y2;
    do {
        printf("\nPlayer %d's turn:\n", player);
        displayBoard();
        printf("Enter the coordinates of the checker you want to move (row col): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter the coordinates of the square you want to move to (row col): ");
        scanf("%d %d", &x2, &y2);
        if (move(x1-1, y1-1, x2-1, y2-1)) {
            player = (player == 1) ? 2 : 1;
        }
    } while (1);
    return 0;
}