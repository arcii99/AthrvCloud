//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

#define WALL 1
#define PATH 0

struct Node {
    int x, y;
    struct Node* parent;
};

void printGrid(int grid[][COL], int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int isValid(int x, int y, int grid[][COL], int visited[][COL]) {
    if(x >= 0 && x < ROW && y >= 0 && y < COL && !visited[x][y] && grid[x][y] != WALL) {
        return 1;
    }
    return 0;
}

void getPath(struct Node* node, int grid[][COL]) {
    if(node == NULL) return;

    getPath(node->parent, grid);
    grid[node->x][node->y] = PATH;
}

void BFS(int grid[][COL], int startX, int startY, int endX, int endY) {
    if(grid[startX][startY] == WALL || grid[endX][endY] == WALL) {
        return;
    }

    int visited[ROW][COL] = {0};

    int distance[ROW][COL];
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            distance[i][j] = -1;
        }
    }

    struct Node* queue[ROW*COL];
    int front = -1;
    int rear = -1;

    struct Node* start = (struct Node*) malloc(sizeof(struct Node));
    start->x = startX;
    start->y = startY;
    start->parent = NULL;
    queue[++rear] = start;
    visited[startX][startY] = 1;
    distance[startX][startY] = 0;

    while(front != rear) {
        struct Node* current = queue[++front];

        if(current->x == endX && current->y == endY) {
            printf("Shortest path distance: %d\n", distance[endX][endY]);

            getPath(current, grid);
            printf("Shortest path:\n");
            printGrid(grid, ROW, COL);

            return;
        }

        // Check all 8 possible moves from current position (up, down, left, right, diagonal)
        int moveX[] = {-1, 0, 1, 0, -1, -1, 1, 1};
        int moveY[] = {0, 1, 0, -1, -1, 1, -1, 1};

        for(int i=0; i<8; i++) {
            int newX = current->x + moveX[i];
            int newY = current->y + moveY[i];

            if(isValid(newX, newY, grid, visited)) {
                visited[newX][newY] = 1;

                struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
                newNode->x = newX;
                newNode->y = newY;
                newNode->parent = current;

                queue[++rear] = newNode;

                distance[newX][newY] = distance[current->x][current->y] + 1;
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    int grid[ROW][COL] = {{0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                          {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}};
    printf("Input grid:\n");
    printGrid(grid, ROW, COL);

    BFS(grid, 0, 0, 9, 9);
}