//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

typedef struct{
    int x;
    int y;
}Coord;

Coord start = {0, 0};
Coord finish = {ROWS-1, COLS-1};

char maze[ROWS][COLS] = {
    {'S','#','#','#','#','#','#','#','#','#'},
    {' ',' ',' ','#',' ',' ','#','#','#',' '},
    {'#','#',' ','#',' ',' ','#','#','#','#'},
    {'#',' ',' ',' ','#',' ','#','#',' ','#'},
    {'#',' ','#','#','#',' ','#','#',' ','#'},
    {'#',' ',' ',' ','#',' ','#',' ',' ',' '},
    {'#','#','#','#','#','#','#','#',' ','#'},
    {'#',' ',' ',' ',' ',' ',' ','#',' ','#'},
    {'#','#','#','#','#','#',' ','#','#','#'},
    {'#','#','#','#','#','#',' ','#','#','F'}
};

int visited[ROWS][COLS];

void printMaze(){
    printf("\n");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int isValid(int x, int y){
    if(x < 0 || y < 0 || x >= ROWS || y >= COLS){
        return 0;
    }
    if(maze[x][y] == '#' || visited[x][y] == 1){
        return 0;
    }
    return 1;
}

void BFS(){
    Coord queue[ROWS*COLS];
    int front = 0, rear = 0;
    queue[rear] = start;
    rear++;
    visited[start.x][start.y] = 1;

    int parent[ROWS][COLS][2];
    memset(parent, -1, sizeof(parent));
    parent[start.x][start.y][0] = -2;

    while(front < rear){
        Coord current = queue[front];
        front++;
        if(current.x == finish.x && current.y == finish.y){
            break;
        }
        int x = current.x;
        int y = current.y;

        if(isValid(x-1,y)){ // Check North
            queue[rear] = (Coord){x-1, y};
            rear++;
            visited[x-1][y] = 1;
            parent[x-1][y][0] = x;
            parent[x-1][y][1] = y;
        }
        if(isValid(x+1,y)){ // Check South
            queue[rear] = (Coord){x+1, y};
            rear++;
            visited[x+1][y] = 1;
            parent[x+1][y][0] = x;
            parent[x+1][y][1] = y;
        }
        if(isValid(x,y-1)){ // Check West
            queue[rear] = (Coord){x, y-1};
            rear++;
            visited[x][y-1] = 1;
            parent[x][y-1][0] = x;
            parent[x][y-1][1] = y;
        }
        if(isValid(x,y+1)){ // Check East
            queue[rear] = (Coord){x, y+1};
            rear++;
            visited[x][y+1] = 1;
            parent[x][y+1][0] = x;
            parent[x][y+1][1] = y;
        }
    }

    Coord path[ROWS*COLS];
    int pathIndex = 0;
    int x = finish.x, y = finish.y;
    while(parent[x][y][0] != -2){
        path[pathIndex] = (Coord){x, y};
        pathIndex++;
        int tempX = parent[x][y][0];
        int tempY = parent[x][y][1];
        x = tempX;
        y = tempY;
    }
    path[pathIndex] = (Coord){x, y};
    pathIndex++;

    printf("Path from start to end: \n");
    for(int i = pathIndex-1; i >=0; i--){
        printf("(%d, %d)", path[i].x, path[i].y);
        if(i){
            printf(" -> ");
        }
    }
    printf("\n");
}

int main(){
    memset(visited, 0, sizeof(visited));

    printf("Original Maze: \n");
    printMaze();

    BFS();

    return 0;
}