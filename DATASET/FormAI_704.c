//FormAI DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void populate_board(int board[][SIZE]);
void print_board(int board[][SIZE]);
void simulate(int board[][SIZE]);

int main() {
    int board[SIZE][SIZE];
    populate_board(board);
    print_board(board);
    simulate(board);
    return 0;
}

void populate_board(int board[][SIZE]) {
    srand(time(NULL));
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = rand()%2;
        }
    }
}

void print_board(int board[][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void simulate(int board[][SIZE]) {
    int copy[SIZE][SIZE];
    while(1) {
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                int neighbors = 0;
                for(int k=-1; k<=1; k++) {
                    for(int l=-1; l<=1; l++) {
                        if(k==0 && l==0) continue;
                        int row = i+k;
                        int col = j+l;
                        if(row<0 || col<0 || row>=SIZE || col>=SIZE) continue;
                        if(board[row][col]==1) neighbors++;
                    }
                }
                if(board[i][j]==1) {
                    if(neighbors < 2 || neighbors > 3) copy[i][j] = 0;
                    else copy[i][j] = 1;
                }
                else {
                    if(neighbors == 3) copy[i][j] = 1;
                    else copy[i][j] = 0;
                }
            }
        }
        printf("\n");
        print_board(copy);
        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                board[i][j] = copy[i][j];
            }
        }
    }
}