//FormAI DATASET v1.0 Category: Chess AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[8][8] = {
    {-1,-2,-3,-4,-5,-3,-2,-1},
    {-6,-6,-6,-6,-6,-6,-6,-6},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {6,6,6,6,6,6,6,6},
    {1,2,3,4,5,3,2,1}
};

void printBoard();
void playerMove();
void computerMove();

int main()
{
    printf("Welcome to the Surrealist Chess AI\n");
    printBoard();
    while(1)
    {
        printf("Player's move\n");
        playerMove();
        printf("Computer's move\n");
        computerMove();
    }
    return 0;
}

void printBoard()
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            switch(abs(board[i][j]))
            {
                case 1: printf("P "); break;
                case 2: printf("K "); break;
                case 3: printf("B "); break;
                case 4: printf("R "); break;
                case 5: printf("Q "); break;
                case 6: printf("C "); break;
                default: printf(". "); break;
            }
        }
        printf("\n");
    }
}

void playerMove()
{
    int fromRow, fromCol, toRow, toCol;
    while(1)
    {
        printf("Enter move: ");
        scanf("%d %d %d %d", &fromRow, &fromCol, &toRow, &toCol);
        if(board[fromRow][fromCol] > 0)
            break;
        printf("Invalid piece, try again.\n");
    }
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = 0;
    printBoard();
}

void computerMove()
{
    srand(time(NULL));
    int fromRow, fromCol, toRow, toCol;
    while(1)
    {
        fromRow = rand() % 8;
        fromCol = rand() % 8;
        if(board[fromRow][fromCol] < 0)
            break;
    }
    while(1)
    {
        toRow = rand() % 8;
        toCol = rand() % 8;
        if(board[toRow][toCol] == 0)
            break;
    }
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = 0;
    printBoard();
}