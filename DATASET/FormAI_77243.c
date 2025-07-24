//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int startX = 0;
int startY = 0;
int endX = 4;
int endY = 4;

int maze[ROWS][COLS] = {
    {0,0,0,0,0},
    {0,1,0,1,0},
    {0,1,0,1,0},
    {0,1,0,1,0},
    {0,0,0,0,0}
};

int visited[ROWS][COLS];

void dfs(int x, int y, int steps) {
    if(x == endX && y == endY) {
        printf("You win in %d steps!\n", steps);
        return;
    }
    
    visited[x][y] = 1;
    
    int nextX, nextY;
    int minDist = ROWS * COLS + 1;

    // find the unvisited neighbor with the smallest Manhattan distance to the target
    if(x > 0 && !visited[x-1][y] && maze[x-1][y] == 0) {
        int dist = abs(x-1 - endX) + abs(y - endY);
        if(dist < minDist) {
            minDist = dist;
            nextX = x - 1;
            nextY = y;
        }
    }
    
    if(x < ROWS - 1 && !visited[x+1][y] && maze[x+1][y] == 0) {
        int dist = abs(x+1 - endX) + abs(y - endY);
        if(dist < minDist) {
            minDist = dist;
            nextX = x + 1;
            nextY = y;
        }
    }
    
    if(y > 0 && !visited[x][y-1] && maze[x][y-1] == 0) {
        int dist = abs(x - endX) + abs(y-1 - endY);
        if(dist < minDist) {
            minDist = dist;
            nextX = x;
            nextY = y - 1;
        }
    }
    
    if(y < COLS - 1 && !visited[x][y+1] && maze[x][y+1] == 0) {
        int dist = abs(x - endX) + abs(y+1 - endY);
        if(dist < minDist) {
            minDist = dist;
            nextX = x;
            nextY = y + 1;
        }
    }
    
    if(minDist != ROWS * COLS + 1) {
        dfs(nextX, nextY, steps + 1);
    }
}

int main() {
    dfs(startX, startY, 0);
    return 0;
}