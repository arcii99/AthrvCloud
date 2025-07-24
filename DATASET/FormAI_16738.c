//FormAI DATASET v1.0 Category: Table Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7

void display_board(char board[][COLS]);
void player_move(char board[][COLS], int turn);
int check_win(char board[][COLS], char token);

int main()
{
    srand(time(NULL)); // seed for random number generator
    char board[ROWS][COLS] = {{'_','_','_','_','_','_','_'},
                              {'_','_','_','_','_','_','_'},
                              {'_','_','_','_','_','_','_'},
                              {'_','_','_','_','_','_','_'},
                              {'_','_','_','_','_','_','_'},
                              {'_','_','_','_','_','_','_'}};
    display_board(board);
    int turn = rand() % 2; // randomly choose starting player
    int winner = 0;
    while (!winner)
    {
        player_move(board, turn);
        display_board(board);
        winner = check_win(board, turn ? 'O' : 'X');
        turn = !turn; // switch players
    }
    printf("\nThe winner is Player %d!\n", winner);
    return 0;
}

// displays the current state of the board
void display_board(char board[][COLS])
{
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("|%c", board[i][j]);
        printf("|\n");
    }
    printf(" 1 2 3 4 5 6 7\n");
}

// prompts the player for a move and updates the board
void player_move(char board[][COLS], int turn)
{
    char token = turn ? 'O' : 'X'; // determine player token
    int col;
    do
    {
        printf("Player %d: Enter column (1-7) to place %c: ", turn+1, token);
        scanf("%d", &col);
    } while (col < 1 || col > 7);
    for (int i = ROWS-1; i >= 0; i--) // find first empty row in column
    {
        if (board[i][col-1] == '_')
        {
            board[i][col-1] = token;
            return;
        }
    }
    printf("Column is full. Try again.\n");
    player_move(board, turn); // repeat turn
}

// checks if the current player has won or if the board is full with a tie
int check_win(char board[][COLS], char token)
{
    // check rows for win
    for (int i = 0; i < ROWS; i++)
    {
        int count = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == token)
                count++;
            else
                count = 0;
            if (count == 4)
                return token == 'X' ? 1 : 2; // return player number who won
        }
    }
    // check columns for win
    for (int j = 0; j < COLS; j++)
    {
        int count = 0;
        for (int i = 0; i < ROWS; i++)
        {
            if (board[i][j] == token)
                count++;
            else
                count = 0;
            if (count == 4)
                return token == 'X' ? 1 : 2;
        }
    }
    // check diagonals for win
    for (int i = 0; i <= ROWS-4; i++)
    {
        for (int j = 0; j <= COLS-4; j++)
        {
            if (board[i][j] == token && board[i+1][j+1] == token &&
                board[i+2][j+2] == token && board[i+3][j+3] == token)
                return token == 'X' ? 1 : 2;
            if (board[i][j+3] == token && board[i+1][j+2] == token &&
                board[i+2][j+1] == token && board[i+3][j] == token)
                return token == 'X' ? 1 : 2;
        }
    }
    // check for tie (board is full)
    int count = 0;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (board[i][j] != '_')
                count++;
    if (count == ROWS*COLS)
        return 3; // tie
    return 0; // no winner yet
}