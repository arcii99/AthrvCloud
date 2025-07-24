//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_MOVES 50

// Initialize the game board with given size
void init_board(char board[][BOARD_SIZE])
{
    int i, j;
    for(i=0; i<BOARD_SIZE; i++)
    {
        for(j=0; j<BOARD_SIZE; j++)
        {
            board[i][j] = '-';
        }
    }
}

// Function to print the game board
void print_board(char board[][BOARD_SIZE])
{
    int i, j;
    printf("\n  ");
    for(i=0; i<BOARD_SIZE; i++)
    {
        printf("%d ", i+1);
    }
    printf("\n");
    for(i=0; i<BOARD_SIZE; i++)
    {
        printf("%c ", (char)(i+'A'));
        for(j=0; j<BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the move is valid
int is_valid_move(char board[][BOARD_SIZE], int x, int y)
{
    if(x>=0 && x<BOARD_SIZE && y>=0 && y<BOARD_SIZE && board[x][y]=='-')
    {
        return 1;
    }
    return 0;
}

// Function to get a random move for the computer player
void get_computer_move(char board[][BOARD_SIZE], int *x, int *y)
{
    do
    {
        *x = rand() % BOARD_SIZE;
        *y = rand() % BOARD_SIZE;
    } while(!is_valid_move(board, *x, *y));
}

// Function to get user move and update the board
void get_user_move(char board[][BOARD_SIZE], int *x, int *y)
{
    char x_char;
    printf("Enter your move (like B3): ");
    scanf(" %c%d", &x_char, y);
    *x = (int)(x_char - 'A');
    (*y)--;
    if(!is_valid_move(board, *x, *y))
    {
        printf("Invalid move. Try again.\n");
        get_user_move(board, x, y);
    }
    else
    {
        board[*x][*y] = 'X';
    }
}

// Function to play the table game
void play_game()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int moves_count = 0, x, y;
    char winner = '-';
    srand(time(0)); // to randomize the computer moves
    init_board(board);
    while(moves_count<MAX_MOVES && winner=='-')
    {
        printf("Move %d:\n", moves_count+1);
        print_board(board);
        get_user_move(board, &x, &y);
        winner = 'X'; // assume user as winner
        if(moves_count<(MAX_MOVES-1) && winner=='-')
        {
            get_computer_move(board, &x, &y);
            winner = 'O'; // assume computer as winner
        }
        moves_count++;
    }
    printf("Game over!\n");
    print_board(board);
    if(winner=='X')
    {
        printf("Congratulations! You won the game.\n");
    }
    else if(winner=='O')
    {
        printf("The computer won the game. Try again.\n");
    }
    else
    {
        printf("The game ended in a draw.\n");
    }
}

// Main function to run the game
int main()
{
    char play_again = 'y';
    printf("Welcome to the Table Game!\n");
    while(play_again=='y')
    {
        play_game();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    }
    printf("Thanks for playing the game. Goodbye!\n");
    return 0;
}