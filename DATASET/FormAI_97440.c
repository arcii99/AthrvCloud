//FormAI DATASET v1.0 Category: Game of Life ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int matrix[ROWS][COLS]; // The matrix for the game
int generation = 0; // Current generation count

void init_matrix();
void print_matrix();
void update_matrix();
int count_neighbors(int row, int col);

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize the matrix with random values
    init_matrix();

    // Print the initial matrix
    print_matrix();

    // Play the game
    while(1)
    {
        update_matrix();
        print_matrix();
        generation++;
        printf("Generation: %d\n", generation);
        printf("Press ENTER to continue or CTRL+C to quit.\n");
        getchar();
    }

    return 0;
}

// Initializes the matrix with random values
void init_matrix()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }
}

// Prints the matrix to the console
void print_matrix()
{
    int i, j;

    printf("\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(matrix[i][j] == 0)
            {
                printf(".");
            }
            else
            {
                printf("*");
            }
        }

        printf("\n");
    }
}

// Updates the matrix based on the Game of Life rules
void update_matrix()
{
    int i, j;
    int neighbors;

    // Create a temporary matrix to hold the new values
    int temp_matrix[ROWS][COLS];

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            neighbors = count_neighbors(i, j);

            if(matrix[i][j] == 1)
            {
                if(neighbors < 2 || neighbors > 3)
                {
                    // Any live cell with fewer than two live neighbors dies
                    // Any live cell with more than three live neighbors dies
                    temp_matrix[i][j] = 0;
                }
                else
                {
                    // Any live cell with two or three live neighbors survives
                    temp_matrix[i][j] = 1;
                }
            }
            else
            {
                if(neighbors == 3)
                {
                    // Any dead cell with exactly three live neighbors becomes a live cell
                    temp_matrix[i][j] = 1;
                }
                else
                {
                    temp_matrix[i][j] = 0;
                }
            }
        }
    }

    // Copy the values from the temporary matrix to the real matrix
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            matrix[i][j] = temp_matrix[i][j];
        }
    }
}

// Counts the number of live neighbors for a given cell
int count_neighbors(int row, int col)
{
    int count = 0;
    int i, j;

    for(i = row - 1; i <= row + 1; i++)
    {
        for(j = col - 1; j <= col + 1; j++)
        {
            // Skip over the current cell and out-of-bounds cells
            if((i == row && j == col) || i < 0 || i >= ROWS || j < 0 || j >= COLS)
            {
                continue;
            }

            if(matrix[i][j] == 1)
            {
                count++;
            }
        }
    }

    return count;
}