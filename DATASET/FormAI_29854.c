//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>

#define ROWS 10    //number of rows
#define COLS 12    //number of columns

char maze[ROWS][COLS] =   //string representation of maze
{
    "+-+-+-+-+-+-+-+-+-+",
    "|         |       |",
    "+ +-+-+ +-+ +-+ + +",
    "|         |   | | |",
    "+ +-+ +-+-+-+ + + +",
    "|   | |     |   | |",
    "+-+-+ + +-+ + +-+ +",
    "|     | | | |     |",
    "+-+-+ + + + +-+-+-+",
    "|   | | |   |     |",
    "+ + + +-+ +-+-+-+ +",
    "| |     |         |",
    "+-+-+-+-+-+-+-+-+-+"
};

//helper functions
int findStart(int* row, int* col);
int isFinish(int row, int col);
void printMaze();
int findPath(int row, int col);

int main()
{
    int startX, startY;
    if (!findStart(&startY, &startX))   //start position not found
    {
        printf("Start not found in maze.\n");
        return -1;
    }

    printf("Starting at: (%d,%d)\n", startX, startY);
    if (findPath(startX, startY))   //path found
    {
        printf("\nPath successfully found!\n");
        printMaze();
    }
    else   //path not found
    {
        printf("\nPath not found :(\n");
    }

    return 0;
}

//function to find starting position in maze
int findStart(int* row, int* col)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (maze[i][j] == '+')   //dead end
            {
                continue;
            }
            else if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)   //on border
            {
                continue;
            }
            else if (maze[i][j] == ' ')   //valid starting position
            {
                *row = i;
                *col = j;
                return 1;
            }
        }
    }

    //start not found
    return 0;
}

//function to check if current position is the finish
int isFinish(int row, int col)
{
    if (row == 0 || row == ROWS - 1 || col == 0 || col == COLS - 1)
    {
        return 1;
    }

    return 0;
}

//function to print maze
void printMaze()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

//function to find path through maze using recursive backtracking
int findPath(int row, int col)
{
    if (isFinish(row, col))   //finish found
    {
        maze[row][col] = '*';
        return 1;
    }
    else if (maze[row][col] != ' ')   //cell already visited
    {
        return 0;
    }
    else   //visit cell
    {
        maze[row][col] = '.';
        if (findPath(row - 1, col) || findPath(row, col + 1) || findPath(row + 1, col) || findPath(row, col - 1))
        {
            maze[row][col] = '*';   //append to path
            return 1;
        }
        else   //dead end
        {
            maze[row][col] = '+';
            return 0;
        }
    }
}