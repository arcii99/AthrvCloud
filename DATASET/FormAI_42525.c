//FormAI DATASET v1.0 Category: Sudoku solver ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GRID_SIZE 9 //Size of the Sudoku Puzzle
#define BOX_SIZE 3 //Size of each box

//Function prototypes
void display(char[][GRID_SIZE]);
int checkRow(char[][GRID_SIZE], int, char);
int checkColumn(char[][GRID_SIZE], int, char);
int checkBox(char[][GRID_SIZE], int, int, char);
int checkValid(char[][GRID_SIZE], int, int, char);
int solveSudoku(char[][GRID_SIZE], int, int);
int generateSudoku(char[][GRID_SIZE], int);
int main()
{
    char grid[GRID_SIZE][GRID_SIZE]; //2D array to hold Sudoku puzzle
    int num;

    srand(time(NULL)); //Seed the random number generator

    generateSudoku(grid, 0); //Generate the Sudoku puzzle

    display(grid); //Display the Sudoku puzzle

    return 0;
}

//Function to display the Sudoku puzzle
void display(char grid[][GRID_SIZE])
{
    int i,j;

    for(i=0;i<GRID_SIZE;i++)
    {
        for(j=0;j<GRID_SIZE;j++)
        {
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }
}

//Function to check if a digit can be placed in a row
int checkRow(char grid[][GRID_SIZE], int row, char num)
{
    int i;

    for(i=0;i<GRID_SIZE;i++)
    {
        if(grid[row][i] == num)
        {
            return 0; //Number already present in row
        }
    }
    return 1; //Number can be placed in row
}

//Function to check if a digit can be placed in a column
int checkColumn(char grid[][GRID_SIZE], int column, char num)
{
    int i;

    for(i=0;i<GRID_SIZE;i++)
    {
        if(grid[i][column] == num)
        {
            return 0; //Number already present in column
        }
    }
    return 1; //Number can be placed in column
}

//Function to check if a digit can be placed in a 3x3 box
int checkBox(char grid[][GRID_SIZE], int rowStart, int columnStart, char num)
{
    int i,j;

    for(i=0;i<BOX_SIZE;i++)
    {
        for(j=0;j<BOX_SIZE;j++)
        {
            if(grid[rowStart+i][columnStart+j] == num)
            {
                return 0; //Number already present in the box
            }
        }
    }
    return 1; //Number can be placed in the box
}

//Function to check if a digit can be placed in a given cell
int checkValid(char grid[][GRID_SIZE], int row, int column, char num)
{
    if(checkRow(grid,row,num) && checkColumn(grid,column,num) && checkBox(grid,row-row%BOX_SIZE,column-column%BOX_SIZE,num))
    {
        return 1; //Digit can be placed in the cell
    }
    return 0; //Digit cannot be placed in the cell
}

//Function to solve the Sudoku puzzle
int solveSudoku(char grid[][GRID_SIZE], int row, int column)
{
    int i;
    char num;

    //Check if end of row is reached
    if(row == GRID_SIZE-1 && column == GRID_SIZE)
    {
        return 1; //Sudoku puzzle solved
    }

    //Check if end of row is reached
    if(column == GRID_SIZE)
    {
        row++;
        column = 0;
    }

    //Check if cell already has a number
    if(grid[row][column] != '-')
    {
        return solveSudoku(grid, row, column+1); //Check next cell
    }

    //Try all possible numbers
    for(i=1;i<=9;i++)
    {
        num = i + '0'; //Convert number to character

        //Check if number can be placed in cell
        if(checkValid(grid,row,column,num))
        {
            grid[row][column] = num; //Place number in cell

            //Check next cell
            if(solveSudoku(grid,row,column+1))
            {
                return 1; //Sudoku puzzle solved
            }
        }

        grid[row][column] = '-'; //Backtrack
    }

    return 0; //Puzzle cannot be solved
}

//Function to generate a Sudoku puzzle
int generateSudoku(char grid[][GRID_SIZE], int count)
{
    int i,j,k;
    char num;

    //Check if 81 cells are filled
    if(count == 81)
    {
        return 1; //Sudoku puzzle generated
    }

    //Find row and column of next empty cell
    i = count / GRID_SIZE;
    j = count % GRID_SIZE;

    //Try all possible numbers
    for(k=1;k<=9;k++)
    {
        num = k + '0'; //Convert number to character

        //Check if number can be placed in cell
        if(checkValid(grid,i,j,num))
        {
            grid[i][j] = num; //Place number in cell

            //Check if Sudoku puzzle can be generated
            if(generateSudoku(grid,count+1))
            {
                return 1; //Sudoku puzzle generated
            }
        }

        grid[i][j] = '-'; //Backtrack
    }

    return 0; //Puzzle cannot be generated
}