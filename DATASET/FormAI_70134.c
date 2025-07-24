//FormAI DATASET v1.0 Category: Chess engine ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

#define bd_size 8

typedef struct piece {
    int type, col, row, has_moved;
}piece;

piece board[bd_size][bd_size];

void init_board(){
    int i, j;
    char c;
    for(i=0; i<bd_size; i++){
        for(j=0; j<bd_size; j++){
            if ((i==0) || (i==bd_size-1)){
                switch(j){
                    case 0:
                    case 7:
                        c = 'R';
                        break;
                    case 1:
                    case 6:
                        c = 'N';
                        break;
                    case 2:
                    case 5:
                        c = 'B';
                        break;
                    case 3:
                        c = 'Q';
                        break;
                    case 4:
                        c = 'K';
                        break;
                }
            }
            else if ((i==1) || (i==bd_size-2)){
                c = 'P';
            }
            else{
                c = '.';
            }
            board[i][j].type = c;
            board[i][j].col = j;
            board[i][j].row = i;
            board[i][j].has_moved = 0;
        }
    }
}

void print_board(){
    int i, j;
    for(i=0; i<bd_size; i++){
        for(j=0; j<bd_size; j++){
            printf("%c ", board[i][j].type);
        }
        printf("\n");
    }
}

int main(){
    init_board();
    print_board();
    return 0;
}