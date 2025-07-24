//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void explore(int x, int y, int visited[10][10]) {
    if (visited[x][y]) return; // already visited this planet
    visited[x][y] = 1; // mark as visited

    printf("Exploring Planet (%d, %d)...\n", x, y);

    // generate random events
    int event = rand() % 3;
    switch (event) {
        case 0:
            printf("Found a new species!\n");
            break;
        case 1:
            printf("Detected a dangerous asteroid field, evading...\n");
            break;
        case 2:
            printf("Discovered a valuable mineral deposit!\n");
            break;
    }

    // generate nearby planet coordinates
    int nearby[4][2] = {{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}};

    // randomly shuffle the nearby planets
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int temp[2] = {nearby[i][0], nearby[i][1]};
        nearby[i][0] = nearby[j][0];
        nearby[i][1] = nearby[j][1];
        nearby[j][0] = temp[0];
        nearby[j][1] = temp[1];
    }

    // recursively explore nearby planets
    for (int i = 0; i < 4; i++) {
        int nx = nearby[i][0];
        int ny = nearby[i][1];
        if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10) {
            explore(nx, ny, visited);
        }
    }
}

int main() {
    srand(time(NULL));

    int visited[10][10] = {{0}}; // initialize all planets as unvisited

    // randomly select starting planet
    int sx = rand() % 10;
    int sy = rand() % 10;

    printf("Starting exploration at Planet (%d, %d)\n", sx, sy);

    explore(sx, sy, visited);

    printf("Exploration complete!\n");

    return 0;
}