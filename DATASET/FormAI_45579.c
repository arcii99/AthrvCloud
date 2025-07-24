//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n = 5; // size of grid
int counter = 0; // counter to keep track of open sites

// function to create grid
int** create_grid(){
    int** grid = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        grid[i] = (int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            grid[i][j] = 0;
        }
    }
    return grid;
}

// function to print grid
void print_grid(int** grid){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

// function to check if site is open or blocked
int is_open(int** grid,int i,int j){
    if(grid[i][j]==0){
        return 0;
    }
    else{
        return 1;
    }
}

// function to open site
void open_site(int** grid,int i,int j){
    if(grid[i][j]==0){
        grid[i][j] = 1;
        counter++;
    }
}

// function to percolate
int percolates(int** grid){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                if(i==0 && is_open(grid,i+1,j)){
                    return 1;
                }
                if(i==n-1 && is_open(grid,i-1,j)){
                    return 1;
                }
                if(i>0 && i<n-1 && is_open(grid,i-1,j) && is_open(grid,i+1,j)){
                    return 1;
                }
                if(j==0 && is_open(grid,i,j+1)){
                    return 1;
                }
                if(j==n-1 && is_open(grid,i,j-1)){
                    return 1;
                }
                if(j>0 && j<n-1 && is_open(grid,i,j-1) && is_open(grid,i,j+1)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    srand(time(0));
    int** grid = create_grid();
    while(!percolates(grid)){
        int i = rand()%n;
        int j = rand()%n;
        open_site(grid,i,j);
    }
    printf("Percolation threshold: %f\n",(float)counter/(n*n));
    return 0;
}