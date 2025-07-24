//FormAI DATASET v1.0 Category: Checkers Game ; Style: happy
// Welcome to the Happy Checkers Game!
#include <stdio.h>
#include <stdlib.h>

// Board size constants
#define BOARD_SIZE 8
#define PIECES_ON_START 12

// Player constants
#define PLAYER_1 'o'
#define PLAYER_2 'x'

// Error constants
#define INVALID_MOVE -1
#define INVALID_PIECE -2

// Function prototypes
void setup_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int make_move(char board[BOARD_SIZE][BOARD_SIZE], int player, int from_row, int from_col, int to_row, int to_col);
int check_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col);

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int player = 1, moves = 0, result = 0, current_turn = 0;
    int from_row, from_col, to_row, to_col;

    // Set up the board
    setup_board(board);

    printf("Welcome to the Happy Checkers Game!\n");
    printf("Player 1 is '%c' and Player 2 is '%c'\n", PLAYER_1, PLAYER_2);

    // Start the game
    while(result == 0)
    {
        print_board(board);

        // Get move from player
        printf("Player %d's turn: ", player);
        scanf("%d%d%d%d", &from_row, &from_col, &to_row, &to_col);

        // Check if the move is valid
        current_turn = make_move(board, player, from_row, from_col, to_row, to_col);

        if(current_turn == INVALID_PIECE)
        {
            printf("There is no valid piece at that location!\n");
            continue;
        }
        else if(current_turn == INVALID_MOVE)
        {
            printf("That is an invalid move!\n");
            continue;
        }

        // Switch players
        player = (player == 1) ? 2 : 1;

        // Check if the game has ended
        moves++;
        if(moves == PIECES_ON_START * 2)
        {
            printf("The game has ended in a draw!\n");
            result = 1;
        }

        // Check if all the player's pieces have been taken
        if(current_turn == 2)
        {
            printf("Player 1 has won!\n");
            result = 1;
        }
        else if(current_turn == 1)
        {
            printf("Player 2 has won!\n");
            result = 1;
        }
    }

    return 0;
}

// Helper function to set up the board
void setup_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int row, col;

    for(row = 0; row < BOARD_SIZE; row++)
    {
        for(col = 0; col < BOARD_SIZE; col++)
        {
            if((row + col) % 2 == 0)
            {
                board[row][col] = ' ';
            }
            else if(row < 3)
            {
                board[row][col] = PLAYER_1;
            }
            else if(row > 4)
            {
                board[row][col] = PLAYER_2;
            }
            else
            {
                board[row][col] = ' ';
            }
        }
    }
}

// Helper function to print the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int row, col;

    printf("\n  ");
    for(col = 0; col < BOARD_SIZE; col++)
    {
        printf(" %d ", col + 1);
    }

    printf("%s", "\n  ");
    for(col = 0; col < BOARD_SIZE; col++)
    {
        printf("==="); 
    }

    printf("%s", "\n");
    for(row = 0; row < BOARD_SIZE; row++)
    {
        printf("%d|", row + 1);
        for(col = 0; col < BOARD_SIZE; col++)
        {
            printf(" %c ", board[row][col]);
        }
        printf("|%d", row + 1);
        printf("%s", "\n");
    }

    printf("  ");
    for(col = 0; col < BOARD_SIZE; col++)
    {
        printf("==="); 
    }

    printf("%s", "\n  ");
    for(col = 0; col < BOARD_SIZE; col++)
    {
        printf(" %d ", col + 1);
    }

    printf("%s", "\n\n");
}

// Helper function to make a move
int make_move(char board[BOARD_SIZE][BOARD_SIZE], int player, int from_row, int from_col, int to_row, int to_col)
{
    if(board[from_row - 1][from_col - 1] != (player == 1 ? PLAYER_1 : PLAYER_2))
    {
        return INVALID_PIECE;
    }

    int valid_move = check_valid_move(board, from_row, from_col, to_row, to_col);
    if(valid_move == INVALID_MOVE)
    {
        return valid_move;
    }

    // Player 1 can only move pieces downwards
    if(player == 1 && from_row >= to_row)
    {
        return INVALID_MOVE;
    }
    // Player 2 can only move pieces upwards
    else if(player == 2 && from_row <= to_row)
    {
        return INVALID_MOVE;
    }
    // Check if the move is a jump
    if(valid_move == 2)
    {
        board[(from_row - 1) + (to_row - from_row) / 2][(from_col - 1) + (to_col - from_col) / 2] = ' ';
    }

    board[to_row - 1][to_col - 1] = (player == 1 ? PLAYER_1 : PLAYER_2);
    board[from_row - 1][from_col - 1] = ' ';

    // Check if the player has won
    int player_pieces = 0, other_pieces = 0;
    for(int row = 0; row < BOARD_SIZE; row++)
    {
        for(int col = 0; col < BOARD_SIZE; col++)
        {
            if(board[row][col] == (player == 1 ? PLAYER_1 : PLAYER_2))
            {
                player_pieces++;
            }
            else if(board[row][col] == (player == 1 ? PLAYER_2 : PLAYER_1))
            {
                other_pieces++;
            }
        }
    }

    if(other_pieces == 0)
    {
        return player;
    }

    return valid_move;
}

// Helper function to check if a move is valid
int check_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col)
{
    // Check if the move is diagonal
    if(abs(from_row - to_row) != abs(from_col - to_col))
    {
        return INVALID_MOVE;
    }

    int direction_row = (to_row - from_row) / abs(to_row - from_row);
    int direction_col = (to_col - from_col) / abs(to_col - from_col);

    // Check if there is another piece between the start and end positions
    if(abs(to_row - from_row) == 2)
    {
        if(board[from_row - 1 + direction_row][from_col - 1 + direction_col] == ' ')
        {
            return INVALID_MOVE;
        }
        else if(board[from_row - 1 + direction_row][from_col - 1 + direction_col] == board[to_row - 1][to_col - 1] ||
                board[from_row - 1 + direction_row][from_col - 1 + direction_col] == board[from_row - 1][from_col - 1])
        {
            return INVALID_MOVE;
        }
        else
        {
            return 2;
        }
    }
    else if(abs(to_row - from_row) > 2)
    {
        return INVALID_MOVE;
    }

    // Check if the move is one space away
    if(abs(to_row - from_row) == 1 && abs(to_col - from_col) == 1 && board[to_row - 1][to_col - 1] == ' ')
    {
        return 1;
    }

    return INVALID_MOVE;
}