//FormAI DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>

// A board is represented using a 2D integer array of size 8x8
int board[8][8] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0}
};

// Helper function to print the board
void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Game loop
    while (1) {
        // Print the board
        print_board();

        // Get user input for the move
        int start_x, start_y, end_x, end_y;
        printf("Enter start position (x,y):\n");
        scanf("%d %d", &start_x, &start_y);
        printf("Enter end position (x,y):\n");
        scanf("%d %d", &end_x, &end_y);

        // Check if the move is valid (only diagonal moves are allowed)
        if ((end_x - start_x == 1 || end_x - start_x == -1) && (end_y - start_y == 1 || end_y - start_y == -1)) {
            // Move the piece
            board[start_x][start_y] = 0;
            board[end_x][end_y] = 1;
        } else {
            printf("Invalid move.\n");
        }
    }

    return 0;
}