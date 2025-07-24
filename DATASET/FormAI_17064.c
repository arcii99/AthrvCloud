//FormAI DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 20
#define MAX_GENERATIONS 100

void print_generation(char matrix[ROW][COL]) {
    printf("\n");
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void simulate(char matrix[ROW][COL]) {
    char new_matrix[ROW][COL];

    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            int neighbors = 0;

            for (int x=-1; x<=1; x++) {
                for (int y=-1; y<=1; y++) {
                    int row = (i + x + ROW) % ROW;
                    int col = (j + y + COL) % COL;
                    neighbors += (matrix[row][col] == 'X');
                }
            }

            if (matrix[i][j] == 'X') {
                neighbors--;
                if (neighbors < 2 || neighbors > 3) {
                    new_matrix[i][j] = ' ';
                } else {
                    new_matrix[i][j] = 'X';
                }
            } else {
                if (neighbors == 3) {
                    new_matrix[i][j] = 'X';
                } else {
                    new_matrix[i][j] = ' ';
                }
            }
        }
    }

    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            matrix[i][j] = new_matrix[i][j];
        }
    }
}

int main() {
    srand(time(NULL));

    char matrix[ROW][COL];

    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            if (rand() % 2 == 0) {
                matrix[i][j] = 'X';
            } else {
                matrix[i][j] = ' ';
            }
        }
    }

    for (int gen=0; gen<MAX_GENERATIONS; gen++) {
        print_generation(matrix);
        simulate(matrix);
    }

    return 0;
}