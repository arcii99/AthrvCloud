//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void print_board(int board[], int size);
int roll_dice();
int move_token(int board[], int player, int dice_roll, int size);

int main()
{
    // Set random seed for dice rolls
    srand(time(0));

    // Initialize the board
    int board[100] = {0};
    board[0] = 1;
    board[99] = 2;

    // Initialize the players
    int player1 = 0;
    int player2 = 0;

    // Game loop
    while (player1 < 99 && player2 < 99)
    {
        // Player 1 turn
        printf("Player 1: ");
        int dice_roll = roll_dice();
        printf("rolled a %d\n", dice_roll);
        player1 = move_token(board, 1, dice_roll, 100);
        print_board(board, 100);
        if (player1 == 99)
        {
            printf("Player 1 wins!\n");
            break;
        }

        // Player 2 turn
        printf("Player 2: ");
        dice_roll = roll_dice();
        printf("rolled a %d\n", dice_roll);
        player2 = move_token(board, 2, dice_roll, 100);
        print_board(board, 100);
        if (player2 == 99)
        {
            printf("Player 2 wins!\n");
            break;
        }
    }

    return 0;
}

// Function to print the current state of the board
void print_board(int board[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        if (board[i] == 1)
        {
            printf("P1");
        }
        else if (board[i] == 2)
        {
            printf("P2");
        }
        else
        {
            printf("__");
        }

        if (i % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

// Function to roll the dice
int roll_dice()
{
    return rand() % 6 + 1;
}

// Function to move the player's token
int move_token(int board[], int player, int dice_roll, int size)
{
    int current_pos;
    if (player == 1)
    {
        current_pos = board[0];
    }
    else
    {
        current_pos = board[size - 1];
    }

    if (current_pos + dice_roll >= size)
    {
        return size - 1;
    }
    else
    {
        int new_pos = current_pos + dice_roll;
        if (board[new_pos] != 0)
        {
            if (board[new_pos] == player)
            {
                return move_token(board, player, dice_roll, size);
            }
            else
            {
                board[new_pos] = player;
                return new_pos;
            }
        }
        else
        {
            board[new_pos] = player;
            board[current_pos] = 0;
            return new_pos;
        }
    }
}