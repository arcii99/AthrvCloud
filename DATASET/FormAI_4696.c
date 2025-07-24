//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define ROW 15
#define COL 15

typedef struct {
    int x, y;
} Point;

Point start = {0, 0};
Point end = {ROW-1, COL-1};
pthread_mutex_t mazeLock;
char maze[ROW][COL];

bool is_valid(int row, int col) {
    return row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == '.';
}

void* generate_maze(void* arg) {
    srand(time(NULL));
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            maze[i][j] = rand() % 2 == 0 ? '.' : '#';
        }
    }

    pthread_exit(NULL);
}

bool depth_first_search(int row, int col) {
    if(row == end.x && col == end.y) return true;

    if(!is_valid(row, col)) return false;

    pthread_mutex_lock(&mazeLock);
    maze[row][col] = '+';
    pthread_mutex_unlock(&mazeLock);

    int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    for(int k = 0; k < 4; k++) {
        int newRow = row + directions[k][0];
        int newCol = col + directions[k][1];
        if(depth_first_search(newRow, newCol)) return true;
    }

    pthread_mutex_lock(&mazeLock);
    maze[row][col] = '.';
    pthread_mutex_unlock(&mazeLock);

    return false;
}

void* generate_path(void* arg) {
    depth_first_search(start.x, start.y);

    pthread_exit(NULL);
}

void print_maze() {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    pthread_t mazeThread, pathThread;
    pthread_mutex_init(&mazeLock, NULL);

    pthread_create(&mazeThread, NULL, generate_maze, NULL);
    pthread_join(mazeThread, NULL);

    pthread_create(&pathThread, NULL, generate_path, NULL);
    pthread_join(pathThread, NULL);

    print_maze();

    pthread_mutex_destroy(&mazeLock);
    return 0;
}