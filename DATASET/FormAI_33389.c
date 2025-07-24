//FormAI DATASET v1.0 Category: Robot movement control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STEPS 100    // maximum number of steps for robot's movement
#define MOVEMENT_RANGE 10 // maximum distance robot can move in one step
#define GRID_SIZE 20     // size of the 2D grid on which robot moves


// function prototypes
void initialize_grid(int grid[][GRID_SIZE]);
void print_grid(int grid[][GRID_SIZE]);
void move_robot(int grid[][GRID_SIZE], int* x_pos, int* y_pos);


int main()
{
    int grid[GRID_SIZE][GRID_SIZE];    // 2D grid for robot's movement
    int x_pos = GRID_SIZE / 2;         // initial x position of robot
    int y_pos = GRID_SIZE / 2;         // initial y position of robot
    char choice;

    initialize_grid(grid);        // initialize 2D grid
    print_grid(grid);             // print initial position of robot in grid

    // move robot for MAX_STEPS or until it reaches the edge of the grid
    for(int i = 0; i < MAX_STEPS && x_pos > 0 && x_pos < GRID_SIZE-1 && y_pos > 0 && y_pos < GRID_SIZE-1; i++)
    {
        move_robot(grid, &x_pos, &y_pos);    // move robot one step
        print_grid(grid);                    // print updated position of robot in grid
        printf("Remaining Steps: %d\n", MAX_STEPS - i - 1);
    }

    if(x_pos == 0 || x_pos == GRID_SIZE-1 || y_pos == 0 || y_pos == GRID_SIZE-1)
        printf("Robot has reached the edge of the grid!\n");
    else
        printf("Maximum steps reached!\n");

    return 0;
}


// initializes the 2D grid with zeros
void initialize_grid(int grid[][GRID_SIZE])
{
    for(int i = 0; i < GRID_SIZE; i++)
        for(int j = 0; j < GRID_SIZE; j++)
            grid[i][j] = 0;
}

// prints the 2D grid with current position of robot
void print_grid(int grid[][GRID_SIZE])
{
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
            printf("%c ", grid[i][j] == 0 ? '.' : grid[i][j] == 1 ? 'R' : '#');    // '.' for empty space, 'R' for robot, '#' for edge of grid
        printf("\n");
    }
    printf("\n");
}

// moves the robot one step in a random direction but never moves outside the grid
void move_robot(int grid[][GRID_SIZE], int* x_pos, int* y_pos)
{
    int x_delta, y_delta;
    do {
        x_delta = (rand() % (MOVEMENT_RANGE*2+1)) - MOVEMENT_RANGE;    // generate random x_delta between [-MOVEMENT_RANGE, MOVEMENT_RANGE]
        y_delta = (rand() % (MOVEMENT_RANGE*2+1)) - MOVEMENT_RANGE;    // generate random y_delta between [-MOVEMENT_RANGE, MOVEMENT_RANGE]
    } while(*x_pos + x_delta < 0 || *x_pos + x_delta >= GRID_SIZE || *y_pos + y_delta < 0 || *y_pos + y_delta >= GRID_SIZE);

    grid[*y_pos][*x_pos] = 0;             // clear previous position of robot
    *x_pos += x_delta;                    // update x position of robot
    *y_pos += y_delta;                    // update y position of robot
    grid[*y_pos][*x_pos] = 1;             // set new position of robot
}