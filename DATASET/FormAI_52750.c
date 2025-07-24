//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Functions to print Bingo card and check for a win
void displayCard(int card[5][5]);
int checkWin(int card[5][5]);

int main()
{
    srand(time(NULL)); // Seed the random number generator
 
    int card[5][5]; // Declare 5x5 array for card
    
    // Fill array with random numbers between 1 and 75
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            card[i][j] = rand() % 75 + 1;
        }
    }
    
    // Set center square to 0 (Free space)
    card[2][2] = 0;
    
    // Display card
    printf("Your Bingo card:\n");
    displayCard(card);
    
    // Game loop
    while (1)
    {
        int number = rand() % 75 + 1; // Generate random number between 1 and 75
        
        printf("The next number is: %d\n", number);
        
        // Check if number matches a number on the card
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (card[i][j] == number)
                {
                    card[i][j] = 0; // Mark the number as found
                    printf("You found the number %d!\n", number);
                }
            }
        }
        
        // Check for win
        if (checkWin(card))
        {
            printf("Bingo! You win!\n");
            break; // End game
        }
    }
    
    return 0; // End program
}

// Function to display Bingo card
void displayCard(int card[5][5])
{
    printf("--------------------\n");
    printf("| B  | I  | N  | G  | O  |\n");
    printf("--------------------\n");
    for (int i = 0; i < 5; i++)
    {
        printf("| ");
        for (int j = 0; j < 5; j++)
        {
            if (card[i][j] < 10) // Add leading space for single digit numbers
            {
                printf(" ");
            }
            printf("%d | ", card[i][j]);
        }
        printf("\n--------------------\n");
    }
}

// Function to check for a win
int checkWin(int card[5][5])
{
    // Check rows
    for (int i = 0; i < 5; i++)
    {
        if (card[i][0] == 0 && card[i][1] == 0 && card[i][2] == 0 && card[i][3] == 0 && card[i][4] == 0)
        {
            return 1; // Row win
        }
    }
    
    // Check columns
    for (int j = 0; j < 5; j++)
    {
        if (card[0][j] == 0 && card[1][j] == 0 && card[2][j] == 0 && card[3][j] == 0 && card[4][j] == 0)
        {
            return 1; // Column win
        }
    }
    
    // Check diagonals
    if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0)
    {
        return 1; // Diagonal win
    }
    if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0)
    {
        return 1; // Diagonal win
    }
    
    return 0; // No win
}