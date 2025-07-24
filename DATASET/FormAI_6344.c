//FormAI DATASET v1.0 Category: Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k;
    time_t t;

    //Initializing random number generator
    srand((unsigned)time(&t));

    //Creating the game board
    int board[3][3];
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            board[i][j] = rand() % 2;
        }
    }

    //Printing the initial game board
    printf("Initial Board:\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    //Checking and updating the game board
    for(k=0; k<3; k++)
    {
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                int neighbors = 0;

                //Checking the left neighbor
                if(j-1 >= 0 && board[i][j-1] == 1)
                {
                    neighbors++;
                }

                //Checking the right neighbor
                if(j+1 < 3 && board[i][j+1] == 1)
                {
                    neighbors++;
                }

                //Checking the top neighbor
                if(i-1 >= 0 && board[i-1][j] == 1)
                {
                    neighbors++;
                }

                //Checking the bottom neighbor
                if(i+1 < 3 && board[i+1][j] == 1)
                {
                    neighbors++;
                }

                //Updating the cell based on the number of neighbors
                if(board[i][j] == 1 && (neighbors < 2 || neighbors > 3))
                {
                    board[i][j] = 0;
                }
                else if(board[i][j] == 0 && neighbors == 3)
                {
                    board[i][j] = 1;
                }
            }
        }

        //Printing the updated game board after each round
        printf("\nAfter round %d:\n", k+1);
        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}