//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

// Maze cells
char maze[HEIGHT][WIDTH];

// Directions
enum Directions { North, South, East, West };

// Random number generator
int rand_num(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

// Check if a cell is within the bounds of the maze
int is_valid(int row, int col)
{
    return row >= 0 && row < HEIGHT && col >= 0 && col < WIDTH && maze[row][col] == ' ';
}

// Create a maze using the depth-first search algorithm
void create_maze(int row, int col)
{
    maze[row][col] = '*';

    // Create an array of directions to shuffle
    enum Directions dirs[] = { North, South, East, West };
    for(int i = 0; i < 4; ++i)
    {
        int rand_dir = rand_num(i, 3);
        enum Directions temp = dirs[rand_dir];
        dirs[rand_dir] = dirs[i];
        dirs[i] = temp;
    }

    // Try each direction
    for(int i = 0; i < 4; ++i)
    {
        int next_row = row, next_col = col;
        switch(dirs[i])
        {
            case North:
                next_row--;
                break;
            case South:
                next_row++;
                break;
            case East:
                next_col++;
                break;
            case West:
                next_col--;
                break;
        }

        if(is_valid(next_row, next_col))
        {
            maze[(row + next_row) / 2][(col + next_col) / 2] = '*';
            create_maze(next_row, next_col);
        }
    }
}

int main()
{
    // Set random seed
    srand(time(NULL));

    // Initialize maze with spaces
    for(int row = 0; row < HEIGHT; ++row)
    {
        for(int col = 0; col < WIDTH; ++col)
        {
            maze[row][col] = ' ';
        }
    }

    // Create maze
    create_maze(0, 0);

    // Print maze
    for(int row = 0; row < HEIGHT; ++row)
    {
        for(int col = 0; col < WIDTH; ++col)
        {
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }

    return 0;
}