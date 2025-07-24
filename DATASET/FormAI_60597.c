//FormAI DATASET v1.0 Category: Checkers Game ; Style: random
#include <stdio.h>

// defining the board size
#define BOARD_SIZE 8

// function to initialize the board with empty spaces
void init_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// function to print the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    printf("    ");
    for(i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d  ", i+1);
    }
    printf("\n");

    printf("  ");
    for(i = 0; i < BOARD_SIZE; i++)
    {
        printf("____");
    }
    printf("_\n");

    for(i = 0; i < BOARD_SIZE; i++)
    {
        printf("%d|", i+1);
        for(j = 0; j < BOARD_SIZE; j++)
        {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("  ");
        for(j = 0; j < BOARD_SIZE; j++)
        {
            printf("____");
        }
        printf("_\n");
    }
}

// function to check if the given position is within the board boundaries
int is_valid_position(int x, int y)
{
    if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE)
    {
        return 0;
    }
    return 1;
}

// function to check if the move is legal
int is_legal_move(char board[BOARD_SIZE][BOARD_SIZE], int curr_x, int curr_y, int new_x, int new_y, char player)
{
    // check if the destination is within the board boundaries
    if(!is_valid_position(new_x, new_y))
    {
        return 0;
    }

    // check if the destination is empty
    if(board[new_x][new_y] != ' ')
    {
        return 0;
    }

    // check if the move is a jump move
    if(abs(new_x - curr_x) == 2 && abs(new_y - curr_y) == 2)
    {
        int mid_x = (new_x + curr_x) / 2;
        int mid_y = (new_y + curr_y) / 2;
        if(board[mid_x][mid_y] == ' ' || board[mid_x][mid_y] == player)
        {
            return 0;
        }
        return 1;
    }

    // check if the move is a regular move
    if(abs(new_x - curr_x) == 1 && abs(new_y - curr_y) == 1)
    {
        return 1;
    }

    return 0;
}

// function to scan the user input as x and y coordinates
void scan_coords(char * msg, int * x, int * y)
{
    printf("%s", msg);
    scanf("%d %d", x, y);
}

// function to get the valid move from player
int get_valid_move(char board[BOARD_SIZE][BOARD_SIZE], char player, int * curr_x, int * curr_y, int * new_x, int * new_y)
{
    while(1)
    {
        // get the current position from user
        scan_coords("Enter your current position (x y): ", curr_x, curr_y);

        // check if the current position belongs to the player
        if(board[*curr_x-1][*curr_y-1] != player && board[*curr_x-1][*curr_y-1] != toupper(player))
        {
            printf("Invalid position! Please try again.\n");
            continue;
        }

        // get the new position from user
        scan_coords("Enter your new position (x y): ", new_x, new_y);

        // check if the move is valid
        if(is_legal_move(board, *curr_x-1, *curr_y-1, *new_x-1, *new_y-1, player))
        {
            return 1;
        }
        printf("Invalid move! Please try again.\n");
    }
}

// function to move the piece
void move_piece(char board[BOARD_SIZE][BOARD_SIZE], int curr_x, int curr_y, int new_x, int new_y, char player)
{
    // move the piece
    board[new_x][new_y] = tolower(player);
    board[curr_x][curr_y] = ' ';
    printf("%c moved from (%d %d) to (%d %d)\n", player, curr_x+1, curr_y+1, new_x+1, new_y+1);

    // check if the piece became a king
    if(new_x == 0 || new_x == BOARD_SIZE-1)
    {
        board[new_x][new_y] = toupper(board[new_x][new_y]);
        printf("%c became a king!\n", board[new_x][new_y]);
    }

    // check if the piece jumped over another piece
    if(abs(new_x - curr_x) == 2)
    {
        int mid_x = (new_x + curr_x) / 2;
        int mid_y = (new_y + curr_y) / 2;
        board[mid_x][mid_y] = ' ';
        printf("%c jumped over %c at (%d %d)\n", player, board[mid_x][mid_y], mid_x+1, mid_y+1);
    }
}

// function to check if the game is over
int is_game_over(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j, white_count = 0, black_count = 0;
    for(i = 0; i < BOARD_SIZE; i++)
    {
        for(j = 0; j < BOARD_SIZE; j++)
        {
            if(board[i][j] == 'w' || board[i][j] == 'W')
            {
                white_count++;
            }
            else if(board[i][j] == 'b' || board[i][j] == 'B')
            {
                black_count++;
            }
        }
    }
    if(white_count == 0 || black_count == 0)
    {
        return 1;
    }
    return 0;
}

// main function
int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int curr_x, curr_y, new_x, new_y;
    char player = 'b';

    // initialize the board
    init_board(board);

    // place the initial pieces
    for(int i = 0; i < BOARD_SIZE; i+=2)
    {
        board[0][i+1] = 'w';
        board[1][i] = 'w';
        board[6][i+1] = 'b';
        board[7][i] = 'b';
    }

    // print the initial board
    print_board(board);

    // main game loop
    while(!is_game_over(board))
    {
        printf("%c's turn:\n", player);

        // get the valid move
        get_valid_move(board, player, &curr_x, &curr_y, &new_x, &new_y);

        // move the piece
        move_piece(board, curr_x-1, curr_y-1, new_x-1, new_y-1, player);

        // switch player
        player = (player == 'b') ? 'w' : 'b';

        // print the board
        print_board(board);
    }

    // print the winner
    if(is_game_over(board))
    {
        int i, j, white_count = 0, black_count = 0;
        for(i = 0; i < BOARD_SIZE; i++)
        {
            for(j = 0; j < BOARD_SIZE; j++)
            {
                if(board[i][j] == 'w' || board[i][j] == 'W')
                {
                    white_count++;
                }
                else if(board[i][j] == 'b' || board[i][j] == 'B')
                {
                    black_count++;
                }
            }
        }
        if(white_count > black_count)
        {
            printf("White wins!\n");
        }
        else if(black_count > white_count)
        {
            printf("Black wins!\n");
        }
        else
        {
            printf("It's a tie!\n");
        }
    }

    return 0;
}