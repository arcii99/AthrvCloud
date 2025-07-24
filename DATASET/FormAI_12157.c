//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 10
#define COLS 10

typedef enum { NONE=0, WALL=1 } cell_type;

typedef struct {
  int row, col;
  int f, g, h;
  cell_type type;
  bool in_closed_set;
  bool in_open_set;
  struct node* parent;
} node;

node grid[ROWS][COLS];
node* start_node;
node* end_node;

int manhattan_distance(node* node1, node* node2) {
  return abs(node1->row - node2->row) + abs(node1->col - node2->col);
}

int heuristic_cost_estimate(node* current_node) {
  return manhattan_distance(current_node, end_node);
}

void initialize_grid() {
  int row, col;
  int wall_count = 0;
  srand(time(NULL));
  
  // Randomly generate walls
  for (row = 0; row < ROWS; row++) {
    for (col = 0; col < COLS; col++) {
      if (rand() % 100 < 20) {
        grid[row][col].type = WALL;
        wall_count++;
      } else {
        grid[row][col].type = NONE;
      }
      grid[row][col].row = row;
      grid[row][col].col = col;
      grid[row][col].in_closed_set = false;
      grid[row][col].in_open_set = false;
      grid[row][col].parent = NULL;
    }
  }
  
  // Ensure there is a clear path from the start to the end
  do {
    start_node = &grid[rand() % ROWS][rand() % COLS];
    end_node = &grid[rand() % ROWS][rand() % COLS];
  } while (start_node == end_node || start_node->type == WALL || end_node->type == WALL || manhattan_distance(start_node, end_node) < ROWS / 2);
  
  printf("Walls generated: %d\n", wall_count);
}

void print_grid() {
  int row, col;
  printf("    ");
  for (col = 0; col < COLS; col++) {
    printf("%d ", col);
  }
  printf("\n");
  printf("\n");
  for (row = 0; row < ROWS; row++) {
    printf(" %d  ", row);
    for (col = 0; col < COLS; col++) {
      if (grid[row][col].type == WALL) {
        printf("X ");
      } else if (grid[row][col].in_closed_set) {
        printf("C ");
      } else if (grid[row][col].in_open_set) {
        printf("O ");
      } else if (grid[row][col].parent == NULL) {
        printf("* ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

node* lowest_f_score_node(node* current_node) {
  node* lowest_f_score_node = NULL;
  int lowest_f_score = INFINITY;
  int row, col;
  
  for (row = 0; row < ROWS; row++) {
    for (col = 0; col < COLS; col++) {
      if (grid[row][col].in_open_set && grid[row][col].f < lowest_f_score) {
        lowest_f_score = grid[row][col].f;
        lowest_f_score_node = &grid[row][col];
      }
    }
  }
  
  return lowest_f_score_node;
}

void process_node(node* current_node, node* neighbour) {
  if (neighbour->in_closed_set) {
    return;
  }
  
  if (!neighbour->in_open_set) {
    neighbour->in_open_set = true;
    neighbour->g = INFINITY;
    neighbour->h = heuristic_cost_estimate(neighbour);
  }
  
  int tentative_g_score = current_node->g + 1; // Assuming each step cost is 1
  if (tentative_g_score >= neighbour->g) {
    return;
  }
  
  neighbour->parent = current_node;
  neighbour->g = tentative_g_score;
  neighbour->f = neighbour->g + neighbour->h;
}

void reconstruct_path() {
  node* current_node = end_node;
  while (current_node != start_node) {
    current_node = current_node->parent;
    current_node->type = NONE;
  }
}

void a_star_algorithm() {
  start_node->g = 0;
  start_node->h = heuristic_cost_estimate(start_node);
  start_node->f = start_node->g + start_node->h;
  start_node->in_open_set = true;
  
  while (true) {
    node* current_node = lowest_f_score_node(start_node);
    if (current_node == NULL) {
      printf("No path found.\n");
      break;
    }
    
    if (current_node == end_node) {
      reconstruct_path();
      break;
    }
    
    current_node->in_open_set = false;
    current_node->in_closed_set = true;
    print_grid();
    
    int row, col;
    for (row = -1; row <= 1; row++) {
      for (col = -1; col <= 1; col++) {
        if (row == 0 && col == 0) {
          continue;
        }
        
        int new_row = current_node->row + row;
        int new_col = current_node->col + col;
        if (new_row < 0 || new_row >= ROWS || new_col < 0 || new_col >= COLS) {
          continue;
        }
        
        node* neighbour = &grid[new_row][new_col];
        if (neighbour->type == WALL) {
          continue;
        }
        
        process_node(current_node, neighbour);
      }
    }
  }
}

int main() {
  initialize_grid();
  print_grid();
  a_star_algorithm();
  printf("\n");
  print_grid();
  
  return 0;
}