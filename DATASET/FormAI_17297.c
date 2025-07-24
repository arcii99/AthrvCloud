//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int board[5][5] = {0}, i, j, count, num, a;
    char ch;

    srand(time(NULL)); // initializing randomizer with time

    printf("\n\n\t\t\t Let's Play Bingo! \n\n\n");

    sleep(1);

    printf("Generating Ticket For You...\n");

    sleep(2);

    // Generating a random bingo ticket

    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            if(i==2 && j==2)
            {
                board[i][j] = -1; // Middle cell of the ticket
            }
            else
            {
                num = (rand() % 15) + (15*j) + 1; // Generating unique numbers for each column and saving in board
                for(a=0; a<=i; a++)
                {
                    if(num==board[a][j])
                    {
                        num = (rand() % 15) + (15*j) + 1; // Regenerating number if the number is already present in the column
                        a=-1;
                    }
                }
                board[i][j] = num;
            }
        }
    }

    printf("\n\n Here's Your Ticket: \n\n");

    sleep(1);

    // Board Display

    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            if(board[i][j]==-1) // Checking for middle element
            {
                printf("  X ");
            }
            else
            {
                printf("%3d ",board[i][j]);
            }
        }
        printf("\n\n");
    }

    sleep(1);

    printf("Are You Ready To Play? ( Press Y to Begin ) \n");

    scanf(" %c",&ch); // Taking input from user to start the game

    // Game Begins

    while(ch=='Y' || ch=='y')
    {
        num = (rand() % 75) + 1; // Generating random number for the game
        printf("\n\n The Number Is: %d \n\n", num);

        // Checking for the number in the ticket

        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                if(board[i][j] == num)
                {
                    board[i][j] = -2; // Replacing the number with -2 to indicate that it has been matched
                }
            }
        }

        // Print the updated board

        for(i=0; i<5; i++)
        {
            for(j=0; j<5; j++)
            {
                if(board[i][j] == -2)
                {
                    printf("  X ");
                }
                else if(board[i][j] == -1)
                {
                    printf("  # ");
                }
                else
                {
                    printf("%3d ",board[i][j]);
                }
                
            }
            printf("\n\n");
        }

        // Checking for winning conditions

        count = 0;

        for(i=0; i<5; i++)
        {
            if(board[i][0]==-2 && board[i][1]==-2 && board[i][2]==-2 && board[i][3]==-2 && board[i][4]==-2)
            {
                printf("\n\n\n BINGO! You Have Won the Game... \n\n\n");
                count++;
                break;
            }

            else if(board[0][i]==-2 && board[1][i]==-2 && board[2][i]==-2 && board[3][i]==-2 && board[4][i]==-2)
            {
                printf("\n\n\n BINGO! You Have Won the Game... \n\n\n");
                count++;
                break;
            }

            else if(board[0][0]==-2 && board[1][1]==-2 && board[2][2]==-2 && board[3][3]==-2 && board[4][4]==-2)
            {
                printf("\n\n\n BINGO! You Have Won the Game... \n\n\n");
                count++;
                break;
            }

            else if(board[0][4]==-2 && board[1][3]==-2 && board[2][2]==-2 && board[3][1]==-2 && board[4][0]==-2)
            {
                printf("\n\n\n BINGO! You Have Won the Game... \n\n\n");
                count++;
                break;
            }
        }

        if(count == 1)
        {
            break;
        }

        printf("Do You Want To Continue? ( Press Y to Proceed ) \n");

        scanf(" %c",&ch); // To ask user if they want to continue
    }

    printf("\n\n Thanks For Playing... \n\n");

    return 0;
}