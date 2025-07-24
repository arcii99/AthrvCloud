//FormAI DATASET v1.0 Category: Chess engine ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDEPTH 10
#define W_INFTY 30000
#define B_INFTY -30000

int pawn=100;
int knight=320;
int bishop=333;
int rook=500;
int queen=900;
int king=20000;

int board[8][8]=
{{16,2,3,4,5,3,2,16},
{1,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{-1,-1,-1,-1,-1,-1,-1,-1},
{-16,-2,-3,-4,-5,-3,-2,-16}};

struct Position
{
    int PieceValue,MoveValue;
    int square;
}table[64][64];

int eval(int color)
{
    int piece_color;
    int value=0,i,j;
    int white_value=0,black_value=0,material_evaluation=0,non_material_evaluation=0;

    if(color==1) piece_color=1;
    else if(color==-1) piece_color=-1;

    for(i=0;i<=7;++i)
    {
        for(j=0;j<=7;++j)
        {
            if(board[i][j])
            {
                if(board[i][j]>0)
                {
                    white_value+=table[i][j].PieceValue;
                }
                else
                {
                    black_value+=table[i][j].PieceValue;
                }
            }
        }
    }

    material_evaluation=(white_value-black_value)*piece_color;

    for(i=0;i<=7;++i)
    {
         for(j=0;j<=7;++j)
         {
             if(board[i][j]>0) value+=table[i][j].MoveValue;
             else if(board[i][j]<0) value+=table[i][j].MoveValue;
         }
    }

    non_material_evaluation=value*piece_color;

    return material_evaluation+non_material_evaluation;
}

void moves(int player,int depth,int alpha,int beta,int *best_move,int *best_value)
{
    int move_list[1000],pos=0,i,j, k, x, y, temp1, temp2;
    int temp_board[8][8]={0},old_board[8][8];
    int max_value=-99999,min_value=99999,value;
    int move_count=0,old_square=0;
    int pieces[6],piece,index=0,old_piece=0;

    if(!depth)
    {
        int val=eval(player);
        *best_value=val;
        return;
    }

    for(i=0;i<=7;++i)
    {
        for(j=0;j<=7;++j)
        {
            if(board[i][j] && board[i][j]/abs(board[i][j])==player)
            {
                switch(abs(board[i][j]))
                {
                    case 1: //pawns
                        if(player==1 && i!=0 && board[i-1][j]<=0)
                        {
                            move_list[pos+1]=i*10+j;
                            move_list[pos+2]=(i-1)*10+j;
                            move_list[pos+3]=board[i-1][j];
                            pos+=3;
                        }
                        else if(player==-1 && i!=7 && board[i+1][j]>=0)
                        {
                            move_list[pos+1]=i*10+j;
                            move_list[pos+2]=(i+1)*10+j;
                            move_list[pos+3]=board[i+1][j];
                            pos+=3;
                        }
                        break;

                     case 2: //knights
                         // loop through direction of knight positions
                         for(k=0;k<=7;++k)
                         {
                            x=i+((k==0)?-1:(k==1)?-2:(k==2)?-2:(k==3)?-1:(k==4)?1:(k==5)?2:(k==6)?2:1);
                            y=j+((k==0)?-2:(k==1)?-1:(k==2)?1:(k==3)?2:(k==4)?2:(k==5)?1:(k==6)?-1:-2);

                            if(x>=0 && y>=0 && x<=7 && y<=7)
                            {
                                if(board[x][y]>=0 && board[x][y]/abs(board[x][y])!=player)
                                {
                                    move_list[pos+1]=i*10+j;
                                    move_list[pos+2]=x*10+y;
                                    move_list[pos+3]=board[x][y];
                                    pos+=3;
                                }
                            }
                        }
                        break;
                    case 3: //bishops
                        //loop through all of following directions for bishop movements
                        for(k=0;k<=7;++k)
                        {
                            x=i+((k==0)?-1:(k==1)?-1:(k==2)?1:1);
                            y=j+((k==0)?-1:(k==1)?1:(k==2)?1:-1);

                            while(x>=0 && y>=0 && x<=7 && y<=7 && board[x][y]==0)
                            {
                                move_list[pos+1]=i*10+j;
                                move_list[pos+2]=x*10+y;
                                move_list[pos+3]=0;
                                pos+=3;
                                x+=((k==0)?-1:(k==1)?1:(k==2)?1:-1);
                                y+=((k==0)?-1:(k==1)?1:(k==2)?1:-1);
                            }
                            if(x>=0 && y>=0 && x<=7 && y<=7 && board[x][y]*player<=0)
                            {
                                move_list[pos+1]=i*10+j;
                                move_list[pos+2]=x*10+y;
                                move_list[pos+3]=board[x][y];
                                pos+=3;
                            }
                         }
                        break;
                    case 4: //rooks
                        // loop through directions rooks can take
                        for(k=0;k<=7;++k)
                        {
                            x=i+((k==0)?-1:(k==1)?0:(k==2)?1:0);
                            y=j+((k==0)?0:(k==1)?-1:(k==2)?0:1);

                            while(x>=0 && y>=0 && x<=7 && y<=7 && board[x][y]==0)
                            {
                                move_list[pos+1]=i*10+j;
                                move_list[pos+2]=x*10+y;
                                move_list[pos+3]=0;
                                pos+=3;
                                x+=((k==0)?-1:(k==1)?0:(k==2)?1:0);
                                y+=((k==0)?0:(k==1)?-1:(k==2)?0:1);
                            }
                            if(x>=0 && y>=0 && x<=7 && y<=7 && board[x][y]*player<=0)
                            {
                                move_list[pos+1]=i*10+j;
                                move_list[pos+2]=x*10+y;
                                move_list[pos+3]=board[x][y];
                                pos+=3;
                            }
                         }
                         break;

                     case 5: //queen
                        piece=player*5;
                        // loop through diagonal and rook possible directions
                        for(k=0;k<=7;++k)
                        {
                            x=i+((k==0)?-1:(k==1)?-1:(k==2)?1:1);
                            y=j+((k==0)?-1:(k==1)?1:(k==2)?1:-1);

                            while(x>=0 && y>=0 && x<=7 && y<=7 && board[x][y]==0)
                            {
                                move_list[pos+1]=i*10+j;
                                move_list[pos+2]=x*10+y;
                                move_list[pos+3]=0;
                                pos+=3;
                                x+=((k==0)?-1:(k==1)?-1:(k==2)?1:1);
                                y+=((k==0)?-1:(k==1)?1:(k==2)?1:-1);
                            }

                            if(x>=0 && y>=0 && x<=7 && y<=7 && board[x][y]*player<=0)
                            {
                                move_list[pos+1]=i*10+j;
                                move_list[pos+2]=x*10+y;
                                move_list[pos+3]=board[x][y];
                                pos+=3;
                            }
                        }

                        for(k=0;k<=7;++k)
                        {
                            x=i+((k==0)?-1:(k==1)?0:(k==2)?1:0);
                            y=j+((k==0)?0:(k==1)?-1:(k==2)?0:1);

                            while(x>=0 && y>=0 && x<=7 && y<=7 && board[x][y]==0)
                            {
                                move_list[pos+1]=i*10+j;
                                move_list[pos+2]=x*10+y;
                                move_list[pos+3]=0;
                                pos+=3;
                                x+=((k==0)?-1:(k==1)?0:(k==2)?1:0);
                                y+=((k==0)?0:(k==1)?-1:(k==2)?0:1);
                            }
                            if(x>=0 && y>=0 && x<=7 && y<=7 && board[x][y]*player<=0)
                            {
                                move_list[pos+1]=i*10+j;
                                move_list[pos+2]=x*10+y;
                                move_list[pos+3]=board[x][y];
                                pos+=3;
                            }
                        }
                        break;

                    case 6: //king
                        for(k=0;k<=7;++k)
                        {
                            x=i+((k==0)?-1:(k==1)?-1:(k==2)?-1:(k==3)?0:(k==4)?1:(k==5)?1:(k==6)?1:0);
                            y=j+((k==0)?-1:(k==1)?0:(k==2)?1:(k==3)?1:(k==4)?1:(k==5)?0:(k==6)?-1:-1);

                            if(x>=0 && y>=0 && x<=7 && y<=7 && board[x][y]*player<=0)
                            {
                                move_list[pos+1]=i*10+j;
                                move_list[pos+2]=x*10+y;
                                move_list[pos+3]=board[x][y];
                                pos+=3;
                            }
                        }

                        for(x=i-1;x<=i+1;++x)
                        {
                            if(x<0 || x>=8) continue;

                            for(y=j-1;y<=j+1;++y)
                            {
                                if(y<0 || y>=8) continue;

                                if(board[x][y]*player>0 || (x==i && y==j)) continue;

                                if(!board[x][y])
                                {
                                    move_list[pos+1]=i*10+j;
                                    move_list[pos+2]=x*10+y;
                                    move_list[pos+3]=0;
                                    pos+=3;
                                }
                            }
                        }
                        break;

                    default:
                        break;
                }
            }
        }
    }

    for(i=1;i<=pos;i+=3)
    {
        old_square=board[move_list[i+1]/10][move_list[i+1]%10];
        board[move_list[i+2]/10][move_list[i+2]%10]=board[move_list[i+1]/10][move_list[i+1]%10];
        board[move_list[i+1]/10][move_list[i+1]%10]=0;

        if(old_square==-player*6)
        {
            if(player==1)
            {
                king=0;
                while(king<64 && board[king/8][king%8]!=player*6) king++;
                board[move_list[i+2]/10][move_list[i+2]%10]=-player*6;
                board[move_list[i+1]/10][move_list[i+1]%10]=old_square;
                if(king!=64) continue;
            }
            else
            {
                king=0;
                while(king<64 && board[king/8][king%8]!=player*6) king++;
                board[move_list[i+2]/10][move_list[i+2]%10]=-player*6;
                board[move_list[i+1]/10][move_list[i+1]%10]=old_square;
                if(king!=64) continue;
            }
        }

        moves(player*-1,depth-1,alpha,beta,best_move,&value);

        if((player==1 && value>=beta) || (player==-1 && value<=alpha))
        {
            board[move_list[i+1]/10][move_list[i+1]%10]=old_square;
            board[move_list[i+2]/10][move_list[i+2]%10]=move_list[i+3];
            return;
        }

        if(player==1 && value>max_value) //maximizing value
        {
            max_value=value;
            *best_move=i;
            *best_value=value;
        }

        else if(player==-1 && value<min_value) //minimizing value
        {
            min_value=value;
            *best_move=i;
            *best_value=value;
        }

        board[move_list[i+1]/10][move_list[i+1]%10]=old_square;
        board[move_list[i+2]/10][move_list[i+2]%10]=move_list[i+3];
    }

    if(player==1) *best_value=max_value;
    if(player==-1) *best_value=min_value;

    return;
}

void method_name()
{
    int i,j,x,y,piece,best_move,best_value,move_list[1000]= {0},pos=0,max_value=-9999;

    for(i=0;i<=7;++i)
    {
        for(j=0;j<=7;++j)
        {
            if(board[i][j]==6)
            {
                x=i;
                y=j;
            }
        }
    }

    moves(1,MAXDEPTH,-W_INFTY,W_INFTY,&best_move,&best_value);

    printf("Move %d\n",best_move);

    return;
}

int main()
{
    method_name();

    return 0;
}