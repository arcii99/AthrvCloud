//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>

#define ROW 5
#define COL 5

typedef struct{
    int row;
    int col;
} Point;

typedef struct {
    int row_change;
    int col_change;
} Move;

bool visited[ROW][COL];
bool maze[ROW][COL] = {
    {true, true, false, true, true},
    {true, false, false, true, true},
    {true, false, true, false, true},
    {true, false, false, false, true},
    {true, true, true, true, true}
};

Move moves[4] = {{-1,0}, {0,1}, {1,0}, {0,-1}}; // Up, right, down, left

Point destination = {4, 3};

void* find_route(void* args) {
    Point current = *(Point*) args;
    visited[current.row][current.col] = true;

    if(current.row == destination.row && current.col == destination.col) {
        printf("\nDestination reached\n");
        pthread_exit(NULL);
    }

    for(int i=0; i<4; i++) {
        int next_row = current.row + moves[i].row_change;
        int next_col = current.col + moves[i].col_change;

        if(next_row >=0 && next_row <ROW && next_col >= 0 && next_col <COL && !maze[next_row][next_col] && !visited[next_row][next_col]) {
            Point next = {next_row, next_col};
            printf("Moving from %d,%d to %d,%d\n", current.row, current.col, next_row, next_col);
            find_route((void*) &next);
        }
    }

    pthread_exit(NULL);
}

int main() {
    memset(visited, false, sizeof visited);

    Point start = {0, 0};
    pthread_t thread;

    printf("Finding route...\n\n");

    if(pthread_create(&thread, NULL, find_route, (void*) &start)) {
        printf("Error creating thread");
        return -1;
    }

    if(pthread_join(thread, NULL)) {
        printf("Error joining thread");
        return -1;
    }

    return 0;
}