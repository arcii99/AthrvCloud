//FormAI DATASET v1.0 Category: Checkers Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int board[SIZE][SIZE] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {2, 0, 2, 0, 2, 0, 2, 0},
    {0, 2, 0, 2, 0, 2, 0, 2},
    {2, 0, 2, 0, 2, 0, 2, 0}
};

void print_board() {
    int i, j;
    printf("\t  1 2 3 4 5 6 7 8\n");
    for (i = 0; i < SIZE; i++) {
        printf("\t%d ", i+1);
        for (j = 0; j < SIZE; j++) {
            switch (board[i][j]) {
                case 0:
                    printf(". ");
                    break;
                case 1:
                    printf("X ");
                    break;
                case 2:
                    printf("O ");
                    break;
                case 3:
                    printf("K ");
                    break;
                case 4:
                    printf("Q ");
                    break;
            }
        }
        printf("%d\n", i+1);
    }
    printf("\t  1 2 3 4 5 6 7 8\n");
}

int main() {
    print_board();
    return 0;
}