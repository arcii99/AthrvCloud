//FormAI DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BOARD_SIZE 20
#define GENERATION_INTERVAL 200000 //microseconds

int board[BOARD_SIZE][BOARD_SIZE] = {0}; //initially all cells are dead

void init_board() {
    // randomly initialize the board
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board() {
    // print current state of the board
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c", board[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

int count_live_neighbors(int i, int j) {
    // count the number of live neighbors of cell i,j
    int count = 0;
    for(int x=i-1; x<=i+1; x++) {
        for(int y=j-1; y<=j+1; y++) {
            if(x>=0 && x<BOARD_SIZE && y>=0 && y<BOARD_SIZE && !(x==i && y==j)) {
                count += board[x][y];
            }
        }
    }
    return count;
}

void *simulate_generation() {
    while(1) {
        // simulate one generation
        int new_board[BOARD_SIZE][BOARD_SIZE] = {0};
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                int live_neighbors = count_live_neighbors(i,j);
                if(board[i][j]) {
                    if(live_neighbors < 2 || live_neighbors > 3) {
                        new_board[i][j] = 0;
                    }
                    else {
                        new_board[i][j] = 1;
                    }
                } 
                else {
                    if(live_neighbors == 3) {
                        new_board[i][j] = 1;
                    }
                }       
            }
        }
        // update the board
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                board[i][j] = new_board[i][j];
            }
        }
        print_board();
        usleep(GENERATION_INTERVAL);
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    init_board(); // initialize the board
    print_board(); // print the initial state of the board
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, simulate_generation, NULL);
    // handle any errors during thread creation
    if(ret) {
        printf("Error: pthread_create returned %d", ret);
        exit(-1);
    }
    pthread_join(tid, NULL); // join the thread
    return 0;
}