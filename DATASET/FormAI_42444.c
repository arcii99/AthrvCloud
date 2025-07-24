//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int N, i, j, count = 0; // Initializing variables
    printf("Enter the size of the grid: ");
    scanf("%d", &N);

    srand(time(NULL)); // Seed the random number generator

    // Initializing the grid
    int grid[N][N];
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            int r = rand() % 100; // Generating a random number between 0 and 99
            if(r < 50) grid[i][j] = 0; // Assigning 0 if r<50
            else grid[i][j] = 1; // Assigning 1 if r>=50
        }
    }

    // Printing the initial grid
    printf("\nInitial Grid:\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Performing percolation
    while(1){
        int changed = 0;
        for(i=1; i<N-1; i++){
            for(j=0; j<N; j++){
                if(grid[i-1][j] == 1 && grid[i][j] == 0 && grid[i+1][j] == 1){
                    grid[i][j] = 1;
                    changed = 1;
                }
            }
        }
        if(changed == 0) break;
    }

    // Printing the final grid
    printf("\nFinal Grid:\n");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%d ", grid[i][j]);
            if(grid[i][j] == 1) count++;
        }
        printf("\n");
    }

    // Printing the percentage of percolation
    float perc = ((float)count / (float)(N*N)) * 100;
    printf("\nPercentage of Percolation: %.2f%%\n", perc);
    return 0;
}