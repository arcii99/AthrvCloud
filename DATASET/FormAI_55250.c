//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10  // Number of rows in the maze
#define COLS 15 // Number of columns in the maze

// Function to print the maze
void print_maze(char maze[ROWS][COLS])
{
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }  
}

// Function to generate a random maze
void generate_maze(char maze[ROWS][COLS])
{
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(i%2==0 || j%2==0){
                maze[i][j]='#';
            }
            else{
                maze[i][j]=' ';
            }
        }
    }

    srand(time(NULL));
    int start_row = rand() % (ROWS/2) * 2 + 1;
    int start_col = rand() % (COLS/2) * 2 + 1;

    maze[start_row][start_col] = 'S'; // Starting point

    int end_row, end_col;
    do{
        end_row = rand() % (ROWS/2) * 2 + 1;
        end_col = rand() % (COLS/2) * 2 + 1;
    } while (end_row == start_row && end_col == start_col);

    maze[end_row][end_col] = 'E'; // Ending point
}

// Function to find the route from start to end
void find_route(char maze[ROWS][COLS], int row, int col)
{
    if(maze[row][col] == 'E'){ // If end point is reached
        return;
    }

    // Check if the cell to the right is clear and unvisited
    if(col < COLS-1 && maze[row][col+2] != '#' && maze[row][col+2] != '.'){
        maze[row][col+1] = '.';
        find_route(maze, row, col+2);
        if(maze[row][col+2] != 'E'){ // If not at the end point yet, revert back
            maze[row][col+1] = ' ';
        }
        else{
            return;
        }
    }

    // Check if the cell below is clear and unvisited
    if(row < ROWS-1 && maze[row+2][col] != '#' && maze[row+2][col] != '.'){
        maze[row+1][col] = '.';
        find_route(maze, row+2, col);
        if(maze[row+2][col] != 'E'){ // If not at the end point yet, revert back
            maze[row+1][col] = ' ';
        }
        else{
            return;
        }
    }

    // Check if the cell to the left is clear and unvisited
    if(col > 0 && maze[row][col-2] != '#' && maze[row][col-2] != '.'){
        maze[row][col-1] = '.';
        find_route(maze, row, col-2);
        if(maze[row][col-2] != 'E'){ // If not at the end point yet, revert back
            maze[row][col-1] = ' ';
        }
        else{
            return;
        }
    }

    // Check if the cell above is clear and unvisited
    if(row > 0 && maze[row-2][col] != '#' && maze[row-2][col] != '.'){
        maze[row-1][col] = '.';
        find_route(maze, row-2, col);
        if(maze[row-2][col] != 'E'){ // If not at the end point yet, revert back
            maze[row-1][col] = ' ';
        }
        else{
            return;
        }
    }
}

int main()
{
    char maze[ROWS][COLS];
    generate_maze(maze);
    printf("Initial maze:\n");
    print_maze(maze);

    int start_row, start_col;
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(maze[i][j] == 'S'){
                start_row = i;
                start_col = j;
                break;
            }
        }
    }

    find_route(maze, start_row, start_col);

    printf("Maze with route:\n");
    print_maze(maze);

    return 0;
}