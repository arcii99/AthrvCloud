//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

// function to print the maze
void printMaze(char maze[ROWS][COLUMNS]) {
  printf("============== MAZE ==============\n");
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

// function to check if a cell is valid, i.e., not out of bounds and not a wall
int isValidCell(char maze[ROWS][COLUMNS], int r, int c) {
  if (r < 0 || r >= ROWS || c < 0 || c >= COLUMNS || maze[r][c] == '#') {
    return 0;
  }
  return 1;
}

// function that uses the breadth-first search (BFS) algorithm to find the shortest path from (sr, sc) to (dr, dc)
int BFS(char maze[ROWS][COLUMNS], int sr, int sc, int dr, int dc) {
  // initialize queue with starting cell
  int queue_rows[ROWS * COLUMNS], queue_cols[ROWS * COLUMNS];
  int front = 0, rear = 0;
  queue_rows[rear] = sr;
  queue_cols[rear] = sc;
  rear++;

  // initialize visited array
  int visited[ROWS][COLUMNS] = {0};
  visited[sr][sc] = 1;

  // initialize distance array
  int distance[ROWS][COLUMNS] = {0};

  // loop until queue is empty
  while (front != rear) {
    // dequeue cell from queue
    int r = queue_rows[front];
    int c = queue_cols[front];
    front++;

    // if destination cell is reached, return distance to it
    if (r == dr && c == dc) {
      return distance[dr][dc];
    }

    // explore neighboring cells
    int dr_offset[] = {-1, 0, 1, 0};
    int dc_offset[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      int r_new = r + dr_offset[i];
      int c_new = c + dc_offset[i];

      // if neighboring cell is valid and unvisited, enqueue it
      if (isValidCell(maze, r_new, c_new) && !visited[r_new][c_new]) {
        queue_rows[rear] = r_new;
        queue_cols[rear] = c_new;
        rear++;

        // mark it as visited and update its distance from starting cell
        visited[r_new][c_new] = 1;
        distance[r_new][c_new] = distance[r][c] + 1;
      }
    }
  }

  // if destination cell is not reachable, return -1
  return -1;
}

int main() {
  char maze[ROWS][COLUMNS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '#', '#', '.', '#', '#', '.', '#'},
    {'#', '#', '.', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
  };

  int shortest_distance = BFS(maze, 1, 1, 8, 9);

  if (shortest_distance > 0) {
    printf("Shortest distance: %d\n", shortest_distance);
  } else {
    printf("Destination cell is not reachable\n");
  }

  // print maze with shortest path
  int r = 1, c = 1;
  while (r != 8 || c != 9) {
    maze[r][c] = '*';
    int dr_offset[] = {-1, 0, 1, 0};
    int dc_offset[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
      int r_new = r + dr_offset[i];
      int c_new = c + dc_offset[i];
      if (isValidCell(maze, r_new, c_new) && BFS(maze, r_new, c_new, 8, 9) == shortest_distance-1) {
        r = r_new;
        c = c_new;
        shortest_distance--;
        break;
      }
    }
  }
  maze[8][9] = '*';

  // print maze with path
  printMaze(maze);

  return 0;
}