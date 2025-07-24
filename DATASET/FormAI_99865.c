//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int cells[HEIGHT][WIDTH];

void generateMaze(int r, int c)
{
    cells[r][c] = 0;
    int directions[4] = {0, 1, 2, 3};
    for (int i = 3; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = directions[j];
        directions[j] = directions[i];
        directions[i] = temp;
    }
    for (int i = 0; i < 4; i++)
    {
        int newRow = r, newCol = c;
        switch (directions[i])
        {
            case 0: newCol--; break;
            case 1: newRow--; break;
            case 2: newCol++; break;
            case 3: newRow++; break;
        }
        if (newRow < 0 || newRow >= HEIGHT || newCol < 0 || newCol >= WIDTH) continue;
        if (cells[newRow][newCol] == -1)
        {
            cells[r + (newRow - r) / 2][c + (newCol - c) / 2] = 0;
            generateMaze(newRow, newCol);
        }
    }
}

int main()
{
    srand(time(NULL));
    
    // initialize cells
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cells[i][j] = -1;
        }
    }
    
    // generate maze
    generateMaze(0, 0);
    
    // print maze
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (cells[i][j] == 0)
            {
                printf("  ");
            }
            else
            {
                printf("**");
            }
        }
        printf("\n");
    }
    
    return 0;
}