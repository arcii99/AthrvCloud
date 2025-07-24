//FormAI DATASET v1.0 Category: Checkers Game ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

char board[8][8];
char c;
int choice, x, y, winner = 0;
int turn = 1, countb = 12, countw = 12;
int r1 = 0, r2 = 0, c1 = 0, c2 = 0;

void print_board();
void play();
void check_winner();
int valid_move();
int valid_jump();
void swap_variables();

int main()
{
    int i, j;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if((i+j)%2 == 0)
            {
                if(i<=2)
                {
                    board[i][j] = 'b';
                }
                else if(i>=5)
                {
                    board[i][j] = 'w';
                }
                else
                {
                    board[i][j] = ' ';
                }
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }

    print_board();

    while(countb != 0 && countw != 0)
    {
        play();
        check_winner();
    }

    if(countb == 0)
    {
        printf("\n\n\nCongratulations, White wins!!!");
    }
    else if(countw == 0)
    {
        printf("\n\n\nCongratulations, Black wins!!!");
    }
    else
    {
        printf("\n\n\nIt is a draw!!!");
    }

    return 0;
}

void print_board()
{
    int i, j;

    printf("\n\n        1     2     3     4     5     6     7     8\n");
    printf("     -------------------------------------------------\n");

    for(i=0;i<8;i++)
    {
        printf("  %d  ",i+1);
        for(j=0;j<8;j++)
        {
            printf("|  %c  ",board[i][j]);
        }
        printf("|");
        printf("\n     -------------------------------------------------\n");
    }
}

void play()
{
    printf("\n\n");
    printf("Turn: ");
    if(turn == 1)
    {
        printf("Black\n");
    }
    else
    {
        printf("White\n");
    }

    printf("Enter row and column of piece to move: ");
    scanf("%d %d",&r1,&c1);

    if(board[r1-1][c1-1] == ' ')
    {
        printf("\n\nInvalid Move!!! Try again.");
        play();
        return;
    }

    if(board[r1-1][c1-1] == 'b' && turn == 2)
    {
        printf("\n\nInvalid Move!!! Try again.");
        play();
        return;
    }

    if(board[r1-1][c1-1] == 'w' && turn == 1)
    {
        printf("\n\nInvalid Move!!! Try again.");
        play();
        return;
    }

    printf("Enter row and column of new position: ");
    scanf("%d %d",&r2,&c2);

    if(valid_move() == 1)
    {
        if(abs(r2-r1) == 2 && abs(c2-c1) == 2)
        {
            valid_jump();
        }

        swap_variables();

        if(turn == 1)
        {
            turn = 2;
        }
        else
        {
            turn = 1;
        }

        print_board();
    }
    else
    {
        printf("\n\nInvalid Move!!! Try again.");
        play();
        return;
    }
}

int valid_move()
{
    if(board[r2-1][c2-1] != ' ' || abs(r2-r1) != abs(c2-c1) || r2<=0 || r2>=9 || c2<=0 || c2>=9)
    {
        return 0;
    }
    if(board[r1-1][c1-1] == 'b' && turn == 1)
    {
        if((r2-r1) != 1 || abs(c2-c1) != 1)
        {
            return 0;
        }
    }
    else if(board[r1-1][c1-1] == 'w' && turn == 2)
    {
        if((r1-r2) != 1 || abs(c2-c1) != 1)
        {
            return 0;
        }
    }
    else if(board[r1-1][c1-1] == 'B' && turn == 1)
    {
        if((r2-r1 != abs(c2-c1)) || r2>=r1 || c2>=c1)
        {
            return 0;
        }

        for(x=r1-2,y=c1-2;x>=r2 && y>=c2;x--,y--)
        {
            if(board[x][y] != ' ')
            {
                return 0;
            }
        }
    }
    else if(board[r1-1][c1-1] == 'W' && turn == 2)
    {
        if((r1-r2 != abs(c2-c1)) || r1>=r2 || c1>=c2)
        {
            return 0;
        }

        for(x=r1-2,y=c1-2;x>=r2 && y>=c2;x--,y--)
        {
            if(board[x][y] != ' ')
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }
    return 1;
}

int valid_jump()
{
    if(board[(r1+r2)/2-1][(c1+c2)/2-1] == ' ' || board[(r1+r2)/2-1][(c1+c2)/2-1] == c)
    {
        return 0;
    }

    if(board[r1-1][c1-1] == 'b' && turn == 1)
    {
        if(r2-r1 == 2 && abs(c2-c1) == 2 && board[(r1+r2)/2-1][(c1+c2)/2-1] == 'w')
        {
            board[r2-1][c2-1] = 'b';

            if(r2 == 8)
            {
                board[r2-1][c2-1] = 'B';
            }
            board[r1-1][c1-1] = ' ';
            board[(r1+r2)/2-1][(c1+c2)/2-1] = ' ';
            countw--;

            if(valid_jump() == 1)
            {
                return 1;
            }
        }
    }
    else if(board[r1-1][c1-1] == 'w' && turn == 2)
    {
        if(r1-r2 == 2 && abs(c2-c1) == 2 && board[(r1+r2)/2-1][(c1+c2)/2-1] == 'b')
        {
            board[r2-1][c2-1] = 'w';

            if(r2 == 1)
            {
                board[r2-1][c2-1] = 'W';
            }
            board[r1-1][c1-1] = ' ';
            board[(r1+r2)/2-1][(c1+c2)/2-1] = ' ';
            countb--;

            if(valid_jump() == 1)
            {
                return 1;
            }
        }
    }
    else if(board[r1-1][c1-1] == 'B' && turn == 1)
    {
        if(r2-r1 == 2 && abs(c2-c1) == 2 && board[(r1+r2)/2-1][(c1+c2)/2-1] == 'w')
        {
            board[r2-1][c2-1] = 'B';

            board[r1-1][c1-1] = ' ';
            board[(r1+r2)/2-1][(c1+c2)/2-1] = ' ';
            countw--;

            if(valid_jump() == 1)
            {
                return 1;
            }
        }
    }
    else if(board[r1-1][c1-1] == 'W' && turn == 2)
    {
        if(r1-r2 == 2 && abs(c2-c1) == 2 && board[(r1+r2)/2-1][(c1+c2)/2-1] == 'b')
        {
            board[r2-1][c2-1] = 'W';

            board[r1-1][c1-1] = ' ';
            board[(r1+r2)/2-1][(c1+c2)/2-1] = ' ';
            countb--;

            if(valid_jump() == 1)
            {
                return 1;
            }
        }
    }
    else
    {
        return 0;
    }

    return 1;
}

void swap_variables()
{
    c = board[r1-1][c1-1];
    board[r1-1][c1-1] = board[r2-1][c2-1];
    board[r2-1][c2-1] = c;
}

void check_winner()
{
    int i, j;
    countb = 0;
    countw = 0;

    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(board[i][j] == 'b' || board[i][j] == 'B')
            {
                countb++;
            }
            else if(board[i][j] == 'w' || board[i][j] == 'W')
            {
                countw++;
            }
        }
    }

    if(countb == 0 || countw == 0)
    {
        winner = 1;
    }
}