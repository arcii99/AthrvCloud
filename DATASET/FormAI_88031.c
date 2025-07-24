//FormAI DATASET v1.0 Category: Checkers Game ; Style: calm
#include<stdio.h>
#include<stdlib.h>

#define ROW 8
#define COLUMN 8

void print_board(int board[ROW][COLUMN]){
    int i, j;
    printf("\n    1   2   3   4   5   6   7   8\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    
    for(i=0; i<ROW; i++){
        printf("%d |", i+1);
        for(j=0; j<COLUMN; j++){
            if(board[i][j]==1) printf(" B |"); //for black
            else if(board[i][j]==2) printf(" W |"); //for white
            else printf("   |");
        }
        printf(" %d\n", i+1);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
    printf("    1   2   3   4   5   6   7   8\n");
}

int move_check(int board[ROW][COLUMN], int origin_x, int origin_y, int dest_x, int dest_y, int player){
    if(origin_x<0 || origin_x>=ROW || origin_y<0 || origin_y>=COLUMN || dest_x<0 || dest_x>=ROW || dest_y<0 || dest_y>=COLUMN){
        printf("\nInvalid Move, Please Stay Within The Board\n");
        return 0;
    }
    if(board[dest_x][dest_y]!=0){
        printf("\nInvalid Move, Destination Is Already Occupied\n");
        return 0;
    }
    if(player==1 && dest_x<origin_x){
        printf("\nInvalid Move, Black Piece Cannot Move Backwards\n");
        return 0;
    }
    if(player==2 && dest_x>origin_x){
        printf("\nInvalid Move, White Piece Cannot Move Backwards\n");
        return 0;
    }
    if(abs(origin_x-dest_x)!=1 || abs(origin_y-dest_y)!=1){
        printf("\nInvalid Move, You Can Only Move Diagonally By One Step\n");
        return 0;
    }
    if(board[origin_x][origin_y]!=player && board[origin_x][origin_y]!=player+2){
        printf("\nInvalid Move, You Cannot Move Opponent's Piece\n");
        return 0;
    }
    if(abs(origin_x-dest_x)==2 && abs(origin_y-dest_y)==2){
        int mid_x = (origin_x+dest_x)/2;
        int mid_y = (origin_y+dest_y)/2;

        if(board[mid_x][mid_y]==0){
            printf("\nInvalid Move, You Can Only Jump Over Opponent's Piece\n");
            return 0;
        }
        else if(board[mid_x][mid_y]==player || board[mid_x][mid_y]==player+2){
            printf("\nInvalid Move, Cannot Jump Over Your Own Player\n");
            return 0;
        }
        else{
            board[mid_x][mid_y] = 0;
        }
    }
    if(player==1 && dest_x==7){
        board[dest_x][dest_y] = 3;
    }
    else if(player==2 && dest_x==0){
        board[dest_x][dest_y] = 4;
    }
    else{
        board[dest_x][dest_y] = player;
    }
    board[origin_x][origin_y] = 0;
    return 1;
}

int check_win(int board[ROW][COLUMN]){
    int i, j, count1=0, count2=0;
    for(i=0; i<ROW; i++){
        for(j=0; j<COLUMN; j++){
            if(board[i][j]==1 || board[i][j]==3){
                count1++;
            }
            else if(board[i][j]==2 || board[i][j]==4){
                count2++;
            }
        }
    }
    if(count1==0){
        return 2;
    }
    else if(count2==0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int board[ROW][COLUMN], i, j, origin_x, origin_y, dest_x, dest_y;
    int player = 1, win=0;
    for(i=0; i<ROW; i++){
        for(j=0; j<COLUMN; j++){
            if(i%2==0){
                if(j%2==0) board[i][j] = 0;
                else board[i][j] = -1;
            }
            else{
                if(j%2==0){
                    board[i][j] = -1;
                }
                else{
                    board[i][j] = 0;
                }
            }
        }
    }
    print_board(board);
    while(!win){
        printf("\n--------PLAYER %d---------\n", player);
        printf("Enter The Position of Piece To Move:\n");
        scanf("%d %d", &origin_x, &origin_y);
        printf("Enter The Destination To Move The Piece:\n");
        scanf("%d %d", &dest_x, &dest_y);
        if(move_check(board, origin_x-1, origin_y-1, dest_x-1, dest_y-1, player)){
            print_board(board);
            win = check_win(board);
            if(win==1) printf("\nPLAYER 1 WINS\n");
            else if(win==2) printf("\nPLAYER 2 WINS\n");
            player = (player % 2) + 1;
        }
    }
    return 0;
}