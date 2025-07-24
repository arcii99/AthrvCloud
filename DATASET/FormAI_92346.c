//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printCard(int card[ROWS][COLS])
{
    printf("--------------------------\n");
    for(int i = 0; i < ROWS; i++)
    {
        printf("| ");
        for(int j = 0; j < COLS; j++)
        {
            if(card[i][j] == 0)
                printf("  ");
            else
                printf("%2d", card[i][j]);

            printf(" | ");
        }
        printf("\n--------------------------\n");
    }
}

int main() 
{
    //initialize card with 0s
    int card[ROWS][COLS] = {0};

    //populate card with random numbers
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            //make sure each column only has numbers within a specific range
            switch(j)
            {
                case 0: //column B
                    card[i][j] = rand() % 15 + 1;
                    break;
                case 1: //column I
                    card[i][j] = rand() % 15 + 16;
                    break;
                case 2: //column N
                    if(i == 2) //middle N number is always 0
                        card[i][j] = 0;
                    else
                        card[i][j] = rand() % 15 + 31;
                    break;
                case 3: //column G
                    card[i][j] = rand() % 15 + 46;
                    break;
                case 4: //column O
                    card[i][j] = rand() % 15 + 61;
                    break;
            }
        }
    }

    //print out the randomly generated card
    printCard(card);

    //simulate bingo game
    int num;
    int bingo = 0;
    int count = 0;
    srand(time(0)); //seed random number generator

    while(!bingo)
    {
        num = rand() % 75 + 1; //generate a random number between 1 and 75

        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(card[i][j] == num) //if the number is on the card
                {
                    card[i][j] = 0; //mark it off
                    count++;

                    //check for bingo
                    if(i == 0 && j == 0) //top left corner
                    {
                        if((card[0][1] == 0 && card[0][2] == 0 && card[0][3] == 0 && card[0][4] == 0) ||
                           (card[1][0] == 0 && card[2][0] == 0 && card[3][0] == 0 && card[4][0] == 0) ||
                           (card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0))
                            bingo = 1;
                    }
                    else if(i == 0 && j == 4) //top right corner
                    {
                        if((card[0][3] == 0 && card[0][2] == 0 && card[0][1] == 0 && card[0][0] == 0) ||
                           (card[1][4] == 0 && card[2][4] == 0 && card[3][4] == 0 && card[4][4] == 0) ||
                           (card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0))
                            bingo = 1;
                    }
                    else if(i == 4 && j == 0) //bottom left corner
                    {
                        if((card[3][0] == 0 && card[2][0] == 0 && card[1][0] == 0 && card[0][0] == 0) ||
                           (card[4][1] == 0 && card[4][2] == 0 && card[4][3] == 0 && card[4][4] == 0) ||
                           (card[3][1] == 0 && card[2][2] == 0 && card[1][3] == 0 && card[0][4] == 0))
                            bingo = 1;
                    }
                    else if(i == 4 && j == 4) //bottom right corner
                    {
                        if((card[3][4] == 0 && card[2][4] == 0 && card[1][4] == 0 && card[0][4] == 0) ||
                           (card[4][3] == 0 && card[4][2] == 0 && card[4][1] == 0 && card[4][0] == 0) ||
                           (card[3][3] == 0 && card[2][2] == 0 && card[1][1] == 0 && card[0][0] == 0))
                            bingo = 1;
                    }
                    else if(i == 0) //top row
                    {
                        if((card[0][1] == 0 && card[0][2] == 0 && card[0][3] == 0 && card[0][4] == 0))
                            bingo = 1;
                    }
                    else if(i == 4) //bottom row
                    {
                        if((card[4][1] == 0 && card[4][2] == 0 && card[4][3] == 0 && card[4][4] == 0))
                            bingo = 1;
                    }
                    else if(j == 0) //left column
                    {
                        if((card[1][0] == 0 && card[2][0] == 0 && card[3][0] == 0 && card[4][0] == 0))
                            bingo = 1;
                    }
                    else if(j == 4) //right column
                    {
                        if((card[1][4] == 0 && card[2][4] == 0 && card[3][4] == 0 && card[4][4] == 0))
                            bingo = 1;
                    }
                    else if(i == j) //diagonal
                    {
                        if((card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0) ||
                           (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0))
                            bingo = 1;
                    }
                    else if(i + j == 4) //other diagonal
                    {
                        if((card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0) ||
                           (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0))
                            bingo = 1;
                    }
                }
            }
        }
        
        printf("\nNumber drawn: %d\n\n", num);
        printCard(card);
    }

    //print out number of balls drawn before bingo was achieved
    printf("\n\nBINGO!!!\n\n");
    printf("It took %d balls to achieve BINGO.\n", count);

    return 0;
}