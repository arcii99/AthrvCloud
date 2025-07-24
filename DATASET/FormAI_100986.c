//FormAI DATASET v1.0 Category: Memory Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLUMNS 4

void generateBoard(int board[ROWS][COLUMNS]);
void printBoard(int board[ROWS][COLUMNS]);
void playGame(int board[ROWS][COLUMNS]);

int main()
{
    int board[ROWS][COLUMNS];

    srand(time(NULL));

    generateBoard(board);
    printBoard(board);
    playGame(board);

    return 0;
}

void generateBoard(int board[ROWS][COLUMNS])
{
    int numPairs = (ROWS * COLUMNS) / 2;
    int pairs[numPairs];
    int count = 0;

    // Populate array with pairs of numbers between 1 and numPairs
    for(int i = 0; i < numPairs; i++)
    {
        pairs[i] = count + 1;
        pairs[i+1] = count + 1;
        count++;
    }

    // Shuffle array using Fisher-Yates algorithm
    int temp, randomIndex;
    for(int i = numPairs - 1; i > 0; i--)
    {
        randomIndex = rand() % (i + 1);
        temp = pairs[i];
        pairs[i] = pairs[randomIndex];
        pairs[randomIndex] = temp;
    }

    // Assign shuffled pairs to board
    count = 0;
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            board[i][j] = pairs[count];
            count++;
        }
    }
}

void printBoard(int board[ROWS][COLUMNS])
{
    printf("\nMemory Game\n");
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLUMNS; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void playGame(int board[ROWS][COLUMNS])
{
    int firstRow, firstColumn, secondRow, secondColumn;
    int numMoves = 0;

    while(1)
    {
        printf("\nEnter first row and column: ");
        scanf("%d %d", &firstRow, &firstColumn);
        printf("Enter second row and column: ");
        scanf("%d %d", &secondRow, &secondColumn);

        // Check if selected cells are valid and not already matched
        if((firstRow < 1 || firstRow > ROWS || firstColumn < 1 || firstColumn > COLUMNS) ||
           (secondRow < 1 || secondRow > ROWS || secondColumn < 1 || secondColumn > COLUMNS) ||
           (board[firstRow-1][firstColumn-1] == 0 || board[secondRow-1][secondColumn-1] == 0))
        {
            printf("Invalid move. Try again.\n");
        }
        else
        {
            // Check if selected cells match
            if(board[firstRow-1][firstColumn-1] == board[secondRow-1][secondColumn-1])
            {
                board[firstRow-1][firstColumn-1] = 0;
                board[secondRow-1][secondColumn-1] = 0;
                numMoves++;
                printf("Match found!\n");
            }
            else
            {
                numMoves++;
                printf("No match. Try again.\n");
            }
        }

        // Check if game is over
        int gameOver = 1;
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLUMNS; j++)
            {
                if(board[i][j] != 0)
                {
                    gameOver = 0;
                    break;
                }
            }
        }
        if(gameOver)
        {
            printf("\nCongratulations! You won in %d moves!\n", numMoves);
            break;
        }
    }
}