//FormAI DATASET v1.0 Category: Checkers Game ; Style: expert-level
#include <stdio.h>

// Constants
#define BOARD_DIMENSION 8
#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define KING 3

// Board and current turn variables
int board[BOARD_DIMENSION][BOARD_DIMENSION];
int current_turn = BLACK;

// Function declarations
void initialize_board();
void print_board();
int can_move(int row, int col, int row_offset, int col_offset);
int can_capture(int row, int col, int row_offset, int col_offset);
int can_jump(int row, int col, int row_offset, int col_offset);
int make_move(int from_row, int from_col, int to_row, int to_col);
int is_king_row(int row);
int has_valid_move(int player);
int get_winner();

int main()
{
    // Initialize the board
    initialize_board();
    
    // Print the board
    print_board();
    
    // Game loop
    while (1)
    {
        int winner = get_winner();
        if (winner != EMPTY)
        {
            printf("Winner: %s\n", winner == BLACK ? "Black" : "White");
            break;
        }
        
        if (!has_valid_move(current_turn))
        {
            printf("%s cannot move. Skipping turn.\n", current_turn == BLACK ? "Black" : "White");
            current_turn = (current_turn == BLACK) ? WHITE : BLACK;
            continue;
        }
        
        int from_row, from_col, to_row, to_col;
        printf("%s's move.\n", current_turn == BLACK ? "Black" : "White");
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &from_row, &from_col);
        printf("Enter the row and column of the square you want to move to: ");
        scanf("%d %d", &to_row, &to_col);
        
        int result = make_move(from_row, from_col, to_row, to_col);
        if (result == 0)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        else if (result == 1)
        {
            printf("%s moved from (%d,%d) to (%d,%d).\n", current_turn == BLACK ? "Black" : "White",
                   from_row, from_col, to_row, to_col);
        }
        else if (result == 2)
        {
            printf("%s captured a piece at (%d,%d) and moved to (%d,%d).\n", current_turn == BLACK ? "Black" : "White",
                   (from_row + to_row) / 2, (from_col + to_col) / 2, to_row, to_col);
        }
        
        // Print the board
        print_board();
        
        // Switch the turn
        current_turn = (current_turn == BLACK) ? WHITE : BLACK;
    }
    
    return 0;
}

// Initializes the board to the starting configuration
void initialize_board()
{
    for (int i = 0; i < BOARD_DIMENSION; i++)
    {
        for (int j = 0; j < BOARD_DIMENSION; j++)
        {
            // Black and white pieces are placed on alternating dark squares
            if ((i + j) % 2 == 1)
            {
                if (i < 3)
                {
                    board[i][j] = BLACK;
                }
                else if (i > 4)
                {
                    board[i][j] = WHITE;
                }
                else
                {
                    board[i][j] = EMPTY;
                }
            }
            else
            {
                board[i][j] = EMPTY;
            }
        }
    }
}

// Prints the current state of the board
void print_board()
{
    // Print the column numbers
    printf("  ");
    for (int i = 0; i < BOARD_DIMENSION; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    
    // Print the board state
    for (int i = 0; i < BOARD_DIMENSION; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < BOARD_DIMENSION; j++)
        {
            printf("%c ", board[i][j] == EMPTY ? '-' :
                   (board[i][j] == BLACK ? 'B' : (board[i][j] == WHITE ? 'W' : 'K')));
        }
        printf("\n");
    }
}

// Returns 1 if the piece at (row,col) can move one square in the given direction
int can_move(int row, int col, int row_offset, int col_offset)
{
    if (board[row][col] == BLACK || board[row][col] == KING)
    {
        if (row + row_offset < 0 || row + row_offset >= BOARD_DIMENSION ||
            col + col_offset < 0 || col + col_offset >= BOARD_DIMENSION)
        {
            return 0;
        }
        if (board[row + row_offset][col + col_offset] == EMPTY)
        {
            return 1;
        }
    }
    if (board[row][col] == WHITE || board[row][col] == KING)
    {
        if (row - row_offset < 0 || row - row_offset >= BOARD_DIMENSION ||
            col + col_offset < 0 || col + col_offset >= BOARD_DIMENSION)
        {
            return 0;
        }
        if (board[row - row_offset][col + col_offset] == EMPTY)
        {
            return 1;
        }
    }
    return 0;
}

// Returns 1 if the piece at (row,col) can capture an opponent piece in the given direction
int can_capture(int row, int col, int row_offset, int col_offset)
{
    if (board[row][col] == BLACK || board[row][col] == KING)
    {
        if (row + 2*row_offset < 0 || row + 2*row_offset >= BOARD_DIMENSION ||
            col + 2*col_offset < 0 || col + 2*col_offset >= BOARD_DIMENSION)
        {
            return 0;
        }
        if (board[row + row_offset][col + col_offset] != EMPTY &&
            board[row + row_offset][col + col_offset] != current_turn &&
            board[row + 2*row_offset][col + 2*col_offset] == EMPTY)
        {
            return 1;
        }
    }
    if (board[row][col] == WHITE || board[row][col] == KING)
    {
        if (row - 2*row_offset < 0 || row - 2*row_offset >= BOARD_DIMENSION ||
            col + 2*col_offset < 0 || col + 2*col_offset >= BOARD_DIMENSION)
        {
            return 0;
        }
        if (board[row - row_offset][col + col_offset] != EMPTY &&
            board[row - row_offset][col + col_offset] != current_turn &&
            board[row - 2*row_offset][col + 2*col_offset] == EMPTY)
        {
            return 1;
        }
    }
    return 0;
}

// Returns 1 if the piece at (row,col) can jump over an opponent piece in the given direction
int can_jump(int row, int col, int row_offset, int col_offset)
{
    if (board[row][col] == BLACK || board[row][col] == KING)
    {
        if (row + 2*row_offset < 0 || row + 2*row_offset >= BOARD_DIMENSION ||
            col + 2*col_offset < 0 || col + 2*col_offset >= BOARD_DIMENSION)
        {
            return 0;
        }
        if (board[row + row_offset][col + col_offset] != EMPTY &&
            board[row + row_offset][col + col_offset] != current_turn &&
            board[row + 2*row_offset][col + 2*col_offset] == EMPTY)
        {
            return 1;
        }
    }
    if (board[row][col] == WHITE || board[row][col] == KING)
    {
        if (row - 2*row_offset < 0 || row - 2*row_offset >= BOARD_DIMENSION ||
            col + 2*col_offset < 0 || col + 2*col_offset >= BOARD_DIMENSION)
        {
            return 0;
        }
        if (board[row - row_offset][col + col_offset] != EMPTY &&
            board[row - row_offset][col + col_offset] != current_turn &&
            board[row - 2*row_offset][col + 2*col_offset] == EMPTY)
        {
            return 1;
        }
    }
    return 0;
}

// Makes a move from (from_row,from_col) to (to_row,to_col) if it is legal
// Returns 0 if the move is illegal, 1 if it is a regular move, or 2 if it captures an opponent piece
int make_move(int from_row, int from_col, int to_row, int to_col)
{
    if (board[from_row][from_col] == EMPTY || board[to_row][to_col] != EMPTY)
    {
        return 0;
    }
    if (current_turn == BLACK && board[from_row][from_col] != BLACK && board[from_row][from_col] != KING)
    {
        return 0;
    }
    if (current_turn == WHITE && board[from_row][from_col] != WHITE && board[from_row][from_col] != KING)
    {
        return 0;
    }
    
    int row_diff = to_row - from_row;
    int col_diff = to_col - from_col;
    
    // Regular move
    if (can_move(from_row, from_col, row_diff, col_diff))
    {
        board[from_row][from_col] = EMPTY;
        board[to_row][to_col] = (is_king_row(to_row) ? KING : current_turn);
        return 1;
    }
    // Capture move
    else if (can_capture(from_row, from_col, row_diff/2, col_diff/2))
    {
        board[from_row][from_col] = EMPTY;
        board[to_row][to_col] = (is_king_row(to_row) ? KING : current_turn);
        board[(from_row + to_row) / 2][(from_col + to_col) / 2] = EMPTY;
        return 2;
    }
    // Invalid move
    else
    {
        return 0;
    }
}

// Returns 1 if the given row has a piece that can become a king
int is_king_row(int row)
{
    for (int col = 0; col < BOARD_DIMENSION; col++)
    {
        if (board[row][col] == BLACK && row == BOARD_DIMENSION - 1)
        {
            return 1;
        }
        if (board[row][col] == WHITE && row == 0)
        {
            return 1;
        }
    }
    return 0;
}

// Returns 1 if the given player has a valid move, 0 otherwise
int has_valid_move(int player)
{
    for (int row = 0; row < BOARD_DIMENSION; row++)
    {
        for (int col = 0; col < BOARD_DIMENSION; col++)
        {
            if (board[row][col] == player || board[row][col] == player + 2)
            {
                if (can_move(row, col, 1, -1) || can_move(row, col, 1, 1) ||
                    can_move(row, col, -1, -1) || can_move(row, col, -1, 1) ||
                    can_capture(row, col, 1, -1) || can_capture(row, col, 1, 1) ||
                    can_capture(row, col, -1, -1) || can_capture(row, col, -1, 1))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Returns the winner of the game (BLACK, WHITE, or EMPTY if the game is not over)
int get_winner()
{
    int black_count = 0;
    int white_count = 0;
    for (int row = 0; row < BOARD_DIMENSION; row++)
    {
        for (int col = 0; col < BOARD_DIMENSION; col++)
        {
            if (board[row][col] == BLACK || board[row][col] == KING)
            {
                black_count++;
            }
            else if (board[row][col] == WHITE || board[row][col] == KING+1)
            {
                white_count++;
            }
        }
    }
    if (black_count == 0)
    {
        return WHITE;
    }
    if (white_count == 0)
    {
        return BLACK;
    }
    return EMPTY;
}