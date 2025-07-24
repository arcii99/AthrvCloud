//FormAI DATASET v1.0 Category: Checkers Game ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants for the board size
#define HEIGHT 8
#define WIDTH 8

// Constants for the piece types
#define EMPTY 0
#define BLACK 1
#define RED 2

// Constants for the player types
#define HUMAN 0
#define COMPUTER 1

// Function to print the board
void print_board(int board[HEIGHT][WIDTH])
{
    printf("\nBoard:\n");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (board[i][j] == EMPTY)
            {
                printf(". ");
            }
            else if (board[i][j] == BLACK)
            {
                printf("B ");
            }
            else if (board[i][j] == RED)
            {
                printf("R ");
            }
        }
        printf("\n");
    }
}

// Function to initialize the board
void initialize_board(int board[HEIGHT][WIDTH])
{
    // Set all the positions to empty
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            board[i][j] = EMPTY;
        }
    }

    // Set the black pieces
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if ((i + j) % 2 == 0)
            {
                board[i][j] = BLACK;
            }
        }
    }

    // Set the red pieces
    for (int i = 5; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if ((i + j) % 2 == 0)
            {
                board[i][j] = RED;
            }
        }
    }
}

// Function to check if a move is valid
bool is_valid_move(int board[HEIGHT][WIDTH], int player, int start_row, int start_col, int end_row, int end_col)
{
    // Check if the end position is empty
    if (board[end_row][end_col] != EMPTY)
    {
        return false;
    }

    // Check if the player is moving their own piece
    if (board[start_row][start_col] != player)
    {
        return false;
    }

    // Check if the piece is moving in the correct direction
    if (player == BLACK && end_row < start_row)
    {
        return false;
    }
    else if (player == RED && end_row > start_row)
    {
        return false;
    }

    // Check if the move is diagonal and only one space away
    int row_diff = abs(end_row - start_row);
    int col_diff = abs(end_col - start_col);
    if (row_diff != 1 || col_diff != 1)
    {
        return false;
    }

    // Passed all tests, so the move is valid
    return true;
}

// Function to make a move on the board, returns true if a piece was captured
bool make_move(int board[HEIGHT][WIDTH], int player, int start_row, int start_col, int end_row, int end_col)
{
    // If the move is not valid, return false
    if (!is_valid_move(board, player, start_row, start_col, end_row, end_col))
    {
        return false;
    }

    // Make the move
    board[start_row][start_col] = EMPTY;
    board[end_row][end_col] = player;

    // Check if a piece was captured
    int row_diff = end_row - start_row;
    int col_diff = end_col - start_col;
    int capture_row = start_row + row_diff / 2;
    int capture_col = start_col + col_diff / 2;

    if (board[capture_row][capture_col] == (player % 2) + 1)
    {
        board[capture_row][capture_col] = EMPTY;
        return true;
    }

    // No piece was captured
    return false;
}

// Function to get user input for a move
void get_user_move(int board[HEIGHT][WIDTH], int player, int* start_row, int* start_col, int* end_row, int* end_col)
{
    // Loop until a valid move is entered
    while (true)
    {
        // Get input for starting position
        printf("Enter the row and column of the piece you want to move:\n");
        scanf("%d %d", start_row, start_col);
        if (board[*start_row][*start_col] != player)
        {
            printf("You don't have a piece there. Try again.\n");
            continue;
        }

        // Get input for ending position
        printf("Enter the row and column of the position you want to move to:\n");
        scanf("%d %d", end_row, end_col);

        // Check if the move is valid
        if (!is_valid_move(board, player, *start_row, *start_col, *end_row, *end_col))
        {
            printf("Invalid move. Try again.\n");
            continue;
        }

        // Move is valid, so return
        return;
    }
}

// Function to get a random move for the computer player
void get_computer_move(int board[HEIGHT][WIDTH], int player, int* start_row, int* start_col, int* end_row, int* end_col)
{
    // Loop until a valid move is found
    while (true)
    {
        // Generate random starting and ending positions
        *start_row = rand() % HEIGHT;
        *start_col = rand() % WIDTH;
        *end_row = rand() % HEIGHT;
        *end_col = rand() % WIDTH;

        // Check if the move is valid
        if (is_valid_move(board, player, *start_row, *start_col, *end_row, *end_col))
        {
            // Move is valid, so return
            return;
        }
    }
}

// Function to check if a player has won
bool has_won(int board[HEIGHT][WIDTH], int player)
{
    // Loop through all the positions on the board
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            // Check if the position has one of the player's pieces
            if (board[i][j] == player)
            {
                // Check if any moves are possible for that piece
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        if (is_valid_move(board, player, i, j, i+k, j+l))
                        {
                            // Valid move found, so player has not won yet
                            return false;
                        }
                    }
                }
            }
        }
    }

    // No moves are possible, so player has won
    return true;
}

// Main function to run the game
int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the board
    int board[HEIGHT][WIDTH];
    initialize_board(board);

    // Initialize the players
    int human_player = HUMAN;
    int computer_player = COMPUTER;

    // Loop while the game is not over
    while (true)
    {
        // Print the board
        print_board(board);

        // Human player's turn
        if (human_player == BLACK)
        {
            int start_row, start_col, end_row, end_col;
            get_user_move(board, human_player, &start_row, &start_col, &end_row, &end_col);
            bool captured = make_move(board, human_player, start_row, start_col, end_row, end_col);
            if (captured)
            {
                printf("You captured a piece!\n");
            }
            if (has_won(board, human_player))
            {
                printf("You win!\n");
                break;
            }
        }

        // Computer player's turn
        if (computer_player == BLACK)
        {
            int start_row, start_col, end_row, end_col;
            get_computer_move(board, computer_player, &start_row, &start_col, &end_row, &end_col);
            bool captured = make_move(board, computer_player, start_row, start_col, end_row, end_col);
            if (captured)
            {
                printf("The computer captured a piece!\n");
            }
            if (has_won(board, computer_player))
            {
                printf("The computer wins!\n");
                break;
            }
        }
    }

    return 0;
}