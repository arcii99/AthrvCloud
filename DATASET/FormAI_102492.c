//FormAI DATASET v1.0 Category: Chess engine ; Style: energetic
#include <stdio.h>
#define SIZE 8

/* Chess Board */
int board[SIZE][SIZE] = {
    {-1,-2,-3,-4,-5,-3,-2,-1},
    {-6,-6,-6,-6,-6,-6,-6,-6},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {6,6,6,6,6,6,6,6},
    {1,2,3,4,5,3,2,1}
};

/* Function to print Chess Board */
void print_board() {
    int i, j;
    printf("#################################\n");
    for(i=0; i<SIZE; i++) {
        printf("#");
        for(j=0; j<SIZE; j++) {
            if(board[i][j] == 0) {
                printf(" %c ", '.');
            }
            else if(board[i][j] == 1) {
                printf(" %c ", 'P');
            }
            else if(board[i][j] == -1) {
                printf(" %c ", 'p');
            }
            else if(board[i][j] == 2) {
                printf(" %c ", 'N');
            }
            else if(board[i][j] == -2) {
                printf(" %c ", 'n');
            }
            else if(board[i][j] == 3) {
                printf(" %c ", 'B');
            }
            else if(board[i][j] == -3) {
                printf(" %c ", 'b');
            }
            else if(board[i][j] == 4) {
                printf(" %c ", 'R');
            }
            else if(board[i][j] == -4) {
                printf(" %c ", 'r');
            }
            else if(board[i][j] == 5) {
                printf(" %c ", 'Q');
            }
            else if(board[i][j] == -5) {
                printf(" %c ", 'q');
            }
            else if(board[i][j] == 6) {
                printf(" %c ", 'K');
            }
            else if(board[i][j] == -6) {
                printf(" %c ", 'k');
            }
        }
        printf("#\n");
    }
    printf("#################################\n");
}

int main() {
    print_board();
    return 0;
}