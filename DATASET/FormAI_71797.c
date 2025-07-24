//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool ghostAppeared = false;
bool playerAlive = true;

void printScreen(int playerPosition)
{
    system("clear");
    printf("Welcome to the Haunted House Simulator!\n\n");

    for(int i=0; i<5; i++)
    {
        if(playerPosition == i)
        {
            printf("😀 ");
        }
        else
        {
            printf("   ");
        }

        if(ghostAppeared && i==2)
        {
            printf("👻");
        }

        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int playerPosition = 0;

    while(playerAlive)
    {
        printScreen(playerPosition);

        int move = rand() % 3 - 1;
        playerPosition += move;

        if(playerPosition < 0)
        {
            playerPosition = 0;
        }

        if(playerPosition > 4)
        {
            playerPosition = 4;
        }

        if(playerPosition == 2 && !ghostAppeared)
        {
            printf("\nA ghost has appeared!\n");
            ghostAppeared = true;
        }

        if(playerPosition == 2 && ghostAppeared)
        {
            printf("\nThe ghost has caught you!\nGame over.\n");
            playerAlive = false;
        }

        printf("\nPress enter to continue.\n");
        getchar();
    }

    return 0;
}