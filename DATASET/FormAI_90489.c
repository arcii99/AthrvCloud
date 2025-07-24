//FormAI DATASET v1.0 Category: Checkers Game ; Style: medieval
#include <stdio.h>

// Function to print the board
void print_board(char board[][8]){
    for(int row=0; row<8; row++){
        printf("%d |", 8-row);
        for(int col=0; col<8; col++){
            printf("%c|", board[row][col]);
        }
        printf("\n  -----------------\n");
    }
    printf("    a b c d e f g h\n");
}

// Function to initialize the board with the starting positions of the pieces
void initialize_board(char board[][8]){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(i%2 == 0 && j%2 == 0){
                board[i][j] = ' ';
            }
            else if(i%2 == 1 && j%2 == 1){
                board[i][j] = ' ';
            }
            else if(i < 3){
                board[i][j] = 'O';
            }
            else if(i > 4){
                board[i][j] = 'X';
            }
            else{
                board[i][j] = ' '; // empty spaces in the middle of the board
            }
        }
    }
}

int main(){
    char board[8][8];
    initialize_board(board);
    print_board(board);
    return 0;
}