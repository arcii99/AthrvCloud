//FormAI DATASET v1.0 Category: Checkers Game ; Style: multivariable
#include<stdio.h>

int board[8][8];

// initialize the checker board
void init_board(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if((i+j)%2 == 0){
                if(i < 3){
                    board[i][j] = 1;
                }
                else if(i > 4){
                    board[i][j] = 2;
                }
                else{
                    board[i][j] = 0;
                }
            }
            else{
                board[i][j] = -1;
            }
        }
    }
}

// print the checker board
void print_board(){
    printf("  0 1 2 3 4 5 6 7\n");
    for(int i=0;i<8;i++){
        printf("%d ",i);
        for(int j=0;j<8;j++){
            switch(board[i][j]){
                case 0:
                    printf(". ");
                    break;
                case 1:
                    printf("o ");
                    break;
                case 2:
                    printf("x ");
                    break;
                case 3:
                    printf("O ");
                    break;
                case 4:
                    printf("X ");
                    break;
                default:
                    printf("  ");
                    break;
            }
        }
        printf("\n");
    }
}

// check if the move is valid or not
int valid_move(int player, int i1, int j1, int i2, int j2){
    if(i2 < 0 || i2 >= 8 || j2 < 0 || j2 >= 8){
        return 0;
    }
    if(board[i2][j2] != 0){
        return 0;
    }
    if(player == 1){
        if(board[i1][j1] == 1 && i2 > i1){
            return 0;
        }
        else if(board[i1][j1] == 3 && (i2 > i1 || j2 > j1 || j2 < j1)){
            return 0;
        }
    }
    else if(player == 2){
        if(board[i1][j1] == 2 && i2 < i1){
            return 0;
        }
        else if(board[i1][j1] == 4 && (i2 < i1 || j2 > j1 || j2 < j1)){
            return 0;
        }
    }
    int di = i2 - i1;
    int dj = j2 - j1;
    if(di == 1 || di == -1){
        if(dj == 1 || dj == -1){
            return 1;
        }
    }
    else if(di == 2 || di == -2){
        if(dj == 2 || dj == -2){
            int ci = (i1+i2)/2;
            int cj = (j1+j2)/2;
            if(player == 1 && (board[ci][cj] == 2 || board[ci][cj] == 4)){
                return 1;
            }
            if(player == 2 && (board[ci][cj] == 1 || board[ci][cj] == 3)){
                return 1;
            }
        }
    }
    return 0;
}

// check if the player can make a move or not
int can_move(int player){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(player == 1){
                if(board[i][j] == 1){
                    if(valid_move(player, i, j, i-1, j-1) || valid_move(player, i, j, i-1, j+1) ||
                       valid_move(player, i, j, i-2, j-2) || valid_move(player, i, j, i-2, j+2)){
                        return 1;
                    }
                }
                else if(board[i][j] == 3){
                    if(valid_move(player, i, j, i-1, j-1) || valid_move(player, i, j, i-1, j+1) ||
                       valid_move(player, i, j, i+1, j-1) || valid_move(player, i, j, i+1, j+1) ||
                       valid_move(player, i, j, i-2, j-2) || valid_move(player, i, j, i-2, j+2) ||
                       valid_move(player, i, j, i+2, j-2) || valid_move(player, i, j, i+2, j+2)){
                        return 1;
                    }
                }
            }
            else if(player == 2){
                if(board[i][j] == 2){
                    if(valid_move(player, i, j, i+1, j-1) || valid_move(player, i, j, i+1, j+1) ||
                       valid_move(player, i, j, i+2, j-2) || valid_move(player, i, j, i+2, j+2)){
                        return 1;
                    }
                }
                else if(board[i][j] == 4){
                    if(valid_move(player, i, j, i-1, j-1) || valid_move(player, i, j, i-1, j+1) ||
                       valid_move(player, i, j, i+1, j-1) || valid_move(player, i, j, i+1, j+1) ||
                       valid_move(player, i, j, i-2, j-2) || valid_move(player, i, j, i-2, j+2) ||
                       valid_move(player, i, j, i+2, j-2) || valid_move(player, i, j, i+2, j+2)){
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// make the move
void make_move(int player, int i1, int j1, int i2, int j2){
    board[i2][j2] = board[i1][j1];
    board[i1][j1] = 0;
    if(player == 1 && i2 == 0 && board[i2][j2] == 1){
        board[i2][j2] = 3;
    }
    else if(player == 2 && i2 == 7 && board[i2][j2] == 2){
        board[i2][j2] = 4;
    }
    if(i2-i1 == 2 || i2-i1 == -2){
        int ci = (i1+i2)/2;
        int cj = (j1+j2)/2;
        board[ci][cj] = 0;
    }
}

int main(){
    init_board();
    int player = 1;
    while(can_move(player)){
        print_board();
        int i1,j1,i2,j2;
        printf("Player %d's turn\nEnter the position of the piece you want to move: ",player);
        scanf("%d%d",&i1,&j1);
        printf("Enter the position where you want to move the piece: ");
        scanf("%d%d",&i2,&j2);
        if(valid_move(player, i1, j1, i2, j2)){
            make_move(player, i1, j1, i2, j2);
            if(player == 1){
                player = 2;
            }
            else{
                player = 1;
            }
        }
        else{
            printf("Invalid move, try again.\n");
        }
    }
    print_board();
    printf("Player %d wins!\n",player);
    return 0;
}