//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 10
#define MAX_Y 10

typedef struct {
  int x;
  int y;
} point;

int get_distance(point a, point b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

point get_random_point() {
  point p;
  p.x = rand() % MAX_X;
  p.y = rand() % MAX_Y;
  return p;
}

int main() {
  srand(time(0));
  point current_location = get_random_point();
  point destination = get_random_point();

  printf("Current Location: X=%d Y=%d\n", current_location.x, current_location.y);
  printf("Destination: X=%d Y=%d\n", destination.x, destination.y);

  while (current_location.x != destination.x || current_location.y != destination.y) {
    if (current_location.x < destination.x) {
      current_location.x++;
      printf("Move right! Current Location: X=%d Y=%d\n", current_location.x, current_location.y);
    }
    else if (current_location.x > destination.x) {
      current_location.x--;
      printf("Move left! Current Location: X=%d Y=%d\n", current_location.x, current_location.y);
    }
    else if (current_location.y < destination.y) {
      current_location.y++;
      printf("Move up! Current Location: X=%d Y=%d\n", current_location.x, current_location.y);
    }
    else {
      current_location.y--;
      printf("Move down! Current Location: X=%d Y=%d\n", current_location.x, current_location.y);
    }
    printf("Distance to destination: %d\n", get_distance(current_location, destination));
  }
  printf("Arrived at destination!\n");

  return 0;
}