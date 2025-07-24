//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: multi-threaded
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

#define ROW 10
#define COL 10
#define MAX_THREADS 5

sem_t s_mutex;

int maze[ROW][COL] =
        {
                {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
                {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                {0, 1, 1, 1, 1, 1, 1, 1, 0, 0}
        };
int sol[ROW][COL] = {0};
int srcx, srcy, destx, desty;
int found = 0;
int active_threads = 0;

void *searchPath(void *args) {
    sem_wait(&s_mutex);
    active_threads++;
    int tid = *((int *) args);
    int i, j;
    for (i = tid; i < ROW; i += MAX_THREADS) {
        for (j = 0; j < COL; j++) {
            if (i == srcx && j == srcy) {
                sol[i][j] = 1;
            }
            if (maze[i][j] == 1 && sol[i][j] == 0) {
                sol[i][j] = 1;
                if (i == destx && j == desty) {
                    found = 1;
                    active_threads--;
                    sem_post(&s_mutex);
                    pthread_exit(NULL);
                }
            }
        }
    }
    active_threads--;
    sem_post(&s_mutex);
    pthread_exit(NULL);
}

int main() {
    sem_init(&s_mutex, 0, 1);

    srcx = 0, srcy = 0, destx = 9, desty = 8;
    pthread_t threads[MAX_THREADS];
    int i, tid[MAX_THREADS];
    for (i = 0; i < MAX_THREADS; i++) {
        tid[i] = i;
        pthread_create(&threads[i], NULL, searchPath, (void *) &tid[i]);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    if (found) {
        printf("Path Found\n");
    } else {
        printf("Path Not Found\n");
    }
    return 0;
}