//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 5
#define COLS 5

struct node {
  int row, col;
  double f, g, h;
  struct node *parent;
};

double heuristic(int r1, int c1, int r2, int c2) {
  return sqrt(pow(r1 - r2, 2) + pow(c1 - c2, 2));
}

void insert(struct node **open_list, struct node *new_node) {
  while (*open_list != NULL && (*open_list)->f < new_node->f) {
    open_list = &((*open_list)->parent);
  }
  new_node->parent = *open_list;
  *open_list = new_node;
}

struct node *pop(struct node **open_list) {
  struct node *pop_node = *open_list;
  *open_list = pop_node->parent;
  return pop_node;
}

int can_move(int row, int col, int map[ROWS][COLS]) {
  return row >= 0 && row < ROWS &&
         col >= 0 && col < COLS &&
         map[row][col] == 0;
}

void print_path(struct node *end) {
  if (end->parent == NULL) {
    printf("(%d, %d)", end->row, end->col);
  } else {
    print_path(end->parent);
    printf(" -> (%d, %d)", end->row, end->col);
  }
}

void a_star(int map[ROWS][COLS], int start_row, int start_col, int end_row, int end_col) {
  struct node *open_list = NULL;
  struct node *start = malloc(sizeof(struct node));
  start->row = start_row;
  start->col = start_col;
  start->f = 0;
  start->g = 0;
  start->h = heuristic(start_row, start_col, end_row, end_col);
  start->parent = NULL;
  insert(&open_list, start);
  while (open_list != NULL) {
    struct node *cur = pop(&open_list);
    if (cur->row == end_row && cur->col == end_col) {
      print_path(cur);
      return;
    }
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) {
          continue;
        }
        int new_row = cur->row + i;
        int new_col = cur->col + j;
        if (can_move(new_row, new_col, map)) {
          struct node *new_node = malloc(sizeof(struct node));
          new_node->row = new_row;
          new_node->col = new_col;
          new_node->g = cur->g + 1;
          new_node->h = heuristic(new_row, new_col, end_row, end_col);
          new_node->f = new_node->g + new_node->h;
          insert(&open_list, new_node);
        }
      }
    }
  }
}

int main() {
  int map[ROWS][COLS] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
  };
  a_star(map, 0, 0, 4, 4); // find path from (0, 0) to (4, 4)
  return 0;
}