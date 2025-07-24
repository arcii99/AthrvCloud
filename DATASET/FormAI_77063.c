//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_ROWS 20
#define MAX_COLS 20

char MAZE[MAX_ROWS][MAX_COLS];

void generateMaze()
{
    int i, j, random_num;

    // initialize maze with borders
    for(i=0;i<MAX_ROWS;i++)
    {
        for(j=0;j<MAX_COLS;j++)
        {
            if(i==0 || j==0 || i==(MAX_ROWS-1) || j==(MAX_COLS-1))
            {
                MAZE[i][j] = '#';
            }
            else
            {
                MAZE[i][j] = ' ';
            }
        }
    }

    // add random obstacles
    srand(time(NULL));
    for(i=1;i<(MAX_ROWS-1);i++)
    {
        for(j=1;j<(MAX_COLS-1);j++)
        {
            random_num = rand()%100;
            if(random_num < 30)
            {
                MAZE[i][j] = '#';
            }
        }
    }
}

int findPath(int row, int col)
{
    if(MAZE[row][col] == 'E')
    {
        return 1;
    }
    else if(MAZE[row][col] == '#' || MAZE[row][col] == '+')
    {
        return 0;
    }
    MAZE[row][col] = '+';
    if(findPath(row-1, col) || findPath(row, col+1) || findPath(row+1, col) || findPath(row, col-1))
    {
        return 1;
    }
    MAZE[row][col] = ' ';
    return 0;
}

void printMaze()
{
    int i, j;

    for(i=0;i<MAX_ROWS;i++)
    {
        for(j=0;j<MAX_COLS;j++)
        {
            printf("%c", MAZE[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int start_row, start_col;

    generateMaze();

    // add start and end points
    srand(time(NULL));
    start_row = rand() % (MAX_ROWS-2) + 1;
    start_col = rand() % (MAX_COLS-2) + 1;
    MAZE[start_row][start_col] = 'S';
    MAZE[MAX_ROWS-2][MAX_COLS-2] = 'E';

    printf("MAZE ROUTE FINDER\n");
    printf("=================\n");
    printf("Starting point (S): (%d,%d)\n", start_row, start_col);
    printf("Ending point (E): (%d,%d)\n", MAX_ROWS-2,MAX_COLS-2);
    printf("=================\n");

    printMaze();

    printf("=================\n");
    printf("Finding path...\n");
    printf("=================\n");

    if(findPath(start_row, start_col))
    {
        printMaze();
    }
    else
    {
        printf("No path found.\n");
    }

    return 0;
}