//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Bingo Simulator\n\n");

    // Setting up the game
    int matrix[5][5];
    srand(time(NULL));
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(i==2 && j==2) // Center square is always free
                matrix[i][j] = 0;
            else
                matrix[i][j] = rand()%75 + 1; // Random number between 1 and 75
        }
    }

    // Printing out the card
    printf("Your Bingo card is:\n\n");
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(matrix[i][j] == 0)
                printf("  * ");
            else
                printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calling out numbers
    int numbers[75];
    for(int i=0; i<75; i++)
        numbers[i] = i+1;

    printf("\nLet's start calling out numbers!\n\n");

    int row, col, count;
    for(int i=0; i<75; i++)
    {
        int randomIndex = rand()%75;
        int number = numbers[randomIndex];

        printf("Bingo number %d!\n", number);

        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(matrix[i][j] == number)
                {
                    row = i;
                    col = j;
                    matrix[i][j] = 0;
                    count++;
                }
            }
        }

        if(count >= 5)
        {
            printf("\nYou have a Bingo!!\n\n");
            break;
        }

        // Printing out the updated card
        printf("Your updated Bingo card is:\n\n");
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                if(matrix[i][j] == 0)
                    printf("  * ");
                else
                    printf("%3d ", matrix[i][j]);
            }
            printf("\n");
        }

        numbers[randomIndex] = numbers[i];
        numbers[i] = number;
    }

    printf("\nThank you for playing!\n");

    return 0;
}