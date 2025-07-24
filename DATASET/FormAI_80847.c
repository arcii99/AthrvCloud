//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 5
#define COL_SIZE 5

void print_board(int board[ROW_SIZE][COL_SIZE]);
void generate_numbers(int* nums, int size);
int check_bingo(int board[ROW_SIZE][COL_SIZE]);

int main()
{
    int board[ROW_SIZE][COL_SIZE] = {0};
    int nums[ROW_SIZE * COL_SIZE] = {0};

    // Generate numbers to fill the board
    generate_numbers(nums, ROW_SIZE * COL_SIZE);

    // Fill the board with the generated numbers
    for (int row = 0; row < ROW_SIZE; row++)
    {
        for (int col = 0; col < COL_SIZE; col++)
        {
            int random_index = rand() % (ROW_SIZE * COL_SIZE); // Generate a random index to select a number from the generated array
            board[row][col] = nums[random_index];
            nums[random_index] = nums[ROW_SIZE * COL_SIZE - 1]; // Replace the selected number with the last number in the array
            nums[ROW_SIZE * COL_SIZE - 1] = 0; // Set the last number to 0 to avoid repetition
        }
    }

    printf("Starting Bingo Simulator...\n\n");
    print_board(board);

    // Play until there is a Bingo
    int is_bingo = 0;
    while (!is_bingo)
    {
        int picked_number;
        printf("Enter the picked number between 1 and 25: ");
        scanf("%d", &picked_number);

        // Check if the picked number exists in the board and replace it with 0 if found
        int is_found = 0;
        for (int row = 0; row < ROW_SIZE; row++)
        {
            for (int col = 0; col < COL_SIZE; col++)
            {
                if (board[row][col] == picked_number)
                {
                    board[row][col] = 0;
                    is_found = 1;
                    break;
                }
            }
            if (is_found) break;
        }

        // Print the updated board
        printf("\n");
        print_board(board);

        // Check if there is a Bingo
        is_bingo = check_bingo(board);
        if (is_bingo) printf("Bingo!\n");
    }

    return 0;
}

void print_board(int board[ROW_SIZE][COL_SIZE])
{
    printf("B  I  N  G  O\n");

    for (int row = 0; row < ROW_SIZE; row++)
    {
        for (int col = 0; col < COL_SIZE; col++)
        {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void generate_numbers(int* nums, int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        nums[i] = rand() % ROW_SIZE * COL_SIZE + 1; // Generate a random number between 1 and 25
    }
}

int check_bingo(int board[ROW_SIZE][COL_SIZE])
{
    int is_bingo = 0;

    // Check rows
    for (int row = 0; row < ROW_SIZE; row++)
    {
        is_bingo = 1;
        for (int col = 0; col < COL_SIZE; col++)
        {
            if (board[row][col] != 0)
            {
                is_bingo = 0;
                break;
            }
        }
        if (is_bingo) return 1;
    }

    // Check columns
    for (int col = 0; col < COL_SIZE; col++)
    {
        is_bingo = 1;
        for (int row = 0; row < ROW_SIZE; row++)
        {
            if (board[row][col] != 0)
            {
                is_bingo = 0;
                break;
            }
        }
        if (is_bingo) return 1;
    }

    // Check diagonal
    is_bingo = 1;
    for (int i = 0; i < ROW_SIZE; i++)
    {
        if (board[i][i] != 0)
        {
            is_bingo = 0;
            break;
        }
    }
    if (is_bingo) return 1;

    // Check inverse diagonal
    is_bingo = 1;
    for (int i = 0; i < ROW_SIZE; i++)
    {
        if (board[ROW_SIZE-i-1][i] != 0)
        {
            is_bingo = 0;
            break;
        }
    }
    if (is_bingo) return 1;

    return 0;
}