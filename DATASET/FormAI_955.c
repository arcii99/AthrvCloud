//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Global variables
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int playerScore = 0;
int computerScore = 0;
int gameCount = 0;
// Function prototypes
void printBoard();
int winner();
void playerMove();
void computerMove();
int minimax(int depth, int isMaximizing);
// Entry point
int main()
{
    srand(time(0));
    printf("Welcome to Tic Tac Toe!\n\n");
    printf("Player: X\n");
    printf("Computer: O\n\n");
    printf("Instructions:\n");
    printf("Enter a row and column number (separated by a space) to make a move.\n");
    printf("For example, to make a move in the top-right corner, enter '1 3'.\n");
    printf("Press Ctrl+C to quit at any time.\n\n");
    // Main game loop
    while (1)
    {
        // Reset board
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }
        // Print board
        printBoard();
        // Game loop
        while (1)
        {
            // Player move
            playerMove();
            printBoard();
            // Check for winner
            if (winner() != 0)
            {
                break;
            }
            // Computer move
            printf("The computer is thinking...\n");
            computerMove();
            printBoard();
            // Check for winner
            if (winner() != 0)
            {
                break;
            }
        }
        // Game over
        gameCount++;
        int result = winner();
        if (result == 1)
        {
            printf("You win!\n\n");
            playerScore++;
        }
        else if (result == 2)
        {
            printf("The computer wins.\n\n");
            computerScore++;
        }
        else
        {
            printf("It's a tie.\n\n");
        }
        printf("Player: %d\n", playerScore);
        printf("Computer: %d\n", computerScore);
        printf("Total games played: %d\n\n", gameCount);
        printf("Do you want to play again? (y/n) ");
        char ch;
        scanf(" %c", &ch);
        if (ch == 'n' || ch == 'N')
        {
            break;
        }
    }
    return 0;
}
// Print the board
void printBoard()
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}
// Check for the winner
int winner()
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            if (board[i][0] == 'X')
            {
                return 1;
            }
            else if (board[i][0] == 'O')
            {
                return 2;
            }
        }
    }
    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            if (board[0][i] == 'X')
            {
                return 1;
            }
            else if (board[0][i] == 'O')
            {
                return 2;
            }
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        if (board[0][0] == 'X')
        {
            return 1;
        }
        else if (board[0][0] == 'O')
        {
            return 2;
        }
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        if (board[0][2] == 'X')
        {
            return 1;
        }
        else if (board[0][2] == 'O')
        {
            return 2;
        }
    }
    // Check for tie
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 3;
}
// Get the player's move
void playerMove()
{
    while (1)
    {
        printf("Enter your move: ");
        int row, col;
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if (row < 0 || row > 2 || col < 0 || col > 2)
        {
            printf("Invalid move.\n");
        }
        else if (board[row][col] != ' ')
        {
            printf("That space is already taken.\n");
        }
        else
        {
            board[row][col] = 'X';
            break;
        }
    }
}
// Get the computer's move
void computerMove()
{
    int bestScore = -1000;
    int row, col;
    // Find the best move
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = 'O';
                int score = minimax(0, 0);
                board[i][j] = ' ';
                if (score > bestScore)
                {
                    bestScore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    // Make the move
    board[row][col] = 'O';
}
// Minimax algorithm with alpha-beta pruning
int minimax(int depth, int isMaximizing)
{
    int result = winner();
    if (result != 0)
    {
        if (result == 1)
        {
            return -10 + depth;
        }
        else if (result == 2)
        {
            return 10 - depth;
        }
        else
        {
            return 0;
        }
    }
    if (isMaximizing)
    {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'O';
                    int score = minimax(depth + 1, 0);
                    board[i][j] = ' ';
                    if (score > bestScore)
                    {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = 'X';
                    int score = minimax(depth + 1, 1);
                    board[i][j] = ' ';
                    if (score < bestScore)
                    {
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}