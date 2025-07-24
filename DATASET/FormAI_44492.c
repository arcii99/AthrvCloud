//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

#define MAX_ROOMS 10
#define ROOM_MIN_SIZE 6
#define ROOM_MAX_SIZE 12

typedef struct {
  int x, y, w, h;
} Room;

void initMap(int map[WIDTH][HEIGHT]) {
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      map[x][y] = 1;
    }
  }
}

void fillRect(int map[WIDTH][HEIGHT], int x, int y, int w, int h, int tile) {
  for (int dx = 0; dx < w; dx++) {
    for (int dy = 0; dy < h; dy++) {
      map[x + dx][y + dy] = tile;
    }
  }
}

void addRoom(Room rooms[MAX_ROOMS], int numRooms) {
  int x = rand() % (WIDTH - ROOM_MAX_SIZE - 1) + 1;
  int y = rand() % (HEIGHT - ROOM_MAX_SIZE - 1) + 1;
  int w = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
  int h = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;

  rooms[numRooms] = (Room){x, y, w, h};
}

void connectRooms(Room rooms[MAX_ROOMS], int numRooms, int map[WIDTH][HEIGHT]) {
  for (int i = 1; i < numRooms; i++) {
    int x1 = rooms[i - 1].x + rooms[i - 1].w / 2;
    int y1 = rooms[i - 1].y + rooms[i - 1].h / 2;
    int x2 = rooms[i].x + rooms[i].w / 2;
    int y2 = rooms[i].y + rooms[i].h / 2;

    while (x1 != x2) {
      x1 += (x1 < x2) ? 1 : -1;
      map[x1][y1] = 0;
    }

    while (y1 != y2) {
      y1 += (y1 < y2) ? 1 : -1;
      map[x1][y1] = 0;
    }
  }
}

void printMap(int map[WIDTH][HEIGHT]) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      putchar(map[x][y] ? '#' : '.');
    }
    putchar('\n');
  }
}

int main() {
  int map[WIDTH][HEIGHT];
  Room rooms[MAX_ROOMS];
  int numRooms = 0;

  srand((unsigned)time(NULL));

  initMap(map);

  for (int i = 0; i < MAX_ROOMS; i++) {
    addRoom(rooms, numRooms);
    if (i > 0) connectRooms(rooms, i, map);
    numRooms++;
  }

  fillRect(map, 0, 0, WIDTH, 1, 1);
  fillRect(map, 0, 0, 1, HEIGHT, 1);
  fillRect(map, 0, HEIGHT - 1, WIDTH, 1, 1);
  fillRect(map, WIDTH - 1, 0, 1, HEIGHT, 1);

  printMap(map);

  return 0;
}