//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10
#define ROOM_MIN_WIDTH 4
#define ROOM_MIN_HEIGHT 4
#define ROOM_MAX_WIDTH 10
#define ROOM_MAX_HEIGHT 10

// define a cell struct to represent a single tile on the map
typedef struct Cell {
  char content;
  bool occupied;
} Cell;

// define a room struct to represent a single room on the map
typedef struct Room {
  int x, y, width, height;
} Room;

// define the map as a two-dimensional array of cells
Cell map[MAP_HEIGHT][MAP_WIDTH];

// define an array to store the rooms in
Room rooms[MAX_ROOMS];

// function to randomly generate a room
Room generate_room() {
  Room room;

  room.width = rand() % (ROOM_MAX_WIDTH - ROOM_MIN_WIDTH) + ROOM_MIN_WIDTH;
  room.height = rand() % (ROOM_MAX_HEIGHT - ROOM_MIN_HEIGHT) + ROOM_MIN_HEIGHT;
  room.x = rand() % (MAP_WIDTH - room.width - 1) + 1;
  room.y = rand() % (MAP_HEIGHT - room.height - 1) + 1;

  return room;
}

int main() {
  // initialize the random number generator
  srand(time(0));

  // generate the rooms
  int num_rooms = 0;
  while (num_rooms < MAX_ROOMS) {
    Room room = generate_room();
    bool overlaps = false;
    for (int i = 0; i < num_rooms; i++) {
      if (room.x < rooms[i].x + rooms[i].width + 1 &&
          room.x + room.width + 1 > rooms[i].x &&
          room.y < rooms[i].y + rooms[i].height + 1 &&
          room.y + room.height + 1 > rooms[i].y) {
        overlaps = true;
        break;
      }
    }
    if (!overlaps) {
      rooms[num_rooms] = room;
      num_rooms++;
    }
  }

  // fill in the map with walls
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      map[y][x].content = '#';
    }
  }

  // carve out the rooms on the map
  for (int i = 0; i < MAX_ROOMS; i++) {
    for (int y = rooms[i].y; y < rooms[i].y + rooms[i].height; y++) {
      for (int x = rooms[i].x; x < rooms[i].x + rooms[i].width; x++) {
        if (y == rooms[i].y || y == rooms[i].y + rooms[i].height - 1 ||
            x == rooms[i].x || x == rooms[i].x + rooms[i].width - 1) {
          map[y][x].content = '+';
        } else {
          map[y][x].content = '.';
          map[y][x].occupied = false;
        }
      }
    }
  }

  // print the map
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      printf("%c", map[y][x].content);
    }
    printf("\n");
  }

  return 0;
}