//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 6

int maze[ROWS][COLS] = {
   {1, 1, 1, 1, 1, 1},
   {0, 0, 0, 0, 0, 1},
   {1, 1, 1, 1, 0, 1},
   {1, 0, 0, 0, 0, 0},
   {1, 1, 1, 1, 1, 1},
   {0, 0, 0, 0, 0, 1}
};

typedef struct {
   int row, col;
} Point;

Point queue[50];
int visited[ROWS][COLS];
int front = -1, rear = -1;

void enqueue(Point p) {
   if (front == -1) {
      front = 0;
      rear = 0;
   } else {
      rear++;
   }
   queue[rear] = p;
}

Point dequeue() {
   Point p = queue[front];
   front++;
   if (front > rear) {
      front = -1;
      rear = -1;
   }
   return p;
}

int is_empty() {
   if (front == -1) {
      return 1;
   } else {
      return 0;
   }
}

void reset_visited() {
   int i, j;
   for (i = 0; i < ROWS; i++) {
      for (j = 0; j < COLS; j++) {
         visited[i][j] = 0;
      }
   }
}

void print_path(Point path[], int path_length) {
   int i;
   for (i = 0; i < path_length; i++) {
      printf("(%d,%d)", path[i].row, path[i].col);
      if (i < path_length - 1) {
         printf(" -> ");
      }
   }
}

int bfs(Point start, Point goal, Point path[]) {
   int i, j, found_goal = 0;
   reset_visited();
   enqueue(start);
   visited[start.row][start.col] = 1;
   while (!is_empty()) {
      Point p = dequeue();
      if (p.row == goal.row && p.col == goal.col) {
         found_goal = 1;
         break;
      }
      if (p.row > 0 && maze[p.row-1][p.col] == 1 && !visited[p.row-1][p.col]) {
         Point neighbor = {p.row-1, p.col};
         visited[neighbor.row][neighbor.col] = 1;
         enqueue(neighbor);
      }
      if (p.row < ROWS-1 && maze[p.row+1][p.col] == 1 && !visited[p.row+1][p.col]) {
         Point neighbor = {p.row+1, p.col};
         visited[neighbor.row][neighbor.col] = 1;
         enqueue(neighbor);
      }
      if (p.col > 0 && maze[p.row][p.col-1] == 1 && !visited[p.row][p.col-1]) {
         Point neighbor = {p.row, p.col-1};
         visited[neighbor.row][neighbor.col] = 1;
         enqueue(neighbor);
      }
      if (p.col < COLS-1 && maze[p.row][p.col+1] == 1 && !visited[p.row][p.col+1]) {
         Point neighbor = {p.row, p.col+1};
         visited[neighbor.row][neighbor.col] = 1;
         enqueue(neighbor);
      }
   }
   if (found_goal) {
      Point current = goal;
      int path_length = 0;
      while (1) {
         path[path_length] = current;
         path_length++;
         if (current.row == start.row && current.col == start.col) {
            break;
         }
         if (current.row > 0 && maze[current.row-1][current.col] == 1
                           && visited[current.row-1][current.col]) {
            current = (Point) {current.row-1, current.col};
         } else if (current.row < ROWS-1 && maze[current.row+1][current.col] == 1
                                          && visited[current.row+1][current.col]) {
            current = (Point) {current.row+1, current.col};
         } else if (current.col > 0 && maze[current.row][current.col-1] == 1
                                    && visited[current.row][current.col-1]) {
            current = (Point) {current.row, current.col-1};
         } else if (current.col < COLS-1 && maze[current.row][current.col+1] == 1
                                          && visited[current.row][current.col+1]) {
            current = (Point) {current.row, current.col+1};
         }
      }
      return path_length;
   } else {
      return -1;
   }
}

int main() {
   Point start = {2, 0};
   Point goal = {5, 5};
   Point path[50];
   int path_length;
   path_length = bfs(start, goal, path);
   if (path_length == -1) {
      printf("No path found.\n");
   } else {
      printf("Path: ");
      print_path(path, path_length);
      printf("\n");
   }
   return 0;
}