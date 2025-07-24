//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: unmistakable
#include <stdio.h>

#define ROW 6
#define COL 6

char maze[ROW][COL] = {
    {'#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', ' ', '#', '#'},
    {'#', '#', '#', '#', '#', '#'}
};  

struct Point {
    int x;
    int y;
};

void printMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int x, int y) {
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] != '#') {
        return 1;
    }
    return 0;
}

int findRoute(int x, int y, struct Point* path) {
    if (x < 0 || x >= ROW || y < 0 || y >= COL) {
        return 0;
    }

    if (maze[x][y] == 'E') {
        path->x = x;
        path->y = y;
        return 1;
    }

    if (isSafe(x, y) == 0) {
        return 0;
    }

    maze[x][y] = '#';

    if (findRoute(x-1, y, path) == 1) {
        path++;
        path->x = x;
        path->y = y;
        return 1;
    }

    if (findRoute(x+1, y, path) == 1) {
        path++;
        path->x = x;
        path->y = y;
        return 1;
    }

    if (findRoute(x, y-1, path) == 1) {
        path++;
        path->x = x;
        path->y = y;
        return 1;
    }

    if (findRoute(x, y+1, path) == 1) {
        path++;
        path->x = x;
        path->y = y;
        return 1;
    }

    return 0;
}

int main() {
    struct Point path[ROW*COL];
    int start_x = 1;
    int start_y = 1;

    maze[start_x][start_y] = '#';

    int found = findRoute(start_x, start_y, path);

    if (found == 1) {
        printMaze();
        printf("\nRoute: ");
        for (int i = ROW*COL-1; i >= 0; i--) {
            printf("(%d,%d) ", path[i].x, path[i].y);
        }
        printf("\n");
    } else {
        printf("No route found.\n");
    }

    return 0;
}