//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool percolates(int n, double p){
    int grid[MAX_SIZE][MAX_SIZE];
    int i, j;

    // Initialize grid
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            grid[i][j] = 0;
        }
    }

    // Fill grid with random values
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if((double)rand()/(double)RAND_MAX < p){
                grid[i][j] = 1;
            }
        }
    }

    // Create virtual nodes
    int top = n*n;
    int bottom = n*n + 1;

    // Create disjoint set
    int uf[MAX_SIZE*MAX_SIZE + 2];
    for(i=0 ; i<MAX_SIZE*MAX_SIZE + 2 ; i++){
        uf[i] = -1;
    }
    uf[top] = top;
    uf[bottom] = bottom;

    // Connect top and bottom rows to virtual nodes
    for(j=0; j<n; j++){
        if(grid[0][j] == 1){
            int p = j;
            int q = top;
            int root_p = p;

            while(root_p != uf[root_p]){
                root_p = uf[root_p];
            }

            uf[p] = root_p;
            uf[root_p] = uf[top];
        }
        if(grid[n-1][j] == 1){
            int p = (n-1)*n + j;
            int q = bottom;
            int root_p = p;

            while(root_p != uf[root_p]){
                root_p = uf[root_p];
            }

            uf[p] = root_p;
            uf[root_p] = uf[bottom];
        }
    }

    // Connect neighboring cells if they are both open
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            int curr = i*n + j;
            int next;

            if(grid[i][j] == 1){
                if(i > 0 && grid[i-1][j] == 1){
                    next = (i-1)*n + j;
                    int root_curr = curr;
                    int root_next = next;

                    while(root_curr != uf[root_curr]){
                        root_curr = uf[root_curr];
                    }

                    while(root_next != uf[root_next]){
                        root_next = uf[root_next];
                    }

                    uf[root_curr] = root_next;
                }
                if(i < n-1 && grid[i+1][j] == 1){
                    next = (i+1)*n + j;
                    int root_curr = curr;
                    int root_next = next;

                    while(root_curr != uf[root_curr]){
                        root_curr = uf[root_curr];
                    }

                    while(root_next != uf[root_next]){
                        root_next = uf[root_next];
                    }

                    uf[root_curr] = root_next;
                }
                if(j > 0 && grid[i][j-1] == 1){
                    next = i*n + j-1;
                    int root_curr = curr;
                    int root_next = next;

                    while(root_curr != uf[root_curr]){
                        root_curr = uf[root_curr];
                    }

                    while(root_next != uf[root_next]){
                        root_next = uf[root_next];
                    }

                    uf[root_curr] = root_next;
                }
                if(j < n-1 && grid[i][j+1] == 1){
                    next = i*n + j+1;
                    int root_curr = curr;
                    int root_next = next;

                    while(root_curr != uf[root_curr]){
                        root_curr = uf[root_curr];
                    }

                    while(root_next != uf[root_next]){
                        root_next = uf[root_next];
                    }

                    uf[root_curr] = root_next;
                }
            }
        }
    }

    // Check if virtual nodes are connected
    int root_top = top;
    int root_bottom = bottom;

    while(root_top != uf[root_top]){
        root_top = uf[root_top];
    }

    while(root_bottom != uf[root_bottom]){
        root_bottom = uf[root_bottom];
    }

    if(root_top == root_bottom){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n = 10;
    double p = 0.5;
    bool result;
    srand(time(NULL));

    result = percolates(n, p);

    if(result == true){
        printf("Percolation occurred\n");
    }
    else{
        printf("Percolation did not occur\n");
    }

    return 0;
}