//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define ROW 10 // Define maze row size
#define COL 10 // Define maze column size

void printMaze(char maze[ROW][COL], int row_size, int col_size){
    int i, j;
    printf("\n\t\t\t Current maze looks like:\n");

    for(i=0; i<row_size; i++){
        for(j=0; j<col_size; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void updateMaze(char maze[ROW][COL], int *row, int *col, int i, int j){
    maze[i][j] = '.';
    *row = i;
    *col = j;
}

int isValidMove(char maze[ROW][COL], int i, int j){
    return (i>=0 && i<ROW && j>=0 && j<COL && maze[i][j]==' ');
}

int findPath(char maze[ROW][COL], int row_size, int col_size, int i, int j, int x, int y){
    int row, col;
    row = i;
    col = j;
    if(i==x && j==y){ // Exit condition
        return 1;
    }

    if(isValidMove(maze, i-1, j)){ // Try to go up
        updateMaze(maze, &row, &col, i-1, j); // Update maze and position
        if(findPath(maze, row_size, col_size, row, col, x, y)==1){ // Recursion
            return 1;
        }
        maze[row][col] = ' '; // Backtracking
    }

    if(isValidMove(maze, i, j+1)){ // Try to go right
        updateMaze(maze, &row, &col, i, j+1);
        if(findPath(maze, row_size, col_size, row, col, x, y)==1){
            return 1;
        }
        maze[row][col] = ' ';
    }

    if(isValidMove(maze, i+1, j)){ // Try to go down
        updateMaze(maze, &row, &col, i+1, j);
        if(findPath(maze, row_size, col_size, row, col, x, y)==1){
            return 1;
        }
        maze[row][col] = ' ';
    }

    if(isValidMove(maze, i, j-1)){ // Try to go left
        updateMaze(maze, &row, &col, i, j-1);
        if(findPath(maze, row_size, col_size, row, col, x, y)==1){
            return 1;
        }
        maze[row][col] = ' ';
    }

    return 0;
}

int main(){
    char maze[ROW][COL] = {
        "##########", // First row
        "#        #", // Next 8 rows
        "# ## ### #",
        "# #      #",
        "# # #### #",
        "#   #    #",
        "### # ####",
        "#   #    #",
        "# #### ## #",
        "#        #X" // Last row
    };

    int row_size = ROW;
    int col_size = COL;
    int i, j, x, y;

    for(i=0; i<row_size; i++){
        for(j=0; j<col_size; j++){
            if(maze[i][j] == 'X'){
                x = i;
                y = j;
            }
        }
    }

    printf("\n\t\t\t Welcome to Maze Route Finder!\n\n");
    printMaze(maze, row_size, col_size);

    i = 1;
    j = 1;

    if(findPath(maze, row_size, col_size, i, j, x, y)==1){
        printf("\n\t\t\t Congratulations! You have found the exit.\n");
    }
    else{
        printf("\n\t\t\t Sorry, there is no path to the exit.\n");
    }

    printMaze(maze, row_size, col_size);

    return 0;
}