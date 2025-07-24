//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, num, card[5][5], count = 0;
    char choice;

    srand(time(0)); // Initializing random number generator

    printf("Welcome to C Bingo Simulator!\n\n"); 
    printf("Each card contains 5 random numbers between 1 and 25.\n");
    printf("The first player to mark off a line, column or diagonal wins the game.\n\n");

    do
    {
        printf("Press enter to generate a new card.\n");
        getchar(); // Waits for user input
        printf("\n");

        // Generates a new card
        for (i = 0; i < 5; ++i)
        {
            for (j = 0; j < 5; ++j)
            {
                num = rand() % 25 + 1; // Generates a random number between 1 and 25
                card[i][j] = num;

                // Checks for duplicates
                for (int k = 0; k < j; ++k)
                {
                    if (card[i][k] == num)
                    {
                        j--;
                        break;
                    }
                }
            }
        }

        // Prints the card
        printf(" B   I   N   G   O\n");
        for (i = 0; i < 5; ++i)
        {
            for (j = 0; j < 5; ++j)
            {
                if (card[i][j] == -1) // Marks off a number if it has been called
                    printf("X   ");
                else 
                    printf("%-3d ", card[i][j]);
            }
            printf("\n");
        }

        while (1)
        {
            printf("Enter the number called (-1 to exit): ");
            scanf("%d", &num);
            printf("\n");

            if (num == -1) // Exits the program
                return 0;

            // Marks off the number on the card
            for (i = 0; i < 5; ++i)
            {
                for (j = 0; j < 5; ++j)
                {
                    if (card[i][j] == num)
                    {
                        card[i][j] = -1; 
                        count++;
                    }
                }
            }

            // Checks for a winner
            if (card[0][0] == -1 && card[1][1] == -1 && card[2][2] == -1 && card[3][3] == -1 && card[4][4] == -1) // Top-left to bottom-right diagonal
            {
                printf("Congratulations! You won!\n");
                break;
            }
            else if (card[0][4] == -1 && card[1][3] == -1 && card[2][2] == -1 && card[3][1] == -1 && card[4][0] == -1) // Top-right to bottom-left diagonal
            {
                printf("Congratulations! You won!\n");
                break;
            }
            else // Rows and columns
            {
                for (i = 0; i < 5; ++i)
                {
                    if (card[i][0] == -1 && card[i][1] == -1 && card[i][2] == -1 && card[i][3] == -1 && card[i][4] == -1) // Row
                    {
                        printf("Congratulations! You won!\n");
                        break;
                    }
                    if (card[0][i] == -1 && card[1][i] == -1 && card[2][i] == -1 && card[3][i] == -1 && card[4][i] == -1) // Column
                    {
                        printf("Congratulations! You won!\n");
                        break;
                    }
                }
                if (i < 5) // There is a winner
                    break;
            }

            // Checks if all numbers have been called
            if (count == 25)
            {
                printf("All numbers have been called. The game is a draw.\n");
                break;
            }
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &choice);
        printf("\n");

        // Resets the card
        for (i = 0; i < 5; ++i)
        {
            for (j = 0; j < 5; ++j)
            {
                card[i][j] = 0;
                count = 0;
            }
        }

    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}