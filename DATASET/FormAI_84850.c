//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the size of the grid
#define N 40

// define the probabilities of each cell being open or blocked
#define P 0.6

// define directions
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// function prototypes
void initialize(int grid[][N]);
void print_grid(int grid[][N]);
int check_percolation(int grid[][N]);
void percolate(int grid[][N], int direction, int row, int col);

int main()
{
    // seed the random number generator
    srand(time(NULL));

    // initialize the grid
    int grid[N][N];
    initialize(grid);

    // print the initial grid
    printf("Initial Grid:\n");
    print_grid(grid);

    // check if the grid percolates
    int percolates = check_percolation(grid);

    // if the grid does not percolate, keep percolating until it does
    while (!percolates)
    {
        // choose a random row and column
        int row = rand() % N;
        int col = rand() % N;

        // choose a random direction
        int direction = rand() % 4 + 1;

        // percolate in the chosen direction
        percolate(grid, direction, row, col);

        // check if the grid percolates
        percolates = check_percolation(grid);
    }

    // print the final grid
    printf("Final Grid:\n");
    print_grid(grid);

    // print a message indicating that the grid has percolated
    printf("The grid has percolated!\n");

    return 0;
}

// function to initialize the grid
void initialize(int grid[][N])
{
    // loop through all cells in the grid
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // assign each cell a value of 0 or 1 based on probability P
            double r = (double)rand() / RAND_MAX;
            if (r < P)
            {
                grid[i][j] = 1; // open cell
            }
            else
            {
                grid[i][j] = 0; // blocked cell
            }
        }
    }

    // set the top row to be open, to allow water to flow through
    for (int j = 0; j < N; j++)
    {
        grid[0][j] = 1;
    }
}

// function to print the grid
void print_grid(int grid[][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 1)
            {
                printf("+"); // open cell
            }
            else
            {
                printf("-"); // blocked cell
            }
        }
        printf("\n");
    }
}

// function to check if the grid percolates
int check_percolation(int grid[][N])
{
    // create a new array to keep track of open cells that have been visited
    int visited[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = 0;
        }
    }

    // loop through the cells in the top row
    for (int j = 0; j < N; j++)
    {
        // if the cell is open, start a DFS to check if it can reach the bottom row
        if (grid[0][j] == 1)
        {
            visited[0][j] = 1;
            int stack_top = 0;
            int stack_x[N * N];
            int stack_y[N * N];
            stack_x[stack_top] = 0;
            stack_y[stack_top] = j;

            while (stack_top >= 0)
            {
                int x = stack_x[stack_top];
                int y = stack_y[stack_top];
                stack_top--;

                if (x == N - 1)
                {
                    // the top and bottom rows are connected, so the grid percolates
                    return 1;
                }

                // push unvisited open neighbors onto the stack
                if (y > 0 && grid[x][y - 1] == 1 && visited[x][y - 1] == 0)
                {
                    stack_top++;
                    stack_x[stack_top] = x;
                    stack_y[stack_top] = y - 1;
                    visited[x][y - 1] = 1;
                }
                if (y < N - 1 && grid[x][y + 1] == 1 && visited[x][y + 1] == 0)
                {
                    stack_top++;
                    stack_x[stack_top] = x;
                    stack_y[stack_top] = y + 1;
                    visited[x][y + 1] = 1;
                }
                if (x < N - 1 && grid[x + 1][y] == 1 && visited[x + 1][y] == 0)
                {
                    stack_top++;
                    stack_x[stack_top] = x + 1;
                    stack_y[stack_top] = y;
                    visited[x + 1][y] = 1;
                }
            }
        }
    }

    // if all open cells in the top row fail to reach the bottom row, the grid does not percolate
    return 0;
}

// function to percolate in the chosen direction
void percolate(int grid[][N], int direction, int row, int col)
{
    switch (direction)
    {
        case UP:
            if (row > 0 && grid[row - 1][col] != 0)
            {
                grid[row][col] = 1;
            }
            break;
        case DOWN:
            if (row < N - 1 && grid[row + 1][col] != 0)
            {
                grid[row][col] = 1;
            }
            break;
        case LEFT:
            if (col > 0 && grid[row][col - 1] != 0)
            {
                grid[row][col] = 1;
            }
            break;
        case RIGHT:
            if (col < N - 1 && grid[row][col + 1] != 0)
            {
                grid[row][col] = 1;
            }
            break;
    }
}