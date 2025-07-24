//FormAI DATASET v1.0 Category: Checkers Game ; Style: random
#include <stdio.h>

char board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {' ', '.', '*', '&', 'w', 'W', 'p', 'P'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {' ', '.', '.', 'P', '.', '.', '.', '.'},
                    {'.', ' ', '.', ' ', '.', '.', '.', '.'},
                    {'P', 'P', 'P', ' ', 'P', 'P', 'P', 'P'},
                    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
                    
void print_board() {
    int row, col;
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

int main() {
    printf("C Checkers Game\n");
    print_board();
    return 0;
}