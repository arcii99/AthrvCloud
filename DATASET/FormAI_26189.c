//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

bool sites[N][N]; // false for blocked, true for open

void print_grid() {
    printf("+");
    for (int i = 0; i < N; i++) {
        printf("-");
    }
    printf("+\n");
    
    for (int i = 0; i < N; i++) {
        printf("|");
        for (int j = 0; j < N; j++) {
            if (sites[i][j] == true) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("|\n");
    }
    
    printf("+");
    for (int i = 0; i < N; i++) {
        printf("-");
    }
    printf("+\n");
}

bool percolates() {
    for (int j = 0; j < N; j++) {
        if (sites[N-1][j] == true) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL));
    int open_sites = 0;
    while (!percolates()) {
        int i = rand() % N;
        int j = rand() % N;
        
        if (sites[i][j] == false) {
            sites[i][j] = true;
            open_sites++;
        }
        
        print_grid();
    }
    
    printf("\nPercolation achieved! %d sites open\n", open_sites);
    
    return 0;
}