//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int card[5][5];
    int i, j, num, flag;
    char ch = 'y';

    srand(time(NULL));

    printf("\n\t\t---- Welcome to the Paranoid Bingo Simulator ----\n\n");
    printf("\t\t  WARNING: This program may read your thoughts\n");
    printf("\t\t    and display the winning numbers accordingly\n\n");

    // Initialize the Bingo card with random numbers between 1 and 25
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            num = (rand() % 25) + 1;
            flag = 0;

            // Check if number already exists in card
            for(int k = 0; k < i; k++)
            {
                for(int l = 0; l < j; l++)
                {
                    if(num == card[k][l])
                    {
                        flag = 1;
                        break;
                    }
                }
            }

            // If number exists, generate a new one
            if(flag == 1)
            {
                j--;
                continue;
            }

            // Else, add number to the card
            card[i][j] = num;
        }
    }

    // Print the Bingo card
    printf("\n\t\t-------------- Your Bingo Card --------------\n\n");
    printf("\t\t|  B  |  I  |  N  |  G  |  O  |\n");
    for(i = 0; i < 5; i++)
    {
        printf("\t\t-----------------------------\n\t\t");
        for(j = 0; j < 5; j++)
        {
            if((i == 2) && (j == 2))
            {
                printf("|  X  ");
            }
            else
            {
                printf("|  %02d ", card[i][j]);
            }
        }
        printf("|\n");
    }
    printf("\t\t-----------------------------\n");

    // Generate and print the winning numbers
    printf("\n\n\t\t********** Press Enter to start **********\n\n");
    getchar();
    printf("\n\n\t\t-------------- The Winning Numbers are --------------\n\n");
    printf("\t\t|  B  |  I  |  N  |  G  |  O  |\n");
    for(i = 0; i < 5; i++)
    {
        printf("\t\t-----------------------------\n\t\t");
        for(j = 0; j < 5; j++)
        {
            if((i == 2) && (j == 2))
            {
                printf("|  X  ");
            }
            else
            {
                num = (rand() % 25) + 1;
                printf("|  %02d ", num);
            }
        }
        printf("|\n");
    }
    printf("\t\t-----------------------------\n");

    // Check if user wants to play again
    printf("\n\n\t\tWould you like to play again (y/n)?: ");
    scanf("%c", &ch);
    if(ch == 'y')
    {
        main();
    }
    else
    {
        printf("\n\n\t\t----- Thank you for playing the Paranoid Bingo Simulator -----");
    }

    return 0;
}