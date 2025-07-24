//FormAI DATASET v1.0 Category: Chess engine ; Style: optimized
#include <stdio.h>

void printBoard(int board[8][8]) {
    int i, j;
    printf("\n");
    for(i = 0; i < 8; i++) {
        printf("+---+---+---+---+---+---+---+---+\n");
        for(j = 0; j < 8; j++) {
            printf("| %d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("+---+---+---+---+---+---+---+---+\n");
}

int main() {
    int board[8][8] = {
        {4, 3, 2, 5, 6, 2, 3, 4},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {-4,-3,-2,-5,-6,-2,-3,-4}
    };

    printBoard(board);

    return 0;
}