//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 5

// Function declaration
void print_board(int board[ROWS][COLS]);
void generate_numbers(int board[ROWS][COLS]);
void player_turn(int board[ROWS][COLS], int *total_numbers_left, int *bingo);
void check_bingo(int board[ROWS][COLS], int *bingo);

int main()
{
    int board[ROWS][COLS] = {0}; // Initialize board with 0s
    int total_numbers_left = ROWS * COLS; // Total numbers remaining in the board
    int bingo = 0; // Flag for bingo
    srand(time(NULL)); // Seed the random number generator

    generate_numbers(board); // Generate random numbers for the board
    print_board(board); // Print initial board

    while (!bingo)
    {
        player_turn(board, &total_numbers_left, &bingo); // Player turn
        print_board(board); // Print updated board
    }

    printf("Congrats! You got a BINGO!\n");

    return 0;
}

// Function to print board
void print_board(int board[ROWS][COLS])
{
    int i, j;

    printf("--- BINGO BOARD ---\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == 0)
                printf("|    ");
            else
                printf("| %2d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-------------------\n");
}

// Function to generate random numbers for the board
void generate_numbers(int board[ROWS][COLS])
{
    int i, j;
    int nums[ROWS * COLS];

    // Initialize nums array with values from 1 to ROWS * COLS
    for (i = 0; i < ROWS * COLS; i++)
    {
        nums[i] = i + 1;
    }

    // Shuffle nums array using Fisher-Yates algorithm
    for (i = ROWS * COLS - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Copy shuffled nums array to board
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = nums[i * ROWS + j];
        }
    }
}

// Function for player turn
void player_turn(int board[ROWS][COLS], int *total_numbers_left, int *bingo)
{
    int i, j;
    int number;

    printf("Enter a number from 1 to %d: ", ROWS * COLS);
    scanf("%d", &number);

    // Search for number in the board
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == number)
            {
                board[i][j] = 0; // Mark number as found
                *total_numbers_left -= 1; // Decrease total numbers left
                check_bingo(board, bingo); // Check for bingo
                return;
            }
        }
    }

    printf("Number not found in board. Try again.\n");
    player_turn(board, total_numbers_left, bingo); // Recursive call to player_turn function
}

// Function to check for bingo
void check_bingo(int board[ROWS][COLS], int *bingo)
{
    int i, j;
    int row_sum, col_sum, diag_sum1, diag_sum2;

    // Check for row bingo
    for (i = 0; i < ROWS; i++)
    {
        row_sum = 0;
        for (j = 0; j < COLS; j++)
        {
            row_sum += board[i][j];
        }
        if (row_sum == 0)
        {
            *bingo = 1;
            return;
        }
    }

    // Check for column bingo
    for (j = 0; j < COLS; j++)
    {
        col_sum = 0;
        for (i = 0; i < ROWS; i++)
        {
            col_sum += board[i][j];
        }
        if (col_sum == 0)
        {
            *bingo = 1;
            return;
        }
    }

    // Check for diagonal bingo 1
    diag_sum1 = 0;
    for (i = 0; i < ROWS; i++)
    {
        diag_sum1 += board[i][i];
    }
    if (diag_sum1 == 0)
    {
        *bingo = 1;
        return;
    }

    // Check for diagonal bingo 2
    diag_sum2 = 0;
    for (i = 0; i < ROWS; i++)
    {
        diag_sum2 += board[i][ROWS - 1 - i];
    }
    if (diag_sum2 == 0)
    {
        *bingo = 1;
        return;
    }
}