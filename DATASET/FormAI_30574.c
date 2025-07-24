//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define MAX_ROOM_SIZE 5
#define MIN_ROOM_SIZE 3
#define MAX_ROOMS 6
#define STAIRS_UP -1
#define STAIRS_DOWN -2

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  Point location;
  int width;
  int height;
} Room;

int map[MAP_SIZE][MAP_SIZE];
Point stairsUpLocation;
Point stairsDownLocation;

int getRandomInt(int min, int max) {
  return rand() % (max - min + 1) + min;
}

void initializeMap() {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      map[i][j] = '#';
    }
  }
}

void initializeRooms(Room* rooms) {
  for (int i = 0; i < MAX_ROOMS; i++) {
    int roomWidth = getRandomInt(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
    int roomHeight = getRandomInt(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
    int x = getRandomInt(1, MAP_SIZE - roomWidth - 1);
    int y = getRandomInt(1, MAP_SIZE - roomHeight - 1);
    
    for (int j = y; j < y + roomHeight; j++) {
      for (int k = x; k < x + roomWidth; k++) {
        map[j][k] = '.';
      }
    }
    
    rooms[i].location.x = x;
    rooms[i].location.y = y;
    rooms[i].width = roomWidth;
    rooms[i].height = roomHeight;
  }
}

void initializeStairs() {
  stairsUpLocation.x = getRandomInt(1, MAP_SIZE - 2);
  stairsUpLocation.y = getRandomInt(1, MAP_SIZE - 2);
  stairsDownLocation.x = getRandomInt(1, MAP_SIZE - 2);
  stairsDownLocation.y = getRandomInt(1, MAP_SIZE - 2);
  
  map[stairsUpLocation.y][stairsUpLocation.x] = STAIRS_UP;
  map[stairsDownLocation.y][stairsDownLocation.x] = STAIRS_DOWN;
}

void printMap() {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  
  Room rooms[MAX_ROOMS];
  
  initializeMap();
  initializeRooms(rooms);
  initializeStairs();
  printMap();
  
  return 0;
}