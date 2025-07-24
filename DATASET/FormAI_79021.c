//FormAI DATASET v1.0 Category: Chess engine ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

//Function to print the chessboard
void print_board(char board[8][8]){
    printf("\n   A  B  C  D  E  F  G  H\n");

    printf("  +------------------------+\n");
    for(int i=0; i<8; i++){
        printf("%d ", 8-i);
        for(int j=0; j<8; j++){
            printf("| %c ", board[i][j]);
        }
        printf("| %d", 8-i);
        printf("\n  +------------------------+\n");
    }
    printf("   A  B  C  D  E  F  G  H\n");
}

//Function to initialize the chess board
void initialize_board(char board[8][8]){
    char pieces[8] = {'r','n','b','q','k','b','n','r'};
    for(int i=0; i<8; i++){
        board[0][i] = pieces[i];
        board[1][i] = 'p';
        board[6][i] = 'P';
        board[7][i] = pieces[i]-32;
        for(int j=2; j<6; j++){
            board[j][i] = ' ';
        }
    }
}

int main(){
    char board[8][8];
    initialize_board(board);

    printf("\n=== WELCOME TO PEACEFUL CHESS ===\n");
    printf("\nHere is the initial board:\n");
    print_board(board);

    return 0;
}