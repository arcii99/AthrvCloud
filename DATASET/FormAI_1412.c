//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5
#define BINGO "BINGO"

// Function to generate random numbers
int random_number(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    char bingo_board[ROWS][COLS]={{'B', 'I', 'N', 'G', 'O'},
                                  {'8', '16', '22', '35', '48'},
                                  {'7', '17', '23', '34', '53'},
                                  {'5', '18', '24', '40', '57'},
                                  {'6', '19', '20', '38', '60'}};
    int bingo_numbers[ROWS*COLS - 1], count=0;
    char *bingo_check[5]={BINGO, &BINGO[1], &BINGO[2], &BINGO[3], &BINGO[4]};

    // Generate random bingo numbers
    srand(time(0));
    for(int i=0; i<ROWS*COLS - 1; i++)
    {
        bingo_numbers[i] = random_number(1,60);
        printf("%d ", bingo_numbers[i]);
        count++;
        if(count%5==0)
            printf("\n");
    }

    // Check each number for match on the bingo board
    for(int i=0; i<ROWS*COLS - 1; i++)
    {
        for(int j=0; j<ROWS; j++)
        {
            for(int k=0; k<COLS; k++)
            {
                if(bingo_board[j][k] == bingo_numbers[i]/10+48 || bingo_board[j][k] == bingo_numbers[i]%10+48)
                    bingo_board[j][k] = 'X';
            }
        }
    }

    // Print final bingo board
    printf("\n\nFinal Bingo Board:\n\n");
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
            printf("%4c", bingo_board[i][j]);
        printf("\n\n");
    }

    // Check for bingo
    printf("\n\nChecking for Bingo...");
    int bingo_count=0, row_count=0, col_count=0, diag_count=0;
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(bingo_board[i][j] == 'X')
            {
                row_count++;
                if(row_count == 5)
                {
                    printf("\n\nBINGO! Found in row %d\n", i+1);
                    bingo_count++;
                    row_count = 0;
                }

                col_count++;
                if(col_count == 5)
                {
                    printf("\n\nBINGO! Found in column %d\n", j+1);
                    bingo_count++;
                    col_count = 0;
                }

                if(i == j)
                {
                    diag_count++;
                    if(diag_count == 5)
                    {
                        printf("\n\nBINGO! Found in diagonal from top left to bottom right\n");
                        bingo_count++;
                        diag_count = 0;
                    }
                }

                if(i == ROWS-j-1)
                {
                    diag_count++;
                    if(diag_count == 5)
                    {
                        printf("\n\nBINGO! Found in diagonal from top right to bottom left\n");
                        bingo_count++;
                        diag_count = 0;
                    }
                }
            }
            else
            {
                row_count = 0;
                col_count = 0;
                diag_count = 0;
            }
        }
    }

    // Check for full house
    if(bingo_count == 5)
        printf("\n\nFull House found! Congratulations!\n");
    else
        printf("\n\nNo Full House this time. Better luck next time!\n");

    return 0;
}