//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printCard(int card[ROWS][COLS])
{
    printf("  B  I  N  G  O\n");
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(card[i][j] == -1)
            {
                printf("   ");
            }
            else
            {
                printf("%2d ", card[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    
    // randomly generate numbers for the game card
    int card[ROWS][COLS];
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(i == 2 && j == 2)
            {
                card[i][j] = -1; // free space
            }
            else
            {
                int num = rand() % 15 + j * 15 + 1;
                while(num == card[i][0] || num == card[i][1] || num == card[i][2] || num == card[i][3] || num == card[i][4])
                {
                    num = rand() % 15 + j * 15 + 1;
                }
                card[i][j] = num;
            }
        }
    }
    
    printf("Welcome to the Mind-Bending Bingo Simulator!\n");
    printf("You will be playing with this card:\n");
    
    // print the game card
    printCard(card);
    
    int numCalled;
    int called[ROWS*COLS]; // keep track of called numbers
    int numFound = 0; // keep track of how many numbers have been called and found on the card
    
    while(numFound < ROWS*COLS)
    {
        numCalled = rand() % 75 + 1;
        printf("The number called is %d\n", numCalled);
        
        // check if the called number is on the card
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(card[i][j] == numCalled)
                {
                    printf("Found %d on the card!\n", numCalled);
                    card[i][j] = -1; // mark it as found
                    numFound++;
                }
            }
        }
        
        called[numCalled-1] = 1; // mark the number as called
        
        // check if the game is over
        if(numFound == ROWS*COLS)
        {
            printf("Congratulations! You have won the game!\n");
            break;
        }
        
        // print the updated card
        printCard(card);
        
        // ask the player if they want to continue
        printf("Do you want to continue? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if(choice == 'n')
        {
            printf("Thanks for playing!\n");
            break;
        }
        
        // check if there is still a chance to win the game
        int chance = 0;
        for(int i = 0; i < ROWS; i++)
        {
            int count = 0;
            for(int j = 0; j < COLS; j++)
            {
                if(card[i][j] == -1)
                {
                    count++;
                }
            }
            if(count == COLS-1)
            {
                chance = 1;
                break;
            }
        }
        if(!chance)
        {
            printf("Sorry, you have no chance to win the game.\n");
            break;
        }
        
    }
    
    return 0;
}