//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5

int main()
{
    srand(time(NULL)); //initialize random seed

    int i, j, k, n, count, number;
    int rowSum[ROW], colSum[COL], diagonalSum[2];
    char bingoBoard[ROW][COL];

    //initialize variables
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            bingoBoard[i][j] = '-';
        }
        rowSum[i] = 0;
    }

    for (j = 0; j < COL; j++)
    {
        colSum[j] = 0;
    }

    for (k = 0; k < 2; k++)
    {
        diagonalSum[k] = 0;
    }

    //generate random numbers and update board
    count = 0;
    while (count < 25)
    {
        number = rand() % 25 + 1;

        for (i = 0; i < ROW; i++)
        {
            for (j = 0; j < COL; j++)
            {
                if (bingoBoard[i][j] == '-' && (i * 5 + j + 1) == number)
                {
                    bingoBoard[i][j] = 'X';
                    count++;

                    //update sums
                    rowSum[i]++;
                    colSum[j]++;

                    if (i == j)
                    {
                        diagonalSum[0]++;
                    }

                    if (i + j == 4)
                    {
                        diagonalSum[1]++;
                    }
                }
            }
        }
    }

    //print board
    printf("B  I  N  G  O\n");
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%c  ", bingoBoard[i][j]);
        }
        printf("%d\n", i + 1);
    }

    //print sums
    printf("Row sums:\n");
    for (i = 0; i < ROW; i++)
    {
        printf("%d ", rowSum[i]);
    }

    printf("\nColumn sums:\n");
    for (j = 0; j < COL; j++)
    {
        printf("%d ", colSum[j]);
    }

    printf("\nDiagonal sums:\n");
    for (k = 0; k < 2; k++)
    {
        printf("%d ", diagonalSum[k]);
    }

    //check if there is a bingo
    for (i = 0; i < ROW; i++)
    {
        if (rowSum[i] == 5)
        {
            printf("\nBingo! Row %d", i + 1);
            return 0;
        }
    }

    for (j = 0; j < COL; j++)
    {
        if (colSum[j] == 5)
        {
            printf("\nBingo! Column %d", j + 1);
            return 0;
        }
    }

    for (k = 0; k < 2; k++)
    {
        if (diagonalSum[k] == 5)
        {
            printf("\nBingo! Diagonal %d", k + 1);
            return 0;
        }
    }

    printf("\nNo bingo.");
    return 0;
}