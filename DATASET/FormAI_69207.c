//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ephemeral
#include <stdio.h>
#define N 10

char maze[N][N] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', 'S', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
    {'#', '#', ' ', '#', ' ', '#', ' ', '#', '#', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', '#', ' ', '#', '#', '#'},
    {'#', ' ', 'E', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
};

int startX = 1, startY = 1, endX = 8, endY = 2;
int visited[N][N];

void printMaze(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int dfs(int x, int y){
    if (x == endX && y == endY){
        return 1;
    }
    visited[x][y] = 1;
    if (maze[x-1][y] != '#' && !visited[x-1][y]){
        if (dfs(x-1, y)){
            return 1;
        }
    }
    if (maze[x+1][y] != '#' && !visited[x+1][y]){
        if (dfs(x+1, y)){
            return 1;
        }
    }
    if (maze[x][y-1] != '#' && !visited[x][y-1]){
        if (dfs(x, y-1)){
            return 1;
        }
    }
    if (maze[x][y+1] != '#' && !visited[x][y+1]){
        if (dfs(x, y+1)){
            return 1;
        }
    }
    return 0;
}

int main() {
    printMaze();
    printf("\n");
    int res = dfs(startX, startY);
    if (res){
        visited[startX][startY] = 0;
        int x = startX, y = startY;
        while (x != endX || y != endY){
            if (maze[x-1][y] != '#' && visited[x-1][y] == 0){
                x--;
            }
            else if (maze[x+1][y] != '#' && visited[x+1][y] == 0){
                x++;
            }
            else if (maze[x][y-1] != '#' && visited[x][y-1] == 0){
                y--;
            }
            else {
                y++;
            }
            visited[x][y] = 0;
            printf("(%d,%d)->", x, y);
        }
        printf("(%d,%d)\n", endX, endY);
    }
    else {
        printf("No path found.\n");
    }
    return 0;
}