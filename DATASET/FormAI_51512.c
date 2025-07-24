//FormAI DATASET v1.0 Category: Checkers Game ; Style: Sherlock Holmes
#include <stdio.h>

char board[8][8] = {
    {'r', '.', 'r', '.', 'r', '.', 'r', '.'},
    {'.', 'r', '.', 'r', '.', 'r', '.', 'r'},
    {'r', '.', 'r', '.', 'r', '.', 'r', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', 'w', '.', 'w', '.', 'w', '.', 'w'},
    {'w', '.', 'w', '.', 'w', '.', 'w', '.'},
    {'.', 'w', '.', 'w', '.', 'w', '.', 'w'} 
};

void print_board(char b[8][8]) {
    int i, j;
    for(i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for(j = 0; j < 8; j++) 
            printf("%c ", b[i][j]);
        printf("\n");
    }
    printf("  a b c d e f g h \n");
}

int main() {
    print_board(board);
    return 0;
}