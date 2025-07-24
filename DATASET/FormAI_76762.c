//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int bingo[5][5], num, i, j, count=0, max_count=0, flag;
    srand(time(0));
    printf("Welcome to the Happy Bingo Simulator!\n");

    // Generate a random Bingo board
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(i == 2 && j == 2) // Middle cell is always FREE
            {
                bingo[i][j] = -1;
            }
            else
            {
                num = (rand() % 15) + ((15*j)+1); // Generate a number between 1-15 for column 1, 16-30 for column 2 and so on..
                flag = 0;
                for(int k=0;k<=j;k++) // Check for duplicates in the same row
                {
                    if(bingo[i][k] == num)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1) // Generate new random number until no duplicates are found
                {
                    j--;
                    continue;
                }
                else
                {
                    bingo[i][j] = num;
                }
            }
        }
    }
    printf("Here's your Bingo board:\n");
    // Print the Bingo board
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d\t",bingo[i][j]);
        }
        printf("\n");
    }
    printf("Let's start playing Bingo!\n");
    // Player's Bingo card
    int arr[5][5] = {{2,6,11,13,21},
                    {23,31,36,41,45},
                    {48,50,-1,58,61},
                    {69,72,77,84,90},
                    {95,98,100,104,107}};
    // Print the player's Bingo card
    printf("Here's your Bingo card:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    while(max_count < 5)
    {
        int r_num = (rand() % 100) + 1; // Generate a random number between 1-100
        printf("The random number generated is: %d\n",r_num);
        // Check for the number in the player's card
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(arr[i][j] == r_num)
                {
                    arr[i][j] = -1; // Mark the number as found
                    count++;
                }
            }
        }
        // Check for a Bingo
        if(count > max_count) // If player has more marks than previous check, then he/she has found a new Bingo
        {
            max_count = count;
            printf("*** BINGO *** Number of marks found: %d\n",max_count);
        }

        // Check for a Full House
        int full_house = 1;
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            {
                if(arr[i][j] != -1)
                {
                    full_house = 0; // If any number is not marked, then Full House is not achieved
                    break;
                }
            }
        }
        if(full_house == 1)
        {
            printf("*** FULL HOUSE *** All numbers are marked!\n");
            break;
        }
    }
    printf("Thanks for playing Bingo!\n");
    return 0;
}