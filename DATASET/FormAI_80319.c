//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

char maze[ROWS][COLUMNS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '.', '#', '#', '#', '.', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '#', '#', '#'},
};

int start_row = 9, start_column = 0;
int end_row = 5, end_column = 9;

bool is_valid_move(int row, int column)
{
    if(row < 0 || row >= ROWS || column < 0 || column >= COLUMNS)
    {
        return false;
    }

    if(maze[row][column] == '#')
    {
        return false;
    }

    return true;
}

bool solve_maze(int row, int column)
{
    if(row == end_row && column == end_column)
    {
        maze[row][column] = '@';
        return true;
    }

    if(is_valid_move(row, column))
    {
        maze[row][column] = '@';

        if(solve_maze(row + 1, column))
        {
            return true;
        }

        if(solve_maze(row - 1, column))
        {
            return true;
        }

        if(solve_maze(row, column + 1))
        {
            return true;
        }

        if(solve_maze(row, column - 1))
        {
            return true;
        }

        maze[row][column] = '.';
        return false;
    }

    return false;
}

void print_maze()
{
    for(int row = 0; row < ROWS; row++)
    {
        for(int column = 0; column < COLUMNS; column++)
        {
            printf("%c ", maze[row][column]);
        }
        printf("\n");
    }
}

int main()
{
    if(solve_maze(start_row, start_column))
    {
        printf("Maze solved!\n");
    }
    else
    {
        printf("Maze cannot be solved!\n");
    }

    print_maze();

    return 0;
}