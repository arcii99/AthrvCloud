//FormAI DATASET v1.0 Category: Chess engine ; Style: mathematical
#include <stdio.h>

// Chess board using 1D array
int chessboard[64] = {
    -4, -2, -3, -5, -6, -3, -2, -4,
    -1, -1, -1, -1, -1, -1, -1, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    4, 2, 3, 5, 6, 3, 2, 4,
};

// Function to print chess board
void print_board() {
    printf("\n");
    for (int i = 0; i < 64; i++) {
        if (i % 8 == 0 && i != 0) {
            printf("\n");
        }
        printf("%d\t", chessboard[i]);
    }
    printf("\n");
}

int main() {
    // Starting position of a game
    print_board();
    return 0;
}