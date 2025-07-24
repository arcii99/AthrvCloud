//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

#define ROW 10
#define COL 10

int visited[ROW][COL];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int path[ROW][COL];
int sx, sy, fx, fy;

void dfs(int x, int y, int cnt) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < ROW && ny >= 0 && ny < COL && !visited[nx][ny] && !path[nx][ny]) {
            path[nx][ny] = cnt + 1;
            dfs(nx, ny, cnt + 1);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &sx, &sy, &fx, &fy);

    sx--;
    sy--;
    fx--;
    fy--;

    path[sx][sy] = 1;
    dfs(sx, sy, 1);

    printf("%d\n", path[fx][fy] - 1);

    return 0;
}