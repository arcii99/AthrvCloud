//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define ROW 25
#define COLUMN 25
 
// Utility function to print the maze
void print_maze(int maze[ROW][COLUMN])
{
    int i,j;
    for(i=0;i<ROW;i++) {
        for(j=0;j<COLUMN;j++) {
            if(maze[i][j] == 0)
                printf("#");
            else if(maze[i][j] == 1)
                printf(" ");
            else if(maze[i][j] == 2)
                printf("S");
            else if(maze[i][j] == 3)
                printf("E");
            else
                printf("*");
        }
        printf("\n");
    }
}
 
// Utility function to generate random integer
int random_int(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
 
// Utility function to generate maze
void generate_maze(int maze[ROW][COLUMN], int row_start, int col_start, int row_end, int col_end)
{
    int i,j;
    for(i=1;i<ROW-1;i++) {
        for(j=1;j<COLUMN-1;j++) {
            if(i == row_start && j == col_start) {
                maze[i][j] = 2;
            } else if(i == row_end && j == col_end) {
                maze[i][j] = 3;
            } else {
                maze[i][j] = 1;
            }
        }
    }
    maze[row_start][col_start] = 0;
 
    int left, right, top, bottom;
    int row, col;
    int counter = 0;
 
    while(counter < ((ROW-2)*(COLUMN-2))/3) {
        row = random_int(1, ROW-2);
        col = random_int(1, COLUMN-2);
 
        if(maze[row][col] == 1) {
            left = maze[row][col-1];
            right = maze[row][col+1];
            top = maze[row-1][col];
            bottom = maze[row+1][col];
 
            if(left + right + top + bottom > 1) {
                maze[row][col] = 0;
                counter++;
            }
        }
    }
}
 
int main()
{
    int maze[ROW][COLUMN];
    int row_start = 1, col_start = 1, row_end = ROW-2, col_end = COLUMN-2;
 
    srand(time(NULL));
 
    generate_maze(maze, row_start, col_start, row_end, col_end);
 
    print_maze(maze);
 
    return 0;
}