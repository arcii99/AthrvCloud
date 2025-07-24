//FormAI DATASET v1.0 Category: Game of Life ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void init_board(int board[ROWS][COLS]){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[ROWS][COLS]){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(board[i][j] == 1){
                printf("#");
            }else{
                printf(".");
            }
        }
        printf("\n");
    }
}

int get_num_neighbors(int board[ROWS][COLS], int row, int col){
    int i,j,num_neighbors=0;
    for(i=row-1;i<=row+1;i++){
        for(j=col-1;j<=col+1;j++){
            if(i<0 || j<0 || i>=ROWS || j>=COLS){
                continue; //outside the board
            }
            if(i==row && j==col){
                continue; //the cell itself
            }
            if(board[i][j] == 1){
                num_neighbors++;
            }
        }
    }
    return num_neighbors;
}

void update_board(int board[ROWS][COLS]){
    int new_board[ROWS][COLS];
    int i,j,num_neighbors;

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            num_neighbors = get_num_neighbors(board, i, j);
            if(num_neighbors < 2 || num_neighbors > 3){
                new_board[i][j] = 0; //cell dies
            }else if(num_neighbors == 3){
                new_board[i][j] = 1; //cell is born
            }else{
                new_board[i][j] = board[i][j]; //cell stays the same
            }
        }
    }
    //copy new board to original board
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            board[i][j] = new_board[i][j];
        }
    }
}

int main(){
    srand(time(0));
    int board[ROWS][COLS];
    init_board(board);
    while(1){
        system("clear"); //clears the console screen
        print_board(board);
        update_board(board);
        usleep(100000); //makes the program pause for 0.1 second
    }
    return 0;
}