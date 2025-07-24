//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int grid[SIZE][SIZE];
int visited[SIZE][SIZE];

void initialize() {
    int i, j;
    srand(time(NULL));
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            if((double) rand() / (double) RAND_MAX < 0.6) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
            visited[i][j] = 0;
        }
    }
}

void percolate(int i, int j) {
    visited[i][j] = 1;
    if(grid[i][j] == 0) return;
    if(i == SIZE - 1) return;
    if(j > 0 && !visited[i][j-1]) percolate(i, j-1);
    if(j < SIZE - 1 && !visited[i][j+1]) percolate(i, j+1);
    if(i > 0 && !visited[i-1][j]) percolate(i-1, j);
    if(i < SIZE - 1 && !visited[i+1][j]) percolate(i+1, j);
}

int is_percolated() {
    int i;
    for(i=0; i<SIZE; i++) {
        if(visited[0][i] && visited[SIZE-1][i]) {
            return 1;
        }
    }
    return 0;
}

void print() {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            if(grid[i][j] == 1) {
                if(visited[i][j]) {
                    printf("O ");
                } else {
                    printf("X ");
                }
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int count = 0;
    initialize();
    while(!is_percolated()) {
        percolate(0, count % SIZE);
        count++;
    }
    print();
    return 0;
}