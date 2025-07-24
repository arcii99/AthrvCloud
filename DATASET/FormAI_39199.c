//FormAI DATASET v1.0 Category: Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 3

void print_board(char board[][BOARD_SIZE])
{
    printf("\n");

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            printf(" %c ", board[row][col]);

            if (col < BOARD_SIZE - 1)
            {
                printf("|");
            }
        }

        printf("\n");

        if (row < BOARD_SIZE - 1)
        {
            printf("---+---+---\n");
        }
    }

    printf("\n");
}

bool is_game_over(char board[][BOARD_SIZE])
{
    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        if (board[row][0] == board[row][1] && 
            board[row][1] == board[row][2] && 
            board[row][0] != ' ')
        {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < BOARD_SIZE; col++)
    {
        if (board[0][col] == board[1][col] && 
            board[1][col] == board[2][col] && 
            board[0][col] != ' ')
        {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && 
         board[1][1] == board[2][2] && 
         board[0][0] != ' ') || 
        (board[2][0] == board[1][1] && 
         board[1][1] == board[0][2] && 
         board[2][0] != ' '))
    {
        return true;
    }

    // Check for tie
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == ' ')
            {
                return false;
            }
        }
    }

    return true;
}

void get_computer_move(char board[][BOARD_SIZE], int *row, int *col)
{
    // Generate random move until an empty cell is found
    do
    {
        *row = rand() % BOARD_SIZE;
        *col = rand() % BOARD_SIZE;
    } while (board[*row][*col] != ' ');
}

void play_game()
{
    // Initialize the board
    char board[BOARD_SIZE][BOARD_SIZE];

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            board[row][col] = ' ';
        }
    }

    // Initialize the turn and game over variables
    int turn = 0;
    bool game_over = false;

    // Play the game until it's over
    while (!game_over)
    {
        // Print the board
        print_board(board);

        // Player's turn
        if (turn % 2 == 0)
        {
            // Get player's move
            int row, col;

            printf("Enter row (1-3): ");
            scanf("%d", &row);
            row--;

            printf("Enter col (1-3): ");
            scanf("%d", &col);
            col--;

            // Update the board
            if (board[row][col] == ' ')
            {
                board[row][col] = 'X';
                turn++;
            }
            else
            {
                printf("Cell already occupied. Please choose another one.\n");
            }
        }
        // Computer's turn
        else
        {
            // Get computer's move
            int row, col;
            get_computer_move(board, &row, &col);

            // Update the board
            board[row][col] = 'O';
            turn++;
        }

        // Check if game is over
        game_over = is_game_over(board);
    }

    // Print the final board
    print_board(board);

    // Print the winner
    if (turn % 2 == 0)
    {
        printf("Computer wins!\n");
    }
    else
    {
        printf("You win!\n");
    }
}

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Play multiple games until the user quits
    char choice;

    do
    {
        play_game();

        printf("Play again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}