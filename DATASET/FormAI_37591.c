//FormAI DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20     // Number of rows in the board
#define COLS 40     // Number of columns in the board
#define ALIVE 'O'   // Character to represent alive cells
#define DEAD '.'    // Character to represent dead cells

// Function signatures
void init_board(char board[][COLS]);
void display_board(char board[][COLS]);
void update_board(char board[][COLS]);

int main()
{
    char board[ROWS][COLS];     // Board to hold current state of cells
    
    srand(time(NULL));          // Seed the random number generator
    
    init_board(board);          // Initialize the board
    display_board(board);       // Display the initial state of the board
    
    // Loop forever
    while (1)
    {
        printf("Press Enter to continue or q to quit: ");
        char input = getchar();     // Wait for user input
        
        if (input == 'q' || input == 'Q')
        {
            break;      // Quit the game if user enters q
        }
        
        update_board(board);    // Update the board
        system("clear");        // Clear the screen
        display_board(board);   // Display the new state of the board
    }
    
    return 0;
}

// Initialize the board with random cells
void init_board(char board[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (rand() % 2 == 0)
            {
                board[i][j] = ALIVE;    // Mark the cell as alive
            }
            else
            {
                board[i][j] = DEAD;     // Mark the cell as dead
            }
        }
    }
}

// Display the current state of the board
void display_board(char board[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", board[i][j]);    // Print the cell
        }
        printf("\n");    // Move to next row
    }
}

// Update the state of the cells based on the rules of the game
void update_board(char board[][COLS])
{
    char new_board[ROWS][COLS];    // Board to hold the new state of cells
    
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int count = 0;    // Count number of alive neighbors
            
            // Check neighboring cells
            for (int x = i-1; x <= i+1; x++)
            {
                for (int y = j-1; y <= j+1; y++)
                {
                    // Skip cells outside the board
                    if (x < 0 || x >= ROWS || y < 0 || y >= COLS)
                    {
                        continue;
                    }
                    
                    // Skip the current cell
                    if (x == i && y == j)
                    {
                        continue;
                    }
                    
                    // Count the number of alive neighbors
                    if (board[x][y] == ALIVE)
                    {
                        count++;
                    }
                }
            }
            
            // Apply the rules of the game
            if (board[i][j] == ALIVE && (count < 2 || count > 3))
            {
                new_board[i][j] = DEAD;     // Cell dies due to under or over population
            }
            else if (board[i][j] == DEAD && count == 3)
            {
                new_board[i][j] = ALIVE;    // Cell comes to life due to reproduction
            }
            else
            {
                new_board[i][j] = board[i][j];    // Cell maintains its current state
            }
        }
    }
    
    // Copy the new state of cells to the original board
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = new_board[i][j];
        }
    }
}