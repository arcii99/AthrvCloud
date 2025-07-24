//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define N 8

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int map[N][N];
int visited[N][N];

int queue[N * N][3];
int head, tail;

void bfs(int x, int y) {

    queue[head][0] = x;
    queue[head][1] = y;
    queue[head][2] = 0;

    while (head < tail) {

        int x = queue[head][0];
        int y = queue[head][1];
        int dist = queue[head][2];

        if (visited[x][y]) {
            head++;
            continue;
        }

        visited[x][y] = 1;

        if (map[x][y] == 2) {
            printf("Found the treasure! Distance: %d\n", dist);
            return;
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            queue[tail][0] = nx;
            queue[tail][1] = ny;
            queue[tail][2] = dist + 1;
            tail++;
        }

        head++;
    }

    printf("The treasure is nowhere to be found!\n");
}

int main() {

    // Fill the map with random values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = rand() % 3;
        }
    }

    // Place the treasure
    int tx = rand() % N;
    int ty = rand() % N;
    map[tx][ty] = 2;

    // Set the starting position
    int sx = rand() % N;
    int sy = rand() % N;

    // Find the treasure
    bfs(sx, sy);

    return 0;
}