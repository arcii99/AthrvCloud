//FormAI DATASET v1.0 Category: Chess engine ; Style: excited
#include<stdio.h>
#include<stdlib.h>

void init_board(char square[8][8])
{
    for(int i=0;i<8;i++)
    {
        square[1][i]='P';
        square[6][i]='p';
    }
    
    square[0][0]='R';
    square[0][1]='N';
    square[0][2]='B';
    square[0][3]='Q';
    square[0][4]='K';
    square[0][5]='B';
    square[0][6]='N';
    square[0][7]='R';

    square[7][0]='r';
    square[7][1]='n';
    square[7][2]='b';
    square[7][3]='q';
    square[7][4]='k';
    square[7][5]='b';
    square[7][6]='n';
    square[7][7]='r';

    for(int i=2;i<6;i++)
    {
        for(int j=0;j<8;j++)
        {
            square[i][j]=' ';
        }
    }
}

void print_board(char square[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            printf("%c ",square[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char square[8][8];
    init_board(square);
    print_board(square);
    return 0;
}