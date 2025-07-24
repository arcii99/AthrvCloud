//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 40

char maze[ROWS][COLUMNS];
int path[ROWS][COLUMNS];

void generate_maze();
void print_maze();
void find_path(int, int);
int is_valid(int, int);

int main()
{
    srand(time(NULL));
    generate_maze();
    printf("Generated Maze:\n");
    print_maze();
    printf("Finding Path...\n");
    find_path(0, 0);
    printf("\nFinal Path:\n");
    print_maze();
    return 0;
}

void generate_maze()
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLUMNS; j++)
        {
            if(i==0 || i==ROWS-1 || j==0 || j==COLUMNS-1)
                maze[i][j] = '#';
            else if(rand()%4==0)
                maze[i][j] = '#';
            else
                maze[i][j] = ' ';
            path[i][j] = 0;
        }
    }
    maze[0][0] = ' ';
    maze[ROWS-1][COLUMNS-1] = ' ';
}

void print_maze()
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLUMNS; j++)
        {
            if(path[i][j])
                printf(".");
            else
                printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void find_path(int row, int column)
{
    if(row<0 || row>=ROWS || column<0 || column>=COLUMNS)
        return;
    
    if(maze[row][column]=='#' || path[row][column])
        return;
    
    path[row][column] = 1;
    
    if(row==ROWS-1 && column==COLUMNS-1)  // Reached the destination
        return;
    
    if(is_valid(row-1, column)) // Top
        find_path(row-1, column);
    if(is_valid(row+1, column)) // Bottom
        find_path(row+1, column);
    if(is_valid(row, column-1)) // Left
        find_path(row, column-1);
    if(is_valid(row, column+1)) // Right
        find_path(row, column+1);
}

int is_valid(int row, int column)
{
    if(row<0 || row>=ROWS || column<0 || column>=COLUMNS)
        return 0;
    if(maze[row][column]=='#' || path[row][column])
        return 0;
    return 1;
}