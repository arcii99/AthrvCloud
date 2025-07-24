//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROW 10
#define COLUMN 10

typedef struct {
    int x, y, steps;
} Node;

int maze[ROW][COLUMN] = {
    {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
    {1, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0}
};

bool visited[ROW][COLUMN] = {false};

Node queue[ROW * COLUMN];
int front = -1, rear = -1;

Node start = {0, 0, 0};
Node end = {0, 0, 0};

bool is_valid(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < ROW) && (y < COLUMN);
}

bool is_obstacle(int x, int y) {
    return (maze[x][y] == 1);
}

bool is_visited(int x, int y) {
    return visited[x][y];
}

void enqueue(Node p) {
    if (front == -1) front = 0;
    rear++;
    queue[rear] = p;
}

Node dequeue() {
    Node tmp = queue[front];
    front++;
    return tmp;
}

void breadth_first_search() {
    visited[start.x][start.y] = true;
    enqueue(start);

    while (front <= rear) {
        Node current = dequeue();

        if (current.x == end.x && current.y == end.y) {
            printf("Path found - %d steps\n", current.steps);
            return;
        }

        if (is_valid(current.x-1, current.y) && !is_obstacle(current.x-1, current.y) && !is_visited(current.x-1, current.y)) {
            visited[current.x-1][current.y] = true;
            Node p = {current.x-1, current.y, current.steps+1};
            enqueue(p);
        }

        if (is_valid(current.x+1, current.y) && !is_obstacle(current.x+1, current.y) && !is_visited(current.x+1, current.y)) {
            visited[current.x+1][current.y] = true;
            Node p = {current.x+1, current.y, current.steps+1};
            enqueue(p);
        }

        if (is_valid(current.x, current.y-1) && !is_obstacle(current.x, current.y-1) && !is_visited(current.x, current.y-1)) {
            visited[current.x][current.y-1] = true;
            Node p = {current.x, current.y-1, current.steps+1};
            enqueue(p);
        }

        if (is_valid(current.x, current.y+1) && !is_obstacle(current.x, current.y+1) && !is_visited(current.x, current.y+1)) {
            visited[current.x][current.y+1] = true;
            Node p = {current.x, current.y+1, current.steps+1};
            enqueue(p);
        }
    }

    printf("Path not found\n");
}

int main() {
    start.steps = 0;
    start.x = 0;
    start.y = 0;

    end.x = ROW - 1;
    end.y = COLUMN - 1;

    breadth_first_search();

    return 0;
}