//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define FREE_SPACE 12

// Function to check if the number has already been called
int check_called_number(int number, int called_numbers[], int counter)
{
    for(int i = 0; i <= counter; i++)
    {
        if(number == called_numbers[i])
        {
            return 0;
        }
    }
    
    return 1;
}

// Function to check if a player has won the game
int check_win(int player_number[], int called_numbers[], int counter)
{
    int row_flag, col_flag, diag1_flag = 1, diag2_flag = 1;
    
    // Check for each row
    for(int i = 0; i < ROWS; i++)
    {
        row_flag = 1;
        
        for(int j = 0; j < COLS; j++)
        {
            if(check_called_number(player_number[(i*COLS)+j], called_numbers, counter) == 0)
            {
                row_flag = 0;
            }
        }
        
        if(row_flag == 1)
        {
            return 1;
        }
    }
    
    // Check for each column
    for(int i = 0; i < COLS; i++)
    {
        col_flag = 1;
        
        for(int j = 0; j < ROWS; j++)
        {
            if(check_called_number(player_number[(j*COLS)+i], called_numbers, counter) == 0)
            {
                col_flag = 0;
            }
        }
        
        if(col_flag == 1)
        {
            return 1;
        }
    }
    
    // Check for diagonal 1
    for(int i = 0; i < ROWS; i++)
    {
        if(check_called_number(player_number[(i*COLS)+i], called_numbers, counter) == 0)
        {
            diag1_flag = 0;
        }
    }
    
    if(diag1_flag == 1)
    {
        return 1;
    }
    
    // Check for diagonal 2
    for(int i = 0; i < ROWS; i++)
    {
        if(check_called_number(player_number[(i*COLS)+(COLS-i-1)], called_numbers, counter) == 0)
        {
            diag2_flag = 0;
        }
    }
    
    if(diag2_flag == 1)
    {
        return 1;
    }
    
    // No win condition has been met yet
    return 0;
}

int main()
{
    int player1[ROWS*COLS], player2[ROWS*COLS], called_numbers[ROWS*COLS-FREE_SPACE], winner = 0, counter = -1, game_over = 0, choice;
    
    // Initialize the player boards with random numbers
    srand(time(0));
    
    for(int i = 0; i < ROWS*COLS; i++)
    {
        player1[i] = rand()%75 + 1;
        player2[i] = rand()%75 + 1;
        
        while(check_called_number(player1[i], called_numbers, counter) == 0)
        {
            player1[i] = rand()%75 + 1;
        }
        
        while(check_called_number(player2[i], called_numbers, counter) == 0)
        {
            player2[i] = rand()%75 + 1;
        }
    }
    
    // Game loop
    while(game_over == 0)
    {
        // Show the player boards
        printf("\n\nPlayer 1\t\tPlayer 2\n");
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                printf("%d\t", player1[(i*COLS)+j]);
            }
            
            printf("\t\t");
            
            for(int j = 0; j < COLS; j++)
            {
                printf("%d\t", player2[(i*COLS)+j]);
            }
            
            printf("\n");
        }
        
        // Ask the player for input
        printf("\n\nEnter your choice:\n1. Call a number\n2. Quit the game\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
            {
                // Generate a random number and check if it has already been called
                int number = rand()%75 + 1;
                
                while(check_called_number(number, called_numbers, counter) == 0)
                {
                    number = rand()%75 + 1;
                }
                
                // Update the called numbers array and the counter
                counter++;
                called_numbers[counter] = number;
                
                // Show the called numbers to the players
                printf("\nCalled numbers:\n");
                for(int i = 0; i <= counter; i++)
                {
                    printf("%d ", called_numbers[i]);
                }
                
                // Update the player boards if necessary and check for a win
                for(int i = 0; i < ROWS*COLS; i++)
                {
                    if(player1[i] == number)
                    {
                        player1[i] = 0;
                        
                        if(check_win(player1, called_numbers, counter) == 1)
                        {
                            winner = 1;
                            game_over = 1;
                            break;
                        }
                    }
                    
                    if(player2[i] == number)
                    {
                        player2[i] = 0;
                        
                        if(check_win(player2, called_numbers, counter) == 1)
                        {
                            winner = 2;
                            game_over = 1;
                            break;
                        }
                    }
                }
                
                break;
            }
            
            case 2:
            {
                game_over = 1;
                break;
            }
            
            default:
            {
                printf("\nInvalid choice. Try again.\n");
                break;
            }
        }
    }
    
    // Show the winner
    if(winner == 1)
    {
        printf("\nPlayer 1 wins!\n");
    }
    else if(winner == 2)
    {
        printf("\nPlayer 2 wins!\n");
    }
    else
    {
        printf("\nThanks for playing!\n");
    }
    
    return 0;
}