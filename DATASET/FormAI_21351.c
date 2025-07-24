//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point from, to;
    double cost;
} Edge;

typedef struct {
    Point parent;
    double f, g, h;
    bool visited;
} NodeData;

typedef struct {
    NodeData nodes[MAX_ROWS][MAX_COLS];
    int rows, cols;
} Grid;

Grid createGrid(int rows, int cols) {
    Grid grid;
    grid.rows = rows;
    grid.cols = cols;
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            grid.nodes[row][col].parent.x = -1;
            grid.nodes[row][col].parent.y = -1;
            grid.nodes[row][col].f = grid.nodes[row][col].g = grid.nodes[row][col].h = 0.0;
            grid.nodes[row][col].visited = false;
        }
    }
    return grid;
}

bool isValid(Point point, Grid grid) {
    return point.x >= 0 && point.y >= 0 && point.x < grid.rows && point.y < grid.cols;
}

bool isBlocked(Point point, int weights[MAX_ROWS][MAX_COLS]) {
    return weights[point.x][point.y] == -1;
}

double calculateCost(Point from, Point to) {
    return sqrt((from.x - to.x) * (from.x - to.x) + (from.y - to.y) * (from.y - to.y));
}

void addNeighbors(Point point, Grid grid, Edge edges[], int *count, int weights[MAX_ROWS][MAX_COLS]) {
    int row = point.x, col = point.y;
    int rowOffsets[] = {-1, 0, 1, 0};
    int colOffsets[] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++) {
        Point neighbor = {row + rowOffsets[i], col + colOffsets[i]};
        if(isValid(neighbor, grid) && !isBlocked(neighbor, weights)) {
            Edge edge = {{row, col}, neighbor, calculateCost(point, neighbor)};
            edges[(*count)++] = edge;
        }
    }
}

bool compareNodes(NodeData node1, NodeData node2) {
    return node1.f < node2.f;
}

void sortEdges(Edge edges[], int count, Grid grid) {
    for(int i = 0; i < count; i++) {
        int minIndex = i;
        for(int j = i + 1; j < count; j++) {
            if(compareNodes(grid.nodes[edges[j].to.x][edges[j].to.y], grid.nodes[edges[minIndex].to.x][edges[minIndex].to.y])) {
                minIndex = j;
            }
        }
        Edge temp = edges[i];
        edges[i] = edges[minIndex];
        edges[minIndex] = temp;
    }
}

double computeHeuristic(Point current, Point goal) {
    return calculateCost(current, goal);
}

void aStar(Point start, Point goal, int weights[MAX_ROWS][MAX_COLS], Grid *grid) {
    grid->nodes[start.x][start.y].g = 0.0;
    grid->nodes[start.x][start.y].h = computeHeuristic(start, goal);
    grid->nodes[start.x][start.y].f = grid->nodes[start.x][start.y].g + grid->nodes[start.x][start.y].h;
    int edgeCount = 0;
    Edge edges[MAX_ROWS * MAX_COLS];
    addNeighbors(start, (*grid), edges, &edgeCount, weights);
    while(edgeCount) {
        sortEdges(edges, edgeCount, (*grid));
        Edge edge = edges[--edgeCount];
        if(edge.to.x == goal.x && edge.to.y == goal.y) {
            (*grid).nodes[goal.x][goal.y].parent.x = edge.from.x;
            (*grid).nodes[goal.x][goal.y].parent.y = edge.from.y;
            return;
        }
        if((*grid).nodes[edge.to.x][edge.to.y].visited) {
            continue;
        }
        (*grid).nodes[edge.to.x][edge.to.y].visited = true;
        (*grid).nodes[edge.to.x][edge.to.y].parent.x = edge.from.x;
        (*grid).nodes[edge.to.x][edge.to.y].parent.y = edge.from.y;
        (*grid).nodes[edge.to.x][edge.to.y].g = (*grid).nodes[edge.from.x][edge.from.y].g + edge.cost;
        (*grid).nodes[edge.to.x][edge.to.y].h = computeHeuristic(edge.to, goal);
        (*grid).nodes[edge.to.x][edge.to.y].f = (*grid).nodes[edge.to.x][edge.to.y].g + (*grid).nodes[edge.to.x][edge.to.y].h;
        addNeighbors(edge.to, (*grid), edges, &edgeCount, weights);
    }
}

void printPath(Point start, Point goal, Grid grid) {
    Point current = goal;
    while(current.x != start.x || current.y != start.y) {
        printf("(%d, %d) -> ", current.x, current.y);
        current = grid.nodes[current.x][current.y].parent;
    }
    printf("(%d, %d)\n", start.x, start.y);
}

void printGrid(Grid grid, Point start, Point goal) {
    for(int row = 0; row < grid.rows; row++) {
        for(int col = 0; col < grid.cols; col++) {
            if(start.x == row && start.y == col) {
                printf("S ");
                continue;
            }
            if(goal.x == row && goal.y == col) {
                printf("G ");
                continue;
            }
            printf("%d ", grid.nodes[row][col].visited ? 1 : 0);
        }
        printf("\n");
    }
}

int main() {
    int weights[MAX_ROWS][MAX_COLS] = {{1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                                       {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                                       {1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                                       {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
                                       {1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
                                       {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                                       {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                                       {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                                       {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    Point start = {0, 0};
    Point goal = {9, 9};
    Grid grid = createGrid(MAX_ROWS, MAX_COLS);
    aStar(start, goal, weights, &grid);
    printPath(start, goal, grid);
    printGrid(grid, start, goal);
    return 0;
}