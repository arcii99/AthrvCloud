//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include <stdio.h>

#define ROW_SIZE 6
#define COL_SIZE 6

char grid[ROW_SIZE][COL_SIZE] = {
    {'#', '#', '#', '#', '#', '#'},
    {'#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', '#'},
    {'#', '#', '#', '#', '#', '#'},
};

typedef struct {
  int x, y;
} Point;

Point start = {1, 1};
Point end = {4, 5};
Point stack[ROW_SIZE * COL_SIZE];

int top = 0;

void push(Point p) {
  stack[top++] = p;
}

Point pop() {
  return stack[--top];
}

int is_empty() {
  return top == 0;
}

Point peek() {
  return stack[top - 1];
}

void print_stack() {
  for (int i = 0; i < top; i++) {
    printf("(%d,%d) ", stack[i].x, stack[i].y);
  }
  printf("\n");
}

void print_grid() {
  for (int i = 0; i < ROW_SIZE; i++) {
    for (int j = 0; j < COL_SIZE; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }
}

int is_valid_move(Point current, Point next) {
  if (next.x < 0 || next.x >= ROW_SIZE) return 0;
  if (next.y < 0 || next.y >= COL_SIZE) return 0;
  if (grid[next.x][next.y] == '#') return 0;
  // check if next is not already in stack
  for (int i = 0; i < top; i++) {
    if (stack[i].x == next.x && stack[i].y == next.y) {
      return 0;
    }
  }
  return 1;
}

void find_path() {
  push(start);
  while (!is_empty()) {
    Point current = pop();
    if (current.x == end.x && current.y == end.y) {
      printf("Found path: ");
      print_stack();
      return;
    }
    Point moves[4] = {
      {current.x - 1, current.y},
      {current.x + 1, current.y},
      {current.x, current.y - 1},
      {current.x, current.y + 1},
    };
    for (int i = 0; i < 4; i++) {
      Point next = moves[i];
      if (is_valid_move(current, next)) {
        push(next);
      }
    }
  }
  printf("No path found\n");
}

int main() {
  printf("Maze:\n");
  print_grid();
  find_path();
  return 0;
}