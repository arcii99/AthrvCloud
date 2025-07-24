//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define BOMB_COUNT 15

void printBoard(char board[ROWS][COLS], int reveal);
int getAdjacentBombs(char board[ROWS][COLS], int row, int col);
int validMove(char board[ROWS][COLS], int row, int col);
void revealBoard(char board[ROWS][COLS]);

int main()
{
    char board[ROWS][COLS];
    int row, col, bombsPlaced = 0, reveal = 0, bombsFound = 0;
    srand(time(0)); //Seed the random number generator with the current time

    //Initialize the board to all unexplored squares
    for(row = 0; row < ROWS; row++)
        for(col = 0; col < COLS; col++)
            board[row][col] = '-';

    //Place bombs on the board
    do {
        row = rand() % ROWS;
        col = rand() % COLS;
        if(board[row][col] == '-') {
            board[row][col] = '*';
            bombsPlaced++;
        }
    } while(bombsPlaced < BOMB_COUNT);

    //Game loop
    while(1) {
        printBoard(board, reveal);

        //Get user input
        printf("\nEnter row and column to explore: ");
        scanf("%d %d", &row, &col);
        //Make sure the move is valid
        if(!validMove(board, row, col)) {
            printf("\nInvalid move, please try again!\n");
            continue;
        }
        //Update the board with the new move
        if(board[row][col] == '*') {
            printf("\nSorry, you hit a bomb! Game over.");
            revealBoard(board);
            break;
        }
        else {
            //Find the number of adjacent bombs and update the board
            int adjacentBombs = getAdjacentBombs(board, row, col);
            if(adjacentBombs == 0) {
                board[row][col] = ' ';
            }
            else {
                board[row][col] = adjacentBombs + '0';
            }
            //Increment the reveal count
            reveal++;
            //Check if the game has been won
            if((ROWS * COLS) - reveal == BOMB_COUNT) {
                printf("\nCongratuations, you won the game!");
                revealBoard(board);
                break;
            }
        }
    }

    return 0;
}

void printBoard(char board[ROWS][COLS], int reveal)
{
    int row, col;

    printf("\n   ");
    for(col = 0; col < COLS; col++) {
        printf("%d ", col);
    }
    printf("\n");
    for(row = 0; row < ROWS; row++)
    {
        printf("%-2d ", row);
        for(col = 0; col < COLS; col++)
        {
            if(board[row][col] == '-' && reveal == 0) {
                printf("# ");
            }
            else {
                printf("%c ", board[row][col]);
            }
        }
        printf("\n");
    }
}

int getAdjacentBombs(char board[ROWS][COLS], int row, int col)
{
    int count = 0;

    //Upper left
    if(row > 0 && col > 0 && board[row-1][col-1] == '*') {
        count++;
    }
    //Upper middle
    if(row > 0 && board[row-1][col] == '*') {
        count++;
    }
    //Upper right
    if(row > 0 && col < COLS-1 && board[row-1][col+1] == '*') {
        count++;
    }
    //Middle left
    if(col > 0 && board[row][col-1] == '*') {
        count++;
    }
    //Middle right
    if(col < COLS-1 && board[row][col+1] == '*') {
        count++;
    }
    //Lower left
    if(row < ROWS-1 && col > 0 && board[row+1][col-1] == '*') {
        count++;
    }
    //Lower middle
    if(row < ROWS-1 && board[row+1][col] == '*') {
        count++;
    }
    //Lower right
    if(row < ROWS-1 && col < COLS-1 && board[row+1][col+1] == '*') {
        count++;
    }

    return count;
}

int validMove(char board[ROWS][COLS], int row, int col)
{
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    if(board[row][col] != '-') {
        return 0;
    }
    return 1;
}

void revealBoard(char board[ROWS][COLS])
{
    int row, col;

    printf("\n   ");
    for(col = 0; col < COLS; col++) {
        printf("%d ", col);
    }
    printf("\n");
    for(row = 0; row < ROWS; row++)
    {
        printf("%-2d ", row);
        for(col = 0; col < COLS; col++)
        {
            if(board[row][col] == '-') {
                printf("* ");
            }
            else {
                printf("%c ", board[row][col]);
            }
        }
        printf("\n");
    }
}