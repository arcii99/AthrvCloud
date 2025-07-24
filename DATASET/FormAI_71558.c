//FormAI DATASET v1.0 Category: Game of Life ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10

void init_board(int board[ROWS][COLS]){
    srand(time(NULL));
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            board[i][j] = rand()%2;
        }
    }
}

void print_board(int board[ROWS][COLS]){
    printf("\n");
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(board[i][j]){
                printf("🌷");
            }
            else{
                printf("🌱");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int board[ROWS][COLS], int row, int col){
    int count = 0;
    for(int i=row-1;i<=row+1;i++){
        for(int j=col-1;j<=col+1;j++){
            if(i>=0 && i<ROWS && j>=0 && j<COLS && !(i==row && j==col)){
                count+=board[i][j];
            }
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]){
    int new_board[ROWS][COLS];
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            int count = count_neighbors(board, i, j);
            if(count == 3){
                new_board[i][j] = 1;
            }
            else if(count == 2){
                new_board[i][j] = board[i][j];
            }
            else{
                new_board[i][j] = 0;
            }
        }
    }
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            board[i][j] = new_board[i][j];
        }
    }
}

int main(){
    int board[ROWS][COLS];
    init_board(board);
    printf("Welcome to the Game of Life! 🌱🌷\n\n");
    int gen_count = 1;
    while(1){
        printf("Generation %d\n", gen_count++);
        print_board(board);
        update_board(board);
        getchar();
    }
    return 0;
}