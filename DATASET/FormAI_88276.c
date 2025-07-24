//FormAI DATASET v1.0 Category: Checkers Game ; Style: configurable
#include<stdio.h> 

char board[8][8];
int turn=1;

void initialize_board()
{
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(i%2!=j%2)
            {
                if(i<=2)
                    board[i][j]='W';
                else if(i>=5)
                    board[i][j]='B';
                else
                    board[i][j]=' ';
            }
            else
                board[i][j]=' ';
}

void print_board()
{
    int i,j;
    printf("\n     1   2   3   4   5   6   7   8");
    for(i=0;i<8;i++)
    {
        printf("\n   +---+---+---+---+---+---+---+---+\n");
        printf("%d  ",i+1);
        for(j=0;j<8;j++)
        {
            printf("| %c ",board[i][j]);
        }
        printf("|");
    }
    printf("\n   +---+---+---+---+---+---+---+---+");
}

int is_valid_move(int i, int j, int p, int q)
{
    if(i<0 || i>=8 || j<0 || j>=8 || p<0 || p>=8 || q<0 || q>=8)
        return 0;
    if(board[p][q]!=' ')
        return 0;
    if(turn==1 && board[i][j]!='W' && board[i][j]!='k')
        return 0;
    if(turn==-1 && board[i][j]!='B' && board[i][j]!='K')
        return 0;
    if(abs(i-p)==1 && abs(j-q)==1)
        return 1;
    if(abs(i-p)==2 && abs(j-q)==2)
    {
        int x=(i+p)/2;
        int y=(j+q)/2;
        if(turn==1 && board[x][y]!='B' && board[x][y]!='K')
            return 0;
        if(turn==-1 && board[x][y]!='W' && board[x][y]!='k')
            return 0;
        return 1;
    }
    return 0;
}

void make_move(int i, int j, int p, int q)
{
    board[p][q]=board[i][j];
    board[i][j]=' ';
    if(abs(i-p)==2 && abs(j-q)==2)
    {
        int x=(i+p)/2;
        int y=(j+q)/2;
        board[x][y]=' ';
    }
    if(p==0 && board[p][q]=='W')
        board[p][q]='K';
    if(p==7 && board[p][q]=='B')
        board[p][q]='K';
}

void make_king(int i, int j)
{
    if(board[i][j]=='W' && i==0)
        board[i][j]='K';
    if(board[i][j]=='B' && i==7)
        board[i][j]='K';
}

int is_game_over()
{
    int i,j;
    int w=0,b=0;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(board[i][j]=='W' || board[i][j]=='K')
                w=1;
            else if(board[i][j]=='B' || board[i][j]=='k')
                b=1;
    if(w==0 || b==0)
        return 1;
    else
        return 0;
}

int main()
{
    int i,j,p,q;
    int over=0;
    initialize_board();
    print_board();
    do
    {
        printf("\nTurn %d :: ",turn);
        do
        {
            printf("Enter the row and column of the piece to be moved (eg. 3 4): ");
            scanf("%d %d",&i,&j);
        } while(board[i-1][j-1]==' ' || (turn==1 && board[i-1][j-1]!='W' && board[i-1][j-1]!='K') || (turn==-1 && board[i-1][j-1]!='B' && board[i-1][j-1]!='k'));
        do
        {
            printf("Enter the row and column of the destination (eg. 4 5): ");
            scanf("%d %d",&p,&q);
        } while(!is_valid_move(i-1,j-1,p-1,q-1));
        make_move(i-1,j-1,p-1,q-1);
        make_king(p-1,q-1);
        print_board();
        over=is_game_over();
        if(turn==1)
            turn=-1;
        else
            turn=1;
    } while(!over);
    if(board[0][0]=='W' || board[0][2]=='W' || board[0][4]=='W' || board[0][6]=='W')
        printf("\nWhite Wins!!");
    else
        printf("\nBlack Wins!!");
    return 0;
}