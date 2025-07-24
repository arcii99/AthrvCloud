//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int main()
{
    srand(time(NULL));
    int i,j,start_row,start_col,end_row,end_col,current_row,current_col;
    int visited[MAX_ROWS][MAX_COLS] = {0};
    char maze[MAX_ROWS][MAX_COLS];

    // Generate the initial maze
    for(i=0;i<MAX_ROWS;i++){
        for(j=0;j<MAX_COLS;j++){
            if(rand()%2==0)
                maze[i][j] = '#';
            else
                maze[i][j] = ' ';
        }
    }

    // Select the starting and ending position of the maze
    start_row = rand()%MAX_ROWS;
    start_col = 0;

    end_row = rand()%MAX_ROWS;
    end_col = MAX_COLS-1;

    maze[start_row][start_col] = 'S';
    maze[end_row][end_col] = 'E';

    // Generate the maze using a depth-first search algorithm
    current_row = start_row;
    current_col = start_col;
    visited[current_row][current_col] = 1;

    while(current_row != end_row || current_col != end_col){
        if(current_col > 0 && maze[current_row][current_col-1] != '#' && visited[current_row][current_col-1] == 0){
            maze[current_row][current_col-1] = '.';
            visited[current_row][current_col-1] = 1;
            current_col--;
        }
        else if(current_col < MAX_COLS-1 && maze[current_row][current_col+1] != '#' && visited[current_row][current_col+1] == 0){
            maze[current_row][current_col+1] = '.';
            visited[current_row][current_col+1] = 1;
            current_col++;
        }
        else if(current_row > 0 && maze[current_row-1][current_col] != '#' && visited[current_row-1][current_col] == 0){
            maze[current_row-1][current_col] = '.';
            visited[current_row-1][current_col] = 1;
            current_row--;
        }
        else if(current_row < MAX_ROWS-1 && maze[current_row+1][current_col] != '#' && visited[current_row+1][current_col] == 0){
            maze[current_row+1][current_col] = '.';
            visited[current_row+1][current_col] = 1;
            current_row++;
        }
        else if((current_col > 0 && maze[current_row][current_col-1] == '#') || (current_col < MAX_COLS-1 && maze[current_row][current_col+1] == '#') || (current_row > 0 && maze[current_row-1][current_col] == '#') || (current_row < MAX_ROWS-1 && maze[current_row+1][current_col] == '#')){
            int backtracked = 0;
            while(backtracked==0){
                int r = rand()%4;
                if(r==0 && current_row > 0 && maze[current_row-1][current_col] == '.' && visited[current_row-1][current_col] == 1){
                    backtracked = 1;
                    current_row--;
                }
                else if(r==1 && current_col > 0 && maze[current_row][current_col-1] == '.' && visited[current_row][current_col-1] == 1){
                    backtracked = 1;
                    current_col--;
                }
                else if(r==2 && current_row < MAX_ROWS-1 && maze[current_row+1][current_col] == '.' && visited[current_row+1][current_col] == 1){
                    backtracked = 1;
                    current_row++;
                }
                else if(r==3 && current_col < MAX_COLS-1 && maze[current_row][current_col+1] == '.' && visited[current_row][current_col+1] == 1){
                    backtracked = 1;
                    current_col++;
                }
            }
        }
    }

    // Print the generated maze
    printf("\nGenerated Maze:\n");
    for(i=0;i<MAX_ROWS;i++){
        for(j=0;j<MAX_COLS;j++){
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}