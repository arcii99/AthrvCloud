//FormAI DATASET v1.0 Category: Table Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 5
 
int main()
{
    int table[ROWS][COLS];
    int i, j;
    int sumRow[ROWS] = {0};
    int sumCol[COLS] = {0};
    int sumDiag[2] = {0};
    int winner = 0;
    
    srand(time(NULL));
    
    printf("Welcome to the Table Game! The game board consists of a %dx%d table.\n", ROWS, COLS);
    
    //generate random numbers and print table
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            table[i][j] = rand() % 10;
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    
    //calculate sum of each row, column, and diagonal
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            sumRow[i] += table[i][j];
            sumCol[j] += table[i][j];
            if(i == j)
            {
                sumDiag[0] += table[i][j];
            }
            if(i + j == ROWS - 1)
            {
                sumDiag[1] += table[i][j];
            }
        }
    }
    
    //determine winner
    for(i = 0; i < ROWS; i++)
    {
        if(sumRow[i] == sumCol[0])
        {
            winner = 1;
            for(j = 1; j < COLS; j++)
            {
                if(sumRow[i] != sumCol[j])
                {
                    winner = 0;
                    break;
                }
            }
            if(winner == 1)
            {
                printf("The winner is Row %d!\n", i+1);
                break;
            }
        }
        if(sumRow[i] == sumDiag[0])
        {
            printf("The winner is Diagonal 1!\n");
            break;
        }
        if(sumRow[i] == sumDiag[1])
        {
            printf("The winner is Diagonal 2!\n");
            break;
        }
    }
    
    //no winner
    if(i == ROWS)
    {
        printf("There is no winner. Please try again!\n");
    }
    
    return 0;
}