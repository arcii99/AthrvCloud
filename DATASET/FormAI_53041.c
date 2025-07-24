//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int main()
{
    int numbers[ROWS][COLS];
    int calledNumbers[100];
    int count = 0;
    int temp;
    int i, j;

    // Generate random numbers for the bingo card
    srand(time(NULL));
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(j == 2 && i == 2)
            {
                numbers[i][j] = -1;    // place a free space in the center of the card
            }
            else
            {
                numbers[i][j] = rand() % 15 + (15 * j) + 1;    // generate numbers within a range for each column
            }
        }
    }

    // Display the bingo card to the user
    printf("Welcome to Bingo!\n\n");
    printf("Here is your bingo card:\n\n");
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%2d ", numbers[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Start calling numbers until a player wins
    while(1)
    {
        // Generate a random number between 1-75 that has not already been called
        temp = rand() % 75 + 1;
        for(i = 0; i < count; i++)
        {
            if(temp == calledNumbers[i])
            {
                break;
            }
        }
        if(i == count)
        {
            // Add the number to the list of called numbers and check if it matches any on the bingo card
            calledNumbers[count++] = temp;
            printf("The number called is: %d\n", temp);
            for(i = 0; i < ROWS; i++)
            {
                for(j = 0; j < COLS; j++)
                {
                    if(numbers[i][j] == temp)
                    {
                        numbers[i][j] = -1;    // mark the number on the bingo card
                    }
                }
            }

            // Check if the user has a bingo
            if(numbers[0][0] == -1 && numbers[0][1] == -1 && numbers[0][2] == -1 && numbers[0][3] == -1 && numbers[0][4] == -1)
            {
                printf("BINGO! You won!\n");
                break;
            }
            else if(numbers[1][0] == -1 && numbers[1][1] == -1 && numbers[1][2] == -1 && numbers[1][3] == -1 && numbers[1][4] == -1)
            {
                printf("BINGO! You won!\n");
                break;
            }
            else if(numbers[2][0] == -1 && numbers[2][1] == -1 && numbers[2][2] == -1 && numbers[2][3] == -1 && numbers[2][4] == -1)
            {
                printf("BINGO! You won!\n");
                break;
            }
            else if(numbers[3][0] == -1 && numbers[3][1] == -1 && numbers[3][2] == -1 && numbers[3][3] == -1 && numbers[3][4] == -1)
            {
                printf("BINGO! You won!\n");
                break;
            }
            else if(numbers[4][0] == -1 && numbers[4][1] == -1 && numbers[4][2] == -1 && numbers[4][3] == -1 && numbers[4][4] == -1)
            {
                printf("BINGO! You won!\n");
                break;
            }
            else if(numbers[0][0] == -1 && numbers[1][0] == -1 && numbers[2][0] == -1 && numbers[3][0] == -1 && numbers[4][0] == -1)
            {
                printf("BINGO! You won!\n");
                break;
            }
            else if(numbers[0][1] == -1 && numbers[1][1] == -1 && numbers[2][1] == -1 && numbers[3][1] == -1 && numbers[4][1] == -1)
            {
                printf("BINGO! You won!\n");
                break;
            }
            else if(numbers[0][2] == -1 && numbers[1][2] == -1 && numbers[2][2] == -1 && numbers[3][2] == -1 && numbers[4][2] == -1)
            {
                printf("BINGO! You won!\n");
                break;
            }
            else if(numbers[0][3] == -1 && numbers[1][3] == -1 && numbers[2][3] == -1 && numbers[3][3] == -1 && numbers[4][3] == -1)
            {
                printf("BINGO! You won!\n");
                break;
            }
            else if(numbers[0][4] == -1 && numbers[1][4] == -1 && numbers[2][4] == -1 && numbers[3][4] == -1 && numbers[4][4] == -1)
            {
                printf("BINGO! You won!\n");
                break;
            }
        }
    }

    return 0;
}