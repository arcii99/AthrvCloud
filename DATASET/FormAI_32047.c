//FormAI DATASET v1.0 Category: Chess AI ; Style: romantic
#include <stdio.h>

//define the board as a 2D array
char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

//define a function to print the board
void print_board(char board[8][8]){
    for(int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            printf("%c ",  board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    print_board(board);
    return 0;
}