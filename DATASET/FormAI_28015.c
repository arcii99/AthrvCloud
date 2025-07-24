//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

#define CELL_VISITED 0x01
#define CELL_TOP_WALL 0x02
#define CELL_BOTTOM_WALL 0x04
#define CELL_LEFT_WALL 0x08
#define CELL_RIGHT_WALL 0x10

typedef struct {
  int x, y;
} Point;

void init_maze(unsigned char maze[HEIGHT][WIDTH]) {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    for (j = 0; j < WIDTH; j++) {
      maze[i][j] = CELL_TOP_WALL | CELL_BOTTOM_WALL | CELL_LEFT_WALL | CELL_RIGHT_WALL;
    }
  }
}

void remove_wall(unsigned char maze[HEIGHT][WIDTH], Point a, Point b) {
  if (a.x == b.x) {
    if (a.y > b.y) {
      maze[a.y][a.x] &= ~CELL_TOP_WALL;
      maze[b.y][b.x] &= ~CELL_BOTTOM_WALL;
    } else {
      maze[a.y][a.x] &= ~CELL_BOTTOM_WALL;
      maze[b.y][b.x] &= ~CELL_TOP_WALL;
    }
  } else if (a.y == b.y) {
    if (a.x < b.x) {
      maze[a.y][a.x] &= ~CELL_RIGHT_WALL;
      maze[b.y][b.x] &= ~CELL_LEFT_WALL;
    } else {
      maze[a.y][a.x] &= ~CELL_LEFT_WALL;
      maze[b.y][b.x] &= ~CELL_RIGHT_WALL;
    }
  }
}

Point random_unvisited_neighbour(unsigned char maze[HEIGHT][WIDTH], Point p) {
  Point neighbours[4] = {
    {p.x, p.y - 1},
    {p.x, p.y + 1},
    {p.x - 1, p.y},
    {p.x + 1, p.y},
  };
  int i;
  for (i = 0; i < 4; i++) {
    int x = neighbours[i].x, y = neighbours[i].y;
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT &&
        !(maze[y][x] & CELL_VISITED)) {
      return neighbours[i];
    }
  }
  return (Point) {-1, -1};
}

void random_depth_first_search(unsigned char maze[HEIGHT][WIDTH]) {
  Point stack[WIDTH * HEIGHT];
  int top = 0;
  Point current = {0, 0};
  maze[current.y][current.x] |= CELL_VISITED;
  do {
    Point next = random_unvisited_neighbour(maze, current);
    if (next.x >= 0) {
      stack[top++] = current;
      remove_wall(maze, current, next);
      current = next;
      maze[current.y][current.x] |= CELL_VISITED;
    } else if (top > 0) {
      current = stack[--top];
    }
  } while (top > 0);
}

void print_maze(unsigned char maze[HEIGHT][WIDTH]) {
  int i, j;
  for (i = 0; i < HEIGHT; i++) {
    // print top walls
    for (j = 0; j < WIDTH; j++) {
      if (maze[i][j] & CELL_TOP_WALL) {
        printf("+--");
      } else {
        printf("+- ");
      }
    }
    printf("+\n");
    // print left and right walls
    for (j = 0; j < WIDTH; j++) {
      if (maze[i][j] & CELL_LEFT_WALL) {
        printf("|  ");
      } else {
        printf("   ");
      }
      if (maze[i][j] & CELL_RIGHT_WALL) {
        printf("|");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  // print bottom walls
  for (j = 0; j < WIDTH; j++) {
    printf("+--");
  }
  printf("+\n");
}

int main() {
  unsigned char maze[HEIGHT][WIDTH];
  srand(time(NULL));
  init_maze(maze);
  random_depth_first_search(maze);
  print_maze(maze);
  return 0;
}