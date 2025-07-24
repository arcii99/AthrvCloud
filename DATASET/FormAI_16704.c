//FormAI DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include<stdio.h>

//checks if a particular number can be 
//put in a certain cell
int canPlace(int grid[9][9],int x,int y,int n){
    for(int i=0;i<9;i++){
        if(grid[x][i]==n || grid[i][y]==n){
            return 0;
        }
    }
    int sx=(x/3)*3;
    int sy=(y/3)*3;
    for(int i=sx;i<sx+3;i++){
        for(int j=sy;j<sy+3;j++){
            if(grid[i][j]==n){
                return 0;
            }
        }
    }
    return 1;
}

//prints the sudoku grid
void printGrid(int grid[9][9]){
    printf("\nCurrent state of the grid:\n\n");
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",grid[i][j]);
            if((j+1)%3==0 && j!=8){
                printf("| ");
            }
        }
        if((i+1)%3==0 && i!=8){
            printf("\n------------------");
        }
        printf("\n");
    }
}

//function to solve the sudoku
int solveSudoku(int grid[9][9],int x,int y){
    if(x==8 && y==9){
        return 1;
    }
    if(y==9){
        x++;
        y=0;
    }
    if(grid[x][y]>0){
        return solveSudoku(grid,x,y+1);
    }
    for(int i=1;i<=9;i++){
        if(canPlace(grid,x,y,i)){
            grid[x][y]=i;
            if(solveSudoku(grid,x,y+1)){
                return 1;
            }
        }
    }
    grid[x][y]=0;
    return 0;
}

int main(){
    int grid[9][9]={
        {3,0,0,8,4,0,2,0,0},
        {0,9,0,1,2,0,0,0,4},
        {0,6,2,0,0,0,0,0,0},
        {4,1,0,0,0,0,9,6,0},
        {0,0,9,0,0,0,3,0,0},
        {0,5,6,0,0,0,0,4,8},
        {0,0,0,0,0,0,8,2,0},
        {2,0,0,0,7,8,0,9,0},
        {0,0,3,0,1,6,0,0,7}};
    printGrid(grid);
    printf("\nSolving.....\n\n");
    if(solveSudoku(grid,0,0)){
        printGrid(grid);
    }
    else{
        printf("No solution exists!");
    }
    return 0;
}