//FormAI DATASET v1.0 Category: Checkers Game ; Style: minimalist
#include <stdio.h>

char board[8][8] = {  //initializing the checkers board
    {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
    {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
    {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
    {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '}
};

int main() {
    int fromRow, fromCol, toRow, toCol;

    while(1) {  //every iteration of this while loop is a turn
        printf("\n\n");
        for(int i=0; i<8; i++) {  //printing the checkers board
            for(int j=0; j<8; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        //getting input from player 1
        printf("\nPlayer 1: Enter the row and column of the checker piece you want to move: ");
        scanf("%d %d", &fromRow, &fromCol);
        printf("\nPlayer 1: Enter the row and column of the destination: ");
        scanf("%d %d", &toRow, &toCol);

        //moving the checker piece
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = ' ';

        //getting input from player 2
        printf("\nPlayer 2: Enter the row and column of the checker piece you want to move: ");
        scanf("%d %d", &fromRow, &fromCol);
        printf("\nPlayer 2: Enter the row and column of the destination: ");
        scanf("%d %d", &toRow, &toCol);

        //moving the checker piece
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = ' ';
    }

    return 0;
}