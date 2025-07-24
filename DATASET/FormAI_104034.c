//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define ROOM_MAX_SIZE 8
#define ROOM_MIN_SIZE 4
#define MAX_ROOMS 5

typedef struct {
  int x, y, width, height;
} Room;

typedef struct {
  int x, y;
  char character;
} Entity;

typedef struct {
  char tiles[MAP_SIZE][MAP_SIZE];
  Room *rooms;
  Entity *player;
  int num_rooms;
} GameMap;

void init_map(GameMap *map);
void create_rooms(GameMap *map);
void place_entities(GameMap *map);
void draw_map(GameMap *map);
void move_player(GameMap *map, int dx, int dy);
int is_entity_at(GameMap *map, int x, int y);
int is_wall_at(GameMap *map, int x, int y);

int main() {
  GameMap map;
  srand(time(NULL));
  init_map(&map);
  create_rooms(&map);
  place_entities(&map);

  while (1) {
    system("clear");
    draw_map(&map);

    char input;
    scanf(" %c", &input);
    int dx = 0, dy = 0;
    switch (input) {
      case 'w': dy = -1; break;
      case 's': dy = 1; break;
      case 'a': dx = -1; break;
      case 'd': dx = 1; break;
      case 'q': goto end_program;
    }

    move_player(&map, dx, dy);
  }

  end_program:
  printf("\nThanks for playing!\n");
  return 0;
}

void init_map(GameMap *map) {
  for (int y = 0; y < MAP_SIZE; ++y) {
    for (int x = 0; x < MAP_SIZE; ++x) {
      map->tiles[y][x] = '#';
    }
  }
  map->rooms = malloc(sizeof(Room) * MAX_ROOMS);
  map->player = malloc(sizeof(Entity));
}

void create_rooms(GameMap *map) {
  map->num_rooms = 0;
  for (int r = 0; r < MAX_ROOMS; ++r) {
    Room room;
    room.width = ROOM_MIN_SIZE + rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1);
    room.height = ROOM_MIN_SIZE + rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1);
    room.x = rand() % (MAP_SIZE - room.width - 1) + 1;
    room.y = rand() % (MAP_SIZE - room.height - 1) + 1;
    for (int y = room.y; y < room.y + room.height; ++y) {
      for (int x = room.x; x < room.x + room.width; ++x) {
        map->tiles[y][x] = '.';
      }
    }
    map->rooms[r] = room;
    ++map->num_rooms;
  }
}

void place_entities(GameMap *map) {
  for (int y = 0; y < MAP_SIZE; ++y) {
    for (int x = 0; x < MAP_SIZE; ++x) {
      if (map->tiles[y][x] == '.') {
        if (rand() % 100 < 20 && !is_entity_at(map, x, y)) {
          Entity ent;
          ent.x = x;
          ent.y = y;
          ent.character = '@';
          map->player = &ent;
        } else if (rand() % 100 < 50 && !is_entity_at(map, x, y)) {
          Entity ent;
          ent.x = x;
          ent.y = y;
          ent.character = 'Z';
        }
      }
    }
  }
}

void draw_map(GameMap *map) {
  for (int y = 0; y < MAP_SIZE; ++y) {
    for (int x = 0; x < MAP_SIZE; ++x) {
      int is_entity = 0;
      for (int e = 0; e < map->num_rooms + 1; ++e) {
        if ((map->player->x == x && map->player->y == y && e == map->num_rooms) ||
            (is_entity_at(map, x, y) && e < map->num_rooms && x >= map->rooms[e].x && y >= map->rooms[e].y && x < map->rooms[e].x + map->rooms[e].width && y < map->rooms[e].y + map->rooms[e].height)) {
          printf("%c", map->player->character);
          is_entity = 1;
          break;
        }
      }
      if (!is_entity) printf("%c", map->tiles[y][x]);
    }
    printf("\n");
  }
}

void move_player(GameMap *map, int dx, int dy) {
  int x = map->player->x + dx;
  int y = map->player->y + dy;
  if (is_wall_at(map, x, y)) return;
  if (is_entity_at(map, x, y)) {
    for (int e = 0; e < map->num_rooms + 1; ++e) {
      if (x == map->rooms[e].x && y == map->rooms[e].y && e < map->num_rooms) {
        printf("\nYou entered room %d!\n", e + 1);
        return;
      }
      if (x == map->player->x && y == map->player->y && e == map->num_rooms) {
        printf("\nYou died!\n");
        goto end_program;
      }
    }
  }
  map->player->x = x;
  map->player->y = y;
  return;

  end_program:
  exit(0);
}

int is_entity_at(GameMap *map, int x, int y) {
  if (map->player->x == x && map->player->y == y) return 1;
  for (int e = 0; e < map->num_rooms; ++e) {
    if (x >= map->rooms[e].x && y >= map->rooms[e].y && x < map->rooms[e].x + map->rooms[e].width && y < map->rooms[e].y + map->rooms[e].height) return 1;
  }
  return 0;
}

int is_wall_at(GameMap *map, int x, int y) {
  return map->tiles[y][x] == '#';
}