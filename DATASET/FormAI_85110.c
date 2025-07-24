//FormAI DATASET v1.0 Category: Chess engine ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define BLACK 1

int board[8][8] = {{-1, -2, -3, -4, -5, -3, -2, -1},
                    {-6, -6, -6, -6, -6, -6, -6, -6},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {6, 6, 6, 6, 6, 6, 6, 6},
                    {1, 2, 3, 4, 5, 3, 2, 1}};

int col, row;

void draw_board() {
    for (col = 0; col < 8; col++) {
        printf("%d", 8 - col);
        for (row = 0; row < 8; row++) {
            printf("\t%c", board[row][col]);
        }
        printf("\n");
    }
    printf("\ta\tb\tc\td\te\tf\tg\th\n\n");
}

int main() {
    draw_board();
    return 0;
}