//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Grateful Bingo Simulator!\n\n");

    // Array to hold the bingo numbers
    int bingoNumbers[25] = {0};

    // Filling the array with the numbers
    srand(time(NULL));
    for(int i = 0; i < 25; i++)
    {
        int number = rand() % 75 + 1;
        // Checking if the number already exists in the array
        int exists = 0;
        for(int j = 0; j < i; j++)
        {
            if(bingoNumbers[j] == number)
            {
                exists = 1;
                break;
            }
        }
        if(exists)
        {
            // If the number exists already, repeat iteration
            i--;
            continue;
        }
        else
        {
            bingoNumbers[i] = number;
        }
    }

    // Printing the bingo board
    printf("    B   I   N   G   O\n");
    printf("  +-------------------+\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%c | ", 'A' + i);
        for(int j = 0; j < 5; j++)
        {
            int index = i * 5 + j;
            if(i == 2 && j == 2)
            {
                printf("FREE ");
            }
            else
            {
                printf("%-2d  ", bingoNumbers[index]);
            }
        }
        printf("|\n");
    }
    printf("  +-------------------+\n\n");

    // Generating the bingo caller
    printf("Starting the game...\n");
    printf("Press enter to call the next number.\n");
    int calledNumbers[75] = {0};

    // Loop until a line or full house is called
    int line = 0, house = 0;
    while(!house)
    {
        getchar();
        int number = rand() % 75 + 1;
        calledNumbers[number - 1] = 1;
        printf("The next number is: %d\n", number);

        // Checking for lines
        if(!line)
        {
            int lines[4][5] = {{0,1,2,3,4}, {5,6,7,8,9}, {10,11,13,14,15}, {20,21,22,23,24}};
            for(int i = 0; i < 4; i++)
            {
                int count = 0;
                for(int j = 0; j < 5; j++)
                {
                    if(calledNumbers[lines[i][j]])
                    {
                        count++;
                    }
                }
                if(count == 5)
                {
                    line = 1;
                    printf("LINE! Press enter to continue.\n");
                    break;
                }
            }
        }

        // Checking for house
        int count = 0;
        for(int i = 0; i < 25; i++)
        {
            if(calledNumbers[bingoNumbers[i] - 1])
            {
                count++;
            }
        }
        if(count == 25)
        {
            house = 1;
            printf("HOUSE! Congratulations!\n");
            break;
        }
    }

    return 0;
}