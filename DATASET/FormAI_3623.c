//FormAI DATASET v1.0 Category: Checkers Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Function to initialize the board
void initialize_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++)
    {
        for (j = 0; j < BOARD_SIZE; j++)
        {
            // Place pieces on the board
            if (i < 3)
            {
                if ((i + j) % 2 == 0)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
            else if (i > 4)
            {
                if ((i + j) % 2 == 0)
                    board[i][j] = 2;
                else
                    board[i][j] = 0;
            }
            else
                board[i][j] = 0;
        }
    }
}

// Function to print the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;

    printf("\n");

    // Print column numbers
    printf("  ");
    for (i = 1; i < BOARD_SIZE + 1; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    // Print board
    for (i = 0; i < BOARD_SIZE; i++)
    {
        // Print row numbers
        printf("%d ", i + 1);
        for (j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 0)
                printf("- ");
            else if (board[i][j] == 1)
                printf("b ");
            else if (board[i][j] == 2)
                printf("w ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if move is valid
int is_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int row, int col, int new_row, int new_col)
{
    if (new_row < 0 || new_row >= BOARD_SIZE || new_col < 0 || new_col >= BOARD_SIZE)
        return 0; // Move is off the board
    else if (board[new_row][new_col] != 0)
        return 0; // New square is not empty
    else if (player == 1) // Black player
    {
        if (new_row < row)
            return 0; // Cannot move backwards
        else if ((new_row - row) == 1 && abs(new_col - col) == 1)
            return 1; // Valid move to an adjacent square
        else if ((new_row - row) == 2 && abs(new_col - col) == 2 && board[row + 1][(col + new_col)/2] == 2)
            return 1; // Valid jump move over a white piece
        else
            return 0; // Invalid move
    }
    else // White player
    {
        if (new_row > row)
            return 0; // Cannot move backwards
        else if ((row - new_row) == 1 && abs(new_col - col) == 1)
            return 1; // Valid move to an adjacent square
        else if ((row - new_row) == 2 && abs(new_col - col) == 2 && board[row - 1][(col + new_col)/2] == 1)
            return 1; // Valid jump move over a black piece
        else
            return 0; // Invalid move
    }
}

// Function to make a move
int make_move(int board[BOARD_SIZE][BOARD_SIZE], int player, int row, int col, int new_row, int new_col)
{
    if (is_valid_move(board, player, row, col, new_row, new_col))
    {
        board[new_row][new_col] = player; // Move piece to new square
        board[row][col] = 0; // Remove piece from old square

        // Capture a piece if it was jumped over
        if (abs(new_row - row) == 2)
        {
            board[(row + new_row)/2][(col + new_col)/2] = 0; // Remove captured piece
            return 1; // Indicate that a piece was captured
        }

        return 0; // Indicate that no piece was captured
    }
    else
        return -1; // Indicate that the move was invalid
}

// Function to check if a player has won
int check_win(int board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    int black_count = 0, white_count = 0;

    // Count the number of black and white pieces
    for (i = 0; i < BOARD_SIZE; i++)
        for (j = 0; j < BOARD_SIZE; j++)
            if (board[i][j] == 1)
                black_count++;
            else if (board[i][j] == 2)
                white_count++;

    // Check if a player has no pieces left on the board
    if (black_count == 0)
        return 2; // White player wins
    else if (white_count == 0)
        return 1; // Black player wins
    else
        return 0; // Neither player has won yet
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE];
    int current_player = 1;
    int row, col, new_row, new_col;
    int piece_captured;
    int game_over = 0;

    initialize_board(board);

    while (!game_over)
    {
        printf("Player %d's turn:\n\n", current_player);
        print_board(board);

        printf("Enter the row and column of the piece you want to move:\n");
        scanf("%d %d", &row, &col);

        printf("Enter the row and column of the square you want to move to:\n");
        scanf("%d %d", &new_row, &new_col);

        piece_captured = make_move(board, current_player, row - 1, col - 1, new_row - 1, new_col - 1);

        if (piece_captured == -1)
        {
            printf("\nInvalid move. Try again.\n\n");
        }
        else if (piece_captured == 0)
        {
            current_player = (current_player == 1) ? 2 : 1; // Switch to other player's turn
        }
        else
        {
            // Check if the capturing player has another jump move
            if ((current_player == 1 && is_valid_move(board, current_player, new_row - 1, new_col - 1, new_row - 2, new_col - 2) && board[new_row - 2][new_col - 2] == 0) ||
                (current_player == 2 && is_valid_move(board, current_player, new_row - 1, new_col - 1, new_row, new_col) && board[new_row][new_col] == 0))
            {
                printf("\nYou captured a piece! You get to go again.\n\n");
            }
            else
            {
                current_player = (current_player == 1) ? 2 : 1; // Switch to other player's turn
            }
        }

        // Check if the game is over
        if (check_win(board) != 0)
        {
            game_over = 1;
        }
    }

    printf("Game over!\n\n");
    print_board(board);

    if (check_win(board) == 1)
        printf("Black player wins!\n");
    else
        printf("White player wins!\n");

    return 0;
}