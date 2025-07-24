//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int card[5][5]; // The bingo card
    int called_nums[75]; // The called numbers
    int bingo = 0; // Counter for number of bingos

    // Initialize the card to all zeros
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            card[i][j] = 0;
        }
    }

    // Generate random numbers for the bingo card
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(i == 2 && j == 2) // Middle spot is always free
            {
                continue;
            }
            int num = (j * 15) + (rand() % 15) + 1;
            // Check if the number has already been assigned to the card
            for(int k = 0; k < i; k++)
            {
                for(int l = 0; l < 5; l++)
                {
                    if(card[k][l] == num)
                    {
                        num = (j * 15) + (rand() % 15) + 1;
                        k = 0;
                        l = -1;
                    }
                }
            }
            card[i][j] = num;
        }
    }

    // Print the bingo card
    printf("BINGO CARD:\n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%-3d ", card[i][j]);
        }
        printf("\n");
    }

    // Initialize the called numbers array to all zeros
    for(int i = 0; i < 75; i++)
    {
        called_nums[i] = 0;
    }

    // Generate random numbers until there is at least one bingo
    while(bingo == 0)
    {
        // Generate a random number
        int num = rand() % 75 + 1;
        // Check if the number has already been called
        for(int i = 0; i < 75; i++)
        {
            if(called_nums[i] == num)
            {
                num = rand() % 75 + 1;
                i = -1;
            }
        }
        // Add the number to the called numbers array
        for(int i = 0; i < 75; i++)
        {
            if(called_nums[i] == 0)
            {
                called_nums[i] = num;
                break;
            }
        }
        printf("NUMBER CALLED: %d\n", num);
        // Check if any numbers on the card match the called number
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(card[i][j] == num)
                {
                    card[i][j] = 0;
                }
            }
        }
        // Check if there is a bingo
        bingo = 1;
        // Check rows
        for(int i = 0; i < 5; i++)
        {
            int row_sum = 0;
            for(int j = 0; j < 5; j++)
            {
                row_sum += card[i][j];
            }
            if(row_sum == 0)
            {
                printf("BINGO! Row %d\n", i+1);
                bingo = 2;
            }
        }
        // Check columns
        for(int i = 0; i < 5; i++)
        {
            int col_sum = 0;
            for(int j = 0; j < 5; j++)
            {
                col_sum += card[j][i];
            }
            if(col_sum == 0)
            {
                printf("BINGO! Column %d\n", i+1);
                bingo = 2;
            }
        }
        // Check diagonals
        if(card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0)
        {
            printf("BINGO! Top-left to bottom-right diagonal\n");
            bingo = 2;
        }
        if(card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0)
        {
            printf("BINGO! Top-right to bottom-left diagonal\n");
            bingo = 2;
        }
    }

    return 0;
}