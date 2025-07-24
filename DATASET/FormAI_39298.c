//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void printMaze(char maze[][COLS]);
void generateMaze(char maze[][COLS], int row, int col);

int main()
{
    char maze[ROWS][COLS]; // 2D array for maze
    srand(time(NULL)); // seeding random generator
    
    generateMaze(maze, 0, 0); // generating maze starting from top left
    printMaze(maze); // printing maze
    
    return 0;
}

void generateMaze(char maze[][COLS], int row, int col)
{
    // initializing maze with walls
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            maze[i][j] = '#';
        }
    }
    
    maze[row][col] = ' '; // starting cell
    
    int directions[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
    // up, down, right and left directions
    
    for(int i = 0; i < 4; i++) // shuffle directions
    {
        int r = rand() % 4;
        int c = rand() % 4;
        int temp = directions[i][0];
        directions[i][0] = directions[r][0];
        directions[r][0] = temp;
        temp = directions[i][1];
        directions[i][1] = directions[c][1];
        directions[c][1] = temp;
    }
    
    for(int d = 0; d < 4; d++) // for each direction
    {
        int r = row + directions[d][0] * 2; // get the next row
        int c = col + directions[d][1] * 2; // get the next column
        
        if(r >= 0 && r < ROWS && c >= 0 && c < COLS && maze[r][c] == '#')
        {
            // if the next cell is within bounds and not visited before
            maze[row + directions[d][0]][col + directions[d][1]] = ' '; // remove wall
            maze[r][c] = ' '; // move to next cell
            generateMaze(maze, r, c); // recursive call for next cell
        }
    }
}

void printMaze(char maze[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}