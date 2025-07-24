//FormAI DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

void print_board(char[][WIDTH]);
void init_board(char[][WIDTH]);

int main(int argc, char const *argv[]) {
    char board[HEIGHT][WIDTH];
    int i, j, k;

    /* Seed random number generator */
    srand(time(NULL));

    /* Initialize board */
    init_board(board);

    /* Game loop */
    for (k = 0; k < 100; k++) {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        print_board(board);

        /* Copy board to temporary buffer */
        char temp[HEIGHT][WIDTH];
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                temp[i][j] = board[i][j];
            }
        }

        /* Iterate over board and update cells */
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                int living_neighbors = 0;
                if (i > 0 && j > 0 && board[i-1][j-1] == 'X') {
                    living_neighbors++;
                }
                if (i > 0 && board[i-1][j] == 'X') {
                    living_neighbors++;
                }
                if (i > 0 && j < WIDTH-1 && board[i-1][j+1] == 'X') {
                    living_neighbors++;
                }
                if (j > 0 && board[i][j-1] == 'X') {
                    living_neighbors++;
                }
                if (j < WIDTH-1 && board[i][j+1] == 'X') {
                    living_neighbors++;
                }
                if (i < HEIGHT-1 && j > 0 && board[i+1][j-1] == 'X') {
                    living_neighbors++;
                }
                if (i < HEIGHT-1 && board[i+1][j] == 'X') {
                    living_neighbors++;
                }
                if (i < HEIGHT-1 && j < WIDTH-1 && board[i+1][j+1] == 'X') {
                    living_neighbors++;
                }

                if (board[i][j] == 'X') {
                    if (living_neighbors < 2 || living_neighbors > 3) {
                        /* Cell dies */
                        temp[i][j] = '.';
                    }
                }
                else {
                    if (living_neighbors == 3) {
                        /* Cell is born */
                        temp[i][j] = 'X';
                    }
                }
            }
        }
        /* Copy temp buffer back to board */
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH; j++) {
                board[i][j] = temp[i][j];
            }
        }
    }
    return 0;
}

void print_board(char board[][WIDTH]) {
    int i, j;
    printf("       MEDIEVAL GAME OF LIFE\n");
    printf("------------------------------------\n");
    for (i = 0; i < HEIGHT; i++) {
        printf("| ");
        for (j = 0; j < WIDTH; j++) {
            if (board[i][j] == '.') {
                printf(" ");
            }
            else {
                printf("X");
            }
        }
        printf(" |\n");
    }
    printf("------------------------------------\n");
}

void init_board(char board[][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (rand() % 2) {
                board[i][j] = 'X';
            }
            else {
                board[i][j] = '.';
            }
        }
    }
}