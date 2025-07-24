//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for sizing of the house grid and maximum steps player can take
#define ROWS 10
#define COLS 10
#define MAX_STEPS 20

// Enumeration for grid cell contents and player status
enum State {EMPTY, WALL, TRAP, TREASURE, PLAYER};
enum Status {ALIVE, DEAD, ESCAPED};

// Function declarations
int initializeGrid(int grid[ROWS][COLS], int traps);
int getRandom(int min, int max);
void printGrid(int grid[ROWS][COLS], int steps, int treasureCount);
int checkMove(int grid[ROWS][COLS], int row, int col);
int movePlayer(int grid[ROWS][COLS], int *row, int *col, int *steps, int *treasureCount);
int checkPlayerStatus(int grid[ROWS][COLS], int row, int col, int steps, int treasureCount);

// Main function
int main()
{
    srand(time(NULL)); // Initialize random seed
    
    int grid[ROWS][COLS]; // Declare grid
    int steps = 0; // Initialize player steps to 0
    int treasureCount = 0; // Initialize treasure count to 0
    
    // Initialize grid with random walls, traps, and treasure
    int traps = getRandom(5, 15);
    int status = initializeGrid(grid, traps);
    if (status == -1)
    {
        printf("Error: could not initialize grid.\n");
        return -1;
    }
    
    // Initialize player starting position
    int row = getRandom(0, ROWS);
    int col = getRandom(0, COLS);
    while (grid[row][col] != EMPTY)
    {
        row = getRandom(0, ROWS);
        col = getRandom(0, COLS);
    }
    grid[row][col] = PLAYER;
    
    // Loop until player status changes to DEAD or ESCAPED
    while (checkPlayerStatus(grid, row, col, steps, treasureCount) == ALIVE)
    {
        printGrid(grid, steps, treasureCount);
        int move = movePlayer(grid, &row, &col, &steps, &treasureCount);
        if (move == -1)
        {
            printf("Error: invalid move.\n");
            return -1;
        }
    }
    
    // Print final grid status and player result
    printGrid(grid, steps, treasureCount);
    
    switch (checkPlayerStatus(grid, row, col, steps, treasureCount))
    {
        case DEAD:
            printf("You have died! Game over.\n");
            break;
        case ESCAPED:
            printf("Congratulations, you have escaped the haunted house alive with %d treasure!\n", treasureCount);
            break;
        default:
            printf("Error: unknown player status.\n");
            break;
    }
    
    return 0;
}

// Function to initialize grid with random walls, traps, and treasure
int initializeGrid(int grid[ROWS][COLS], int traps)
{
    // Check if number of traps to add is valid
    if (traps >= ROWS * COLS - 1)
    {
        return -1;
    }
    
    // Randomly add walls, traps, and treasure to grid
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int r = getRandom(1, 100);
            if (r <= 20)
            {
                grid[i][j] = WALL;
            }
            else if (r <= 40 && traps > 0)
            {
                grid[i][j] = TRAP;
                traps--;
            }
            else if (r <= 45)
            {
                grid[i][j] = TREASURE;
            }
            else
            {
                grid[i][j] = EMPTY;
            }
        }
    }
    
    return 0;
}

// Function to get a random integer between min and max (inclusive)
int getRandom(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to print the current grid status and player stats
void printGrid(int grid[ROWS][COLS], int steps, int treasureCount)
{
    printf("\n");
    printf("Moves remaining: %d    Treasures found: %d\n", MAX_STEPS - steps, treasureCount);
    printf("+");
    for (int j = 0; j < COLS; j++)
    {
        printf("-+");
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("|");
        for (int j = 0; j < COLS; j++)
        {
            switch (grid[i][j])
            {
                case EMPTY:
                    printf(" |");
                    break;
                case WALL:
                    printf("#|");
                    break;
                case TRAP:
                    printf("*|");
                    break;
                case TREASURE:
                    printf("$|");
                    break;
                case PLAYER:
                    printf("@|");
                    break;
                default:
                    printf("?|");
                    break;
            }
        }
        printf("\n");
        printf("+");
        for (int j = 0; j < COLS; j++)
        {
            printf("-+");
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int checkMove(int grid[ROWS][COLS], int row, int col)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
    {
        return -1;
    }
    if (grid[row][col] == WALL || grid[row][col] == TRAP)
    {
        return -1;
    }
    return 0;
}

// Function to move the player and update grid
int movePlayer(int grid[ROWS][COLS], int *row, int *col, int *steps, int *treasureCount)
{
    char dir;
    printf("Enter direction to move (U/D/L/R): ");
    scanf(" %c", &dir);
    
    int newRow = *row;
    int newCol = *col;
    
    switch (dir)
    {
        case 'U':
            newRow--;
            break;
        case 'D':
            newRow++;
            break;
        case 'L':
            newCol--;
            break;
        case 'R':
            newCol++;
            break;
        default:
            return -1;
            break;
    }
    
    int check = checkMove(grid, newRow, newCol);
    if (check == -1)
    {
        return -1;
    }
    
    (*steps)++;
    if (grid[newRow][newCol] == TREASURE)
    {
        (*treasureCount)++;
    }
    
    grid[*row][*col] = EMPTY;
    grid[newRow][newCol] = PLAYER;
    *row = newRow;
    *col = newCol;
    
    return 0;
}

// Function to check player status based on grid contents and steps/treasure found
int checkPlayerStatus(int grid[ROWS][COLS], int row, int col, int steps, int treasureCount)
{
    if (steps >= MAX_STEPS)
    {
        return DEAD;
    }
    if (grid[row][col] != PLAYER)
    {
        return DEAD;
    }
    if (treasureCount >= 3)
    {
        return ESCAPED;
    }
    return ALIVE;
}