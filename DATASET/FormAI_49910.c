//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20
#define MAX_ROOMS 10
#define MIN_ROOM_WIDTH 4
#define MIN_ROOM_HEIGHT 3
#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 8
#define MAX_MONSTERS 5

typedef struct {
  int x;
  int y;
  int width;
  int height;
} Room;

typedef struct {
  int x;
  int y;
  char symbol;
} Monster;

typedef struct {
  char tile;
  char symbol;
  int explored;
} Tile;

Tile map[MAP_HEIGHT][MAP_WIDTH];
Room rooms[MAX_ROOMS];
int num_rooms = 0;
Monster monsters[MAX_MONSTERS];
int num_monsters = 0;
int player_x = 0;
int player_y = 0;
int level = 1;

void generate_map();
void draw_map();
void place_rooms();
void dig_room(int room_index);
void place_player();
void place_monsters();
int move_player(int dx, int dy);
void move_monsters();
int check_collision(int x, int y);

int main() {
  srand(time(NULL));
  
  generate_map();
  place_player();
  place_monsters();
  
  while(1) {
    draw_map();
    
    int dx = 0;
    int dy = 0;
    
    printf("Enter a direction (w,a,s,d): ");
    char input = getchar();
    getchar(); // remove newline
    switch(input) {
      case 'w':
        dy = -1;
        break;
      case 'a':
        dx = -1;
        break;
      case 's':
        dy = 1;
        break;
      case 'd':
        dx = 1;
        break;
    }
    
    int result = move_player(dx, dy);
    if(result == 1) {
      printf("You win!\n");
      break;
    } else if(result == -1) {
      printf("You lose!\n");
      break;
    }
    
    move_monsters();
  }
  
  return 0;
}

void generate_map() {
  // initialize map
  for(int y = 0; y < MAP_HEIGHT; y++) {
    for(int x = 0; x < MAP_WIDTH; x++) {
      map[y][x].tile = '#';
      map[y][x].symbol = ' ';
      map[y][x].explored = 0;
    }
  }
  
  // place rooms
  place_rooms();
  
  // dig out rooms
  for(int i = 0; i < num_rooms; i++) {
    dig_room(i);
  }
}

void place_rooms() {
  for(int i = 0; i < MAX_ROOMS; i++) {
    int x = rand() % (MAP_WIDTH - MAX_ROOM_WIDTH - 1) + 1;
    int y = rand() % (MAP_HEIGHT - MAX_ROOM_HEIGHT - 1) + 1;
    int width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
    int height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
    
    // check for collision with other rooms
    int collision = 0;
    for(int j = 0; j < num_rooms; j++) {
      if(x < rooms[j].x + rooms[j].width &&
         x + width > rooms[j].x &&
         y < rooms[j].y + rooms[j].height &&
         y + height > rooms[j].y) {
        collision = 1;
        break;
      }
    }
    if(collision) continue;
    
    // add room
    rooms[num_rooms].x = x;
    rooms[num_rooms].y = y;
    rooms[num_rooms].width = width;
    rooms[num_rooms].height = height;
    num_rooms++;
    
    // connect to previous room
    if(num_rooms > 1) {
      int prev_x = rooms[num_rooms-2].x + rooms[num_rooms-2].width/2;
      int prev_y = rooms[num_rooms-2].y + rooms[num_rooms-2].height/2;
      int curr_x = rooms[num_rooms-1].x + rooms[num_rooms-1].width/2;
      int curr_y = rooms[num_rooms-1].y + rooms[num_rooms-1].height/2;
      while(prev_x != curr_x) {
        if(prev_x < curr_x) prev_x++;
        else prev_x--;
        map[prev_y][prev_x].tile = '.';
      }
      while(prev_y != curr_y) {
        if(prev_y < curr_y) prev_y++;
        else prev_y--;
        map[prev_y][prev_x].tile = '.';
      }
    }
  }
}

void dig_room(int room_index) {
  for(int y = rooms[room_index].y; y < rooms[room_index].y + rooms[room_index].height; y++) {
    for(int x = rooms[room_index].x; x < rooms[room_index].x + rooms[room_index].width; x++) {
      if(y == rooms[room_index].y || y == rooms[room_index].y + rooms[room_index].height - 1 ||
         x == rooms[room_index].x || x == rooms[room_index].x + rooms[room_index].width - 1) {
        map[y][x].tile = '#';
      } else {
        map[y][x].tile = '.';
      }
    }
  }
}

void place_player() {
  int room_index = rand() % num_rooms;
  player_x = rooms[room_index].x + rooms[room_index].width/2;
  player_y = rooms[room_index].y + rooms[room_index].height/2;
  map[player_y][player_x].symbol = '@';
}

void place_monsters() {
  for(int i = 0; i < MAX_MONSTERS; i++) {
    monsters[i].x = -1;
    monsters[i].y = -1;
    monsters[i].symbol = 'm';
  }
  num_monsters = rand() % (MAX_MONSTERS - num_rooms + 1) + num_rooms;
  for(int i = 0; i < num_monsters; i++) {
    int room_index = rand() % num_rooms;
    int x = rooms[room_index].x + rand() % rooms[room_index].width;
    int y = rooms[room_index].y + rand() % rooms[room_index].height;
    while(check_collision(x, y)) {
      x = rooms[room_index].x + rand() % rooms[room_index].width;
      y = rooms[room_index].y + rand() % rooms[room_index].height;
    }
    monsters[i].x = x;
    monsters[i].y = y;
    map[y][x].symbol = monsters[i].symbol;
  }
}

int move_player(int dx, int dy) {
  int new_x = player_x + dx;
  int new_y = player_y + dy;
  if(map[new_y][new_x].tile == '#') {
    return 0;
  } else if(map[new_y][new_x].symbol != ' ') {
    for(int i = 0; i < num_monsters; i++) {
      if(monsters[i].x == new_x && monsters[i].y == new_y) {
        printf("You attacked a monster!\n");
        int damage = rand() % level + 1;
        monsters[i].symbol = 'X';
        if(damage > level/2) {
          printf("You killed the monster!\n");
          map[new_y][new_x].symbol = ' ';
          return 0;
        } else {
          printf("You wounded the monster!\n");
          return 0;
        }
      }
    }
    return -1;
  } else {
    map[player_y][player_x].symbol = ' ';
    player_x += dx;
    player_y += dy;
    map[player_y][player_x].symbol = '@';
    map[player_y][player_x].explored = 1;
    if(rand() % 10 < level) {
      printf("You found a treasure!\n");
      level++;
      generate_map();
      place_player();
      place_monsters();
    }
    if(player_x == MAP_WIDTH-1) {
      return 1;
    }
    return 0;
  }
}

void move_monsters() {
  for(int i = 0; i < num_monsters; i++) {
    if(monsters[i].symbol == 'X') continue;
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    int new_x = monsters[i].x + dx;
    int new_y = monsters[i].y + dy;
    if(map[new_y][new_x].tile == '#' || check_collision(new_x, new_y)) continue;
    map[monsters[i].y][monsters[i].x].symbol = ' ';
    monsters[i].x = new_x;
    monsters[i].y = new_y;
    map[monsters[i].y][monsters[i].x].symbol = monsters[i].symbol;
  }
}

int check_collision(int x, int y) {
  if(x == player_x && y == player_y) return 1;
  for(int i = 0; i < num_monsters; i++) {
    if(x == monsters[i].x && y == monsters[i].y) return 1;
  }
  return 0;
}

void draw_map() {
  system("clear");
  printf("Level %d\n", level);
  for(int y = 0; y < MAP_HEIGHT; y++) {
    for(int x = 0; x < MAP_WIDTH; x++) {
      if(map[y][x].explored) {
        printf("%c", map[y][x].symbol);
      } else {
        printf("%c", map[y][x].tile);
      }
    }
    printf("\n");
  }
}