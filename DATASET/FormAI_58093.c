//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 7

// Constants for directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Constants for cell types
#define EMPTY 0
#define WALL 1
#define START 2
#define GOAL 3
#define PATH 4
#define CLOSED 5

int maze[ROWS][COLS] = {
  {1, 1, 1, 1, 1, 1, 1},
  {1, 2, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1},
  {1, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 0, 1},
  {1, 1, 1, 3, 1, 1, 1}
};

// Struct for representing a cell
struct cell {
  int row;
  int col;
  int type;
  int g;
  int h;
  int f;
  struct cell *parent;
};

// Function for calculating the Manhattan distance between two cells
int manhattan_distance(struct cell *a, struct cell *b)
{
  return abs(a->row - b->row) + abs(a->col - b->col);
}

// Function for printing the maze
void print_maze()
{
  for (int row = 0; row < ROWS; row++)
  {
    for (int col = 0; col < COLS; col++)
    {
      switch(maze[row][col])
      {
        case WALL:
          printf("# ");
          break;
        case START:
          printf("S ");
          break;
        case GOAL:
          printf("G ");
          break;
        case PATH:
          printf("* ");
          break;
        default:
          printf(". ");
          break;
      }
    }
    printf("\n");
  }
}

// Function for checking if a cell is inside the maze
bool valid_cell(struct cell *c)
{
  return c->row >= 0 && c->row < ROWS && c->col >= 0 && c->col < COLS;
}

// Function for checking if a cell is traversable
bool traversable_cell(struct cell *c)
{
  return valid_cell(c) && maze[c->row][c->col] != WALL && maze[c->row][c->col] != CLOSED;
}

// Function for finding the lowest f value in a list of cells
struct cell *lowest_f_value(struct cell **list, int length)
{
  struct cell *lowest = list[0];
  
  for (int i = 1; i < length; i++)
  {
    if (list[i]->f < lowest->f)
    {
      lowest = list[i];
    }
  }
  
  return lowest;
}

// Function for generating a list of neighbors for a given cell
struct cell **get_neighbors(struct cell *c)
{
  struct cell **neighbors = malloc(4 * sizeof(struct cell *));
  struct cell up = {c->row - 1, c->col, EMPTY, 0, 0, 0, NULL};
  struct cell right = {c->row, c->col + 1, EMPTY, 0, 0, 0, NULL};
  struct cell down = {c->row + 1, c->col, EMPTY, 0, 0, 0, NULL};
  struct cell left = {c->row, c->col - 1, EMPTY, 0, 0, 0, NULL};
  struct cell *n;

  n = &up;
  if (traversable_cell(n)) neighbors[NORTH] = n;
  else neighbors[NORTH] = NULL;

  n = &right;
  if (traversable_cell(n)) neighbors[EAST] = n;
  else neighbors[EAST] = NULL;

  n = &down;
  if (traversable_cell(n)) neighbors[SOUTH] = n;
  else neighbors[SOUTH] = NULL;

  n = &left;
  if (traversable_cell(n)) neighbors[WEST] = n;
  else neighbors[WEST] = NULL;

  return neighbors;
}

// Function for freeing memory allocated for a list of cells
void free_cell_list(struct cell **list, int length)
{
  for (int i = 0; i < length; i++)
  {
    free(list[i]);
  }
  free(list);
}

// Function for finding the shortest path from the start to the goal
void find_path(struct cell *start, struct cell *goal)
{
  // Initialization
  struct cell *open_list[ROWS * COLS];
  int num_open = 0;
  struct cell *closed_list[ROWS * COLS];
  int num_closed = 0;
  start->g = 0;
  start->h = manhattan_distance(start, goal);
  start->f = start->g + start->h;
  open_list[num_open] = start;
  num_open++;

  // A* algorithm
  while (num_open > 0)
  {
    // Find the cell with the lowest f value in the open list
    struct cell *current = lowest_f_value(open_list, num_open);

    // If the current cell is the goal, we've found the shortest path
    if (current->type == GOAL)
    {
      struct cell *c = current;
      while (c != start)
      {
        c->type = PATH;
        c = c->parent;
      }
      print_maze();
      return;
    }

    // Move the current cell from the open list to the closed list
    for (int i = 0; i < num_open; i++)
    {
      if (open_list[i] == current)
      {
        for (int j = i; j < num_open - 1; j++)
        {
          open_list[j] = open_list[j+1];
        }
        num_open--;
        break;
      }
    }
    closed_list[num_closed] = current;
    num_closed++;

    // Generate a list of neighbors for the current cell
    struct cell **neighbors = get_neighbors(current);

    // Loop through every neighbor
    for (int i = 0; i < 4; i++)
    {
      struct cell *neighbor = neighbors[i];

      // If the neighbor is not traversable, skip it
      if (neighbor == NULL)
      {
        continue;
      }

      // Calculate the tentative g value for the neighbor
      int tentative_g = current->g + 1;

      // If the neighbor is already in the closed list and the tentative g value is higher than its current g value, skip it
      bool in_closed_list = false;
      for (int j = 0; j < num_closed; j++)
      {
        if (closed_list[j] == neighbor)
        {
          in_closed_list = true;
          if (tentative_g >= neighbor->g)
          {
            goto skip;
          }
          break;
        }
      }

      // If the neighbor is not in the open list, add it and calculate its g, h, and f values
      if (!in_closed_list)
      {
        neighbor->parent = current;
        neighbor->g = tentative_g;
        neighbor->h = manhattan_distance(neighbor, goal);
        neighbor->f = neighbor->g + neighbor->h;
        open_list[num_open] = neighbor;
        num_open++;
      }
      // If the neighbor is already in the open list and the tentative g value is lower than its current g value, update its g, h, and f values and set its parent to the current cell
      else if (tentative_g < neighbor->g)
      {
        neighbor->parent = current;
        neighbor->g = tentative_g;
        neighbor->h = manhattan_distance(neighbor, goal);
        neighbor->f = neighbor->g + neighbor->h;
      }

      skip:;
    }

    free_cell_list(neighbors, 4);
  }
}

// Main function
int main()
{
  // Find the start and goal cells
  struct cell start = {0, 0, EMPTY, 0, 0, 0, NULL};
  struct cell goal = {0, 0, EMPTY, 0, 0, 0, NULL};
  for (int row = 0; row < ROWS; row++)
  {
    for (int col = 0; col < COLS; col++)
    {
      if (maze[row][col] == START)
      {
        start.row = row;
        start.col = col;
        start.type = START;
      }
      else if (maze[row][col] == GOAL)
      {
        goal.row = row;
        goal.col = col;
        goal.type = GOAL;
      }
    }
  }

  find_path(&start, &goal);

  return 0;
}