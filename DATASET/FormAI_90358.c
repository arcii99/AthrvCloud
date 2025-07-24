//FormAI DATASET v1.0 Category: Chess AI ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE] = {
    {2, 3, 4, 5, 6, 4, 3, 2},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-2, -3, -4, -5, -6, -4, -3, -2},
};

void print_board() {
    int i, j;
    printf("   A B C D E F G H\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d  ", BOARD_SIZE - i);
        for (j = 0; j < BOARD_SIZE; j++) {
            switch(board[i][j]) {
                case 2:
                    printf("K ");
                    break;
                case 3:
                    printf("Q ");
                    break;
                case 4:
                    printf("R ");
                    break;
                case 5:
                    printf("B ");
                    break;
                case 6:
                    printf("N ");
                    break;
                case 1:
                    printf("P ");
                    break;
                case -1:
                    printf("p ");
                    break;
                case -2:
                    printf("n ");
                    break;
                case -3:
                    printf("b ");
                    break;
                case -4:
                    printf("r ");
                    break;
                case -5:
                    printf("q ");
                    break;
                case -6:
                    printf("k ");
                    break;
                default:
                    printf("- ");
            }
        }
        printf(" %d", BOARD_SIZE - i);
        printf("\n");
    }
    printf("   A B C D E F G H\n");
}

int main() {
    int i;
    print_board();
    return 0;
}