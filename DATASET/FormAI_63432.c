//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int status[SIZE][SIZE];
int visited[SIZE][SIZE];

void print_board() {
    int row, col;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (status[row][col] == 1) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_board() {
    int row, col;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (row == 0 || col == 0 || row == SIZE-1 || col == SIZE-1) {
                status[row][col] = 1;
            } else {
                status[row][col] = rand() % 2;
            }
        }
    }
}

void percolate(int row, int col) {
    visited[row][col] = 1;
    status[row][col] = 2;
    if (row > 0 && status[row-1][col] == 1 && visited[row-1][col] == 0) { // top
        percolate(row-1, col);
    }
    if (row < SIZE-1 && status[row+1][col] == 1 && visited[row+1][col] == 0) { // bottom
        percolate(row+1, col);
    }
    if (col > 0 && status[row][col-1] == 1 && visited[row][col-1] == 0) { // left
        percolate(row, col-1);
    }
    if (col < SIZE-1 && status[row][col+1] == 1 && visited[row][col+1] == 0) { // right
        percolate(row, col+1);
    }
}

int test_percolation() {
    int row, col;
    for (col = 0; col < SIZE; col++) {
        if (status[SIZE-2][col] == 2) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    generate_board();
    printf("Initial board:\n");
    print_board();
    percolate(1, 1);
    if (test_percolation()) {
        printf("\nIt percolates!\n");
    } else {
        printf("\nIt doesn't percolate.\n");
    }
    printf("\nFinal board:\n");
    print_board();
    return 0;
}