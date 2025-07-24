//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 20

void display(char maze[ROW][COL], int row, int col);
void generateMaze(char maze[ROW][COL], int row, int col);

int main()
{
    char maze[ROW][COL];
    generateMaze(maze, ROW, COL);
    display(maze, ROW, COL);
    return 0;
}

void display(char maze[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(char maze[ROW][COL], int row, int col)
{
    srand(time(NULL));
    
    // Initialize the maze with walls
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            maze[i][j] = '#';
        }
    }
    
    // Pick a random starting point
    int x = rand() % (row - 2) + 1;
    int y = rand() % (col - 2) + 1;
    maze[x][y] = ' ';
    
    // Generate the maze
    while (1)
    {
        // Break loop if all maze cells have been processed
        int flag = 1;
        for (int i = 1; i < row - 1; i++)
        {
            for (int j = 1; j < col - 1; j++)
            {
                if (maze[i][j] == '#')
                {
                    flag = 0;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        if (flag)
        {
            break;
        }
        
        // Pick a random direction
        int dir = rand() % 4;
        
        // Move in the chosen direction
        if (dir == 0 && x > 1 && maze[x-2][y] == '#')
        {
            maze[x-1][y] = ' ';
            maze[x-2][y] = ' ';
            x -= 2;
        }
        else if (dir == 1 && y > 1 && maze[x][y-2] == '#')
        {
            maze[x][y-1] = ' ';
            maze[x][y-2] = ' ';
            y -= 2;
        }
        else if (dir == 2 && x < row - 2 && maze[x+2][y] == '#')
        {
            maze[x+1][y] = ' ';
            maze[x+2][y] = ' ';
            x += 2;
        }
        else if (dir == 3 && y < col - 2 && maze[x][y+2] == '#')
        {
            maze[x][y+1] = ' ';
            maze[x][y+2] = ' ';
            y += 2;
        }
    }
    maze[1][0] = 'S';   // Starting point
    maze[row-2][col-1] = 'E';   // Ending point
}