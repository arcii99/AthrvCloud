//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#define N 9 // change N as per your maze size

int map[N][N] = { // 1 signifies blocked, 0 signifies accessible
    { 0, 0, 0, 1, 1, 1, 1, 1, 1 },
    { 1, 0, 1, 0, 1, 0, 0, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 1, 1, 1 },
    { 1, 0, 1, 1, 1, 1, 1, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 0, 1, 0, 1 },
    { 1, 0, 0, 0, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 0, 1, 0, 1 },
    { 1, 1, 1, 1, 1, 0, 0, 0, 0 },
};
int visited[N][N];

int dfs(int x,int y) {
    if(x == N - 1 && y == N - 1) { // destination found
        visited[x][y] = 1;
        return 1;
    }
    if(x < 0 || y < 0 || x >= N || y >= N) { // out of bound
        return 0;
    }
    if(visited[x][y] == 1) { // already explored
        return 0;
    }
    if(map[x][y] == 1) { // blocked
        return 0;
    }
    visited[x][y] = 1; // visited
    if(dfs(x + 1,y)) { // moving down
        return 1;
    }
    if(dfs(x,y + 1)) { // moving right
        return 1;
    }
    if(dfs(x - 1,y)) { // moving up
        return 1;
    }
    if(dfs(x,y - 1)) { // moving left
        return 1;
    }
    return 0;
}

int main() {
    int i,j;
    for(i = 0;i < N;i++) { // initializing visited nodes
        for(j = 0;j < N;j++) {
            visited[i][j] = 0;
        }
    }

    printf("The given maze is : \n");
    for(i = 0;i < N;i++) { // printing the given maze
        for(j = 0;j < N;j++) {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }

    if(dfs(0,0)) { // dfs to find route
        printf("\n\nThe found route is : \n\n");
        for(i = 0;i < N;i++) { // printing the route
            for(j = 0;j < N;j++) {
                if(visited[i][j] == 1) {
                    printf("o ");
                }
                else {
                    printf("x ");
                }
            }
            printf("\n");
        }
    }
    else { // no route found
        printf("No route found");
    }
    return 0;
}