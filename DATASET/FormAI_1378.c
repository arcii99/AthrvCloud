//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10
#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 8

void generateMap(int map[MAP_WIDTH][MAP_HEIGHT]);
void generateRoom(int map[MAP_WIDTH][MAP_HEIGHT], int startX, int startY);
void connectRooms(int map[MAP_WIDTH][MAP_HEIGHT], int startX, int startY, int endX, int endY);

int main() {
  int map[MAP_WIDTH][MAP_HEIGHT];
  srand(time(NULL));

  generateMap(map);

  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      if (map[x][y] == 1) {
        printf(".");
      } else if (map[x][y] == 2) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}

void generateMap(int map[MAP_WIDTH][MAP_HEIGHT]) {
  // Fill map with walls
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      map[x][y] = 2;
    }
  }

  // Generate rooms
  int roomCount = 0;
  while (roomCount < MAX_ROOMS) {
    int startX = rand() % (MAP_WIDTH - 2 - MAX_ROOM_WIDTH) + 1;
    int startY = rand() % (MAP_HEIGHT - 2 - MAX_ROOM_HEIGHT) + 1;
    if (map[startX][startY] == 2) {
      generateRoom(map, startX, startY);
      roomCount++;
    }
  }

  // Connect rooms
  int startX = -1, startY = -1;
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      if (map[x][y] == 1) {
        if (startX == -1 && startY == -1) {
          startX = x;
          startY = y;
        } else {
          connectRooms(map, startX, startY, x, y);
          startX = -1;
          startY = -1;
        }
      }
    }
  }
}

void generateRoom(int map[MAP_WIDTH][MAP_HEIGHT], int startX, int startY) {
  int width = rand() % (MAX_ROOM_WIDTH - 2) + 3;
  int height = rand() % (MAX_ROOM_HEIGHT - 2) + 3;
  for (int y = startY; y < startY + height; y++) {
    for (int x = startX; x < startX + width; x++) {
      if (x == startX || x == startX + width - 1 || y == startY || y == startY + height - 1) {
        map[x][y] = 2;
      } else {
        map[x][y] = 1;
      }
    }
  }
}

void connectRooms(int map[MAP_WIDTH][MAP_HEIGHT], int startX, int startY, int endX, int endY) {
  while (startX != endX || startY != endY) {
    int xDiff = abs(endX - startX);
    int yDiff = abs(endY - startY);
    if (xDiff > yDiff) {
      if (startX < endX) {
        startX++;
      } else {
        startX--;
      }
    } else {
      if (startY < endY) {
        startY++;
      } else {
        startY--;
      }
    }
    map[startX][startY] = 1;
  }
}