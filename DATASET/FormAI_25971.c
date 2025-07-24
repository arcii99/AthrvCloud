//FormAI DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define DELAY 100

void show_board(int board[][WIDTH]){
    printf("Current Board:\n");
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            printf("%c ", board[i][j] ? 'X' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int board[][WIDTH], int row, int col){
    int count = 0;
    for(int i=row-1; i<=row+1; i++){
        for(int j=col-1; j<=col+1; j++){
            if(i>=0 && j>=0 && i<HEIGHT && j<WIDTH){
                if(i!=row || j!=col){
                    count += board[i][j];
                }
            }
        }
    }
    return count;
}

void update_board(int board[][WIDTH]){
    int next_board[HEIGHT][WIDTH] = {0};
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            int neighbors = count_neighbors(board, i, j);
            if(board[i][j]){ // cell is alive
                if(neighbors == 2 || neighbors == 3){
                    next_board[i][j] = 1;
                }
            } else { // cell is dead
                if(neighbors == 3){
                    next_board[i][j] = 1;
                }
            }
        }
    }
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            board[i][j] = next_board[i][j];
        }
    }
}

int main(){
    // initialize board with random values
    int board[HEIGHT][WIDTH] = {0};
    srand(time(0));
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            board[i][j] = rand() % 2;
        }
    }

    // play game of life
    int generation = 0;
    while(1){
        printf("Generation: %d\n", generation);
        show_board(board);
        update_board(board);
        generation++;
        usleep(DELAY*1000);
    }

    return 0;
}