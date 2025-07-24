//FormAI DATASET v1.0 Category: Memory Game ; Style: innovative
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define SIZE 4 // Size of the grid
#define MAX_MOVES 25 // Maximum number of moves
#define MAX_VALUE 9 // Maximum value on the grid

int main() 
{ 
    int grid[SIZE][SIZE] = {0}; // Initialize grid with all 0s
    int moves[MAX_MOVES] = {0}; // Array to store moves
    int moveCount = 0; // Counter for moves 
    int max = MAX_VALUE; // Maximum value allowed on the grid
    int i, j, k; // Counter variables

    srand(time(NULL)); // Initialize random number generator
    printf("Welcome to the C Memory Game!\n\n");

    // Game Loop
    while (1) 
    {   
        // Print out the board
        printf("  ");
        for (i = 0; i < SIZE; i++) 
        {
            printf("%d ", i);
        } 
        printf("\n");
        
        for (i = 0; i < SIZE; i++) 
        {
            printf("%d ", i);
            for (j = 0; j < SIZE; j++) 
            {
                if (grid[i][j] == 0) 
                {
                    printf(". ");
                }
                else 
                {
                    printf("%d ", grid[i][j]);
                }
            }
            printf("\n");
        }
        
        // Check if we've won
        int didWeWin = 1;
        for (i = 0; i < SIZE; i++) 
        {
            for (j = 0; j < SIZE; j++) 
            {
                if (grid[i][j] != (i * SIZE) + (j + 1)) 
                {
                    didWeWin = 0;
                }
            }
        }
        if (didWeWin) 
        {
            printf("\nCongratulations! You win!\n");
            break; 
        }

        // If we've reached the maximum number of allowed moves, game over
        if (moveCount == MAX_MOVES) 
        {
            printf("\nGame over. You've run out of moves.\n");
            break;
        } 
        
        int row1, col1, row2, col2;
        
        // Get user input for first move
        printf("\nEnter the coordinates of the first tile (row, col):");
        scanf("%d %d", &row1, &col1);
        while (grid[row1][col1] != 0) 
        {
            printf("Tile is already flipped, try again:");
            scanf("%d %d", &row1, &col1);
        }
        int val1 = rand() % max + 1;
        grid[row1][col1] = val1;

        // Get user input for second move
        printf("\nEnter the coordinates of the second tile (row, col):");
        scanf("%d %d", &row2, &col2);
        while ((grid[row2][col2] != 0) || ((row1 == row2) && (col1 == col2))) 
        {
            printf("Tile is already flipped, try again:");
            scanf("%d %d", &row2, &col2);
        }
        int val2 = rand() % max + 1;
        grid[row2][col2] = val2;
        
        // If numbers match, keep the tiles flipped
        if (val1 == val2) 
        {
            printf("\nYou found a match! %d and %d will remain flipped.\n", val1, val2);
            moves[moveCount] = val1;
            moveCount++;
        }
        // Otherwise, flip the tiles back over
        else 
        {
            printf("\nSorry, %d and %d didn't match! They have been flipped back over.\n", val1, val2);
            grid[row1][col1] = 0;
            grid[row2][col2] = 0;
        }
        
        // Decrease the maximum number allowed on the grid as the game progresses
        if (moveCount > 10) 
        {
            max = 5;
        }
    }
    
    return 0;  
}