//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct{
    int x, y;
} Point;

int main(){
    int maze[MAX][MAX] = {{0}}; // the maze: 0 = empty, 1 = wall
    Point start = {0, 0}; // starting point
    Point end = {9, 9}; // ending point
    Point path[MAX * MAX] = {{0}}; // record the path
    int pathLen = 0; // length of the path
    int visited[MAX][MAX] = {{0}}; // mark which point has been visited
    int i, j, k;

    // initialize the maze
    for(i = 0; i < MAX; i++){
        maze[0][i] = 1;
        maze[i][0] = 1;
        maze[MAX-1][i] = 1;
        maze[i][MAX-1] = 1;
    }
    for(i = 1; i < MAX-1; i++){
        for(j = 1; j < MAX-1; j++){
            if(rand() % 100 < 30){
                maze[i][j] = 1;
            }
        }
    }
    maze[start.x][start.y] = 0; // start point cannot be a wall
    maze[end.x][end.y] = 0; // end point cannot be a wall

    // print the maze
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            if(maze[i][j] == 1){
                printf("#");
            } else if(i == start.x && j == start.y){
                printf("S");
            } else if(i == end.x && j == end.y){
                printf("E");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");

    // set the starting point as visited
    visited[start.x][start.y] = 1;
    path[0] = start;
    pathLen = 1;

    // find the path
    Point current = start;
    while(current.x != end.x || current.y != end.y){
        int foundNext = 0;
        // try four directions
        if(maze[current.x-1][current.y] == 0 && visited[current.x-1][current.y] == 0){
            path[pathLen++] = (Point){current.x-1, current.y};
            visited[current.x-1][current.y] = 1;
            current = (Point){current.x-1, current.y};
            foundNext = 1;
        } else if(maze[current.x][current.y+1] == 0 && visited[current.x][current.y+1] == 0){
            path[pathLen++] = (Point){current.x, current.y+1};
            visited[current.x][current.y+1] = 1;
            current = (Point){current.x, current.y+1};
            foundNext = 1;
        } else if(maze[current.x+1][current.y] == 0 && visited[current.x+1][current.y] == 0){
            path[pathLen++] = (Point){current.x+1, current.y};
            visited[current.x+1][current.y] = 1;
            current = (Point){current.x+1, current.y};
            foundNext = 1;
        } else if(maze[current.x][current.y-1] == 0 && visited[current.x][current.y-1] == 0){
            path[pathLen++] = (Point){current.x, current.y-1};
            visited[current.x][current.y-1] = 1;
            current = (Point){current.x, current.y-1};
            foundNext = 1;
        }
        // if no unvisited path is found, backtrack
        if(foundNext == 0){
            visited[current.x][current.y] = 1;
            pathLen--;
            current = path[pathLen-1];
        }
    }

    // print the path
    for(k = 0; k < pathLen; k++){
        printf("(%d,%d) ", path[k].x, path[k].y);
    }

    return 0;
}