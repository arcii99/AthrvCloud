//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 20

int maze[SIZE][SIZE];

void generateMaze(int row, int col)
{
    if((row < 0 || row >= SIZE) || (col < 0 || col >= SIZE)) //check if current position is out of maze
        return;

    if(maze[row][col] == 1) //check if current position is already visited
        return;

    maze[row][col] = 1; //mark current position as visited

    // randomly select direction to move
    int dirs[4] = {1, 2, 3, 4};
    for(int i = 0; i < 4; i++)
    {
        int randIndex = rand() % 4;
        int temp = dirs[i];
        dirs[i] = dirs[randIndex];
        dirs[randIndex] = temp;
    }

    // move in randomly selected direction
    for(int i = 0; i < 4; i++)
    {
        switch(dirs[i])
        {
            case 1: // move up
                generateMaze(row-1, col);
                break;
            case 2: // move down
                generateMaze(row+1, col);
                break;
            case 3: // move left
                generateMaze(row, col-1);
                break;
            case 4: // move right
                generateMaze(row, col+1);
                break;
        }
    }
}

int main()
{
    srand(time(NULL)); // seed for random number generation

    // fill maze with 0s
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            maze[i][j] = 0;
        }
    }

    int startingRow = rand() % SIZE; // randomly select starting row
    int startingCol = rand() % SIZE; // randomly select starting column

    generateMaze(startingRow, startingCol);

    // print generated maze
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(maze[i][j] == 0) // print black box for unvisited position
                printf("\x1b[48;5;16m  \x1b[0m");
            else                // print white box for visited position
                printf("\x1b[48;5;231m  \x1b[0m");
        }
        printf("\n");
    }

    return 0;
}