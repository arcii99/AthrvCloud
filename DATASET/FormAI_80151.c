//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void displayInstructions();
void setupBoard(char board[][COLS]);
void printBoard(char board[][COLS]);
int checkHorizontal(char board[][COLS], int row);
int checkVertical(char board[][COLS], int col);
int checkDiagonal(char board[][COLS]);
int checkWinner(char board[][COLS]);

int main()
{
    char board[ROWS][COLS];
    int i = 0, j = 0, num = 0, numCount = 0;
    char answer = ' ';
    
    srand((unsigned)time(NULL)); //Seed for random number generation
    
    displayInstructions(); //Display game instructions
    
    do
    {
        setupBoard(board); //Initialize the board
        
        do
        {
            printBoard(board); //Print the board
            
            printf("\nEnter a number between 1 and 25: ");
            scanf("%d", &num); //Get user input
            
            if (num < 1 || num > 25) //Validate user input
            {
                printf("Invalid input. You must enter a number between 1 and 25.\n");
                continue;
            }
            
            //Mark the cell with the number entered by the user
            for (i = 0; i < ROWS; i++)
            {
                for (j = 0; j < COLS; j++)
                {
                    if (board[i][j] == ' ')
                    {
                        numCount++;
                        
                        if (numCount == num)
                        {
                            board[i][j] = 'X';
                        }
                    }
                }
            }
            
        } while (checkWinner(board) == 0); //Keep playing until we have a winner
        
        printf("\nGAME OVER. The winner is... player X!\n");
        
        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &answer); //Get user input
        
    } while (toupper(answer) == 'Y'); //Repeat game if user answers "Y"
    
    printf("\nThanks for playing! Goodbye.\n");
    
    return 0;
}

void displayInstructions()
{
    printf("* * * * * * * * * * * * * * *\n");
    printf("*  Welcome to C Bingo!     *\n");
    printf("* * * * * * * * * * * * * * *\n\n");
    printf("To play the game, enter a number between 1 and 25 when prompted. If the number you enter\n");
    printf("matches a cell on the board, an 'X' will be placed in that cell. The winner is the first\n");
    printf("player to get five 'X's in a row (horizontally, vertically, or diagonally).\n\n");
}

void setupBoard(char board[][COLS])
{
    int i, j, num;
    int nums[25];
    int numCount = 0;
    
    //Fill an array with the numbers 1 through 25 in random order
    for (i = 0; i < 25; i++)
    {
        nums[i] = i + 1;
    }
    
    for (i = 0; i < 25; i++)
    {
        int swapIndex = rand() % 25;
        int temp = nums[i];
        nums[i] = nums[swapIndex];
        nums[swapIndex] = temp;
    }
    
    //Fill the board with the numbers from the array
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            numCount++;
            board[i][j] = ' ';
            if (numCount == nums[num])
            {
                board[i][j] = nums[num] + '0'; //Convert number to character
                num++;
            }
        }
    }
}

void printBoard(char board[][COLS])
{
    int i, j;
    
    printf("\nB   I   N   G   O\n");
    
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (j == 2 && i == 2)
            {
                printf(" F  ");
            }
            else
            {
                printf(" %c  ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int checkHorizontal(char board[][COLS], int row)
{
    int i, count = 0;
    
    for (i = 0; i < COLS; i++)
    {
        if (board[row][i] == 'X')
        {
            count++;
        }
    }
    
    return count;
}

int checkVertical(char board[][COLS], int col)
{
    int i, count = 0;
    
    for (i = 0; i < ROWS; i++)
    {
        if (board[i][col] == 'X')
        {
            count++;
        }
    }
    
    return count;
}

int checkDiagonal(char board[][COLS])
{
    int count = 0;
    
    if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X' && board[4][4] == 'X')
    {
        count = 5;
    }
    else if (board[4][0] == 'X' && board[3][1] == 'X' && board[2][2] == 'X' && board[1][3] == 'X' && board[0][4] == 'X')
    {
        count = 5;
    }
    
    return count;
}

int checkWinner(char board[][COLS])
{
    int i, count = 0;
    
    //Check rows
    for (i = 0; i < ROWS; i++)
    {
        if (checkHorizontal(board, i) == 5)
        {
            return 1;
        }
    }
    
    //Check columns
    for (i = 0; i < COLS; i++)
    {
        if (checkVertical(board, i) == 5)
        {
            return 1;
        }
    }
    
    //Check diagonals
    if (checkDiagonal(board) == 5)
    {
        return 1;
    }
    
    return 0;
}