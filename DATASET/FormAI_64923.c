//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 30

// Function to check game over
bool checkGameOver(char gameGrid[ROWS][COLUMNS], int pacManRow, int pacManCol)
{
    char object = gameGrid[pacManRow][pacManCol];
    if (object == '#')
    {
        printf("\nGAME OVER!\n");
        return true;
    }
    return false;
}

int main()
{
    // Initialize game grid with walls and dots
    char gameGrid[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLUMNS - 1 || (i == ROWS/2 && j == COLUMNS/2))
            {
                gameGrid[i][j] = '#';
            }
            else
            {
                gameGrid[i][j] = '.';
            }
        }
    }

    // Initialize Pac-Man position
    int pacManRow = ROWS / 2;
    int pacManCol = COLUMNS / 2;

    // Initialize ghost position
    int ghostRow = ROWS / 3;
    int ghostCol = COLUMNS / 3;

    // Initialize random seed for movement
    srand(time(NULL));
    
    // Game loop
    bool gameOver = false;
    while (!gameOver)
    {
        // Print game grid with Pac-Man and ghost
        system("clear"); // Clear console screen
        gameGrid[pacManRow][pacManCol] = 'P';
        gameGrid[ghostRow][ghostCol] = 'G';
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLUMNS; j++)
            {
                printf("%c ", gameGrid[i][j]);
            }
            printf("\n");
        }
        gameGrid[pacManRow][pacManCol] = '.'; // Remove Pac-Man from game grid
        gameGrid[ghostRow][ghostCol] = '.'; // Remove ghost from game grid
        
        // Get Pac-Man movement input
        char movement = getchar();
        getchar(); // Remove newline character
        
        // Move Pac-Man
        switch (movement)
        {
            case 'w':
                if (gameGrid[pacManRow-1][pacManCol] != '#')
                {
                    pacManRow--;
                }
                break;
            case 'a':
                if (gameGrid[pacManRow][pacManCol-1] != '#')
                {
                    pacManCol--;
                }
                break;
            case 's':
                if (gameGrid[pacManRow+1][pacManCol] != '#')
                {
                    pacManRow++;
                }
                break;
            case 'd':
                if (gameGrid[pacManRow][pacManCol+1] != '#')
                {
                    pacManCol++;
                }
                break;
        }

        // Move ghost randomly
        int ghostMovement = rand() % 4;
        switch (ghostMovement)
        {
            case 0:
                if (gameGrid[ghostRow-1][ghostCol] != '#')
                {
                    ghostRow--;
                }
                break;
            case 1:
                if (gameGrid[ghostRow][ghostCol-1] != '#')
                {
                    ghostCol--;
                }
                break;
            case 2:
                if (gameGrid[ghostRow+1][ghostCol] != '#')
                {
                    ghostRow++;
                }
                break;
            case 3:
                if (gameGrid[ghostRow][ghostCol+1] != '#')
                {
                    ghostCol++;
                }
                break;
        }
        
        // Check if game is over
        gameOver = checkGameOver(gameGrid, pacManRow, pacManCol);
    }

    return 0;
}