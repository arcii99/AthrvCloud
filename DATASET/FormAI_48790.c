//FormAI DATASET v1.0 Category: Game of Life ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to display the grid
void display(int arr[][10], int n, int m){
    printf("\n");
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if(arr[i][j])
                printf(" * ");
            else
                printf("   ");
        }
        printf("\n");
    }
}

// Function to initialize the grid with random values
void initialize(int arr[][10], int n, int m){
    srand(time(NULL));
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            arr[i][j] = rand()%2;
}

// Function to check if cell is alive or dead and apply game of life rules
int checkLife(int arr[][10], int i, int j){
    int count = 0;
    if(i-1>=0 && arr[i-1][j]==1) //N
        count++;
    if(j+1<10 && arr[i][j+1]==1) //E
        count++;
    if(i+1<10 && arr[i+1][j]==1) //S
        count++;
    if(j-1>=0 && arr[i][j-1]==1) //W
        count++;
    if(i-1>=0 && j-1>=0 && arr[i-1][j-1]==1) //NW
        count++;
    if(i-1>=0 && j+1<10 && arr[i-1][j+1]==1) //NE
        count++;
    if(i+1<10 && j+1<10 && arr[i+1][j+1]==1) //SE
        count++;
    if(i+1<10 && j-1>=0  && arr[i+1][j-1]==1) //SW
        count++;
    if(count==2 || count==3){
        return 1; //Alive
    }
    else{
        return 0; //Dead
    }
}

// Main function
int main(){
    int grid[10][10];
    int generation = 0;
    initialize(grid, 10, 10);
    display(grid, 10, 10);
    while(generation<100){  //maximum 100 generations
        int newGrid[10][10];
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                newGrid[i][j] = checkLife(grid, i, j);
        printf("\nGeneration: %d", generation);
        display(newGrid, 10, 10);
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                grid[i][j] = newGrid[i][j];
        generation++;
    }
    return 0;
}