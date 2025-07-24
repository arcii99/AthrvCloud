//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Grid size

int grid[N][N];
int open[N][N];
int virtualTop;
int virtualBottom;

int root(int x){ // method to get the root of the node
    while(x != grid[x / N][x % N]){
          grid[x / N][x % N] = grid[grid[x / N][x % N] / N][grid[x / N][x % N] % N];
          x = grid[x / N][x % N];
    }
    return x;
}

void init(){ // Initializes the grid and open[][], also sets virtualTop and virtualBottom
    virtualTop = N * N;
    virtualBottom = virtualTop + 1;
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++){
            grid[i][j] = i * N + j;
            open[i][j] = 0;
        }
    }
    for(i = 0; i < N; i++){
        grid[N][i] = virtualTop;
        grid[N + 1][i] = virtualBottom;
    }
}

void connect(int a, int b){ // Connect the two nodes a and b
    if(a == virtualTop){
        grid[b / N][b % N] = a;
        return;
    }
    if(b == virtualTop){
        grid[a / N][a % N] = b;
        return;
    }
    int root_a = root(a);
    int root_b = root(b);
    grid[root_a / N][root_a % N] = root_b;
}

int isFull(){ // checks if virtualTop is connected to virtualBottom
    return root(virtualTop) == root(virtualBottom);
}

void percolate(){ // Generates a random number between 0 and N^2 - 1. Opens that site and connects it to its adjacent sites if they are also open. Repeats until the grid percolates
    srand(time(NULL));
    int random_num, row, col;
    while (!isFull()) {
        random_num = rand() % (N * N);
        row = random_num / N;
        col = random_num % N;
        if (open[row][col] == 0) {
            open[row][col] = 1;
            if (row == 0) // connect to virtualTop if on the top row
                connect(row * N + col, virtualTop);
            if (row == N - 1) // connect to virtualBottom if on the bottom row
                connect(row * N + col, virtualBottom);

            if (row > 0 && open[row - 1][col]) // connect to top site if open
                connect(row * N + col, (row - 1) * N + col);
            if (col < N - 1 && open[row][col + 1]) // connect to right site if open
                connect(row * N + col, row * N + col + 1);
            if (row < N - 1 && open[row + 1][col]) // connect to bottom site if open
                connect(row * N + col, (row + 1) * N + col);
            if (col > 0 && open[row][col - 1]) // connect to left site if open
                connect(row * N + col, row * N + col - 1);
        }
    }
    printf("\nPercolation achieved!\n");
}

void draw(){ // draws the grid
    printf("\n");
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(open[i][j] == 0)
                printf("\t.");
            else if (i == N - 1)
                printf("\tX"); // virtualBottom
            else if (i == 0)
                printf("\tO"); // virtualTop
            else
                printf("\t ");
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Percolation Simulator\n");
    init();
    percolate();
    draw();
    return 0;
}