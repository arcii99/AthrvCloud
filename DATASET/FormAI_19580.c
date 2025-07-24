//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 25

char map[MAP_HEIGHT][MAP_WIDTH];
int playerX, playerY;

void createMap() {
  // Fill map with walls
  for (int i = 0; i < MAP_HEIGHT; i++) {
    for (int j = 0; j < MAP_WIDTH; j++) {
      map[i][j] = '#';
    }
  }

  // Generate random rooms 
  srand(time(NULL));
  int numRooms = rand() % 5 + 5;
  int roomSize, roomX, roomY;
  for (int i = 0; i < numRooms; i++) {
    roomX = rand() % (MAP_WIDTH - 10);
    roomY = rand() % (MAP_HEIGHT - 10);
    roomSize = rand() % 8 + 3;

    for (int j = roomY; j < roomY + roomSize; j++) {
      for (int k = roomX; k < roomX + roomSize; k++) {
        if (j == roomY || j == roomY + roomSize - 1 || k == roomX || k == roomX + roomSize - 1) {
          map[j][k] = '#';
        } else {
          map[j][k] = '.';
        }
      }
    }
  }

  // Connect rooms with corridors
  int prevRoomX, prevRoomY;
  for (int i = 0; i < numRooms - 1; i++) {
    roomX = rand() % (MAP_WIDTH - 10);
    roomY = rand() % (MAP_HEIGHT - 10);
    
    while (prevRoomX == 0 && prevRoomY == 0) {
      prevRoomX = rand() % (MAP_WIDTH - 10);
      prevRoomY = rand() % (MAP_HEIGHT - 10);
    }

    if (roomX > prevRoomX) {
      for (int j = prevRoomX; j < roomX; j++) {
        if (map[prevRoomY][j] == '#') {
          map[prevRoomY][j] = '.';
        }
      }
    } else {
      for (int j = roomX; j < prevRoomX; j++) {
        if (map[prevRoomY][j] == '#') {
          map[prevRoomY][j] = '.';
        }
      }
    }

    if (roomY > prevRoomY) {
      for (int j = prevRoomY; j < roomY; j++) {
        if (map[j][roomX] == '#') {
          map[j][roomX] = '.';
        }
      }
    } else {
      for (int j = roomY; j < prevRoomY; j++) {
        if (map[j][roomX] == '#') {
          map[j][roomX] = '.';
        }
      }
    }

    prevRoomX = roomX;
    prevRoomY = roomY;
  }

  // Place player
  playerX = rand() % MAP_WIDTH;
  playerY = rand() % MAP_HEIGHT;
  map[playerY][playerX] = '@';
}

void printMap() {
  for (int i = 0; i < MAP_HEIGHT; i++) {
    for (int j = 0; j < MAP_WIDTH; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

int main() {
  createMap();
  printMap();

  return 0;
}