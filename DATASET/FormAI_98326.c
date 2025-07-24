//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define game constants
#define MAP_WIDTH 50
#define MAP_HEIGHT 30
#define MAX_ROOMS 10
#define MIN_ROOM_WIDTH 3
#define MIN_ROOM_HEIGHT 3
#define MAX_ROOM_WIDTH 10
#define MAX_ROOM_HEIGHT 10
#define WALL '#'
#define FLOOR '.'
#define PLAYER '@'

// Define data structures
typedef struct {
  int x, y, width, height;
} Room;

typedef struct {
  int x, y;
} Position;

// Function prototypes
void initialize_map(char map[MAP_HEIGHT][MAP_WIDTH]);
void generate_rooms(Room rooms[], int num_rooms);
void draw_rooms(char map[MAP_HEIGHT][MAP_WIDTH], Room rooms[], int num_rooms);
void connect_rooms(char map[MAP_HEIGHT][MAP_WIDTH], Room rooms[], int num_rooms);
void place_player(char map[MAP_HEIGHT][MAP_WIDTH], Position *player);
void print_map(char map[MAP_HEIGHT][MAP_WIDTH], Position player);
void move_player(char map[MAP_HEIGHT][MAP_WIDTH], Position *player, char direction);

int main() {
  char map[MAP_HEIGHT][MAP_WIDTH];
  Room rooms[MAX_ROOMS];
  Position player;
  char input;

  // Seed the random number generator
  srand(time(NULL));

  // Initialize the map and generate the rooms
  initialize_map(map);
  generate_rooms(rooms, MAX_ROOMS);

  // Draw the rooms and connect them with corridors
  draw_rooms(map, rooms, MAX_ROOMS);
  connect_rooms(map, rooms, MAX_ROOMS);

  // Place the player character on the map
  place_player(map, &player);

  // Main game loop
  while (1) {
    // Print the map and get the player's next move
    print_map(map, player);
    printf("Enter a direction to move (hjkl): ");
    scanf(" %c", &input);

    // Move the player and update the map if valid
    move_player(map, &player, input);
  }

  return 0;
}

void initialize_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
  int i, j;

  // Set all tiles to walls by default
  for (i = 0; i < MAP_HEIGHT; i++) {
    for (j = 0; j < MAP_WIDTH; j++) {
      map[i][j] = WALL;
    }
  }
}

void generate_rooms(Room rooms[], int num_rooms) {
  int i;
  for (i = 0; i < num_rooms; i++) {
    Room room;
    room.width = rand() % (MAX_ROOM_WIDTH - MIN_ROOM_WIDTH + 1) + MIN_ROOM_WIDTH;
    room.height = rand() % (MAX_ROOM_HEIGHT - MIN_ROOM_HEIGHT + 1) + MIN_ROOM_HEIGHT;
    room.x = rand() % (MAP_WIDTH - room.width - 1) + 1;
    room.y = rand() % (MAP_HEIGHT - room.height - 1) + 1;

    rooms[i] = room;
  }
}

void draw_rooms(char map[MAP_HEIGHT][MAP_WIDTH], Room rooms[], int num_rooms) {
  int i, j, k;
  for (i = 0; i < num_rooms; i++) {
    Room room = rooms[i];
    for (j = room.y; j < room.y + room.height; j++) {
      for (k = room.x; k < room.x + room.width; k++) {
        map[j][k] = FLOOR;
      }
    }
  }
}

void connect_rooms(char map[MAP_HEIGHT][MAP_WIDTH], Room rooms[], int num_rooms) {
  int i;
  for (i = 0; i < num_rooms - 1; i++) {
    Room room1 = rooms[i];
    Room room2 = rooms[i+1];

    Position pos1, pos2;

    // Pick random positions within each room for corridor start and end
    pos1.x = rand() % room1.width + room1.x;
    pos1.y = rand() % room1.height + room1.y;
    pos2.x = rand() % room2.width + room2.x;
    pos2.y = rand() % room2.height + room2.y;

    // Carve out the corridor from one room to another
    int x = pos1.x;
    int y = pos1.y;
    while (x != pos2.x || y != pos2.y) {
      if (x < pos2.x) {
        x++;
      } else if (x > pos2.x) {
        x--;
      } else if (y < pos2.y) {
        y++;
      } else if (y > pos2.y) {
        y--;
      }
      map[y][x] = FLOOR;
    }
  }
}

void place_player(char map[MAP_HEIGHT][MAP_WIDTH], Position *player) {
  int i, j;
  do {
    // Pick a random empty tile for the player to start on
    i = rand() % MAP_HEIGHT;
    j = rand() % MAP_WIDTH;
  } while (map[i][j] != FLOOR);

  // Set the player's position and place them on the map
  player->x = j;
  player->y = i;
  map[i][j] = PLAYER;
}

void print_map(char map[MAP_HEIGHT][MAP_WIDTH], Position player) {
  int i, j;
  for (i = 0; i < MAP_HEIGHT; i++) {
    for (j = 0; j < MAP_WIDTH; j++) {
      // Highlight the player's position
      if (i == player.y && j == player.x) {
        printf("%c%c", PLAYER, PLAYER);
      } else {
        printf("%c ", map[i][j]);
      }
    }
    printf("\n");
  }
}

void move_player(char map[MAP_HEIGHT][MAP_WIDTH], Position *player, char direction) {
  int new_x = player->x;
  int new_y = player->y;

  // Calculate the new position based on the player's chosen direction
  switch (direction) {
    case 'h':
      new_x--;
      break;
    case 'j':
      new_y++;
      break;
    case 'k':
      new_y--;
      break;
    case 'l':
      new_x++;
      break;
  }

  // Check if the new position is within bounds and on a floor tile
  if (new_x >= 0 && new_x < MAP_WIDTH &&
      new_y >= 0 && new_y < MAP_HEIGHT &&
      map[new_y][new_x] == FLOOR) {
    // Update the player's position and move them on the map
    map[player->y][player->x] = FLOOR;
    player->x = new_x;
    player->y = new_y;
    map[player->y][player->x] = PLAYER;
  }
}