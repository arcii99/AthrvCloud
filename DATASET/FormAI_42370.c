//FormAI DATASET v1.0 Category: Chess engine ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE]; // Global board array

// Initializes the board
void init_board(){
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if(i==1){
                board[i][j] = 'p';
            }else if(i==6){
                board[i][j] = 'P';
            }else{
                board[i][j] = '.';
            }
        }
    }

    // Placing rooks on respective positions
    board[0][0]='r'; 
    board[0][7]='r';
    board[7][0]='R'; 
    board[7][7]='R';

    // Placing knights on respective positions
    board[0][1]='n'; 
    board[0][6]='n';
    board[7][1]='N'; 
    board[7][6]='N';

    // Placing bishops on respective positions
    board[0][2]='b'; 
    board[0][5]='b';
    board[7][2]='B'; 
    board[7][5]='B';

    // Placing queens on respective positions
    board[0][3]='q'; 
    board[7][3]='Q';

    // Placing kings on respective positions
    board[0][4]='k'; 
    board[7][4]='K';
}

// Displays the board
void display_board(){
    for(int i=0; i<BOARD_SIZE; i++){
        printf("%d ", BOARD_SIZE-i);
        for(int j=0; j<BOARD_SIZE; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int main(){
    init_board(); // Initializes the board

    display_board(); // Displays the board

    return 0;
}