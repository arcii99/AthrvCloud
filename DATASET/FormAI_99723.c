//FormAI DATASET v1.0 Category: Chess engine ; Style: enthusiastic
#include <stdio.h>

int main() {

    printf("Welcome to the Chess Engine!\nLet's Play!\n");

    //Initialize the Chess board
    char chessBoard[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    //Print the board
    for(int i=0; i<8; i++){
        printf("%d| ", 8-i);
        for(int j=0; j<8; j++){
            printf("%c ", chessBoard[i][j]);
        }
        printf("|\n");
    }

    printf("  -----------------\n");
    printf("   a b c d e f g h  \n");

    //Let's play!
    char move[5];
    printf("Your Turn: ");
    scanf("%s", move);
    printf("You moved %c%c to %c%c\n", move[0], move[1], move[2], move[3]);

    return 0;
}