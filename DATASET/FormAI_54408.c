//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAPSIZE 20
#define ROOMSIZE_MIN 5
#define ROOMSIZE_MAX 8
#define NUM_ROOMS 5
#define FLOOR_CHAR '.'
#define WALL_CHAR '#'
#define PLAYER_CHAR '@'

struct Room {
  int x, y, width, height;
};

char map[MAPSIZE][MAPSIZE];
struct Room rooms[NUM_ROOMS];
int player_x, player_y;

void init_map() {
  for (int i = 0; i < MAPSIZE; i++) {
    for (int j = 0; j < MAPSIZE; j++) {
      map[i][j] = WALL_CHAR;
    }
  }
}

void print_map() {
  for (int i = 0; i < MAPSIZE; i++) {
    for (int j = 0; j < MAPSIZE; j++) {
      if (i == player_y && j == player_x) {
        printf("%c ", PLAYER_CHAR);
      } else {
        printf("%c ", map[i][j]);
      }
    }
    printf("\n");
  }
}

void gen_room(int index) {
  int width = rand() % (ROOMSIZE_MAX - ROOMSIZE_MIN + 1) + ROOMSIZE_MIN;
  int height = rand() % (ROOMSIZE_MAX - ROOMSIZE_MIN + 1) + ROOMSIZE_MIN;
  int x = rand() % (MAPSIZE - width - 1) + 1;
  int y = rand() % (MAPSIZE - height - 1) + 1;

  for (int i = y; i < y + height; i++) {
    for (int j = x; j < x + width; j++) {
      map[i][j] = FLOOR_CHAR;
    }
  }

  rooms[index] = (struct Room) { x, y, width, height };
}

void gen_rooms() {
  for (int i = 0; i < NUM_ROOMS; i++) {
    gen_room(i);
  }
}

void connect_rooms() {
  for (int i = 0; i < NUM_ROOMS - 1; i++) {
    int x1 = rooms[i].x + rooms[i].width / 2;
    int y1 = rooms[i].y + rooms[i].height / 2;
    int x2 = rooms[i + 1].x + rooms[i + 1].width / 2;
    int y2 = rooms[i + 1].y + rooms[i + 1].height / 2;

    while (x1 != x2) {
      if (x1 < x2) {
        x1++;
      } else {
        x1--;
      }
      map[y1][x1] = FLOOR_CHAR;
    }

    while (y1 != y2) {
      if (y1 < y2) {
        y1++;
      } else {
        y1--;
      }
      map[y1][x1] = FLOOR_CHAR;
    }
  }
}

void place_player() {
  int room_index = rand() % NUM_ROOMS;
  player_x = rooms[room_index].x + rooms[room_index].width / 2;
  player_y = rooms[room_index].y + rooms[room_index].height / 2;
  map[player_y][player_x] = PLAYER_CHAR;
}

int main() {
  srand(time(NULL));

  init_map();
  gen_rooms();
  connect_rooms();
  place_player();

  printf("Welcome to the Rogue-like Game!\n\n");
  
  while (1) {
    print_map();

    char input;
    printf("\nMove with WASD, Q to quit: ");
    scanf(" %c", &input);

    switch (input) {
      case 'w':
        if (map[player_y - 1][player_x] != WALL_CHAR) {
          map[player_y][player_x] = FLOOR_CHAR;
          player_y--;
        }
        break;
      case 'a':
        if (map[player_y][player_x - 1] != WALL_CHAR) {
          map[player_y][player_x] = FLOOR_CHAR;
          player_x--;
        }
        break;
      case 's':
        if (map[player_y + 1][player_x] != WALL_CHAR) {
          map[player_y][player_x] = FLOOR_CHAR;
          player_y++;
        }
        break;
      case 'd':
        if (map[player_y][player_x + 1] != WALL_CHAR) {
          map[player_y][player_x] = FLOOR_CHAR;
          player_x++;
        }
        break;
      case 'q':
        printf("\nThanks for playing!\n");
        return 0;
      default:
        printf("\nInvalid input\n");
    }
  }
}