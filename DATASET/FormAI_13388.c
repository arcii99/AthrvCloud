//FormAI DATASET v1.0 Category: Chess engine ; Style: rigorous
#include<stdio.h>
#define BLACK_PAWN 'p'
#define BLACK_ROOK 'r'
#define BLACK_KNIGHT 'n'
#define BLACK_BISHOP 'b'
#define BLACK_QUEEN 'q'
#define BLACK_KING 'k'
#define WHITE_PAWN 'P'
#define WHITE_ROOK 'R'
#define WHITE_KNIGHT 'N'
#define WHITE_BISHOP 'B'
#define WHITE_QUEEN 'Q'
#define WHITE_KING 'K'
#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE]; //chess board array

//Initialize board with standard starting positions
//ASCII table is used to assign black pieces using lowercase letters and white pieces using uppercase letters
void initialize_board(){
    int i, j;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if(i==0 || i==7){
                if(j==0 || j==7){
                    board[i][j] = (i==0)?BLACK_ROOK:WHITE_ROOK;
                }
                else if(j==1 || j==6){
                    board[i][j] = (i==0)?BLACK_KNIGHT:WHITE_KNIGHT;
                }
                else if(j==2 || j==5){
                    board[i][j] = (i==0)?BLACK_BISHOP:WHITE_BISHOP;
                }
                else if(j==3){
                    board[i][j] = (i==0)?BLACK_QUEEN:WHITE_QUEEN;
                }
                else{
                    board[i][j] = (i==0)?BLACK_KING:WHITE_KING;
                }
            }
            else if(i==1 || i==6){
                board[i][j] = (i==1)?BLACK_PAWN:WHITE_PAWN;
            }
            else{
                board[i][j] = ' ';
            }
        }
    }
}

//Print the current chess board
void print_board(){
    int i, j;
    printf("\n  A B C D E F G H\n");
    for(i=0; i<BOARD_SIZE; i++){
        printf("%d", (BOARD_SIZE-i));
        for(j=0; j<BOARD_SIZE; j++){
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }
}

int main(){
    initialize_board(); //initialize board before the game starts
    print_board(); //print board on either side
    return 0;
}