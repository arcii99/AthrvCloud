//FormAI DATASET v1.0 Category: Chess AI ; Style: multiplayer
#include<stdio.h>

int main(){

    char board[8][8] = {
                        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        };

    //print initial chess board
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}