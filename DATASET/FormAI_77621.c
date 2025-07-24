//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW_SIZE 5
#define COL_SIZE 5

typedef struct
{
    int row;
    int col;
} Index;

// Function to get a random number within a range
int generateRandomNumber(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to check if a number exists in 2D array
int checkIfNumberExists(int number, int bingoBoard[ROW_SIZE][COL_SIZE])
{
    int row, col;
    for (row = 0; row < ROW_SIZE; row++)
    {
        for (col = 0; col < COL_SIZE; col++)
        {
            if (bingoBoard[row][col] == number)
                return 1;
        }
    }
    return 0;
}

// Function to randomly generate a bingo board
void generateBingoBoard(int bingoBoard[ROW_SIZE][COL_SIZE])
{
    int row, col;
    // Generate random numbers for each row and column
    for (row = 0; row < ROW_SIZE; row++)
    {
        for (col = 0; col < COL_SIZE; col++)
        {
            int lower, upper;
            // Set range based on column
            switch (col)
            {
            case 0: // Column B
                lower = 1;
                upper = 15;
                break;
            case 1: // Column I
                lower = 16;
                upper = 30;
                break;
            case 2: // Column N
                lower = 31;
                upper = 45;
                break;
            case 3: // Column G
                lower = 46;
                upper = 60;
                break;
            case 4: // Column O
                lower = 61;
                upper = 75;
                break;
            default:
                break;
            }
            // Generate random number within range
            int number = generateRandomNumber(lower, upper);
            // Check if number already exists in board
            while (checkIfNumberExists(number, bingoBoard))
            {
                number = generateRandomNumber(lower, upper);
            }
            // Assign number to board
            bingoBoard[row][col] = number;
        }
    }
}

// Function to print bingo board
void printBingoBoard(int bingoBoard[ROW_SIZE][COL_SIZE], Index index)
{
    int row, col;
    printf("+----+----+----+----+----+\n");
    for (row = 0; row < ROW_SIZE; row++)
    {
        for (col = 0; col < COL_SIZE; col++)
        {
            printf("|");
            if (row == index.row && col == index.col)
            {
                printf("XX");
            }
            else
            {
                printf("%02d", bingoBoard[row][col]);
            }
        }
        printf("|\n");
        printf("+----+----+----+----+----+\n");
    }
}

int main()
{
    int bingoBoard[ROW_SIZE][COL_SIZE];
    generateBingoBoard(bingoBoard);
    Index index = { 0, 2 }; // Start in the center of board (Free space)
    int counter = 0;
    srand(time(NULL)); // Initialize random number generator
    while (counter < 25)
    {
        system("clear"); // Clear console screen
        printBingoBoard(bingoBoard, index);
        int number = generateRandomNumber(1, 75); // Generate random number between 1 and 75
        if (checkIfNumberExists(number, bingoBoard))
        {
            // Mark number off board
            int row, col;
            for (row = 0; row < ROW_SIZE; row++)
            {
                for (col = 0; col < COL_SIZE; col++)
                {
                    if (bingoBoard[row][col] == number)
                        bingoBoard[row][col] = -1; // -1 represents marked off number
                }
            }
            counter++;
        }
        // Move to next spot on board
        if (index.col == 4)
        {
            index.col = 0;
            index.row++;
        }
        else
        {
            index.col++;
        }
        // Pause for 1 second before generating next number
        printf("Next Number: %d\n", number);
        printf("Press Enter to continue...\n");
        getchar();
    }
    printf("Bingo!\n");
    return 0;
}