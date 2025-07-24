//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int main()
{
    int board[ROW][COL];
    int i, j, x, y, score;

    // Initialize board with random numbers
    srand(time(NULL));
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = rand() % 2;
        }
    }

    // Initialize score
    score = 0;

    // Loop until board is completely cleared
    while (1) {

        // Print board
        printf("\nScore: %d\n\n", score);
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Get user input
        printf("\nEnter row/column to clear (e.g. 3,4): ");
        scanf("%d,%d", &x, &y);

        // Check if input is valid and in range
        if (x < 0 || x >= ROW || y < 0 || y >= COL) {
            printf("\nInvalid input. Please enter a row/column in range.\n");
            continue;
        }

        // Clear selected cell and its neighbors recursively
        if (board[x][y]) {
            score++;
            board[x][y] = 0;
            if (x > 0) clear(board, x-1, y);
            if (x < ROW-1) clear(board, x+1, y);
            if (y > 0) clear(board, x, y-1);
            if (y < COL-1) clear(board, x, y+1);
        }

        // Check if board is completely cleared
        if (is_cleared(board)) {
            printf("\nCongratulations! You cleared the board!\n");
            printf("Final Score: %d\n", score);
            break;
        }
    }

    return 0;
}

// Clear selected cell and its neighbors recursively
void clear(int board[][COL], int x, int y)
{
    if (board[x][y]) {
        board[x][y] = 0;
        if (x > 0) clear(board, x-1, y);
        if (x < ROW-1) clear(board, x+1, y);
        if (y > 0) clear(board, x, y-1);
        if (y < COL-1) clear(board, x, y+1);
    }
}

// Check if board is completely cleared
int is_cleared(int board[][COL])
{
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (board[i][j]) return 0;
        }
    }
    return 1;
}