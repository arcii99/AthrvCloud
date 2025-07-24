//FormAI DATASET v1.0 Category: Checkers Game ; Style: optimized
#include<stdio.h>

// Creating a function to display the checker board
void display_board(char board[][8]){
    int i,j;
    printf("  A B C D E F G H\n");
    for(i=0;i<8;i++){
        printf("%d ",i+1);
        for(j=0;j<8;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

// Creating a function to move the checker piece
void move_piece(char board[][8], int x1, int y1, int x2, int y2){
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = '-';
}

int main(){

    char board[8][8] = {
        {'-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-'}
    };

    // Placing the checker pieces on the board
    board[0][1] = 'W';
    board[0][3] = 'W';
    board[0][5] = 'W';
    board[0][7] = 'W';
    board[1][0] = 'W';
    board[1][2] = 'W';
    board[1][4] = 'W';
    board[1][6] = 'W';
    board[2][1] = 'W';
    board[2][3] = 'W';
    board[2][5] = 'W';
    board[2][7] = 'W';

    board[5][0] = 'B';
    board[5][2] = 'B';
    board[5][4] = 'B';
    board[5][6] = 'B';
    board[6][1] = 'B';
    board[6][3] = 'B';
    board[6][5] = 'B';
    board[6][7] = 'B';
    board[7][0] = 'B';
    board[7][2] = 'B';
    board[7][4] = 'B';
    board[7][6] = 'B';

    int i, j, k, x1, y1, x2, y2;
    int valid;

    display_board(board);

    // Loop to allow the players to make moves
    for(k=1;k<=50;k++){
        if(k%2!=0){
            printf("Player 1 (W) make a move:\n");
            valid = 0;
            while(valid!=1){
                printf("Select the current location of your piece (x,y): ");
                scanf("%d,%d",&x1,&y1);
                printf("Select the new location of your piece (x,y): ");
                scanf("%d,%d",&x2,&y2);
                if(board[x1-1][y1-1]=='W'){
                    if(x2==(x1-1) && (y2==(y1+1) || y2==(y1-1))){
                        if(board[x2][y2]!='-'){
                            printf("Invalid move!\n");
                        }
                        else{
                            move_piece(board,x1-1,y1-1,x2,y2);
                            valid = 1;
                        }
                    }
                    else if(x2==(x1-2) && (y2==(y1+2) || y2==(y1-2))){
                        if((board[x1-1][(y1+y2)/2-1]=='B' && board[x2][y2]!='-')){
                            printf("Invalid move!\n");
                        }
                        else{
                            move_piece(board,x1-1,y1-1,x2,y2);
                            board[x1-1][(y1+y2)/2-1] = '-';
                            valid = 1;
                        }
                    }
                    else{
                        printf("Invalid move!\n");
                    }
                }
                else if(board[x1-1][y1-1]=='w'){
                    // Code to handle a king piece
                }
                else{
                    printf("Invalid move!\n");
                }
            }
        }
        else{
            printf("Player 2 (B) make a move:\n");
            valid = 0;
            while(valid!=1){
                printf("Select the current location of your piece (x,y): ");
                scanf("%d,%d",&x1,&y1);
                printf("Select the new location of your piece (x,y): ");
                scanf("%d,%d",&x2,&y2);
                if(board[x1-1][y1-1]=='B'){
                    if(x2==(x1+1) && (y2==(y1+1) || y2==(y1-1))){
                        if(board[x2][y2]!='-'){
                            printf("Invalid move!\n");
                        }
                        else{
                            move_piece(board,x1-1,y1-1,x2,y2);
                            valid = 1;
                        }
                    }
                    else if(x2==(x1+2) && (y2==(y1+2) || y2==(y1-2))){
                        if((board[x1-1][(y1+y2)/2-1]=='W' && board[x2][y2]!='-')){
                            printf("Invalid move!\n");
                        }
                        else{
                            move_piece(board,x1-1,y1-1,x2,y2);
                            board[x1-1][(y1+y2)/2-1] = '-';
                            valid = 1;
                        }
                    }
                    else{
                        printf("Invalid move!\n");
                    }
                }
                else if(board[x1-1][y1-1]=='b'){
                    // Code to handle a king piece
                }
                else{
                    printf("Invalid move!\n");
                }
            }
        }

        display_board(board);

        // Check if one of the players has won
        int W_count=0, B_count=0;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                if(board[i][j]=='W'){
                    W_count++;
                }
                else if(board[i][j]=='B'){
                    B_count++;
                }
            }
        }
        if(W_count==0){
            printf("Player 2 (B) wins!\n");
            break;
        }
        if(B_count==0){
            printf("Player 1 (W) wins!\n");
            break;
        }
    }

    return 0;
}