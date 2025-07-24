//FormAI DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 20

int grid[N][N];

void init_grid(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            grid[i][j] = 0;
        }
    }
}

void print_grid(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(grid[i][j] == 0){
                printf("-");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

void update_grid(){
    int tmp_grid[N][N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tmp_grid[i][j] = grid[i][j];
        }
    }

    for(int r = 0; r < N; r++){
        for(int c = 0; c < N; c++){
            int n_neighbours = 0;
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int rr = (r + i + N) % N;
                    int cc = (c + j + N) % N;
                    n_neighbours += grid[rr][cc];
                }
            }
            n_neighbours -= grid[r][c];

            if (grid[r][c]){
                if (n_neighbours == 2 || n_neighbours == 3){
                    tmp_grid[r][c] = 1;
                } else {
                    tmp_grid[r][c] = 0;
                }
            } else {
                if (n_neighbours == 3){
                    tmp_grid[r][c] = 1;
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            grid[i][j] = tmp_grid[i][j];
        }
    }
}

int main(){
    init_grid();

    // create a blinker
    grid[N/2][N/2] = 1;
    grid[N/2+1][N/2] = 1;
    grid[N/2-1][N/2] = 1;

    while(1){
        // clear the output
        printf("\033[H\033[J");

        print_grid();

        usleep(100000); // sleep for 1/10 of a second

        update_grid();
    }
    return 0;
}