//FormAI DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>

int board[8][8];
int player = 1;

void initialize_board(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i<3 && (i+j)%2 == 0){
                board[i][j] = 1;
            }else if(i>4 && (i+j)%2 == 0){
                board[i][j] = 2;
            }else{
                board[i][j] = 0;
            }
        }
    }
}

void print_board(){
    printf("  0 1 2 3 4 5 6 7\n");
    for(int i=0;i<8;i++){
        printf("%d ",i);
        for(int j=0;j<8;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}

int move(int from_x, int from_y, int to_x, int to_y){
    int diff_x = to_x - from_x;
    int diff_y = to_y - from_y;
    if(board[from_x][from_y] == 1 && diff_x > 0){
        printf("Invalid move!\n");
        return 0;
    }
    if(board[from_x][from_y] == 2 && diff_x < 0){
        printf("Invalid move!\n");
        return 0;
    }
    if(abs(diff_x) == 1 && abs(diff_y) == 1){
        if(board[to_x][to_y] == 0){
            board[to_x][to_y] = board[from_x][from_y];
            board[from_x][from_y] = 0;
            return 1;
        }
    }else if(abs(diff_x) == 2 && abs(diff_y) == 2){
        int jumped_x = from_x + (diff_x/2);
        int jumped_y = from_y + (diff_y/2);
        if(board[to_x][to_y] == 0 && board[jumped_x][jumped_y] != player){
            board[to_x][to_y] = board[from_x][from_y];
            board[jumped_x][jumped_y] = 0;
            board[from_x][from_y] = 0;
            return 1;
        }
    }
    printf("Invalid move!\n");
    return 0;
}

int game_over(){
    int p1_count = 0;
    int p2_count = 0;
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j] == 1 || board[i][j] == 3){
                p1_count++;
            }
            if(board[i][j] == 2 || board[i][j] == 4){
                p2_count++;
            }
        }
    }
    
    if(p1_count == 0 || p2_count == 0){
        return 1;
    }
    return 0;
}

int main(){
    initialize_board();
    print_board();

    while(!game_over()){
        int from_x, from_y, to_x, to_y;
        printf("Player %d's turn:\n",player);
        printf("Enter from x: ");
        scanf("%d",&from_x);
        printf("Enter from y: ");
        scanf("%d",&from_y);
        printf("Enter to x: ");
        scanf("%d",&to_x);
        printf("Enter to y: ");
        scanf("%d",&to_y);

        if(move(from_x,from_y,to_x,to_y)){
            print_board();
            if(player == 1){
                player = 2;
            }else{
                player = 1;
            }
        }
    }

    printf("Game Over, Player %d wins!\n",player);

    return 0;
}