//FormAI DATASET v1.0 Category: Game of Life ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define ROWS 20
#define COLS 20
#define SEED 42
#define DELAY 50000

int grid[ROWS][COLS];

void init_grid() {
    srand(SEED);
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid() {
    printf("\033[2J"); // clear screen
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", grid[i][j] ? '#':' ');
        }
        printf("\n");
    }
}

int count_neighbors(int row, int col) {
    int count = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            // wrap around edges
            int ii = (i + ROWS) % ROWS;
            int jj = (j + COLS) % COLS;
            if(grid[ii][jj] == 1 && !(ii==row && jj==col)) 
                count++;
        }
    }
    return count;
}

void *compute_grid(void *arg) {
    int thread_id = *(int*)arg;
    int start_row = thread_id * (ROWS / 4);
    int end_row = start_row + (ROWS / 4);

    for(int i=start_row; i<end_row; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbors = count_neighbors(i, j);
            if(grid[i][j] == 1 && (neighbors<2 || neighbors>3)) 
                grid[i][j] = 0;
            else if(grid[i][j] == 0 && neighbors == 3) 
                grid[i][j] = 1;       
        }
    }
    return NULL;
}

int main() {
    init_grid();
    printf("Press CTRL+C to stop\n");

    while(1) {
        print_grid();

        pthread_t threads[4];
        int thread_ids[4] = {0,1,2,3};
        for(int i=0; i<4; i++) {
            pthread_create(&threads[i], NULL, compute_grid, &thread_ids[i]);
        }
        for(int i=0; i<4; i++) {
            pthread_join(threads[i], NULL);
        }

        usleep(DELAY);
    }

    return 0;
}