//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3    // Tic Tac Toe board size 
#define PLAYER     'X'  // Player symbol
#define COMPUTER   'O'  // Computer symbol
#define EMPTY      '-'  // Empty cell symbol

// Function prototypes
void display_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_winner(char board[BOARD_SIZE][BOARD_SIZE]);
int min_max_algorithm(char board[BOARD_SIZE][BOARD_SIZE], int depth, int is_maximizing);
int get_best_move(char board[BOARD_SIZE][BOARD_SIZE]);
int make_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char symbol);

// The main function
int main(void)
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY },
        { EMPTY, EMPTY, EMPTY }
    };

    int winner = 0;
    int row, col, move_count = 0;

    display_board(board);

    while (winner == 0)
    {
        printf("Your turn: ");

        // Get player move
        scanf("%d %d", &row, &col);

        if (make_move(board, row, col, PLAYER) == 1)
        {
            move_count++;
            winner = check_winner(board);

            if (winner != 0 || move_count == 9)
                break;

            // Get computer move
            int best_move = get_best_move(board);
            row = best_move / BOARD_SIZE;
            col = best_move % BOARD_SIZE;

            make_move(board, row, col, COMPUTER);
            move_count++;
            winner = check_winner(board);
        }
        else
            printf("Invalid move\n");

        display_board(board);
    }

    if (winner == PLAYER)
        printf("Congratulations, you won!\n");
    else if (winner == COMPUTER)
        printf("Sorry, you lost!\n");
    else
        printf("It's a tie!\n");

    return 0;
}

// Displays the Tic Tac Toe board
void display_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);

        if (i != BOARD_SIZE - 1)
            printf("---|---|---\n");
    }

    printf("\n");
}

// Checks if someone has won the game
int check_winner(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];
    }

    // Check columns
    for (j = 0; j < BOARD_SIZE; j++)
    {
        if (board[0][j] != EMPTY && board[0][j] == board[1][j] && board[0][j] == board[2][j])
            return board[0][j];
    }

    // Check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0];

    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[0][2];

    return 0;   // No winner yet
}

// Implements the min-max algorithm
int min_max_algorithm(char board[BOARD_SIZE][BOARD_SIZE], int depth, int is_maximizing)
{
    int winner = check_winner(board);

    if (winner != 0 || depth == 0)
    {
        if (winner == COMPUTER)
            return 1;
        else if (winner == PLAYER)
            return -1;
        else
            return 0;
    }

    int score, best_score;

    if (is_maximizing)
    {
        best_score = -1000;

        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = COMPUTER;
                    score = min_max_algorithm(board, depth - 1, 0);
                    board[i][j] = EMPTY;

                    if (score > best_score)
                        best_score = score;
                }
            }
        }

        return best_score;
    }
    else
    {
        best_score = 1000;

        for (int i = 0; i < BOARD_SIZE; i++)
        {
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = PLAYER;
                    score = min_max_algorithm(board, depth - 1, 1);
                    board[i][j] = EMPTY;

                    if (score < best_score)
                        best_score = score;
                }
            }
        }

        return best_score;
    }
}

// Finds the best move for the computer using the min-max algorithm
int get_best_move(char board[BOARD_SIZE][BOARD_SIZE])
{
    srand(time(NULL));

    int row, col, best_score = -1000, score;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == EMPTY)
            {
                board[i][j] = COMPUTER;
                score = min_max_algorithm(board, 4, 0);   // Search depth of 4
                board[i][j] = EMPTY;

                if (score > best_score)
                {
                    best_score = score;
                    row = i;
                    col = j;
                }
                else if (score == best_score)
                {
                    // Choose randomly among equally good moves
                    int coin_toss = rand() % 2;

                    if (coin_toss == 0)
                    {
                        row = i;
                        col = j;
                    }
                }
            }
        }
    }

    return (row * BOARD_SIZE + col);
}

// Makes a move on the board and returns 1 if successful, 0 if invalid move
int make_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char symbol)
{
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE &&
        board[row][col] == EMPTY)
    {
        board[row][col] = symbol;
        return 1;
    }
    else
        return 0;
}