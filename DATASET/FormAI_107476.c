//FormAI DATASET v1.0 Category: Game of Life ; Style: synchronous
#include <stdio.h>

#define ROWS 10
#define COLS 10

int main() {
    int board[ROWS][COLS] = {0};
    int next_board[ROWS][COLS] = {0};
    int i, j, k, l, neighbors, stable = 0;
    
    //initialize board randomly
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    
    //print initial board
    printf("Initial Board:\n");
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    
    //simulate life
    while(!stable) {
        stable = 1; //assume board is stable until proven otherwise
        
        //look at each cell
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++) {
                neighbors = 0; //count number of live neighbors
                
                //look at each neighbor
                for(k = i - 1; k <= i + 1; k++) {
                    for(l = j - 1; l <= j + 1; l++) {
                        if(k == i && l == j) {
                            continue; //don't count self as neighbor
                        }
                        if(k >= 0 && k < ROWS && l >= 0 && l < COLS && board[k][l]) {
                            neighbors++; //count live neighbor
                        }
                    }
                }
                
                //apply game of life rules
                if(board[i][j] && (neighbors < 2 || neighbors > 3)) {
                    next_board[i][j] = 0; //cell dies from underpopulation/overpopulation
                    stable = 0; //board is not stable
                } else if(!board[i][j] && neighbors == 3) {
                    next_board[i][j] = 1; //cell is born from reproduction
                    stable = 0; //board is not stable
                } else {
                    next_board[i][j] = board[i][j]; //cell stays the same
                }
            }
        }
        
        //copy next board to current board
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++) {
                board[i][j] = next_board[i][j];
            }
        }
        
        //print board
        printf("\nNext Board:\n");
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}