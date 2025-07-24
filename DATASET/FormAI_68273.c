//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// The following function generates the Bingo board, which includes 25 integers ranging from 1 to 75.
void generate_board(int *board) 
{
    int i, j, k = 1;

    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
            if (i == 2 && j == 2)
            {
                board[k-1] = 0;
            }
            else
            {
                board[k-1] = k * (rand() % 15 + 1);
                k++;
            }       
        }
    }
}

// The following function displays the Bingo board that was generated.
void display_board(int *board) 
{
    int i, j;

    printf("\n\tB \tI \tN \tG \tO");

    for(i = 0; i < 5; i++) 
    {
        printf("\n");
        for(j = 0; j < 5; j++) 
        {
            if (i == 2 && j == 2) 
            {
                printf("\t ");
            }
            else 
            {
                printf("\t%d", board[i*5+j]);
            }           
        }       
    }
    printf("\n");
}

// The following function determines if the input number is on the board.
int is_on_board(int *board, int number) 
{
    int i;

    for (i = 0; i < 25; i++) 
    {
        if (board[i] == number) 
        {
            board[i] = 0;
            return 1;
        }
    }
    return 0;
}

int main() 
{
    int board[25];
    int number_drawn;
    int numbers_drawn[75] = {0};
    int i = 0, row, col, diagonal1 = 0, diagonal2 = 0;
    char play_again = 'y';

    srand(time(0));

    // Welcome message
    printf("Welcome to the Bingo Simulator!\n");

    // The game can continue until the user doesn't want to play anymore.
    while (play_again == 'y' || play_again == 'Y') 
    {
        // Generate a new board.
        generate_board(board);
        // Display the board
        display_board(board);

        // The game will continue until there is a Bingo or all of the spaces have been filled in.
        while (i < 25) 
        {
            // Generate a random number that hasn't been seen before.
            do 
            {
                number_drawn = rand() % 75 + 1;
            } while (numbers_drawn[number_drawn-1] == 1);
            // Mark that number as drawn.
            numbers_drawn[number_drawn-1] = 1;

            printf("The number drawn is: %d\n", number_drawn);

            if (is_on_board(board, number_drawn)) 
            {
                printf("That number is on your board!\n");

                // Determine if there is a horizontal row.
                for (row = 0; row < 5; row++) 
                {
                    int row_sum = 0;
                    for (col = 0; col < 5; col++) 
                    {
                        row_sum += board[row*5+col];
                    }
                    if (row_sum == 0) 
                    {
                        printf("You have a horizontal row!\n");
                        i = 25;
                        break;
                    }
                }

                // Determine if there is a vertical row.
                for (col = 0; col < 5; col++) 
                {
                    int col_sum = 0;
                    for (row = 0; row < 5; row++) 
                    {
                        col_sum += board[row*5+col];
                    }
                    if (col_sum == 0) 
                    {
                        printf("You have a vertical row!\n");
                        i = 25;
                        break;
                    }
                }

                // Determine if there is a diagonal row (top-left to bottom-right).
                for (row = 0; row < 5; row++) 
                {
                    diagonal1 += board[row*5+row];
                }
                if (diagonal1 == 0) 
                {
                    printf("You have a diagonal row (top-left to bottom-right)!\n");
                    i = 25;
                    break;
                }

                // Determine if there is a diagonal row (bottom-left to top-right).
                for (row = 0; row < 5; row++) 
                {
                    diagonal2 += board[(4-row)*5+row];
                }
                if (diagonal2 == 0) 
                {
                    printf("You have a diagonal row (bottom-left to top-right)!\n");
                    i = 25;
                    break;
                }
            } 
            else 
            {
                printf("That number is not on your board.\n");
            }

            i++;
        }
        if (i == 25) 
        {
            printf("BINGO!!! You have won!\n");
        } 
        else 
        {
            printf("Sorry, you didn't win this time :( \n");
        }

        // Ask if the user wants to play again.
        printf("Do you want to play again? (y/n)");
        getchar();
        scanf("%c", &play_again);
        getchar();
    }

    printf("Thank you for playing the Bingo Simulator!\n");
    return 0;
}