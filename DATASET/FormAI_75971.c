//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HEIGHT 10
#define WIDTH 10

char maze[HEIGHT][WIDTH] = {
   {'#','#','#','#','#','#','#','#','#','#'},
   {'#','x','#','.','.','.','#','.','.','#'},
   {'#','.','#','.','#','.','#','#','.','#'},
   {'#','.','.','.','#','.','.','.','.','#'},
   {'#','#','#','.','.','.','.','#','#','#'},
   {'#','.','.','#','#','.','.','#','.','#'},
   {'#','.','#','.','.','#','.','#','.','#'},
   {'#','.','.','.','#','.','.','.','.','#'},
   {'#','#','.','#','.','.','#','#','.','#'},
   {'#','#','#','#','#','#','#','#','#','#'},
};

typedef struct node_t {
  int x, y;
  struct node_t* parent;
} node_t;

node_t* start_node;
node_t* end_node;

/**
 * Function to initialize the start and end nodes.
 */
void initialize() {
  start_node = (node_t*) malloc(sizeof(node_t));
  end_node = (node_t*) malloc(sizeof(node_t));

  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      if (maze[i][j] == 'x') {
        start_node->x = i;
        start_node->y = j;
        start_node->parent = NULL;
      } else if (maze[i][j] == '.') {
        end_node->x = i;
        end_node->y = j;
      }
    }
  }
}

/**
 * Function to check if a given position is valid to move to.
 * Returns true if position is valid, false otherwise.
 */
bool isValid(int x, int y) {
  if (x < 0 || y < 0 || x >= HEIGHT || y >= WIDTH) {
    return false;
  }

  if (maze[x][y] == '#' || maze[x][y] == 'v') {
    return false;
  }

  return true;
}

/**
 * Function to print the path from start to end.
 */
void printPath(node_t* node) {
  while (node != NULL) {
    printf("(%d, %d)\n", node->x, node->y);
    node = node->parent;
  }
}

/**
 * Function to find the shortest path using BFS algorithm.
 */
void findShortestPath() {
  int queue_size = HEIGHT * WIDTH;
  node_t* queue[queue_size];
  int front = 0;
  int rear = 1;

  // Add start node to queue.
  queue[front] = start_node;
  queue[front]->parent = NULL;

  // Loop until queue is empty.
  while (front < rear) {
    // Remove node from queue.
    node_t* current_node = queue[front++];
    int x = current_node->x;
    int y = current_node->y;

    // We have reached the end node!
    if (x == end_node->x && y == end_node->y) {
      printPath(current_node);
      return;
    }

    // Mark current node as visited.
    maze[x][y] = 'v';

    // Generate next possible nodes.
    if (isValid(x-1, y)) {
      queue[rear] = (node_t*) malloc(sizeof(node_t));
      queue[rear]->x = x-1;
      queue[rear]->y = y;
      queue[rear]->parent = current_node;
      rear++;
    }

    if (isValid(x+1, y)) {
      queue[rear] = (node_t*) malloc(sizeof(node_t));
      queue[rear]->x = x+1;
      queue[rear]->y = y;
      queue[rear]->parent = current_node;
      rear++;
    }

    if (isValid(x, y-1)) {
      queue[rear] = (node_t*) malloc(sizeof(node_t));
      queue[rear]->x = x;
      queue[rear]->y = y-1;
      queue[rear]->parent = current_node;
      rear++;
    }

    if (isValid(x, y+1)) {
      queue[rear] = (node_t*) malloc(sizeof(node_t));
      queue[rear]->x = x;
      queue[rear]->y = y+1;
      queue[rear]->parent = current_node;
      rear++;
    }
  }

  printf("No path found!\n");
}

int main() {
  initialize();
  findShortestPath();
  return 0;
}