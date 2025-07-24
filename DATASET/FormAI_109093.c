//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 50
#define MAX_Y 20
#define MAX_ROOMS 10

typedef struct {
  int x, y, width, height;
} Room;

typedef struct {
  int x, y;
} Point;

void print_map(char map[MAX_Y][MAX_X]) {
  int i, j;
  for (i = 0; i < MAX_Y; i++) {
    for (j = 0; j < MAX_X; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

void carve_h_tunnel(int x1, int x2, int y, char map[MAX_Y][MAX_X]) {
  int i;
  for (i = x1; i <= x2; i++) {
    map[y][i] = ' ';
  }
}

void carve_v_tunnel(int y1, int y2, int x, char map[MAX_Y][MAX_X]) {
  int i;
  for (i = y1; i <= y2; i++) {
    map[i][x] = ' ';
  }
}

void carve_room(Room room, char map[MAX_Y][MAX_X]) {
  int i, j;
  for (i = room.y; i < room.y + room.height; i++) {
    for (j = room.x; j < room.x + room.width; j++) {
      map[i][j] = ' ';
    }
  }
}

int intersects(Room room1, Room room2) {
  return room1.x <= room2.x + room2.width &&
         room1.x + room1.width >= room2.x &&
         room1.y <= room2.y + room2.height &&
         room1.y + room1.height >= room2.y;
}

void generate_rooms(Room rooms[MAX_ROOMS], int num_rooms) {
  int i, j, r1, r2, room_count = 0, tries = 0;
  while (room_count < num_rooms && tries < 100) {
    Room new_room = {
      .x = rand() % (MAX_X - 4) + 2,
      .y = rand() % (MAX_Y - 4) + 2,
      .width = rand() % 6 + 5,
      .height = rand() % 4 + 3
    };
    int intersects_other = 0;
    for (i = 0; i < room_count; i++) {
      if (intersects(new_room, rooms[i])) {
        intersects_other = 1;
        break;
      }
    }
    if (!intersects_other) {
      rooms[room_count++] = new_room;
    }
    tries++;
  }
}

void generate_map(char map[MAX_Y][MAX_X]) {
  int i, j, room_count = 0;
  Room rooms[MAX_ROOMS];
  for (i = 0; i < MAX_Y; i++) {
    for (j = 0; j < MAX_X; j++) {
      map[i][j] = '#';
    }
  }
  generate_rooms(rooms, MAX_ROOMS);
  for (i = 0; i < MAX_ROOMS; i++) {
    carve_room(rooms[i], map);
  }
  for (i = 0; i < MAX_ROOMS - 1; i++) {
    Point center1 = {
      .x = (rooms[i].x + rooms[i].width) / 2,
      .y = (rooms[i].y + rooms[i].height) / 2
    };
    Point center2 = {
      .x = (rooms[i + 1].x + rooms[i + 1].width) / 2,
      .y = (rooms[i + 1].y + rooms[i + 1].height) / 2
    };
    if (rand() % 2) {
      carve_h_tunnel(center1.x, center2.x, center1.y, map);
      carve_v_tunnel(center1.y, center2.y, center2.x, map);
    } else {
      carve_v_tunnel(center1.y, center2.y, center1.x, map);
      carve_h_tunnel(center1.x, center2.x, center2.y, map);
    }
  }
}

int main() {
  srand(time(NULL));
  char map[MAX_Y][MAX_X];
  generate_map(map);
  print_map(map);
  return 0;
}