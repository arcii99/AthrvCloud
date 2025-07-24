//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Room {
  int x;
  int y;
  int w;
  int h;
} Room;

void generateMap(int width, int height, Room* rooms, int roomCount) {
  // Initialize the map with impassable borders
  int map[height][width];
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
        map[y][x] = 1;
      } else {
        map[y][x] = 0;
      }
    }
  }

  // Generate rooms
  for (int i = 0; i < roomCount; i++) {
    int w = rand() % 6 + 4;
    int h = rand() % 6 + 4;
    int x = rand() % (width - w - 2) + 1;
    int y = rand() % (height - h - 2) + 1;

    rooms[i] = (Room) { x, y, w, h };

    for (int r = y; r < y + h; r++) {
      for (int c = x; c < x + w; c++) {
        map[r][c] = 1;
      }
    }
  }

  // Connect rooms with corridors
  for (int i = 0; i < roomCount - 1; i++) {
    Room r1 = rooms[i];
    Room r2 = rooms[i+1];

    int x1 = r1.x + r1.w / 2;
    int y1 = r1.y + r1.h / 2;
    int x2 = r2.x + r2.w / 2;
    int y2 = r2.y + r2.h / 2;

    while (x1 != x2) {
      if (x1 < x2) {
        x1++;
      } else {
        x1--;
      }
      map[y1][x1] = 0;
    }

    while (y1 != y2) {
      if (y1 < y2) {
        y1++;
      } else {
        y1--;
      }
      map[y1][x1] = 0;
    }
  }

  // Print map
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      printf("%c", map[y][x] == 1 ? '#' : '.');
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  int width = 40;
  int height = 20;
  int roomCount = 8;

  Room rooms[roomCount];

  generateMap(width, height, rooms, roomCount);
  
  return 0;
}