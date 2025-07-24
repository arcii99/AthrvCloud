//FormAI DATASET v1.0 Category: Checkers Game ; Style: immersive
#include <stdio.h>

int main() {
    int board[8][8] = {  // Initialize the starting board
        {-1, 0,-1, 0,-1, 0,-1, 0},
        { 0,-1, 0,-1, 0,-1, 0,-1},
        {-1, 0,-1, 0,-1, 0,-1, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 1, 0, 1, 0, 1, 0, 1},
        { 1, 0, 1, 0, 1, 0, 1, 0},
        { 0, 1, 0, 1, 0, 1, 0, 1}
    };

    // Game loop
    while (1) {
        // Print the current board
        printf("  0 1 2 3 4 5 6 7\n");
        for (int i = 0; i < 8; i++) {
            printf("%d ", i);
            for (int j = 0; j < 8; j++) {
                switch (board[i][j]) {
                    case -1: printf("O "); break;
                    case 0: printf("  "); break;
                    case 1: printf("X "); break;
                }
            }
            printf("%d\n", i);
        }
        printf("  0 1 2 3 4 5 6 7\n");

        // Prompt the player for their move
        printf("Enter the row and column of the piece you want to move: ");
        int sr, sc;
        scanf("%d%d", &sr, &sc);

        printf("Enter the row and column of where you want to move it: ");
        int er, ec;
        scanf("%d%d", &er, &ec);

        // Check if the move is valid
        if (board[sr][sc] != 1) {
            printf("Invalid move: you don't have a piece there\n");
            continue;
        }
        if (board[er][ec] != 0) {
            printf("Invalid move: destination is not empty\n");
            continue;
        }
        if (er != sr + 1 || (ec != sc - 1 && ec != sc + 1)) {
            printf("Invalid move: you can only move diagonally one space\n");
            continue;
        }

        // Move the piece
        board[sr][sc] = 0;
        board[er][ec] = 1;
    }

    return 0;
}