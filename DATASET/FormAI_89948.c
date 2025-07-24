//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between range
int generateRandom(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    // Code for colorful output
    system("color 03");

    // Variables for game
    int cards[3][9] = {{0}}, count = 0, num;

    // Printing title and game rules
    printf("Welcome to C Bingo Simulator!\n");
    printf("Game rules:\n1. You have 3 cards with 9 numbers each\n2. The numbers in each card are between 1-90\n3. The program will generate random numbers\n4. If you have a matching number, it will be crossed out\n5. The first player to cross out all numbers in a row wins!\n\n");

    // Loop for generating cards
    for (int i = 0; i < 3; i++)
    {
        count = 0;

        // Loop for generating unique numbers in a row
        while (count < 9)
        {
            num = generateRandom(i * 10 + 1, (i + 1) * 10);
            int flag = 0;

            // Checking if number is already present in the row
            for (int j = 0; j < count; j++)
            {
                if (cards[i][j] == num)
                {
                    flag = 1;
                    break;
                }
            }

            // If number is unique, add it to the row
            if (!flag)
            {
                cards[i][count] = num;
                count++;
            }
        }
    }

    // Variables for tracking state of game
    int rows[3] = {0}, cols[9] = {0}, diag1 = 0, diag2 = 0, winner = 0, numCount = 0;

    // Loop for game
    while (!winner && numCount < 90)
    {
        // Generate random number
        int n = generateRandom(1, 90);

        // Printing number and crossing it out
        printf("Number generated: %d\n", n);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (cards[i][j] == n)
                {
                    printf("Found number %d at card %d, position %d,%d\n", n, i + 1, j + 1, i * 3 + j + 1);
                    cards[i][j] = 0;
                    rows[i]++;
                    cols[j]++;
                    if (i == j)
                    {
                        diag1++;
                    }
                    if (i + j == 8)
                    {
                        diag2++;
                    }
                    numCount++;
                }
            }
        }

        // Checking for winner
        for (int i = 0; i < 3; i++)
        {
            if (rows[i] == 9)
            {
                winner = i + 1;
                break;
            }
        }
        if (diag1 == 9 || diag2 == 9)
        {
            winner = 4;
        }
        for (int j = 0; j < 9; j++)
        {
            if (cols[j] == 3)
            {
                winner = 5 + j;
                break;
            }
        }

        // Printing updated card status
        printf("\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%2d ", cards[i][j]);
            }
            printf("\n");
        }

        printf("\n\n");
    }
    
    // Printing winner
    if (winner == 0)
    {
        printf("Draw! All numbers have been called.\n");
    }
    else if (winner == 4)
    {
        printf("Player %d wins on diagonal!\n", winner - 3);
    }
    else if (winner >= 5)
    {
        printf("Player %d wins on column %d!\n", winner - 4, winner - 5);
    }
    else
    {
        printf("Player %d wins on row %d!\n", winner, winner);
    }

    return 0;
}