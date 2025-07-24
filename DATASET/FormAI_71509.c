//FormAI DATASET v1.0 Category: Checkers Game ; Style: realistic
#include <stdio.h>

// Define board size
#define BOARD_SIZE 8

// Define pieces
#define EMPTY 0
#define RED 1
#define BLACK 2

// Initialize the board
int board[BOARD_SIZE][BOARD_SIZE] =
    {
        {0, 2, 0, 2, 0, 2, 0, 2},
        {2, 0, 2, 0, 2, 0, 2, 0},
        {0, 2, 0, 2, 0, 2, 0, 2},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {3, 0, 3, 0, 3, 0, 3, 0},
        {0, 3, 0, 3, 0, 3, 0, 3},
        {3, 0, 3, 0, 3, 0, 3, 0}
    };

// Print the board
void print_board(int board[][BOARD_SIZE])
{
    printf("    0 1 2 3 4 5 6 7 \n");
    printf("   -----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d | ", i);
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            switch(board[i][j])
            {
                case EMPTY:
                    printf("  ");
                    break;
                case RED:
                    printf(" R");
                    break;
                case BLACK:
                    printf(" B");
                    break;
                case 3:
                    printf(" *");
                    break;
            }
        }
        printf(" |\n");
    }
    printf("   -----------------\n");
}

// Check if move is valid
int is_valid_move(int board[][BOARD_SIZE], int x, int y, int new_x, int new_y, int player)
{
    // Check if valid move
    if (new_x < 0 || new_x > 7 || new_y < 0 || new_y > 7)
        return 0;
    if (board[new_x][new_y] != 0)
        return 0;
    if (player == RED && board[x][y] == 1 && new_x > x)
        return 0;
    if (player == BLACK && board[x][y] == 2 && new_x < x)
        return 0;
    if (abs(new_x - x) == 1 && abs(new_y - y) == 1)
        return 1;
    if (abs(new_x - x) == 2 && abs(new_y - y) == 2 &&
        ((board[(new_x+x)/2][(new_y+y)/2] == RED && player == BLACK) ||
         (board[(new_x+x)/2][(new_y+y)/2] == BLACK && player == RED)))
        return 1;
    return 0;
}

// Check if jump move is possible
int is_jump_possible(int board[][BOARD_SIZE], int x, int y, int player)
{
    if ((player == RED && board[x][y] != RED) || (player == BLACK && board[x][y] != BLACK))
        return 0;
    if (player == RED)
    {
        if (((x+2 < BOARD_SIZE && y+2 < BOARD_SIZE) && is_valid_move(board, x, y, x+2, y+2, player)) ||
            ((x+2 < BOARD_SIZE && y-2 >= 0) && is_valid_move(board, x, y, x+2, y-2, player)))
            return 1;
    }
    else if (player == BLACK)
    {
        if (((x-2 >= 0 && y+2 < BOARD_SIZE) && is_valid_move(board, x, y, x-2, y+2, player)) ||
            ((x-2 >= 0 && y-2 >= 0) && is_valid_move(board, x, y, x-2, y-2, player)))
            return 1;
    }
    return 0;
}

// Make the move
void make_move(int board[][BOARD_SIZE], int x, int y, int new_x, int new_y, int player)
{
    board[new_x][new_y] = board[x][y];
    board[x][y] = EMPTY;
    if (abs(new_x - x) == 2 && abs(new_y - y) == 2)
        board[(new_x+x)/2][(new_y+y)/2] = EMPTY;

    // Make a piece king
    if (new_x == 0 && board[new_x][new_y] == RED)
        board[new_x][new_y] = 3;
    else if (new_x == 7 && board[new_x][new_y] == BLACK)
        board[new_x][new_y] = 3;
}

// Check if the game is over
int is_game_over(int board[][BOARD_SIZE])
{
    int black_pieces = 0, red_pieces = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == BLACK || board[i][j] == 3)
                black_pieces++;
            if (board[i][j] == RED || board[i][j] == 3)
                red_pieces++;
        }
    }
    if (black_pieces == 0 || red_pieces == 0)
        return 1;
    return 0;
}

// Check which player won the game
int player_won(int board[][BOARD_SIZE])
{
    int black_pieces = 0, red_pieces = 0;
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == BLACK || board[i][j] == 3)
                black_pieces++;
            if (board[i][j] == RED || board[i][j] == 3)
                red_pieces++;
        }
    }
    if (black_pieces > red_pieces)
        return BLACK;
    else
        return RED;
}

int main()
{
    int player = BLACK;
    int x, y, new_x, new_y;

    // Play the game
    while (!is_game_over(board))
    {
        print_board(board);
        printf("\nPlayer %d's turn: \n", player);

        // Check the move
        do {
            printf("Enter the x and y coordinates of the piece you want to move: ");
            scanf("%d %d", &x, &y);
        } while (!is_jump_possible(board, x, y, player));

        // Make the move
        do {
            printf("Enter the new x and y coordinates to move to: ");
            scanf("%d %d", &new_x, &new_y);
        } while (!is_valid_move(board, x, y, new_x, new_y, player));
        make_move(board, x, y, new_x, new_y, player);

        // Change player
        if (player == BLACK)
            player = RED;
        else
            player = BLACK;
    }

    // Display the winner
    print_board(board);
    printf("\nPlayer %d wins!\n", player_won(board));

    return 0;
}