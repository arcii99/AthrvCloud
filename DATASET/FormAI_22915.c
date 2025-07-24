//FormAI DATASET v1.0 Category: Checkers Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

//function prototypes for game logic functions
bool is_valid_move(int, int, int, int, char [][BOARD_SIZE], char);
bool is_valid_capture(int, int, int, int, char [][BOARD_SIZE], char);
bool is_game_over(char [][BOARD_SIZE], char);
void play_game(char [][BOARD_SIZE], char, char);

//function to print the game board
void print_board(char board[][BOARD_SIZE])
{
    printf("\n    0  1  2  3  4  5  6  7\n");
    printf("  -----------------------\n");
    for(int i=0; i<BOARD_SIZE; i++)
    {
        printf("%d | ", i);
        for(int j=0; j<BOARD_SIZE; j++)
        {
            printf("%c  ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  -----------------------\n");
}

//function to initialize the game board
void init_board(char board[][BOARD_SIZE])
{
    for(int i=0; i<BOARD_SIZE; i++)
    {
        for(int j=0; j<BOARD_SIZE; j++)
        {
            if(i%2 == j%2)
            {
                if(i < 3)
                {
                    board[i][j] = 'r';
                }
                else if(i > 4)
                {
                    board[i][j] = 'b';
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    char player1 = 'r';
    char player2 = 'b';

    init_board(board);

    printf("Welcome to Checkers Game!\n");
    printf("Player 1 (red pieces): r\n");
    printf("Player 2 (black pieces): b\n");
    printf("Game board initialized.\n");

    print_board(board);

    play_game(board, player1, player2);

    return 0;
}

//function to check if a move is valid
bool is_valid_move(int row1, int col1, int row2, int col2, char board[][BOARD_SIZE], char player)
{
    if(board[row2][col2] != ' ')
    {
        return false;
    }

    if(player == 'r')
    {
        if(row2 > row1)
        {
            return false;
        }

        if(row2 == row1-1 && col2 == col1+1 && board[row1][col1] == 'r' && board[row2][col2] == ' ')
        {
            return true;
        }

        if(row2 == row1-1 && col2 == col1-1 && board[row1][col1] == 'r' && board[row2][col2] == ' ')
        {
            return true;
        }

        if(row2 == row1-2 && col2 == col1+2 && board[row1-1][col1+1] == 'b' && board[row2][col2] == ' ')
        {
            return true;
        }

        if(row2 == row1-2 && col2 == col1-2 && board[row1-1][col1-1] == 'b' && board[row2][col2] == ' ')
        {
            return true;
        }
    }
    else if(player == 'b')
    {
        if(row2 < row1)
        {
            return false;
        }

        if(row2 == row1+1 && col2 == col1+1 && board[row1][col1] == 'b' && board[row2][col2] == ' ')
        {
            return true;
        }

        if(row2 == row1+1 && col2 == col1-1 && board[row1][col1] == 'b' && board[row2][col2] == ' ')
        {
            return true;
        }

        if(row2 == row1+2 && col2 == col1+2 && board[row1+1][col1+1] == 'r' && board[row2][col2] == ' ')
        {
            return true;
        }

        if(row2 == row1+2 && col2 == col1-2 && board[row1+1][col1-1] == 'r' && board[row2][col2] == ' ')
        {
            return true;
        }
    }

    return false;
}

//function to check if a capture is valid
bool is_valid_capture(int row1, int col1, int row2, int col2, char board[][BOARD_SIZE], char player)
{
    if(board[row2][col2] != ' ')
    {
        return false;
    }

    if(player == 'r')
    {
        if(row2 > row1)
        {
            return false;
        }

        if(row2 == row1-2 && col2 == col1+2 && board[row1-1][col1+1] == 'b' && board[row2][col2] == ' ')
        {
            return true;
        }

        if(row2 == row1-2 && col2 == col1-2 && board[row1-1][col1-1] == 'b' && board[row2][col2] == ' ')
        {
            return true;
        }
    }
    else if(player == 'b')
    {
        if(row2 < row1)
        {
            return false;
        }

        if(row2 == row1+2 && col2 == col1+2 && board[row1+1][col1+1] == 'r' && board[row2][col2] == ' ')
        {
            return true;
        }

        if(row2 == row1+2 && col2 == col1-2 && board[row1+1][col1-1] == 'r' && board[row2][col2] == ' ')
        {
            return true;
        }
    }

    return false;
}

//function to check if the game is over
bool is_game_over(char board[][BOARD_SIZE], char player)
{
    int pieces_count = 0;
    for(int i=0; i<BOARD_SIZE; i++)
    {
        for(int j=0; j<BOARD_SIZE; j++)
        {
            if(board[i][j] == player)
            {
                pieces_count++;
            }
        }
    }

    if(pieces_count == 0)
    {
        return true;
    }

    return false;
}

//function for gameplay
void play_game(char board[][BOARD_SIZE], char player1, char player2)
{
    int turn = 1;
    int row1, col1, row2, col2;

    while(true)
    {
        char player = (turn % 2 == 1) ? player1 : player2;

        printf("\nPlayer %d (%c) turn.\n", (turn % 2 == 1) ? 1 : 2, player);
        printf("Enter source row and col: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter destination row and col: ");
        scanf("%d %d", &row2, &col2);

        if(is_valid_move(row1, col1, row2, col2, board, player))
        {
            //make the move
            board[row2][col2] = board[row1][col1];
            board[row1][col1] = ' ';

            //check for king
            if(player == 'r' && row2 == 0)
            {
                board[row2][col2] = 'R';
            }
            else if(player == 'b' && row2 == BOARD_SIZE-1)
            {
                board[row2][col2] = 'B';
            }
        }
        else if(is_valid_capture(row1, col1, row2, col2, board, player))
        {
            //make the capture
            board[row2][col2] = board[row1][col1];
            board[row1][col1] = ' ';
            board[(row1+row2)/2][(col1+col2)/2] = ' ';

            //check for king
            if(player == 'r' && row2 == 0)
            {
                board[row2][col2] = 'R';
            }
            else if(player == 'b' && row2 == BOARD_SIZE-1)
            {
                board[row2][col2] = 'B';
            }
        }
        else
        {
            printf("Invalid move/capture. Try again.\n");
            continue;
        }

        print_board(board);

        if(is_game_over(board, player1))
        {
            printf("Player 2 (black pieces) wins!\n");
            break;
        }

        if(is_game_over(board, player2))
        {
            printf("Player 1 (red pieces) wins!\n");
            break;
        }

        turn++;
    }
}