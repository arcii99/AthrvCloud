//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ROW 5
#define MAX_COL 5

typedef struct {
    int x;
    int y;
} Position;

Position start_pos = {0,0};
Position end_pos = {MAX_ROW-1, MAX_COL-1};
int maze[MAX_ROW][MAX_COL] = {
    {0,0,0,0,1},
    {0,1,1,0,1},
    {0,1,0,0,1},
    {0,1,0,1,0},
    {0,0,0,0,0}
};
int visited[MAX_ROW][MAX_COL] = {0}; // Mark visited positions
Position path[MAX_ROW*MAX_COL]; // Store path

int path_len = 0; // Length of path
int can_find_path = 1; // Flag to indicate whether path can be found

void* dfs(void* arg) {
    Position* curr = arg;
    visited[curr->x][curr->y] = 1;

    // If we have reached the end position, stop and return
    if (curr->x == end_pos.x && curr->y == end_pos.y) {
        path[path_len++] = end_pos;
        can_find_path = 0;
        return NULL;
    }

    // Check the neighbours of the current position
    if (curr->x > 0 && maze[curr->x-1][curr->y] == 0 && !visited[curr->x-1][curr->y]) { // Up
        Position next_pos = {curr->x-1, curr->y};
        dfs(&next_pos);
        if (!can_find_path) {
            path[path_len++] = *curr;
            return NULL;
        }
    }
    if (curr->x < MAX_ROW-1 && maze[curr->x+1][curr->y] == 0 && !visited[curr->x+1][curr->y]) { // Down
        Position next_pos = {curr->x+1, curr->y};
        dfs(&next_pos);
        if (!can_find_path) {
            path[path_len++] = *curr;
            return NULL;
        }
    }
    if (curr->y > 0 && maze[curr->x][curr->y-1] == 0 && !visited[curr->x][curr->y-1]) { // Left
        Position next_pos = {curr->x, curr->y-1};
        dfs(&next_pos);
        if (!can_find_path) {
            path[path_len++] = *curr;
            return NULL;
        }
    }
    if (curr->y < MAX_COL-1 && maze[curr->x][curr->y+1] == 0 && !visited[curr->x][curr->y+1]) { // Right
        Position next_pos = {curr->x, curr->y+1};
        dfs(&next_pos);
        if (!can_find_path) {
            path[path_len++] = *curr;
            return NULL;
        }
    }

    return NULL;
}

int main() {
    pthread_t t;
    dfs(&start_pos);
    if (can_find_path) printf("Cannot find a path\n");
    else {
        printf("Path found:\n");
        for (int i=path_len-1; i>=0; i--) {
            printf("(%d,%d) -> ", path[i].x, path[i].y);
        }
        printf("\n");
    }
    return 0;
}