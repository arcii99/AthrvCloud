//FormAI DATASET v1.0 Category: Checkers Game ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

void print_board(char board[][8]){
    printf("\n    +---+---+---+---+---+---+---+---+\n");
    for(int i=0;i<8;i++){
        printf(" %d  |", i+1);
        for(int j=0; j<8; j++){
            printf(" %c |", board[i][j]);
        }
        printf("\n    +---+---+---+---+---+---+---+---+\n");
    }
    printf("      A   B   C   D   E   F   G   H\n\n");
}

int main(){
    char board[8][8] =
        {{'r','n','b','q','k','b','n','r'},
        {'p','p','p','p','p','p','p','p'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'P','P','P','P','P','P','P','P'},
        {'R','N','B','Q','K','B','N','R'}}; //initial board
    print_board(board);
    return 0;
}