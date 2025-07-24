//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// function to print the game board
void printBoard(char board[][SIZE])
{
    printf("   ");
    for(int i=0; i<SIZE; i++)
        printf(" %d ", i+1);
    printf("\n");
    printf("  ");
    for(int i=0; i<SIZE; i++)
        printf("---");
    printf("\n");
    for(int i=0; i<SIZE; i++)
    {
        printf("%c |", 'A'+i);
        for(int j=0; j<SIZE; j++)
            printf(" %c |", board[i][j]);
        printf("\n");
        printf("  ");
        for(int j=0; j<SIZE; j++)
            printf("---");
        printf("\n");
    }
}

// function to determine if the move is valid
int isValidMove(char board[][SIZE], int row, int col)
{
    if(row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == '-')
        return 1;
    else
        return 0;
}

// function to check if a player has won the game
int hasWon(char board[][SIZE], char player)
{
    // check horizontal
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE-4; j++)
        {
            if(board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player && board[i][j+3] == player && board[i][j+4] == player)
                return 1;
        }
    }
    
    // check vertical
    for(int i=0; i<SIZE-4; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player && board[i+3][j] == player && board[i+4][j] == player)
                return 1;
        }
    }
    
    // check diagonal
    for(int i=0; i<SIZE-4; i++)
    {
        for(int j=0; j<SIZE-4; j++)
        {
            if(board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player && board[i+3][j+3] == player && board[i+4][j+4] == player)
                return 1;
        }
    }
    
    // check other diagonal
    for(int i=0; i<SIZE-4; i++)
    {
        for(int j=4; j<SIZE; j++)
        {
            if(board[i][j] == player && board[i+1][j-1] == player && board[i+2][j-2] == player && board[i+3][j-3] == player && board[i+4][j-4] == player)
                return 1;
        }
    }
    
    return 0;
}

int main()
{
    char board[SIZE][SIZE];
    char player1 = 'X';
    char player2 = 'O';
    char currentPlayer = player1;
    int row, col;
    
    // initialize the board
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            board[i][j] = '-';
        }
    }
    
    srand(time(NULL)); // initialize random seed
    
    while(1)
    {
        printBoard(board);
        
        if(currentPlayer == player1)
            printf("Player 1 (X) turn:\n");
        else
            printf("Player 2 (O) turn:\n");
            
        // get user input
        if(currentPlayer == player1)
        {
            printf("Enter row (A-J): ");
            scanf(" %c", &row);
            printf("Enter column (1-10): ");
            scanf("%d", &col);
            row -= 'A'; // convert letter to index
            col--; // convert number to index
        }
        else
        {
            // generate random move for player 2
            do
            {
                row = rand() % SIZE;
                col = rand() % SIZE;
            } while(!isValidMove(board, row, col));
        }
        
        // make move
        board[row][col] = currentPlayer;
        
        // check for win
        if(hasWon(board, currentPlayer))
        {
            printf("\n");
            printBoard(board);
            printf("Player %d (%c) has won the game!\n", currentPlayer == player1 ? 1 : 2, currentPlayer);
            break;
        }
        
        // switch players
        if(currentPlayer == player1)
            currentPlayer = player2;
        else
            currentPlayer = player1;
    }
    
    return 0;
}