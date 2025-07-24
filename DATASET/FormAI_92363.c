//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: all-encompassing
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_ROOMS 6
#define MAX_SIZE 8

typedef struct {
  int x, y, w, h;
} Room;

void print_map(char map[HEIGHT][WIDTH]) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c", map[y][x]);
    }
    printf("\n");
  }
}

void draw_rect(char map[HEIGHT][WIDTH], int x1, int y1, int x2, int y2) {
  for (int y = y1; y <= y2; y++) {
    for (int x = x1; x <= x2; x++) {
      if (y == y1 || y == y2) {
        map[y][x] = '-';
      } else if (x == x1 || x == x2) {
        map[y][x] = '|';
      } else {
        map[y][x] = '.';
      }
    }
  }
}

void generate_map(char map[HEIGHT][WIDTH]) {
  // Initialize map with walls
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      map[y][x] = '#';
    }
  }

  // Seed random number generator
  srand(time(NULL));

  // Generate rooms
  Room rooms[MAX_ROOMS];
  for (int i = 0; i < MAX_ROOMS; i++) {
    int w = rand() % MAX_SIZE + 2;
    int h = rand() % MAX_SIZE + 2;
    int x = rand() % (WIDTH - w - 1) + 1;
    int y = rand() % (HEIGHT - h - 1) + 1;
    rooms[i] = (Room) { x, y, w, h };
    draw_rect(map, x, y, x+w-1, y+h-1);
  }

  // Connect rooms with tunnels
  for (int i = 0; i < MAX_ROOMS-1; i++) {
    Room r1 = rooms[i];
    Room r2 = rooms[i+1];
    int x1 = r1.x + r1.w/2;
    int y1 = r1.y + r1.h/2;
    int x2 = r2.x + r2.w/2;
    int y2 = r2.y + r2.h/2;
    while (x1 != x2) {
      if (x1 < x2) {
        x1++;
      } else {
        x1--;
      }
      map[y1][x1] = '.';
    }
    while (y1 != y2) {
      if (y1 < y2) {
        y1++;
      } else {
        y1--;
      }
      map[y1][x1] = '.';
    }
  }
}

int main() {
  char map[HEIGHT][WIDTH];
  generate_map(map);
  print_map(map);
  return 0;
}