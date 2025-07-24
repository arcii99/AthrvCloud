//FormAI DATASET v1.0 Category: Checkers Game ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
int turn = 1;

// Function to initialize the board with starting pieces
void initialize_board()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if ((i + j) % 2 == 0)
            {
                if (i < 3)
                {
                    board[i][j] = 1;
                }
                else if (i > 4)
                {
                    board[i][j] = 2;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
            else
            {
                board[i][j] = 0;
            }
        }
    }
}

// Function to print the board
void print_board()
{
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 1)
            {
                printf("O ");
            }
            else if (board[i][j] == 2)
            {
                printf("X ");
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_valid_move(int row, int col, int dest_row, int dest_col)
{
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || dest_row < 0 || dest_row >= BOARD_SIZE || dest_col < 0 || dest_col >= BOARD_SIZE)
    {
        return 0;
    }

    if (board[dest_row][dest_col] != 0)
    {
        return 0;
    }

    int piece = board[row][col];
    if (piece == 1 && turn == 2)
    {
        return 0;
    }
    else if (piece == 2 && turn == 1)
    {
        return 0;
    }

    if (abs(dest_row - row) == 1 && abs(dest_col - col) == 1)
    {
        if (abs(dest_row - row) == 1 && abs(dest_col - col) == 1 && abs(dest_row - row) == 1 && abs(dest_col - col) == 1)
        {
            return 0;
        }
        return 1;
    }
    else if (abs(dest_row - row) == 2 && abs(dest_col - col) == 2)
    {
        int mid_row = (row + dest_row) / 2;
        int mid_col = (col + dest_col) / 2;
        int middle = board[mid_row][mid_col];
        if (middle == 0 || (middle == piece))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

// Function to make a move
void make_move(int row, int col, int dest_row, int dest_col)
{
    int piece = board[row][col];
    int king = 0;
    if (piece == 1 && dest_row == BOARD_SIZE - 1)
    {
        king = 1;
    }
    else if (piece == 2 && dest_row == 0)
    {
        king = 1;
    }

    board[dest_row][dest_col] = piece;
    board[row][col] = 0;

    if (king == 1)
    {
        if (piece == 1)
        {
            board[dest_row][dest_col] = 3;
        }
        else
        {
            board[dest_row][dest_col] = 4;
        }
    }

    if (abs(dest_row - row) == 2 && abs(dest_col - col) == 2)
    {
        int mid_row = (row + dest_row) / 2;
        int mid_col = (col + dest_col) / 2;
        board[mid_row][mid_col] = 0;
    }
}

// Function to check if there are any valid moves for a player
int has_valid_moves(int player)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == player || board[i][j] == player + 2)
            {
                for (int k = -2; k <= 2; k++)
                {
                    for (int l = -2; l <= 2; l++)
                    {
                        if (is_valid_move(i, j, i + k, j + l))
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// Function to check if the game is over
int is_game_over()
{
    if (!has_valid_moves(1))
    {
        return 2;
    }

    if (!has_valid_moves(2))
    {
        return 1;
    }

    return 0;
}

int main()
{
    initialize_board();
    int game_over = 0;

    while (!game_over)
    {
        print_board();
        if (turn == 1)
        {
            printf("Player 1's turn (O)\n");
        }
        else
        {
            printf("Player 2's turn (X)\n");
        }
        int row, col, dest_row, dest_col;
        printf("Enter the row and column of the piece you want to move (separated by a space): ");
        scanf("%d %d", &row, &col);
        printf("Enter the row and column of the destination (separated by a space): ");
        scanf("%d %d", &dest_row, &dest_col);
        if (is_valid_move(row, col, dest_row, dest_col))
        {
            make_move(row, col, dest_row, dest_col);
            if (turn == 1)
            {
                turn = 2;
            }
            else
            {
                turn = 1;
            }
        }
        else
        {
            printf("Invalid move.\n");
        }

        game_over = is_game_over();
    }

    print_board();
    if (game_over == 1)
    {
        printf("Player 1 wins!\n");
    }
    else if (game_over == 2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("It's a draw!\n");
    }

    return 0;
}