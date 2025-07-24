//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 7
#define COLS 7

// Define the maze.
char maze[ROWS][COLS] = {
  {'#', '#', '#', '#', '#', '#', '#'},
  {'#', '.', '.', '.', '#', '.', '#'},
  { '.', '.', '#', '.', '#', '.', '#'},
  { '.', '#', '.', '.', '#', '.', '#'},
  { '.', '#', '#', '.', '.', '.', '#'},
  { '.', '.', '.', '#', '#', '.', '#'},
  {'#', '#', '#', '#', '#', '#', '#'}
};

// Define the start and end points.
int start_row = 1, start_col = 1;
int end_row = 5, end_col = 5;

// Define a struct for each point in the maze.
typedef struct {
  int row;
  int col;
} Point;

// Define a struct for the node in the queue.
typedef struct {
  Point point;
  int parent_index;
} Node;

// Define the queue.
Node queue[ROWS*COLS];
int front = 0;
int back = 0;

// Add a point to the queue.
void enqueue(Point point, int parent_index) {
  queue[back].point = point;
  queue[back].parent_index = parent_index;
  back++;
}

// Remove the next point from the queue.
Node dequeue() {
  Node node = queue[front];
  front++;
  return node;
}

// Check if a point is valid (not outside the maze and not a wall).
bool is_valid(Point point) {
  if (point.row < 0 || point.row >= ROWS ||
      point.col < 0 || point.col >= COLS ||
      maze[point.row][point.col] == '#') {
    return false;
  } else {
    return true;
  }
}

// Find the shortest route from the start to the end.
void find_route() {
  Point start_point = {start_row, start_col};
  enqueue(start_point, -1);

  while (front != back) {
    Node node = dequeue();
    Point point = node.point;
    int parent_index = node.parent_index;

    if (point.row == end_row && point.col == end_col) {
      // Found the end point. Print the route.
      printf("Shortest route length: %d\n", parent_index+1);
      int index = parent_index;
      int route[ROWS*COLS];
      while (index != -1) {
        route[index] = parent_index - index;
        node = queue[index];
        index = node.parent_index;
      }
      printf("Shortest route: ");
      for (int i = parent_index; i >= 0; i--) {
        printf("%d ", route[i]);
      }
      printf("\n");
      return;
    }

    // Try the four possible moves from the current point.
    Point move_point;
    move_point.row = point.row - 1;
    move_point.col = point.col;
    if (is_valid(move_point)) {
      enqueue(move_point, front-1);
      maze[move_point.row][move_point.col] = '#';
    }
    move_point.row = point.row;
    move_point.col = point.col + 1;
    if (is_valid(move_point)) {
      enqueue(move_point, front-1);
      maze[move_point.row][move_point.col] = '#';
    }
    move_point.row = point.row + 1;
    move_point.col = point.col;
    if (is_valid(move_point)) {
      enqueue(move_point, front-1);
      maze[move_point.row][move_point.col] = '#';
    }
    move_point.row = point.row;
    move_point.col = point.col - 1;
    if (is_valid(move_point)) {
      enqueue(move_point, front-1);
      maze[move_point.row][move_point.col] = '#';
    }
  }

  // No route found.
  printf("No route found.\n");
}

// Main function.
int main() {
  find_route();
  return 0;
}