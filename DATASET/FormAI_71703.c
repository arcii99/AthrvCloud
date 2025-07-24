//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

typedef enum {
  EMPTY,
  OBSTACLE,
  START,
  DESTINATION
} NodeType;

typedef struct {
  int x, y;
} Node;

typedef struct NodeQueue {
  Node data;
  struct NodeQueue* next;
} NodeQueue;

void enqueue(NodeQueue** queue, Node node) {
  NodeQueue* newNode = (NodeQueue*) malloc(sizeof(NodeQueue));
  newNode->data = node;
  newNode->next = NULL;

  if (*queue == NULL) {
    *queue = newNode;
    return;
  }
  NodeQueue* iter = *queue;
  while (iter->next != NULL) {
    iter = iter->next;
  }
  iter->next = newNode;
}

Node dequeue(NodeQueue** queue) {
  if (*queue == NULL) {
    fprintf(stderr, "Error: Queue is empty\n");
    exit(-1);
  }
  NodeQueue* node = *queue;
  Node data = node->data;
  *queue = node->next;

  free(node);
  return data;
}

bool is_empty(NodeQueue* queue) {
  return queue == NULL;
}

bool is_valid_node(int x, int y, int map[ROWS][COLUMNS]) {
  if (x < 0 || y < 0 || x >= ROWS || y >= COLUMNS) {
    return false;
  }
  return map[x][y] != OBSTACLE;
}

int manhattan_distance(Node a, Node b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

void add_adjacent_nodes(Node node, Node destination, int gScore[ROWS][COLUMNS], int fScore[ROWS][COLUMNS], int map[ROWS][COLUMNS], NodeQueue** openSet, Node cameFrom[ROWS][COLUMNS]) {
  int x = node.x;
  int y = node.y;
  int tentative_gScore = gScore[x][y] + 1;
  for (int xx = -1; xx < 2; xx++) {
    for (int yy = -1; yy < 2; yy++) {
      int new_x = x + xx;
      int new_y = y + yy;
      if (xx == 0 && yy == 0) {
        continue;
      }
      if (!is_valid_node(new_x, new_y, map)) {
        continue;
      }
      int tentative_fScore = tentative_gScore + manhattan_distance((Node) {new_x, new_y}, destination);
      if (tentative_fScore < fScore[new_x][new_y]) {
        cameFrom[new_x][new_y] = node;
        gScore[new_x][new_y] = tentative_gScore;
        fScore[new_x][new_y] = tentative_fScore;
        enqueue(openSet, (Node) {new_x, new_y});
      }
    }
  }
}

void reconstruct_path(Node cameFrom[ROWS][COLUMNS], Node current) {
  if (cameFrom[current.x][current.y].x != -1 && cameFrom[current.x][current.y].y != -1) {
    reconstruct_path(cameFrom, cameFrom[current.x][current.y]);
  }
  printf("-> (%d,%d)", current.x, current.y);
}

void a_star(int map[ROWS][COLUMNS], Node start, Node destination) {
  Node cameFrom[ROWS][COLUMNS];
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      cameFrom[i][j] = (Node) {-1, -1};
    }
  }

  int gScore[ROWS][COLUMNS];
  int fScore[ROWS][COLUMNS];
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      gScore[i][j] = 0xffff;
      fScore[i][j] = 0xffff;
    }
  }

  gScore[start.x][start.y] = 0;
  fScore[start.x][start.y] = manhattan_distance(start, destination);

  NodeQueue* openSet = NULL;
  enqueue(&openSet, start);

  while (!is_empty(openSet)) {
    Node current = dequeue(&openSet);
    if (current.x == destination.x && current.y == destination.y) {
      reconstruct_path(cameFrom, current);
      return;
    }

    add_adjacent_nodes(current, destination, gScore, fScore, map, &openSet, cameFrom);
  }

  printf("No path found\n");
}

int main() {
  int map[ROWS][COLUMNS] = {
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
  };

  Node start = {1, 1};
  Node destination = {ROWS - 2, COLUMNS - 2};

  printf("Finding path from (%d,%d) to (%d,%d):\n", start.x, start.y, destination.x, destination.y);
  a_star(map, start, destination);

  return 0;
}