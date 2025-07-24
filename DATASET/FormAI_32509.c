//FormAI DATASET v1.0 Category: Chess AI ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int board[8][8]; //global chess board

void print_board() //function to print the chess board
{
    printf("-----------------------------------\n");
    for(int i=0;i<8;i++)
    {
        printf("|");
        for(int j=0;j<8;j++)
        {
            if(board[i][j]==0) printf("      |");
            else if(board[i][j]==1) printf("  P   |");
            else if(board[i][j]==2) printf("  R   |");
            else if(board[i][j]==3) printf("  K   |");
            else if(board[i][j]==4) printf("  B   |");
            else if(board[i][j]==5) printf("  Q   |");
            else if(board[i][j]==6) printf("  K   |");
            else if(board[i][j]==-1) printf("  p   |");
            else if(board[i][j]==-2) printf("  r   |");
            else if(board[i][j]==-3) printf("  k   |");
            else if(board[i][j]==-4) printf("  b   |");
            else if(board[i][j]==-5) printf("  q   |");
            else if(board[i][j]==-6) printf("  k   |");
        }
        printf("\n");
        printf("-----------------------------------\n");
    }
}

int abs(int x) //function to return absolute value of a number
{
    if(x<0) return -x;
    return x;
}

int is_still_in_board(int x, int y) //function to check if a given coordinate is still inside the board or not
{
    if(x<0 || x>7 || y<0 || y>7) return 0;
    return 1;
}

int pawn_move(int x1, int y1, int x2, int y2) //function to check if valid pawn move
{
    if(board[x1][y1]>0) //if it's white player's pawn
    {
        if(x2==x1-1 && y2==y1 && board[x2][y2]==0) return 1; //move one step ahead
        if(x2==x1-2 && y2==y1 && x1==6 && board[x2][y2]==0) return 1; //move two steps ahead
        if(x2==x1-1 && abs(y2-y1)==1 && board[x2][y2]<0) return 1; //capture opponent's pawn
    }
    else //if it's black player's pawn
    {
        if(x2==x1+1 && y2==y1 && board[x2][y2]==0) return 1; //move one step ahead
        if(x2==x1+2 && y2==y1 && x1==1 && board[x2][y2]==0) return 1; //move two steps ahead
        if(x2==x1+1 && abs(y2-y1)==1 && board[x2][y2]>0) return 1; //capture opponent's pawn
    }
    return 0; //if none of the above conditions are met
}

int rook_move(int x1, int y1, int x2, int y2) //function to check if valid rook move
{
    if(x1==x2) //if moving horizontally
    {
        if(y2>y1) //if moving right
        {
            for(int i=y1+1;i<y2;i++)
                if(board[x1][i]!=0) return 0; //no other piece should be on the way
            if(board[x2][y2]==0 || (board[x2][y2]<0 && board[x1][y1]>0) || (board[x2][y2]>0 && board[x1][y1]<0)) return 1; //if the destination square is empty or has opposite color's piece
        }
        else //if moving left
        {
            for(int i=y1-1;i>y2;i--)
                if(board[x1][i]!=0) return 0; //no other piece should be on the way
            if(board[x2][y2]==0 || (board[x2][y2]<0 && board[x1][y1]>0) || (board[x2][y2]>0 && board[x1][y1]<0)) return 1; //if the destination square is empty or has opposite color's piece
        }
    }
    else if(y1==y2) //if moving vertically
    {
        if(x2>x1) //if moving down
        {
            for(int i=x1+1;i<x2;i++)
                if(board[i][y1]!=0) return 0; //no other piece should be on the way
            if(board[x2][y2]==0 || (board[x2][y2]<0 && board[x1][y1]>0) || (board[x2][y2]>0 && board[x1][y1]<0)) return 1; //if the destination square is empty or has opposite color's piece
        }
        else //if moving up
        {
            for(int i=x1-1;i>x2;i--)
                if(board[i][y1]!=0) return 0; //no other piece should be on the way
            if(board[x2][y2]==0 || (board[x2][y2]<0 && board[x1][y1]>0) || (board[x2][y2]>0 && board[x1][y1]<0)) return 1; //if the destination square is empty or has opposite color's piece
        }
    }
    else return 0; //if neither of the above conditions are met
}

int knight_move(int x1, int y1, int x2, int y2) //function to check if valid knight move
{
    if((abs(x2-x1)==2 && abs(y2-y1)==1) || (abs(x2-x1)==1 && abs(y2-y1)==2)) //if the move is like an 'L'
    {
        if(board[x2][y2]==0 || (board[x2][y2]<0 && board[x1][y1]>0) || (board[x2][y2]>0 && board[x1][y1]<0)) return 1; //if the destination square is empty or has opposite color's piece
    }
    return 0; //if above condition is not met
}

int bishop_move(int x1, int y1, int x2, int y2) //function to check if valid bishop move
{
    if(abs(x2-x1)==abs(y2-y1)) //if moving diagonally
    {
        if(x2>x1 && y2>y1) //if moving northeast
        {
            for(int i=1;i<x2-x1;i++)
                if(board[x1+i][y1+i]!=0) return 0; //no other piece should be on the way
            if(board[x2][y2]==0 || (board[x2][y2]<0 && board[x1][y1]>0) || (board[x2][y2]>0 && board[x1][y1]<0)) return 1; //if the destination square is empty or has opposite color's piece
        }
        else if(x2>x1 && y2<y1) //if moving northwest
        {
            for(int i=1;i<x2-x1;i++)
                if(board[x1+i][y1-i]!=0) return 0; //no other piece should be on the way
            if(board[x2][y2]==0 || (board[x2][y2]<0 && board[x1][y1]>0) || (board[x2][y2]>0 && board[x1][y1]<0)) return 1; //if the destination square is empty or has opposite color's piece
        }
        else if(x2<x1 && y2<y1) //if moving southwest
        {
            for(int i=1;i<x1-x2;i++)
                if(board[x1-i][y1-i]!=0) return 0; //no other piece should be on the way
            if(board[x2][y2]==0 || (board[x2][y2]<0 && board[x1][y1]>0) || (board[x2][y2]>0 && board[x1][y1]<0)) return 1; //if the destination square is empty or has opposite color's piece
        }
        else if(x2<x1 && y2>y1) //if moving southeast
        {
            for(int i=1;i<x1-x2;i++)
                if(board[x1-i][y1+i]!=0) return 0; //no other piece should be on the way
            if(board[x2][y2]==0 || (board[x2][y2]<0 && board[x1][y1]>0) || (board[x2][y2]>0 && board[x1][y1]<0)) return 1; //if the destination square is empty or has opposite color's piece
        }
    }
    return 0; //if none of the above conditions are met
}

int queen_move(int x1, int y1, int x2, int y2) //function to check if valid queen move
{
    if(rook_move(x1, y1, x2, y2) || bishop_move(x1, y1, x2, y2)) return 1; //if it's either a valid rook move or a valid bishop move
    return 0; //if none of the above conditions are met
}

int king_move(int x1, int y1, int x2, int y2) //function to check if valid king move
{
    if(abs(x2-x1)<=1 && abs(y2-y1)<=1 && board[x2][y2]!=board[x1][y1]) return 1; //if moving only one step in any direction and the destination square is not of same color
    return 0; //if the above condition is not met
}

void initialize_board() //function to initialize the chess board
{
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) board[i][j]=0; //clear the board
    for(int j=0;j<8;j++)
    {
        board[1][j]=-1; //set black pawns
        board[6][j]=1; //set white pawns
    }
    board[0][0]=-2; board[0][7]=-2; //set black rooks
    board[7][0]=2; board[7][7]=2; //set white rooks
    board[0][1]=-3; board[0][6]=-3; //set black knights
    board[7][1]=3; board[7][6]=3; //set white knights
    board[0][2]=-4; board[0][5]=-4; //set black bishops
    board[7][2]=4; board[7][5]=4; //set white bishops
    board[0][3]=-5; board[7][3]=5; //set queens
    board[0][4]=-6; board[7][4]=6; //set kings
}

void copy_board(int b[8][8], int bb[8][8]) //function to copy one chess board into another
{
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) bb[i][j]=b[i][j];
}

int get_score() //function to calculate the score of the current board configuration
{
    int score=0;
    for(int i=0;i<8;i++) for(int j=0;j<8;j++) score+=board[i][j];
    return score;
}

int minimax(int depth, int alpha, int beta, int is_max_player) //function for minimax algorithm
{
    if(depth==0) return -get_score();
    int b[8][8], s;
    copy_board(board, b);
    if(is_max_player) //max player
    {
        int max_score=-9999;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j]>0) //if it's white player's piece
                {
                    for(int i2=0;i2<8;i2++)
                    {
                        for(int j2=0;j2<8;j2++)
                        {
                            if(queen_move(i, j, i2, j2))
                            {
                                int temp=board[i2][j2];
                                board[i2][j2]=board[i][j];
                                board[i][j]=0;
                                s=-minimax(depth-1, -beta, -alpha, 0);
                                if(s>=beta) return s;
                                if(s>max_score) max_score=s;
                                alpha=(alpha>s)?alpha:s;
                                copy_board(b, board);
                            }
                        }
                    }
                }
                else if(board[i][j]<0) //if it's black player's piece
                {
                    for(int i2=0;i2<8;i2++)
                    {
                        for(int j2=0;j2<8;j2++)
                        {
                            if(queen_move(i, j, i2, j2))
                            {
                                int temp=board[i2][j2];
                                board[i2][j2]=board[i][j];
                                board[i][j]=0;
                                s=-minimax(depth-1, -beta, -alpha, 0);
                                if(s>=beta) return s;
                                if(s>max_score) max_score=s;
                                alpha=(alpha>s)?alpha:s;
                                copy_board(b, board);
                            }
                        }
                    }
                }
            }
        }
        return max_score;
    }
    else //min player
    {
        int min_score=9999;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j]>0) //if it's white player's piece
                {
                    for(int i2=0;i2<8;i2++)
                    {
                        for(int j2=0;j2<8;j2++)
                        {
                            if(queen_move(i, j, i2, j2))
                            {
                                int temp=board[i2][j2];
                                board[i2][j2]=board[i][j];
                                board[i][j]=0;
                                s=-minimax(depth-1, -beta, -alpha, 1);
                                if(s<=alpha) return s;
                                if(s<min_score) min_score=s;
                                beta=(beta<s)?beta:s;
                                copy_board(b, board);
                            }
                        }
                    }
                }
                else if(board[i][j]<0) //if it's black player's piece
                {
                    for(int i2=0;i2<8;i2++)
                    {
                        for(int j2=0;j2<8;j2++)
                        {
                            if(queen_move(i, j, i2, j2))
                            {
                                int temp=board[i2][j2];
                                board[i2][j2]=board[i][j];
                                board[i][j]=0;
                                s=-minimax(depth-1, -beta, -alpha, 1);
                                if(s<=alpha) return s;
                                if(s<min_score) min_score=s;
                                beta=(beta<s)?beta:s;
                                copy_board(b, board);
                            }
                        }
                    }
                }
            }
        }
        return min_score;
    }
}

void make_computer_move() //function to make the computer's move
{
    int b[8][8], max_score=-9999, x1, y1, x2, y2;
    copy_board(board, b);
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board[i][j]<0)
            {
                for(int i2=0;i2<8;i2++)
                {
                    for(int j2=0;j2<8;j2++)
                    {
                        if(queen_move(i, j, i2, j2))
                        {
                            int temp=board[i2][j2];
                            board[i2][j2]=board[i][j];
                            board[i][j]=0;
                            int s=-minimax(3, -9999, 9999, 1);
                            if(s>max_score)
                            {
                                max_score=s;
                                x1=i;
                                y1=j;
                                x2=i2;
                                y2=j2;
                            }
                            copy_board(b, board);
                        }
                    }
                }
            }
        }
    }
    board[x2][y2]=board[x1][y1];
    board[x1][y1]=0;
    print_board();
}

int main() //main function
{
    initialize_board();
    print_board();
    printf("\n");
    while(1)
    {
        int x1, y1, x2, y2;
        printf("Enter coordinates for your move (ex: 0 1 1 1): ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(queen_move(x1, y1, x2, y2))
        {
            board[x2][y2]=board[x1][y1];
            board[x1][y1]=0;
            print_board();
            printf("\n");
            make_computer_move();
            printf("\n");
        }
        else printf("Invalid Move!\n");
    }
    return 0;
}