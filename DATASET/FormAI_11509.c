//FormAI DATASET v1.0 Category: Checkers Game ; Style: automated
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Global variables
int board[BOARD_SIZE][BOARD_SIZE];
int turn = 0;

// Function prototypes
void initializeBoard();
void printBoard();
bool isValidMove(int, int, int, int);
bool isJumpValid(int, int, int, int);
bool checkEndGame();
int countPieces(int);
void makeMove(int, int, int, int);
void makeJump(int, int, int, int);

// Main function
int main()
{
    initializeBoard();

    while (true)
    {
        printBoard();

        // Make sure there are still moves left
        if (checkEndGame())
        {
            printf("Player %d wins!\n", turn % 2 + 1);
            break;
        }

        // Get input from user and check if it is valid
        int x, y, newX, newY;
        printf("Player %d's turn. Enter your move: ", turn % 2 + 1);
        scanf("%d %d %d %d", &x, &y, &newX, &newY);

        if (!isValidMove(x, y, newX, newY))
        {
            printf("Invalid move! Please try again.\n");
            continue;
        }

        // Check if a jump is being made
        if (isJumpValid(x, y, newX, newY))
        {
            makeJump(x, y, newX, newY);

            // Check if the player can make another jump
            if (isJumpValid(newX, newY, newX-2, newY-2) ||
                isJumpValid(newX, newY, newX-2, newY+2) ||
                isJumpValid(newX, newY, newX+2, newY-2) ||
                isJumpValid(newX, newY, newX+2, newY+2))
            {
                printf("Player %d has made a jump. Please make another jump.\n", turn % 2 + 1);
                continue;
            }
        }
        else // Standard move
        {
            makeMove(x, y, newX, newY);
        }

        turn++;
    }

    return 0;
}

// Function to initialize the board
void initializeBoard()
{
    // Initialize all spaces to 0
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Place player 1's pieces
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if ((i+j) % 2 == 0)
            {
                board[i][j] = 1;
            }
        }
    }

    // Place player 2's pieces
    for (int i = BOARD_SIZE-1; i >= BOARD_SIZE-3; i--)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if ((i+j) % 2 == 0)
            {
                board[i][j] = 2;
            }
        }
    }
}

// Function to print the current board state
void printBoard()
{
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d  ", i);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                printf(". ");
            }
            else if (board[i][j] == 1)
            {
                printf("O ");
            }
            else
            {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Function to check if a move is valid
bool isValidMove(int x, int y, int newX, int newY)
{
    // Check if the requested space is out of bounds
    if (newX < 0 || newX >= BOARD_SIZE || newY < 0 || newY >= BOARD_SIZE)
    {
        return false;
    }

    // Check if the new space is not empty
    if (board[newX][newY] != 0)
    {
        return false;
    }

    // Check if the piece being moved belongs to the current player
    if (board[x][y] != turn % 2 + 1)
    {
        return false;
    }

    // Check if the move is a standard move
    if ((newX == x+1 && newY == y+1) || (newX == x+1 && newY == y-1) ||
        (newX == x-1 && newY == y+1) || (newX == x-1 && newY == y-1))
    {
        return true;
    }

    // Check if the move is a jump
    if ((newX == x+2 && newY == y+2 && board[x+1][y+1] == (turn+1) % 2 + 1) ||
        (newX == x+2 && newY == y-2 && board[x+1][y-1] == (turn+1) % 2 + 1) ||
        (newX == x-2 && newY == y+2 && board[x-1][y+1] == (turn+1) % 2 + 1) ||
        (newX == x-2 && newY == y-2 && board[x-1][y-1] == (turn+1) % 2 + 1))
    {
        return true;
    }

    return false;
}

// Function to check if a jump is valid
bool isJumpValid (int x, int y, int newX, int newY)
{
    if (!isValidMove(x, y, newX, newY))
    {
        return false;
    }

    if ((newX == x+2 && newY == y+2 && board[x+1][y+1] == (turn+1) % 2 + 1) ||
        (newX == x+2 && newY == y-2 && board[x+1][y-1] == (turn+1) % 2 + 1) ||
        (newX == x-2 && newY == y+2 && board[x-1][y+1] == (turn+1) % 2 + 1) ||
        (newX == x-2 && newY == y-2 && board[x-1][y-1] == (turn+1) % 2 + 1))
    {
        return true;
    }

    return false;
}

// Function to check if the game is over
bool checkEndGame()
{
    // Check if one player has no pieces left
    if (countPieces(1) == 0 || countPieces(2) == 0)
    {
        return true;
    }

    // Check if one player is unable to make a move
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == turn % 2 + 1)
            {
                if (isJumpValid(i, j, i+2, j+2) || isJumpValid(i, j, i+2, j-2) ||
                    isJumpValid(i, j, i-2, j+2) || isJumpValid(i, j, i-2, j-2) ||
                    isValidMove(i, j, i+1, j+1) || isValidMove(i, j, i+1, j-1) ||
                    isValidMove(i, j, i-1, j+1) || isValidMove(i, j, i-1, j-1))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

// Function to count the number of pieces belonging to a player
int countPieces(int player)
{
    int count = 0;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == player)
            {
                count++;
            }
        }
    }

    return count;
}

// Function to make a standard move
void makeMove(int x, int y, int newX, int newY)
{
    board[newX][newY] = board[x][y];
    board[x][y] = 0;
}

// Function to make a jump
void makeJump(int x, int y, int newX, int newY)
{
    board[newX][newY] = board[x][y];
    board[x][y] = 0;
    board[(x+newX)/2][(y+newY)/2] = 0;
}