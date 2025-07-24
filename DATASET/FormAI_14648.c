//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MAP_WIDTH 100
#define MAX_MAP_HEIGHT 100
#define MAX_ROOMS 20

typedef struct {
  int x;
  int y;
  int width;
  int height;
} Room;

typedef struct {
  Room rooms[MAX_ROOMS];
  int map[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
  int num_rooms;
} GameMap;

void init_map(GameMap *map) {
  // Clear map
  for (int i = 0; i < MAX_MAP_HEIGHT; i++) {
    for (int j = 0; j < MAX_MAP_WIDTH; j++) {
      map->map[i][j] = -1;
    }
  }
  for (int i = 0; i < MAX_ROOMS; i++) {
    map->rooms[i].x = -1;
    map->rooms[i].y = -1;
    map->rooms[i].width = -1;
    map->rooms[i].height = -1;
  }
  map->num_rooms = 0;
}

int has_overlap(Room *r1, Room *r2) {
  if (r1->x < r2->x + r2->width &&
      r1->x + r1->width > r2->x &&
      r1->y < r2->y + r2->height &&
      r1->y + r1->height > r2->y) {
    return 1;
  }
  return 0;
}

int create_room(GameMap *map) {
  if (map->num_rooms == MAX_ROOMS) {
    return 0;
  }
  Room room;
  room.width = rand() % 8 + 4;
  room.height = rand() % 8 + 4;
  room.x = rand() % (MAX_MAP_WIDTH - room.width - 2) + 1;
  room.y = rand() % (MAX_MAP_HEIGHT - room.height - 2) + 1;
  for (int i = 0; i < map->num_rooms; i++) {
    if (has_overlap(&room, &map->rooms[i])) {
      return 0;
    }
  }
  // Add room to map
  for (int i = room.y; i < room.y + room.height; i++) {
    for (int j = room.x; j < room.x + room.width; j++) {
      map->map[i][j] = map->num_rooms;
    }
  }
  map->rooms[map->num_rooms] = room;
  map->num_rooms++;
  return 1;
}

void connect_rooms(GameMap *map) {
  for (int i = 0; i < map->num_rooms; i++) {
    Room *r1 = &map->rooms[i];
    Room *r2 = NULL;
    int r2_index;
    int r2_x, r2_y;
    for (int j = 0; j < map->num_rooms; j++) {
      if (i == j) continue;
      r2 = &map->rooms[j];
      if (r1->x < r2->x) {
        r2_x = r1->x + r1->width;
        if (r2_x < r2->x) continue;
        if (r1->y + (r1->height / 2) == r2->y + (r2->height / 2)) {
          for (int k = r2_x; k < r2->x; k++) {
            map->map[r1->y + (r1->height / 2)][k] = 1;
          }
          break;
        }
      } else if (r1->x > r2->x) {
        r2_x = r2->x + r2->width;
        if (r2_x < r1->x) continue;
        if (r1->y + (r1->height / 2) == r2->y + (r2->height / 2)) {
          for (int k = r1->x + r1->width; k < r2_x; k++) {
            map->map[r1->y + (r1->height / 2)][k] = 1;
          }
          break;
        }
      } else if (r1->y < r2->y) {
        r2_y = r1->y + r1->height;
        if (r2_y < r2->y) continue;
        if (r1->x + (r1->width / 2) == r2->x + (r2->width / 2)) {
          for (int k = r2_y; k < r2->y; k++) {
            map->map[k][r1->x + (r1->width / 2)] = 1;
          }
          break;
        }
      } else if (r1->y > r2->y) {
        r2_y = r2->y + r2->height;
        if (r2_y < r1->y) continue;
        if (r1->x + (r1->width / 2) == r2->x + (r2->width / 2)) {
          for (int k = r1->y + r1->height; k < r2_y; k++) {
            map->map[k][r1->x + (r1->width / 2)] = 1;
          }
          break;
        }
      }
    }
  }
}

void print_map(GameMap *map) {
  for (int i = 0; i < MAX_MAP_HEIGHT; i++) {
    for (int j = 0; j < MAX_MAP_WIDTH; j++) {
      if (map->map[i][j] == -1) {
        printf("#");
      } else if (map->map[i][j] == 1) {
        printf(".");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL));
  GameMap map;
  init_map(&map);
  for (int i = 0; i < 10; i++) {
    create_room(&map);
  }
  connect_rooms(&map);
  print_map(&map);
  return 0;
}