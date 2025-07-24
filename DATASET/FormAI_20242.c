//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

char maze[HEIGHT][WIDTH] =
    {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
        {'#', '#', '#', ' ', ' ', ' ', '#', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#'},
        {'#', '#', '#', '#', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

int solution[HEIGHT][WIDTH];
int startRow = 1, startCol = 1; 
int endRow = 8, endCol = 8;     
int found;

void findPath(int row, int col, int count)
{
    if (row == endRow && col == endCol) 
    {
        found = count;
        return;
    }

    if (found) return;

    if (maze[row][col] == '#' || solution[row][col] != 0) return; 

    solution[row][col] = count;

    findPath(row - 1, col, count + 1); 
    findPath(row + 1, col, count + 1); 
    findPath(row, col - 1, count + 1); 
    findPath(row, col + 1, count + 1); 

    solution[row][col] = 0;
}

void printMaze()
{
    int i, j;

    for (i = 0; i < HEIGHT; i++) 
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (maze[i][j] == '#')
                printf("%c", maze[i][j]);
            else if (solution[i][j] != 0)
                printf("%c", '.');
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    printf("Maze:\n");
    printMaze();

    findPath(startRow, startCol, 1);

    printf("\nSolution:\n");
    printMaze();

    if (found)
        printf("\nShortest path length: %d\n", found - 1);
    else
        printf("\nNo path found\n");

    return 0;
}