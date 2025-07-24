//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 8 // number of maze rows
#define COLS 8 // number of maze columns

int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 0},
    {0, 1, 0, 1, 0, 0, 1, 0},
    {0, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 1, 0},
    {0, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

typedef struct {
    int x, y;
} point;

point directions[4] = {{1,0}, {0,1}, {-1,0}, {0,-1}}; // possible directions: right, down, left, up

bool isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= ROWS || y >= COLS){
        return false;
    }
    if(maze[x][y] == 0){
        return false;
    }
    return true;
}

point findRoute() {
    point start = {1, 1}; // starting point
    bool visited[ROWS][COLS] = {{false}}; // mark all points as unvisited
    point stack[ROWS * COLS]; // use stack to store visited points
    int top = 0;
    visited[start.x][start.y] = true; // mark start point as visited
    stack[top] = start; // add start point to the stack
    while(top >= 0){ // while stack is not empty
        point current = stack[top];
        top--;
        if(current.x == ROWS - 2 && current.y == COLS - 2){ // if we reached the end
            return current;
        }
        for(int i = 0; i < 4; ++i){
            point next = {current.x + directions[i].x, current.y + directions[i].y};
            if(isValid(next.x, next.y) && !visited[next.x][next.y]){
                visited[next.x][next.y] = true; // mark as visited
                stack[++top] = next; // add to the stack
            }
        }
    }
    point invalid = {-1, -1}; // return an invalid point if route not found
    return invalid;
}

int main() {
    point routeEnd = findRoute(); // find the end of the route
    if(routeEnd.x == -1 && routeEnd.y == -1) { // if route not found
        printf("Route not found.\n");
        return 0;
    }
    printf("Route found from (1,1) to (%d,%d):\n", routeEnd.x, routeEnd.y);
    for(int i = 0; i < ROWS; ++i){
        for(int j = 0; j < COLS; ++j){
            if(i == 1 && j == 1){ // start point
                printf("S ");
            } else if(i == routeEnd.x && j == routeEnd.y){ // end point
                printf("E ");
            } else if(maze[i][j] == 0){ // wall
                printf("# ");
            } else if(maze[i][j] == 1){ // path
                printf(". ");
            }
        }
        printf("\n");
    }
    return 0;
}