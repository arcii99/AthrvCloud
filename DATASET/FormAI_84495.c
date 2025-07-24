//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 21              // Rows of the Maze
#define COL 21              // Columns of the Maze

int maze[ROW+1][COL+1];     // Matrix to store the maze

void generateMaze()         // Function to generate maze
{
    srand(time(0));        // Set Seed for Randomization

    // Initialize all Elements of maze with 1
    for(int i=1; i<=ROW; i++)
    {
        for(int j=1; j<=COL; j++)
        {
            maze[i][j] = 1;
        }
    }

    // Randomly Assign Starting Point and Set it to 0
    int start = rand() % ((ROW-1)/2) * 2 + 2;
    maze[start][1] = 0;

    // Randomly Assign Finishing Point and Set it to 0
    int finish = rand() % ((ROW-1)/2) * 2 + 2;
    maze[finish][COL] = 0;

    // Randomly Generate Maze
    int i=start, j=1;
    while(i!=finish || j!=COL)
    {
        int rand_dir = rand() % 4;
        if(rand_dir == 0 && i>1 && maze[i-2][j]==1)
        {
            maze[i-1][j] = 0;
            maze[i-2][j] = 0;
            i -= 2;
        }
        else if(rand_dir == 1 && j<COL-1 && maze[i][j+2]==1)
        {
            maze[i][j+1] = 0;
            maze[i][j+2] = 0;
            j += 2;
        }
        else if(rand_dir == 2 && i<ROW-1 && maze[i+2][j]==1)
        {
            maze[i+1][j] = 0;
            maze[i+2][j] = 0;
            i += 2;
        }
        else if(rand_dir == 3 && j>1 && maze[i][j-2]==1)
        {
            maze[i][j-1] = 0;
            maze[i][j-2] = 0;
            j -= 2;
        }
    }
}

void printMaze()            // Function to Print Maze
{
    for(int i=1; i<=ROW; i++)
    {
        for(int j=1; j<=COL; j++)
        {
            if(maze[i][j] == 1) printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}

int main()                  // Main Function
{
    generateMaze();
    printMaze();
    return 0;
}