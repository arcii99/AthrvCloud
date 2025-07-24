//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

#define ROW 10 //Define number of rows
#define COL 10 //Define number of columns

//Structure to hold location in matrix
struct location {
    int row;
    int col;
};

//Function to print matrix
void printMatrix(int matrix[][COL], int rows, int columns){
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            printf("%d ", matrix[i][j]);
        }
    printf("\n");
    }
}

//Function to check if a certain cell is valid or not
int isCellValid(int row, int col, int matrix[][COL], int rows, int columns){
    if(row>=0 && col>=0 && row<rows && col<columns && matrix[row][col]!=0){ //If cell is within matrix limits and not an obstacle
        return 1; //Return true
    } else {
        return 0; //Return false
    }
}

//Function to find shortest path using A* algorithm
void aStarAlgorithm(int startRow, int startCol, int endRow, int endCol, int matrix[][COL], int rows, int columns){
    
    struct location neighbors[8];
    
    neighbors[0].row = -1;
    neighbors[0].col = -1;
    neighbors[1].row = -1;
    neighbors[1].col = 0;
    neighbors[2].row = -1;
    neighbors[2].col = 1;
    neighbors[3].row = 0;
    neighbors[3].col = -1;
    neighbors[4].row = 0;
    neighbors[4].col = 1;
    neighbors[5].row = 1;
    neighbors[5].col = -1;
    neighbors[6].row = 1;
    neighbors[6].col = 0;
    neighbors[7].row = 1;
    neighbors[7].col = 1;
    
    struct location parent[ROW][COL];
    parent[startRow][startCol].row = -1;
    parent[startRow][startCol].col = -1;
    
    int g[ROW][COL]; //Create matrix to store g costs
    int h[ROW][COL]; //Create matrix to store h costs
    int f[ROW][COL]; //Create matrix to store f costs
    
    int i, j;
    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            g[i][j] = 0; //Initialize g costs to zero
            h[i][j] = abs(j-endCol) + abs(i-endRow); //Calculate h costs to Manhattan distance
            f[i][j] = g[i][j] + h[i][j]; //Calculate f costs
        }
    }
    
    //Create a list of open cells
    int openRows[ROW*COL], openCols[ROW*COL];
    int openSize = 1;
    openRows[0] = startRow;
    openCols[0] = startCol;
    int currentRow = startRow;
    int currentCol = startCol;
    
    int closed[ROW][COL] = {0}; //Create matrix to store closed cells
    
    //Loop until end cell is found
    while(currentRow!=endRow || currentCol!=endCol){
        
        //Find the cell with the lowest f cost
        int minF = 99999;
        int minIndex = 0;
        for(i=0;i<openSize;i++){
            int fCost = f[openRows[i]][openCols[i]];
            if(fCost < minF){
                minF = fCost;
                minIndex = i;
            }
        }
        
        //Set current cell to cell with lowest f cost
        currentRow = openRows[minIndex];
        currentCol = openCols[minIndex];
        closed[currentRow][currentCol] = 1;
        
        //Remove current cell from open list
        for(i=minIndex;i<openSize-1;i++){
            openRows[i] = openRows[i+1];
            openCols[i] = openCols[i+1];
        }
        openSize--;
        
        //Check neighbors
        for(i=0;i<8;i++){
            int nextRow = currentRow + neighbors[i].row;
            int nextCol = currentCol + neighbors[i].col;
            if(isCellValid(nextRow, nextCol, matrix, ROW, COL) && !closed[nextRow][nextCol]){
                int newCost = g[currentRow][currentCol] + abs(nextCol-currentCol) + abs(nextRow-currentRow);
                if(newCost < g[nextRow][nextCol] || !g[nextRow][nextCol]){
                    g[nextRow][nextCol] = newCost;
                    f[nextRow][nextCol] = g[nextRow][nextCol] + h[nextRow][nextCol];
                    parent[nextRow][nextCol].row = currentRow;
                    parent[nextRow][nextCol].col = currentCol;
                    openRows[openSize] = nextRow;
                    openCols[openSize] = nextCol;
                    openSize++;
                }
            }
        }
    }
    
    //Print the matrix with the shortest path
    int tempRow = endRow;
    int tempCol = endCol;
    while(tempRow!=startRow || tempCol!=startCol){
        matrix[tempRow][tempCol] = 2; //Mark cells in the path as 2
        tempRow = parent[tempRow][tempCol].row;
        tempCol = parent[tempRow][tempCol].col;
    }
    printf("\nMatrix with the shortest path: \n");
    printMatrix(matrix, ROW, COL);

}

//Main function
int main(){
    
    int matrix[ROW][COL] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,0,1,1,1},
        {1,1,1,1,1,1,1,1,0,1},
        {1,1,1,1,0,1,1,1,0,1},
        {1,1,1,1,0,1,1,1,1,1},
        {1,1,1,1,0,1,1,1,1,1},
        {1,1,1,1,0,1,1,1,1,1},
        {1,1,1,1,0,1,1,1,1,1},
        {1,0,1,1,1,1,1,1,1,1}
    };
    printf("Original matrix: \n");
    printMatrix(matrix, ROW, COL);
    
    aStarAlgorithm(0,0,9,9,matrix,ROW,COL);

    return 0;
}