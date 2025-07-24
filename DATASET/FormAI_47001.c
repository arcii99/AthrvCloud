//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>

#define ROWS 10
#define COLS 10

void find_route(char maze[][COLS], int start_row, int start_col, int end_row, int end_col);

int main(void)
{
  char maze[ROWS][COLS] = {
      {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
      {'#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', '#'},
      {'#', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', '#'},
      {'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
      {'#', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
      {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
      {'#', '#', '#', '#', ' ', '#', '#', '#', '#', '#'},
      {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  };

  find_route(maze, 1, 1, 8, 8);

  return 0;
}

void find_route(char maze[][COLS], int start_row, int start_col, int end_row, int end_col)
{
  int row_dir[] = {-1, 0, 1, 0}; // Up, right, down, left
  int col_dir[] = {0, 1, 0, -1};
  int i, j, k;
  int queue[ROWS * COLS][2]; // Queue to hold all possible locations to be explored
  int parent[ROWS][COLS][2]; // Parent array to keep track of the previous location
  int visited[ROWS][COLS] = {}; // Visited array to keep track of already visited locations
  int front = -1; // Initialize front of the queue
  int rear = -1; // Initialize rear of the queue

  queue[++rear][0] = start_row; // Adding the starting location to the queue
  queue[rear][1] = start_col;
  visited[start_row][start_col] = 1; // Marking the starting location as visited

  // Finding the end location
  while (front != rear)
  {
    int current_row = queue[++front][0]; // Dequeuing the front location from the queue
    int current_col = queue[front][1];

    if (current_row == end_row && current_col == end_col)
    {
      break; // End location reached
    }

    for (i = 0; i < 4; ++i) // Exploring the locations around the current location
    {
      int new_row = current_row + row_dir[i];
      int new_col = current_col + col_dir[i];

      if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS && maze[new_row][new_col] != '#' && !visited[new_row][new_col])
      {
        visited[new_row][new_col] = 1; // Marking the new location as visited
        queue[++rear][0] = new_row; // Enqueuing the new location to the queue
        queue[rear][1] = new_col;
        parent[new_row][new_col][0] = current_row; // Updating the parent array with the previous location
        parent[new_row][new_col][1] = current_col;
      }
    }
  }

  // Reconstructing the route from the end location to the starting location
  int route[ROWS * COLS][2]; // Array to hold the route
  int steps = 0; // Number of steps taken
  int curr_row = end_row;
  int curr_col = end_col;

  while (curr_row != start_row || curr_col != start_col)
  {
    route[steps][0] = curr_row; // Adding the current location to the route array
    route[steps++][1] = curr_col;
    int new_row = parent[curr_row][curr_col][0]; // Finding the previous location
    int new_col = parent[curr_row][curr_col][1];
    curr_row = new_row; // Updating the current location to the previous location
    curr_col = new_col;
  }

  route[steps][0] = start_row; // Adding the starting location to the route array
  route[steps++][1] = start_col;

  // Printing the maze with the route marked by '*'
  printf("Maze with the route marked by '*':\n");
  for (i = 0; i < ROWS; ++i)
  {
    for (j = 0; j < COLS; ++j)
    {
      // Checking if the current location is part of the route
      int is_route = 0;
      for (k = 0; k < steps; ++k)
      {
        if (route[k][0] == i && route[k][1] == j)
        {
          is_route = 1;
          break;
        }
      }

      // Printing the location with the appropriate symbol
      if (is_route)
      {
        printf("* ");
      }
      else
      {
        printf("%c ", maze[i][j]);
      }
    }
    printf("\n");
  }
}