//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

int main() {

    int bingo[ROWS][COLUMNS];
    int calledNumbers[76] = {0};
    int countCalledNumbers = 0;
    int numbersFound = 0;
    int row, column;
    int randomNumber;
    char choice;

    // Seed the random number generator
    srand(time(NULL));

    // Fill the bingo card with random numbers
    for (row = 0; row < ROWS; row++) 
    {
        for (column = 0; column < COLUMNS; column++) 
        {
            // Generate a random number between 1 and 75
            do 
            {
                randomNumber = rand() % 75 + 1;
            } while (calledNumbers[randomNumber]);

            // Store the number in the bingo card
            bingo[row][column] = randomNumber;

            // Mark the number as called
            calledNumbers[randomNumber] = 1;
        }
    }

    // Print the bingo card
    printf("BINGO CARD\n");
    for (row = 0; row < ROWS; row++) 
    {
        for (column = 0; column < COLUMNS; column++) 
        {
            printf("%2d ", bingo[row][column]);
        }
        printf("\n");
    }

    // Game loop
    do 
    {
        // Generate a random number between 1 and 75
        do 
        {
            randomNumber = rand() % 75 + 1;
        } while (calledNumbers[randomNumber]);

        // Mark the number as called
        calledNumbers[randomNumber] = 1;
        countCalledNumbers++;

        printf("\nNumber called: %d\n", randomNumber);

        // Check the bingo card for the called number
        for (row = 0; row < ROWS; row++) 
        {
            for (column = 0; column < COLUMNS; column++) 
            {
                if (bingo[row][column] == randomNumber) 
                {
                    bingo[row][column] = 0;
                    numbersFound++;
                }
            }
        }

        // Print the updated bingo card
        printf("\nBINGO CARD\n");
        for (row = 0; row < ROWS; row++) 
        {
            for (column = 0; column < COLUMNS; column++) 
            {
                printf("%2d ", bingo[row][column]);
            }
            printf("\n");
        }

        // Check for a winning combination
        if (bingo[0][0] == 0 && bingo[0][1] == 0 && bingo[0][2] == 0 && bingo[0][3] == 0 && bingo[0][4] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }
        if (bingo[1][0] == 0 && bingo[1][1] == 0 && bingo[1][2] == 0 && bingo[1][3] == 0 && bingo[1][4] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }
        if (bingo[2][0] == 0 && bingo[2][1] == 0 && bingo[2][2] == 0 && bingo[2][3] == 0 && bingo[2][4] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }
        if (bingo[3][0] == 0 && bingo[3][1] == 0 && bingo[3][2] == 0 && bingo[3][3] == 0 && bingo[3][4] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }
        if (bingo[4][0] == 0 && bingo[4][1] == 0 && bingo[4][2] == 0 && bingo[4][3] == 0 && bingo[4][4] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }
        if (bingo[0][0] == 0 && bingo[1][0] == 0 && bingo[2][0] == 0 && bingo[3][0] == 0 && bingo[4][0] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }
        if (bingo[0][1] == 0 && bingo[1][1] == 0 && bingo[2][1] == 0 && bingo[3][1] == 0 && bingo[4][1] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }
        if (bingo[0][2] == 0 && bingo[1][2] == 0 && bingo[2][2] == 0 && bingo[3][2] == 0 && bingo[4][2] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }
        if (bingo[0][3] == 0 && bingo[1][3] == 0 && bingo[2][3] == 0 && bingo[3][3] == 0 && bingo[4][3] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }
        if (bingo[0][4] == 0 && bingo[1][4] == 0 && bingo[2][4] == 0 && bingo[3][4] == 0 && bingo[4][4] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }
        if (bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }
        if (bingo[4][0] == 0 && bingo[3][1] == 0 && bingo[2][2] == 0 && bingo[1][3] == 0 && bingo[0][4] == 0) 
        {
            printf("\nBINGO! You won!\n");
            break;
        }

        // Ask the user if they want to continue playing
        printf("\nDo you want to continue playing? (y/n) ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    printf("\nThanks for playing Bingo!\n");
    printf("You found %d numbers in %d called numbers.\n", numbersFound, countCalledNumbers);

    return 0;
}