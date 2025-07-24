//FormAI DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_MOVES 8

void printBoard(char board[][BOARD_SIZE])
{
    for(int i=0; i<BOARD_SIZE; i++)
    {
        for(int j=0; j<BOARD_SIZE; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void clearBoard(char board[][BOARD_SIZE])
{
    for(int i=0; i<BOARD_SIZE; i++)
    {
        for(int j=0; j<BOARD_SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void generateRandomMoves(int moves[])
{
    srand(time(NULL));
    for(int i=0; i<MAX_MOVES; i++)
    {
        moves[i] = rand() % (BOARD_SIZE * BOARD_SIZE);
    }
}

void placeMovesOnBoard(char board[][BOARD_SIZE], int moves[], char moveSymbol)
{
    int moveIndex = 0;
    for(int i=0; i<BOARD_SIZE; i++)
    {
        for(int j=0; j<BOARD_SIZE; j++)
        {
            if(moveIndex < MAX_MOVES && (i * BOARD_SIZE + j) == moves[moveIndex])
            {
                board[i][j] = moveSymbol;
                moveIndex++;
            }
        }
    }
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    char moveSymbol = '*';
    int moves[MAX_MOVES];
    
    clearBoard(board);
    generateRandomMoves(moves);
    placeMovesOnBoard(board, moves, moveSymbol);
    
    printf("Welcome to the Romantic Memory Game!\n");
    printf("Find all the matching pairs of asterisks in the board...\n");
    printf("You have 10 attempts!\n");
    
    for(int attempts=1; attempts<=10; attempts++)
    {
        printf("Attempt #%d\n", attempts);
        printf("---------------------------\n");
        printBoard(board);
        printf("Enter first cell coordinates (i j):\n");
        int i1, j1, i2, j2;
        scanf("%d %d", &i1, &j1);
        printf("Enter second cell coordinates (i j):\n");
        scanf("%d %d", &i2, &j2);
        if(board[i1-1][j1-1] == board[i2-1][j2-1])
        {
            printf("Match found! Yay, you are so romantic!\n");
            board[i1-1][j1-1] = ' ';
            board[i2-1][j2-1] = ' ';
        }
        else
        {
            printf("No match found, keep trying!\n");
        }
    }
    
    printf("Game over, thank you for playing the Romantic Memory Game!\n");
    
    return 0;
}