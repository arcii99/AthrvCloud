//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char player = 'X', cpu = 'O';
//function to display the board
void display(char b[3][3])
{
    printf("\n");
    for(int i=0;i<3;i++)
    {
        printf("\t\t\t");
        for(int j=0;j<3;j++)
            printf(" %c |",b[i][j]);
        printf("\n\t\t\t");
        printf("-----------");
        printf("\n");
    }
}
//function to check winning condition
int check_win(char b[3][3], char ch)
{
    if( (b[0][0]==ch && b[0][1]==ch && b[0][2]==ch) || 
        (b[1][0]==ch && b[1][1]==ch && b[1][2]==ch) || 
        (b[2][0]==ch && b[2][1]==ch && b[2][2]==ch) ||
        (b[0][0]==ch && b[1][0]==ch && b[2][0]==ch) ||
        (b[0][1]==ch && b[1][1]==ch && b[2][1]==ch) ||
        (b[0][2]==ch && b[1][2]==ch && b[2][2]==ch) ||
        (b[0][0]==ch && b[1][1]==ch && b[2][2]==ch) ||
        (b[0][2]==ch && b[1][1]==ch && b[2][0]==ch)
        )
        return 1;
    else
        return 0;
}
 
//function to check if move is possible or not
int move_possible(char b[3][3], int x, int y)
{
    if(b[x][y] == '-')
        return 1;
    else
        return 0;
}
//function to get a random move for computer
void get_random_move(char b[3][3], int *x, int *y)
{
    srand(time(NULL));
    *x = rand()%3;
    *y = rand()%3;
}
//function to get a move for computer based on calculations
void get_ai_move(char b[3][3], int *x, int *y)
{
    int sum_rows[3], sum_cols[3], sum_diag1=0, sum_diag2=0;
    int max_row=-1, max_col=-1, max_diag=-1;

    //calculate sum of rows and columns
    for(int i=0;i<3;i++)
    {
        sum_rows[i] = 0;
        sum_cols[i] = 0;
        for(int j=0;j<3;j++)
        {
            if(b[i][j]=='-')
                sum_rows[i]+=1;
            if(b[j][i]=='-')
                sum_cols[i]+=1;
        }
    }
    //calculate sum of diagonals
    if(b[0][0]=='-')
        sum_diag1+=1;
    if(b[1][1]=='-')
        sum_diag1+=1;
    if(b[2][2]=='-')
        sum_diag1+=1;

    if(b[0][2]=='-')
        sum_diag2+=1;
    if(b[1][1]=='-')
        sum_diag2+=1;
    if(b[2][0]=='-')
        sum_diag2+=1;

    //find the max sum row and column
    for(int i=0;i<3;i++)
    {
        if(sum_rows[i]>max_row)
            max_row=sum_rows[i];
        if(sum_cols[i]>max_col)
            max_col=sum_cols[i];
    }

    //find the max sum diagonal
    if(sum_diag1>max_diag)
        max_diag = sum_diag1;
    if(sum_diag2>max_diag)
        max_diag = sum_diag2;

    //make a move based on max sum row or column or diagonal
    if(max_row>=max_col && max_row>=max_diag)
    {
        for(int i=0;i<3;i++)
        {
            if(b[max_row][i]=='-')
            {
                *x = max_row;
                *y = i;
                return;
            }
        }
    }
    else if(max_col>=max_row && max_col>=max_diag)
    {
        for(int i=0;i<3;i++)
        {
            if(b[i][max_col]=='-')
            {
                *x = i;
                *y = max_col;
                return;
            }
        }
    }
    else
    {
        if(b[0][0]=='-')
        {
            *x = 0;
            *y = 0;
            return;
        }
        if(b[1][1]=='-')
        {
            *x = 1;
            *y = 1;
            return;
        }
        if(b[2][2]=='-')
        {
            *x = 2;
            *y = 2;
            return;
        }
        if(b[0][2]=='-')
        {
            *x = 0;
            *y = 2;
            return;
        }
        if(b[2][0]=='-')
        {
            *x = 2;
            *y = 0;
            return;
        }
    }
}
//function to ask human player for move and validate it
void get_user_move(char b[3][3], int *x, int *y)
{
    printf("\nEnter the row and column index (0-2) where you want to put your %c : ",player);
    scanf("%d %d",&(*x),&(*y));
    while((*x)>2 || (*y)>2)
    {
        printf("\nEnter correct indices (0-2) : ");
        scanf("%d %d",&(*x),&(*y));
    }
    while(!move_possible(b,*x,*y))
    {
        printf("\nInvalid Move! ");
        printf("\nEnter the row and column index where you want to put your %c : ",player);
        scanf("%d %d",&(*x),&(*y));
    }
}
//main function
void main()
{
    char board[3][3]={ {'-','-','-'},
                        {'-','-','-'},
                        {'-','-','-'} };
    int turn=0, x=0, y=0;

    printf("\nWelcome to Tic Tac Toe!\n\n");
    display(board);

    while(turn<9)
    {
        if(turn%2==0)
        {
            get_user_move(board,&x,&y);
            board[x][y] = player;
        }
        else
        {
            printf("\n\nComputer's Move : ");
            get_ai_move(board,&x,&y);
            printf("%d %d",x,y);
            board[x][y] = cpu;
        }
        display(board);
        if(check_win(board,player))
        {
            printf("\n\nCongratulations! You Win!\n");
            break;
        }
        if(check_win(board,cpu))
        {
            printf("\n\nSorry! You Lose!\n");
            break;
        }
        turn++;
    }
    if(!check_win(board,player) && !check_win(board,cpu))
        printf("\n\nTie Game!\n");
}