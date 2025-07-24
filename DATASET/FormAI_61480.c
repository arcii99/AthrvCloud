//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 30
#define MAX_ROOMS 10
#define MIN_ROOM_WIDTH 4
#define MIN_ROOM_HEIGHT 4
#define MAX_ROOM_WIDTH 12
#define MAX_ROOM_HEIGHT 12
#define MAX_MONSTERS 5

typedef struct {
  int x, y;
} Position;

typedef struct {
  Position pos;
  char symbol;
  bool is_visible;
  bool is_walkable;
} Tile;

typedef struct {
  Position pos;
  int width, height;
} Room;

typedef struct {
  Position pos;
  char symbol;
  int max_hp;
  int hp;
} Monster;

Tile map[MAP_HEIGHT][MAP_WIDTH];
Room rooms[MAX_ROOMS];
Monster monsters[MAX_MONSTERS];

void initialize_map() {
  for(int y = 0; y < MAP_HEIGHT; y++) {
    for(int x = 0; x < MAP_WIDTH; x++) {
      map[y][x].pos.x = x;
      map[y][x].pos.y = y;
      map[y][x].symbol = '#';
      map[y][x].is_visible = false;
      map[y][x].is_walkable = false;
    }
  }
}

void create_rooms() {
  int num_rooms = rand() % MAX_ROOMS + 1;
  for(int i = 0; i < num_rooms; i++) {
    int room_width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
    int room_height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
    int room_x = rand() % (MAP_WIDTH - room_width - 1) + 1;
    int room_y = rand() % (MAP_HEIGHT - room_height - 1) + 1;
    Room room = { .pos.x = room_x, .pos.y = room_y, .width = room_width, .height = room_height };
    bool can_create_room = true;
    for(int j = 0; j < i; j++) {
      if((room.pos.x < rooms[j].pos.x + rooms[j].width) &&
         (room.pos.x + room.width > rooms[j].pos.x) &&
         (room.pos.y < rooms[j].pos.y + rooms[j].height) &&
         (room.pos.y + room.height > rooms[j].pos.y)) {
        can_create_room = false;
        break;
      }
    }
    if(can_create_room) {
      for(int y = room.pos.y; y < room.pos.y + room.height; y++) {
        for(int x = room.pos.x; x < room.pos.x + room.width; x++) {
          map[y][x].symbol = '.';
          map[y][x].is_walkable = true;
        }
      }
      rooms[i] = room;
    }
  }
}

void populate_monsters() {
  int num_monsters = rand() % MAX_MONSTERS + 1;
  for(int i = 0; i < num_monsters; i++) {
    int x, y;
    do {
      int room_index = rand() % MAX_ROOMS;
      x = rand() % rooms[room_index].width + rooms[room_index].pos.x;
      y = rand() % rooms[room_index].height + rooms[room_index].pos.y;
    } while(!map[y][x].is_walkable);
    monsters[i] = (Monster) { .pos.x = x, .pos.y = y, .symbol = 'M', .max_hp = 10, .hp = 10 };
  }
}

void draw_map() {
  for(int y = 0; y < MAP_HEIGHT; y++) {
    for(int x = 0; x < MAP_WIDTH; x++) {
      printf("%c", map[y][x].symbol);
    }
    printf("\n");
  }
}

bool is_player_position_valid(int x, int y) {
  return (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT && map[y][x].is_walkable);
}

bool is_monster_position_valid(int x, int y) {
  return (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT && map[y][x].is_walkable);
}

void move_monster(int index) {
  int dx = rand() % 3 - 1;
  int dy = rand() % 3 - 1;
  if(dx == 0 && dy == 0) {
    return;
  }
  int new_x = monsters[index].pos.x + dx;
  int new_y = monsters[index].pos.y + dy;
  if(!is_monster_position_valid(new_x, new_y)) {
    return;
  }
  monsters[index].pos.x = new_x;
  monsters[index].pos.y = new_y;
}

void perform_game_loop() {
  int player_x = rooms[0].pos.x + rooms[0].width / 2;
  int player_y = rooms[0].pos.y + rooms[0].height / 2;
  bool win = false;
  while(true) {
    for(int i = 0; i < MAX_MONSTERS; i++) {
      if(monsters[i].hp > 0) {
        move_monster(i);
        if(player_x == monsters[i].pos.x && player_y == monsters[i].pos.y) {
          printf("You were attacked by a monster!\n");
        }
      } else {
        printf("You defeated the monster!\n");
      }
    }
    draw_map();
    char input = getchar();
    if(input == 'q') {
      break;
    }
    int new_player_x = player_x;
    int new_player_y = player_y;
    if(input == 'h') {
      new_player_x--;
    } else if(input == 'j') {
      new_player_y++;
    } else if(input == 'k') {
      new_player_y--;
    } else if(input == 'l') {
      new_player_x++;
    }
    if(is_player_position_valid(new_player_x, new_player_y)) {
      player_x = new_player_x;
      player_y = new_player_y;
    }
    if(player_x == rooms[MAX_ROOMS - 1].pos.x + rooms[MAX_ROOMS - 1].width / 2 &&
       player_y == rooms[MAX_ROOMS - 1].pos.y + rooms[MAX_ROOMS - 1].height / 2) {
      win = true;
      break;
    }
  }
  if(win) {
    printf("Congratulations, you won the game!\n");
  } else {
    printf("Game over!\n");
  }
}

int main() {
  srand(time(NULL));
  initialize_map();
  create_rooms();
  populate_monsters();
  perform_game_loop();
  return 0;
}