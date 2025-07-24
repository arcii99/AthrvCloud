//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: lively
#include <stdio.h>
#include <stdbool.h>

#define ROW 15
#define COL 15

int grid[ROW][COL] = {
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int startX = 0;
int startY = 0;
int endX = 14;
int endY = 14;

int parent[ROW][COL] = {-1};
bool visited[ROW][COL] = {false};

bool isValid(int x, int y) {
    return x >= 0 && x < ROW && y >= 0 && y < COL && !visited[x][y] && grid[x][y] == 0;
}

void printPath() {
    int currentX = endX;
    int currentY = endY;
    while (currentX != startX || currentY != startY) {
        printf("(%d, %d) -> ", currentX, currentY);
        int tempX = currentX;
        currentX = parent[currentX][currentY] / 15;
        currentY = parent[tempX][currentY] % 15;
    }
    printf("(%d, %d)\n", startX, startY);
}

void BFS() {
    int queue[ROW * COL];
    int front = -1;
    int rear = -1;
    queue[++rear] = startX * 15 + startY;
    visited[startX][startY] = true;
    while (front != rear) {
        int current = queue[++front];
        int x = current / 15;
        int y = current % 15;
        if (x == endX && y == endY) {
            printPath();
            printf("Path Length: %d\n", parent[x][y]);
            return;
        }
        if (isValid(x, y + 1)) {
            queue[++rear] = x * 15 + (y + 1);
            visited[x][y+1] = true;
            parent[x][y+1] = current;
        }
        if (isValid(x, y - 1)) {
            queue[++rear] = x * 15 + (y - 1);
            visited[x][y-1] = true;
            parent[x][y-1] = current;
        }
        if (isValid(x + 1, y)) {
            queue[++rear] = (x + 1) * 15 + y;
            visited[x+1][y] = true;
            parent[x+1][y] = current;
        }
        if (isValid(x - 1, y)) {
            queue[++rear] = (x - 1) * 15 + y;
            visited[x-1][y] = true;
            parent[x-1][y] = current;
        }
    }
    printf("No path found.\n");
}

int main() {
    printf("~~~ Welcome to the Pathfinding Algorithm! ~~~\n\n");
    printf("Start Position: (%d, %d)\n", startX, startY);
    printf("End Position: (%d, %d)\n\n", endX, endY);
    printf("The Grid:\n");
    for (int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    BFS();
    return 0;
}