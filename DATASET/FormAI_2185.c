//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define NUM_OF_BINGO_NUMBERS 25

int generateRandomNumber(int *bingoNumbers, int index);
void initializeBingoBoard(int bingoBoard[ROWS][COLS], int bingoNumbers[NUM_OF_BINGO_NUMBERS]);
void printBingoBoard(int bingoBoard[ROWS][COLS]);
void chooseNewNumber(int *chosen, int bingoNumbers[NUM_OF_BINGO_NUMBERS]);
int checkIfBingo(int bingoBoard[ROWS][COLS], int *chosen);

int main()
{
    int bingoBoard[ROWS][COLS];
    int bingoNumbers[NUM_OF_BINGO_NUMBERS];
    int chosen;

    // Set seed for random number generator
    srand(time(NULL));

    // Initialize bingo board with random numbers from the bingo numbers array
    initializeBingoBoard(bingoBoard, bingoNumbers);

    // Print out the initial bingo board
    printf("Bingo board:\n");
    printBingoBoard(bingoBoard);
    printf("\n");

    // Loop until there is a bingo
    while (1)
    {
        // Randomly choose a new number from the potential bingo numbers
        chooseNewNumber(&chosen, bingoNumbers);

        // Check if the chosen number is on the bingo board, and mark it if it is
        if (checkIfBingo(bingoBoard, &chosen))
        {
            printf("New bingo number is: %d\n", chosen);
            printBingoBoard(bingoBoard);
            printf("\nBINGO! You won!\n");
            break;
        }
        else
        {
            printf("New bingo number is: %d\n", chosen);
        }
    }

    return 0;
}

/**
 * Returns a random element from the bingo numbers array.
 * The element is replaced with the last element in the array, and the array is resized.
 **/
int generateRandomNumber(int *bingoNumbers, int index)
{
    int randomIndex = rand() % index;
    int randomElement = bingoNumbers[randomIndex];

    // Replace chosen element with last element in array, and decrease array size
    bingoNumbers[randomIndex] = bingoNumbers[index - 1];

    return randomElement;
}

/**
 * Initializes the bingo board with random numbers from the bingo numbers array.
 * The bingo numbers array is resized and shuffled.
 **/
void initializeBingoBoard(int bingoBoard[ROWS][COLS], int bingoNumbers[NUM_OF_BINGO_NUMBERS])
{
    int i, j;

    // Fill bingo numbers array with values
    for (i = 0; i < NUM_OF_BINGO_NUMBERS; i++)
    {
        bingoNumbers[i] = i + 1;
    }

    // Shuffle bingo numbers array
    for (i = NUM_OF_BINGO_NUMBERS - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = bingoNumbers[i];
        bingoNumbers[i] = bingoNumbers[j];
        bingoNumbers[j] = temp;
    }

    // Fill bingo board with values from shuffled bingo numbers array
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            bingoBoard[i][j] = generateRandomNumber(bingoNumbers, NUM_OF_BINGO_NUMBERS - (i * COLS) - j);
        }
    }

    // Mark center of bingo board
    bingoBoard[2][2] = -1;
}

/**
 * Prints out the bingo board.
 **/
void printBingoBoard(int bingoBoard[ROWS][COLS])
{
    int i, j;

    printf("    B  I  N  G  O\n");

    for (i = 0; i < ROWS; i++)
    {
        printf("  +--+--+--+--+--+\n");

        for (j = 0; j < COLS; j++)
        {
            if (bingoBoard[i][j] == -1)
            {
                printf(" | X");
            }
            else if (bingoBoard[i][j] < 10)
            {
                printf(" | %d", bingoBoard[i][j]);
            }
            else
            {
                printf("| %d", bingoBoard[i][j]);
            }

            if (j == 4)
            {
                printf(" |\n");
            }
        }
    }

    printf("  +--+--+--+--+--+\n");
}

/**
 * Chooses a new number from the potential bingo numbers array.
 **/
void chooseNewNumber(int *chosen, int bingoNumbers[NUM_OF_BINGO_NUMBERS])
{
    *chosen = generateRandomNumber(bingoNumbers, NUM_OF_BINGO_NUMBERS);
}

/**
 * Checks if the chosen number appears on the bingo board.
 * If it does, it is marked on the board.
 **/
int checkIfBingo(int bingoBoard[ROWS][COLS], int *chosen)
{
    int i, j, bingo;

    // Mark matched number on bingo board
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (bingoBoard[i][j] == *chosen)
            {
                bingoBoard[i][j] = -1;
                break;
            }
        }
    }

    // Check for bingo on rows
    for (i = 0; i < ROWS; i++)
    {
        bingo = 1;

        for (j = 0; j < COLS; j++)
        {
            if (bingoBoard[i][j] != -1)
            {
                bingo = 0;
                break;
            }
        }

        if (bingo)
        {
            return 1;
        }
    }

    // Check for bingo on columns
    for (j = 0; j < COLS; j++)
    {
        bingo = 1;

        for (i = 0; i < ROWS; i++)
        {
            if (bingoBoard[i][j] != -1)
            {
                bingo = 0;
                break;
            }
        }

        if (bingo)
        {
            return 1;
        }
    }

    // Check for bingo on first diagonal
    bingo = 1;

    for (i = 0; i < ROWS; i++)
    {
        if (bingoBoard[i][i] != -1)
        {
            bingo = 0;
            break;
        }
    }

    if (bingo)
    {
        return 1;
    }

    // Check for bingo on second diagonal
    bingo = 1;

    for (i = 0; i < ROWS; i++)
    {
        if (bingoBoard[i][COLS - i - 1] != -1)
        {
            bingo = 0;
            break;
        }
    }

    if (bingo)
    {
        return 1;
    }

    return 0;
}