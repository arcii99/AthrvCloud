//FormAI DATASET v1.0 Category: Chess AI ; Style: immersive
#include <stdio.h>

int main() {
    char board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    };
    
    for (int i = 0; i < 8; i++) {
        printf("%d", 8-i);
        for (int j = 0; j < 8; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
    
    printf("  a b c d e f g h\n");
    return 0;
}