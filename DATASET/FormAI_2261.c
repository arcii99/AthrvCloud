//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 30

// Function to draw the maze
void drawMaze(char maze[][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to generate the maze
void generateMaze(int x, int y, char maze[][COL])
{
    // Set the current cell as visited
    maze[x][y] = '.';

    // Figure out the direction to move
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    srand(time(0));
    int random = rand() % 4;
    int dx = directions[random][0];
    int dy = directions[random][1];

    int count = 0;
    while (count < 4)
    {
        // Check if the cell in that direction is unvisited and within bounds
        if (x + dx >= 0 && x + dx < ROW && y + dy >= 0 && y + dy < COL && maze[x + dx][y + dy] == '#')
        {
            generateMaze(x + dx, y + dy, maze);
        }

        // Get a new direction
        random = rand() % 4;
        dx = directions[random][0];
        dy = directions[random][1];

        count++;
    }
}

int main()
{
    char maze[ROW][COL];

    // Initialize the maze with walls
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            maze[i][j] = '#';
        }
    }

    // Generate the maze from a random starting point
    srand(time(0));
    int startX = rand() % ROW;
    int startY = rand() % COL;
    generateMaze(startX, startY, maze);

    // Draw the maze
    drawMaze(maze);
    return 0;
}