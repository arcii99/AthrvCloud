//FormAI DATASET v1.0 Category: Checkers Game ; Style: authentic
#include<stdio.h>
#define ROW 8
#define COL 8
int main()
{
    char board[ROW][COL] = {
        {' ','R',' ','R',' ','R',' ','R'},
        {'R',' ','R',' ','R',' ','R',' '},
        {' ','R',' ','R',' ','R',' ','R'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'B',' ','B',' ','B',' ','B',' '},
        {' ','B',' ','B',' ','B',' ','B'},
        {'B',' ','B',' ','B',' ','B',' '}
    };
    int i,j,x,y,z,a,b,c,d,p,q;
    char m;
    printf("\n\n\t\t\t\tWELCOME TO THE CHECKERS GAME\n\n\n");
    printf("\n\t\t\t\tGAME INSTRUCTIONS : \n\n\t\t\t\t  1. PLAYER 1 -> RED \n\n\t\t\t\t  2. PLAYER 2 -> BLACK\n");
    printf("\n\t\t\t  * To select a coin press its cooresponding alphabate \n\n\t\t\t  * Then input the desired position to move the coin\n");
    printf("\n\t\t\t  * Player with no move loses\n");
    printf("\n\t\t\t\t GAME WILL START IN 3 SECONDS !!!");
    for(i=1;i<=3;i++)
    {
        printf(".");
        sleep(1);
    }
    while(1)
    {
        printf("\n\n\n");
        printf("\t\t\t\t\t\t     BLACK \n\n");
        printf("\n\t\t\t\t     1 2 3 4 5 6 7 8\n\n");
        for(i=0;i<ROW;i++)
        {
            printf("\t\t\t\t     %d",i+1);
            for(j=0;j<COL;j++)
            {
               printf("|");
               printf(" %c ",board[i][j]);
            }
            printf("|");
            printf("\n\t\t\t\t                   ");

            for(c=0;c<25;c++)
            {printf("-");}

            printf("\n");
        }
        if(a==2)
        {
            printf("\n\n\t\t\t\tBLACK HAS NO MOVES LEFT!!!!\n\n\t\t\t\t RED WINS!!!!\n");
            break;
        }
        printf("\n\n\t\t\t\t\t\t\tRED\n\n");
        printf("\nSELECT THE COIN YOU WISH TO MOVE: ");
        scanf(" %c",&m);
        printf("\nENTER THE ROW TO MOVE");
        scanf("%d",&x);
        printf("\nENTER THE COLUMN TO MOVE");
        scanf("%d",&y);

        if(m=='r'||m=='R')
        {
            if(board[x-1][y-1]=='R')
            {
                if(board[x][y]==' ')
                {
                    board[x-1][y-1]=' ';
                    board[x][y]='R';
                }
            }
            if(board[x-1][y-1]=='R')
            {
                if(board[x-2][y]==' ')
                {
                    board[x-1][y-1]=' ';
                    board[x-2][y]='R';
                }
            }
            if(board[x-1][y-1]=='R')
            {
                if(board[x][y]=='b' || board[x][y]=='B')
                {
                    if(board[x+1][y+1]==' ')
                    {
                        board[x+1][y+1]='R';
                        board[x][y]=' ';
                        board[x-1][y-1]=' ';
                    }
                    else if(board[x+1][y+1]=='b' || board[x+1][y+1]=='B')
                    {
                        if(board[x+2][y+2]==' ')
                        {
                            board[x+2][y+2]='R';
                            board[x+1][y+1]=' ';
                            board[x][y]=' ';
                            board[x-1][y-1]=' ';
                        }
                    }
                }
            }
            a=2;
            for(p=0;p<ROW;p++)
            {
                for(q=0;q<COL;q++)
                {
                    if(board[p][q]=='R')
                    {
                        if(board[p+1][q+1]==' ' || board[p+1][q-1]==' ' || board[p+2][q+2]==' ' || board[p+2][q-2]==' ')
                        {
                            a=1;
                            break;
                        }
                    }
                }
                if(a==1)
                break;
            }
            if(z==2)
            {
                printf("\n\n\t\t\t\t RED HAS NO MOVES LEFT!!!!\n\n\t\t\t\t BLACK WINS!!!!\n");
                break;
            }
        }
        else if(m=='b'||m=='B')
        {
            if(board[x+1][y+1]=='B')
            {
                if(board[x][y]==' ')
                {
                    board[x+1][y+1]=' ';
                    board[x][y]='B';
                }
            }
            if(board[x+1][y+1]=='B')
            {
                if(board[x+2][y+2]==' ')
                {
                    board[x+2][y+2]='B';
                    board[x+1][y+1]=' ';
                    board[x][y]=' ';
                }
            }
            if(board[x+1][y+1]=='B')
            {
                if(board[x][y]=='r' || board[x][y]=='R')
                {
                    if(board[x-1][y-1]==' ')
                    {
                        board[x-1][y-1]='B';
                        board[x][y]=' ';
                        board[x+1][y+1]=' ';
                    }
                    else if(board[x-1][y-1]=='r' || board[x-1][y-1]=='R')
                    {
                        if(board[x-2][y-2]==' ')
                        {
                            board[x-2][y-2]='B';
                            board[x-1][y-1]=' ';
                            board[x][y]=' ';
                            board[x+1][y+1]=' ';
                        }
                    }
                }
            }
            z=2;
            for(p=0;p<ROW;p++)
            {
                for(q=0;q<COL;q++)
                {
                    if(board[p][q]=='B')
                    {
                        if(board[p-1][q-1]==' ' || board[p-1][q+1]==' ' || board[p-2][q-2]==' ' || board[p-2][q+2]==' ')
                        {
                            z=1;
                            break;
                        }
                    }
                }
                if(z==1)
                break;
            }
            if(a==2)
            {
                printf("\n\n\t\t\t\tBLACK HAS NO MOVES LEFT!!!!\n\n\t\t\t\t RED WINS!!!!\n");
                break;
            }
        }
        else
        printf("\nINVALID INPUT");
    }
    return 0;
}