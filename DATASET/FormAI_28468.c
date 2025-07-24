//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

// Function declarations
void printBoard(char board[ROWS][COLS]);
int movePlayer(char board[ROWS][COLS], int row, int col);
int isGameOver(char board[ROWS][COLS]);

// Main function
int main()
{
    // Initialize the board
    char board[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '.', '#', '#', '#', '#', '.', '#', '.', '#'},
        {'#', '.', '.', '.', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '#', '#', '.', '#', '.', '#', '.', '#'},
        {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    // Player starting position
    int playerRow = 1;
    int playerCol = 1;

    // Game loop
    while(!isGameOver(board))
    {
        // Print the board
        printBoard(board);

        // Move the player
        int validMove = movePlayer(board, playerRow, playerCol);

        if(validMove)
        {
            // Update player position
            if(board[playerRow][playerCol] != '$')
            {
                board[playerRow][playerCol] = '.';
            }
            playerRow = validMove / 10;
            playerCol = validMove % 10;
            board[playerRow][playerCol] = '@';
        }
    }

    // Game over
    printf("\nYou have escaped the haunted house!\n");

    return 0;
}

// Function to print the board
void printBoard(char board[ROWS][COLS])
{
    system("clear");

    printf("HAUNTED HOUSE SIMULATOR\n\n");

    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLS; col++)
        {
            printf("%c", board[row][col]);
        }
        printf("\n");
    }
}

// Function to move the player
int movePlayer(char board[ROWS][COLS], int row, int col)
{
    // Get input from user
    printf("\nEnter direction (w/a/s/d): ");
    char input;
    scanf(" %c", &input);

    // Calculate new position
    int newRow = row;
    int newCol = col;

    switch(input)
    {
        case 'w': newRow--; break;
        case 'a': newCol--; break;
        case 's': newRow++; break;
        case 'd': newCol++; break;
    }

    // Check if valid move
    if(board[newRow][newCol] == ' ' || board[newRow][newCol] == '$')
    {
        return newRow * 10 + newCol;
    }
    else
    {
        printf("\nINVALID MOVE!\n");
        return 0;
    }
}

// Function to check if game is over
int isGameOver(char board[ROWS][COLS])
{
    if(board[8][1] == '@')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}