//FormAI DATASET v1.0 Category: Robot movement control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10 //number of rows in the grid
#define COLS 10 //number of columns in the grid
#define MAX_MOVES 20 //maximum number of moves allowed for each player

//function prototype for movement function
void move_robot(char grid[][COLS], int row, int col, int move);

int main()
{
    char grid[ROWS][COLS]; //create empty grid

    srand(time(NULL)); //seed random number generator

    //initialize grid with empty space character
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            grid[i][j] = ' ';
        }
    }

    //place robots randomly in the grid
    int robot1_row = rand() % ROWS;
    int robot1_col = rand() % COLS;
    grid[robot1_row][robot1_col] = '1';

    int robot2_row = rand() % ROWS;
    int robot2_col = rand() % COLS;
    while(grid[robot2_row][robot2_col] == '1') //make sure robot 2 doesn't overlap with robot 1
    {
        robot2_row = rand() % ROWS;
        robot2_col = rand() % COLS;
    }
    grid[robot2_row][robot2_col] = '2';

    int moves_left = MAX_MOVES; //initialize number of moves left for each player

    //start game loop
    while(moves_left > 0)
    {
        //player 1's turn
        printf("\nPlayer 1's turn (%d moves left)\n", moves_left);
        int move = rand() % 4; //randomly select a movement direction
        move_robot(grid, robot1_row, robot1_col, move);
        if(grid[robot1_row][robot1_col] == '2') //check if player 1 landed on player 2's robot
        {
            printf("\nPlayer 1 has won!\n");
            break;
        }
        printf("\nPlayer 1's new position: (%d,%d)\n", robot1_row, robot1_col);
        moves_left--;

        //player 2's turn
        printf("\nPlayer 2's turn (%d moves left)\n", moves_left);
        move = rand() % 4; //randomly select a movement direction
        move_robot(grid, robot2_row, robot2_col, move);
        if(grid[robot2_row][robot2_col] == '1') //check if player 2 landed on player 1's robot
        {
            printf("\nPlayer 2 has won!\n");
            break;
        }
        printf("\nPlayer 2's new position: (%d,%d)\n", robot2_row, robot2_col);
        moves_left--;
    }

    //game over
    printf("\nGame over!\n");
    printf("\nFinal grid state:\n");
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//function definition for movement function
void move_robot(char grid[][COLS], int row, int col, int move)
{
    switch(move)
    {
        case 0: //move up
            if(row > 0 && grid[row-1][col] == ' ') //make sure robot doesn't go out of bounds or overlap with another robot
            {
                grid[row][col] = ' ';
                grid[row-1][col] = '1';
                row--;
            }
            break;
        case 1: //move down
            if(row < ROWS-1 && grid[row+1][col] == ' ')
            {
                grid[row][col] = ' ';
                grid[row+1][col] = '1';
                row++;
            }
            break;
        case 2: //move left
            if(col > 0 && grid[row][col-1] == ' ')
            {
                grid[row][col] = ' ';
                grid[row][col-1] = '1';
                col--;
            }
            break;
        case 3: //move right
            if(col < COLS-1 && grid[row][col+1] == ' ')
            {
                grid[row][col] = ' ';
                grid[row][col+1] = '1';
                col++;
            }
            break;
        default: //invalid move
            break;
    }
}