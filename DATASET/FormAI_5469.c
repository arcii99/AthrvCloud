//FormAI DATASET v1.0 Category: Chess engine ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Definition of board and pieces
char board[8][8] =
    {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
     {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
     {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
     {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
     {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
     {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
     {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
     {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

int king_pos[2][2] = {{0, 4}, {7, 4}}; // Position of Kings, [0][4] for White and [7][4] for Black

// Function to print the board
void print_board()
{
    printf("\n\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("|%c", board[i][j]);
        }
        printf("|\n\n");
    }
}

// Function to check if the move is valid
int is_move_valid(int curr_row, int curr_col, int new_row, int new_col, int player)
{
    // Check if new position is within the bounds of the board
    if (new_row < 0 || new_row > 7 || new_col < 0 || new_col > 7)
    {
        return 0;
    }

    // Check if player is moving their own piece
    if ((player == 1 && board[curr_row][curr_col] >= 'a' && board[curr_row][curr_col] <= 'z')
        || (player == 2 && board[curr_row][curr_col] >= 'A' && board[curr_row][curr_col] <= 'Z'))
    {
        return 0;
    }

    // Check if new position is not the same as current position
    if (curr_row == new_row && curr_col == new_col)
    {
        return 0;
    }

    // Check if player is not moving onto their own piece
    if ((player == 1 && board[new_row][new_col] >= 'a' && board[new_row][new_col] <= 'z') 
        || (player == 2 && board[new_row][new_col] >= 'A' && board[new_row][new_col] <= 'Z'))
    {
        return 0;
    }

    // Check if player is moving the correct piece
    switch (board[curr_row][curr_col])
    {
    case 'P':
        // Check if pawn is moving forward
        if (curr_col == new_col)
        {
            if (player == 1)
            {
                if (new_row == curr_row - 1 && board[new_row][new_col] == ' ')
                {
                    return 1;
                }
                else if (new_row == curr_row - 2 && curr_row == 6 && board[new_row][new_col] == ' ')
                {
                    return 1;
                }
            }
            else
            {
                if (new_row == curr_row + 1 && board[new_row][new_col] == ' ')
                {
                    return 1;
                }
                else if (new_row == curr_row + 2 && curr_row == 1 && board[new_row][new_col] == ' ')
                {
                    return 1;
                }
            }
        }
        // Check if pawn is capturing
        else
        {
            if (player == 1)
            {
                if (new_row == curr_row - 1 && (new_col == curr_col - 1 || new_col == curr_col + 1) 
                    && board[new_row][new_col] >= 'a' && board[new_row][new_col] <= 'z')
                {
                    return 1;
                }
            }
            else
            {
                if (new_row == curr_row + 1 && (new_col == curr_col - 1 || new_col == curr_col + 1) 
                    && board[new_row][new_col] >= 'A' && board[new_row][new_col] <= 'Z')
                {
                    return 1;
                }
            }
        }
        break;

    case 'R':
        // Check if rook is moving vertically or horizontally
        if (curr_row == new_row || curr_col == new_col)
        {
            // Check if there are no pieces in between the current and new position
            int i;
            if (curr_row == new_row)
            {
                for (i = curr_col + 1; i < new_col; i++)
                {
                    if (board[new_row][i] != ' ')
                    {
                        return 0;
                    }
                }
                for (i = curr_col - 1; i > new_col; i--)
                {
                    if (board[new_row][i] != ' ')
                    {
                        return 0;
                    }
                }
            }
            else
            {
                for (i = curr_row + 1; i < new_row; i++)
                {
                    if (board[i][new_col] != ' ')
                    {
                        return 0;
                    }
                }
                for (i = curr_row - 1; i > new_row; i--)
                {
                    if (board[i][new_col] != ' ')
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }
        break;

    case 'N':
        // Check if knight is moving in an L shape
        if ((abs(new_row - curr_row) == 2 && abs(new_col - curr_col) == 1)
            || (abs(new_row - curr_row) == 1 && abs(new_col - curr_col) == 2))
        {
            return 1;
        }
        break;

    case 'B':
        // Check if bishop is moving diagonally
        if (abs(new_row - curr_row) == abs(new_col - curr_col))
        {
            // Check if there are no pieces in between the current and new position
            int i, j;
            if (new_row > curr_row && new_col > curr_col)
            {
                i = curr_row + 1;
                j = curr_col + 1;
                while (i < new_row && j < new_col)
                {
                    if (board[i][j] != ' ')
                    {
                        return 0;
                    }
                    i++;
                    j++;
                }
            }
            else if (new_row > curr_row && new_col < curr_col)
            {
                i = curr_row + 1;
                j = curr_col - 1;
                while (i < new_row && j > new_col)
                {
                    if (board[i][j] != ' ')
                    {
                        return 0;
                    }
                    i++;
                    j--;
                }
            }
            else if (new_row < curr_row && new_col > curr_col)
            {
                i = curr_row - 1;
                j = curr_col + 1;
                while (i > new_row && j < new_col)
                {
                    if (board[i][j] != ' ')
                    {
                        return 0;
                    }
                    i--;
                    j++;
                }
            }
            else
            {
                i = curr_row - 1;
                j = curr_col - 1;
                while (i > new_row && j > new_col)
                {
                    if (board[i][j] != ' ')
                    {
                        return 0;
                    }
                    i--;
                    j--;
                }
            }
            return 1;
        }
        break;

    case 'Q':
        // Check if queen is moving vertically, horizontally, or diagonally
        if (curr_row == new_row || curr_col == new_col || abs(new_row - curr_row) == abs(new_col - curr_col))
        {
            // Check if there are no pieces in between the current and new position
            int i, j;
            if (curr_row == new_row)
            {
                for (i = curr_col + 1; i < new_col; i++)
                {
                    if (board[new_row][i] != ' ')
                    {
                        return 0;
                    }
                }
                for (i = curr_col - 1; i > new_col; i--)
                {
                    if (board[new_row][i] != ' ')
                    {
                        return 0;
                    }
                }
            }
            else if (curr_col == new_col)
            {
                for (i = curr_row + 1; i < new_row; i++)
                {
                    if (board[i][new_col] != ' ')
                    {
                        return 0;
                    }
                }
                for (i = curr_row - 1; i > new_row; i--)
                {
                    if (board[i][new_col] != ' ')
                    {
                        return 0;
                    }
                }
            }
            else
            {
                if (new_row > curr_row && new_col > curr_col)
                {
                    i = curr_row + 1;
                    j = curr_col + 1;
                    while (i < new_row && j < new_col)
                    {
                        if (board[i][j] != ' ')
                        {
                            return 0;
                        }
                        i++;
                        j++;
                    }
                }
                else if (new_row > curr_row && new_col < curr_col)
                {
                    i = curr_row + 1;
                    j = curr_col - 1;
                    while (i < new_row && j > new_col)
                    {
                        if (board[i][j] != ' ')
                        {
                            return 0;
                        }
                        i++;
                        j--;
                    }
                }
                else if (new_row < curr_row && new_col > curr_col)
                {
                    i = curr_row - 1;
                    j = curr_col + 1;
                    while (i > new_row && j < new_col)
                    {
                        if (board[i][j] != ' ')
                        {
                            return 0;
                        }
                        i--;
                        j++;
                    }
                }
                else
                {
                    i = curr_row - 1;
                    j = curr_col - 1;
                    while (i > new_row && j > new_col)
                    {
                        if (board[i][j] != ' ')
                        {
                            return 0;
                        }
                        i--;
                        j--;
                    }
                }
            }
            return 1;
        }
        break;

    case 'K':
        // Check if king is moving one step in any direction
        if (abs(new_row - curr_row) <= 1 && abs(new_col - curr_col) <= 1)
        {
            return 1;
        }

        // Check if king is castling
        if (curr_row == new_row && abs(new_col - curr_col) == 2)
        {
            if ((player == 1 && curr_row == 7 && curr_col == 4 && new_col == 6 && board[7][7] == 'R' 
                && board[7][5] == ' ' && board[7][6] == ' ') 
                || (player == 2 && curr_row == 0 && curr_col == 4 && new_col == 2 && board[0][0] == 'r' 
                && board[0][3] == ' ' && board[0][2] == ' ' && board[0][1] == ' '))
            {
                return 1;
            }
        }
        break;

    default:
        break;
    }

    // Return 0 if move is invalid for the piece
    return 0;
}

// Function to play a move
void play_move(int curr_row, int curr_col, int new_row, int new_col)
{
    // Check if move is castling
    if (board[curr_row][curr_col] == 'K' && abs(new_col - curr_col) == 2)
    {
        if (new_col == 6)
        {
            board[curr_row][curr_col + 2] = board[curr_row][curr_col];
            board[curr_row][curr_col] = ' ';
            board[curr_row][curr_col + 1] = board[curr_row][curr_col + 3];
            board[curr_row][curr_col + 3] = ' ';
        }
        else
        {
            board[curr_row][curr_col - 2] = board[curr_row][curr_col];
            board[curr_row][curr_col] = ' ';
            board[curr_row][curr_col - 1] = board[curr_row][curr_col - 4];
            board[curr_row][curr_col - 4] = ' ';
        }
    }
    else
    {
        board[new_row][new_col] = board[curr_row][curr_col];
        board[curr_row][curr_col] = ' ';
    }

    // Update position of kings
    if (board[new_row][new_col] == 'K')
    {
        king_pos[0][0] = new_row;
        king_pos[0][1] = new_col;
    }
    else if (board[new_row][new_col] == 'k')
    {
        king_pos[1][0] = new_row;
        king_pos[1][1] = new_col;
    }
}

int main()
{
    // Initial position of board
    print_board();

    // Loop to play the game
    int player = 1; // White starts first
    int curr_row, curr_col, new_row, new_col;
    while (1)
    {
        // Get input from user
        printf("\nPlayer %d's turn:\n\nEnter current row: ", player);
        scanf("%d", &curr_row);
        printf("Enter current column: ");
        scanf("%d", &curr_col);
        printf("Enter new row: ");
        scanf("%d", &new_row);
        printf("Enter new column: ");
        scanf("%d", &new_col);

        // Check if move is valid
        if (is_move_valid(curr_row, curr_col, new_row, new_col, player))
        {
            // Play the move
            play_move(curr_row, curr_col, new_row, new_col);

            // Check if game is over (king is in checkmate or stalemate)
            // Code for this has to be implemented

            // Print updated board
            print_board();

            // Change player
            player = (player == 1) ? 2 : 1;
        }
        else
        {
            printf("\nInvalid Move, Please Try Again.\n");
        }
    }

    return 0;
}