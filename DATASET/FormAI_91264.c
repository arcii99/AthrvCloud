//FormAI DATASET v1.0 Category: Checkers Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Defining Board size
#define SIZE 8

// Defining Player Constants
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'

// Defining Game Status Constants
#define IN_PROGRESS 0
#define PLAYER_ONE_WON 1
#define PLAYER_TWO_WON 2
#define DRAW 3

// Defining Piece Constants
#define PIECE_ONE 'b'
#define PIECE_TWO 'B'
#define PIECE_THREE 'w'
#define PIECE_FOUR 'W'

// Defining Function Prototypes
void initialize_board(char board[SIZE][SIZE]);
void print_board(char board[SIZE][SIZE]);
void player_move(char player, char board[SIZE][SIZE]);
int check_move(char player, char board[SIZE][SIZE], int from_x, int from_y, int to_x, int to_y);
int check_jump(char player, char board[SIZE][SIZE], int from_x, int from_y, int to_x, int to_y, int jumped_x, int jumped_y);
int check_win(char board[SIZE][SIZE]);

// Main Function
int main()
{
    char board[SIZE][SIZE]; // Declaring the game board

    initialize_board(board); // Initializing the game board

    printf("Welcome to Checkers in C!\n\n");

    print_board(board); // Outputting the board

    while (check_win(board) == IN_PROGRESS) // Loop until game is finished
    {
        player_move(PLAYER_ONE, board); // Player One moves
        print_board(board);
        if (check_win(board) != IN_PROGRESS)
        {
            break;
        }
        player_move(PLAYER_TWO, board); // Player Two moves
        print_board(board);
    }

    int status = check_win(board); // Get game status

    if (status == PLAYER_ONE_WON)
    {
        printf("Player One has won!\n");
    }
    else if (status == PLAYER_TWO_WON)
    {
        printf("Player Two has won!\n");
    }
    else if (status == DRAW)
    {
        printf("The game is a draw.\n");
    }

    return 0;
}

// Function Definitions

// Function to initialize the board
void initialize_board(char board[SIZE][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if ((i + j) % 2 == 0 && i < 3)
            {
                board[i][j] = PIECE_ONE;
            }
            else if ((i + j) % 2 == 0 && i > 4)
            {
                board[i][j] = PIECE_THREE;
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }
}

// Function to print the board
void print_board(char board[SIZE][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        printf("%d", i + 1);
        for (j = 0; j < SIZE; j++)
        {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }

    printf(" ");
    for (i = 0; i < SIZE; i++)
    {
        printf(" %c", 'a' + i);
    }
    printf("\n\n");
}

// Function for a player to make a move
void player_move(char player, char board[SIZE][SIZE])
{
    char piece;
    int from_x, from_y, to_x, to_y;

    while (1) // Loop until valid move is made
    {
        printf("Player %c's turn.\n", player);
        printf("Enter the coordinates of the piece you would like to move: ");
        scanf("%d %d", &from_y, &from_x);
        printf("Enter the coordinates of the space you would like to move to: ");
        scanf("%d %d", &to_y, &to_x);

        from_x--;
        from_y--;
        to_x--;
        to_y--;

        piece = board[from_x][from_y];

        if (piece == ' ')
        {
            printf("There is no piece at that location. Please try again.\n");
            continue;
        }
        else if (player == PLAYER_ONE && !(piece == PIECE_ONE || piece == PIECE_TWO))
        {
            printf("You can only move your own pieces. Please try again.\n");
            continue;
        }
        else if (player == PLAYER_TWO && !(piece == PIECE_THREE || piece == PIECE_FOUR))
        {
            printf("You can only move your own pieces. Please try again.\n");
            continue;
        }
        else if (check_move(player, board, from_x, from_y, to_x, to_y) == 0)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        else
        {
            board[to_x][to_y] = piece;
            board[from_x][from_y] = ' ';

            if (abs(from_x - to_x) == 2) // If piece made a jump
            {
                int jumped_x = (from_x + to_x) / 2;
                int jumped_y = (from_y + to_y) / 2;

                board[jumped_x][jumped_y] = ' ';
            }

            break;
        }
    }
}

// Function to check if a move is valid
int check_move(char player, char board[SIZE][SIZE], int from_x, int from_y, int to_x, int to_y)
{
    int direction, distance;

    if (player == PLAYER_ONE)
    {
        direction = -1;
    }
    else
    {
        direction = 1;
    }

    if (board[to_x][to_y] != ' ')
    {
        return 0;
    }

    distance = abs(from_x - to_x);

    if (distance != abs(from_y - to_y))
    {
        return 0;
    }

    if (distance == 1) // If only moving one space
    {
        if (!(board[from_x][from_y] == PIECE_ONE || board[from_x][from_y] == PIECE_TWO))
        {
            return 0;
        }

        if (to_x - from_x != direction) // If not moving in the correct direction
        {
            return 0;
        }
    }
    else if (distance == 2) // If jumping over a piece
    {
        int jumped_x = (from_x + to_x) / 2;
        int jumped_y = (from_y + to_y) / 2;

        if (!(board[from_x][from_y] == PIECE_TWO || board[from_x][from_y] == PIECE_ONE))
        {
            return 0;
        }

        if (to_x - from_x != 2 * direction) // If not jumping in the correct direction
        {
            return 0;
        }

        if (board[jumped_x][jumped_y] == ' ') // If no piece to jump over
        {
            return 0;
        }

        if (board[jumped_x][jumped_y] == PIECE_ONE || board[jumped_x][jumped_y] == PIECE_TWO || (player == PLAYER_ONE && (board[jumped_x][jumped_y] == PIECE_THREE || board[jumped_x][jumped_y] == PIECE_FOUR)) || (player == PLAYER_TWO && (board[jumped_x][jumped_y] == PIECE_ONE || board[jumped_x][jumped_y] == PIECE_TWO)))
        {
            return 0;
        }
    }
    else // If distance is not 1 or 2
    {
        return 0;
    }

    return 1;
}

// Function to check if a jump move is valid
int check_jump(char player, char board[SIZE][SIZE], int from_x, int from_y, int to_x, int to_y, int jumped_x, int jumped_y)
{
    if (board[to_x][to_y] != ' ')
    {
        return 0;
    }

    if (board[jumped_x][jumped_y] == ' ')
    {
        return 0;
    }

    if (player == PLAYER_ONE && (board[jumped_x][jumped_y] == PIECE_THREE || board[jumped_x][jumped_y] == PIECE_FOUR))
    {
        return 0;
    }

    if (player == PLAYER_TWO && (board[jumped_x][jumped_y] == PIECE_ONE || board[jumped_x][jumped_y] == PIECE_TWO))
    {
        return 0;
    }

    return 1;
}

// Function to check game win status
int check_win(char board[SIZE][SIZE])
{
    int i, j, piece_count_one = 0, piece_count_two = 0;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (board[i][j] == PIECE_ONE || board[i][j] == PIECE_TWO)
            {
                piece_count_one++;
            }
            else if (board[i][j] == PIECE_THREE || board[i][j] == PIECE_FOUR)
            {
                piece_count_two++;
            }
        }
    }

    if (piece_count_one == 0)
    {
        return PLAYER_TWO_WON;
    }
    else if (piece_count_two == 0)
    {
        return PLAYER_ONE_WON;
    }

    return IN_PROGRESS;
}