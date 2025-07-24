//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 5
#define COL 5

/* Function to Generate Random Number */
int generateRandom()
{
    int number = (rand() % 15) + 1;
    return number;
}

/* Function to Print the Game Board */
void printBoard(int board[][COL], int numCalls)
{
    printf("\tB   I   N   G   O\n");
    printf("\t-----------------\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (numCalls == board[i][j])
                printf("\tX ");
            else
                printf("\t%d ", board[i][j]);
        }
        printf("\n\n");
    }
}

/* Function to Check if Bingo Occurs */
int bingoCheck(int board[][COL])
{
    int count, j;
    for (int i = 0; i < ROW; i++)
    {
        /* Check Rows */
        count = 0;
        for (j = 0; j < COL; j++)
        {
            if (board[i][j] == -1)
                count++;
            else
                break;
        }
        if (count == 5)
            return 1;

        /* Check Columns */
        count = 0;
        for (j = 0; j < COL; j++)
        {
            if (board[j][i] == -1)
                count++;
            else
                break;
        }
        if (count == 5)
            return 1;
    }

    /* Check Diagonals */
    count = 0;
    for (int i = 0; i < ROW; i++)
    {
        if (board[i][i] == -1)
            count++;
        else
            break;
    }
    if (count == 5)
        return 1;

    count = 0;
    for (int i = 0; i < ROW; i++)
    {
        if (board[i][4 - i] == -1)
            count++;
        else
            break;
    }
    if (count == 5)
        return 1;

    return 0;
}

/* Main Function */
int main()
{
    int board[ROW][COL], card[25], numCalls = 0, randNum;
    printf("\n\t\t BINGO!\n\n");

    /* Randomly Generate Cards */
    for (int i = 0; i < 25; i++)
    {
        randNum = generateRandom();
        while (card[randNum])
            randNum = generateRandom();
        card[randNum] = 1;
    }

    /* Fill Board with Generated Cards */
    int k = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            board[i][j] = card[k];
            k++;
        }
    }

    board[2][2] = -1;

    /* Print Initial Board */
    printBoard(board, numCalls);

    /* Begin Game */
    while (1)
    {
        printf("Enter 0 to Quit or Anything Else to Generate the Next Number: ");
        int choice;
        scanf("%d", &choice);

        /* If User Quits */
        if (choice == 0)
            break;

        /* Generate Next Number */
        randNum = generateRandom();

        /* Check if Number is Already Called */
        while (card[randNum] == -1)
            randNum = generateRandom();

        numCalls++;

        /* Update Board */
        int flag = 0;
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                if (board[i][j] == randNum)
                {
                    board[i][j] = -1;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }

        /* Print Updated Board */
        printBoard(board, randNum);

        /* Check for Bingo */
        if (bingoCheck(board))
        {
            printf("BINGO!!!\n");
            break;
        }
    }

    printf("Thanks for Playing!\n");

    return 0;
}