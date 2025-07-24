//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

typedef struct {
    int row, col;
} Node;

typedef struct {
    int f, g, h;
    Node parent;
} Cell;

void printPath(Node path[], int len) {
    for (int i = len - 1; i >= 0; i--) {
        printf("(%d, %d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

void aStar(int grid[][COL], Node start, Node end) {
    Cell cells[ROW][COL];
    
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cells[i][j].f = 0;
            cells[i][j].g = 0;
            cells[i][j].h = 0;
            cells[i][j].parent.row = -1;
            cells[i][j].parent.col = -1;
        }
    }
    
    const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
    const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
    
    Node openList[ROW * COL];
    int front = 0;
    int rear = 0;
    openList[rear++] = start;
    
    cells[start.row][start.col].f = 0;
    cells[start.row][start.col].g = 0;
    cells[start.row][start.col].h = 0;
    cells[start.row][start.col].parent.row = start.row;
    cells[start.row][start.col].parent.col = start.col;
    
    bool found = false;
    while (front != rear) {
        Node current = openList[front++];
        if (current.row == end.row && current.col == end.col) {
            printf("Path found: ");
            found = true;
            break;
        }
        for (int i = 0; i < 8; i++) {
            int x = current.row + dx[i];
            int y = current.col + dy[i];
            if (x >= 0 && x < ROW && y >= 0 && y < COL && grid[x][y] != 1) {
                int gNew = cells[current.row][current.col].g + 1;
                int hNew = abs(x - end.row) + abs(y - end.col);
                int fNew = gNew + hNew;
                if (cells[x][y].f == 0 || cells[x][y].f > fNew) {
                    openList[rear++] = (Node) {x, y};
                    cells[x][y].f = fNew;
                    cells[x][y].g = gNew;
                    cells[x][y].h = hNew;
                    cells[x][y].parent.row = current.row;
                    cells[x][y].parent.col = current.col;
                }
            }
        }
    }
    
    if (!found) {
        printf("Failed to find path\n");
        return;
    }
    
    Node path[ROW * COL];
    int len = 0;
    Node curr = end;    
    while (curr.row != start.row || curr.col != start.col) {
        path[len++] = curr;
        curr = cells[curr.row][curr.col].parent;
    }
    path[len++] = start;
    
    printPath(path, len);
}

int main() {
    int grid[ROW][COL] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
    };
    Node start = {0, 0};
    Node end = {4, 4};
    aStar(grid, start, end);
    return 0;
}