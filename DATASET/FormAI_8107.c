//FormAI DATASET v1.0 Category: Chess engine ; Style: standalone
#include <stdio.h>

#define WHITE 0
#define BLACK 1

// define the chess board square structure
typedef struct square {
    int piece;          // stores the piece type
    int color;          // stores the color of the piece
    int moved;          // stores whether the piece has moved yet
} Square;

// initialize the chess board
Square board[8][8] = {
    { {1, BLACK, 0}, {2, BLACK, 0}, {3, BLACK, 0}, {4, BLACK, 0}, {5, BLACK, 0}, {3, BLACK, 0}, {2, BLACK, 0}, {1, BLACK, 0} },
    { {6, BLACK, 0}, {6, BLACK, 0}, {6, BLACK, 0}, {6, BLACK, 0}, {6, BLACK, 0}, {6, BLACK, 0}, {6, BLACK, 0}, {6, BLACK, 0} },
    { {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0} },
    { {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0} },
    { {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0} },
    { {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0}, {0, BLACK, 0} },
    { {6, WHITE, 0}, {6, WHITE, 0}, {6, WHITE, 0}, {6, WHITE, 0}, {6, WHITE, 0}, {6, WHITE, 0}, {6, WHITE, 0}, {6, WHITE, 0} },
    { {1, WHITE, 0}, {2, WHITE, 0}, {3, WHITE, 0}, {4, WHITE, 0}, {5, WHITE, 0}, {3, WHITE, 0}, {2, WHITE, 0}, {1, WHITE, 0} }
};

// print the current state of the board
void print_board() {
    int i, j;
    for (i = 7; i >= 0; i--) {
        for (j = 0; j < 8; j++) {
            printf("[%d,%d]", board[i][j].piece, board[i][j].color);
        }
        printf("\n");
    }
}

int main() {
    print_board();
    return 0;
}