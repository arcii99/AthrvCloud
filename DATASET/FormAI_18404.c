//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,1,1,0,0},
    {0,1,0,1,0,0,1,0,1,0},
    {0,1,0,0,1,0,1,0,0,0},
    {0,0,1,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,1,1,0,0},
    {0,0,0,1,1,0,0,0,0,0},
    {0,1,0,1,0,0,0,1,0,0},
    {0,0,1,0,0,1,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0}
};

struct Point {
    int row;
    int col;
};

void printGrid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool isValidCell(int row, int col) {
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS || grid[row][col] == 0) {
        return false;
    }
    return true;
}

bool isDestination(int row, int col, struct Point dest) {
    if(row == dest.row && col == dest.col) {
        return true;
    }
    return false;
}

void findPath(struct Point src, struct Point dest) {
    int dr[] = {-1, 0, 0, 1};
    int dc[] = {0, -1, 1, 0};
    
    bool visited[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            visited[i][j] = false;
        }
    }
    
    struct Point queue[ROWS*COLS];
    int front = 0;
    int rear = 0;
    
    visited[src.row][src.col] = true;
    queue[rear++] = src;
    bool foundDest = false;
    
    while(front != rear) {
        struct Point curr = queue[front++];
        
        if(isDestination(curr.row, curr.col, dest)) {
            foundDest = true;
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int rr = curr.row + dr[i];
            int cc = curr.col + dc[i];
            if(isValidCell(rr, cc) && !visited[rr][cc]) {
                visited[rr][cc] = true;
                struct Point neighbor = {rr, cc};
                queue[rear++] = neighbor;
            }
        }
    }
    
    if(foundDest) {
        printf("Path found!\n");
    } else {
        printf("Path not found.\n");
    }
}

int main() {
    struct Point src = {1, 1};
    struct Point dest = {8, 8};
    findPath(src, dest);
    printGrid();
    return 0;
}