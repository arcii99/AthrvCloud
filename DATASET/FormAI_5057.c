//FormAI DATASET v1.0 Category: Chess engine ; Style: Dennis Ritchie
#include <stdio.h>

#define WHITE 1
#define BLACK -1
#define EMPTY 0

int board[8][8] = {
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1}
};

void printBoard(){
    printf("  a b c d e f g h\n");
    for(int i = 0; i < 8; i++){
        printf("%d ", i + 1);
        for(int j = 0; j < 8; j++){
            if(board[i][j] == WHITE){
                printf("W ");
            } else if(board[i][j] == BLACK){
                printf("B ");
            } else {
                printf("_ ");
            }
        }
        printf("%d\n", i + 1);
    }
    printf("  a b c d e f g h\n");
}

int main(){
    printBoard();
    return 0;
}