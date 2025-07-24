//FormAI DATASET v1.0 Category: Game of Life ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define grid dimensions
#define ROWS 30
#define COLS 60

// Define cyberpunk color codes
#define CYBER_GREEN "\033[1;32m"
#define CYBER_BLUE "\033[1;34m"
#define CYBER_CYAN "\033[1;36m"
#define CYBER_PURPLE "\033[1;35m"
#define CYBER_MAGENTA "\033[1;31m"
#define CYBER_YELLOW "\033[1;33m"
#define CYBER_WHITE "\033[1;37m"
#define CYBER_RESET "\033[0m"

// Function to initialize the grid with random cells
void init_grid(int grid[ROWS][COLS])
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the grid
void print_grid(int grid[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j])
            {
                printf(CYBER_GREEN "█" CYBER_RESET);
            }
            else
            {
                printf(CYBER_BLUE " " CYBER_RESET);
            }
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors for a given cell
int count_neighbors(int grid[ROWS][COLS], int row, int col)
{
    int count = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int r = (row + i + ROWS) % ROWS;
            int c = (col + j + COLS) % COLS;
            if (!(i == 0 && j == 0) && grid[r][c])
            {
                count++;
            }
        }
    }
    return count;
}

// Function to update the grid according to the Game of Life rules
void update_grid(int grid[ROWS][COLS])
{
    int new_grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j])
            {
                new_grid[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            }
            else
            {
                new_grid[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
    // Update the grid with the new state
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            grid[i][j] = new_grid[i][j];
        }
    }
}

// Main function
int main()
{
    // Initialize the grid
    int grid[ROWS][COLS];
    init_grid(grid);

    // Run the Game of Life
    for (int i = 0; i < 100; i++)
    {
        // Print the grid
        system("clear");
        printf(CYBER_CYAN "=== Cyberpunk Game of Life ===\n" CYBER_RESET);
        printf(CYBER_PURPLE "Generation: %d\n\n" CYBER_RESET, i);
        print_grid(grid);

        // Update the grid
        update_grid(grid);

        // Pause for a moment to see the animation
        usleep(250000);
    }

    return 0;
}