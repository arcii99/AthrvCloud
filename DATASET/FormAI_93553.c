//FormAI DATASET v1.0 Category: Checkers Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>


int main() {

    // Initialize the game board with all pieces in their starting positions.
    char board[8][8] = {
        {" r  n  b  q  k  b  n  r "},
        {" p  p  p  p  p  p  p  p "},
        {"                       "},
        {"                       "},
        {"                       "},
        {"                       "},
        {" P  P  P  P  P  P  P  P "},
        {" R  N  B  Q  K  B  N  R "}
    };

    // Display the game board.
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}