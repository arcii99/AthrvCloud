//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

bool visited[ROW][COL];

int maze[ROW][COL] = {{0, 1, 0, 0, 0},
                      {0, 1, 0, 1, 0},
                      {0, 0, 0, 1, 0},
                      {1, 1, 1, 0, 0},
                      {0, 0, 0, 0, 0}};

void printMaze() {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int posX, int posY) {
    if(posX >= 0 && posX < ROW && posY >= 0 && posY < COL && maze[posX][posY] == 0 && !visited[posX][posY])
        return true;
    return false;
}

bool findRoute(int posX, int posY, int path[ROW][COL]){
    
    if(posX == ROW - 1 && posY == COL - 1){
        path[posX][posY] = 1;
        return true;
    }
    
    if(isSafe(posX, posY)){
        visited[posX][posY] = true;
        path[posX][posY] = 1;
        
        if(findRoute(posX + 1, posY, path))
            return true;
        if(findRoute(posX, posY + 1, path))
            return true;
        if(findRoute(posX - 1, posY, path))
            return true;
        if(findRoute(posX, posY - 1, path))
            return true;
        
        path[posX][posY] = 0;
        return false;
    }
    
    return false;
}

int main() {
    int path[ROW][COL] = {{0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0}};
                          
    printf("Original maze: \n");
    printMaze();
    
    if(findRoute(0, 0, path)){
        printf("Path found!\n\n");
        for(int i = 0; i < ROW; i++) {
            for(int j = 0; j < COL; j++) {
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No path found!");
    }
    
    return 0;
}