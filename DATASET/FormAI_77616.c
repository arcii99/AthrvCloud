//FormAI DATASET v1.0 Category: Chess AI ; Style: complex
#include<stdio.h>
#include<stdlib.h>

#define W_KING 1
#define W_QUEEN 2
#define W_ROOK 3
#define W_KNIGHT 4
#define W_BISHOP 5
#define W_PAWN 6

#define B_KING -1
#define B_QUEEN -2
#define B_ROOK -3
#define B_KNIGHT -4
#define B_BISHOP -5
#define B_PAWN -6

int board[8][8] = {{B_ROOK, B_KNIGHT, B_BISHOP, B_QUEEN, B_KING, B_BISHOP, B_KNIGHT, B_ROOK},
                   {B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN, B_PAWN},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0},
                   {W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN, W_PAWN},
                   {W_ROOK, W_KNIGHT, W_BISHOP, W_QUEEN, W_KING, W_BISHOP, W_KNIGHT, W_ROOK}};

void print_board(){
    printf("  a b c d e f g h\n");
    for(int i = 0; i < 8; i++){
        printf("%d ", 8-i);
        for(int j = 0; j < 8; j++){
            if(board[i][j] == 0){
                printf("- ");
            }
            else{
                switch(board[i][j]){
                    case B_ROOK:
                        printf("r ");
                        break;
                    case B_KNIGHT:
                        printf("n ");
                        break;
                    case B_BISHOP:
                        printf("b ");
                        break;
                    case B_QUEEN:
                        printf("q ");
                        break;
                    case B_KING:
                        printf("k ");
                        break;
                    case B_PAWN:
                        printf("p ");
                        break;
                    case W_ROOK:
                        printf("R ");
                        break;
                    case W_KNIGHT:
                        printf("N ");
                        break;
                    case W_BISHOP:
                        printf("B ");
                        break;
                    case W_QUEEN:
                        printf("Q ");
                        break;
                    case W_KING:
                        printf("K ");
                        break;
                    case W_PAWN:
                        printf("P ");
                        break;
                }
            }
        }
        printf("%d", 8-i);
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int main(){
    printf("Initial Position\n");
    print_board();
    return 0;
}