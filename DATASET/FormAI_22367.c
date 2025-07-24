//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: safe
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25
#define NUM_ROOMS 20

char map[HEIGHT][WIDTH];

typedef struct {
  int x, y, w, h;
} room_t;

void init_map() {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      map[y][x] = '#';
    }
  }

  srand(time(NULL));
}

void draw_map() {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      printf("%c", map[y][x]);
    }
    printf("\n");
  }
}

void add_room(int x, int y, int w, int h) {
  for (int j = y; j < y + h; j++) {
    for (int i = x; i < x + w; i++) {
      map[j][i] = '.';
    }
  }
}

void connect_rooms(room_t a, room_t b) {
  int ax = a.x + rand() % a.w;
  int ay = a.y + rand() % a.h;
  int bx = b.x + rand() % b.w;
  int by = b.y + rand() % b.h;

  while (ax != bx) {
    if (ax < bx) {
      ax++;
    } else {
      ax--;
    }

    map[ay][ax] = '.';
  }

  while (ay != by) {
    if (ay < by) {
      ay++;
    } else {
      ay--;
    }

    map[ay][ax] = '.';
  }
}

void generate_map() {
  room_t rooms[NUM_ROOMS];
  int count = 0;

  while (count < NUM_ROOMS) {
    int x = rand() % (WIDTH-10)+5;
    int y = rand() % (HEIGHT-10)+5;
    int w = rand() % 10+5;
    int h = rand() % 10+5;

    room_t new_room = {x, y, w, h};

    int intersects = 0;

    for (int i = 0; i < count; i++) {
      if (new_room.x < rooms[i].x + rooms[i].w &&
          new_room.x + new_room.w > rooms[i].x &&
          new_room.y < rooms[i].y + rooms[i].h &&
          new_room.y + new_room.h > rooms[i].y) {
        intersects = 1;
        break;
      }
    }

    if (!intersects) {
      add_room(new_room.x, new_room.y, new_room.w, new_room.h);
      rooms[count] = new_room;
      count++;
    }
  }

  for (int i = 0; i < NUM_ROOMS-1; i++) {
    connect_rooms(rooms[i], rooms[i+1]);
  }
}

int main() {
  init_map();
  generate_map();
  draw_map();

  return 0;
}