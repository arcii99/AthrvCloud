//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 /* the grid dimension */

void print_grid(int grid[N][N]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%c", grid[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

void percolate(int grid[N][N]){
    int i, j, k, l;
    int complete = 0;
    int count = 0;
    while(!complete){
        complete = 1;
        for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                if(grid[i][j] == 0){
                    if(j > 0 && grid[i][j-1] == 1){
                        grid[i][j] = 1;
                        complete = 0;
                    }
                    else if(j < N-1 && grid[i][j+1] == 1){
                        grid[i][j] = 1;
                        complete = 0;
                    }
                    else if(i > 0 && grid[i-1][j] == 1){
                        grid[i][j] = 1;
                        complete = 0;
                    }
                    else if(i < N-1 && grid[i+1][j] == 1){
                        grid[i][j] = 1;
                        complete = 0;
                    }
                }
            }
        }
        count++;
    }
    printf("Number of iterations until percolation: %d\n", count);
}

int main(){
    int grid[N][N];
    int i, j;
    srand(time(NULL));
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            /* randomly fill grid */
            grid[i][j] = rand() % 2;
        }
    }
    printf("Initial grid:\n");
    print_grid(grid);
    percolate(grid);
    printf("Final grid:\n");
    print_grid(grid);
    return 0;
}