//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define RANGE 75

int main()
{
    int card[ROWS][COLS];
    int i, j, count = 0, num, win = 0;
    char choice;
    srand(time(0));
    
    // Initialize all elements with 0
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            card[i][j] = 0;
        }
    }
    
    // Generate random numbers for card
    while(count < RANGE)
    {
        num = rand() % RANGE + 1;
        for(i=0; i<ROWS; i++)
        {
            for(j=0; j<COLS; j++)
            {
                if(card[i][j] == num)
                {
                    num = rand() % RANGE + 1;
                    i = -1;
                    break;
                }
            }
        }
        card[count/COLS][count%COLS] = num;
        count++;
    }
    
    // Display the card
    printf("Welcome to C Bingo Simulator!\n");
    printf("Your card is:\n");
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
    
    // Ask user to start the game
    printf("Press any key to start the game...\n");
    getchar();
    
    // Start the game
    while(win == 0)
    {
        num = rand() % RANGE + 1;
        printf("The number called is: %d\n", num);
        for(i=0; i<ROWS; i++)
        {
            for(j=0; j<COLS; j++)
            {
                if(card[i][j] == num)
                {
                    card[i][j] = 0;
                }
            }
        }
        // Check for win
        for(i=0; i<ROWS; i++)
        {
            if(card[i][0] == 0 && card[i][1] == 0 && card[i][2] == 0 && card[i][3] == 0 && card[i][4] == 0)
            {
                win = 1;
                printf("Congratulations! You have won the game!\n");
                break;
            }
            if(card[0][i] == 0 && card[1][i] == 0 && card[2][i] == 0 && card[3][i] == 0 && card[4][i] == 0)
            {
                win = 1;
                printf("Congratulations! You have won the game!\n");
                break;
            }
        }
        if(card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0)
        {
            win = 1;
            printf("Congratulations! You have won the game!\n");
            break;
        }
        if(card[4][0] == 0 && card[3][1] == 0 && card[2][2] == 0 && card[1][3] == 0 && card[0][4] == 0)
        {
            win = 1;
            printf("Congratulations! You have won the game!\n");
            break;
        }
        // Ask user to continue playing
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &choice);
        if(choice == 'n' || choice == 'N')
        {
            printf("Thanks for playing!\n");
            break;
        }
        fflush(stdin);
    }
    return 0;
}