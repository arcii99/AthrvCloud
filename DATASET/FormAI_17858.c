//FormAI DATASET v1.0 Category: Robot movement control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVES 20

int main()
{
    srand(time(NULL));
    int moves[MAX_MOVES];
    int i, moveCount;

    // generate random moves
    for(i=0; i<MAX_MOVES; i++)
    {
        moves[i] = rand()%4; //randomly choose 0-3 for up, down, left, right respectively 
    }

    printf("The robot will perform the following moves:\n");
    for(i=0; i<MAX_MOVES; i++)
    {
        switch(moves[i])
        {
            case 0:
                printf("Up\n");
                break;
            case 1:
                printf("Down\n");
                break;
            case 2:
                printf("Left\n");
                break;
            case 3:
                printf("Right\n");
                break;
        }
    }

    // execute moves
    int xPos = 0, yPos = 0; //starting position
    moveCount = 0;
    while(moveCount < MAX_MOVES)
    {
        switch(moves[moveCount])
        {
            case 0: //up
                yPos++;
                break;
            case 1: //down
                yPos--;
                break;
            case 2: //left
                xPos--;
                break;
            case 3: //right
                xPos++;
                break;
        }
        moveCount++;
        printf("(%d, %d)\n", xPos, yPos); //output new position after each move
    }

    return 0;
}