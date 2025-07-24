//FormAI DATASET v1.0 Category: Chess engine ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

char board[8][8]={
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

void display_board(){
    int i, j;
    
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            printf("+---");
        }
        printf("+\n");
        
        for(j=0; j<8; j++){
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    
    for(j=0; j<8; j++){
        printf("+---");
    }
    printf("+\n");
}

int main(){
    int i;
    char player = 'W';
    
    display_board();
    
    for(i=0; i<20; i++){
        printf("It's %c's turn\n", player);
        printf("Move your piece: ");
        getchar();
        printf("Where to? ");
        getchar();
        
        if(player == 'W'){
            player = 'B';
        }
        else{
            player = 'W';
        }
    }
    
    return 0;
}