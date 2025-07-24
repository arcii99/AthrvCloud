//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define WALL 'X'
#define PATH ' '
#define START 'S'
#define END 'E'

void print_maze(char maze[][SIZE]);
void generate_maze(char maze[][SIZE], int row, int col);
void randomize_directions(int directions[]);
void carve_maze(char maze[][SIZE], int row, int col);
int get_random_direction(int directions[]);

int main()
{
    char maze[SIZE][SIZE];
    int row, col;

    srand(time(NULL));

    //initialize maze with walls
    for(row=0; row<SIZE; row++) {
        for(col=0; col<SIZE; col++) {
            if(row == 0 || row == SIZE-1 || col == 0 || col == SIZE-1) {
                maze[row][col] = WALL;
            } else {
                maze[row][col] = PATH;
            }
        }
    }

    generate_maze(maze, 1, 1);

    //add start and end points
    maze[1][1] = START;
    maze[SIZE-2][SIZE-2] = END;

    print_maze(maze);

    return 0;
}

void print_maze(char maze[][SIZE])
{
    int row, col;

    for(row=0; row<SIZE; row++) {
        for(col=0; col<SIZE; col++) {
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }
}

void generate_maze(char maze[][SIZE], int row, int col)
{
    int directions[] = {1, 2, 3, 4};
    int direction = 0;

    randomize_directions(directions);

    for(int i=0; i<4; i++)
    {
        direction = get_random_direction(directions);

        int next_row = row;
        int next_col = col;

        switch (direction)
        {
            case 1: //Up
                next_row -= 2;
                break;
            case 2: //Right
                next_col += 2;
                break;
            case 3: //Down
                next_row += 2;
                break;
            case 4: //Left
                next_col -= 2;
                break;
        }

        if(next_row <= 0 || next_row >= SIZE-1 || next_col <= 0 || next_col >= SIZE-1) {
            continue;
        }

        if(maze[next_row][next_col] == WALL) {
            maze[next_row][next_col] = PATH;
            maze[(next_row+row)/2][(next_col+col)/2] = PATH;
            generate_maze(maze, next_row, next_col);
        }
    }
}

void randomize_directions(int directions[])
{
    for(int i=0; i<4; i++)
    {
        int j = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }
}

int get_random_direction(int directions[])
{
    int i = rand() % 4;
    int direction = directions[i];

    for(int j=i; j<3; j++)
    {
        directions[j] = directions[j+1];
    }

    return direction;
}