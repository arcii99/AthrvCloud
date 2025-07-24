//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the current game board
void printBoard(char board[][30], int rows, int cols)
{
    printf("\n   ");
    for(int c=0; c<cols; c++)
    {
        printf("%d ", c+1);
    }
    printf("\n");
    
    for(int r=0; r<rows; r++)
    {
        printf("%d |", r+1);
        for(int c=0; c<cols; c++)
        {
            printf("%c|", board[r][c]);
        }
        printf("\n");
    }
}

// Function to check if Pac-Man has collided with any of the ghosts
int checkCollision(char board[][30], int rows, int cols, int x, int y)
{
    if(board[x][y] == 'G')
    {
        return -1; // Pac-Man collided with a ghost
    }
    return 0; // Pac-Man did not collide with any ghosts
}

int main()
{
    srand(time(NULL)); // Seed the random number generator

    char board[20][30]; // Game board array
    
    int rows = 20, cols = 30; // Dimensions of the game board
    
    // Initialize the game board with empty spaces
    for(int r=0; r<rows; r++)
    {
        for(int c=0; c<cols; c++)
        {
            board[r][c] = ' ';
        }
    }
    
    // Initialize the ghosts at random positions on the game board
    for(int i=0; i<5; i++)
    {
        int x = rand() % rows;
        int y = rand() % cols;
        board[x][y] = 'G';
    }
    
    // Initialize Pac-Man at a random position on the game board
    int x = rand() % rows;
    int y = rand() % cols;
    board[x][y] = 'P';
    
    // Print the initial game board
    printBoard(board, rows, cols);
    
    char move = ' '; // Variable to store Pac-Man's move
    
    // Game loop
    while(move != 'q')
    {
        printf("\nEnter move (w,a,s,d): ");
        scanf(" %c", &move);
        
        // Move Pac-Man based on user input
        switch(move)
        {
            case 'w':
                if(x > 0) // Move Pac-Man up
                {
                    board[x][y] = ' '; // Clear the current position of Pac-Man
                    x--; // Decrement the row index
                    board[x][y] = 'P'; // Update the new position of Pac-Man
                }
                break;
            case 'a':
                if(y > 0) // Move Pac-Man left
                {
                    board[x][y] = ' '; // Clear the current position of Pac-Man
                    y--; // Decrement the column index
                    board[x][y] = 'P'; // Update the new position of Pac-Man
                }
                break;
            case 's':
                if(x < rows-1) // Move Pac-Man down
                {
                    board[x][y] = ' '; // Clear the current position of Pac-Man
                    x++; // Increment the row index
                    board[x][y] = 'P'; // Update the new position of Pac-Man
                }
                break;
            case 'd':
                if(y < cols-1) // Move Pac-Man right
                {
                    board[x][y] = ' '; // Clear the current position of Pac-Man
                    y++; // Increment the column index
                    board[x][y] = 'P'; // Update the new position of Pac-Man
                }
                break;
            default:
                break;
        }
        
        // Check for collision with ghosts
        if(checkCollision(board, rows, cols, x, y) == -1)
        {
            printf("\nGame over! Pac-Man was caught by a ghost.\n");
            break;
        }
        
        // Print the updated game board
        printBoard(board, rows, cols);
    }
    
    return 0;
}