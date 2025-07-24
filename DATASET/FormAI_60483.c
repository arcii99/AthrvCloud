//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int random_num(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int main()
{
    char house[ROWS][COLS] = { "||||||||||",
                               "|........|",
                               "|........|",
                               "|........|",
                               "|........|",
                               "|........|",
                               "|........|",
                               "|........|",
                               "|........|",
                               "||||||||||" };
    int player_row = 1;
    int player_col = 1;
    int ghost_row = 8;
    int ghost_col = 8;
    int key_row = 3;
    int key_col = 3;
    int steps = 0;
    int has_key = 0;
    int is_ghost_here = 0;
    srand(time(0)); // for random events
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Escape the house without getting caught by the ghost.\nCollect the key to unlock the door.\n\n");
    
    while (1)
    {
        // print the house
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (player_row == i && player_col == j) // player
                    printf("@");
                else if (ghost_row == i && ghost_col == j && is_ghost_here) // ghost
                    printf("G");
                else if (key_row == i && key_col == j && !has_key) // key
                    printf("K");
                else
                    printf("%c", house[i][j]);
            }
            printf("\n");
        }
        
        // check if player has won or lost
        if (player_row == ROWS-2 && player_col == COLS-2 && has_key)
        {
            printf("\nCongratulations! You have escaped the haunted house!\n");
            break;
        }
        else if (player_row == ghost_row && player_col == ghost_col)
        {
            printf("\nGame over! You have been caught by the ghost.\n");
            break;
        }
        
        // get user input
        char input;
        printf("Enter your move (W/A/S/D) or Q to quit: ");
        scanf(" %c", &input);
        printf("\n");
        
        // handle user input
        switch (input)
        {
            case 'W':
            case 'w':
                if (house[player_row-1][player_col] == '.' || house[player_row-1][player_col] == '|')
                    break;
                player_row--;
                steps++;
                break;
                
            case 'A':
            case 'a':
                if (house[player_row][player_col-1] == '.' || house[player_row][player_col-1] == '|')
                    break;
                player_col--;
                steps++;
                break;
                
            case 'S':
            case 's':
                if (house[player_row+1][player_col] == '.' || house[player_row+1][player_col] == '|')
                    break;
                player_row++;
                steps++;
                break;
                
            case 'D':
            case 'd':
                if (house[player_row][player_col+1] == '.' || house[player_row][player_col+1] == '|')
                    break;
                player_col++;
                steps++;
                break;
                
            case 'Q':
            case 'q':
                printf("\nThanks for playing!\n");
                exit(0);
                
            default:
                printf("Invalid input, try again.\n");
                break;
        }
        
        // check for random events
        int event = random_num(1, 10); // random number from 1 to 10
        if (event == 1 && !is_ghost_here) // ghost event
        {
            ghost_row = random_num(1, ROWS-2); // random row (except first and last)
            ghost_col = random_num(1, COLS-2); // random column (except first and last)
            is_ghost_here = 1;
            printf("\nWARNING! You feel a cold chill down your spine...\n");
        }
        else if (event == 2 && !has_key) // key event
        {
            key_row = random_num(1, ROWS-2); // random row (except first and last)
            key_col = random_num(1, COLS-2); // random column (except first and last)
            printf("\nYou found a key!\n");
        }
        
        // handle ghost movement
        if (is_ghost_here)
        {
            int ghost_move = random_num(1, 4); // random number from 1 to 4
            switch (ghost_move)
            {
                case 1: // move up
                    if (ghost_row > 1 && house[ghost_row-1][ghost_col] != '|')
                        ghost_row--;
                    break;
                    
                case 2: // move left
                    if (ghost_col > 1 && house[ghost_row][ghost_col-1] != '|')
                        ghost_col--;
                    break;
                    
                case 3: // move down
                    if (ghost_row < ROWS-2 && house[ghost_row+1][ghost_col] != '|')
                        ghost_row++;
                    break;
                    
                case 4: // move right
                    if (ghost_col < COLS-2 && house[ghost_row][ghost_col+1] != '|')
                        ghost_col++;
                    break;
            }
        }
        
        // check if player got the key
        if (player_row == key_row && player_col == key_col && !has_key)
        {
            has_key = 1;
            printf("\nYou picked up the key!\n");
        }
        
        // clear screen
        system("clear");
    }
    
    printf("You took %d steps.\n", steps);
    
    return 0;
}