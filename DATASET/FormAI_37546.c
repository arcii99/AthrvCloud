//FormAI DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // size of the game board

void print_board(int board[][SIZE]); 
int check_winner(int board[][SIZE], int player); 
void get_position(int player, int *row, int *col); 

int main() 
{
    int board[SIZE][SIZE] = {0}; //initialize board with zeros
    int player = 1;
    int row, col;
    int winner = 0;
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Print the initial board
    print_board(board);
    
    // Loop until there is a winner or the board is full
    while (!winner) 
    {
        // Get the player's position
        get_position(player, &row, &col);
        
        // Place the player's marker on the board
        board[row][col] = player;
        
        // Print the board
        print_board(board);
        
        // Check for a winner
        winner = check_winner(board, player);
        
        // Switch to the other player
        player = player == 1 ? 2 : 1;
    }
    
    // Print the winner
    printf("Player %d wins!\n", winner);
    
    return 0;
}

// Print the game board
void print_board(int board[][SIZE]) 
{
    printf("\n");
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++) 
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if a player has won
int check_winner(int board[][SIZE], int player) 
{
    // Check each row
    for (int i = 0; i < SIZE; i++) 
    {
        int count = 0;
        for (int j = 0; j < SIZE; j++) 
        {
            if (board[i][j] == player) 
            {
                count++;
            }
        }
        if (count == SIZE) 
        {
            return player;
        }
    }
    
    // Check each column
    for (int j = 0; j < SIZE; j++) 
    {
        int count = 0;
        for (int i = 0; i < SIZE; i++) 
        {
            if (board[i][j] == player) 
            {
                count++;
            }
        }
        if (count == SIZE) 
        {
            return player;
        }
    }
    
    // Check the main diagonal
    int count = 0;
    for (int i = 0; i < SIZE; i++) 
    {
        if (board[i][i] == player) 
        {
            count++;
        }
    }
    if (count == SIZE) 
    {
        return player;
    }
    
    // Check the secondary diagonal
    count = 0;
    for (int i = 0; i < SIZE; i++) 
    {
        if (board[i][SIZE - 1 - i] == player) 
        {
            count++;
        }
    }
    if (count == SIZE) 
    {
        return player;
    }
    
    // If no winner is found, return 0
    return 0;
}

// Get the player's position
void get_position(int player, int *row, int *col) 
{
    printf("Player %d, enter your position (row, column).\n", player);
    printf("Row (0-9): ");
    scanf("%d", row);
    printf("Column (0-9): ");
    scanf("%d", col);
    printf("\n");
}