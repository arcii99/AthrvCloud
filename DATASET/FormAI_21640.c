//FormAI DATASET v1.0 Category: Game of Life ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define WIDTH 40
#define HEIGHT 20
#define ALIVE 1
#define DEAD 0

int board[WIDTH][HEIGHT];
int new_board[WIDTH][HEIGHT];

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// generate random initial board
void init_board() {
    srand(time(NULL));
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// print current board
void print_board() {
    printf("\033[H");
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            if(board[i][j] == ALIVE) printf("\u25A0 ");
            else printf("  ");
        }
        printf("\n");
    }
}

// check number of live neighbors for a cell
int count_neighbors(int x, int y) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int row = (x+i+WIDTH) % WIDTH;
            int col = (y+j+HEIGHT) % HEIGHT;
            count += board[row][col];
        }
    }
    count -= board[x][y];
    return count;
}

// calculate new board based on current board
void* calculate_board(void* arg) {
    int start = *((int *) arg);
    for(int i=start; i<WIDTH*HEIGHT; i+=2) {
        int x = i / HEIGHT;
        int y = i % HEIGHT;
        int neighbors = count_neighbors(x, y);
        if(board[x][y] == ALIVE) {
            if(neighbors < 2 || neighbors > 3) new_board[x][y] = DEAD;
            else new_board[x][y] = ALIVE;
        } else {
            if(neighbors == 3) new_board[x][y] = ALIVE;
            else new_board[x][y] = DEAD;
        }
    }
    pthread_exit(NULL);
}

// update the board with new board
void update_board() {
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

// main simulation loop
void run_simulation(int num_threads) {
    pthread_t threads[num_threads];
    int thread_args[num_threads];
    for(int i=0; i<num_threads; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, calculate_board, &thread_args[i]);
    }
    for(int i=0; i<num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    update_board();
}

// main function
int main() {
    int num_threads = 2;
    init_board();
    while(1) {
        print_board();
        usleep(100000);
        run_simulation(num_threads);
    }
    pthread_mutex_destroy(&lock);
    return 0;
}