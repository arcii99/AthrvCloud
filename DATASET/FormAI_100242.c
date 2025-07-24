//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 15

int grid[ROW][COL]; // The grid to store the maze

void printMaze() // Function to print the maze
{
    printf("\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (grid[i][j] == 0)
                printf("#");
            else if (grid[i][j] == 1)
                printf(".");
        }
        printf("\n");
    }
}

int isSafe(int x, int y) // Function to check if the cell is safe
{
    return (x >= 0 && x < ROW && y >= 0 && y < COL && grid[x][y] == 0);
}

void generateMaze(int x, int y) // Function to generate the maze
{
    int i, j, rand_num;
    int x_moves[4] = {1, -1, 0, 0}, y_moves[4] = {0, 0, 1, -1};
    int visited = 1;
    grid[x][y] = 1;
    printMaze();
    while (visited < ROW * COL)
    {
        rand_num = rand() % 4; // Generate a random direction
        i = x + x_moves[rand_num];
        j = y + y_moves[rand_num];
        if (isSafe(i, j))
        {
            grid[i][j] = 1;
            visited++;
            x = i;
            y = j;
            printMaze();
        }
    }
}

int main()
{
    srand(time(NULL)); // Set the random seed
    generateMaze(0, 0);
    return 0;
}