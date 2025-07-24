//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20
#define MAX_ROOMS 6
#define MIN_ROOM_SIZE 4
#define MAX_ROOM_SIZE 8

char dungeon[WIDTH][HEIGHT];

struct Room {
  int left;
  int top;
  int width;
  int height;
};
typedef struct Room Room;

void initDungeon() {
  int i, j;
  for(i = 0; i < WIDTH; i++) {
    for(j = 0; j < HEIGHT; j++) {
      dungeon[i][j] = '.';
    }
  }
}

void drawDungeon() {
  int i, j;
  for(i = 0; i < WIDTH; i++) {
    for(j = 0; j < HEIGHT; j++) {
      printf("%c", dungeon[i][j]);
    }
    printf("\n");
  }
}

void carveRoom(Room room) {
  int i, j;
  for(i = room.left; i < room.left + room.width; i++) {
    for(j = room.top; j < room.top + room.height; j++) {
      dungeon[i][j] = ' ';
    }
  }
}

void carveCorridor(int x1, int y1, int x2, int y2) {
  int i;
  if(x1 == x2) {
    for(i = y1; i <= y2; i++) {
      dungeon[x1][i] = '#';
    }
  } else if(y1 == y2) {
    for(i = x1; i <= x2; i++) {
      dungeon[i][y1] = '#';
    }
  } else {
    printf("ERROR: tried to carve non-axial corridor\n");
  }
}

int isOverlapping(Room a, Room b) {
  return 
    a.left <= b.left + b.width &&
    a.left + a.width >= b.left &&
    a.top <= b.top + b.height &&
    a.top + a.height >= b.top;
}

int canPlaceRoom(Room room) {
  int i, j;
  if(room.left < 1 || room.left + room.width > WIDTH - 2 ||
     room.top < 1 || room.top + room.height > HEIGHT - 2) {
    return 0;
  }
  for(i = room.left - 1; i < room.left + room.width + 1; i++) {
    for(j = room.top - 1; j < room.top + room.height + 1; j++) {
      if(dungeon[i][j] == ' ') {
        return 0;
      }
    }
  }
  for(i = 0; i < MAX_ROOMS; i++) {
    if(isOverlapping(room, (Room){i, i, i, i})) {
      return 0;
    }
  }
  return 1;
}

Room getRandomRoom() {
  int left = rand() % (WIDTH - MAX_ROOM_SIZE - 2) + 1;
  int top = rand() % (HEIGHT - MAX_ROOM_SIZE - 2) + 1;
  int width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
  int height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE + 1) + MIN_ROOM_SIZE;
  return (Room){left, top, width, height};
}

void placeRooms() {
  int i, tries = 100;
  for(i = 0; i < MAX_ROOMS && tries > 0; tries--) {
    Room room = getRandomRoom();
    if(canPlaceRoom(room)) {
      carveRoom(room);
      i++;
      tries = 100;
    }
  }
}

int main() {
  srand(time(NULL));
  initDungeon();
  placeRooms();
  drawDungeon();
  return 0;
}