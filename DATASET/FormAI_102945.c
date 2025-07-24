//FormAI DATASET v1.0 Category: Chess AI ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 8
#define COL 8

int board[ROW][COL];

void printboard()
{
    int i,j;
    printf("\n\n");
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
            printf("%d ",board[i][j]);
        printf("\n");
    }
}

int legalmoves(int r,int c,int color)
{
    int i,j,k,flg = 0;
    int tempboard[ROW][COL];

    for(i=0;i<ROW;i++)
        for(j=0;j<COL;j++)
            tempboard[i][j] = board[i][j];

    if(color==1)//white
    {
        if(tempboard[r-1][c] == 2)//if up is there opponent piece
        {
            for(k=r-1;k>=0;k--)
            {
                if(tempboard[k][c] != 2)
                {
                    if(tempboard[k][c] == 1)//if it ends with own color
                        flg = 1; 
                    break;
                }   

            }
            if(flg==1)
            {
                for(k=r-1;k>=k;k--)
                    tempboard[k][c] = 1;
            }
        }
        flg = 0;

        if(tempboard[r+1][c] == 2)//if down is there opponent piece
        {
            for(k=r+1;k<ROW;k++)
            {
                if(tempboard[k][c] != 2)
                {
                    if(tempboard[k][c] == 1)//if it ends with own color
                        flg = 1; 
                    break;
                }   

            }
            if(flg==1)
            {
                for(k=r+1;k<=k;k++)
                    tempboard[k][c] = 1;
            }
        }
        flg = 0;

        if(tempboard[r][c-1] == 2)//if left is there opponent piece
        {
            for(k=c-1;k>=0;k--)
            {
                if(tempboard[r][k] != 2)
                {
                    if(tempboard[r][k] == 1)//if it ends with own color
                        flg = 1; 
                    break;
                }   

            }
            if(flg==1)
            {
                for(k=c-1;k>=k;k--)
                    tempboard[r][k] = 1;
            }
        }
        flg = 0;

        if(tempboard[r][c+1] == 2)//if right is there opponent piece
        {
            for(k=c+1;k<COL;k++)
            {
                if(tempboard[r][k] != 2)
                {
                    if(tempboard[r][k] == 1)//if it ends with own color
                        flg = 1; 
                    break;
                }   

            }
            if(flg==1)
            {
                for(k=c+1;k<=k;k++)
                    tempboard[r][k] = 1;
            }
        }
        flg = 0;

        if(tempboard[r-1][c-1] == 2)//if top-left is there own opponent
        {
            i = r-1;
            j = c-1;
            while(i>=0 && j>=0)
            {
                if(tempboard[i][j] != 2)
                {
                    if(tempboard[i][j] == 1)//if it ends with own color
                        flg = 1; 
                    break;
                }  
                i--;
                j--;
            }
            if(flg==1)
            {
                i = r-1;
                j = c-1;
                while(i>=0 && j>=0)
                {
                    if(tempboard[i][j] != 2)
                    {
                      tempboard[i][j] = 1;
                    }  
                    i--;
                    j--;
                }
            }
        }
        flg = 0;

        if(tempboard[r-1][c+1] == 2)//if top-right is there own opponent
        {
            i = r-1;
            j = c+1;
            while(i>=0 && j<COL)
            {
                if(tempboard[i][j] != 2)
                {
                    if(tempboard[i][j] == 1)//if it ends with own color
                        flg = 1; 
                    break;
                }  
                i--;
                j++;
            }
            if(flg==1)
            {
                i = r-1;
                j = c+1;
                while(i>=0 && j<COL)
                {
                    if(tempboard[i][j] != 2)
                    {
                      tempboard[i][j] = 1;
                    }  
                    i--;
                    j++;
                }
            }
        }
        flg = 0;

        if(tempboard[r+1][c-1] == 2)//if down left is there own opponent
        {
            i = r+1;
            j = c-1;
            while(i<ROW && j>=0)
            {
                if(tempboard[i][j] != 2)
                {
                    if(tempboard[i][j] == 1)//if it ends with own color
                        flg = 1; 
                    break;
                }  
                i++;
                j--;
            }
            if(flg==1)
            {
                i = r+1;
                j = c-1;
                while(i<ROW && j>=0)
                {
                    if(tempboard[i][j] != 2)
                    {
                      tempboard[i][j] = 1;
                    }  
                    i++;
                    j--;
                }
            }
        }
        flg = 0;

        if(tempboard[r+1][c+1] == 2)//if down right is there own opponent
        {
            i = r+1;
            j = c+1;
            while(i<ROW && j<COL)
            {
                if(tempboard[i][j] != 2)
                {
                    if(tempboard[i][j] == 1)//if it ends with own color
                        flg = 1; 
                    break;
                }  
                i++;
                j++;
            }
            if(flg==1)
            {
                i = r+1;
                j = c+1;
                while(i<ROW && j<COL)
                {
                    if(tempboard[i][j] != 2)
                    {
                      tempboard[i][j] = 1;
                    }  
                    i++;
                    j++;
                }
            }
        }
    }
    else//black
    {

        if(tempboard[r-1][c] == 1)//if up is there opponent piece
        {
            for(k=r-1;k>=0;k--)
            {
                if(tempboard[k][c] != 1)
                {
                    if(tempboard[k][c] == 2)//if it ends with own color
                        flg = 1; 
                    break;
                }   

            }
            if(flg==1)
            {
                for(k=r-1;k>=k;k--)
                    tempboard[k][c] = 2;
            }
        }
        flg = 0;

        if(tempboard[r+1][c] == 1)//if down is there opponent piece
        {
            for(k=r+1;k<ROW;k++)
            {
                if(tempboard[k][c] != 1)
                {
                    if(tempboard[k][c] == 2)//if it ends with own color
                        flg = 1; 
                    break;
                }   

            }
            if(flg==1)
            {
                for(k=r+1;k<=k;k++)
                    tempboard[k][c] = 2;
            }
        }
        flg = 0;

        if(tempboard[r][c-1] == 1)//if left is there opponent piece
        {
            for(k=c-1;k>=0;k--)
            {
                if(tempboard[r][k] != 1)
                {
                    if(tempboard[r][k] == 2)//if it ends with own color
                        flg = 1; 
                    break;
                }   

            }
            if(flg==1)
            {
                for(k=c-1;k>=k;k--)
                    tempboard[r][k] = 2;
            }
        }
        flg = 0;

        if(tempboard[r][c+1] == 1)//if right is there opponent piece
        {
            for(k=c+1;k<COL;k++)
            {
                if(tempboard[r][k] != 1)
                {
                    if(tempboard[r][k] == 2)//if it ends with own color
                        flg = 1; 
                    break;
                }   

            }
            if(flg==1)
            {
                for(k=c+1;k<=k;k++)
                    tempboard[r][k] = 2;
            }
        }
        flg = 0;

        if(tempboard[r-1][c-1] == 1)//if top-left is there opponent piece
        {
            i = r-1;
            j = c-1;
            while(i>=0 && j>=0)
            {
                if(tempboard[i][j] != 1)
                {
                    if(tempboard[i][j] == 2)//if it ends with own color
                        flg = 1; 
                    break;
                }  
                i--;
                j--;
            }
            if(flg==1)
            {
                i = r-1;
                j = c-1;
                while(i>=0 && j>=0)
                {
                    if(tempboard[i][j] != 1)
                    {
                      tempboard[i][j] = 2;
                    }  
                    i--;
                    j--;
                }
            }
        }
        flg = 0;

        if(tempboard[r-1][c+1] == 1)//if top-right is there opponent piece
        {
            i = r-1;
            j = c+1;
            while(i>=0 && j<COL)
            {
                if(tempboard[i][j] != 1)
                {
                    if(tempboard[i][j] == 2)//if it ends with own color
                        flg = 1; 
                    break;
                }  
                i--;
                j++;
            }
            if(flg==1)
            {
                i = r-1;
                j = c+1;
                while(i>=0 && j<COL)
                {
                    if(tempboard[i][j] != 1)
                    {
                      tempboard[i][j] = 2;
                    }  
                    i--;
                    j++;
                }
            }
        }
        flg = 0;

        if(tempboard[r+1][c-1] == 1)//if down-left is there opponent piece
        {
            i = r+1;
            j = c-1;
            while(i<ROW && j>=0)
            {
                if(tempboard[i][j] != 1)
                {
                    if(tempboard[i][j] == 2)//if it ends with own color
                        flg = 1; 
                    break;
                }  
                i++;
                j--;
            }
            if(flg==1)
            {
                i = r+1;
                j = c-1;
                while(i<ROW && j>=0)
                {
                    if(tempboard[i][j] != 1)
                    {
                      tempboard[i][j] = 2;
                    }  
                    i++;
                    j--;
                }
            }
        }
        flg = 0;

        if(tempboard[r+1][c+1] == 1)//if down-right is there opponent piece
        {
            i = r+1;
            j = c+1;
            while(i<ROW && j<COL)
            {
                if(tempboard[i][j] != 1)
                {
                    if(tempboard[i][j] == 2)//if it ends with own color
                        flg = 1; 
                    break;
                }  
                i++;
                j++;
            }
            if(flg==1)
            {
                i = r+1;
                j = c+1;
                while(i<ROW && j<COL)
                {
                    if(tempboard[i][j] != 1)
                    {
                      tempboard[i][j] = 2;
                    }  
                    i++;
                    j++;
                }
            }
        }   
    }
    if(tempboard[r][c]==0)
        tempboard[r][c] = 3;
    printboard();
    return 0;
}

int main()
{
    int i,j;
    for(i=0;i<ROW;i++)
        for(j=0;j<COL;j++)
            board[i][j] = 0;
    
    board[3][3] = 1;
    board[3][4] = 2;
    board[4][3] = 2;
    board[4][4] = 1;

    printboard();

    //legalmoves(2,3,1);

    return 0;
}