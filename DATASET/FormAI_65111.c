//FormAI DATASET v1.0 Category: Checkers Game ; Style: invasive
//Invasive Style Checkers Game Program
#include<stdio.h>
#include<stdlib.h>

//function to print the board
void print_board(char board[][8]){
    int i,j;
    printf("Current Board:\n");
    printf("  0 1 2 3 4 5 6 7\n");
    for(i=0;i<8;i++){
        printf("%d ",i);
        for(j=0;j<8;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

//function to check if the move is legal or not
int check_move(char board[][8],int source_row,int source_col,int dest_row,int dest_col,int player){
    if(dest_row < 0 || dest_row > 7 || dest_col < 0 || dest_col > 7){
        return 0;
    }
    if(player == 1){
        if(dest_row >= source_row){
            return 0;
        }
    }
    else{
        if(dest_row <= source_row){
            return 0;
        }
    }
    if(abs(dest_row - source_row) != abs(dest_col - source_col)){
        return 0;
    }
    int i,j;
    if(dest_row > source_row){
        i = source_row + 1;
    }
    else{
        i = dest_row + 1;
    }
    if(dest_col > source_col){
        j = source_col + 1;
    }
    else{
        j = dest_col + 1;
    }
    while(i < dest_row && j < dest_col){
        if(board[i][j] != '-'){
            return 0;
        }
        i++;
        j++;
    }
    if(board[dest_row][dest_col] != '-'){
        return 0;
    }
    if(abs(dest_row - source_row) == 2){
        int jump_row = (source_row + dest_row) / 2;
        int jump_col = (source_col + dest_col) / 2;
        if(player == 1 && board[jump_row][jump_col] != 'o' && board[jump_row][jump_col] != 'O'){
            return 0;
        }
        if(player == 2 && board[jump_row][jump_col] != 'x' && board[jump_row][jump_col] != 'X'){
            return 0;
        }
    }
    return 1;
}

//function to move the piece
void move_piece(char board[][8],int source_row,int source_col,int dest_row,int dest_col,int player){
    board[dest_row][dest_col] = board[source_row][source_col];
    board[source_row][source_col] = '-';
    if(abs(dest_row - source_row) == 2){
        int jump_row = (source_row + dest_row) / 2;
        int jump_col = (source_col + dest_col) / 2;
        board[jump_row][jump_col] = '-';
    }
    if(player == 1 && dest_row == 0){
        board[dest_row][dest_col] = 'O';
    }
    if(player == 2 && dest_row == 7){
        board[dest_row][dest_col] = 'X';
    }
}

//function to check if the game is over or not
int check_game_over(char board[][8]){
    int i,j;
    int x_count = 0;
    int o_count = 0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(board[i][j] == 'x' || board[i][j] == 'X'){
                x_count++;
            }
            if(board[i][j] == 'o' || board[i][j] == 'O'){
                o_count++;
            }
        }
    }
    if(x_count == 0 || o_count == 0){
        return 1;
    }
    return 0;
}

int main(){
    char board[8][8] = {{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'},{'-','-','-','-','-','-','-','-'}};
    int player = 1;
    int source_row,source_col,dest_row,dest_col;
    int i,j;
    //setting up the initial board
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(i <= 2 && (i+j)%2 == 1){
                board[i][j] = 'o';
            }
            if(i >= 5 && (i+j)%2 == 1){
                board[i][j] = 'x';
            }
        }
    }
    printf("Welcome to Checkers Game!\n");
    printf("Player 1: o\n");
    printf("Player 2: x\n");
    while(1){
        print_board(board);
        if(player == 1){
            printf("Player 1 Turn:\n");
        }
        else{
            printf("Player 2 Turn:\n");
        }
        printf("Enter the row and column of the piece to move: ");
        scanf("%d%d",&source_row,&source_col);
        printf("Enter the row and column of the destination: ");
        scanf("%d%d",&dest_row,&dest_col);
        if(check_move(board,source_row,source_col,dest_row,dest_col,player)){
            move_piece(board,source_row,source_col,dest_row,dest_col,player);
            if(check_game_over(board)){
                print_board(board);
                if(player == 1){
                    printf("Player 2 Wins!\n");
                }
                else{
                    printf("Player 1 Wins!\n");
                }
                break;
            }
            if(player == 1){
                player = 2;
            }
            else{
                player = 1;
            }
        }
        else{
            printf("Invalid Move! Try Again.\n");
        }
    }
    return 0;
}