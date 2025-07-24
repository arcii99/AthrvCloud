//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int board[5][5];
    int row, col;
    int i, j;
    int numList[25];
    int count = 0;
    char input;

    srand(time(NULL));

    printf("------- BINGO SIMULATOR -------\n");
    printf("Press enter to start playing!\n");

    while(input != '\n')
    {
        input = getchar();
    }

    // Initialize board with random numbers
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            if(i == 2 && j == 2) // Set middle space to 0
            {
                board[i][j] = 0;
            }
            else
            {
                board[i][j] = rand() % 75 + 1;

                // Check for duplicates and generate a new number
                for(int k=0; k<count; k++)
                {
                    if(board[i][j] == numList[k])
                    {
                        board[i][j] = rand() % 75 + 1;
                        k = -1;
                    }
                }

                // Add generated number to numList
                numList[count] = board[i][j];
                count++;
            }
        }
    }

    // Display board
    printf("\n\n");

    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%2d ", board[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");

    // Play game
    while(1)
    {
        printf("Enter a number (1-75): ");
        scanf("%d", &numList[count]);

        // Check for duplicate inputs
        for(i=0; i<count; i++)
        {
            if(numList[count] == numList[i])
            {
                printf("Number already called. Please enter a different number\n");
                break;
            }
        }

        // Check board for entered number
        for(row=0; row<5; row++)
        {
            for(col=0; col<5; col++)
            {
                if(board[row][col] == numList[count])
                {
                    board[row][col] = 0; // Mark number as played

                    // Display updated board
                    printf("\n\n");

                    for(i=0; i<5; i++)
                    {
                        for(j=0; j<5; j++)
                        {
                            printf("%2d ", board[i][j]);
                        }

                        printf("\n");
                    }

                    printf("\n\n");

                    // Check for win
                    if((board[row][0] == 0 && board[row][1] == 0 && board[row][2] == 0 && board[row][3] == 0 && board[row][4] == 0) || 
                        (board[0][col] == 0 && board[1][col] == 0 && board[2][col] == 0 && board[3][col] == 0 && board[4][col] == 0) ||
                        (board[0][0] == 0 && board[1][1] == 0 && board[2][2] == 0 && board[3][3] == 0 && board[4][4] == 0) ||
                        (board[0][4] == 0 && board[1][3] == 0 && board[2][2] == 0 && board[3][1] == 0 && board[4][0] == 0))
                    {
                        printf("BINGO! You win!\n");
                        exit(0);
                    }

                    break;
                }
            }

            if(col != 5)
            {
                break;
            }
        }

        count++; // Increment count of valid inputs
    }

    return 0;
}