//FormAI DATASET v1.0 Category: Chess AI ; Style: invasive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define INFINITY 2147483647
#define DEPTH 3

int eval(char board[][8])
{
    int score = 0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            switch(board[i][j])
            {
                case 'P': score += 10;
                    break;
                case 'p': score -= 10;
                    break;
                case 'N': score += 30;
                    break;
                case 'n': score -= 30;
                    break;
                case 'B': score += 30;
                    break;
                case 'b': score -= 30;
                    break;
                case 'R': score += 50;
                    break;
                case 'r': score -= 50;
                    break;
                case 'Q': score += 90;
                    break;
                case 'q': score -= 90;
                    break;
            }
        }
    }
    return score;
}

int min(int a,int b)
{
    return a<b?a:b;
}

int max(int a,int b)
{
    return a>b?a:b;
}

int alpha_beta_prune(char board[][8],int depth,int alpha,int beta,bool player)
{
    if(depth==0)
    {
        return eval(board);
    }
    if(player)
    {
        int score = -INFINITY;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j]>='A' && board[i][j]<='Z')
                {
                    char o = board[i][j];
                    board[i][j] = ' ';
                    for(int p=0;p<8;p++)
                    {
                        for(int m=0;m<8;m++)
                        {
                            if(board[p][m]==' ')
                            {
                                board[p][m] = o;
                                int temp = alpha_beta_prune(board,depth-1,alpha,beta,false);
                                board[p][m] = ' ';
                                score = max(score,temp);
                                alpha = max(alpha,score);
                                if(beta<=alpha)
                                {
                                    return score;
                                }
                            }
                        }
                    }
                    board[i][j] = o;
                }
            }
        }
        return score;
    }
    else
    {
        int score = INFINITY;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j]>='a' && board[i][j]<='z')
                {
                    char o = board[i][j];
                    board[i][j] = ' ';
                    for(int p=0;p<8;p++)
                    {
                        for(int m=0;m<8;m++)
                        {
                            if(board[p][m]==' ')
                            {
                                board[p][m] = o;
                                int temp = alpha_beta_prune(board,depth-1,alpha,beta,true);
                                board[p][m] = ' ';
                                score = min(score,temp);
                                beta = min(beta,score);
                                if(beta<=alpha)
                                {
                                    return score;
                                }
                            }
                        }
                    }
                    board[i][j] = o;
                }
            }
        }
        return score;
    }
}

void makeMove(char board[][8], int depth, bool player) {

    int source_row,source_col,target_row,target_col;
    int max_score = -INFINITY;
    int min_score = INFINITY;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(player)
            {
                if(board[i][j]>='A' && board[i][j]<='Z')
                {
                    char o = board[i][j];
                    board[i][j] = ' ';
                    for(int p=0;p<8;p++)
                    {
                        for(int m=0;m<8;m++)
                        {
                            if(board[p][m]==' ')
                            {
                                board[p][m] = o;
                                int temp = alpha_beta_prune(board,depth-1,-INFINITY,INFINITY,false);
                                board[p][m] = ' ';
                                if(temp>max_score)
                                {
                                    max_score = temp;
                                    source_row = i;
                                    source_col = j;
                                    target_row = p;
                                    target_col = m;
                                }
                            }
                        }
                    }
                    board[i][j] = o;
                }
            }
            else
            {
                if(board[i][j]>='a' && board[i][j]<='z')
                {
                    char o = board[i][j];
                    board[i][j] = ' ';
                    for(int p=0;p<8;p++)
                    {
                        for(int m=0;m<8;m++)
                        {
                            if(board[p][m]==' ')
                            {
                                board[p][m] = o;
                                int temp = alpha_beta_prune(board,depth-1,-INFINITY,INFINITY,true);
                                board[p][m] = ' ';
                                if(temp<min_score)
                                {
                                    min_score = temp;
                                    source_row = i;
                                    source_col = j;
                                    target_row = p;
                                    target_col = m;
                                }
                            }
                        }
                    }
                    board[i][j] = o;
                }
            }
        }
    }

    printf("%c%d-%c%d\n",(char)(source_col+'a'),8-source_row,(char)(target_col+'a'),8-target_row);
    board[target_row][target_col] = board[source_row][source_col];
    board[source_row][source_col] = ' ';
}

int main()
{
    char board[8][8] = {{'r','n','b','q','k','b','n','r'},
                        {'p','p','p','p','p','p','p','p'},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {'P','P','P','P','P','P','P','P'},
                        {'R','N','B','Q','K','B','N','R'}};
    int depth = DEPTH;
    bool player = true;

    makeMove(board,depth,player);

    return 0;
}