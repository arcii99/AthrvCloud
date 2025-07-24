//FormAI DATASET v1.0 Category: Chess engine ; Style: careful
#include <stdio.h>

char chessboard[8][8] =
{{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
 {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
 {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
 {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
 {' ', '.', ' ', '.', ' ', '.', ' ', ' '},
 {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
 {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
 {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

void print_board() {
    int i, j;
    for(i = 0; i < 8; ++i) {
        for (j = 0; j < 8; ++j)
            printf("%c ", chessboard[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main() {
    print_board();
    return 0;
}