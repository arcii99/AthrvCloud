//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
int maze[ROWS][COLS] = {
    {1,1,1,1,1,1,0,1,1,1},
    {1,0,0,0,1,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,1,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};
int visited[ROWS][COLS];
int startX = 1, startY = 1;
int endX = 8, endY = 8;
int countSteps = 0;
int steps[ROWS*COLS][2];

void dfs(int x, int y) {
    visited[x][y] = 1;
    steps[countSteps][0] = x;
    steps[countSteps][1] = y;
    countSteps++;

    if(x == endX && y == endY) {
        printf("Path found!\n");
        for(int i = 0; i < countSteps; i++)
            printf("(%d, %d)\n", steps[i][0], steps[i][1]);
        return;
    }

    if(x-1 >= 0 && maze[x-1][y] == 0 && !visited[x-1][y])
        dfs(x-1, y);

    if(x+1 < ROWS && maze[x+1][y] == 0 && !visited[x+1][y])
        dfs(x+1, y);

    if(y-1 >= 0 && maze[x][y-1] == 0 && !visited[x][y-1])
        dfs(x, y-1);

    if(y+1 < COLS && maze[x][y+1] == 0 && !visited[x][y+1])
        dfs(x, y+1);

    countSteps--;
}

int main() {
    dfs(startX, startY);
    return 0;
}