//FormAI DATASET v1.0 Category: Chess engine ; Style: Claude Shannon
#include<stdio.h>

int board[8][8] = 
    { {-1,-2,-3,-4,-5,-3,-2,-1},
      {-6,-6,-6,-6,-6,-6,-6,-6},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {0,0,0,0,0,0,0,0},
      {6,6,6,6,6,6,6,6},
      {1,2,3,4,5,3,2,1} };

void print_board() {
    int i, j;
    for(i=0; i <= 7; i++) {
        printf("\n");
        for(j=0; j <= 7; j++)
            printf("%d ",board[i][j]);
    }
}

int main() {
    print_board();
    return 0;
}