//FormAI DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
/**
*	Title:		C Table Game
*	Author:		[Your Name]
*	Date:		[Date]
**/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4				//size of the table

//function prototypes
void printTable(int table[][SIZE]);
int enterMove(int table[][SIZE]);
int generateRandomNumber(int min, int max);
void copyTable(int sourceTable[][SIZE], int destinationTable[][SIZE]);
void addRandomNumber(int table[][SIZE]);

int main()
{
    int table[SIZE][SIZE] = {0};
    int gameOver = 0;

    //add two random numbers at the beginning
    addRandomNumber(table);
    addRandomNumber(table);

    //print the table
    printTable(table);

    //game logic
    while(!gameOver)
    {
        //get user's move
        int move = enterMove(table);

        if(move == 0)   //left
        {
            int previousTable[SIZE][SIZE];
            copyTable(table, previousTable);
            for(int i=0; i<SIZE; i++)
            {
                int index = 0;
                for(int j=0; j<SIZE; j++)
                {
                    if(table[i][j] != 0)
                    {
                        if(index != j)
                        {
                            table[i][index] = table[i][j];
                            table[i][j] = 0;
                        }
                        if(index > 0 && table[i][index] == table[i][index-1])
                        {
                            table[i][index-1] *=2;
                            table[i][index] = 0;
                        }
                        index++;
                    }
                }
            }
            if(!compareTables(table, previousTable))
                addRandomNumber(table);
        }
        else if(move == 1)  //up
        {
            int previousTable[SIZE][SIZE];
            copyTable(table, previousTable);
            for(int j=0; j<SIZE; j++)
            {
                int index = 0;
                for(int i=0; i<SIZE; i++)
                {
                    if(table[i][j] != 0)
                    {
                        if(index != i)
                        {
                            table[index][j] = table[i][j];
                            table[i][j] = 0;
                        }
                        if(index > 0 && table[index][j] == table[index-1][j])
                        {
                            table[index-1][j] *=2;
                            table[index][j] = 0;
                        }
                        index++;
                    }
                }
            }
            if(!compareTables(table, previousTable))
                addRandomNumber(table);
        }
        else if(move == 2)  //right
        {
            int previousTable[SIZE][SIZE];
            copyTable(table, previousTable);
            for(int i=0; i<SIZE; i++)
            {
                int index = SIZE - 1;
                for(int j=SIZE-1; j>=0; j--)
                {
                    if(table[i][j] != 0)
                    {
                        if(index != j)
                        {
                            table[i][index] = table[i][j];
                            table[i][j] = 0;
                        }
                        if(index < SIZE-1 && table[i][index] == table[i][index+1])
                        {
                            table[i][index+1] *=2;
                            table[i][index] = 0;
                        }
                        index--;
                    }
                }
            }
            if(!compareTables(table, previousTable))
                addRandomNumber(table);
        }
        else if(move == 3)  //down
        {
            int previousTable[SIZE][SIZE];
            copyTable(table, previousTable);
            for(int j=0; j<SIZE; j++)
            {
                int index = SIZE - 1;
                for(int i=SIZE-1; i>=0; i--)
                {
                    if(table[i][j] != 0)
                    {
                        if(index != i)
                        {
                            table[index][j] = table[i][j];
                            table[i][j] = 0;
                        }
                        if(index < SIZE-1 && table[index][j] == table[index+1][j])
                        {
                            table[index+1][j] *=2;
                            table[index][j] = 0;
                        }
                        index--;
                    }
                }
            }
            if(!compareTables(table, previousTable))
                addRandomNumber(table);
        }

        //print the table
        printTable(table);

        //check for game over
        gameOver = checkGameOver(table);
    }

    printf("Game Over!\n");

    return 0;
}

/**
*	Prints the table.
**/
void printTable(int table[][SIZE])
{
    printf("\n");
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
            printf("%d\t", table[i][j]);
        printf("\n");
    }
}

/**
*	Gets the user's move and returns the corresponding integer value.
*	0 for left
*	1 for up
*	2 for right
*	3 for down
**/
int enterMove(int table[][SIZE])
{
    int move = -1;
    printf("\nEnter your move (0:Left, 1:Up, 2:Right, 3:Down): ");
    scanf("%d", &move);

    //check for invalid moves
    while(move<0 || move>3)
    {
        printf("Invalid move! Enter again: ");
        scanf("%d", &move);
    }

    return move;
}

/**
*	Generates a random number between min and max.
**/
int generateRandomNumber(int min, int max)
{
    static int initialized = 0;
    if(!initialized)
    {
        srand(time(NULL));
        initialized = 1;
    }
    return min + rand() % (max+1-min);
}

/**
*	Copies the elements of sourceTable to destinationTable.
**/
void copyTable(int sourceTable[][SIZE], int destinationTable[][SIZE])
{
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            destinationTable[i][j] = sourceTable[i][j];
}

/**
*	Adds a random number (2 or 4) to an empty cell in the table.
*	If no empty cell, no number is added.
**/
void addRandomNumber(int table[][SIZE])
{
    int row = generateRandomNumber(0, SIZE-1);
    int column = generateRandomNumber(0, SIZE-1);

    while(table[row][column] != 0)
    {
        row = generateRandomNumber(0, SIZE-1);
        column = generateRandomNumber(0, SIZE-1);
    }

    int number = generateRandomNumber(1, 2) * 2;
    table[row][column] = number;
}

/**
*	Compares two tables and returns 1 if they are equal and 0 otherwise.
**/
int compareTables(int table1[][SIZE], int table2[][SIZE])
{
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            if(table1[i][j] != table2[i][j])
                return 0;
    return 1;
}

/**
*	Checks whether the game is over.
*	Returns 1 if it is over and 0 otherwise.
**/
int checkGameOver(int table[][SIZE])
{
    //check for empty cells
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            if(table[i][j] == 0)
                return 0;

    //check for merging possibilities
    for(int i=0; i<SIZE-1; i++)
        for(int j=0; j<SIZE-1; j++)
            if(table[i][j] == table[i+1][j] || table[i][j] == table[i][j+1])
                return 0;

    for(int i=0; i<SIZE-1; i++)
        if(table[i][SIZE-1] == table[i+1][SIZE-1])
            return 0;

    for(int j=0; j<SIZE-1; j++)
        if(table[SIZE-1][j] == table[SIZE-1][j+1])
            return 0;

    return 1;
}