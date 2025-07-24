//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5
#define COLS 5
#define MAX_NUM 75

//function to generate random numbers
int generate_number(int numbers[])
{
    int random_number;
    do
    {
        random_number = rand() % MAX_NUM + 1;
    } while (numbers[random_number] != 0);
    numbers[random_number] = 1;
    return random_number;
}

//function to initialize the bingo card
void initialize_board(int board[][ROWS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            board[i][j] = generate_number((int[76]){0});
        }
    }
    board[2][2] = 0;
}

//function to display the bingo card
void display_board(int board[][ROWS])
{
    int i, j;
    printf("\n| B  | I  | N  | G  | O  |\n");
    for (i = 0; i < ROWS; i++)
    {
        printf("|-----------------------|\n");
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == 0)
            {
                printf("| XX ");
            }
            else
            {
                printf("| %2d ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("|-----------------------|\n");
}

//function to mark a number on the bingo card
void mark_number(int board[][ROWS], int number)
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == number)
            {
                board[i][j] = 0;
                break;
            } 
        }
    }
}

//function to check if there is a bingo
int has_bingo(int board[][ROWS])
{
    int i, j, count;

    //check horizontal lines
    for (i = 0; i < ROWS; i++)
    {
        count = 0;
        for (j = 0; j < COLS; j++)
        {
            if (board[i][j] == 0)
            {
                count++;
            }
        }
        if (count == COLS)
        {
            return 1;
        }
    }

    //check vertical lines
    for (i = 0; i < COLS; i++)
    {
        count = 0;
        for (j = 0; j < ROWS; j++)
        {
            if (board[j][i] == 0)
            {
                count++;
            }
        }
        if (count == ROWS)
        {
            return 1;
        }
    }

    //check diagonal
    count = 0;
    for (i = 0; i < ROWS; i++) 
    {
        if (board[i][i] == 0) 
        {
            count++;
        }
    }
    if (count == ROWS) 
    {
        return 1;
    }

    count = 0;
    for (i = 0; i < ROWS; i++) 
    {
        if (board[i][ROWS-1-i] == 0) 
        {
            count++;
        }
    }
    if (count == ROWS) 
    {
        return 1;
    }

    return 0;
}

int main()
{
    int board[ROWS][COLS];
    int numbers_called[MAX_NUM+1] = {0};
    int number, count = 0, bingo = 0;

    //initialize random seed
    srand(time(NULL));

    //initialize the bingo card
    initialize_board(board);

    //display the bingo card
    printf("Welcome to Bingo Game!\n");
    printf("Here is your Bingo Card:\n");
    display_board(board);

    //start the game
    while (!bingo && count < MAX_NUM)
    {
        //generate a random number and mark it on the card
        number = generate_number(numbers_called);
        mark_number(board, number);
        printf("The number called is: %d\n", number);

        //display the updated card
        display_board(board);

        //check if there is a bingo
        bingo = has_bingo(board);
        count++;
    }

    //display the game result
    if (bingo)
    {
        printf("Bingo! You won in %d turns!\n", count);
    }
    else
    {
        printf("Sorry, you didn't get Bingo in %d turns. Better luck next time!\n", count);
    }

    return 0;
}