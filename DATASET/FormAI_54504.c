//FormAI DATASET v1.0 Category: Game of Life ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int board[SIZE][SIZE];
int new_board[SIZE][SIZE];

void init_board() {
    srand(time(NULL));

    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(rand()%2 == 0)
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
}

void print_board() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == 1)
                printf("# ");
            else
                printf("- ");
        }
        printf("\n");
    }
}

int count_neighbors(int x, int y) {
    int count = 0;

    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            if(!((i==0) && (j==0))) {
                int row = (x+i+SIZE)%SIZE;
                int col = (y+j+SIZE)%SIZE;
                count += board[row][col];
            }
        }
    }

    return count;
}

void update_board() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            int neighbors = count_neighbors(i, j);
            if(board[i][j] == 1) {
                if(neighbors < 2 || neighbors > 3)
                    new_board[i][j] = 0;
                else
                    new_board[i][j] = 1;
            }
            else {
                if(neighbors == 3)
                    new_board[i][j] = 1;
                else
                    new_board[i][j] = 0;
            }
        }
    }

    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    init_board();

    for(int i=0; i<100; i++) {
        printf("Generation %d:\n", i+1);
        print_board();
        update_board();
        printf("\n");
    }

    return 0;
}