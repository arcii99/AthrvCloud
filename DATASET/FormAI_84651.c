//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int map[ROW][COL] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,0,1,1,1,0},
    {0,0,0,0,0,0,1,0,1,0},
    {0,1,1,1,1,1,1,0,1,0},
    {0,1,0,0,0,1,1,0,1,0},
    {0,1,1,1,0,0,0,0,1,0},
    {0,0,0,1,0,1,1,1,1,0},
    {0,1,0,0,0,1,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0},
};

struct Point {
  int x;
  int y;
};

void print_map() {
  printf("\nMap:\n");
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      printf("%d ", map[i][j]);
    }
    printf("\n");
  }
}

int is_valid(int x, int y) {
  if (x < 0 || x >= ROW) return 0;
  if (y < 0 || y >= COL) return 0;
  if (map[x][y] == 0) return 0;
  return 1;
}

int is_dest(int x, int y, struct Point dest) {
  if (x == dest.x && y == dest.y) return 1;
  return 0;
}

struct Node {
  struct Point point;
  struct Node* parent;
};

void print_path(struct Node* node) {
  if (node == NULL) return;
  print_path(node->parent);
  printf("(%d, %d)\n", node->point.x, node->point.y);
}

void bfs(struct Point start, struct Point dest) {
  struct Node* queue = (struct Node*) malloc(sizeof(struct Node));
  queue->point = start;
  queue->parent = NULL;
  int front = 0;
  int rear = 1;
  int size = 1;
  while (front < rear) {
    struct Node curr = queue[front];
    front++;
    if (is_dest(curr.point.x, curr.point.y, dest)) {
      printf("Shortest Path:\n");
      print_path(&curr);
      return;
    }
    struct Point moves[4] = {
      {curr.point.x - 1, curr.point.y},
      {curr.point.x, curr.point.y + 1},
      {curr.point.x + 1, curr.point.y},
      {curr.point.x, curr.point.y - 1}
    };
    for (int i = 0; i < 4; i++) {
      int x = moves[i].x;
      int y = moves[i].y;
      if (is_valid(x, y)) {
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        node->point.x = x;
        node->point.y = y;
        node->parent = &curr;
        queue = (struct Node*) realloc(queue, sizeof(struct Node) * (++size));
        queue[rear] = *node;
        rear++;
      }
    }
  }
  printf("No Path Found!\n");
}

int main() {
  print_map();
  printf("\nSearching...\n");
  struct Point start = {1, 1};
  struct Point dest = {8, 8};
  bfs(start, dest);
  return 0;
}