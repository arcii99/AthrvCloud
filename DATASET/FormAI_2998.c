//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: complex
#include <stdio.h>

#define ROW 15
#define COL 15
#define WALL 1
#define PATH 2
#define MAX_ROUTE_LEN 225

int maze[ROW][COL] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                      {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
                      {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
                      {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                      {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
                      {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                      {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                      {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                      {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                      {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                      {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                      {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                      {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                      {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

typedef struct {
  int row, col;
} Point;

typedef struct {
  Point points[MAX_ROUTE_LEN];
  int route_len;
} Route;

Point starting_point;
Point destination_point;

Route find_route(Point current_point, Route current_route);
void reset_route(Route *route);

int main() {
  starting_point.row = 1;
  starting_point.col = 1;

  destination_point.row = 13;
  destination_point.col = 13;

  Route solution_route = find_route(starting_point, (Route){{{0, 0}}, 0});

  if (solution_route.route_len > 0) {
    printf("The shortest route from (%d, %d) to (%d, %d) is:\n", starting_point.row, starting_point.col,
           destination_point.row, destination_point.col);

    for (int i = 0; i <= solution_route.route_len; i++) {
      printf("(%d, %d)\n", solution_route.points[i].row, solution_route.points[i].col);
    }

  } else {
    printf("No route found from (%d, %d) to (%d, %d)\n", starting_point.row, starting_point.col, destination_point.row,
           destination_point.col);
  }

  return 0;
}

Route find_route(Point current_point, Route current_route) {
  if (current_point.row == destination_point.row && current_point.col == destination_point.col) {
    return current_route;
  }

  Route shortest_route = (Route){{{0, 0}}, MAX_ROUTE_LEN};

  maze[current_point.row][current_point.col] = PATH;
  Point neighbouring_points[] = {{current_point.row - 1, current_point.col}, {current_point.row + 1, current_point.col},
                                 {current_point.row, current_point.col - 1}, {current_point.row, current_point.col + 1}};

  for (int i = 0; i < 4; i++) {
    Point next_point = neighbouring_points[i];

    if (maze[next_point.row][next_point.col] == 0) {
      Route new_route = current_route;
      new_route.points[new_route.route_len++] = next_point;
      Route candidate_route = find_route(next_point, new_route);

      if (candidate_route.route_len > 0 && candidate_route.route_len < shortest_route.route_len) {
        shortest_route = candidate_route;
      }
    }
  }

  maze[current_point.row][current_point.col] = 0; /* reset to 0 for retry */
  return shortest_route;
}

void reset_route(Route *route) {
  route->route_len = 0;
  for (int i = 0; i < MAX_ROUTE_LEN; i++) {
    route->points[i] = (Point){0, 0};
  }
}