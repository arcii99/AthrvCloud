//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 10  // assuming the map size is 10x10
#define MAX_QUEUE_SIZE 1000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point point;
    int g_cost;
    int f_cost;
} Node;

typedef struct {
    Node nodes[MAX_QUEUE_SIZE];
    int size;
} PriorityQueue;

typedef struct {
    int map[MAP_SIZE][MAP_SIZE];
    char symbol[MAP_SIZE][MAP_SIZE]; // for visualization purpose
    Point start;
    Point goal;
} Map;

void initMap(Map* map) {
    memset(map->map, 0, sizeof(map->map));
    memset(map->symbol, '-', sizeof(map->symbol));
    map->start.x = 0;
    map->start.y = 0;
    map->goal.x = MAP_SIZE - 1;
    map->goal.y = MAP_SIZE - 1;
}

void printMap(Map* map) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%c ", map->symbol[i][j]);
        }
        printf("\n");
    }
}

int heuristicCost(Point current, Point goal) {
    // assuming the heuristic cost is Euclidean distance
    return ((current.x - goal.x) * (current.x - goal.x) + 
            (current.y - goal.y) * (current.y - goal.y));
}

void enqueue(PriorityQueue* queue, Node node) {
    int i = queue->size - 1;
    while (i >= 0 && queue->nodes[i].f_cost > node.f_cost) {
        queue->nodes[i + 1] = queue->nodes[i];
        i--;
    }
    queue->nodes[i + 1] = node;
    queue->size++;
}

void dequeue(PriorityQueue* queue) {
    if (queue->size > 0) {
        queue->size--;
    }
}

Node front(PriorityQueue* queue) {
    return queue->nodes[queue->size - 1];
}

int isEmpty(PriorityQueue* queue) {
    return queue->size == 0;
}

void markPath(Map* map, Point current, Point* parent) {
    while (current.x != map->start.x || current.y != map->start.y) {
        map->symbol[current.x][current.y] = 'X';
        current = parent[current.x * MAP_SIZE + current.y];
    }
    map->symbol[map->start.x][map->start.y] = 'S';
    map->symbol[map->goal.x][map->goal.y] = 'G';
}

void AStar(Map* map) {
    int visited[MAP_SIZE][MAP_SIZE] = { 0 };
    Point parent[MAP_SIZE * MAP_SIZE];
    memset(parent, -1, sizeof(parent));
    PriorityQueue queue = { .size = 0 };
    Node currentNode = { .point = map->start, .g_cost = 0, .f_cost = heuristicCost(map->start, map->goal) };
    enqueue(&queue, currentNode);
    while (!isEmpty(&queue)) {
        currentNode = front(&queue);
        dequeue(&queue);
        if (visited[currentNode.point.x][currentNode.point.y]) {
            continue;
        }
        visited[currentNode.point.x][currentNode.point.y] = 1;
        parent[currentNode.point.x * MAP_SIZE + currentNode.point.y] = 
            (Point) { currentNode.point.x, currentNode.point.y };
        if (currentNode.point.x == map->goal.x && currentNode.point.y == map->goal.y) {
            markPath(map, currentNode.point, parent);
            return;
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                Point neighbor = { currentNode.point.x + i, currentNode.point.y + j };
                if (neighbor.x < 0 || neighbor.x >= MAP_SIZE || 
                    neighbor.y < 0 || neighbor.y >= MAP_SIZE ||
                    visited[neighbor.x][neighbor.y] ||
                    map->map[neighbor.x][neighbor.y]) {
                    continue;
                }
                Node neighborNode = {
                    .point = neighbor,
                    .g_cost = currentNode.g_cost + 1,
                    .f_cost = currentNode.g_cost + 1 + heuristicCost(neighbor, map->goal)
                };
                enqueue(&queue, neighborNode);
            }
        }
    }
}

int main() {
    Map map;
    initMap(&map);
    map.map[1][0] = 1;
    map.map[1][1] = 1;
    map.map[2][1] = 1;
    map.map[3][1] = 1;
    map.map[3][2] = 1;
    map.map[3][3] = 1;
    map.map[1][4] = 1;
    map.map[2][4] = 1;
    map.map[2][5] = 1;
    map.map[2][6] = 1;
    map.map[2][7] = 1;
    map.map[3][7] = 1;
    map.map[3][8] = 1;
    map.map[4][8] = 1;
    map.map[5][8] = 1;
    map.map[5][7] = 1;
    map.map[6][7] = 1;
    map.map[7][7] = 1;
    map.map[7][6] = 1;
    map.map[7][5] = 1;
    map.map[7][4] = 1;
    map.map[7][3] = 1;
    map.map[6][3] = 1;
    map.map[5][3] = 1;
    map.map[5][2] = 1;
    map.map[5][1] = 1;
    map.map[6][1] = 1;
    AStar(&map);
    printMap(&map);
    return 0;
}