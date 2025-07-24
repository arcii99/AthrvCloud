//FormAI DATASET v1.0 Category: Game of Life ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 20
#define COLUMNS 20

int grid[ROWS][COLUMNS];
int empty_grid[ROWS][COLUMNS];
void show_grid()
{
    system("cls");
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLUMNS;j++)
        {
            if(grid[i][j]==1)
            {
                printf("*");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int row,int col)
{
    int count=0;
    for(int i=row-1;i<=row+1;i++)
    {
        for(int j=col-1;j<=col+1;j++)
        {
            if(i!=row || j!=col)
            {
                if(i>=0 && j>=0 && i<ROWS && j<COLUMNS && grid[i][j]==1)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

void update_grid()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLUMNS;j++)
        {
            int neighbors=count_neighbors(i,j);
            if(grid[i][j]==1)
            {
                if(neighbors<2 || neighbors>3)
                {
                    empty_grid[i][j]=0;
                }
                else
                {
                    empty_grid[i][j]=1;
                }
            }
            else
            {
                if(neighbors==3)
                {
                    empty_grid[i][j]=1;
                }
                else
                {
                    empty_grid[i][j]=0;
                }
            }
        }
    }
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLUMNS;j++)
        {
            grid[i][j]=empty_grid[i][j];
        }
    }
}

int main()
{
    srand(time(NULL));
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLUMNS;j++)
        {
            grid[i][j]=rand()%2;
        }
    }
    while(1)
    {
        show_grid();
        update_grid();
        for(long int i=0;i<10000000;i++);
    }
    return 0;
}