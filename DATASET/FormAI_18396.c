//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

// Global variables
int numbers[MAX_NUM];
int counter = 0;

// Function prototypes
void generateRandomNumbers();
void printBingoBoard(int board[ROWS][COLS]);
void checkForMatch(int num, int board[ROWS][COLS]);

int main()
{
    // Initialization
    srand(time(NULL));
    int board[ROWS][COLS] = {{0}};
    generateRandomNumbers();

    // Main game loop
    while (counter < MAX_NUM)
    {
        printf("Next number: %d\n", numbers[counter]);
        checkForMatch(numbers[counter], board);
        printBingoBoard(board);
        if (counter == MAX_NUM - 1)
        {
            printf("Bingo! You've won!\n");
            break;
        }
        printf("Press ENTER for next number...");
        getchar();
        counter++;
    }

    return 0;
}

// Function to generate random numbers for the game
void generateRandomNumbers()
{
    for (int i = 0; i < MAX_NUM; i++)
    {
        numbers[i] = rand() % MAX_NUM + 1;
    }
}

// Function to print out the current state of the bingo board
void printBingoBoard(int board[ROWS][COLS])
{
    printf("\nBINGO BOARD:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == -1)
            {
                printf("| X ");
            }
            else
            {
                printf("| %d ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("\n");
}

// Function to check if a number matches any on the bingo board and mark it as matched
void checkForMatch(int num, int board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == num)
            {
                board[i][j] = -1;
            }
        }
    }
}