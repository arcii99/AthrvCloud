//FormAI DATASET v1.0 Category: Table Game ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initialize random seed
    srand(time(NULL));
    
    //initialize board size and players
    int board[10] = {0}; //board size of 10
    int player1_position = 0;
    int player2_position = 0;
    
    printf("Welcome to C Table Game!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n\n");
    
    while (player1_position != 9 && player2_position != 9)
    {
        //player 1 turn
        printf("Player 1's turn:\n");
        int dice_roll = rand() % 6 + 1;
        printf("You rolled a %d!\n", dice_roll);
        player1_position += dice_roll;
        if (player1_position > 9)
        {
            int overshoot = player1_position - 9;
            player1_position = 9 - overshoot;
        }
        board[player1_position] = 1;
        
        //print board
        printf("\nCurrent Board:\n");
        for (int i = 0; i < 10; i++)
        {
            if (board[i] == 1)
            {
                printf("| X ");
            }
            else if (board[i] == 2)
            {
                printf("| O ");
            }
            else
            {
                printf("|   ");
            }
        }
        printf("|\n\n");
        
        //check if player 1 won
        if (player1_position == 9)
        {
            printf("Player 1 wins!\n");
            break;
        }
        
        //player 2 turn
        printf("Player 2's turn:\n");
        dice_roll = rand() % 6 + 1;
        printf("You rolled a %d!\n", dice_roll);
        player2_position += dice_roll;
        if (player2_position > 9)
        {
            int overshoot = player2_position - 9;
            player2_position = 9 - overshoot;
        }
        board[player2_position] = 2;
        
        //print board
        printf("\nCurrent Board:\n");
        for (int i = 0; i < 10; i++)
        {
            if (board[i] == 1)
            {
                printf("| X ");
            }
            else if (board[i] == 2)
            {
                printf("| O ");
            }
            else
            {
                printf("|   ");
            }
        }
        printf("|\n\n");
        
        //check if player 2 won
        if (player2_position == 9)
        {
            printf("Player 2 wins!\n");
            break;
        }
    }
    
    return 0;
}