//FormAI DATASET v1.0 Category: Chess engine ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE] = {
    {-1,-2,-3,-4,-5,-3,-2,-1},
    {-6,-6,-6,-6,-6,-6,-6,-6},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {6,6,6,6,6,6,6,6},
    {1,2,3,4,5,3,2,1}
};

void display_board(){
    printf("  a b c d e f g h\n");
    for(int i=0; i<BOARD_SIZE; i++){
        printf("%d ", 8-i);
        for(int j=0; j<BOARD_SIZE; j++){
            switch(board[i][j]){
                case 0: printf(". "); break;
                case 1: printf("K "); break;
                case 2: printf("Q "); break;
                case 3: printf("R "); break;
                case 4: printf("B "); break;
                case 5: printf("N "); break;
                case 6: printf("P "); break;
                case -1: printf("k "); break;
                case -2: printf("q "); break;
                case -3: printf("r "); break;
                case -4: printf("b "); break;
                case -5: printf("n "); break;
                case -6: printf("p "); break;
            }
        }
        printf("%d", 8-i);
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

void make_move(int start_row, int start_col, int end_row, int end_col){
    int piece = board[start_row][start_col];
    board[end_row][end_col] = piece;
    board[start_row][start_col] = 0;
}

void play_game(){
    display_board();
    while(1){
        char start[3], end[3];
        printf("Enter move (ex. e2 e4): ");
        scanf("%s %s", start, end);

        int start_row = 8 - (start[1] - '0');
        int start_col = start[0] - 'a';
        int end_row = 8 - (end[1] - '0');
        int end_col = end[0] - 'a';

        make_move(start_row, start_col, end_row, end_col);

        display_board();
    }
}

int main(){
    play_game();
    return 0;
}