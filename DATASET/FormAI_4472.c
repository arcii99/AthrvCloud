//FormAI DATASET v1.0 Category: Checkers Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int board[8][8] = { {0,1,0,1,0,1,0,1},
                    {1,0,1,0,1,0,1,0},
                    {0,1,0,1,0,1,0,1},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {-1,0,-1,0,-1,0,-1,0},
                    {0,-1,0,-1,0,-1,0,-1},
                    {-1,0,-1,0,-1,0,-1,0} };
                    
void display_board() {
    int i,j;
    printf("\n\t    A   B   C   D   E   F   G   H");
    printf("\n\t  +---+---+---+---+---+---+---+---+");
    for (i=0;i<8;i++) {
        printf("\n\t%d |",i+1);
        for (j=0;j<8;j++) {
            if (board[i][j]==0) {
                printf("   |");
            }
            else if (board[i][j]==1) {
                printf(" X |");
            }
            else if (board[i][j]==-1) {
                printf(" O |");
            }
        }
        printf(" %d",i+1);
        printf("\n\t  +---+---+---+---+---+---+---+---+");
    }
    printf("\n\t    A   B   C   D   E   F   G   H\n");
}

int main() {
    printf("\nCHECKERS GAME\n");
    char from[2],to[2];
    int x1,x2,y1,y2;
    char ch;
    int player=1;
    while(1) {
        display_board();
        printf("\nPlayer %d's turn:",player);
        printf("\nMove from:");
        scanf("%s",from);
        x1=from[1]-'0';
        y1=from[0]-'A';
        printf("\nMove to:");
        scanf("%s",to);
        x2=to[1]-'0';
        y2=to[0]-'A';
        if (board[x1-1][y1]==1) {
            if ((x2==x1-1 && y2==y1-1) || (x2==x1-1 && y2==y1+1)) {
                if (board[x2-1][y2]==-1) {
                    board[x2-1][y2]=0;
                }
                board[x1-1][y1]=0;
                board[x2-1][y2]=1;
                player=2;
            }
            else if ((x2==x1-2 && y2==y1-2) || (x2==x1-2 && y2==y1+2)) {
                if (board[x2-1][y2]==0) {
                    if (board[x1-2][y1-2]==-1 || board[x1-2][y1+2]==-1) {
                        board[x1-1][y1]=0;
                        board[x2-1][y2]=1;
                        if (board[x1-2][y1-2]==-1) {
                            board[x1-2][y1-2]=0;
                        }
                        else {
                            board[x1-2][y1+2]=0;
                        }
                        player=2;
                    }
                }
            }
            else {
                printf("\nInvalid move...try again.\n");
            }
        }
        else if (board[x1-1][y1]==-1) {
            if ((x2==x1+1 && y2==y1-1) || (x2==x1+1 && y2==y1+1)) {
                if (board[x2-1][y2]==1) {
                    board[x2-1][y2]=0;
                }
                board[x1-1][y1]=0;
                board[x2-1][y2]=-1;
                player=1;
            }
            else if ((x2==x1+2 && y2==y1-2) || (x2==x1+2 && y2==y1+2)) {
                if (board[x2-1][y2]==0) {
                    if (board[x1][y1-2]==1 || board[x1][y1+2]==1) {
                        board[x1-1][y1]=0;
                        board[x2-1][y2]=-1;
                        if (board[x1][y1-2]==1) {
                            board[x1][y1-2]=0;
                        }
                        else {
                            board[x1][y1+2]=0;
                        }
                        player=1;
                    }
                }
            }
            else {
                printf("\nInvalid move...try again.\n");
            }
        }

        // check if game over
        int i,j,cnt1=0,cnt2=0;
        for (i=0;i<8;i++) {
            for (j=0;j<8;j++) {
                if (board[i][j]==1) {
                    cnt1++;
                }
                else if (board[i][j]==-1) {
                    cnt2++;
                }
            }
        }
        if (cnt1==0) {
            printf("\nPlayer 2 wins!");
            break;
        }
        else if (cnt2==0) {
            printf("\nPlayer 1 wins!");
            break;
        }
    }
    printf("\nThanks for playing.");
    return 0;
}