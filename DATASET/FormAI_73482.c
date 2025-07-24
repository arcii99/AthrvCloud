//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 10
#define COL 10

int isVisited[ROW][COL];
int maze[ROW][COL];

void dfs(int x, int y) {
    if(x < 0 || x >= ROW || y < 0 || y >= COL) {
        return;
    }

    if(isVisited[x][y]) {
        return;
    }

    isVisited[x][y] = 1;
    maze[x][y] = 0;

    int dir = rand() % 4;

    if(dir == 0) {
        dfs(x + 1, y);
    }
    else if(dir == 1) {
        dfs(x - 1, y);
    }
    else if(dir == 2) {
        dfs(x, y + 1);
    }
    else if(dir == 3) {
        dfs(x, y - 1);
    }
}

int main() {
    srand(time(0));

    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            maze[i][j] = 1;
        }
    }

    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            isVisited[i][j] = 0;
        }
    }

    dfs(0, 0);

    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}