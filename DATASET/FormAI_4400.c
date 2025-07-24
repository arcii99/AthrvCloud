//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

void initializeBoard(int bingoBoard[ROWS][COLS], int* usedNumbers);
void displayBoard(int bingoBoard[ROWS][COLS]);
int drawNumber(int* usedNumbers);
int checkForWin(int bingoBoard[ROWS][COLS]);

int main()
{
    int bingoBoard[ROWS][COLS];
    int usedNumbers[MAX_NUM] = {0};

    // Initialize the bingo board and the used numbers array
    initializeBoard(bingoBoard, usedNumbers);

    // Display the initial bingo board
    printf("Welcome to the Interactive Bingo Simulator!\n\n");
    displayBoard(bingoBoard);

    // Loop until there is a win
    while (!checkForWin(bingoBoard))
    {
        // Draw a number
        int number = drawNumber(usedNumbers);

        // Update the bingo board
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (bingoBoard[i][j] == number)
                {
                    bingoBoard[i][j] = -1;
                }
            }
        }

        // Display the updated bingo board
        printf("Number drawn: %d\n\n", number);
        displayBoard(bingoBoard);
    }

    // Display the final bingo board and congratulate the winner
    printf("BINGO! We have a winner!\n\n");
    displayBoard(bingoBoard);
    printf("Congratulations!\n");

    return 0;
}

// Initializes the bingo board and the used numbers array
void initializeBoard(int bingoBoard[ROWS][COLS], int* usedNumbers)
{
    // Fill the used numbers array with 0s
    for (int i = 0; i < MAX_NUM; i++)
    {
        usedNumbers[i] = 0;
    }

    // Fill the bingo board with random numbers
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // Generate a random number
            int number = rand() % MAX_NUM + 1;

            // Check if the number has already been used
            while (usedNumbers[number - 1] == 1)
            {
                number = rand() % MAX_NUM + 1;
            }

            // Update the bingo board and used numbers array
            bingoBoard[i][j] = number;
            usedNumbers[number - 1] = 1;
        }
    }

    // Mark the center of the board as "FREE"
    bingoBoard[2][2] = -1;
}

// Displays the current bingo board to the console
void displayBoard(int bingoBoard[ROWS][COLS])
{
    printf("B    I    N    G    O\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (bingoBoard[i][j] == -1)
            {
                printf("FREE ");
            }
            else
            {
                printf("%-4d ", bingoBoard[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Draws a random number that hasn't been used yet
int drawNumber(int* usedNumbers)
{
    // Generate a random number
    int number = rand() % MAX_NUM + 1;

    // Check if the number has already been used
    while (usedNumbers[number - 1] == 1)
    {
        number = rand() % MAX_NUM + 1;
    }

    // Update the used numbers array
    usedNumbers[number - 1] = 1;

    return number;
}

// Checks if there is a win on the current bingo board
int checkForWin(int bingoBoard[ROWS][COLS])
{
    int win = 0;

    // Check for horizontal wins
    for (int i = 0; i < ROWS; i++)
    {
        if (bingoBoard[i][0] == -1 && bingoBoard[i][1] == -1 && bingoBoard[i][2] == -1 && bingoBoard[i][3] == -1 && bingoBoard[i][4] == -1)
        {
            win = 1;
        }
    }

    // Check for vertical wins
    for (int i = 0; i < COLS; i++)
    {
        if (bingoBoard[0][i] == -1 && bingoBoard[1][i] == -1 && bingoBoard[2][i] == -1 && bingoBoard[3][i] == -1 && bingoBoard[4][i] == -1)
        {
            win = 1;
        }
    }

    // Check for diagonal wins
    if (bingoBoard[0][0] == -1 && bingoBoard[1][1] == -1 && bingoBoard[2][2] == -1 && bingoBoard[3][3] == -1 && bingoBoard[4][4] == -1)
    {
        win = 1;
    }
    if (bingoBoard[0][4] == -1 && bingoBoard[1][3] == -1 && bingoBoard[2][2] == -1 && bingoBoard[3][1] == -1 && bingoBoard[4][0] == -1)
    {
        win = 1;
    }

    return win;
}