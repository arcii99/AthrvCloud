//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define PLAYER 1
#define COMPUTER 2
#define SIDE 3 // Size of the Tic Tac Toe board
#define EMPTY 0

// function to display Tic Tac Toe board
void display_board(int board[][SIDE])
{
    printf("\n");

    for (int i = 0; i < SIDE; i++) 
    {
        for (int j = 0; j < SIDE; j++) 
        {
            if (board[i][j] == EMPTY)
            {
                printf(" ");
            }
            else if (board[i][j] == PLAYER)
            {
                printf("X");
            }
            else
            {
                printf("O");
            }

            if (j != SIDE - 1)
                printf(" | ");
        }

        printf("\n");

        if (i != SIDE - 1)
        {
            printf("---|---|---\n");
        }
    }
}

// function to check if any player has won
int check_win(int board[][SIDE], int player)
{
    // check rows for a win
    for (int i = 0; i < SIDE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }

    // check columns for a win
    for (int i = 0; i < SIDE; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }

    // check diagonals for a win
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    // if no win found
    return 0;
}

// function to check if the game ended in a tie
int check_tie(int board[][SIDE])
{
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                return 0;
            }
        }
    }

    return 1;
}

// recursive function to find the best move for the computer
int find_best_move(int board[][SIDE], int depth, int is_max)
{
    int score = 0;
    int best_score = is_max ? -1000 : 1000;

    // check for terminal state
    if (check_win(board, PLAYER))
    {
        return -10 + depth;
    }
    else if (check_win(board, COMPUTER))
    {
        return 10 - depth;
    }
    else if (check_tie(board))
    {
        return 0;
    }

    // loop through all possible moves
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                // make the move
                if (is_max)
                {
                    board[i][j] = COMPUTER;
                    score = find_best_move(board, depth + 1, 0);
                }
                else
                {
                    board[i][j] = PLAYER;
                    score = find_best_move(board, depth + 1, 1);
                }

                // undo the move
                board[i][j] = EMPTY;

                // update the best score
                if (is_max)
                {
                    if (score > best_score)
                    {
                        best_score = score;
                    }
                }
                else
                {
                    if (score < best_score)
                    {
                        best_score = score;
                    }
                }
            }
        }
    }

    return best_score;
}

// function to make the next move for the computer
void make_move(int board[][SIDE])
{
    int best_score = -1000; // initialize as low as possible
    int row = -1;
    int col = -1;

    // loop through all possible moves
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                // make the move
                board[i][j] = COMPUTER;

                // find the score for that move
                int score = find_best_move(board, 0, 0);

                // undo the move
                board[i][j] = EMPTY;

                // update the best score and move
                if (score > best_score)
                {
                    best_score = score;
                    row = i;
                    col = j;
                }
            }
        }
    }

    // make the best move
    board[row][col] = COMPUTER;
}

// function for player's move
void player_move(int board[][SIDE])
{
    int row;
    int col;

    printf("Enter the row and column number (1-3): ");
    scanf("%d %d", &row, &col);

    while (board[row - 1][col - 1] != EMPTY)
    {
        printf("Invalid move. Enter the row and column number (1-3): ");
        scanf("%d %d", &row, &col);
    }

    board[row - 1][col - 1] = PLAYER;
}

// function to play the game
void play_game()
{
    int board[SIDE][SIDE] = {{EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}};
    int current_player = PLAYER;
    int winner = 0;

    while (!winner)
    {
        display_board(board);

        if (current_player == PLAYER)
        {
            player_move(board);
        }
        else
        {
            make_move(board);
        }

        if (check_win(board, current_player))
        {
            winner = current_player;
        }
        else if (check_tie(board))
        {
            winner = -1; // tie
        }

        current_player = current_player == PLAYER ? COMPUTER : PLAYER;
    }

    display_board(board);

    if (winner == PLAYER)
    {
        printf("You win!\n");
    }
    else if (winner == COMPUTER)
    {
        printf("Computer wins!\n");
    }
    else
    {
        printf("Tie game!\n");
    }
}

// main function to run the game
int main()
{
    char play_again = 'y';

    printf("Welcome to Tic Tac Toe!\n");

    while (play_again == 'y')
    {
        play_game();

        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &play_again);
    }

    printf("Thanks for playing!\n");

    return 0;
}