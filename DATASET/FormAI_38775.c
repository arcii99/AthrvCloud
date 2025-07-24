//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 20

// Function to print game board
void print_board(int game_board[MAX_ROWS][MAX_COLS], int player_row, int player_col)
{
    int i, j;
    printf("\n");
    for(i=0; i<MAX_ROWS; i++)
    {
        for(j=0; j<MAX_COLS; j++)
        {
            if(i==player_row && j==player_col)
                printf("@ ");
            else if(game_board[i][j]==0)
                printf("# ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

// Function for procedural generation of game board
void generate_board(int game_board[MAX_ROWS][MAX_COLS])
{
    srand(time(NULL)); // Seed for random number generator
    int i, j, random_num;
    for(i=0; i<MAX_ROWS; i++)
    {
        for(j=0; j<MAX_COLS; j++)
        {
            random_num = rand() % 5; // Random number between 0 and 4
            if(random_num == 0)
                game_board[i][j] = 0; // Wall
            else
                game_board[i][j] = 1; // Path
        }
    }
}

int main()
{
    int game_board[MAX_ROWS][MAX_COLS];
    generate_board(game_board); // Generate game board
    // Player starts in top left corner
    int player_row = 0;
    int player_col = 0;
    char move;
    printf("Welcome to Rogue-like game!\n");
    do
    {
        print_board(game_board, player_row, player_col); // Print game board
        printf("\nUse wasd keys to move or q to quit: ");
        scanf("%c", &move);
        switch(move)
        {
            case 'w':
                if(player_row-1 >= 0 && game_board[player_row-1][player_col]==1)
                    player_row--;
                break;
            case 'a':
                if(player_col-1 >= 0 && game_board[player_row][player_col-1]==1)
                    player_col--;
                break;
            case 's':
                if(player_row+1 < MAX_ROWS && game_board[player_row+1][player_col]==1)
                    player_row++;
                break;
            case 'd':
                if(player_col+1 < MAX_COLS && game_board[player_row][player_col+1]==1)
                    player_col++;
                break;
        }
        fflush(stdin); // Clear input buffer
    } while(move != 'q'); // Repeat until user quits
    return 0;
}