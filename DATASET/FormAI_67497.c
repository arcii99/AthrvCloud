//FormAI DATASET v1.0 Category: Chess engine ; Style: energetic
// Welcome to Chess Engine 3000!

#include <stdio.h>
#include <stdlib.h>

// board representation
char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

int main() {
    // print chess board
    printf("\nWelcome to Chess Engine 3000!\n");
    printf("  a b c d e f g h\n");
    printf(" +-----------------+\n");
    for (int i = 0; i < 8; i++) {
        printf("%d| ", i+1);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf(" +-----------------+\n");
    
    // TODO: implement chess logic
    printf("\nEngine under construction...\n");
    return 0;
}