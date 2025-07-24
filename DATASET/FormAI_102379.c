//FormAI DATASET v1.0 Category: Chess engine ; Style: medieval
#include <stdio.h>

void printBoard(char board[8][8]) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n\n");
    }
}

int main() {
    // Create the initial chess board
    char board[8][8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};
    
    
    // Print the initial chess board
    printf("Initial Chess Board:\n\n");
    printBoard(board);
    
    
    return 0;
}