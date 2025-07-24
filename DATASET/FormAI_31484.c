//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surprised
#include <stdio.h>
#define ROW 10
#define COL 10
int visit[ROW][COL];
int grid[ROW][COL];
int shortestPath = 0;

// structure for holding coordinates
struct point {
    int x; 
    int y; 
};

void AStarPathFinding(struct point start, struct point dest) {

    // initialization
    struct point q[ROW * COL];
    int f = 0, r = 0;
    q[r++] = start;
    visit[start.x][start.y] = 1;

    // directions: right, up, left, down
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    while (f < r) {

        int k = 0;
        int minDist = ROW * COL + 1;

        // get the closest neighbors to the goal
        for (int i = 0; i < 4; i++) {

            struct point cur = q[f];
            struct point next = {cur.x + dx[i], cur.y + dy[i]};

            if (next.x < 0 || next.x >= ROW || next.y < 0 || next.y >= COL) {
                continue;
            }

            // find Manhattan distance
            int dist = abs(next.x - dest.x) + abs(next.y - dest.y);

            // update shortest path
            if (dist < minDist && !visit[next.x][next.y] && grid[next.x][next.y]) {
                k = i;
                minDist = dist;
            }
        }

        // record the visit and add the next point to the queue
        struct point cur = q[f];
        f++;
        visit[cur.x][cur.y] = 1;

        // update shortest path
        shortestPath += minDist;

        if (cur.x == dest.x && cur.y == dest.y) {
            return;
        }

        q[r++] = (struct point){cur.x + dx[k], cur.y + dy[k]};

    }
}

int main() {

    // create grid map example
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = 1;
        }
    }

    // mark obstacles
    grid[3][3] = 0;
    grid[4][3] = 0;
    grid[5][3] = 0;

    // mark start and end points
    struct point start = {0, 0};
    struct point dest = {9, 9};

    // run A* pathfinding algorithm
    AStarPathFinding(start, dest);

    // print shortest path
    printf("Shortest path: %d\n", shortestPath);

    return 0;
}