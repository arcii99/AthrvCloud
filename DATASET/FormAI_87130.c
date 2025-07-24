//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5 // Number of rows
#define COLS 5 // Number of columns

int main()
{
    int card[ROWS][COLS] = {0}; // Initialize bingo card
    int numbers[75] = {0}; // Array to keep track of called numbers
    int count = 0; // Count of numbers called
    int num, row, col; // Variables to hold user input
    
    srand(time(NULL)); // Seed random number generator
    
    // Generate bingo card
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (j == 2 && i == 2) // Free space in middle of card
            {
                card[i][j] = 'X';
            }
            else // Generate random number for cell
            {
                int num = rand() % 15 + j * 15 + 1;
                card[i][j] = num;
            }
        }
    }
    
    printf("BINGO SIMULATOR\n\n");
    printf("Your card:\n");
    
    // Print bingo card
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%-4d", card[i][j]);
        }
        printf("\n");
    }
    
    printf("\nPress ENTER to start game.\n");
    getchar(); // Wait for user to press Enter
    
    // Game loop
    while (count < 75)
    {
        system("clear"); // Clear terminal
        
        printf("Current card:\n");
        
        // Print current card with called numbers marked
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (card[i][j] == 'X') // Print X for free space
                {
                    printf("X   ");
                }
                else if (numbers[card[i][j]] == 1) // Mark called numbers
                {
                    printf("%-4s", "X");
                }
                else // Print number
                {
                    printf("%-4d", card[i][j]);
                }
            }
            printf("\n");
        }
        
        // Get user input for called number
        printf("\nType the number that was called: ");
        scanf("%d", &num);
        
        if (num < 1 || num > 75) // Validate input
        {
            printf("Invalid number.\n");
            continue;
        }
        
        if (numbers[num] == 1) // Check if number has already been called
        {
            printf("Number %d has already been called.\n", num);
            continue;
        }
        
        // Mark number as called and increment count
        numbers[num] = 1;
        count++;
        
        // Check if number is on the card and mark it if it is
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (card[i][j] == num)
                {
                    card[i][j] = 'X';
                }
            }
        }
        
        // Check if card has a winning pattern
        if (card[0][0] == 'X' && card[0][1] == 'X' && card[0][2] == 'X' && card[0][3] == 'X' && card[0][4] == 'X')
        {
            printf("You have won! Horizontal line in top row.\n");
            break;
        }
        else if (card[1][0] == 'X' && card[1][1] == 'X' && card[1][2] == 'X' && card[1][3] == 'X' && card[1][4] == 'X')
        {
            printf("You have won! Horizontal line in second row.\n");
            break;
        }
        else if (card[2][0] == 'X' && card[2][1] == 'X' && card[2][2] == 'X' && card[2][3] == 'X' && card[2][4] == 'X')
        {
            printf("You have won! Horizontal line in third row.\n");
            break;
        }
        else if (card[3][0] == 'X' && card[3][1] == 'X' && card[3][2] == 'X' && card[3][3] == 'X' && card[3][4] == 'X')
        {
            printf("You have won! Horizontal line in fourth row.\n");
            break;
        }
        else if (card[4][0] == 'X' && card[4][1] == 'X' && card[4][2] == 'X' && card[4][3] == 'X' && card[4][4] == 'X')
        {
            printf("You have won! Horizontal line in bottom row.\n");
            break;
        }
        else if (card[0][0] == 'X' && card[1][0] == 'X' && card[2][0] == 'X' && card[3][0] == 'X' && card[4][0] == 'X')
        {
            printf("You have won! Vertical line in left column.\n");
            break;
        }
        else if (card[0][1] == 'X' && card[1][1] == 'X' && card[2][1] == 'X' && card[3][1] == 'X' && card[4][1] == 'X')
        {
            printf("You have won! Vertical line in second column.\n");
            break;
        }
        else if (card[0][2] == 'X' && card[1][2] == 'X' && card[2][2] == 'X' && card[3][2] == 'X' && card[4][2] == 'X')
        {
            printf("You have won! Vertical line in third column.\n");
            break;
        }
        else if (card[0][3] == 'X' && card[1][3] == 'X' && card[2][3] == 'X' && card[3][3] == 'X' && card[4][3] == 'X')
        {
            printf("You have won! Vertical line in fourth column.\n");
            break;
        }
        else if (card[0][4] == 'X' && card[1][4] == 'X' && card[2][4] == 'X' && card[3][4] == 'X' && card[4][4] == 'X')
        {
            printf("You have won! Vertical line in right column.\n");
            break;
        }
        else if (card[0][0] == 'X' && card[1][1] == 'X' && card[2][2] == 'X' && card[3][3] == 'X' && card[4][4] == 'X')
        {
            printf("You have won! Diagonal line from top left to bottom right.\n");
            break;
        }
        else if (card[0][4] == 'X' && card[1][3] == 'X' && card[2][2] == 'X' && card[3][1] == 'X' && card[4][0] == 'X')
        {
            printf("You have won! Diagonal line from top right to bottom left.\n");
            break;
        }
        
        printf("\nPress ENTER to continue.\n");
        getchar(); // Wait for user to press Enter
    }
    
    printf("\nThanks for playing!\n");
    
    return 0;
}