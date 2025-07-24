//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

void printArray(int arr[][COLUMNS]);
void shuffleArray(int arr[][COLUMNS]);
void playBingo(int arr[][COLUMNS]);

int main()
{
    int bingoCard[ROWS][COLUMNS] = {{0}};

    // Generate random numbers for each column
    srand(time(NULL));
    for(int col = 0; col < COLUMNS; col++)
    {
        for(int row = 0; row < ROWS; row++)
        {
            if(col == 2 && row == 2) // center cell is always empty
            {
                bingoCard[row][col] = 0;
            }
            else
            {
                int num = rand() % 15 + 15 * col + 1;
                bingoCard[row][col] = num;
            }
        }
    }

    shuffleArray(bingoCard);
    printArray(bingoCard);
    playBingo(bingoCard);

    return 0;
}

void printArray(int arr[][COLUMNS])
{
    // Print header
    printf("\tB\tI\tN\tG\tO\n\n");

    // Print array
    for(int row = 0; row < ROWS; row++)
    {
        for(int col = 0; col < COLUMNS; col++)
        {
            if(col == 0 && row == 2) // center cell is always empty
            {
                printf("\t");
            }
            else
            {
                printf("%d\t", arr[row][col]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void shuffleArray(int arr[][COLUMNS])
{
    // Shuffle array
    for(int col = 0; col < COLUMNS; col++)
    {
        for(int row = 0; row < ROWS; row++)
        {
            int randRow = rand() % ROWS;
            int randCol = rand() % COLUMNS;

            // Swap cells
            int temp = arr[row][col];
            arr[row][col] = arr[randRow][randCol];
            arr[randRow][randCol] = temp;
        }
    }
}

void playBingo(int arr[][COLUMNS])
{
    int numsCalled[ROWS * COLUMNS] = {0};
    int numOfCalls = 0;

    printf("Let's play Bingo!\n\n");
    printf("When you get a Bingo, type 'Bingo' to win!\n\n");

    // Keep calling numbers until someone wins
    while(1)
    {
        // Call a random number
        int randNum = rand() % (ROWS * COLUMNS) + 1;
        while(numsCalled[randNum - 1] != 0)
        {
            randNum = rand() % (ROWS * COLUMNS) + 1;
        }
        numsCalled[randNum - 1] = 1;
        numOfCalls++;

        // Check if number is on the card
        for(int col = 0; col < COLUMNS; col++)
        {
            for(int row = 0; row < ROWS; row++)
            {
                if(arr[row][col] == randNum)
                {
                    arr[row][col] = 0; // Mark cell as called
                }
            }
        }

        // Print the called number and the updated card
        printf("Called number: %d\n\n", randNum);
        printArray(arr);

        // Check if anyone won
        int winner = 0;

        // Check rows
        for(int row = 0; row < ROWS; row++)
        {
            int rowSum = 0;
            for(int col = 0; col < COLUMNS; col++)
            {
                rowSum += arr[row][col];
            }
            if(rowSum == 0)
            {
                winner = 1;
                break;
            }
        }

        // Check columns
        for(int col = 0; col < COLUMNS; col++)
        {
            int colSum = 0;
            for(int row = 0; row < ROWS; row++)
            {
                colSum += arr[row][col];
            }
            if(colSum == 0)
            {
                winner = 1;
                break;
            }
        }

        // Check diagonals
        if(arr[0][0] + arr[1][1] + arr[2][2] + arr[3][3] + arr[4][4] == 0 ||
        arr[0][4] + arr[1][3] + arr[2][2] + arr[3][1] + arr[4][0] == 0)
        {
            winner = 1;
        }

        if(winner)
        {
            printf("Bingo!\n");
            printf("It took %d calls to win!\n", numOfCalls);
            break;
        }
    }
}