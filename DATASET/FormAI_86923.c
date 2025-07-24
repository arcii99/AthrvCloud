//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COLUMN 20

void printMaze(char maze[][COLUMN]);
void findRoute(char maze[][COLUMN], int x, int y, int visited[][COLUMN]);

int main() {
    char maze[ROW][COLUMN] = {
        {'*', '*', '*', ' ', '*', ' ', '*', '*', '*', '*', '*', '*', ' ', '*', ' ', '*', '*', '*', '*', '*'},
        {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'},
        {'*', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', '*', '*', '*', '*', '*'},
        {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*'},
        {'*', '*', '*', ' ', '*', '*', '*', '*', '*', ' ', '*', ' ', '*', '*', '*', '*', ' ', '*', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*'},
        {'*', '*', '*', '*', '*', '*', '*', ' ', '*', ' ', '*', ' ', '*', '*', '*', '*', ' ', '*', ' ', '*'},
        {'*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', '*'},
        {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', ' ', '*', '*', '*', ' ', '*', ' ', 'G'},
        {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', ' ', '*', '*', '*'},
    };

    int visited[ROW][COLUMN] = {0};
    int startX = 7, startY = 0; // Starting position

    printf("Maze:\n");
    printMaze(maze);

    printf("\nFinding route...\n");
    findRoute(maze, startX, startY, visited);

    printf("\nVisited cells:\n");
    printMaze((char*)visited);

    return 0;
}

void printMaze(char maze[][COLUMN]) {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COLUMN; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void findRoute(char maze[][COLUMN], int x, int y, int visited[][COLUMN]) {
    visited[x][y] = 1;

    if(maze[x][y] == 'G') { // Base case: exit found
        printf("Exit found at (%d, %d)!\n", x, y);
        return;
    }

    // Check each neighboring cell
    if(maze[x][y+1] != '*' && visited[x][y+1] == 0) { // Right
        findRoute(maze, x, y+1, visited);
    }
    if(maze[x+1][y] != '*' && visited[x+1][y] == 0) { // Down
        findRoute(maze, x+1, y, visited);
    }
    if(maze[x][y-1] != '*' && visited[x][y-1] == 0) { // Left
        findRoute(maze, x, y-1, visited);
    }
    if(maze[x-1][y] != '*' && visited[x-1][y] == 0) { // Up
        findRoute(maze, x-1, y, visited);
    }
}