//FormAI DATASET v1.0 Category: Table Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayTable(int *table, int size)
{
    printf("\nCurrent Table: ");
    for (int i = 0; i < size; i++)
        printf("%d ", table[i]);
}

int rollDice()
{
    srand(time(NULL)); // seed random function
    return (rand() % 6) + 1;
}

void playGame(int *table, int size)
{
    int currentPlayer = 1;
    int currentPosition = 0;
    int dice = 0;
    
    printf("\nStarting game with %d players", size);
    
    while (currentPosition < size - 1)
    {
        printf("\n\n*** Player %d's Turn ***", currentPlayer);
        printf("\nPress enter to roll the dice...");
        getchar();
        dice = rollDice();
        printf("\nPlayer %d rolled a %d", currentPlayer, dice);
        currentPosition += dice;
        
        // player lands on a special tile
        if (table[currentPosition] != 0 && table[currentPosition] != currentPosition)
        {
            printf("\nPlayer %d landed on a special tile, move to position %d", currentPlayer, table[currentPosition]);
            currentPosition = table[currentPosition];
        }
        
        // player lands on last tile
        if (currentPosition == size - 1)
        {
            printf("\nPlayer %d reached the end of the table and wins!", currentPlayer);
            return;
        }
        
        // switch to next player
        currentPlayer = ((currentPlayer + 1) % size == 0) ? size : (currentPlayer + 1) % size;
        displayTable(table, size);
    }
}

int main()
{
    int size = 6;
    int table[] = {0, 0, 8, 0, 0, 12, 0, 0, 0, 0, 18, 0, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};
    
    printf("\nWelcome to the C Table Game!");
    displayTable(table, size);
    printf("\nRules: 1. Roll dice to move forward.\n2. Land on special tiles to move to different position.\n3. Reach the end of the table first to win!");
    
    playGame(table, size);
    
    return 0;
}