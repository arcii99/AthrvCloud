//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define rows 10
#define cols 10

typedef struct {
    int x;
    int y;
} point;

point path[rows*cols];

int visited[rows][cols];
int obstacles[rows][cols] = {{0,1,0,0,0,0,1,0,0,0},
                             {0,0,0,1,0,0,0,0,0,0},
                             {0,1,0,0,1,0,1,0,0,0},
                             {1,0,0,0,1,0,0,0,0,0},
                             {0,0,1,0,0,0,1,0,0,0},
                             {0,0,0,0,1,1,0,0,1,0},
                             {0,0,0,0,0,0,0,1,0,0},
                             {1,0,1,0,0,1,0,0,0,1},
                             {0,1,0,0,0,0,0,0,0,0},
                             {0,0,0,1,0,0,1,0,1,0}};

void printObstacles() {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            printf("%d ", obstacles[i][j]);
        }
        printf("\n");
    }
}

int isObstacle(int x, int y) {
    return obstacles[x][y] == 1;
}

int isOutOfBounds(int x, int y) {
    return x > rows-1 || y > cols-1 || x < 0 || y < 0;
}

int isValid(int x, int y) {
    return !isOutOfBounds(x,y) && !isObstacle(x,y) && !visited[x][y];
}

int dfs(int x, int y, int step) {
    if (isOutOfBounds(x,y) || isObstacle(x,y) || visited[x][y]) {
        return 0;
    }

    visited[x][y] = 1;
    path[step].x = x;
    path[step].y = y;

    if (x == rows-1 && y == cols-1) {
        return 1;
    }

    if(isValid(x+1, y)) {
        if(dfs(x+1, y, step+1)) {
            return 1;
        }
    }

    if(isValid(x, y+1)) {
        if(dfs(x, y+1, step+1)) {
            return 1;
        }
    }

    if(isValid(x-1, y)) {
        if(dfs(x-1, y, step+1)) {
            return 1;
        }
    }

    if(isValid(x, y-1)) {
        if(dfs(x, y-1, step+1)) {
            return 1;
        }
    }

    visited[x][y] = 0;
    return 0;
}

void printPath(int steps) {
    printf("Path taken: ");

    for (int i=0; i<steps; i++) {
        printf("(%d,%d)", path[i].x, path[i].y);
        if (i != steps-1) {
            printf(" -> ");
        }
    }

    printf("\n");
}

int main()
{
    printf("Welcome to the Pathfinding Algorithm\n\n");
    printf("Here is the obstacles array: \n");
    printObstacles();

    int start_x, start_y;
    printf("Enter the starting point (x,y): ");
    scanf("%d,%d", &start_x, &start_y);

    int steps = dfs(start_x, start_y, 0);
    printf("\n");

    printf("The result of the algorithm: \n");
    if (steps == 0) {
        printf("No path found\n");
    } else {
        printf("Path found in %d steps\n", steps);
        printPath(steps);
    }

    return 0;
}