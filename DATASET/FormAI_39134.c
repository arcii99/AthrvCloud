//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 20
#define MAP_HEIGHT 10
#define MAX_ROOMS 6

int map[MAP_WIDTH][MAP_HEIGHT];

typedef struct {
  int x;
  int y;
  int width;
  int height;
} Room;

void printMap() {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      printf("%c", map[x][y] ? '.' : '#');
    }
    printf("\n");
  }
}

void addRoom(Room room) {
  for (int x = room.x; x < room.x + room.width; x++) {
    for (int y = room.y; y < room.y + room.height; y++) {
      map[x][y] = 1;
    }
  }
}

int isOverlap(Room room1, Room room2) {
  if (room1.x < room2.x + room2.width &&
      room1.x + room1.width > room2.x &&
      room1.y < room2.y + room2.height &&
      room1.y + room1.height > room2.y) {
    return 1;
  }
  return 0;
}

void generateMap() {
  // initialize map with walls
  for (int x = 0; x < MAP_WIDTH; x++) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
      map[x][y] = 0;
    }
  }

  // generate rooms
  Room rooms[MAX_ROOMS];
  for (int i = 0; i < MAX_ROOMS; i++) {
    Room room;

    // randomly set room size
    room.width = rand() % 5 + 5;
    room.height = rand() % 5 + 5;

    // randomly set room position
    room.x = rand() % (MAP_WIDTH - room.width - 1) + 1;
    room.y = rand() % (MAP_HEIGHT - room.height - 1) + 1;

    // check for overlap with previous rooms
    int overlaps = 0;
    for (int j = 0; j < i; j++) {
      if (isOverlap(room, rooms[j])) {
        overlaps = 1;
        break;
      }
    }

    if (overlaps) {
      i--;
      continue;
    }

    // add room to map
    rooms[i] = room;
    addRoom(room);

    // connect room to previous room
    if (i > 0) {
      int prevX = rooms[i-1].x + rooms[i-1].width / 2;
      int prevY = rooms[i-1].y + rooms[i-1].height / 2;
      int curX = room.x + room.width / 2;
      int curY = room.y + room.height / 2;

      while (prevX != curX) {
        if (prevX < curX) {
          prevX++;
        } else {
          prevX--;
        }
        map[prevX][prevY] = 1;
      }

      while (prevY != curY) {
        if (prevY < curY) {
          prevY++;
        } else {
          prevY--;
        }
        map[prevX][prevY] = 1;
      }
    }
  }

  printMap();
}

int main() {
  srand(time(NULL));
  generateMap();
  return 0;
}