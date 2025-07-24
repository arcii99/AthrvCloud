//FormAI DATASET v1.0 Category: Game of Life ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define ROWS 20
#define COLS 20

int matrix[ROWS][COLS];
int copy[ROWS][COLS];

void randomize_matrix() {
    int i, j, num;
    srand((unsigned) time(NULL));
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            num = rand() % 2;
            matrix[i][j] = num;
        }
    }
}

void print_matrix() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            printf("%c ", matrix[i][j] ? '#' : '-');
        }
        printf("\n");
    }
    printf("\n");
}

void copy_matrix() {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            copy[i][j] = matrix[i][j];
        }
    }
}

void update_cell(int i, int j) {
    int live_neighbors = 0;
    int k, l;
    for(k = -1; k <= 1; k++) {
        for(l = -1; l <= 1; l++) {
            if(i+k >= 0 && i+k < ROWS && j+l >= 0 && j+l < COLS && !(k == 0 && l == 0)) {
                if(matrix[i+k][j+l]) {
                    live_neighbors++;
                }
            }
        }
    }
    if(matrix[i][j] && (live_neighbors < 2 || live_neighbors > 3)) {
        copy[i][j] = 0;
    }
    else if(!matrix[i][j] && live_neighbors == 3) {
        copy[i][j] = 1;
    }
}

void update_matrix(int thread_rows, int thread_id) {
    int start = thread_id * thread_rows;
    int end = start + thread_rows;
    int i, j;
    for(i = start; i < end; i++) {
        for(j = 0; j < COLS; j++) {
            update_cell(i, j);
        }
    }
}

void *worker(void *arg) {
    int thread_id = *(int*) arg;
    int thread_rows = ROWS / 4;
    update_matrix(thread_rows, thread_id);
    return NULL;
}

int main() {
    randomize_matrix();

    while(1) {
        system("clear");
        print_matrix();
        copy_matrix();

        pthread_t threads[4];
        int thread_ids[4];
        int i;
        for(i = 0; i < 4; i++) {
            thread_ids[i] = i;
            pthread_create(&threads[i], NULL, worker, &thread_ids[i]);
        }

        for(i = 0; i < 4; i++) {
            pthread_join(threads[i], NULL);
        }

        for(i = 0; i < ROWS; i++) {
            int j;
            for(j = 0; j < COLS; j++) {
                matrix[i][j] = copy[i][j];
            }
        }
        usleep(100000);
    }

    return 0;
}