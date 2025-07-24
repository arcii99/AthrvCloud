//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

// Struct to represent a point in the maze
struct Point {
  int x;
  int y;
};

// Function to check if a given point is inside the maze or not
int isValid(int row, int col) {
  return (row >= 0) && (row < ROWS) && (col >= 0) && (col < COLS);
}

// Function to check if a given point is a wall or not
int isWall(char maze[][COLS], int row, int col) {
  return maze[row][col] == '#';
}

// Function to check if a given point is a visited point or not
int isVisited(int visited[][COLS], int row, int col) {
  return visited[row][col] == 1;
}

// Function to check if a given point is a destination point or not
int isDestination(struct Point dest, int row, int col) {
  return (dest.x == row) && (dest.y == col);
}

// Function to print the path from the start to the destination
void printPath(struct Point path[], int path_size) {
  int i;

  for (i = 0; i < path_size; i++) {
    printf("(%d,%d) ", path[i].x, path[i].y);
  }

  printf("\n");
}

// A recursive function to find the shortest path from start to destination
void findPath(char maze[][COLS], int row, int col, struct Point dest, int visited[][COLS], struct Point path[], int path_size, int *shortest_distance, struct Point *shortest_path) {
  // Base Case: If we have reached the destination, then return
  if (isDestination(dest, row, col)) {
    if (path_size < *shortest_distance) {
      // Update the shortest distance and shortest path if we have found a shorter path
      *shortest_distance = path_size;
      memcpy(shortest_path, path, path_size*sizeof(struct Point));
    }
    return;
  }

  // If the current point is invalid or a wall or already visited, then return
  if (!isValid(row, col) || isWall(maze, row, col) || isVisited(visited, row, col)) {
    return;
  }

  // Mark the current point as visited
  visited[row][col] = 1;

  // Add the current point to the path
  path[path_size] = (struct Point) {row, col};
  path_size++;

  // Recur for all the adjacent points
  findPath(maze, row-1, col, dest, visited, path, path_size, shortest_distance, shortest_path); // Up
  findPath(maze, row, col-1, dest, visited, path, path_size, shortest_distance, shortest_path); // Left
  findPath(maze, row+1, col, dest, visited, path, path_size, shortest_distance, shortest_path); // Down
  findPath(maze, row, col+1, dest, visited, path, path_size, shortest_distance, shortest_path); // Right

  // Remove the current point from the path and mark it as unvisited to explore another path that handle this point differently.
  path_size--;
  visited[row][col] = 0;
}

int main() {
  char maze[ROWS][COLS] = {
    "#S######.#",
    "......#..#",
    ".######.#.",
    ".#..#.....",
    ".#..#.###.",
    "......#..#",
    ".######.#.",
    ".#......#.",
    ".####.#...",
    "....#E####"
  };

  int visited[ROWS][COLS];
  memset(visited, 0, sizeof visited);

  struct Point start = (struct Point) {0, 1};
  struct Point dest = (struct Point) {9, 5};

  int shortest_distance = ROWS * COLS;
  struct Point shortest_path[ROWS*COLS];

  struct Point path[ROWS*COLS];
  int path_size = 0;

  findPath(maze, start.x, start.y, dest, visited, path, path_size, &shortest_distance, shortest_path);

  printf("Shortest Path: ");
  printPath(shortest_path, shortest_distance);

  return 0;
}