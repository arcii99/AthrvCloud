//FormAI DATASET v1.0 Category: Chess engine ; Style: creative
#include<stdio.h>
#include<stdlib.h>

//function to display the chess board
void display_board(char board[8][8]){
    int i,j;
    printf("\n        A   B   C   D   E   F   G   H\n");
    printf("      +---+---+---+---+---+---+---+---+\n");
    for(i=0;i<8;i++){
        printf("   %d  |",i+1);
        for(j=0;j<8;j++){
            printf(" %c |",board[i][j]);
        }
        printf("  %d\n",i+1);
        printf("      +---+---+---+---+---+---+---+---+\n");
    }
    printf("        A   B   C   D   E   F   G   H\n");
}

//function to initialize the chess board
void init_board(char board[8][8]){
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(i==0 || i==7){
                if(j==0 || j==7){
                    board[i][j] = 'R';
                }
                else if(j==1 || j==6){
                    board[i][j] = 'N';
                }
                else if(j==2 || j==5){
                    board[i][j] = 'B';
                }
                else if(j==3){
                    board[i][j] = 'Q';
                }
                else{
                    board[i][j] = 'K';
                }
            }
            else if(i==1 || i==6){
                board[i][j] = 'P';
            }
            else{
                board[i][j] = ' ';
            }
        }
    }
}

int main(){
    int i,j;
    char board[8][8];
    init_board(board);
    display_board(board);
    return 0;
}