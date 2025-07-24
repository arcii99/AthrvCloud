//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];
int visited[ROWS][COLS];

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point point;
    int distance;
} Node;

typedef struct {
    Node queue[ROWS*COLS];
    int front;
    int rear;
} Queue;

void init_queue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, Node node) {
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = node;
}

Node dequeue(Queue *q) {
    if (q->front > q->rear || q->front == -1) {
        Node node = {{0, 0}, -1};
        return node;
    }
    Node node = q->queue[q->front];
    q->front++;
    return node;
}

int is_empty(Queue *q) {
    return q->front > q->rear || q->front == -1;
}

void print_grid() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void print_visited() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
}

Node create_node(int x, int y, int distance) {
    Node node;
    node.point.x = x;
    node.point.y = y;
    node.distance = distance;
    return node;
}

int is_valid(Point point) {
    return point.x >= 0 && point.x < ROWS && point.y >= 0 && point.y < COLS && visited[point.x][point.y] == 0 && grid[point.x][point.y] != -1;
}

int is_destination(Point point, Point dest) {
    return point.x == dest.x && point.y == dest.y;
}

int bfs(Point src, Point dest) {
    Queue q;
    init_queue(&q);

    visited[src.x][src.y] = 1;
    Node src_node = create_node(src.x, src.y, 0);
    enqueue(&q, src_node);
    Node curr;
    while (!is_empty(&q)) {
        curr = dequeue(&q);

        Point north = {curr.point.x - 1, curr.point.y};
        Point south = {curr.point.x + 1, curr.point.y};
        Point west = {curr.point.x, curr.point.y - 1};
        Point east = {curr.point.x, curr.point.y + 1};

        if (is_destination(curr.point, dest)) {
            return curr.distance;
        }

        if (is_valid(north)) {
            visited[north.x][north.y] = 1;
            Node node = create_node(north.x, north.y, curr.distance + 1);
            enqueue(&q, node);
        }

        if (is_valid(south)) {
            visited[south.x][south.y] = 1;
            Node node = create_node(south.x, south.y, curr.distance + 1);
            enqueue(&q, node);
        }

        if (is_valid(west)) {
            visited[west.x][west.y] = 1;
            Node node = create_node(west.x, west.y, curr.distance + 1);
            enqueue(&q, node);
        }

        if (is_valid(east)) {
            visited[east.x][east.y] = 1;
            Node node = create_node(east.x, east.y, curr.distance + 1);
            enqueue(&q, node);
        }
    }
    return -1;
}

void reset_visited() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            visited[i][j] = 0;
        }
    }
}

void set_obstacle(Point point) {
    grid[point.x][point.y] = -1;
}

int main() {
    // Initialize grid to all 0s (no obstacles)
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            grid[i][j] = 0;
        }
    }

    // Set some obstacles
    set_obstacle((Point){3, 2});
    set_obstacle((Point){7, 3});
    set_obstacle((Point){5, 7});
    set_obstacle((Point){9, 9});

    // Print the grid
    printf("Grid with obstacles:\n");
    print_grid();

    Point src = {0, 0};
    Point dest = {ROWS-1, COLS-1};

    // Test BFS algorithm
    printf("Shortest distance from (%d, %d) to (%d, %d): %d\n", src.x, src.y, dest.x, dest.y, bfs(src, dest));

    // Print the visited grid after BFS
    printf("Visited grid after BFS:\n");
    print_visited();

    // Reset visited grid for next test
    reset_visited();

    // Test BFS with different source and destination points
    src = (Point){2, 3};
    dest = (Point){7, 8};
    printf("Shortest distance from (%d, %d) to (%d, %d): %d\n", src.x, src.y, dest.x, dest.y, bfs(src, dest));

    return 0;
}