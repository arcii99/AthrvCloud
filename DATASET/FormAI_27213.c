//FormAI DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void shuffle(int *arr, int n);
void printBoard(int board[][COLS], int revealed[][COLS]);
void reveal(int board[][COLS], int revealed[][COLS], int row, int col);

int main()
{
    int board[ROWS][COLS] = {{0,1,2,3},{4,5,6,7},{0,1,2,3},{4,5,6,7}};
    int revealed[ROWS][COLS] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int firstRow, secondRow, firstCol, secondCol;
    int pairs = 0;
    
    //initialize random seed
    srand(time(NULL));
    
    //shuffle board
    shuffle((int*)board, ROWS*COLS);
    
    while(pairs < ROWS*COLS/2)
    {
        printBoard(board, revealed);
        
        //get user input
        printf("Enter row and column of first card: ");
        scanf("%d %d", &firstRow, &firstCol);
        
        //checking if card is already revealed or out of bounds
        if(firstRow < 0 || firstRow >= ROWS || firstCol < 0 || firstCol >= COLS || revealed[firstRow][firstCol] == 1)
        {
            printf("Invalid input.\n");
            continue;
        }
        
        reveal(board, revealed, firstRow, firstCol);
        printBoard(board, revealed);
        
        printf("Enter row and column of second card: ");
        scanf("%d %d", &secondRow, &secondCol);
        
        //checking if card is already revealed or out of bounds
        if(secondRow < 0 || secondRow >= ROWS || secondCol < 0 || secondCol >= COLS || revealed[secondRow][secondCol] == 1)
        {
            printf("Invalid input.\n");
            revealed[firstRow][firstCol] = 0;
            continue;
        }
        
        reveal(board, revealed, secondRow, secondCol);
        printBoard(board, revealed);
        
        //checking if the two cards are a match
        if(board[firstRow][firstCol] == board[secondRow][secondCol])
        {
            printf("You found a pair!\n");
            pairs++;
        }
        else
        {
            printf("Not a pair.\n");
            revealed[firstRow][firstCol] = 0;
            revealed[secondRow][secondCol] = 0;
        }
    }
    
    printf("You won the game!\n");
    
    return 0;
}

//shuffles an array of size 'n'
void shuffle(int *arr, int n)
{
    for(int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

//prints the game board
void printBoard(int board[][COLS], int revealed[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(revealed[i][j])
                printf("%d ", board[i][j]);
            else
                printf("* ");
        }
        printf("\n");
    }
}

//reveals a card
void reveal(int board[][COLS], int revealed[][COLS], int row, int col)
{
    revealed[row][col] = 1;
}