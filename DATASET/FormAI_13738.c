//FormAI DATASET v1.0 Category: Chess AI ; Style: puzzling
#include<stdio.h>
#define N 8

int checkAttack(int row,int col,int board[N][N]) //function to check attacks
{
    int i,j;
    for(i=0;i<row;i++) //checking rows for attack
        if(board[i][col])
            return 0;
    for(i=row,j=col;i>=0 && j>=0;i--,j--) //checking diagonals for attack
        if(board[i][j])
            return 0;
    for(i=row,j=col;i>=0 && j<N;i--,j++) //checking diagonals for attack
        if(board[i][j])
            return 0;
    return 1; //no attack found
}

int solve(int row,int board[N][N]) //recursive function to solve chess board
{
    int i;
    if(row==N) //if all rows are filled including Nth row
        return 1;
    for(i=0;i<N;i++) //checking all columns in current row
    {
        if(checkAttack(row,i,board)) //if no attack found
        {
            board[row][i]=1; //place queen in that cell
            if(solve(row+1,board)) //recursive call for next rows
                return 1; //queen placements found, return 1
            board[row][i]=0; //if placement was wrong, backtrack
        }
    }
    return 0; //All columns of current row are checked, no placement found
}

int main()
{
    int i,j,board[N][N]={0}; //initializing chess board with 0
    solve(0,board); //starting from first row
    printf("\nThe chess board configuration:\n");
    for(i=0;i<N;i++) //loop to print chess board
    {
        for(j=0;j<N;j++)
            printf("%d ",board[i][j]); //if 1, queen is present
        printf("\n");
    }
    return 0; //successful run
}