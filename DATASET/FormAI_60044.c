//FormAI DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#define ROW 10
#define COL 10

//Function to initialize the grid with zeros
void initializeGrid(int grid[][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            grid[i][j] = 0;
        }
    }
}

//Function to print the grid
void printGrid(int grid[][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(grid[i][j] == 0)
                printf(".");
            else
                printf("*");
        }
        printf("\n");
    }
}

//Function to check for neighbour cells
int checkNeighbours(int grid[][COL], int row, int col){
    int count = 0;
    
    if(row-1 >= 0 && col-1 >= 0 && grid[row-1][col-1] == 1) //top-left diagonal
        count++;
    if(row-1 >= 0 && grid[row-1][col] == 1) //top-middle neighbour
        count++;
    if(row-1 >= 0 && col+1 < COL && grid[row-1][col+1] == 1) //top-right diagonal
        count++;
    if(col-1 >= 0 && grid[row][col-1] == 1) //left neighbour
        count++;
    if(col+1 < COL && grid[row][col+1] == 1) //right neighbour
        count++;
    if(row+1 < ROW && col-1 >= 0 && grid[row+1][col-1] == 1) //bottom-left diagonal
        count++;
    if(row+1 < ROW && grid[row+1][col] == 1) //bottom-middle neighbour
        count++;
    if(row+1 < ROW && col+1 < COL && grid[row+1][col+1] == 1) //bottom-right diagonal
        count++;
    
    return count;
}

//Function to determine next generation
void nextGeneration(int grid[][COL]){
    int nextGeneration[ROW][COL];
    initializeGrid(nextGeneration);
    
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            int neighbours = checkNeighbours(grid, i, j);
            if(grid[i][j] == 1 && (neighbours == 2 || neighbours ==3)){
                nextGeneration[i][j] = 1;
            } else if(grid[i][j] == 0 && neighbours == 3){
                nextGeneration[i][j] = 1;
            }
        }
    }
    
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            grid[i][j] = nextGeneration[i][j];
        }
    }
}

int main() {
    int grid[ROW][COL];
    initializeGrid(grid);
    
    //Initial pattern
    grid[5][5] = 1;
    grid[5][6] = 1;
    grid[5][7] = 1;
    
    printf("Game of Life\n");
    printGrid(grid);
    
    for(int i=0; i<10; i++){
        nextGeneration(grid);
        printGrid(grid);
        printf("\n");
    }
    
    return 0;
}