//FormAI DATASET v1.0 Category: Checkers Game ; Style: inquisitive
#include <stdio.h> 

int main() 
{    
    int board[8][8]={{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0},    
                      {0,1,0,1,0,1,0,1},{0,0,0,0,0,0,0,0},    
                      {0,0,0,0,0,0,0,0},{2,0,2,0,2,0,2,0},    
                      {0,2,0,2,0,2,0,2},{2,0,2,0,2,0,2,0}}; //initialize checkers board    
    int turn=1, x1, y1, x2, y2, piece;   
    while(1) //game loop   
    {    
        printf("\n");
        for(int i=0;i<8;i++)
        {
            printf("-----------------\n|");
            for(int j=0;j<8;j++)
            {
                if(board[i][j]==0||board[i][j]==1) printf(" |"); //empty space or player 1's piece  
                else if(board[i][j]==2) printf("O|"); //player 2's piece
                else printf("X|"); //player 1's king piece
            }
            printf("\n");
        }
        printf("-----------------\n");
        if(turn==1) printf("\nPlayer 1's turn!");
        else printf("\nPlayer 2's turn!");

        printf("\nEnter the coordinates of the piece you want to move (x,y): ");
        scanf("%d,%d", &x1, &y1);

        piece=board[x1][y1];
        if((turn==1&&piece==1)||(turn==2&&piece==2)) //valid piece to move
        {
            printf("\nEnter the coordinates of where you want to move the piece (x,y): ");
            scanf("%d,%d", &x2, &y2);

            if(x2<0||x2>7||y2<0||y2>7) //invalid move
            {
                printf("\nInvalid move!");
            }
            else if(board[x2][y2]!=0) //occupied space
            {
                printf("\nSpace already occupied!");
            }   
            else //valid move
            {
                board[x1][y1]=0;
                board[x2][y2]=piece;
                if(turn==1&&x2==7) //player 1 kinged their piece
                {
                    board[x2][y2]=3;
                    printf("\nPlayer 1 kinged a piece!");
                }
                else if(turn==2&&x2==0) //player 2 kinged their piece
                {
                    board[x2][y2]=4;
                    printf("\nPlayer 2 kinged a piece!");
                }
                turn=3-turn; //switch turns 
            }
        }
        else //invalid piece to move
        {
            printf("\nInvalid piece to move!");
        }
        //check for game over (no more pieces on one side)
        int p1=0, p2=0;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                if(board[i][j]==1||board[i][j]==3) p1++;
                else if(board[i][j]==2||board[i][j]==4) p2++;
            }
        }
        if(p1==0||p2==0) 
        {
            printf("\nGame over! ");
            if(p1==0) printf("Player 2 wins!");
            else printf("Player 1 wins!");
            break; //exit game loop
        }
    }
    return 0;
}