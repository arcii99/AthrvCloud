//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define MAX_ROOM_SIZE 10
#define MIN_ROOM_SIZE 5
#define MAX_ROOMS 12

int map[ROWS][COLS] = {0}; // initialize map to 0's

// function to draw the map
void drawMap() {
  for(int y = 0; y < ROWS; y++) {
    for(int x = 0; x < COLS; x++) {
      switch(map[y][x]) {
        case 0: // empty space
          printf(" ");
          break;
        case 1: // wall
          printf("#");
          break;
        case 2: // floor
          printf(".");
          break;
        default:
          break;
      }
    }
    printf("\n");
  }
}

// check if a room has overlap with existing ones
int checkOverlap(int x, int y, int width, int height) {
  for(int i = y - 1; i < y + height + 1; i++) {
    for(int j = x - 1; j < x + width + 1; j++) {
      if(i < 0 || i >= ROWS || j < 0 || j >= COLS) {
        continue;
      }
      if(map[i][j] == 2) {
        return 1;
      }
    }
  }
  return 0;
}

// create a new room
void createRoom(int x, int y, int width, int height) {
  for(int i = y; i < y + height; i++) {
    for(int j = x; j < x + width; j++) {
      map[i][j] = 2; // fill in with floor tiles
    }
  }
}

// generate the dungeon layout
void generateDungeon() {
  srand(time(NULL)); // set the seed for randomization

  int numRooms = rand() % MAX_ROOMS + 1; // random number of rooms
  int rooms[numRooms][4]; // 2D array to store room positions and sizes

  for(int i = 0; i < numRooms; i++) {
    int x = rand() % (COLS - MAX_ROOM_SIZE - 2) + 1; // randomize x coordinate
    int y = rand() % (ROWS - MAX_ROOM_SIZE - 2) + 1; // randomize y coordinate
    int width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE; // randomize width
    int height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE; // randomize height

    if(checkOverlap(x, y, width, height)) { // check if there's overlap
      i--;
      continue;
    }

    createRoom(x, y, width, height); // create the room
    rooms[i][0] = x;
    rooms[i][1] = y;
    rooms[i][2] = width;
    rooms[i][3] = height;
  }

  // connect rooms with corridors
  for(int i = 0; i < numRooms - 1; i++) {
    int x1 = rooms[i][0] + rooms[i][2] / 2; // center of first room
    int y1 = rooms[i][1] + rooms[i][3] / 2; // center of first room
    int x2 = rooms[i + 1][0] + rooms[i + 1][2] / 2; // center of second room
    int y2 = rooms[i + 1][1] + rooms[i + 1][3] / 2; // center of second room

    while(x1 != x2 || y1 != y2) {
      if(x1 < x2) {
        x1++;
      } else if(x1 > x2) {
        x1--;
      }

      if(y1 < y2) {
        y1++;
      } else if(y1 > y2) {
        y1--;
      }

      if(map[y1][x1] != 2) {
        map[y1][x1] = 2; // create corridor
      }
    }
  }

  // add walls around empty spaces
  for(int y = 0; y < ROWS; y++) {
    for(int x = 0; x < COLS; x++) {
      if(map[y][x] == 2) {
        continue;
      }

      if(y > 0 && map[y - 1][x] == 2) {
        map[y][x] = 1; // create wall to the north
      } else if(x > 0 && map[y][x - 1] == 2) {
        map[y][x] = 1; // create wall to the west
      } else if(y < ROWS - 1 && map[y + 1][x] == 2) {
        map[y][x] = 1; // create wall to the south
      } else if(x < COLS - 1 && map[y][x + 1] == 2) {
        map[y][x] = 1; // create wall to the east
      }
    }
  }
}

int main() {
  generateDungeon();
  drawMap();

  return 0;
}