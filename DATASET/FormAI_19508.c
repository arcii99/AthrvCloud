//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // adjust the maze size here

// function prototypes
void init_maze(int maze[][SIZE]);
void print_maze(int maze[][SIZE]);
void generate_maze(int maze[][SIZE], int row, int col);

int main()
{
    int maze[SIZE][SIZE];

    srand(time(0)); // seed the random number generator

    init_maze(maze); // initialize the maze
    generate_maze(maze, 1, 1); // generate the maze
    print_maze(maze); // print the maze

    return 0;
}

void init_maze(int maze[][SIZE])
{
    int i, j;

    // fill the maze with walls
    for(i = 0; i < SIZE; i++)
        for(j = 0; j < SIZE; j++)
            maze[i][j] = 1;

    // set the starting and ending points
    maze[1][0] = 0;
    maze[SIZE-2][SIZE-1] = 0;
}

void print_maze(int maze[][SIZE])
{
    int i, j;

    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(maze[i][j])
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void generate_maze(int maze[][SIZE], int row, int col)
{
    int directions[4] = {0, 1, 2, 3}; // 0 = up, 1 = right, 2 = down, 3 = left
    int tmp, n = 4, i, j, k;

    // shuffle the directions array
    for(i = n-1; i > 0; i--) {
        j = rand() % (i+1);
        tmp = directions[i];
        directions[i] = directions[j];
        directions[j] = tmp;
    }

    // check each direction
    for(k = 0; k < 4; k++) {
        i = row;
        j = col;

        if(directions[k] == 0) {
            i--;
            if(i < 1)
                continue; // out of bounds
            if(maze[i][j])
                continue; // already visited
            maze[i+1][j] = 0; // remove the wall
        }
        else if(directions[k] == 1) {
            j++;
            if(j > SIZE-2)
                continue; // out of bounds
            if(maze[i][j])
                continue; // already visited
            maze[i][j-1] = 0; // remove the wall
        }
        else if(directions[k] == 2) {
            i++;
            if(i > SIZE-2)
                continue; // out of bounds
            if(maze[i][j])
                continue; // already visited
            maze[i-1][j] = 0; // remove the wall
        }
        else if(directions[k] == 3) {
            j--;
            if(j < 1)
                continue; // out of bounds
            if(maze[i][j])
                continue; // already visited
            maze[i][j+1] = 0; // remove the wall
        }

        generate_maze(maze, i, j); // recursive call
    }
}