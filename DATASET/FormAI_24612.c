//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int board[3][3];

void init_board()
{
    int i,j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            board[i][j]=-1;
}

void print_board()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==-1)
                printf("  -  ");
            if(board[i][j]==0)
                printf("  O  ");
            if(board[i][j]==1)
                printf("  X  ");
        }    
        printf("\n\n");
    }
}

int check_win()
{
    int i;
    for(i=0;i<3;i++)
    {
        if(board[i][0]!=-1 && board[i][0]==board[i][1] && board[i][1]==board[i][2])
            return board[i][0];
        if(board[0][i]!=-1 && board[0][i]==board[1][i] && board[1][i]==board[2][i])
            return board[0][i];
    }
    if(board[0][0]!=-1 && board[0][0]==board[1][1] && board[1][1]==board[2][2])
        return board[0][0];
    if(board[0][2]!=-1 && board[0][2]==board[1][1] && board[1][1]==board[2][0])
        return board[0][2];
    return -1;
}

int evaluate()
{
    int result=check_win();
    if(result==0)
        return 10;
    else if(result==1)
        return -10;
    else
        return 0;
}

int minimax(int depth, int player)
{
    int score=evaluate();
    if(score==10 || score==-10)
        return score;
    if(depth==9)
        return 0;
    int best_score,i,j;
    if(player==0)
    {
        best_score=-1000;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(board[i][j]==-1)
                {
                    board[i][j]=0;
                    int current_score=minimax(depth+1,1);
                    board[i][j]=-1;
                    best_score=(current_score>best_score)?current_score:best_score;
                }
            }
        }
    }
    else
    {
        best_score=1000;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(board[i][j]==-1)
                {
                    board[i][j]=1;
                    int current_score=minimax(depth+1,0);
                    board[i][j]=-1;
                    best_score=(current_score<best_score)?current_score:best_score;
                }
            }
        }
    }
    return best_score;
}

void make_move()
{
    int i,j;
    int best_score=-1000;
    int best_i,best_j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(board[i][j]==-1)
            {
                board[i][j]=0;
                int current_score=minimax(0,1);
                board[i][j]=-1;
                if(current_score>best_score)
                {
                    best_score=current_score;
                    best_i=i;
                    best_j=j;
                }
            }
        }
    }
    board[best_i][best_j]=0;
}

int main()
{
    srand(time(NULL));
    init_board();
    int turn=rand()%2;
    int i,j,move_count=0;
    while(move_count<9)
    {
        if(turn==0)
        {
            printf("Player's turn:\n");
            print_board();
            printf("Enter [row] [column]: ");
            scanf("%d %d",&i,&j);
            if(board[i][j]==-1)
            {
                board[i][j]=1;
                move_count++;
            }
            else
            {
                printf("Invalid move!\n");
                continue;
            }
        }
        else
        {
            printf("Computer's turn:\n");
            make_move();
            move_count++;
        }
        turn=1-turn;
        int result=check_win();
        if(result!=-1)
        {
            print_board();
            if(result==1)
                printf("You win!\n");
            else
                printf("You lose!\n");
            return 0;
        }
    }
    printf("Draw!\n");
    return 0;
}