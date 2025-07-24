//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point parent;
    int f, g, h;
} Node;

Point start = {0, 0};
Point target = {9, 9};

Node nodes[WIDTH][HEIGHT];

Point GetLowestF() {
    int lowestF = 10000;
    Point lowestPoint = {-1, -1};

    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            Node *node = &nodes[i][j];

            if(node->f < lowestF && node->f != -1) {
                lowestF = node->f;
                lowestPoint = (Point){i, j};
            }
        }
    }

    return lowestPoint;
}

void UpdateNeighbours(Node *current) {
    int x = current->parent.x;
    int y = current->parent.y;
    int gScore = current->g + 1;

    // North
    if(y > 0 && nodes[x][y-1].f != -1) {
        Node *node = &nodes[x][y-1];

        if(gScore < node->g) {
            node->g = gScore;
            node->h = abs(target.x - x) + abs(target.y - (y-1));
            node->f = node->g + node->h;
            node->parent = (Point){x, y};
        }
    }

    // South
    if(y < HEIGHT - 1 && nodes[x][y+1].f != -1) {
        Node *node = &nodes[x][y+1];

        if(gScore < node->g) {
            node->g = gScore;
            node->h = abs(target.x - x) + abs(target.y - (y+1));
            node->f = node->g + node->h;
            node->parent = (Point){x, y};
        }
    }

    // West
    if(x > 0 && nodes[x-1][y].f != -1) {
        Node *node = &nodes[x-1][y];

        if(gScore < node->g) {
            node->g = gScore;
            node->h = abs(target.x - (x-1)) + abs(target.y - y);
            node->f = node->g + node->h;
            node->parent = (Point){x, y};
        }
    }

    // East
    if(x < WIDTH - 1 && nodes[x+1][y].f != -1) {
        Node *node = &nodes[x+1][y];

        if(gScore < node->g) {
            node->g = gScore;
            node->h = abs(target.x - (x+1)) + abs(target.y - y);
            node->f = node->g + node->h;
            node->parent = (Point){x, y};
        }
    }
}

int main(void) {
    // Init the nodes
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            nodes[i][j].parent = (Point){-1, -1};
            nodes[i][j].f = -1;
            nodes[i][j].g = -1;
            nodes[i][j].h = -1;
        }
    }

    // Set starting point
    nodes[start.x][start.y].f = 0;
    nodes[start.x][start.y].g = 0;
    nodes[start.x][start.y].h = abs(target.x - start.x) + abs(target.y - start.y);

    // Find path
    Point current = GetLowestF();
    while(current.x != -1 && current.y != -1 && current.x != target.x && current.y != target.y) {
        UpdateNeighbours(&nodes[current.x][current.y]);
        current = GetLowestF();
    }

    // Print out path
    Point path[WIDTH * HEIGHT];
    Point point = target;
    int pathIndex = 0;

    printf("Path:\n");
    while(point.x != start.x || point.y != start.y) {
        path[pathIndex++] = point;
        point = nodes[point.x][point.y].parent;
    }
    path[pathIndex++] = point;

    for(int i = pathIndex - 1; i >= 0; i--) {
        printf("(%d, %d)\n", path[i].x, path[i].y);
    }

    return 0;
}