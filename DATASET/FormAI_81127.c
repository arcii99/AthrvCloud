//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int visited[ROWS][COLS];

void generateMaze(int row, int col, int maze[][COLS])
{
    if(row < 0 || col < 0 || row >= ROWS || col >= COLS || visited[row][col])
        return;
    
    visited[row][col] = 1;
    int n = 0;
    int neighbors[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
    int temp[4][2];
    
    for(int i = 0; i < 4; i++)
    {
        int r = row + neighbors[i][0];
        int c = col + neighbors[i][1];
        
        if(r >= 0 && c >= 0 && r < ROWS && c < COLS && !visited[r][c])
        {
            temp[n][0] = r;
            temp[n][1] = c;
            n++;
        }
    }
    
    while(n > 0)
    {
        int index = rand() % n;
        int r = temp[index][0];
        int c = temp[index][1];
        maze[row + r + 1][col + c + 1] = 0;
        generateMaze(r, c, maze);
        for(int i = index; i < n-1; i++)
        {
            temp[i][0] = temp[i+1][0];
            temp[i][1] = temp[i+1][1];
        }
        n--;
    }
}

void printMaze(int maze[][COLS])
{
    for(int i = 0; i < ROWS + 2; i++)
    {
        for(int j = 0; j < COLS + 2; j++)
        {
            if(maze[i][j])
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

int main()
{
    int maze[ROWS+2][COLS+2];
    srand(time(NULL));
    generateMaze(0, 0, maze);
    printMaze(maze);
    return 0;
}