//FormAI DATASET v1.0 Category: Chess engine ; Style: standalone
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if(i==1){
                board[i][j] = 'B'; // black pawn
            }else if(i==6){
                board[i][j] = 'W'; // white pawn
            }else{
                board[i][j] = ' ';
            }
        }
    }

    // initialize rooks
    board[0][0] = 'b'; // black rook 
    board[0][7] = 'b'; 
    board[7][0] = 'w'; // white rook 
    board[7][7] = 'w'; 

    // initialize knights
    board[0][1] = 'b'; // black knight 
    board[0][6] = 'b'; 
    board[7][1] = 'w'; // white knight 
    board[7][6] = 'w'; 

    // initialize bishops
    board[0][2] = 'b'; // black bishop 
    board[0][5] = 'b'; 
    board[7][2] = 'w'; // white bishop 
    board[7][5] = 'w'; 

    // initialize kings and queens
    board[0][3] = 'b'; // black queen 
    board[0][4] = 'b'; // black king 
    board[7][3] = 'w'; // white queen 
    board[7][4] = 'w'; // white king  
}

void print_board() {
    printf("   ---- Chess Board ----\n");
    for(int i=0; i<BOARD_SIZE; i++){
        printf("%d| ", BOARD_SIZE-i);
        for(int j=0; j<BOARD_SIZE; j++){
            printf("%c | ", board[i][j]);
        }
        printf("\n");
    }
    printf("  ---------------------\n");
    printf("   | a | b | c | d | e | f | g | h |\n");
}

int main() {
    init_board();
    print_board();
    return 0;
}