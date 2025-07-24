//FormAI DATASET v1.0 Category: Checkers Game ; Style: detailed
/* A simple Checkers Game in C language */
#include <stdio.h>

#define SIZE 8 // board size
#define EMPTY '.' // empty cell
#define BLACK 'B' // black piece
#define WHITE 'W' // white piece
#define INVALID -1 // invalid move

/* Function prototypes */
void initialize_board(char board[][SIZE]);
void print_board(const char board[][SIZE]);
int make_move(char board[][SIZE], int i, int j, int x, int y);
int valid_move(int player, const char board[][SIZE], int i, int j, int x, int y);
int player_has_moves(int player, const char board[][SIZE]);

/* Main function */
int main()
{
    char board[SIZE][SIZE];
    int i, j, x, y, player, winner;
    
    // initialize the board
    initialize_board(board);
    
    // print the initial board
    print_board(board);
    
    // main game loop
    player = BLACK; // black starts
    winner = 0; // no one wins yet
    while (1)
    {
        // get player move
        printf("\nPlayer %c: enter move (x1 y1 x2 y2): ", player);
        scanf("%d %d %d %d", &i, &j, &x, &y);
        
        // check if move is valid
        if (!valid_move(player, board, i, j, x, y))
        {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        // make the move
        if (make_move(board, i, j, x, y) == INVALID)
        {
            printf("Invalid move! Try again.\n");
            continue;
        }
        
        // print the updated board
        print_board(board);
        
        // check for winner
        if (!player_has_moves(BLACK, board))
        {
            printf("White wins!\n");
            winner = WHITE;
            break;
        }
        if (!player_has_moves(WHITE, board))
        {
            printf("Black wins!\n");
            winner = BLACK;
            break;
        }
        
        // switch player
        player = (player == BLACK) ? WHITE : BLACK;
    }
    
    // print the final board
    print_board(board);
    
    return 0;
}

/* Function definitions */

/* Initializes the board with pieces */
void initialize_board(char board[][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if ((i + j) % 2 == 0 && i < 3) // black pieces
            {
                board[i][j] = BLACK;
            }
            else if ((i + j) % 2 == 0 && i > SIZE - 4) // white pieces
            {
                board[i][j] = WHITE;
            }
            else // empty squares
            {
                board[i][j] = EMPTY;
            }
        }
    }
}

/* Prints the board */
void print_board(const char board[][SIZE])
{
    int i, j;
    printf("\n   0 1 2 3 4 5 6 7\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d  ", i);
        for (j = 0; j < SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* Makes a move on the board */
int make_move(char board[][SIZE], int i, int j, int x, int y)
{
    // check if move is valid
    if (!valid_move(board[i][j], board, i, j, x, y))
    {
        return INVALID;
    }
    
    // make the move
    board[x][y] = board[i][j];
    board[i][j] = EMPTY;
    if (x == 0 && board[x][y] == WHITE) // white piece reaches the end
    {
        board[x][y] = 'w';
    }
    else if (x == SIZE - 1 && board[x][y] == BLACK) // black piece reaches the end
    {
        board[x][y] = 'b';
    }
    
    // remove captured piece
    if (i - x == 2 && j - y == 2) // capture to the left
    {
        board[i-1][j-1] = EMPTY;
    }
    else if (i - x == 2 && j - y == -2) // capture to the right
    {
        board[i-1][j+1] = EMPTY;
    }
    else if (i - x == -2 && j - y == 2) // capture to the left (king)
    {
        board[i+1][j-1] = EMPTY;
    }
    else if (i - x == -2 && j - y == -2) // capture to the right (king)
    {
        board[i+1][j+1] = EMPTY;
    }
    
    return 0;
}

/* Checks if a move is valid */
int valid_move(int player, const char board[][SIZE], int i, int j, int x, int y)
{
    int dx, dy;
    
    // check if initial position is valid
    if (i < 0 || i >= SIZE || j < 0 || j >= SIZE || board[i][j] != player)
    {
        return 0;
    }
    
    // check if final position is empty
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != EMPTY)
    {
        return 0;
    }
    
    // calculate the direction of the move
    dx = x - i;
    dy = y - j;
    
    // check if move is valid for a regular piece
    if (player == BLACK && dx == 1 && (dy == 1 || dy == -1))
    {
        return 1;
    }
    if (player == WHITE && dx == -1 && (dy == 1 || dy == -1))
    {
        return 1;
    }
    
    // check if move is valid for a king piece
    if (board[i][j] == 'b' || board[i][j] == 'w')
    {
        if (dx == 1 || dx == -1)
        {
            if (dy == 1 || dy == -1)
            {
                return 1;
            }
            if (dy == 2) // capture to the left
            {
                if ((j > y) && (board[i+1][j-1] == WHITE || board[i+1][j-1] == 'w'))
                {
                    return 1;
                }
            }
            if (dy == -2) // capture to the right
            {
                if ((j < y) && (board[i+1][j+1] == WHITE || board[i+1][j+1] == 'w'))
                {
                    return 1;
                }
            }
        }
        if (dx == 2 || dx == -2) // capture
        {
            if (dy == 2) // to the left
            {
                if ((j > y) && (board[i-1][j-1] == WHITE || board[i-1][j-1] == 'w'))
                {
                    return 1;
                }
            }
            if (dy == -2) // to the right
            {
                if ((j < y) && (board[i-1][j+1] == WHITE || board[i-1][j+1] == 'w'))
                {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}

/* Checks if a player has any valid moves */
int player_has_moves(int player, const char board[][SIZE])
{
    int i, j, x, y;
    
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == player || board[i][j] == 'b' || board[i][j] == 'w')
            {
                for (x = 0; x < SIZE; x++)
                {
                    for (y = 0; y < SIZE; y++)
                    {
                        if (valid_move(player, board, i, j, x, y))
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