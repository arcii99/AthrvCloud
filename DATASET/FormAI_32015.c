//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROW 5
#define COL 5

int graph[ROW][COL] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0}
};

int visited[ROW];

struct bfs_args {
    int start_row;
};

void bfs(int start_row) {
    printf("Starting traversal from row %d\n", start_row);

    visited[start_row] = 1;

    int queue[ROW];
    int front = -1;
    int rear = -1;

    queue[++rear] = start_row;

    while(front != rear) {
        int current_row = queue[++front];

        printf("Visiting row %d\n", current_row);

        for(int col = 0; col < COL; col++) {
            if(graph[current_row][col] == 1 && visited[col] == 0) {
                visited[col] = 1;
                queue[++rear] = col;
            }
        }
    }
}

void *thread_bfs(void *args) {
    struct bfs_args *bfs_args = (struct bfs_args *)args;
    bfs(bfs_args->start_row);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[ROW];
    struct bfs_args args[ROW];

    for(int i = 0; i < ROW; i++) {
        args[i].start_row = i;
        pthread_create(&threads[i], NULL, thread_bfs, (void *)&args[i]);
    }

    for(int i = 0; i < ROW; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}