//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: minimalist
#include <stdio.h> //Contains the standard input/output library
#include <stdlib.h> //Contains the standard library
#include <time.h> //Contains functions for working with time


int main()
{
    srand(time(NULL)); //Seed the random number generator with the current time

    int bingoCard[5][5]; //Declare the 5x5 matrix that represents the bingo card

    //Fill the bingo card with random numbers from 1 to 75
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            int num = (j*15) + (rand()%15) + 1; //Generate a random number between 1 and 75
            bingoCard[i][j] = num; //Assign the number to the current position in the matrix
        }
    }

    //Replace the middle square with a 'FREE' space
    bingoCard[2][2] = 0;

    //Print out the bingo card
    printf("BINGO CARD:\n");
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(bingoCard[i][j] == 0)
            {
                printf("FREE\t"); //If the current position is the 'FREE' space, print 'FREE'
            }
            else
            {
                printf("%d\t",bingoCard[i][j]); //Otherwise, print the number in the current position
            }
        }
        printf("\n"); //Print a newline character after each row
    }

    return 0; //Exit the program
}