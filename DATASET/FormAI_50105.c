//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // Grid size
#define P 0.5 // Probability of site being open

typedef struct{
    int x;
    int y;
} point;

point *neighbours(point p);

int main(){
    srand(time(NULL));
    int open[N][N], full[N][N];
    int i, j;
    point p = {0, 0}, *n;
    int count = 0, percolates = 0;
    
    // Initialize all sites as closed
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            open[i][j] = 0;
            full[i][j] = 0;
        }
    }
    
    // Open random sites
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if((double)rand() / (double)RAND_MAX < P){
                open[i][j] = 1;
                count++;
            }
        }
    }
    
    // Initialize top row as full
    for(i=0; i<N; i++){
        full[0][i] = open[0][i];
    }
    
    // Propagate fullness from top row
    for(i=0; i<N-1; i++){
        for(j=0; j<N; j++){
            if(full[i][j]){
                n = neighbours((point){i, j});
                for(int k=0; k<4; k++){
                    if(n[k].x >= 0 && n[k].x < N && n[k].y >= 0 && n[k].y < N
                    && open[n[k].x][n[k].y] && !full[n[k].x][n[k].y]){
                        full[n[k].x][n[k].y] = 1;
                    }
                }
            }
        }
    }
    
    // Check if bottom row is full
    for(i=0; i<N; i++){
        if(full[N-1][i]){
            percolates = 1;
            break;
        }
    }
    
    // Print Grid
    printf("Percolates: %s\n\n", percolates ? "Yes" : "No");
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            printf("%c ", open[i][j] ? (full[i][j] ? 'O' : ' ') : '#');
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}

// Returns array of neighbouring points
point *neighbours(point p){
    static point n[4];
    n[0] = (point){p.x-1, p.y};
    n[1] = (point){p.x, p.y-1};
    n[2] = (point){p.x+1, p.y};
    n[3] = (point){p.x, p.y+1};
    return n;
}