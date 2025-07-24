//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAP_HEIGHT 25
#define MAP_WIDTH 80
#define MAX_ROOMS 10
#define MAX_ROOM_SIZE 15
#define MIN_ROOM_SIZE 5
#define PLAYER_CHAR '@'
#define FLOOR_CHAR '.'
#define WALL_CHAR '#'

// Define structs
struct room {
  int x;
  int y;
  int width;
  int height;
};

// Declare functions
void init_map(char map[MAP_HEIGHT][MAP_WIDTH]);
void print_map(char map[MAP_HEIGHT][MAP_WIDTH]);
void place_player(char map[MAP_HEIGHT][MAP_WIDTH], int *player_x, int *player_y);
void generate_rooms(struct room rooms[], int *num_rooms);
void connect_rooms(struct room rooms[], int num_rooms, char map[MAP_HEIGHT][MAP_WIDTH]);
void place_rooms(struct room rooms[], int num_rooms, char map[MAP_HEIGHT][MAP_WIDTH]);

int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Set up variables
  char map[MAP_HEIGHT][MAP_WIDTH];
  int player_x, player_y;
  struct room rooms[MAX_ROOMS];
  int num_rooms = 0;

  // Generate map
  init_map(map);
  place_player(map, &player_x, &player_y);
  generate_rooms(rooms, &num_rooms);
  place_rooms(rooms, num_rooms, map);
  connect_rooms(rooms, num_rooms, map);

  // Print map
  print_map(map);

  return 0;
}

/**
 * Initialize the map with walls and floors
 */
void init_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
  int row, col;

  for (row = 0; row < MAP_HEIGHT; row++) {
    for (col = 0; col < MAP_WIDTH; col++) {
      if (row == 0 || col == 0 || row == MAP_HEIGHT - 1 || col == MAP_WIDTH - 1) {
        // Place walls on the edge of the map
        map[row][col] = WALL_CHAR;
      } else {
        // Randomly place floors
        if (rand() % 100 < 40) {
          map[row][col] = FLOOR_CHAR;
        } else {
          map[row][col] = WALL_CHAR;
        }
      }
    }
  }
}

/**
 * Print the map to the console
 */
void print_map(char map[MAP_HEIGHT][MAP_WIDTH]) {
  int row, col;

  for (row = 0; row < MAP_HEIGHT; row++) {
    for (col = 0; col < MAP_WIDTH; col++) {
      putchar(map[row][col]);
    }

    putchar('\n');
  }
}

/**
 * Place the player randomly on the map
 */
void place_player(char map[MAP_HEIGHT][MAP_WIDTH], int *player_x, int *player_y) {
  int row, col;

  do {
    row = rand() % (MAP_HEIGHT - 2) + 1;
    col = rand() % (MAP_WIDTH - 2) + 1;
  } while (map[row][col] != FLOOR_CHAR);

  map[row][col] = PLAYER_CHAR;
  *player_x = col;
  *player_y = row;
}

/**
 * Generate rooms randomly on the map
 */
void generate_rooms(struct room rooms[], int *num_rooms) {
  int i;

  *num_rooms = rand() % MAX_ROOMS + 1;

  for (i = 0; i < *num_rooms; i++) {
    rooms[i].width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
    rooms[i].height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
    rooms[i].x = rand() % (MAP_WIDTH - 2 - rooms[i].width) + 1;
    rooms[i].y = rand() % (MAP_HEIGHT - 2 - rooms[i].height) + 1;
  }
}

/**
 * Place rooms on the map
 */
void place_rooms(struct room rooms[], int num_rooms, char map[MAP_HEIGHT][MAP_WIDTH]) {
  int i, j, row, col;

  for (i = 0; i < num_rooms; i++) {
    for (row = rooms[i].y; row < rooms[i].y + rooms[i].height; row++) {
      for (col = rooms[i].x; col < rooms[i].x + rooms[i].width; col++) {
        map[row][col] = FLOOR_CHAR;
      }
    }
  }
}

/**
 * Connect rooms with corridors
 */
void connect_rooms(struct room rooms[], int num_rooms, char map[MAP_HEIGHT][MAP_WIDTH]){
  int i, j, row, col, dest_row, dest_col;

  for (i = 0; i < num_rooms; i++) {
    for (j = 0; j < num_rooms; j++) {
      if (i == j) {
        continue;
      }

      if (rand() % 2) {
        // Connect vertically first
        if (rooms[i].y < rooms[j].y) {
          row = rooms[i].y + rooms[i].height;
          dest_row = rooms[j].y;
        } else {
          row = rooms[j].y + rooms[j].height;
          dest_row = rooms[i].y;
        }

        col = rooms[i].x + (rooms[i].width / 2);
        dest_col = rooms[j].x + (rooms[j].width / 2);

        while (row != dest_row) {
          if (map[row][col] == WALL_CHAR) {
            map[row][col] = FLOOR_CHAR;
          }

          if (row < dest_row) {
            row++;
          } else {
            row--;
          }
        }

        // Connect horizontally
        while (col != dest_col) {
          if (map[row][col] == WALL_CHAR) {
            map[row][col] = FLOOR_CHAR;
          }

          if (col < dest_col) {
            col++;
          } else {
            col--;
          }
        }
      } else {
        // Connect horizontally first
        if (rooms[i].x < rooms[j].x) {
          col = rooms[i].x + rooms[i].width;
          dest_col = rooms[j].x;
        } else {
          col = rooms[j].x + rooms[j].width;
          dest_col = rooms[i].x;
        }

        row = rooms[i].y + (rooms[i].height / 2);
        dest_row = rooms[j].y + (rooms[j].height / 2);

        while (col != dest_col) {
          if (map[row][col] == WALL_CHAR) {
            map[row][col] = FLOOR_CHAR;
          }

          if (col < dest_col) {
            col++;
          } else {
            col--;
          }
        }

        // Connect vertically
        while (row != dest_row) {
          if (map[row][col] == WALL_CHAR) {
            map[row][col] = FLOOR_CHAR;
          }

          if (row < dest_row) {
            row++;
          } else {
            row--;
          }
        }
      }
    }
  }
}