//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

void createMaze(int maze[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS]);
int isValid(int row, int col);
void move(int *row, int *col, int dir);
int hasUnvisitedNeighbour(int row, int col, int maze[ROWS][COLS]);
void shuffleArray(int *arr, int size);

int main(void)
{
    int maze[ROWS][COLS];
    srand(time(NULL));
    createMaze(maze);
    printMaze(maze);
    return 0;
}

void createMaze(int maze[ROWS][COLS])
{
    int visited[ROWS][COLS] = {0};
    int stack_row[ROWS*COLS];
    int stack_col[ROWS*COLS];
    int top = -1;

    // Initialize maze to walls
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            maze[i][j] = 1;
        }
    }
    
    // Choose random starting cell
    int row = rand() % ROWS;
    int col = rand() % COLS;
    visited[row][col] = 1;
    
    // Loop until all cells have been visited
    while(1)
    {
        if(hasUnvisitedNeighbour(row, col, visited))
        {
            int neighbours[4] = {0};
            int num_neighbours = 0;
            
            // Check North neighbour
            if(isValid(row-1, col) && !visited[row-1][col])
            {
                neighbours[num_neighbours++] = 0;
            }
            
            // Check East neighbour
            if(isValid(row, col+1) && !visited[row][col+1])
            {
                neighbours[num_neighbours++] = 1;   
            }

            // Check South neighbour
            if(isValid(row+1, col) && !visited[row+1][col])
            {
                neighbours[num_neighbours++] = 2;
            }

            // Check West neighbour
            if(isValid(row, col-1) && !visited[row][col-1])
            {
                neighbours[num_neighbours++] = 3;
            }
            
            // Choose random neighbour to move to
            shuffleArray(neighbours, num_neighbours);
            int dir = neighbours[0];
            move(&row, &col, dir);
            
            // Update maze and visited array
            maze[row][col] = 0; // remove wall
            visited[row][col] = 1;
            
            // Push current cell onto stack
            stack_row[++top] = row;
            stack_col[top] = col;
        }
        else // Backtrack
        {
            if(top == -1) // All cells visited
            {
                break;
            }
            row = stack_row[top];
            col = stack_col[top--];
        }
    }
    
    // Set entrance and exit in maze
    maze[0][1] = 0;
    maze[ROWS-1][COLS-2] = 0;
}

void printMaze(int maze[ROWS][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(maze[i][j] == 1) // wall
            {
                printf("#");
            }
            else if(i == 0 && j == 1) // entrance
            {
                printf("S");
            }
            else if(i == ROWS-1 && j == COLS-2) // exit
            {
                printf("E");
            }
            else // path
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int isValid(int row, int col)
{
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

void move(int *row, int *col, int dir)
{
    switch(dir)
    {
        case 0: // North
            (*row)--;
            break;
        case 1: // East
            (*col)++;
            break;
        case 2: // South
            (*row)++;
            break;
        case 3: // West
            (*col)--;
            break;
    }
}

int hasUnvisitedNeighbour(int row, int col, int visited[ROWS][COLS])
{
    if(isValid(row-1, col) && !visited[row-1][col])
    {
        return 1;
    }
    if(isValid(row, col+1) && !visited[row][col+1])
    {
        return 1;   
    }
    if(isValid(row+1, col) && !visited[row+1][col])
    {
        return 1;
    }
    if(isValid(row, col-1) && !visited[row][col-1])
    {
        return 1;
    }
    return 0;
}

void shuffleArray(int *arr, int size)
{
    for(int i = size-1; i >= 0; i--)
    {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}