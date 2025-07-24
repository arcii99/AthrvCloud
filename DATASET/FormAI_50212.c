//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10     //Number of rows in game grid
#define COLUMNS 10  //Number of columns in game grid
#define MINES 10    //Number of mines

//Function to initialize game grid with mines and numbers
void initialize(char gameGrid[ROWS][COLUMNS], char solutionGrid[ROWS][COLUMNS])
{
    int i, j, mineCount = 0;
    srand(time(0)); //Set random seed
    
    //Empty both grids
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLUMNS; j++)
        {
            gameGrid[i][j] = '-';
            solutionGrid[i][j] = '-';
        }
    }
    
    //Add mines to solution grid
    while(mineCount < MINES)
    {
        i = rand() % ROWS;
        j = rand() % COLUMNS;
        if(solutionGrid[i][j] != '*')
        {
            solutionGrid[i][j] = '*';
            mineCount++;
        }
    }
    
    //Add numbers to solution grid
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLUMNS; j++)
        {
            if(solutionGrid[i][j] == '-')
            {
                int mineCount = 0;
                if(i > 0 && j > 0 && solutionGrid[i-1][j-1] == '*')
                    mineCount++;
                if(i > 0 && solutionGrid[i-1][j] == '*')
                    mineCount++;
                if(i > 0 && j < COLUMNS-1 && solutionGrid[i-1][j+1] == '*')
                    mineCount++;
                if(j < COLUMNS-1 && solutionGrid[i][j+1] == '*')
                    mineCount++;
                if(i < ROWS-1 && j < COLUMNS-1 && solutionGrid[i+1][j+1] == '*')
                    mineCount++;
                if(i < ROWS-1 && solutionGrid[i+1][j] == '*')
                    mineCount++;
                if(i < ROWS-1 && j > 0 && solutionGrid[i+1][j-1] == '*')
                    mineCount++;
                if(j > 0 && solutionGrid[i][j-1] == '*')
                    mineCount++;
                if(mineCount > 0)
                    solutionGrid[i][j] = mineCount + '0';
            }
        }
    }
}

int main()
{
    char gameGrid[ROWS][COLUMNS], solutionGrid[ROWS][COLUMNS];
    int i, j, remaining = ROWS*COLUMNS - MINES;
    initialize(gameGrid, solutionGrid);
    
    //Print game rules
    printf("Welcome to Minesweeper!\n");
    printf("Your goal is to reveal all spaces without detonating any mines.\n");
    printf("A number in a square indicates how many mines are in the eight surrounding squares.\n");
    printf("Select a square by entering its coordinates (row, column), separated by a space.\n");
    printf("Uncover a square by entering 'u' followed by the coordinates.\n");
    printf("Mark a square as a mine by entering 'm' followed by the coordinates.\n");
    
    //Game loop
    while(remaining > 0)
    {
        //Print game grid
        printf("\n  ");
        for(j = 0; j < COLUMNS; j++)
            printf("%d ", j);
        printf("\n");
        for(i = 0; i < ROWS; i++)
        {
            printf("%d ", i);
            for(j = 0; j < COLUMNS; j++)
                printf("%c ", gameGrid[i][j]);
            printf("\n");
        }
        
        //Get user input
        char action, space;
        int row, column;
        printf("Enter an action and coordinates: ");
        scanf(" %c%c%d%c%d", &action, &space, &row, &space, &column);
        
        //Check user input
        if(row < 0 || row >= ROWS || column < 0 || column >= COLUMNS)
        {
            printf("Invalid coordinates.\n");
            continue;
        }
        if(gameGrid[row][column] != '-' && action == 'u')
        {
            printf("Space already uncovered.\n");
            continue;
        }
        if(gameGrid[row][column] == 'F' && action == 'u')
        {
            printf("Space marked as flag. Unmark with 'm'.\n");
            continue;
        }
        if(gameGrid[row][column] != '-' && action == 'm')
        {
            printf("Space already marked as flag. Unmark with 'm'.\n");
            continue;
        }
        if(action != 'u' && action != 'm')
        {
            printf("Invalid action.\n");
            continue;
        }
        
        //Process user action
        if(action == 'u')
        {
            if(solutionGrid[row][column] == '*')
            {
                printf("BOOM! Game over. You hit a mine.\n");
                for(i = 0; i < ROWS; i++)
                {
                    for(j = 0; j < COLUMNS; j++)
                    {
                        if(solutionGrid[i][j] == '*' && gameGrid[i][j] != 'F')
                            gameGrid[i][j] = '*';
                    }
                }
                break;
            }
            else
            {
                gameGrid[row][column] = solutionGrid[row][column];
                remaining--;
            }
        }
        else
        {
            gameGrid[row][column] = 'F';
        }
    }
    
    //Print solution grid
    printf("\n  ");
    for(j = 0; j < COLUMNS; j++)
        printf("%d ", j);
    printf("\n");
    for(i = 0; i < ROWS; i++)
    {
        printf("%d ", i);
        for(j = 0; j < COLUMNS; j++)
            printf("%c ", solutionGrid[i][j]);
        printf("\n");
    }
    
    //Print game outcome
    if(remaining == 0)
        printf("Congratulations! You won the game.\n");
        
    return 0;
}