//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 21
#define COL 51

void generateMaze(int maze[][COL], int row, int col);
int isVisited(int visited[][COL], int row, int col);
int inBounds(int row, int col);
void printMaze(int maze[][COL], int row, int col);

int main()
{
    srand(time(0));
    int maze[ROW][COL];
    generateMaze(maze, ROW, COL);
    printMaze(maze, ROW, COL);
    return 0;
}

// Function to generate maze using Recursive Backtracking Algorithm
void generateMaze(int maze[][COL], int row, int col)
{
    int visited[row][col]; // Represents visited cells
    int i, j;
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
        {
            maze[i][j] = 1; // Represents wall blocks
            visited[i][j] = 0; // Initialize all cells as unvisited
        }

    // Starting cell is visited and set as current cell
    visited[1][1] = 1;
    int currentRow = 1, currentCol = 1;

    // Initialize stack to keep track of visited cells
    int stack[ROW*COL][2];
    int top = -1, totalVisited = 1;

    while(totalVisited < (row-1)*(col-1))
    {
        int dir = rand()%4; // Choose a random direction
        int newRow = currentRow + (dir==0) - (dir==1);
        int newCol = currentCol + (dir==2) - (dir==3);

        if(inBounds(newRow, newCol) && !isVisited(visited, newRow, newCol))
        {
            // Break the wall between current cell and the new cell
            if(dir==0) maze[currentRow-1][currentCol] = 0; // Up
            if(dir==1) maze[currentRow+1][currentCol] = 0; // Down
            if(dir==2) maze[currentRow][currentCol-1] = 0; // Left
            if(dir==3) maze[currentRow][currentCol+1] = 0; // Right

            // Update current cell and mark the new cell as visited
            stack[++top][0] = currentRow; stack[top][1] = currentCol;
            visited[currentRow][currentCol] = 1;
            currentRow = newRow; currentCol = newCol;
            visited[currentRow][currentCol] = 1;
            totalVisited++;
        }
        // If dead end or no unvisited cells in the vicinity, backtrack to previously visited cell
        else if(top!=-1)
        {
            currentRow = stack[top][0]; currentCol = stack[top--][1];
        }
    }
}

// Function to check if a cell is visited or not
int isVisited(int visited[][COL], int row, int col)
{
    if(visited[row][col]==1) return 1;
    else return 0;
}

// Function to check if cell is within the bounds of the maze
int inBounds(int row, int col)
{
    if(row>=1 && row<ROW-1 && col>=1 && col<COL-1) return 1;
    else return 0;
}

// Function to print the generated maze
void printMaze(int maze[][COL], int row, int col)
{
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(maze[i][j]==1) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
}