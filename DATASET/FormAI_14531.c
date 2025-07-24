//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_HEIGHT 20
#define MAP_WIDTH 40
#define MAX_ROOMS 6
#define ROOM_MIN_HEIGHT 3
#define ROOM_MAX_HEIGHT 7
#define ROOM_MIN_WIDTH 3
#define ROOM_MAX_WIDTH 10

int map[MAP_HEIGHT][MAP_WIDTH];
int num_rooms;

void print_map() {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      if (map[y][x] == 0) printf(".");
      else printf("#");
    }
    printf("\n");
  }
}

void generate_map() {
  srand(time(NULL)); // Seed the random number generator
  // Set all map cells to 0 (empty)
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      map[y][x] = 0;
    }
  }
  // Generate rooms
  num_rooms = 0;
  while (num_rooms < MAX_ROOMS) {
    int room_x = rand() % (MAP_WIDTH - ROOM_MAX_WIDTH - 1) + 1;
    int room_y = rand() % (MAP_HEIGHT - ROOM_MAX_HEIGHT - 1) + 1;
    int room_width = rand() % (ROOM_MAX_WIDTH - ROOM_MIN_WIDTH + 1) + ROOM_MIN_WIDTH;
    int room_height = rand() % (ROOM_MAX_HEIGHT - ROOM_MIN_HEIGHT + 1) + ROOM_MIN_HEIGHT;
    // Check if the room overlaps with any other room
    int overlap = 0;
    for (int y = room_y - 1; y <= room_y + room_height; y++) {
      for (int x = room_x - 1; x <= room_x + room_width; x++) {
        if (map[y][x] != 0) overlap = 1;
      }
    }
    // If the room doesn't overlap, create it.
    if (!overlap) {
      for (int y = room_y; y < room_y + room_height; y++) {
        for (int x = room_x; x < room_x + room_width; x++) {
          map[y][x] = 1;
        }
      }
      num_rooms++;
    }
  }
  // Connect rooms with corridors
  for (int i = 0; i < num_rooms - 1; i++) {
    int start_x = rand() % (ROOM_MAX_WIDTH - ROOM_MIN_WIDTH + 1) + ROOM_MIN_WIDTH;
    int start_y = rand() % (ROOM_MAX_HEIGHT - ROOM_MIN_HEIGHT + 1) + ROOM_MIN_HEIGHT;
    int end_x = rand() % (ROOM_MAX_WIDTH - ROOM_MIN_WIDTH + 1) + ROOM_MIN_WIDTH;
    int end_y = rand() % (ROOM_MAX_HEIGHT - ROOM_MIN_HEIGHT + 1) + ROOM_MIN_HEIGHT;
    int x = i % 2 == 0 ? start_x : end_x;
    int y = i % 2 == 0 ? start_y : end_y;
    while (map[y][x] == 0) {
      if (x < MAP_WIDTH/2) {
        x++;
      } else {
        x--;
      }
      if (y < MAP_HEIGHT/2) {
        y++;
      } else {
        y--;
      }
      map[y][x] = 1;
    }
  }
}

int main() {
  generate_map();
  print_map();
  return 0;
}